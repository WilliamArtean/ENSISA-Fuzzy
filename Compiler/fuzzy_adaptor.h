//
// Created by coscoy on 02/05/2020.
//

#ifndef CLIONTEST_FUZZY_ADAPTOR_H
#define CLIONTEST_FUZZY_ADAPTOR_H

# include <string>
# include <map>
#include "../Fuzzy/AndMin.h"
#include "../Core/Expression.h"
#include "../Fuzzy/AndMult.h"
#include "../Fuzzy/OrMax.h"
#include "../Fuzzy/OrPlus.h"
#include "../Core/ValueModel.h"
#include "../Fuzzy/ThenMin.h"
#include "../Fuzzy/ThenMult.h"
#include "../Fuzzy/CogDefuzz.h"
#include "../Fuzzy/AggMax.h"
#include "../Fuzzy/AggPlus.h"
#include "../Fuzzy/NotMinus1.h"
#include "../Fuzzy/IsTriangle.h"

template <class T>
class fuzzy_adaptor{
public:
    std::map<std::string, core::Expression<T>*> adapt(std::vector<std::string>);
};

template<class T>
std::map<std::string, core::Expression<T>*> fuzzy_adaptor<T>::adapt(std::vector<std::string> input) {
    std::map<std::string, core::Expression<T>*> variables;
    typename std::vector<std::string>::const_iterator it= input.begin();
    std::vector<core::Expression<T>> expressions;
    std::cout << *it << std::endl;
    if (*it == "AndMin") {
        fuzzy::AndMin<T> oper = fuzzy::AndMin<T>();
        variables.insert( std::pair<std::string, core::Expression<T>*>("and",((core::Expression<T>*)&oper)));
    } else if (*it == "AndMult") {
        fuzzy::AndMult<T> oper = fuzzy::AndMult<T>();
        variables.insert( std::pair<std::string, core::Expression<T>*>("and",((core::Expression<T>*)&oper)));
    } else {
        fuzzy::AndMin<T> oper = fuzzy::AndMin<T>();
        variables.insert( std::pair<std::string, core::Expression<T>*>("and",((core::Expression<T>*)&oper)));
    }
    ++it;
    std::cout << *it << std::endl;
    if (*it == "OrMax") {
        fuzzy::OrMax<T> oper = fuzzy::OrMax<T>();
        variables.insert( std::pair<std::string, core::Expression<T>*>("or",((core::Expression<T>*)&oper)));
    } else if (*it == "OrPlus") {
        fuzzy::OrPlus<T> oper = fuzzy::OrPlus<T>();
        variables.insert( std::pair<std::string, core::Expression<T>*>("or",((core::Expression<T>*)&oper)));
    } else {
        fuzzy::OrMax<T> oper = fuzzy::OrMax<T>();
        variables.insert( std::pair<std::string, core::Expression<T>*>("or",((core::Expression<T>*)&oper)));
    }
    ++it;
    std::cout << *it << std::endl;
    if (*it == "ThenMin") {
        fuzzy::ThenMin<T> oper = fuzzy::ThenMin<T>();
        variables.insert( std::pair<std::string, core::Expression<T>*>("then",((core::Expression<T>*)&oper)));
    } else if (*it == "ThenMult") {
        fuzzy::ThenMult<T> oper = fuzzy::ThenMult<T>();
        variables.insert( std::pair<std::string, core::Expression<T>*>("then",((core::Expression<T>*)&oper)));
    } else {
        fuzzy::ThenMin<T> oper = fuzzy::ThenMin<T>();
        variables.insert( std::pair<std::string, core::Expression<T>*>("then",((core::Expression<T>*)&oper)));
    }
    ++it;
    std::cout << *it << std::endl;
    if (*it == "CogDefuzz") {
        fuzzy::CogDefuzz<T> oper = fuzzy::CogDefuzz<T>();
        variables.insert( std::pair<std::string, core::Expression<T>*>("defuzz",((core::Expression<T>*)&oper)));
    } else {
        fuzzy::CogDefuzz<T> oper = fuzzy::CogDefuzz<T>();
        variables.insert( std::pair<std::string, core::Expression<T>*>("defuzz",((core::Expression<T>*)&oper)));
    }
    ++it;
    std::cout << *it << std::endl;
    if (*it == "AggMax") {
        fuzzy::AggMax<T> oper = fuzzy::AggMax<T>();
        variables.insert( std::pair<std::string, core::Expression<T>*>("agg",((core::Expression<T>*)&oper)));
    } else if (*it == "AggPlus") {
        fuzzy::AggPlus<T> oper = fuzzy::AggPlus<T>();
        variables.insert( std::pair<std::string, core::Expression<T>*>("agg",((core::Expression<T>*)&oper)));
    } else {
        fuzzy::AggMax<T> oper = fuzzy::AggMax<T>();
        variables.insert( std::pair<std::string, core::Expression<T>*>("agg",((core::Expression<T>*)&oper)));
    }
    ++it;
    fuzzy::NotMinus1<T> oper = fuzzy::NotMinus1<T>();
    variables.insert( std::pair<std::string, core::Expression<T>*>("not",((core::Expression<T>*)&oper)));
    bool membership = true;
    while (membership) {
        if (*it == "triangle") {
            double min, max, step;
            it++;
            min = atof(it++->c_str());
            max = atof(it++->c_str());
            step = atof(it++->c_str());
            std::string name = *it++;
            //fuzzy::IsTriangle<T> shape(&min, &max, &step);
            //variables.insert(std::pair<std::string, core::Expression<T> *>(name, ((core::Expression<T> *) &shape)));
        } else
            membership = false;
    }
    while (*it != "newphrase") {
        std::string name = *it++;
        auto* vm = new core::ValueModel<T>(atof(it++->c_str()));
        variables.insert( std::pair<std::string, core::Expression<T>*>(name,((core::Expression<T>*)vm)));
    }
    while (it != input.end()) {
        std::cout << *it << std::endl;
        it++;
    }
    return variables;
}

#endif //CLIONTEST_FUZZY_ADAPTOR_H
