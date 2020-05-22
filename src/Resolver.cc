#include <external/json.hpp>
#include <string>
#include <map>
#include <iostream>
#include <memory>

#include "Block.h"
#include "BlockTable.h"

#include "NestedBlock/RoundBlock/Constant.h"
#include "NestedBlock/RoundBlock/RoundBlock.h"
#include "NestedBlock/RoundBlock/BinaryFunction/FunctionAdd.h"
#include "NestedBlock/RoundBlock/BinaryFunction/FunctionSubtract.h"
#include "NestedBlock/RoundBlock/BinaryFunction/FunctionMultiply.h"
#include "NestedBlock/RoundBlock/BinaryFunction/FunctionDivide.h"
#include "NestedBlock/RoundBlock/Variable.h"
#include "NestedBlock/RoundBlock/List/List.h"

#include "NestedBlock/SharpBlock/BinaryLogical/LogicalAnd.h"
#include "NestedBlock/SharpBlock/BinaryLogical/LogicalOr.h"
#include "NestedBlock/SharpBlock/LogicalNot.h"
#include "NestedBlock/SharpBlock/BinaryComparison/ComparisonE.h"
#include "NestedBlock/SharpBlock/BinaryComparison/ComparisonLT.h"
#include "NestedBlock/SharpBlock/BinaryComparison/ComparisonGT.h"

#include "StackedBlock/Looks/LooksSay.h"
#include "StackedBlock/Looks/LooksThink.h"
#include "StackOfBlocks.h"
#include "StackedBlock/Control/IfBlock.h"
#include "StackedBlock/Control/IfElseBlock.h"
#include "StackedBlock/Control/RepeatUntilBlock.h"
#include "StackedBlock/VariableOperation/SetVariable.h"

using json = nlohmann::json;

std::shared_ptr<Block> resolveShadow(BlockTable &blocktable, json shadow) {
    if (shadow.at(0) == 1) {
        return blocktable.getIndex(std::stoi(shadow[1].get<std::string>()));
    } else {
        return std::make_shared<Constant>(shadow.at(1));
    }
}

std::shared_ptr<StackOfBlocks> resolveStackOfBlocks(BlockTable &blocktable, json blocks, std::string start) {
    std::string next = start;
    std::vector<std::shared_ptr<StackedBlock>> stackvector;
    while (true) {
        stackvector.push_back(std::static_pointer_cast<StackedBlock>(blocktable.getIndex(std::stoi(next))));
        if (blocks[next]["next"].is_null()) {
            break;
        }
        next = blocks[next]["next"].get<std::string>();
    }
    std::shared_ptr<StackOfBlocks> stack = std::make_shared<StackOfBlocks>(stackvector);
    return stack;
}

std::shared_ptr<Block> resolveBlock(BlockTable &blocktable, json blocks, std::string id) {
    int intid = std::stoi(id);
    json block = blocks[id];
    json inputs = block["inputs"];
    json fields = block["fields"];
    std::string opcode = block["opcode"].get<std::string>();

    if (blocktable.getIndex(intid)) {
        return blocktable.getIndex(intid);
    }

    std::shared_ptr<Block> b;

    if (opcode == "control_repeat_until") {
        std::shared_ptr<SharpBlock> con = std::static_pointer_cast<SharpBlock>(resolveShadow(blocktable, inputs["CONDITION"]));
        std::shared_ptr<StackOfBlocks> stk = resolveStackOfBlocks(blocktable, blocks, inputs["SUBSTACK"][1].get<std::string>());
        b = std::make_shared<RepeatUntilBlock>(con, stk);
    } else if (opcode == "control_if") {
        std::shared_ptr<SharpBlock> con = std::static_pointer_cast<SharpBlock>(resolveShadow(blocktable, inputs["CONDITION"]));
        std::shared_ptr<StackOfBlocks> stk = resolveStackOfBlocks(blocktable, blocks, inputs["SUBSTACK"][1].get<std::string>());
        b = std::make_shared<IfBlock>(con, stk);
    } else if (opcode == "control_if_else") {
        std::shared_ptr<SharpBlock> con = std::static_pointer_cast<SharpBlock>(resolveShadow(blocktable, inputs["CONDITION"]));
        std::shared_ptr<StackOfBlocks> stk1 = resolveStackOfBlocks(blocktable, blocks, inputs["SUBSTACK"][1].get<std::string>());
        std::shared_ptr<StackOfBlocks> stk2 = resolveStackOfBlocks(blocktable, blocks, inputs["SUBSTACK2"][1].get<std::string>());
        b = std::make_shared<IfElseBlock>(con, stk1, stk2);
    } else if (opcode == "data_setvariableto") {
        std::shared_ptr<NestedBlock> val = std::static_pointer_cast<NestedBlock>(resolveShadow(blocktable, inputs["VALUE"]));
        std::shared_ptr<Variable> var = std::static_pointer_cast<Variable>(resolveShadow(blocktable, fields["VARIABLE"]));
        b = std::make_shared<SetVariable>(var, val);
    } else if (opcode == "looks_say") {
        std::shared_ptr<NestedBlock> msg = std::static_pointer_cast<NestedBlock>(resolveShadow(blocktable, inputs["MESSAGE"]));
        b = std::make_shared<LooksSay>(msg);
    } else if (opcode == "looks_think") {
        std::shared_ptr<NestedBlock> msg = std::static_pointer_cast<NestedBlock>(resolveShadow(blocktable, inputs["MESSAGE"]));
        b = std::make_shared<LooksThink>(msg);
    } else if (opcode == "operator_add") {
        std::shared_ptr<NestedBlock> num1 = std::static_pointer_cast<NestedBlock>(resolveShadow(blocktable, inputs["NUM1"]));
        std::shared_ptr<NestedBlock> num2 = std::static_pointer_cast<NestedBlock>(resolveShadow(blocktable, inputs["NUM2"]));
        b = std::make_shared<FunctionAdd>(num1, num2);
    } else if (opcode == "operator_subtract") {
        std::shared_ptr<NestedBlock> num1 = std::static_pointer_cast<NestedBlock>(resolveShadow(blocktable, inputs["NUM1"]));
        std::shared_ptr<NestedBlock> num2 = std::static_pointer_cast<NestedBlock>(resolveShadow(blocktable, inputs["NUM2"]));
        b = std::make_shared<FunctionSubtract>(num1, num2);
    } else if (opcode == "operator_multiply") {
        std::shared_ptr<NestedBlock> num1 = std::static_pointer_cast<NestedBlock>(resolveShadow(blocktable, inputs["NUM1"]));
        std::shared_ptr<NestedBlock> num2 = std::static_pointer_cast<NestedBlock>(resolveShadow(blocktable, inputs["NUM2"]));
        b = std::make_shared<FunctionMultiply>(num1, num2);
    } else if (opcode == "operator_divide") {
        std::shared_ptr<NestedBlock> num1 = std::static_pointer_cast<NestedBlock>(resolveShadow(blocktable, inputs["NUM1"]));
        std::shared_ptr<NestedBlock> num2 = std::static_pointer_cast<NestedBlock>(resolveShadow(blocktable, inputs["NUM2"]));
        b = std::make_shared<FunctionDivide>(num1, num2);
    } else if (opcode == "operator_lt") {
        std::shared_ptr<NestedBlock> opr1 = std::static_pointer_cast<NestedBlock>(resolveShadow(blocktable, inputs["OPERAND1"]));
        std::shared_ptr<NestedBlock> opr2 = std::static_pointer_cast<NestedBlock>(resolveShadow(blocktable, inputs["OPERAND2"]));
        b = std::make_shared<ComparisonLT>(opr1, opr2);
    } else if (opcode == "operator_equals") {
        std::shared_ptr<NestedBlock> opr1 = std::static_pointer_cast<NestedBlock>(resolveShadow(blocktable, inputs["OPERAND1"]));
        std::shared_ptr<NestedBlock> opr2 = std::static_pointer_cast<NestedBlock>(resolveShadow(blocktable, inputs["OPERAND2"]));
        b = std::make_shared<ComparisonE>(opr1, opr2);
    } else if (opcode == "operator_gt") {
        std::shared_ptr<NestedBlock> opr1 = std::static_pointer_cast<NestedBlock>(resolveShadow(blocktable, inputs["OPERAND1"]));
        std::shared_ptr<NestedBlock> opr2 = std::static_pointer_cast<NestedBlock>(resolveShadow(blocktable, inputs["OPERAND2"]));
        b = std::make_shared<ComparisonGT>(opr1, opr2);
    } else if (opcode == "operator_and") {
        std::shared_ptr<SharpBlock> opr1 = std::static_pointer_cast<SharpBlock>(resolveShadow(blocktable, inputs["OPERAND1"]));
        std::shared_ptr<SharpBlock> opr2 = std::static_pointer_cast<SharpBlock>(resolveShadow(blocktable, inputs["OPERAND2"]));
        b = std::make_shared<LogicalAnd>(opr1, opr2);
    } else if (opcode == "operator_or") {
        std::shared_ptr<SharpBlock> opr1 = std::static_pointer_cast<SharpBlock>(resolveShadow(blocktable, inputs["OPERAND1"]));
        std::shared_ptr<SharpBlock> opr2 = std::static_pointer_cast<SharpBlock>(resolveShadow(blocktable, inputs["OPERAND2"]));
        b = std::make_shared<LogicalOr>(opr1, opr2);
    } else if (opcode == "operator_not") {
        std::shared_ptr<SharpBlock> opr = std::static_pointer_cast<SharpBlock>(resolveShadow(blocktable, inputs["OPERAND"]));
        b = std::make_shared<LogicalNot>(opr);
    }
    blocktable.setIndex(intid, b);
    return b;
}
