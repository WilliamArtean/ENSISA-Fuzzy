cmake_minimum_required(VERSION 3.15)
project(CLionTest)

set(CMAKE_CXX_STANDARD 14)


include_directories("C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/VC/Tools/MSVC/14.24.28314/bin/Hostx86/x86/*")

add_executable(CLionTest main.cpp Core/Expression.h Core/ValueModel.h Core/UnaryExpression.h Core/UnaryExpressionModel.h Fuzzy/NotMinus1.h Fuzzy/IsTriangle.h Core/BinaryExpression.h Core/BinaryExpressionModel.h Fuzzy/Operator.h Fuzzy/OrMax.h Fuzzy/AndMin.h Fuzzy/AndMult.h Fuzzy/OrPlus.h Fuzzy/ThenMin.h Fuzzy/ThenMult.h Fuzzy/AggMax.h Fuzzy/AggPlus.h Core/NaryExpression.h Core/NaryExpressionModel.h Fuzzy/SugenoDefuzz.h Fuzzy/SugenoThen.h Fuzzy/SugenoConclusion.h Fuzzy/MamdaniDefuzz.h Core/ExpressionFactory.h Fuzzy/FuzzyFactory.h Core/BinaryShadowExpression.h Core/UnaryShadowExpression.h Fuzzy/Agg.h Fuzzy/Not.h Fuzzy/Or.h Fuzzy/Is.h Fuzzy/And.h Fuzzy/Then.h Fuzzy/CogDefuzz.h Compiler/fuzzy_driver.cpp Compiler/fuzzy_driver.h Compiler/test.cpp Compiler/fuzzy_parser.tab.cc Compiler/fuzzy_parser.tab.hh Compiler/lex.yy.cc Compiler/location.hh Compiler/position.hh Compiler/stack.hh Compiler/fuzzy_adaptor.h Core/NaryShadowExpression.h)

