#include <external/json.hpp>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <memory>

#include "StackOfBlocks.h"
#include "BlockTable.h"
#include "NestedBlock/RoundBlock/Variable.h"
#include "NestedBlock/RoundBlock/List/List.h"
#include "NestedBlock/RoundBlock/List/ListLength.h"

using json = nlohmann::json;

std::shared_ptr<Block> resolveBlock(BlockTable &blocktable, json blocks, std::string id);
std::shared_ptr<Block> resolveShadow(BlockTable &blocktable, json shadow);
std::shared_ptr<StackOfBlocks> resolveStackOfBlocks(BlockTable &blocktable, json blocks, std::string start);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Please specify the name of the .scrape file.\n";
        return 1;
    } else if (argc > 2) {
        std::cout << "Please specify only the name of the .scrape file.\n";
        return 1;
    }

    std::ifstream scrapefile(argv[1]);
    json scrapejson;
    scrapefile >> scrapejson;

    BlockTable scrapestate(scrapejson["ids"].get<int>()+1);

    for (auto& variable:scrapejson["container"]["variables"].items()) {
        std::shared_ptr<Variable> v = std::make_shared<Variable>(std::to_string(scrapejson["container"]["variables"][variable.key()].get<int>()));
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

    mainstack->execAll();

    return 0;
}
