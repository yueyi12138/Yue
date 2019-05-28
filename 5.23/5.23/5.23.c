#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
void Function(int *arr, int len, int *px, int *py)
{
	int sum = 0;
	int pos = 0;
	int i = 0;
	for (i = 0; i < len; i++)
	{
		sum = sum^arr[i];
	}
	for (i = 0; i < 32; i++)
	{
		if (((sum >> i) & 1) == 1)
		{
			pos = i;
			break;
		}
	}
	for (i = 0; i < len; i++)
	{
		if (((arr[i] >> pos) & 1) == 1)
		{
			*px = *px^arr[i];
		}
		else
		{
			*py = *px^arr[i];
		}
	}

}
int main()
{
	int arr[] = { 1, 3, 2, 5, 5, 3, 2, 7, 1, 9 };
	int x = 0;
	int y = 0;
	int len = sizeof(arr) / sizeof(arr[0]);
	Function(arr, len, &x, &y);
	printf("%d %d", x, y);
	system("pause");
	return 0;
}