#include <external/json.hpp>
#include <string>
#include <map>
#include <iostream>
#include <memory>

#include "Block.h"
#include "BlockTable.h"
#include "StackOfBlocks.h"

#include "NestedBlock/RoundBlock/Constant.h"
#include "NestedBlock/RoundBlock/RoundBlock.h"
#include "NestedBlock/RoundBlock/BinaryFunction/FunctionAdd.h"
#include "NestedBlock/RoundBlock/BinaryFunction/FunctionSubtract.h"
#include "NestedBlock/RoundBlock/BinaryFunction/FunctionMultiply.h"
#include "NestedBlock/RoundBlock/BinaryFunction/FunctionDivide.h"
#include "NestedBlock/RoundBlock/Operators/OperatorsRandom.h"
#include "NestedBlock/RoundBlock/Operators/OperatorsJoin.h"
#include "NestedBlock/RoundBlock/Operators/OperatorsLetterOf.h"
#include "NestedBlock/RoundBlock/Operators/OperatorsLength.h"
#include "NestedBlock/RoundBlock/Operators/OperatorsMod.h"
#include "NestedBlock/RoundBlock/Operators/OperatorsRound.h"
#include "NestedBlock/RoundBlock/Operators/OperatorsMathOp.h"

#include "NestedBlock/RoundBlock/Variable.h"
#include "NestedBlock/RoundBlock/List/List.h"
#include "NestedBlock/RoundBlock/List/ListLength.h"
#include "NestedBlock/RoundBlock/List/ListFindItem.h"
#include "NestedBlock/RoundBlock/List/ListGetItem.h"

#include "NestedBlock/SharpBlock/BinaryLogical/LogicalAnd.h"
#include "NestedBlock/SharpBlock/BinaryLogical/LogicalOr.h"
#include "NestedBlock/SharpBlock/LogicalNot.h"
#include "NestedBlock/SharpBlock/BinaryComparison/ComparisonE.h"
#include "NestedBlock/SharpBlock/BinaryComparison/ComparisonLT.h"
#include "NestedBlock/SharpBlock/BinaryComparison/ComparisonGT.h"
#include "NestedBlock/SharpBlock/ListContainsItem.h"
#include "NestedBlock/SharpBlock/OperatorsContains.h"

#include "StackedBlock/Looks/LooksSay.h"
#include "StackedBlock/Looks/LooksThink.h"
#include "StackedBlock/Control/ForeverBlock.h"
#include "StackedBlock/Control/IfBlock.h"
#include "StackedBlock/Control/IfElseBlock.h"
#include "StackedBlock/Control/RepeatBlock.h"
#include "StackedBlock/Control/RepeatUntilBlock.h"
#include "StackedBlock/Control/WaitBlock.h"
#include "StackedBlock/Control/WaitUntilBlock.h"
#include "StackedBlock/VariableOperation/SetVariable.h"
#include "StackedBlock/VariableOperation/ChangeVariable.h"
#include "StackedBlock/ListOperation/ListAddItem.h"
#include "StackedBlock/ListOperation/ListDeleteAll.h"
#include "StackedBlock/ListOperation/ListDeleteItem.h"
#include "StackedBlock/ListOperation/ListInsertItem.h"
#include "StackedBlock/ListOperation/ListReplaceItem.h"

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
    std::shared_ptr<std::vector<std::shared_ptr<StackedBlock>>> stackvector = std::make_shared<std::vector<std::shared_ptr<StackedBlock>>>();
    while (true) {
        stackvector->push_back(std::static_pointer_cast<StackedBlock>(blocktable.getIndex(std::stoi(next))));
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

    if (opcode == "control_repeat") {
        std::shared_ptr<NestedBlock> times = std::static_pointer_cast<NestedBlock>(resolveShadow(blocktable, inputs["TIMES"]));
        std::shared_ptr<StackOfBlocks> stk = resolveStackOfBlocks(blocktable, blocks, inputs["SUBSTACK"][1].get<std::string>());
        b = std::make_shared<RepeatBlock>(times, stk);
    } else if (opcode == "control_repeat_until") {
        std::shared_ptr<SharpBlock> con = std::static_pointer_cast<SharpBlock>(resolveShadow(blocktable, inputs["CONDITION"]));
        std::shared_ptr<StackOfBlocks> stk = resolveStackOfBlocks(blocktable, blocks, inputs["SUBSTACK"][1].get<std::string>());
        b = std::make_shared<RepeatUntilBlock>(con, stk);
    } else if (opcode == "control_forever") {
        std::shared_ptr<StackOfBlocks> stk = resolveStackOfBlocks(blocktable, blocks, inputs["SUBSTACK"][1].get<std::string>());
        b = std::make_shared<ForeverBlock>(stk);
    } else if (opcode == "control_wait") {
        std::shared_ptr<NestedBlock> dur = std::static_pointer_cast<NestedBlock>(resolveShadow(blocktable, inputs["DURATION"]));
        b = std::make_shared<WaitBlock>(dur);
    } else if (opcode == "control_wait_until") {
        std::shared_ptr<SharpBlock> con = std::static_pointer_cast<SharpBlock>(resolveShadow(blocktable, inputs["CONDITION"]));
        b = std::make_shared<WaitUntilBlock>(con);
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
        std::shared_ptr<Variable> var = std::static_pointer_cast<Variable>(resolveShadow(blocktable, fields["VARIABLE"]));
        std::shared_ptr<NestedBlock> val = std::static_pointer_cast<NestedBlock>(resolveShadow(blocktable, inputs["VALUE"]));
        b = std::make_shared<SetVariable>(var, val);
    } else if (opcode == "data_changevariableby") {
        std::shared_ptr<Variable> var = std::static_pointer_cast<Variable>(resolveShadow(blocktable, fields["VARIABLE"]));
        std::shared_ptr<NestedBlock> val = std::static_pointer_cast<NestedBlock>(resolveShadow(blocktable, inputs["VALUE"]));
        b = std::make_shared<ChangeVariable>(var, val);
    } else if (opcode == "data_addtolist") {
        std::shared_ptr<List> list = std::static_pointer_cast<List>(resolveShadow(blocktable, fields["LIST"]));
        std::shared_ptr<NestedBlock> item = std::static_pointer_cast<NestedBlock>(resolveShadow(blocktable, inputs["ITEM"]));
        b = std::make_shared<ListAddItem>(list, item);
    } else if (opcode == "data_deleteoflist") {
        std::shared_ptr<List> list = std::static_pointer_cast<List>(resolveShadow(blocktable, fields["LIST"]));
        std::shared_ptr<NestedBlock> index = std::static_pointer_cast<NestedBlock>(resolveShadow(blocktable, inputs["INDEX"]));
        b = std::make_shared<ListDeleteItem>(list, index);
    } else if (opcode == "data_insertatlist") {
        std::shared_ptr<List> list = std::static_pointer_cast<List>(resolveShadow(blocktable, fields["LIST"]));
        std::shared_ptr<NestedBlock> index = std::static_pointer_cast<NestedBlock>(resolveShadow(blocktable, inputs["INDEX"]));
        std::shared_ptr<NestedBlock> item = std::static_pointer_cast<NestedBlock>(resolveShadow(blocktable, inputs["ITEM"]));
        b = std::make_shared<ListInsertItem>(list, index, item);
    } else if (opcode == "data_replaceitemoflist") {
        std::shared_ptr<List> list = std::static_pointer_cast<List>(resolveShadow(blocktable, fields["LIST"]));
        std::shared_ptr<NestedBlock> index = std::static_pointer_cast<NestedBlock>(resolveShadow(blocktable, inputs["INDEX"]));
        std::shared_ptr<NestedBlock> item = std::static_pointer_cast<NestedBlock>(resolveShadow(blocktable, inputs["ITEM"]));
        b = std::make_shared<ListReplaceItem>(list, index, item);
    } else if (opcode == "data_itemoflist") {
        std::shared_ptr<List> list = std::static_pointer_cast<List>(resolveShadow(blocktable, fields["LIST"]));
        std::shared_ptr<NestedBlock> index = std::static_pointer_cast<NestedBlock>(resolveShadow(blocktable, inputs["INDEX"]));
        b = std::make_shared<ListGetItem>(list, index);
    } else if (opcode == "data_itemnumoflist") {
        std::shared_ptr<List> list = std::static_pointer_cast<List>(resolveShadow(blocktable, fields["LIST"]));
        std::shared_ptr<NestedBlock> item = std::static_pointer_cast<NestedBlock>(resolveShadow(blocktable, inputs["ITEM"]));
        b = std::make_shared<ListFindItem>(list, item);
    } else if (opcode == "data_lengthoflist") {
        std::shared_ptr<List> list = std::static_pointer_cast<List>(resolveShadow(blocktable, fields["LIST"]));
        b = std::make_shared<ListLength>(list);
    } else if (opcode == "data_listcontainsitem") {
        std::shared_ptr<List> list = std::static_pointer_cast<List>(resolveShadow(blocktable, fields["LIST"]));
        std::shared_ptr<NestedBlock> item = std::static_pointer_cast<NestedBlock>(resolveShadow(blocktable, inputs["ITEM"]));
        b = std::make_shared<ListContainsItem>(list, item);
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
    } else if (opcode == "operator_random") {
        std::shared_ptr<NestedBlock> lb = std::static_pointer_cast<NestedBlock>(resolveShadow(blocktable, inputs["FROM"]));
        std::shared_ptr<NestedBlock> ub = std::static_pointer_cast<NestedBlock>(resolveShadow(blocktable, inputs["TO"]));
        b = std::make_shared<OperatorsRandom>(lb, ub);
    } else if (opcode == "operator_join") {
        std::shared_ptr<NestedBlock> lb = std::static_pointer_cast<NestedBlock>(resolveShadow(blocktable, inputs["STRING1"]));
        std::shared_ptr<NestedBlock> rb = std::static_pointer_cast<NestedBlock>(resolveShadow(blocktable, inputs["STRING2"]));
        b = std::make_shared<OperatorsJoin>(lb, rb);
    } else if (opcode == "operator_letter_of") {
        std::shared_ptr<NestedBlock> i = std::static_pointer_cast<NestedBlock>(resolveShadow(blocktable, inputs["LETTER"]));
        std::shared_ptr<NestedBlock> s = std::static_pointer_cast<NestedBlock>(resolveShadow(blocktable, inputs["STRING"]));
        b = std::make_shared<OperatorsLetterOf>(i, s);
    } else if (opcode == "operator_length") {
        std::shared_ptr<NestedBlock> s = std::static_pointer_cast<NestedBlock>(resolveShadow(blocktable, inputs["STRING"]));
        b = std::make_shared<OperatorsLength>(s);
    } else if (opcode == "operator_contains") {
        std::shared_ptr<NestedBlock> s1 = std::static_pointer_cast<NestedBlock>(resolveShadow(blocktable, inputs["STRING1"]));
        std::shared_ptr<NestedBlock> s2 = std::static_pointer_cast<NestedBlock>(resolveShadow(blocktable, inputs["STRING2"]));
        b = std::make_shared<OperatorsContains>(s1, s2);
    } else if (opcode == "operator_mod") {
        std::shared_ptr<NestedBlock> n1 = std::static_pointer_cast<NestedBlock>(resolveShadow(blocktable, inputs["NUM1"]));
        std::shared_ptr<NestedBlock> n2 = std::static_pointer_cast<NestedBlock>(resolveShadow(blocktable, inputs["NUM2"]));
        b = std::make_shared<OperatorsMod>(n1, n2);
    } else if (opcode == "operator_round") {
        std::shared_ptr<NestedBlock> n = std::static_pointer_cast<NestedBlock>(resolveShadow(blocktable, inputs["NUM"]));
        b = std::make_shared<OperatorsRound>(n);
    } else if (opcode == "operator_mathop") {
        std::shared_ptr<Constant> o = std::static_pointer_cast<Constant>(resolveShadow(blocktable, fields["OPERATOR"]));
        std::shared_ptr<NestedBlock> n = std::static_pointer_cast<NestedBlock>(resolveShadow(blocktable, inputs["NUM"]));
        b = std::make_shared<OperatorsMathOp>(o, n);
    } else {
        std::cerr << "Warning: Unsupported block " << opcode << ".\n";
    }
    blocktable.setIndex(intid, b);
    return b;
}
