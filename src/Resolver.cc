#include <external/json.hpp>
#include <string>
#include <map>
#include <iostream>

#include "Block.h"
#include "BlockTable.h"

#include "NestedBlock/RoundBlock/Constant.h"
#include "NestedBlock/RoundBlock/RoundBlock.h"
#include "NestedBlock/RoundBlock/BinaryFunction/FunctionAdd.h"
#include "NestedBlock/RoundBlock/BinaryFunction/FunctionSubtract.h"
#include "NestedBlock/RoundBlock/BinaryFunction/FunctionMultiply.h"
#include "NestedBlock/RoundBlock/BinaryFunction/FunctionDivide.h"
#include "NestedBlock/RoundBlock/Variable.h"
#include "NestedBlock/RoundBlock/List.h"

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

Block* resolveShadow(BlockTable &blocktable, json shadow) {
    if (shadow.at(0) == 1) {
        return blocktable.getIndex(std::stoi(shadow[1].get<std::string>()));
    } else {
        return new Constant(shadow.at(1));
    }
}

StackOfBlocks* resolveStackOfBlocks(BlockTable &blocktable, json blocks, std::string start) {
    std::string next = start;
    std::vector<StackedBlock*> stackvector;
    while (true) {
        stackvector.push_back((StackedBlock*)(blocktable.getIndex(std::stoi(next))));
        if (blocks[next]["next"].is_null()) {
            break;
        }
        next = blocks[next]["next"].get<std::string>();
    }
    StackOfBlocks *stack = new StackOfBlocks(stackvector);
    return stack;
}

Block* resolveBlock(BlockTable &blocktable, json blocks, std::string id) {
    int intid = std::stoi(id);
    json block = blocks[id];
    json inputs = block["inputs"];
    json fields = block["fields"];
    std::string opcode = block["opcode"].get<std::string>();

    if (blocktable.getIndex(intid)) {
        return blocktable.getIndex(intid);
    }

    Block *b;

    if (opcode == "control_repeat_until") {
        SharpBlock *con = (SharpBlock*)(resolveShadow(blocktable, inputs["CONDITION"]));
        StackOfBlocks *stk = resolveStackOfBlocks(blocktable, blocks, inputs["SUBSTACK"][1].get<std::string>());
        RepeatUntilBlock *b = new RepeatUntilBlock(*con, *stk);
    } else if (opcode == "control_if") {
        SharpBlock *con = (SharpBlock*)(resolveShadow(blocktable, inputs["CONDITION"]));
        StackOfBlocks *stk = resolveStackOfBlocks(blocktable, blocks, inputs["SUBSTACK"][1].get<std::string>());
        IfBlock *b = new IfBlock(*con, *stk);
    } else if (opcode == "control_if_else") {
        SharpBlock *con = (SharpBlock*)(resolveShadow(blocktable, inputs["CONDITION"]));
        StackOfBlocks *stk1 = resolveStackOfBlocks(blocktable, blocks, inputs["SUBSTACK"][1].get<std::string>());
        StackOfBlocks *stk2 = resolveStackOfBlocks(blocktable, blocks, inputs["SUBSTACK2"][1].get<std::string>());
        IfElseBlock *b = new IfElseBlock(*con, *stk1, *stk2);
    } else if (opcode == "data_setvariableto") {
        NestedBlock *val = (NestedBlock*)(resolveShadow(blocktable, inputs["VALUE"]));
        Variable *var = (Variable*)(resolveShadow(blocktable, fields["VARIABLE"]));
        SetVariable *b = new SetVariable(*var, *val);
    } else if (opcode == "looks_say") {
        NestedBlock *msg = (NestedBlock*)(resolveShadow(blocktable, inputs["MESSAGE"]));
        LooksSay *b = new LooksSay(*msg);
    } else if (opcode == "looks_think") {
        NestedBlock *msg = (NestedBlock*)(resolveShadow(blocktable, inputs["MESSAGE"]));
        LooksThink *b = new LooksThink(*msg);
    } else if (opcode == "operator_add") {
        NestedBlock *num1 = (NestedBlock*)(resolveShadow(blocktable, inputs["NUM1"]));
        NestedBlock *num2 = (NestedBlock*)(resolveShadow(blocktable, inputs["NUM2"]));
        FunctionAdd *b = new FunctionAdd(*num1, *num2);
    } else if (opcode == "operator_subtract") {
        NestedBlock *num1 = (NestedBlock*)(resolveShadow(blocktable, inputs["NUM1"]));
        NestedBlock *num2 = (NestedBlock*)(resolveShadow(blocktable, inputs["NUM2"]));
        FunctionSubtract *b = new FunctionSubtract(*num1, *num2);
    } else if (opcode == "operator_multiply") {
        NestedBlock *num1 = (NestedBlock*)resolveShadow(blocktable, inputs["NUM1"]);
        NestedBlock *num2 = (NestedBlock*)resolveShadow(blocktable, inputs["NUM2"]);
        FunctionMultiply *b = new FunctionMultiply(*num1, *num2);
    } else if (opcode == "operator_divide") {
        NestedBlock *num1 = (NestedBlock*)resolveShadow(blocktable, inputs["NUM1"]);
        NestedBlock *num2 = (NestedBlock*)resolveShadow(blocktable, inputs["NUM2"]);
        FunctionDivide *b = new FunctionDivide(*num1, *num2);
    } else if (opcode == "operator_lt") {
        NestedBlock *opr1 = (NestedBlock*)resolveShadow(blocktable, inputs["OPERAND1"]);
        NestedBlock *opr2 = (NestedBlock*)resolveShadow(blocktable, inputs["OPERAND2"]);
        ComparisonLT *b = new ComparisonLT(*opr1, *opr2);
    } else if (opcode == "operator_equals") {
        NestedBlock *opr1 = (NestedBlock*)resolveShadow(blocktable, inputs["OPERAND1"]);
        NestedBlock *opr2 = (NestedBlock*)resolveShadow(blocktable, inputs["OPERAND2"]);
        ComparisonE *b = new ComparisonE(*opr1, *opr2);
    } else if (opcode == "operator_gt") {
        NestedBlock *opr1 = (NestedBlock*)resolveShadow(blocktable, inputs["OPERAND1"]);
        NestedBlock *opr2 = (NestedBlock*)resolveShadow(blocktable, inputs["OPERAND2"]);
        ComparisonGT *b = new ComparisonGT(*opr1, *opr2);
    } else if (opcode == "operator_and") {
        SharpBlock *opr1 = (SharpBlock*)resolveShadow(blocktable, inputs["OPERAND1"]);
        SharpBlock *opr2 = (SharpBlock*)resolveShadow(blocktable, inputs["OPERAND2"]);
        LogicalAnd *b = new LogicalAnd(*opr1, *opr2);
    } else if (opcode == "operator_or") {
        SharpBlock *opr1 = (SharpBlock*)resolveShadow(blocktable, inputs["OPERAND1"]);
        SharpBlock *opr2 = (SharpBlock*)resolveShadow(blocktable, inputs["OPERAND2"]);
        LogicalOr *b = new LogicalOr(*opr1, *opr2);
    } else if (opcode == "operator_not") {
        SharpBlock *opr = (SharpBlock*)resolveShadow(blocktable, inputs["OPERAND"]);
        LogicalNot *b = new LogicalNot(*opr);
    }
    blocktable.setIndex(intid, b);
    return b;
}
