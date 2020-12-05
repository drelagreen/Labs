#pragma once
#include "Triad.h"
#include "SpecialRoundType.h"

class Date :
    public Triad
{
private:
    
public:
    static const int MAX_A = 31;
    static const int MAX_B = 12;
    static const int MAX_C = 10000;
    Date(int a, int b, int c) : Triad(MAX_A, MAX_B, MAX_C, a, b, c) {
    }

    void specialRound(int* a, int* b, int* c, SpecialRoundType flag) override;
};

