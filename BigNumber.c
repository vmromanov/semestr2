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

    result->size = ((number1->size >= number2->size )? (number1->size): (number2->size)) + 1;
    result->digits = (digit*)calloc(result->size, sizeof(digit));

    if (result->digits == NULL)
    {
        free(result);
        return NULL;
    }

    BigNumber* min_bn = number1->size <= number2->size ? number1 : number2;
    BigNumber* max_bn = number1->size > number2->size ? number1 : number2;

    int carry = 0;
    size_t diff = max_bn->size - min_bn->size;
    
    if (number1->is_negative == number2->is_negative)
    {
        result->is_negative = number1->is_negative;

        for (long long int i = (min_bn->size)-1; i >= 0; --i)
        {
            char sum = (min_bn->digits[i] + max_bn->digits[i + diff]) + carry;

            result->digits[i + diff + 1] = sum % 10;

            carry = sum / 10;
        }

        for (long long int i = (long long int)(diff - 1); i >= 0; --i)
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

    int swipe = 0;;
    for (long long i = 0; result->digits[i] == 0; ++i)
       swipe++;
    for (int i = 0; i < swipe; ++i)
       for (long long int j = 0; j < (result->size) - 1; ++j)
          result->digits[j] = result->digits[j + 1];

    realloc(result->digits, ((result->size) - swipe) * sizeof(digit));
    result->size -= swipe;
    return result;
}



BigNumber* MinusBN(BigNumber* number1, BigNumber* number2)
{
    BigNumber* result = malloc(sizeof(BigNumber)); 
    if (result == NULL) 
        return NULL;

    result->size = ((number1->size >= number2->size) ? (number1->size) : (number2->size)) + 1;
    result->digits = (digit*)calloc(result->size, sizeof(digit)); 
     
    if (result->digits == NULL) 
    { 
        free(result);
        return NULL;
    }

    BigNumber* min_bn = number1->size <= number2->size ? number1 : number2; 
    BigNumber* max_bn = number1->size > number2->size ? number1 : number2; 

    if (number1->is_negative != number2->is_negative)
    {
       result->is_negative = max_bn->is_negative;
       min_bn->is_negative = max_bn->is_negative;
          result = SummBig(number1, number2);
       return result;
    }

    size_t SizeDiff = max_bn->size - min_bn->size;

    int carry = 0;
    if (number1->size >= number2->size)
    {
       for (long long int i = min_bn->size - 1; i >= 0; i--)
       {
          char diff = max_bn->digits[i + SizeDiff] - min_bn->digits[i] - carry;
          if (diff < 0) {
             diff += 10;
             carry = 1;
          }
          else
             carry = 0;

          result->digits[i + SizeDiff + 1] = diff;
       }


       for (long long int i = (long long int)(SizeDiff - 1); i >= 0; --i)
       {
          char diff = max_bn->digits[i] - carry;
          carry = 0;
          result->digits[i + 1] = diff;
       }
    }
    else
    {
       result = MinusBN(number2, number1);
    }

    if (number1->size > number2->size)result->is_negative = number1->is_negative;
    if (number1->size < number2->size)
       if (number2->is_negative == false)
          result->is_negative = true;
       else
          result->is_negative = false;

    if (number1->size == number2->size)
    {
       result->is_negative = false;
       for (int i = 0; i < number1->size; ++i)
       {
          if (number1->digits[i] > number2->digits[i])
          {
             result->is_negative = number1->is_negative;
             break;
          }
          if (number1->digits[i] < number2->digits[i])
          {
             result->is_negative = number2->is_negative;
             break;
          }
       }
       
    }

    if (number1->size >= number2->size)
    {
       int swipe = 0;;
       for (long long i = 0; (result->digits[i]) == 0; ++i)
          swipe++;
       for (int i = 0; i < swipe; ++i)
          for (long long int j = 0; j < (result->size) - 1; ++j)
             result->digits[j] = result->digits[j + 1];

       if (swipe != result->size)
       {
          realloc(result->digits, ((result->size) - swipe) * sizeof(digit));
          result->size -= swipe;
       }
       else
       {
          realloc(result->digits, ((result->size) - swipe + 1) * sizeof(digit));
          result->size -= (swipe - 1);
       }
    }

    return result;
}

BigNumber* BigMult(BigNumber* number1, BigNumber* number2)
{
   BigNumber* result = malloc(sizeof(BigNumber));
   if (result == NULL)
      return NULL;


   result->size = number1->size + number2->size;

   result->digits = (digit*)calloc(result->size, sizeof(digit));

   if (number1->is_negative == number2->is_negative)
      result->is_negative = false;
   else
      result->is_negative = true;

   BigNumber* n1 = number1;
   BigNumber* n2 = number2;

   char ones = "1";
   BigNumber* one = BignumCreate(ones);

   char ki[] = "0";
   BigNumber* i = BignumCreate(ki);

   i->size = number2->size;
   
   while(MinusBN()!=0)




}

void PrintBN(BigNumber* bn_)
{
   if (bn_ == NULL)
   {
      printf("BigNumber is empty!\n");
      return;
   }

   size_t i = 0;
   if (bn_->is_negative)
      printf("-");

   

   for (; i < bn_->size ; ++i)
      printf("%d", bn_->digits[i]);

   printf("\n");
}


void DeleteBN(BigNumber** bn_)
{
   free((*bn_)->digits);
   free(*bn_);

   *bn_ = NULL;
}


//целочисленное деление, сложение, вычитание, умножение, печать, создание.



















