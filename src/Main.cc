#include <string>
#include <iostream>
#include "Constant.h"
#include "RoundBlock.h"
#include "FunctionAdd.h"
#include "FunctionSubtract.h"
#include "FunctionMultiply.h"
#include "FunctionDivide.h"
#include "BinaryLogical.h"

int main()
{
    std::string s="hello";
    Constant cst(s);
    std::cout<<cst.getValue()<<'\n';

    RoundBlock& rb3=cst;
    std::cout<<rb3.getValue()<<'\n';

    FunctionAdd fa(Constant("69.420e-3"),Constant("-100"));
    std::cout<<fa.getValue()<<'\n';

    // 69*(420+(1234/7))-69420
    FunctionDivide f1(Constant("1234"),Constant("7"));
    FunctionAdd f2(Constant("420"),f1);
    FunctionMultiply f3(Constant("69"),f2);
    FunctionSubtract f4(f3,Constant("69420"));
    std::cout<<f4.getValue()<<'\n';
    return 0;
}
