#include <stdio.h>
#include <stdlib.h>
#include "roman_numeral.h"

extern int romanLetterValue(char letter)
{
    switch (letter){
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default:
            fprintf(stderr,"error: Invalid Roman Numeral '%c' \n", letter);
            exit(1);
    }
}