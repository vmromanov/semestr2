#include <stdio.h>
#include "Euler2.h"
#include "Date.h"
#include "BigNumber.h"

int main()
{  // 
	////problem 6
	//printf("enter amount of numbers\n");
	//int amount=0;
	//scanf_s("%d", &amount);
	//printf("\neuler 6 problem answer:");
	//printf("%d", Problem6(amount));
	
	////problem7
	//printf("enter prime number's number\n");
	//int number = 0;
	//scanf_s("%d", &number);
	//printf("\n");
	//printf("%d prime number is : %d", number, Problem7(number));

	////LeapYear
	//printf("enter year");
	//Date date;
	//scanf_s("%d", &date.year);

	//time difference

	/*Date earlyDate; Date lateDate;
	printf("enter year month day hour minutes seconds for earlyer date\n");
	scanf_s("%d %d %d %d %d %d", &earlyDate.year, &earlyDate.month, &earlyDate.day, &earlyDate.hour, &earlyDate.minutes, &earlyDate.seconds);

	printf("enter year month day hour minutes seconds for later date\n");
	scanf_s("%d %d %d %d %d %d", &lateDate.year, &lateDate.month, &lateDate.day, &lateDate.hour, &lateDate.minutes, &lateDate.seconds);

	TimeDifference(&earlyDate, &lateDate);*/

	//BigNUm

	/*char number1[] = "555555555555555555555";
	char number2[] = " 43333333333333333333";
	printf(" 555555555555555555555\n");
	printf("  33333333333333333333\n");
	BigNumber* num1 = BignumCreate(number1);
	BigNumber* num2 = BignumCreate(number2);
	PrintBN(SummBig(num1, num2));

	DeleteBN(&num1);
	DeleteBN(&num2);*/



	//proglem8

	/*char number[] = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";
	BigNumber* num1 = BignumCreate(number);
	problem9(num1);
	
	printf("%d", problem8(num1));*/



	//problem9

	//int rez = problem9(1000);

	//printf("%d", rez);

	
	//problem 10

	int rez = 1;
	for (unsigned int i = 3; i <= 2000000; ++i) 
	{
		if (Prime(i)) rez = i + rez;
	}
			
	printf("%u", rez);
	printf("\n142913828922\n");
	



	return 0;
}
















































