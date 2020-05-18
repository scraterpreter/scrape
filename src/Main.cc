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
#include "StackedBlock/Looks/LooksSay.h"
#include "StackedBlock/Looks/LooksThink.h"

int main() {
    Constant c1("Hello, World!");
    LooksSay s1(c1);
    s1.exec();
    Constant c2("69"),c3("hello");
    FunctionMultiply f1(c2,c3);
    LooksSay s2(f1);
    s2.exec();
    ComparisonE comp1(c2,c3);
    LooksSay s3(comp1);
    s3.exec();
    FunctionAdd f2(comp1,c2);
    LooksSay s4(f2);
    s4.exec();
}
