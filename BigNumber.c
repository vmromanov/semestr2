#include <string.h>
#include "BigNumber.h"
#include <stdio.h>


bool IsIntString(char* str_)
{
   if (str_[0] == '-')str_++;
   while (*str_)
   {
      if (*str_ < '0' || *str_>'9')
         return false;
      str_++;
   }
   return true;
}

BigNumber* BignumCreate(char* number_)
{
   if (number_ == NULL || strlen(number_) == 0||!IsIntString(number_))
      return NULL;

   BigNumber* Bn = malloc(sizeof(BigNumber));

   if (Bn == NULL)
      return NULL;

   if (*number_ == '-')
   {
      Bn->is_negative = true;
      number_++;
   }
   else
      Bn->is_negative = false;

   Bn->digits = calloc(Bn->size, sizeof(digit));
   if (Bn->digits==NULL)
   {
      free(Bn);
      return NULL;
   }
 
   for (size_t i = 0; i < Bn->size - (Bn->is_negative ? 1 : 0);)
      Bn->digits[i] = number_[i] - '0';

   return Bn;
  
}












//целочисленное деление, сложение, вычитание, умножение, печать, создание.



















