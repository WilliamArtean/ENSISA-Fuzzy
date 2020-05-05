//
// Created by coscoy on 02/05/2020.
//

#ifndef CLIONTEST_FUZZY_ADAPTOR_H
#define CLIONTEST_FUZZY_ADAPTOR_H

# include <string>
# include <map>
#include "../Fuzzy/FuzzyFactory.h"
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
    core::Expression<T>* iswofactory(std::vector<std::string>::const_iterator);
    core::Expression<T>* phrasewofactory(std::vector<std::string>::const_iterator);


    fuzzy::FuzzyFactory<T>* factory;
public:
    void adapt(std::vector<std::string>);

    std::map<std::string, core::Expression<T>*> variables;

    fuzzy_adaptor();
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
    factory = new fuzzy::FuzzyFactory<T>((fuzzy::And<T>*)variables["and"],(fuzzy::Or<T>*)variables["or"],(fuzzy::Not<T>*)variables["not"],(fuzzy::Then<T>*)variables["then"],(fuzzy::Agg<T>*)variables["agg"]);
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
    bool first = true;
    core::Expression<T>* res;
    for (auto ph : phrases) {
        if (first) {
            res = ph;
            first = false;
        } else {
            res = factory->newAgg(res, ph);
            //res = new fuzzy::AggMax<T>(*res,*ph);
        }
    }
    variables.insert( std::pair<std::string, core::Expression<T>*>("result",res));
}

template<class T>
core::Expression<T> *fuzzy_adaptor<T>::phrase(std::vector<std::string>::const_iterator it) {
    auto it2 = it;
    core::Expression<T>* val;
    while (*it != "then") {
        std::cout << *it << std::endl;
        it++;
    }
    val = factory->NewThen(is(it2),is(it));
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
        v2 = factory->NewNot(variables[*it]);
    } else {
        it++;
        v2 = variables[*it];
    }
    it++;
    auto* is = factory->NewIs(v1,v2);
    if (*it == "and") {
       return factory->NewAnd(is,is(it));
    } else if (*it == "or") {
        return factory->NewOr(is,is(it));
    }
    return is;
}

template<class T>
fuzzy_adaptor<T>::fuzzy_adaptor() {

}
/*
template<class T>
core::Expression<T> *fuzzy_adaptor<T>::phrasewofactory(std::vector<std::string>::const_iterator it) {
    auto it2 = it;
    core::Expression<T>* val;
    while (*it != "then") {
        std::cout << *it << std::endl;
        it++;
    }
    //val = factory->NewThen(is(it2),is(it));
    val = new fuzzy::ThenMin<T>(iswofactory(it2),iswofactory(it));
    return val;
}

template<class T>
core::Expression<T> *fuzzy_adaptor<T>::iswofactory(std::vector<std::string>::const_iterator it) {
    core::Expression<T>* v1;
    core::Expression<T>* v2;
    v1 = variables[*it];
    it++;
    if (*it == "not") {
        it++;
        //v2 = factory->NewNot(variables[*it]);
        v2 = new fuzzy::NotMinus1<T>(variables[*it]);
    } else {
        it++;
        v2 = variables[*it];
    }
    it++;
    //auto* is = factory->NewIs(v1,v2);
    auto* is = new core::UnaryExpression<T>(v2,v1);
    if (*it == "and") {
        //   return factory->NewAnd(is,is(it));
        return fuzzy::AndMin<T>(is,is(it));
    } else if (*it == "or") {
        //    return factory->NewOr(is,is(it));
        return fuzzy::OrMax<T>(is,is(it));
    }
    return is;
}
*/
#endif //CLIONTEST_FUZZY_ADAPTOR_H
