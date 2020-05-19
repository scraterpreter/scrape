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
#include "StackedBlock/IfBlock.h"
#include "StackedBlock/IfElseBlock.h"

int main() {
{
    Constant c1("Hello, World!");
    LooksSay s1(c1);
    s1.exec();
}
{
    Variable v1("0");
    LooksSay s2(v1);
    s2.exec();
    v1.setValue("1");
    s2.exec();
}
{
    List l1({"yes"});
    LooksSay s3(l1);
    s3.exec();
    l1.add("no");
    s3.exec();
    l1.remove(0);
    s3.exec();
    l1.insert(0, "maybe");
    s3.exec();
    l1.replace(1, "perhaps");
    s3.exec();
    l1.clear();
    l1.add("perhapsNOT");
    s3.exec();
}
{
    Constant c2("69"),c3("hello");
    FunctionMultiply f1(c2,c3);
    LooksSay s4(f1);
    s4.exec();
    ComparisonE comp1(c2,c3);
    LooksSay s5(comp1);
    s5.exec();
    FunctionAdd f2(comp1,c2);
    LooksSay s6(f2);
    s6.exec();
}
{
    // Test if statement
    Constant banner("--- IF STATEMENT TEST ---");
    LooksSay sayBanner(banner);
    sayBanner.exec();
    Constant c("yes!!!");
    Constant d("69");
    Constant e("23");
    Constant f("3");
    LooksSay s1(c),s2(d);
    std::vector<StackedBlock*> b={&s1,&s2};
    StackOfBlocks stack(b);
    FunctionMultiply fm(e,f);
    ComparisonE comp(fm,f);
    LogicalNot ln(comp);
    IfBlock ib(ln,stack);
    ib.exec();
    
    Constant h("executing else ...");
    LooksSay s3(h);
    std::vector<StackedBlock*> ree={&s3};
    StackOfBlocks stack2(ree);
    IfElseBlock ieb(comp,stack,stack2);
    ieb.exec();
}
}
