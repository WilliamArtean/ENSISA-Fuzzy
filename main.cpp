#include <iostream>
#include <cassert>
#include <cmath>

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
#include "Fuzzy/CogDefuzz.h"
#include "Fuzzy/IsGbellmf.h"
#include "Fuzzy/IsGaussianmf.h"
#include "Fuzzy/IsTriangle.h"
#include "Fuzzy/SugenoThen.h"
#include "Fuzzy/SugenoConclusion.h"
#include "Fuzzy/SugenoDefuzz.h"
#include "Compiler/fuzzy_driver.h"
#include "Compiler/fuzzy_adaptor.h"
#include "Core/NaryShadowExpression.h"


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
    core::BinaryExpressionModel<double> bem;
    core::ValueModel<double> vm(0.2);
    core::ValueModel<double> vm2(0.5);
    assert(bem.evaluate() == 0);
    assert(bem.evaluate(&vm, &vm2) == 0);
    std::cout << std::endl << "valued ctor test BinaryExpressionModel double";
    fuzzy::AndMin<double> am;
    core::BinaryExpressionModel<double> bem2(&am, &vm, &vm2);
    assert(bem2.evaluate() == 0.2);
    assert(bem2.evaluate(&vm, &vm2) == 0.2);
}

void testBuildShape() {
    std::cout << std::endl << "build shape test double" << std::endl;
    fuzzy::CogDefuzz<double> md;
    core::ValueModel<double> x(0);
    core::ValueModel<double> y(0.02);
    fuzzy::OrPlus<double> op;
    core::BinaryExpressionModel<double> bem(&op, &x, &y);
    md.PrintShape(std::cout, md.BuildShape(0,1,0.1, &x, &bem));
}

void testValuedConstructorCog() {
    std::cout << std::endl << "cog valued constructor test";
    core::ValueModel<double> x(0.1);
    core::ValueModel<double> y(0.5);
    fuzzy::OrPlus<double> op;
    core::BinaryExpressionModel<double> bem(&op, &x, &y);
    fuzzy::CogDefuzz<double> cogD(&x, &bem,5, 7, 8);
    assert(cogD.getMin() == 5);
    assert(cogD.getMax() == 7);
    assert(cogD.getStep() == 8);
    assert(cogD.getValue()->evaluate() == 0.1);
    assert(((core::BinaryExpressionModel<double>*)(cogD.getExpression()))->evaluate() == bem.evaluate());
}

void testMamdaniCogDefuzz() {
    std::cout << std::endl << "Test Defuzz CogDefuzz/MamdaniDefuzz";
    core::ValueModel<double> x(0);
    core::ValueModel<double> y(0.1);
    fuzzy::OrPlus<double> op;
    core::BinaryExpressionModel<double> bem(&op, &x, &y);
    fuzzy::CogDefuzz<double> cogD;
    fuzzy::CogDefuzz<double>::Shape s = cogD.BuildShape(0,0.5,0.1, &x, &bem);
    assert(round(100*cogD.Defuzz(s)) == 35);
}

void testMamdaniCogEvaluate() {
    std::cout << std::endl << "Test Evaluate CogDefuzz/MamdaniDefuzz";
    core::ValueModel<double> x(0);
    core::ValueModel<double> y(0.1);
    fuzzy::OrPlus<double> op;
    core::BinaryExpressionModel<double> bem(&op, &x, &y);
    fuzzy::CogDefuzz<double> cogD(&x, &bem, 0, 0.5, 0.1);
    assert(round(100*cogD.Evaluate()) == 35);
}

void testNaryExpressionModel() {
    std::cout << std::endl << "default ctor test NaryExpressionModel double";
    core::NaryExpressionModel<double> nem;

    std::cout << std::endl << "valued ctor test NaryExpressionModel double";
    //SugenoConclusion
    std::vector<double> coeffs = {0.5, 0.1, 0.2};
    fuzzy::SugenoConclusion<double> sc1(coeffs);

    fuzzy::SugenoDefuzz<double> sd1;

    //Vector des valeurs d'entrée
    core::ValueModel<double> vm1(0.1);
    core::ValueModel<double> vm2(0.2);
    core::ValueModel<double> vm3(0.3);
    fuzzy::SugenoThen<double> st;
    core::BinaryExpressionModel<double> bem1(&st, &vm1, &vm2);
    core::BinaryExpressionModel<double> bem2(&st, &vm3, &vm1);


    vector<core::Expression<double> *> inputs = {&bem1, &bem2};

    core::NaryExpressionModel<double> nem2(&sd1, inputs);

    //std::cout << std::endl << nem2.evaluate();
    assert(nem2.evaluate() == 0.125);

    //Deuxième vecteur - test de evaluate() avec paramètres

    //std::cout << std::endl << nem2.evaluate(inputs);
    assert(nem2.evaluate(inputs) == 0.125);
}

void testSugenoConclusion() {
    std::cout << std::endl << "default ctor test SugenoConclusion double";
    fuzzy::SugenoConclusion<double> sugenoConclusionNull;

    std::cout << std::endl << "valued ctor test SugenoConclusion double";
    std::vector<double> coeffs = {0.5, 0.1, 0.2};

    core::ValueModel<double> vm(0.3);
    core::ValueModel<double> vm2(0.5);
    core::ValueModel<double> vm3(0.8);
    fuzzy::AndMin<double> am;
    core::BinaryExpressionModel<double> bem1(&am, &vm, &vm2);
    core::BinaryExpressionModel<double> bem2(&am, &vm3, &vm);
    vector<core::Expression<double> *> operands = {&bem1, &bem2};

    fuzzy::SugenoConclusion<double> sc1(coeffs);

    assert(sc1.evaluate(operands) == 0.38);
}

void testSugenoThen() {
    std::cout << std::endl << "default ctor test SugenoThen double";
    fuzzy::SugenoThen<double> st;

    //SugenoConclusion et BinaryExpressionModel
    std::vector<double> coeffs = {0.5, 0.1, 0.2};
    fuzzy::SugenoConclusion<double> sc1(coeffs);
    core::ValueModel<double> vm1(0.3);
    core::ValueModel<double> vm2(0.5);
    fuzzy::AndMin<double> am;
    core::BinaryExpressionModel<double> bem1(&am, &vm1, &vm2);

    assert(st.evaluate(&vm2, &bem1) == 0.3);
    assert(st.getPremiseValue() == 0.5);
}

void testSugenoDefuzz() {
    //vector de SugenoThen
    std::vector<double> coeffs = {0.5, 0.1, 0.2};
    fuzzy::SugenoConclusion<double> sc1(coeffs);
    core::ValueModel<double> vm1(0.4);
    core::ValueModel<double> vm2(0.5);
    core::ValueModel<double> vm3(0.6);

    fuzzy::SugenoThen<double> st;

    core::BinaryExpressionModel<double> bem1(&st, &vm1, &vm2);
    core::BinaryExpressionModel<double> bem2(&st, &vm3, &vm1);


    vector<core::Expression<double> *> operands = {&bem1, &bem2};

    std::cout << std::endl << "test SugenoDefuzz double";
    fuzzy::SugenoDefuzz<double> sd;

    //std::cout << std::endl << sd.evaluate(operands);
    assert(sd.evaluate(operands) == 0.44);
}

void testNaryShadowExpression() {
    std::vector<double> coeffs = {0.5, 0.1, 0.2};
    fuzzy::SugenoConclusion<double> sc1(coeffs);
    core::ValueModel<double> vm1(0.4);
    core::ValueModel<double> vm2(0.5);
    core::ValueModel<double> vm3(0.6);
    fuzzy::SugenoThen<double> st;
    core::BinaryExpressionModel<double> bem1(&st, &vm1, &vm2);
    core::BinaryExpressionModel<double> bem2(&st, &vm3, &vm1);
    vector<core::Expression<double> *> operands = {&bem1, &bem2};

    fuzzy::SugenoDefuzz<double> sd;

    std::cout << std::endl << "test NaryShadowExpression double";
    core::NaryShadowExpression<double> nse;
    nse.setTarget(&sd);
    assert(nse.getTarget() == &sd);
    assert(nse.evaluate(operands) == 0.44);
}

void testExpressions() {
    testValueModel();
    testUnaryExpressionModel();
    testBinaryExpressionModel();
    testValuedConstructorCog();
    testNaryExpressionModel();
}


void testOperator() {
    testNotMinus1();
    testAndMin();
}


void testSugeno() {
    testSugenoConclusion();
    testSugenoDefuzz();
    testSugenoThen();
}

void testShadowExpressions() {
    testNaryShadowExpression();
}

int testCompiler() {
    int res = 0;
    fuzzy_adaptor<double> adaptor;
    fuzzy_driver driver;
    if (false)  //show parcing
    driver.trace_parsing = true;
    if (false)  //show scanning
    driver.trace_scanning = true;
    if (!driver.parse ("Compiler/instructions.txt")) {
        adaptor.adapt(driver.result);
    }
    res = 1;
    return res;
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

    core::BinaryExpressionModel<int> bem3(&thenMult, &vmint, &vmint2);
    assert(bem3.evaluate() == 42*-1085);



    testExpressions();
    testOperator();
    testValueModel();
    testNotMinus1();
    testAndMin();
    testSugeno();
    testBuildShape();
    testMamdaniCogDefuzz();
    testMamdaniCogEvaluate();
    testShadowExpressions();


    //Omar Testing Part
    //testing IsTriangle
    std::cout <<  std::endl <<"isTriangle";
    core::ValueModel<float> vmForTriangle;
    vmForTriangle.setValue(3.5);
    fuzzy::IsTriangle<float> isTriangle(1,4,5);
    std::cout << std::endl<<isTriangle.evaluate(&vmForTriangle);



    //testing isGaussian
    std::cout <<  std::endl <<"is Gaussian";
    core::ValueModel<float> vmForGaussian;
    vmForGaussian.setValue(0);
    fuzzy::IsGaussianmf<float> isGaussianmf(0.5, 0);
    std::cout << std::endl<<isGaussianmf.evaluate(&vmForGaussian);

    //testing isGbellmf
    std::cout <<  std::endl <<"is GBell";
    core::ValueModel<float> vmForGbell;
    vmForGbell.setValue(100);
    fuzzy::IsGbellmf<float> isGbellmf(20,4,100);
    std::cout << std::endl<<isGbellmf.evaluate(&vmForGbell);

    //Compiler
    testCompiler();

    return 0;
}

