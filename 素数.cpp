//打印100~200 之间的素数
#include<stdio.h>
int main()
{
	int i,j,k=1;
	for(i=100;i<=200;i++)
	{
		k=1;
		for(j=2;j<i;j++)
		{
			if(i%j==0){
			  k=0;
			  break;
			}

		}
		    if(k==1)
		    printf("%d\n",i);
	}
	return 0;
}
