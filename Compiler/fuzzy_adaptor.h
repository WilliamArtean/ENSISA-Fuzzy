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


    fuzzy::FuzzyFactory<T>* factory;
public:
    std::map<std::string, core::Expression<T>*> variables;

    T defuzz(std::string, T min, T max, T step);
    void adapt(std::vector<std::string>);


    fuzzy_adaptor();
};

template<class T>
void fuzzy_adaptor<T>::adapt(std::vector<std::string> input) {
    std::vector<std::string>::const_iterator it = input.begin();
    std::vector<core::Expression<T>> expressions;
    if (*it == "AndMin") {
        auto *oper = new fuzzy::AndMin<T>();
        variables.insert(std::pair<std::string, core::Expression<T> *>("and", ((core::Expression<T> *) oper)));
    } else if (*it == "AndMult") {
        auto *oper = new fuzzy::AndMult<T>();
        variables.insert(std::pair<std::string, core::Expression<T> *>("and", ((core::Expression<T> *) oper)));
    } else {
        auto *oper = new fuzzy::AndMin<T>();
        variables.insert(std::pair<std::string, core::Expression<T> *>("and", ((core::Expression<T> *) oper)));
    }
    ++it;
    if (*it == "OrMax") {
        auto *oper = new fuzzy::OrMax<T>();
        variables.insert(std::pair<std::string, core::Expression<T> *>("or", ((core::Expression<T> *) oper)));
    } else if (*it == "OrPlus") {
        auto *oper = new fuzzy::OrPlus<T>();
        variables.insert(std::pair<std::string, core::Expression<T> *>("or", ((core::Expression<T> *) oper)));
    } else {
        auto *oper = new fuzzy::OrMax<T>();
        variables.insert(std::pair<std::string, core::Expression<T> *>("or", ((core::Expression<T> *) oper)));
    }
    ++it;
    if (*it == "ThenMin") {
        auto *oper = new fuzzy::ThenMin<T>();
        variables.insert(std::pair<std::string, core::Expression<T> *>("then", ((core::Expression<T> *) oper)));
    } else if (*it == "ThenMult") {
        auto *oper = new fuzzy::ThenMult<T>();
        variables.insert(std::pair<std::string, core::Expression<T> *>("then", ((core::Expression<T> *) oper)));
    } else {
        auto *oper = new fuzzy::ThenMin<T>();
        variables.insert(std::pair<std::string, core::Expression<T> *>("then", ((core::Expression<T> *) oper)));
    }
    ++it;
    if (*it == "CogDefuzz") {
        auto *oper = new fuzzy::CogDefuzz<T>();
        variables.insert(std::pair<std::string, core::Expression<T> *>("defuzz", ((core::Expression<T> *) oper)));
    } else if (*it != "CogDefuzz") {
            auto *oper = new fuzzy::CogDefuzz<T>();
            variables.insert(std::pair<std::string, core::Expression<T> *>("defuzz", ((core::Expression<T> *) oper)));
        } else {
            auto *oper = new fuzzy::CogDefuzz<T>();
            variables.insert(std::pair<std::string, core::Expression<T> *>("defuzz", ((core::Expression<T> *) oper)));
        }
        ++it;
        if (*it == "AggMax") {
            auto *oper = new fuzzy::AggMax<T>();
            variables.insert(std::pair<std::string, core::Expression<T> *>("agg", ((core::Expression<T> *) oper)));
        } else if (*it == "AggPlus") {
            auto *oper = new fuzzy::AggPlus<T>();
            variables.insert(std::pair<std::string, core::Expression<T> *>("agg", ((core::Expression<T> *) oper)));
        } else {
            auto *oper = new fuzzy::AggMax<T>();
            variables.insert(std::pair<std::string, core::Expression<T> *>("agg", ((core::Expression<T> *) oper)));
        }
        ++it;
        auto *oper = new fuzzy::NotMinus1<T>();
        variables.insert(std::pair<std::string, core::Expression<T> *>("not", ((core::Expression<T> *) oper)));
        factory = new fuzzy::FuzzyFactory<T>((fuzzy::And<T> *) variables["and"], (fuzzy::Or<T> *) variables["or"],
                                             (fuzzy::Not<T> *) variables["not"], (fuzzy::Then<T> *) variables["then"],
                                             (fuzzy::Agg<T> *) variables["agg"],
                                             (fuzzy::CogDefuzz<T> *) variables["defuzz"]);
        bool membership = true;
        while (membership) {
            if (*it == "triangle") {
                double min, mid, max;
                it++;
                min = atof(it++->c_str());
                mid = atof(it++->c_str());
                max = atof(it++->c_str());
                std::string name = *it++;
                auto *shape = new fuzzy::IsTriangle<T>(min, mid, max);
                variables.insert(std::pair<std::string, core::Expression<T> *>(name, ((core::Expression<T> *) shape)));
            } else if (*it == "gaussian") {
                double x, y;
                it++;
                y = atof(it++->c_str());
                x = atof(it++->c_str());
                std::string name = *it++;
                auto *shape = new fuzzy::IsGaussianmf<T>(x, y);
                variables.insert(std::pair<std::string, core::Expression<T> *>(name, ((core::Expression<T> *) shape)));
            } else if (*it == "gbellmf") {
                double x, y, z;
                it++;
                x = atof(it++->c_str());
                y = atof(it++->c_str());
                z = atof(it++->c_str());
                std::string name = *it++;
                auto *shape = new fuzzy::IsGbellmf<T>(x, y, z);
                variables.insert(std::pair<std::string, core::Expression<T> *>(name, ((core::Expression<T> *) shape)));
            }
            else
                membership = false;
        }
        while (*it != "newphrase") {
            std::string name = *it++;
            auto *vm = new core::ValueModel<T>(atof(it++->c_str()));
            variables.insert(std::pair<std::string, core::Expression<T> *>(name, ((core::Expression<T> *) vm)));
        }
        std::vector<core::Expression<T> *> phrases;
        while (it != input.end()) {
            if (*it == "newphrase") {
                phrases.push_back(phrase(it));
            }
            it++;
        }
        bool first = true;
        core::Expression<T> *res;
        for (auto ph : phrases) {

            if (first) {
                res = ph;
                first = false;
            } else {
                res = factory->newAgg(res, ph);
            }

        }
        variables.insert(std::pair<std::string, core::Expression<T> *>("result", res));
}

template<class T>
core::Expression<T> *fuzzy_adaptor<T>::phrase(std::vector<std::string>::const_iterator it) {
    auto it2 = it;
    core::Expression<T>* val = 0;
    while (*it != "then") {
        it++;
    }
    auto* is1 = is(it2);
    auto* is2 = is(it);
    val = factory->newThen(is1,is2);
    return val;
}

template<class T>
core::Expression<T> *fuzzy_adaptor<T>::is(std::vector<std::string>::const_iterator it) {
    core::Expression<T>* v1;
    core::Expression<T>* v2;
    it++;
    v1 = variables[*it];
    it++;
    if (*it == "not") {
        it++;
        std::cout<< "not test ";
        v2 = factory->newNot(variables[*it]);
        //std::cout << v2->evaluate() <<std::endl;
    } else {
        it++;
        v2 = variables[*it];
    }
    it++;
    auto* isval = factory->newIs(v1,(fuzzy::Is<T>*)v2);
    if (*it == "and") {
       return factory->newAnd(isval,is(it));
    } else if (*it == "or") {
        return factory->newOr(isval,is(it));
    }
    return isval;
}

template<class T>
fuzzy_adaptor<T>::fuzzy_adaptor() {

}

template<class T>
T fuzzy_adaptor<T>::defuzz(std::string val, T min, T max, T step) {
    auto* value = variables[val];
    core::Expression<T>* resdef= (factory->newMamdaniDefuzz(((core::ValueModel<T>*)value), variables["result"], min, max, step));
    return resdef->evaluate();
}

#endif //CLIONTEST_FUZZY_ADAPTOR_H
