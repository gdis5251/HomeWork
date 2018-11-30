#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>

int main(void)
{
	int i_num = 12345;
	FILE *fp = fopen("test.txt", "wb");

	if (!fp)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	fwrite(&i_num, sizeof(int), 1, fp);

	fclose(fp);

	system("pause");
	return 0;
}