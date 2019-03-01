#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<Windows.h>

int main()
{
	FILE * pFile;
	pFile = fopen("unexist.ent", "rb");
	if (pFile == NULL)
	{
		perror("The following error occurred");
	}
	else
		fclose(pFile);

	system("pause");
	return 0;
}