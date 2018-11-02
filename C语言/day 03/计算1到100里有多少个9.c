#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i = 0;
	int count = 1;

	for (i = 10; i <= 100; i++)
	{
		if (0 == (i - 9) % 10)
		{
			count++;
		}
	}

	printf("%d\n", count);

	system("pause");
	return 0;

}