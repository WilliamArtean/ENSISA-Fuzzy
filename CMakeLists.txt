cmake_minimum_required(VERSION 3.15)
project(CLionTest)

set(CMAKE_CXX_STANDARD 14)

add_executable(CLionTest main.cpp Core/Expression.h Core/ValueModel.h Core/UnaryExpression.h Core/UnaryExpressionModel.h Fuzzy/NotMinus1.h Fuzzy/IsTriangle.h Core/BinaryExpression.h Core/BinaryExpressionModel.h Fuzzy/Operator.h Fuzzy/OrMax.h Fuzzy/AndMin.h Fuzzy/AndMult.h Fuzzy/OrPlus.h Fuzzy/ThenMin.h Fuzzy/ThenMult.h Fuzzy/AggMax.h Fuzzy/AggPlus.h Fuzzy/MamdaniDefuzz.h Core/ExpressionFactory.h Fuzzy/FuzzyFactory.h Core/BinaryShadowExpression.h Core/UnaryShadowExpression.h Fuzzy/CogDefuzz.h Fuzzy/Agg.h Fuzzy/Not.h Fuzzy/Or.h Fuzzy/Is.h Fuzzy/And.h Fuzzy/Then.h)