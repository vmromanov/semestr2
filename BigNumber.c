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
        return NULL;

    result->size = max(number1->size, number2->size) + 1;
    result->digits = (digit*)calloc(result->size, sizeof(digit));

    if (result->digits == NULL)
    {
        free(result);
        return NULL;
    }

    BigNumber* min_bn = number1->size <= number2->size ? number1 : number2;
    BigNumber* max_bn = number1->size > number2->size ? number1 : number2;

    int carry = 0;
    int diff = max_bn->size - min_bn->size;
  
    if (number1->is_negative == false && number2->is_negative == false)
    {
        result->is_negative = false;



        for (int i = min_bn->size - 1; i >= 0; --i)
        {
            char sum = (min_bn->digits[i] + max_bn->digits[i + diff]) + carry;
            result->digits[i + diff + 1] = sum % 10;

            carry = sum / 10;
        }
        carry = 0;

        for (int i = diff - 1; i >= 0; --i) 
        {
            char sum = max_bn->digits[i] + carry; 
            result->digits[i + 1] = sum %10 ; 
            carry = sum / 10; 
        }

        result->digits[0] = carry;

    }
    else
    {
        return MinusBN(number1, number2);
    }
    return result;
}



BigNumber* MinusBN(BigNumber* number1, BigNumber* number2)
{
    BigNumber* result = malloc(sizeof(BigNumber)); 
    if (result == NULL) 
        return NULL;

    result->size = max(number1->size, number2->size) + 1; 
    result->digits = (digit*)calloc(result->size, sizeof(digit)); 
     
    if (result->digits == NULL) 
    { 
        free(result); 
        return NULL;
    }

    BigNumber* min_bn = number1->size <= number2->size ? number1 : number2; 
    BigNumber* max_bn = number1->size > number2->size ? number1 : number2; 

    int SizeDiff = max_bn->size - min_bn->size;


    int carry = 0;
    for (int i = min_bn->size - 1; i >= 0; i--) {
        int diff = min_bn->digits[i] - max_bn->digits[i] - carry;
        if (diff < 0) {
            diff += 10;
            carry = 1;
        }
        else {
            carry = 0;
        }
        result->digits[i] = diff;
    }

    return result;
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
      printf("%c", bn_->digits[i]);

   printf("\n");
}


void DeleteBN(BigNumber** bn_)
{
   free((*bn_)->digits);
   free(*bn_);

   *bn_ = NULL;
}


//целочисленное деление, сложение, вычитание, умножение, печать, создание.



















