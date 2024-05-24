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
   if (Bn->size == 1)
   {
       Bn->digits[0] = (*number_ - '0');
   }
   else
   {
       for (size_t i = 0; i < Bn->size - (Bn->is_negative ? 1 : 0); ++i)
           Bn->digits[i] = (number_[i] - '0');
   }
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
       for (long long int j = 0; j < (long long int)(result->size) - 1; ++j)
          result->digits[j] = result->digits[j + 1];

    realloc(result->digits, ((result->size) - swipe) * sizeof(digit));
    result->size -= swipe;


    return result;
}



BigNumber* MinusBN(BigNumber* number1, BigNumber* number2)
{
    if (number1 == NULL || number2 == NULL)
        return NULL;

    BigNumber* num1 = number1;
    BigNumber* num2 = number2;



    BigNumber* result = malloc(sizeof(BigNumber)); 
    if (result == NULL) 
        return NULL;

    result->size = ((num1->size >= num2->size) ? (num1->size) : (num2->size)) + 1;
    result->digits = (digit*)calloc(result->size, sizeof(digit)); 
     
    if (result->digits == NULL) 
    { 
        free(result);
        return NULL;
    }
    BigNumber* min_bn;
    BigNumber* max_bn;
     min_bn = num1->size < num2->size ? num1 : num2; 
     max_bn= num1->size > num2->size ? num1 : num2; 
    if (num1->size == num2->size)
    {
        for (int i = 0; i < num1->size; ++i)
        {
            if (num1->digits[i] > num2->digits[i])
            {
                max_bn = num1;
                min_bn = num2;
                break;
            }
            else
                if (num1->digits[i] < num2->digits[i])
                {
                    max_bn = num2;
                    min_bn = num1;
                    break;
                }
                
        }

    }
    if (min_bn == NULL || max_bn == NULL)
    {
        min_bn = num1;
        max_bn = num2;
    }
   
    if (num1->is_negative != num2->is_negative) 
    {
        if (num1->is_negative == true) 
        {
            num1->is_negative = false;
            result = SummBig(num1, num2);
            result->is_negative = true;
            return result;
        }
        else
        {
            num2->is_negative = false;
            result = SummBig(num1, num2);
            result->is_negative = false;
            return result; 
        }
       /*result->is_negative = max_bn->is_negative;
       min_bn->is_negative = max_bn->is_negative;
          result = SummBig(number1, number2);
       return result;*/
    }

    size_t SizeDiff = max_bn->size - min_bn->size;

    int carry = 0;
    if (num1->size >= num2->size)
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
          if (diff < 0) {
              diff += 10;
              carry = 1;
          }
          else
              carry = 0;
          result->digits[i + 1] = diff;
       }
    }
    else
    {
       result = MinusBN(number2, number1);
    }

    if (num1->size > num2->size)result->is_negative = num1->is_negative;
    if (num1->size < num2->size)
       if (num2->is_negative == false)
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
       size_t swipe = 0;;
       for (long long i = 0; (result->digits[i]) == 0; ++i)
          swipe++;
       for (int i = 0; i < swipe; ++i)
          for (long long int j = 0; j < (long long int)(result->size) - 1; ++j)
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

   result->is_negative = (number1->is_negative == number2->is_negative ? false : true);

   result->size = number2->size + number1->size;

   result->digits = calloc(result->size, sizeof(digit));
   if (result->digits == NULL)
   {
       free(result);
       return NULL;
   }
  
  
   BigNumber* bn_max = (number1->size >= number2->size ? number1 : number2);
   BigNumber* bn_min = (number2->size <= number1->size ? number2 : number1);

   for (long long int i=bn_max->size-1;i>=0;--i)
       for (long long j = bn_min->size-1; j >= 0; --j)
       {
           size_t num = result->size - (bn_max->size-i) - (bn_min->size-j)+1;
           result->digits[num] = (bn_max->digits[i]) * (bn_min->digits[j]);
       }

   /*for (int i = 0; i < number1->size; ++i)
       for (int j = 0; i < number2->size; ++i)
           result->digits[i + j + 1] += number1->digits[i] * number2->digits[j];*/

   for (long long int i = (long long int)(result->size)-1; i > 0; --i)
   {
       result->digits[i - 1] += result->digits[i] / 10;
       result->digits[i] %= 10;
   }



   size_t swipe = 0;;
   for (long long i = 0; (result->digits[i]) == 0; ++i)
       swipe++;
   for (int i = 0; i < swipe; ++i)
       for (long long int j = 0; j < (long long int)(result->size) - 1; ++j)
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
   
   return result;

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



















