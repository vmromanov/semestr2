#pragma once
#include <stdbool.h>

typedef unsigned char digit;

typedef struct BigNumber
{
   bool is_negative;                    // çíàêîâîå èëè íåò
   digit* digits;                // öèôðû
   size_t size;                  // êîë-âî ñèìâîëîâ           
} BigNumber;



BigNumber* BignumCreate(char* number_);


BigNumber* SummBig(BigNumber* number1, BigNumber* number2);

BigNumber* BigMult(BigNumber* number1, BigNumber* number2);

BigNumber* divideBig(BigNumber* dividend, BigNumber* divisor);

/*
* @brief вычитает number2 from number1
*/
BigNumber* MinusBN(BigNumber* number1, BigNumber* number2);


void PrintBN(BigNumber* bn_);


void DeleteBN(BigNumber** bn_);