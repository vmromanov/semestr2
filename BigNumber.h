#pragma once
#include <stdbool.h>

typedef unsigned char digit;

typedef struct BigNumber
{
   bool is_negative;                    // знаковое или нет
   digit* digits;                // цифры
   size_t size;                  // кол-во символов           
} BigNumber;



BigNumber* BignumCreate(char* number_);


BigNumber* SummBig(BigNumber* number1, BigNumber* number2);


BigNumber* MinusBig(BigNumber* number1, BigNumber* number2);


void PrintBN(BigNumber* bn_);


void DeleteBN(BigNumber** bn_);