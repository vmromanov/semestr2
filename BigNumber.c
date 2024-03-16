#include <string.h>
#include "BigNumber.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

   BigNumber* Bn = (BigNumber*)malloc(sizeof(BigNumber));

   if (Bn == NULL)
      return NULL;

   size_t size = strlen(number_);
   if (*number_ == '-')
   {
      Bn->size = size - 1;
      Bn->is_negative = true;
      number_++;
   }
   else
   {
      Bn->size = size;
      Bn->is_negative = false;
   }

   Bn->digits = (digit*)calloc(Bn->size, sizeof(digit));
   if (Bn->digits==NULL)
   {
      free(Bn);
      return NULL;
   }
 
   for (size_t i = 0; i < Bn->size - (Bn->is_negative ? 1 : 0);++i)
      Bn->digits[i] = number_[i] - '0';

   return Bn;
  
}


BigNumber* SummBig(BigNumber* number1, BigNumber* number2)
{
   BigNumber* result = malloc(sizeof(BigNumber));

   if (result == NULL)
   {
      perror("memmory allocation error");
      return NULL;
   }

   size_t maxSize = 0;
   size_t minSize = 0;

   if (number1->size > number2->size)
   {
      maxSize = number1->size;
      minSize = number2->size;
   }
   else
   {
      maxSize = number2->size;
      minSize = number1->size;
   }


   result->size = maxSize + 1;

   result->digits = calloc(result->size, sizeof(digit));

   if (result->digits == NULL)
   {
      free(result);
      return NULL;
   }


   if ((number1->is_negative == true || number2->is_negative == true) && !(number1->is_negative == true && number2->is_negative == true))
      return MinusBig(number1, number2);
   
  
   if (number1->is_negative == true && number2->is_negative == true)
      result->is_negative = true;
   else
      result->is_negative = false;

   size_t difference = (maxSize - minSize);
   printf("difference : %lld\n", difference);
  /* for (long long int i = result->size; i > difference+1; --i)
   {
      result->digits[i] += (minSize==number1->size?number1->digits[i - difference]+number2->digits[i]:
         number2->digits[i - difference] + number1->digits[i]);
      for (long long int j = difference; j > 0; --j)
         result->digits[j] += (maxSize == number1->size ? number1->digits[j] : number2->digits[j]);
      if (result->digits[i] > 9)
      {
         result->digits[i] -= 10;
         result->digits[i - 1]+=1;
      }
   }
   for (long long int j = difference; j >= 0; --j) {
      result->digits[j] += (maxSize == number1->size ? number1->digits[j] : number2->digits[j]);
      if (result->digits[j] > 9)
      {
         result->digits[j] -= 10;
         result->digits[j - 1] += 1;
      }
   }*/

   for (long long int i = result->size; i > 1 ; --i)
   {
      result->digits[i] += (number1->size > number2->size ? number1->digits[i - 1] : number2->digits[i - 1]);
   }
   for (long long int i = result->size; i > 1; --i)
   {
      result->digits[i] += (number1->size < number2->size ? number1->digits[i - difference - 1] : number2->digits[i - difference - 1]);
   }


   return result;
}

BigNumber* MinusBig(BigNumber* number1, BigNumber* number2)
{

}

void PrintBN(BigNumber* bn_)
{
   if (bn_ == NULL)
   {
      printf("BigNumber is empty!\n");
      return;
   }

   if (bn_->is_negative)
      printf("-");

   for (size_t i = 0; i < bn_->size ; ++i)
      printf("%u", bn_->digits[i]);

   printf("\n");
}


void DeleteBN(BigNumber** bn_)
{
   free((*bn_)->digits);
   free(*bn_);

   *bn_ = NULL;
}


//целочисленное деление, сложение, вычитание, умножение, печать, создание.



















