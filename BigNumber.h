#pragma once
#include <stdbool.h>

typedef unsigned char digit;

typedef struct BigNumber
{
   bool is_negative;                    // �������� ��� ���
   digit* digits;                // �����
   size_t size;                  // ���-�� ��������           
} BigNumber;












