#include <string>
#include <iostream>
#include "NestedBlock/RoundBlock/Constant.h"
#include "NestedBlock/RoundBlock/RoundBlock.h"
#include "NestedBlock/RoundBlock/BinaryFunction/FunctionAdd.h"
#include "NestedBlock/RoundBlock/BinaryFunction/FunctionSubtract.h"
#include "NestedBlock/RoundBlock/BinaryFunction/FunctionMultiply.h"
#include "NestedBlock/RoundBlock/BinaryFunction/FunctionDivide.h"
#include "NestedBlock/SharpBlock/BinaryLogical/LogicalAnd.h"
#include "NestedBlock/SharpBlock/BinaryLogical/LogicalOr.h"
#include "NestedBlock/SharpBlock/LogicalNot.h"
#include "NestedBlock/SharpBlock/BinaryComparison/ComparisonE.h"
#include "NestedBlock/SharpBlock/BinaryComparison/ComparisonLT.h"
#include "NestedBlock/SharpBlock/BinaryComparison/ComparisonGT.h"

int main()
{
    std::string s="hello";
    Constant cst(s);
    std::cout<<cst.getValue()<<'\n';

    RoundBlock& rb3=cst;
    std::cout<<rb3.getValue()<<'\n';

    FunctionAdd fa(Constant("69.420e-3"),Constant("-100"));
    std::cout<<fa.getValue()<<'\n';

    ComparisonE yes(Constant("0"), Constant("0"));
    LogicalNot no(yes);
    std::cout << no.getValue() << '\n';

    // 69*(420+(1234/7))-69420
    FunctionDivide f1(Constant("1234"),Constant("7"));
    FunctionAdd f2(Constant("420"),f1);
    FunctionMultiply f3(Constant("69"),f2);
    FunctionSubtract f4(f3,Constant("69420"));
    std::cout<<f4.getValue()<<'\n';
    return 0;
}
