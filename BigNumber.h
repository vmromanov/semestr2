#pragma once
#include <stdbool.h>

typedef unsigned char digit;

typedef struct BigNumber
{
   bool is_negative;                    // знаковое или нет
   digit* digits;                // цифры
   size_t size;                  // кол-во символов           
} BigNumber;












