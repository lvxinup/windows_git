
//¼ÆËã1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 ¡­¡­ + 1 / 99 - 1 / 100 µÄÖµ
#include<stdio.h>
#include<stdlib.h>
int main()
{
	float i = 0.0,j=1.0;
	float sum = 0.0;
	float sum1 = 0.0;
	for (i = 0; i <= 100; i += 2)
	{
		sum = sum + 1 / i;
	 }
	for (j = 1; j < 100; j += 2)
	{
		sum1 = sum1 + 1 / j;
	 }
	printf("%f", sum1-sum);
	system("pause");
	return 0;
}