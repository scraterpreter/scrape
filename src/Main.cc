#include <external/json.hpp>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <memory>
#include <stdlib.h>
#include <time.h>

#include "StackOfBlocks.h"
#include "BlockTable.h"
#include "NestedBlock/RoundBlock/Variable.h"
#include "NestedBlock/RoundBlock/List/List.h"
#include "NestedBlock/RoundBlock/List/ListLength.h"
#include "GlobalTimer.h"
#include "StackedBlock/Control/StopBlock.h"
#include "StackedBlock/Ask/AskAndWait.h"

using json = nlohmann::json;

std::shared_ptr<Block> resolveBlock(BlockTable &blocktable, json blocks, std::string id);
std::shared_ptr<Block> resolveShadow(BlockTable &blocktable, json shadow);
std::shared_ptr<StackOfBlocks> resolveStackOfBlocks(BlockTable &blocktable, json blocks, std::string start);

int main(int argc, char* argv[]) {
    srand(time(0));

    if (argc < 2) {
        std::cerr << "Please specify the name of the .scrape file.\n";
        return 1;
    } else if (argc > 2) {
        std::cerr << "Please specify only the name of the .scrape file.\n";
        return 1;
    }

    std::ifstream scrapefile(argv[1]);
    if(!scrapefile.good())
    {
        std::cerr << "Error opening file \""<<argv[1]<<"\"!\n";
        return 1;
    }
    json scrapejson;
    scrapefile >> scrapejson;

    BlockTable scrapestate(scrapejson["ids"].get<int>()+2);
    
    scrapestate.setIndex(scrapestate.size()-2,std::make_shared<Variable>()); // Answer Variable
    scrapestate.setIndex(scrapestate.size()-1,std::make_shared<GlobalTimer>()); // Global Timer 
    
    for (auto& variable:scrapejson["container"]["variables"].items()) {
        std::shared_ptr<Variable> v = std::make_shared<Variable>(scrapejson["container"]["variables"][variable.key()].get<std::string>());
        scrapestate.setIndex(std::stoi(variable.key()), v);
    }

    for (auto& list:scrapejson["container"]["lists"].items()) {
        std::shared_ptr<List> l = std::make_shared<List>(scrapejson["container"]["lists"][list.key()].get<std::vector<std::string>>());
        scrapestate.setIndex(std::stoi(list.key()), l);
    }

    for (auto& id:scrapejson["build_order"].items()) {
        resolveBlock(scrapestate, scrapejson["blocks"], id.value());
    }
    
    std::shared_ptr<StackOfBlocks> mainstack = resolveStackOfBlocks(scrapestate, scrapejson["blocks"], scrapejson["start"].get<std::string>());
    
    try
    {
        mainstack->execAll();
    }
    catch(StopBlockCalledException& e) {}
    catch(StandardInputException& e) {}

    return 0;
}
