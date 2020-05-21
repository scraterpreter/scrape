#include "NestedBlock/RoundBlock/Constant.h"
#include "NestedBlock/RoundBlock/RoundBlock.h"
#include "NestedBlock/RoundBlock/BinaryFunction/FunctionAdd.h"
#include "NestedBlock/RoundBlock/BinaryFunction/FunctionSubtract.h"
#include "NestedBlock/RoundBlock/BinaryFunction/FunctionMultiply.h"
#include "NestedBlock/RoundBlock/BinaryFunction/FunctionDivide.h"
#include "NestedBlock/RoundBlock/Variable.h"
#include "NestedBlock/RoundBlock/List/List.h"
#include "NestedBlock/RoundBlock/List/ListLength.h"

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
#include "StackedBlock/ListOperation/ListAddItem.h"
#include "StackedBlock/ListOperation/ListDeleteAll.h"
#include "StackedBlock/ListOperation/ListDeleteItem.h"
#include "StackedBlock/ListOperation/ListInsertItem.h"
#include "StackedBlock/ListOperation/ListReplaceItem.h"

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
{
    // Test repeat until
    Constant banner("--- REPEAT UNTIL TEST ---\nComputes first power of 2 that is greater than one billion!");
    LooksSay sayBanner(banner);
    sayBanner.exec();
    Constant c1("2"),c2("1e9");
    Variable v;
    SetVariable(v,c1).exec();
    ComparisonGT comp(v,c2);
    FunctionMultiply f1(v,c1);
    SetVariable sv(v,f1);
    std::vector<StackedBlock*> b={&sv};
    RepeatUntilBlock ru(comp,b);
    ru.exec();
    LooksSay(v).exec();
    /*Constant c1("69"),c2("70"),c3("1");
    Variable v;
    ComparisonLT comp(v,c2);
    LooksSay(comp).exec();
    SetVariable(v,c1).exec();
    LooksSay(comp).exec();
    FunctionAdd f1(v,c3);
    SetVariable(v,f1).exec();
    LooksSay(comp).exec();
   */ 
}
{
    // Test variable operations 
    Constant banner("--- VARIABLE OPERATION TEST ---");
    LooksSay sayBanner(banner);
    sayBanner.exec();
    Constant ree("REEE");
    Variable v; 
    LooksSay(v).exec();
    SetVariable sv(v,ree);
    sv.exec();
    LooksSay(v).exec();
    Constant c1("69"),c2("420");
    FunctionAdd f1(c1,c2);
    SetVariable sv2(v,f1);
    sv2.exec();
    LooksSay(v).exec();
}
{
    // Test list operations 
    Constant banner("--- LIST OPERATION TEST ---");
    LooksSay sayBanner(banner);
    sayBanner.exec();
    List l;
    LooksSay(l).exec();
    Constant c1("2"),c2("3"),c3("5"),c4("bf"),c5("4"),c6("1");
    ListAddItem a1(l,c1);
    a1.exec();
    LooksSay(l).exec();
    ListAddItem a2(l,c2),a3(l,c3);
    a3.exec();
    a2.exec();
    LooksSay(l).exec();
    ListReplaceItem r1(l,c2,c4);
    r1.exec();
    LooksSay(l).exec();
    ListLength listLength(l);
    LooksSay(listLength).exec();
    a1.exec();
    LooksSay(l).exec();
    LooksSay(listLength).exec();
    ListDeleteAll rmrf(l);
    rmrf.exec();
    LooksSay(l).exec();
    LooksSay(listLength).exec();
}
}
