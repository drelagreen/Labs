#pragma once
#include "Triad.h"
class Time :
    public Triad
{
private:
    static const int MAX_A = 59;
    static const int MAX_B = 59;
    static const int MAX_C = 23;
public:
    Time(int a, int b, int c) : Triad(MAX_A,MAX_B,MAX_C,a,b,c) {
    }
};

