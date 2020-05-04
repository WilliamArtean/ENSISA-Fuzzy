//
// Created by coscoy on 02/05/2020.
//

#ifndef CLIONTEST_FUZZY_ADAPTOR_H
#define CLIONTEST_FUZZY_ADAPTOR_H

# include <string>
# include <map>
#include <FuzzyFactory.h>
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
private:
    core::Expression<T>* is(std::vector<std::string>::const_iterator);
    core::Expression<T>* phrase(std::vector<std::string>::const_iterator);
    std::map<std::string, core::Expression<T>*> variables;
    //fuzzy::FuzzyFactory<T> factory;
public:
    void adapt(std::vector<std::string>);
};

template<class T>
void fuzzy_adaptor<T>::adapt(std::vector<std::string> input) {
    std::vector<std::string>::const_iterator it = input.begin();
    std::vector<core::Expression<T>> expressions;
    if (*it == "AndMin") {
        auto* oper = new fuzzy::AndMin<T>();
        variables.insert( std::pair<std::string, core::Expression<T>*>("and",((core::Expression<T>*)oper)));
    } else if (*it == "AndMult") {
        auto* oper = new fuzzy::AndMult<T>();
        variables.insert( std::pair<std::string, core::Expression<T>*>("and",((core::Expression<T>*)oper)));
    } else {
        auto* oper = new fuzzy::AndMin<T>();
        variables.insert( std::pair<std::string, core::Expression<T>*>("and",((core::Expression<T>*)oper)));
    }
    ++it;
    if (*it == "OrMax") {
        auto* oper = new fuzzy::OrMax<T>();
        variables.insert( std::pair<std::string, core::Expression<T>*>("or",((core::Expression<T>*)oper)));
    } else if (*it == "OrPlus") {
        auto* oper = new fuzzy::OrPlus<T>();
        variables.insert( std::pair<std::string, core::Expression<T>*>("or",((core::Expression<T>*)oper)));
    } else {
        auto* oper = new fuzzy::OrMax<T>();
        variables.insert( std::pair<std::string, core::Expression<T>*>("or",((core::Expression<T>*)oper)));
    }
    ++it;
    if (*it == "ThenMin") {
        auto* oper = new fuzzy::ThenMin<T>();
        variables.insert( std::pair<std::string, core::Expression<T>*>("then",((core::Expression<T>*)oper)));
    } else if (*it == "ThenMult") {
        auto* oper = new fuzzy::ThenMult<T>();
        variables.insert( std::pair<std::string, core::Expression<T>*>("then",((core::Expression<T>*)oper)));
    } else {
        auto* oper = new fuzzy::ThenMin<T>();
        variables.insert( std::pair<std::string, core::Expression<T>*>("then",((core::Expression<T>*)oper)));
    }
    ++it;
    if (*it == "CogDefuzz") {
        auto* oper = new fuzzy::CogDefuzz<T>();
        variables.insert( std::pair<std::string, core::Expression<T>*>("defuzz",((core::Expression<T>*)oper)));
    } else {
        auto* oper = new fuzzy::CogDefuzz<T>();
        variables.insert( std::pair<std::string, core::Expression<T>*>("defuzz",((core::Expression<T>*)oper)));
    }
    ++it;
    if (*it == "AggMax") {
        auto* oper = new fuzzy::AggMax<T>();
        variables.insert( std::pair<std::string, core::Expression<T>*>("agg",((core::Expression<T>*)oper)));
    } else if (*it == "AggPlus") {
        auto* oper = new fuzzy::AggPlus<T>();
        variables.insert( std::pair<std::string, core::Expression<T>*>("agg",((core::Expression<T>*)oper)));
    } else {
        auto* oper = new fuzzy::AggMax<T>();
        variables.insert( std::pair<std::string, core::Expression<T>*>("agg",((core::Expression<T>*)oper)));
    }
    ++it;
    auto* oper = new fuzzy::NotMinus1<T>();
    variables.insert( std::pair<std::string, core::Expression<T>*>("not",((core::Expression<T>*)oper)));
    //factory(variables["and"],variables["or"],variables["not"],variables["then"],variables["agg"]);
    bool membership = true;
    while (membership) {
        if (*it == "triangle") {
            double min, max, step;
            it++;
            min = atof(it++->c_str());
            max = atof(it++->c_str());
            step = atof(it++->c_str());
            std::string name = *it++;
            auto* shape = new fuzzy::IsTriangle<T>(min, max, step);
            variables.insert(std::pair<std::string, core::Expression<T> *>(name, ((core::Expression<T> *) shape)));
        } else
            membership = false;
    }
    while (*it != "newphrase") {
        std::string name = *it++;
        auto* vm = new core::ValueModel<T>(atof(it++->c_str()));
        variables.insert( std::pair<std::string, core::Expression<T>*>(name,((core::Expression<T>*)vm)));
    }
    std::vector<core::Expression<T>*> phrases;
    while (it != input.end()) {
        if (*it == "newphrase"){
            phrases.push_back(phrase(it));
        }
        it++;
    }
}

template<class T>
core::Expression<T> *fuzzy_adaptor<T>::phrase(std::vector<std::string>::const_iterator it) {
    auto it2 = it;
    core::Expression<T>* val;
    while (*it != "then") {
        std::cout << *it << std::endl;
        it++;
    }
    //val = factory.NewThen(is(it2),is(it));
    return val;
}

template<class T>
core::Expression<T> *fuzzy_adaptor<T>::is(std::vector<std::string>::const_iterator it) {
    core::Expression<T>* v1;
    core::Expression<T>* v2;
    v1 = variables[*it];
    it++;
    if (*it == "not") {
        it++;
        //v2 = factory.NewNot(variables[*it]);
    } else {
        it++;
        v2 = variables[*it];
    }
    it++;
    //auto* is = factory.NewIs(v1,v2);
    if (*it == "and") {
    //   return factory.NewAnd(is,is(it));
    } else if (*it == "or") {
    //    return factory.NewOr(is,is(it));
    }
    return is;
}

#endif //CLIONTEST_FUZZY_ADAPTOR_H
