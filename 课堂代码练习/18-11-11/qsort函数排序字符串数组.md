# qsort函数排序字符串数组

## 描述：

**qsort()函数是一个库函数，也是一个万能的排序函数，只需要自己写好compare()函数即可，那么怎么用qsort()函数来排序字符串呢？**

## 思路：

**个人感觉，这个问题很好解决，困难的就是在调用函数时，参数应该怎么写。**

有两个需要注意的点！！！！！

1. 先来看一下main()函数

```c
int main(void)
{
	char *arr[] = {"dddd", "bbbb", "cccc", "aaaa", "eeee"};
	int i = 0;

	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%s ", arr[i]);
	}
	printf("\n");

	//调用库函数来排序
	//因为字符串数组里面保存的都是指针
	//所以size在传参的时候要传指针的大小
	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(char* ), char_cmp);

	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%s ", arr[i]);
	}
	printf("\n");

	MyQsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(char*), char_cmp);
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%s ", arr[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}
```

> qsort(数组首元素地址，数组元素的个数，每个元素所占字节大小，回调函数compare的地址（这里是一个函数指针，是一个指向函数的指针）)

其他参数都好说，可是第三个参数到底是字符串的大小还是这个指针的大小,应该是指针的大小```sizeof(char* )```。因为，这个数组里存储是这些字符串的地址，也就是一个个指针，所以这里的带下应该是指针的大小。

2. 再来看一下char_cmp()函数

```c
int char_cmp(const void* x, const void* y)
{
	assert(x && y);

	//因为数组里存的是字符串的地址，所以要强制类型转换成(char **)
	//然后再解引用一下才是字符串的地址
	return strcmp(*(char**)x, *(char**)y);
	
}
```

在返回的时候，strcmp()里的参数到底怎么写，这个在我写的时候就卡住了好久，可是仔细捋一捋，我们需要比较的是字符串，所以strcmp()函数里的参数需要写字符串的地址，但是我们本来的数组是指针数组，数组里存储的是指针，所以先需要强转为```(char**)``` 这样才可以得到真正的字符串，然后再一次解引用，就是字符串的地址。这里有点绕，所以要仔细想~

## 源代码：

```c
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <assert.h>

/*
* 利用qsort函数理解回调函数
* 郭文峰
* 2018/11/11
*/

int char_cmp(const void* x, const void* y)
{
	assert(x && y);

	//因为数组里存的是字符串的地址，所以要强制类型转换成(char **)
	//然后再解引用一下才是字符串的地址
	return strcmp(*(char**)x, *(char**)y);
	
}

void swap(void* x, void* y, int size)
{

	int i = 0;

	for (i = 0; i < size; i++)
	{
		*((char*)x + i) ^= *((char*)y + i);
		*((char*)y + i) ^= *((char*)x + i);
		*((char*)x + i) ^= *((char*)y + i);
	}
}

//用冒泡排序模拟实现Qsort函数
void MyQsort(void* base, int count, \
	int size, int(*compare)(const void*, const void*))
{
	int i = 0;
	int j = 0;

	for (i = 0; i < count - 1; i++)
	{
		for (j = 0; j < count - 1 - i; j++)
		{
			if (compare((char*)base + j*size, (char*)base + (j + 1)*size) > 0)
			{
				swap((char*)base + j*size, (char*)base + (j + 1)*size, size);
			}
		}
	}
}

int main(void)
{
	char *arr[] = {"dddd", "bbbb", "cccc", "aaaa", "eeee"};
	int i = 0;

	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%s ", arr[i]);
	}
	printf("\n");

	//调用库函数来排序
	//因为字符串数组里面保存的都是指针
	//所以size在传参的时候要传指针的大小
	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(char* ), char_cmp);

	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%s ", arr[i]);
	}
	printf("\n");

	MyQsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(char*), char_cmp);
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%s ", arr[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}
```

### 注意：

1. assert()可以判断一个函数传进来的指针是否为空指针，如果不为空则不作任何操作，反之则报错。
2. 我用冒泡排序法来模拟了一下qsort函数，实际的qsort函数用的是快速排序法。
3. swap()函数交换的时候，因为是不确定类型，所以我强制转换为```(char* )``` 类型，然后交换每个字节。例如如果交换两个整数就交换他们的每个字节，即交换四次。

