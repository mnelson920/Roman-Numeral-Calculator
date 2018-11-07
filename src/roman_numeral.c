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

extern int sumOfRoman(char* romanOne, char* romanTwo){
   short int firstNum = romanToInt(romanOne);
   short int secondNum = romanToInt(romanTwo);
   printf ("Input 1: %s | Input 2: %s\n", romanOne, romanTwo);
   printf ("The sum of %d and %d is: %d | Roman Numeral: %s\n", firstNum, secondNum, firstNum + secondNum, intToRoman(firstNum+secondNum));
   return firstNum + secondNum;
}

extern int diffOfRoman(char* romanOne, char* romanTwo){
   short int firstNum = romanToInt(romanOne);
   short int secondNum = romanToInt(romanTwo);
   printf ("Input 1: %s | Input 2: %s\n", romanOne, romanTwo);
   printf ("The difference of %d and %d is: %d | Roman Numeral: %s\n", firstNum, secondNum, firstNum - secondNum, intToRoman(firstNum-secondNum));
   return firstNum - secondNum;
}

extern char* intToRoman(short int result){
    char *c[4][10] = {
        {"","I","II","III","IV","V","VI","VII","VIII","IX"},
        {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
        {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
        {"","M","MM","MMM"}
    };

    char *ret = (char *)malloc(sizeof(char)*20);
    int count = 0;
    
    char *temp = c[3][result/1000];
    while(*temp!='\0'){
        ret[count++]=*temp;
        temp++;
    }
    
    temp = c[2][result/100%10];
    while(*temp!='\0'){
        ret[count++]=*temp;
        temp++;
    }
    
    temp = c[1][result/10%10];
    while(*temp!='\0'){
        ret[count++]=*temp;
        temp++;
    }
    
    temp = c[0][result%10];
    while(*temp!='\0'){
        ret[count++]=*temp;
        temp++;
    }
    
    ret[count++]='\0';
    return ret;
}