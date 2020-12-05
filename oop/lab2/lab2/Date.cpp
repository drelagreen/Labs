#include "Date.h"

void Date::specialRound(int* a, int* b, int* c, SpecialRoundType flag) {
    if (flag == DECREMENT) {
        if (*a >= 31)
            switch (*b) {
            case 2:
                if (*c % 4 == 0 && (*c % 100 != 0 || *c % 100 == 0)) {
                    (*a) = 29;
                }
                else {
                    (*a) = 28;
            case 4:
            case 6:
            case 9:
            case 11:
                (*a) = 30;
            default:
                break;
                }
            }
    }
    else if (flag == INCREMENT) {
        switch (*b)
        {
        case 2:
            if (*a == 29 && !(*c % 4 == 0 && (*c % 100 != 0 || *c % 100 == 0))) {
                (*a) += 1;
            }
        case 4:
        case 6:
        case 9:
        case 11:
            if (*a == 30) {
                (*a) += 2;
            }
        default:
            break;
        }
    }
    else if (flag == NULL_DECREMENT) {
        if (*a <= 0) {
            *a = -1;
        }
        if (*b <= 0) {
            *b = -1;
        }
        if (*c <= 0) {
            *c = -1;
        }
    }
    else if (flag == NULL_INCREMENT) {
        if (*a <= 0) {
            *a = 1;
        }
        if (*b <= 0) {
            *b = 1;
        }
        if (*c <= 0) {
            *c = 1;
        }
    }
}