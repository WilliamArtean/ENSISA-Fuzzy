#include <iostream>
#include <cassert>

#include "Core/ValueModel.h"
#include "Core/UnaryExpressionModel.h"
#include "Core/BinaryExpressionModel.h"
#include "Core/NaryExpressionModel.h"
#include "Fuzzy/NotMinus1.h"
#include "Fuzzy/OrMax.h"
#include "Fuzzy/AndMin.h"
#include "Fuzzy/AndMult.h"
#include "Fuzzy/OrPlus.h"
#include "Fuzzy/ThenMin.h"
#include "Fuzzy/ThenMult.h"
#include "Fuzzy/AggMax.h"
#include "Fuzzy/AggPlus.h"


void testAndMin();

void testBinaryExpressionModel();

void testValueModel() {
    std::cout << std::endl << "default ctor test ValueModel int";
    core::ValueModel<int> vm;
    std::cout << std::endl << "defaultValue int : " << vm.evaluate();
    vm.setValue(5);
    assert(vm.evaluate() == 5);
    std::cout << std::endl << "valued ctor test ValueModel int";
    core::ValueModel<int> vm2(10);
    assert(vm2.evaluate() == 10);
}

void testNotMinus1() {
    std::cout << std::endl << "test NotMinus1";
    fuzzy::NotMinus1<double> nm1;
    core::ValueModel<double> vm(0.2);
    assert(nm1.evaluate(&vm) == 0.8);
}

void testUnaryExpressionModel() {
    std::cout << std::endl << "default ctor test UnaryExpressionModel double";
    core::UnaryExpressionModel<double> uem;
    core::ValueModel<double> vm(0.2);
    assert(uem.evaluate() == 0);
    assert(uem.evaluate(&vm) == 0);
    std::cout << std::endl << "valued ctor test UnaryExpressionModel double";
    fuzzy::NotMinus1<double> nm1;
    core::UnaryExpressionModel<double> uem2(&nm1,&vm);
    assert(uem2.evaluate() == 0.8);
    assert(uem2.evaluate(&vm) == 0.8);
}

void testAndMin() {
    std::cout << std::endl << "test AndMin";
    core::ValueModel<double> vm(0.2);
    core::ValueModel<double> vm2(0.5);
    fuzzy::AndMin<double> am;
    assert(am.evaluate(&vm, &vm2) == vm.evaluate());
}


void testBinaryExpressionModel() {
    std::cout << std::endl << "default ctor test BinaryExpressionModel double";
    core::BinaryExpressionModel<double> uem;
    core::ValueModel<double> vm(0.2);
    core::ValueModel<double> vm2(0.5);
    assert(uem.evaluate() == 0);
    assert(uem.evaluate(&vm, &vm2) == 0);
    std::cout << std::endl << "valued ctor test BinaryExpressionModel double";
    fuzzy::AndMin<double> am;
    core::BinaryExpressionModel<double> uem2(&am, &vm, &vm2);
    assert(uem2.evaluate() == 0.2);
    assert(uem2.evaluate(&vm, &vm2) == 0.2);
}

void testNaryExpressionModel() {
    std::cout << std::endl << "default ctor test NaryExpressionModel double";
    core::NaryExpressionModel<double> nem;
}

void testExpressions() {
    testValueModel();
    testUnaryExpressionModel();
    testBinaryExpressionModel();
    testNaryExpressionModel();
}


void testOperator() {
    testNotMinus1();
    testAndMin();
}

void testNaryExpression() {

}


int main() {
    std::cout << std::endl << "Test ValueModel";
    core::ValueModel<int> vmint = core::ValueModel<int>(15);
    core::ValueModel<int> vmint2 = core::ValueModel<int>(-1085);
    assert(vmint.evaluate() == 15);
    vmint.setValue(42);
    assert(vmint.evaluate() == 42);
    core::ValueModel<double> vmdouble = core::ValueModel<double>(0.1);
    core::ValueModel<double> vmdouble2 = core::ValueModel<double>(165.44);



    std::cout << std::endl << "Test NotMinus1 (int and double)";
    fuzzy::NotMinus1<int> opNot = fuzzy::NotMinus1<int>();
    assert(opNot.evaluate(&vmint) == -41);

    fuzzy::NotMinus1<double> opNotDouble = fuzzy::NotMinus1<double>();
    assert(opNotDouble.evaluate(&vmdouble) == 0.9);


    std::cout << std::endl << "Test UnaryExpressionModel (with NotMinus1)";
    core::UnaryExpressionModel<int> uem1 = core::UnaryExpressionModel<int>(&opNot, &vmint);
    assert(uem1.evaluate() == -41);
    core::UnaryExpressionModel<int> uem2 = core::UnaryExpressionModel<int>();



    std::cout << std::endl << "Test OrMax";
    fuzzy::OrMax<int> orMax = fuzzy::OrMax<int>();
    assert(orMax.evaluate(&vmint, &vmint2) == 42);

    fuzzy::OrMax<double> orMaxDouble = fuzzy::OrMax<double>();
    assert(orMaxDouble.evaluate(&vmdouble, &vmdouble2) == 165.44);


    std::cout << std::endl << "Test OrPlus";
    fuzzy::OrPlus<int> orPlus = fuzzy::OrPlus<int>();
    assert(orPlus.evaluate(&vmint, &vmint2) == 42-1085);

    fuzzy::OrPlus<double> orPlusDouble = fuzzy::OrPlus<double>();
    assert(orPlusDouble.evaluate(&vmdouble, &vmdouble2) == 1);


    std::cout << std::endl << "Test AndMin";
    fuzzy::AndMin<int> andMin = fuzzy::AndMin<int>();
    assert(andMin.evaluate(&vmint, &vmint2) == -1085);

    fuzzy::AndMin<double> andMinDouble = fuzzy::AndMin<double>();
    assert(andMinDouble.evaluate(&vmdouble, &vmdouble2) == 0.1);


    std::cout << std::endl << "Test AndMult";
    fuzzy::AndMult<int> andMult = fuzzy::AndMult<int>();
    assert(andMult.evaluate(&vmint, &vmint2) == 42*-1085);

    fuzzy::AndMult<double> andMultDouble = fuzzy::AndMult<double>();
    assert(andMultDouble.evaluate(&vmdouble, &vmdouble2) == 0.1*165.44);


    std::cout << std::endl << "Test ThenMin";
    fuzzy::ThenMin<int> thenMin = fuzzy::ThenMin<int>();
    assert(thenMin.evaluate(&vmint, &vmint2) == -1085);

    fuzzy::ThenMin<double> thenMinDouble = fuzzy::ThenMin<double>();
    assert(thenMinDouble.evaluate(&vmdouble, &vmdouble2) == 0.1);


    std::cout << std::endl << "Test AndMult";
    fuzzy::ThenMult<int> thenMult = fuzzy::ThenMult<int>();
    assert(thenMult.evaluate(&vmint, &vmint2) == 42*-1085);

    fuzzy::ThenMult<double> thenMultDouble = fuzzy::ThenMult<double>();
    assert(thenMultDouble.evaluate(&vmdouble, &vmdouble2) == 0.1*165.44);


    std::cout << std::endl << "Test AggMax";
    fuzzy::AggMax<int> aggMax = fuzzy::AggMax<int>();
    assert(aggMax.evaluate(&vmint, &vmint2) == 42);

    fuzzy::AggMax<double> aggMaxDouble = fuzzy::AggMax<double>();
    assert(aggMaxDouble.evaluate(&vmdouble, &vmdouble2) == 165.44);


    std::cout << std::endl << "Test AggPlus";
    fuzzy::AggPlus<int> aggPlus = fuzzy::AggPlus<int>();
    assert(aggPlus.evaluate(&vmint, &vmint2) == 42-1085);

    fuzzy::AggPlus<double> aggPlusDouble = fuzzy::AggPlus<double>();
    assert(aggPlusDouble.evaluate(&vmdouble, &vmdouble2) == 1);


    std::cout << std::endl << "Test BinaryExpressionModel";
    core::BinaryExpressionModel<double> bem1 = core::BinaryExpressionModel<double>(&orMaxDouble, &vmdouble, &vmdouble2);
    assert(bem1.evaluate() == 165.44);
    core::BinaryExpressionModel<int> bem2 = core::BinaryExpressionModel<int>();

    core::BinaryExpressionModel<int> bem3 = core::BinaryExpressionModel<int>(&thenMult, &vmint, &vmint2);
    assert(bem3.evaluate() == 42*-1085);


    testExpressions();
    testOperator();

    return 0;
}
