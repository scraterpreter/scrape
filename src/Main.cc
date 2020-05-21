#include <external/json.hpp>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "StackOfBlocks.h"
#include "BlockTable.h"
#include "NestedBlock/RoundBlock/Variable.h"
#include "NestedBlock/RoundBlock/List/List.h"
#include "NestedBlock/RoundBlock/List/ListLength.h"

using json = nlohmann::json;

Block* resolveBlock(BlockTable &blocktable, json blocks, std::string id);
Block* resolveShadow(BlockTable &blocktable, json shadow);
StackOfBlocks* resolveStackOfBlocks(BlockTable &blocktable, json blocks, std::string start);

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
        scrapestate.setIndex(std::stoi(variable.key()), new Variable(std::to_string(scrapejson["container"]["variables"][variable.key()].get<int>())));
    }

    for (auto& list:scrapejson["container"]["lists"].items()) {
        scrapestate.setIndex(std::stoi(list.key()), new List(scrapejson["container"]["lists"][list.key()].get<std::vector<std::string>>()));
    }

    for (auto& id:scrapejson["build_order"].items()) {
        resolveBlock(scrapestate, scrapejson["blocks"], id.key());
    }

    StackOfBlocks* mainstack = resolveStackOfBlocks(scrapestate, scrapejson["blocks"], scrapejson["start"].get<std::string>());

    mainstack->execAll();

    delete mainstack;

    return 0;
}
