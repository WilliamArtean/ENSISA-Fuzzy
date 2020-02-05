//
// Created by CHICHAOUI Omar on 05/02/2020.
//

#ifndef CLIONTEST_COGDEFUZZ_H
#define CLIONTEST_COGDEFUZZ_H

#include "MamdaniDefuzz.h"

namespace fuzzy {
    template <class T>
    class CogDefuzz: public MamdaniDefuzz<T>
    {
    public:
        CogDefuzz();


    };
}

#endif //CLIONTEST_COGDEFUZZ_H
