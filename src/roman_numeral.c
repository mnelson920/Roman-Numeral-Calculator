#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
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
        //default:
            //fprintf(stderr,"error: Invalid Roman Numeral '%c' \n", letter);
            //exit(1);
    }
    return 0;
}

extern int romanToInt(char* s)
{
    int result = 0;
    int tmp = 1;
    int value1 = 0, value2 = 0;

    for (int index = 0; index < strlen(s); index = tmp + index)
    {
        tmp = 1;
        value1 = romanLetterValue(s[index]);
        value2 = romanLetterValue(s[index + 1]);
        if ((value1 < value2) && (value2 != 0))
        {
            result = value2 - value1 + result;
            tmp = 2;
        }
        else{
            result = value1 +result;
        }
    }
    return result;
}