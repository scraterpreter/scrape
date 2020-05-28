#include <string>
#include <memory>
#include <cmath>
#include "NestedBlock/RoundBlock/Constant.h"
#include "NestedBlock/RoundBlock/Operators/OperatorsMathOp.h"

#define RAD 57.29577951308232d

std::string OperatorsMathOp::getValue() const
{
    double inp = num->getDouble();
    double ans;
    if (op->getValue() == "abs") {
        ans = std::abs(inp);
    } else if (op->getValue() == "floor") {
        ans = floor(inp);
    } else if (op->getValue() == "ceiling") {
        ans = ceil(inp);
    } else if (op->getValue() == "sqrt") {
        ans = sqrt(inp);
    } else if (op->getValue() == "sin") {
        ans = sin(inp/RAD);
    } else if (op->getValue() == "cos") {
        ans = cos(inp/RAD);
    } else if (op->getValue() == "tan") {
        ans = tan(inp/RAD);
    } else if (op->getValue() == "asin") {
        ans = asin(inp)*RAD;
    } else if (op->getValue() == "acos") {
        ans = acos(inp)*RAD;
    } else if (op->getValue() == "atan") {
        ans = atan(inp)*RAD;
    } else if (op->getValue() == "ln") {
        ans = log(inp);
    } else if (op->getValue() == "log") {
        ans = log10(inp);
    } else if (op->getValue() == "e ^") {
        ans = exp(inp);
    } else if (op->getValue() == "10 ^") {
        ans = pow(10, inp);
    } else {
        ans = inp;
    }
    return std::to_string(ans);
}

OperatorsMathOp::OperatorsMathOp(std::shared_ptr<Constant> o, std::shared_ptr<NestedBlock> n) : op(o), num(n) {}
