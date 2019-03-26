#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//a：数组首元素地址
//pos：指定的位置
//data：需要插入的元素
//size：数组的长度，数组元素的个数，不是数组的大小，增加元素，需要做相应修改
void insert_array(int *a, int pos, int data, int *size);
void remove_array(int *a, int pos, int *size);
void print_array(int *a, int size); //打印数组

int main()
{

	int a[15] = { 1, 3, 5, 7, 9, 11, 13 };
	int size = 7; //数组长度，已经放元素的个数

	print_array(a, size); //打印
	insert_array(a, 0, -1, &size); //在0的位置插入-1
	print_array(a, size); //打印

	insert_array(a, 2, 8, &size); //在2的位置插入8
	print_array(a, size); //打印

	insert_array(a, size, 250, &size); //在末尾的位置插入250
	print_array(a, size); //打印

	print_array(a, size); //打印
	remove_array(a, 0, &size); //删除第0个元素
	print_array(a, size); //打印

	return 0;
}

void insert_array(int *a, int pos, int data, int *size)
{
	if (*size <= 15)
	{
		int cnt = (*size - pos)*sizeof(int);
		int* p = (int*)malloc(cnt);
		memcpy(p, a + pos,cnt);

		*(a + pos) = data;
		memcpy(a + pos + 1, p, cnt);
		*size += 1;
	}
	else
	{
		printf("数组已经满了\n");
	}
}

void print_array(int *a, int size) //打印数组
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void remove_array(int *a, int pos, int *size)
{
	if (*size >0 )
	{
		int cnt = (*size - pos-1)*sizeof(int);
		int* p = (int*)malloc(cnt);
		memcpy(p, a + pos+1,cnt);
		memcpy(a + pos , p, cnt);
		*size -= 1;
	}
	else
	{
		printf("数组已经空了\n");
	}
}
