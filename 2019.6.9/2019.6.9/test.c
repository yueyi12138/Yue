#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//void print(int *p, int right)
//{
//	int i = 0;
//	for (i = 0; i <= right; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	printf("\n");
//}
//void separate(int arr[], int left, int right)
//{
//	while (left <= right)
//	{
//		if (arr[left] % 2 == 1 && arr[right] % 2 == 0)
//		{
//			left++;
//			right--;
//		}
//		else if (arr[left] % 2 == 0 && arr[right] % 2 == 1)
//		{
//			int tmp = arr[left];
//			arr[left] = arr[right];
//			arr[right] = tmp;
//			left++;
//			right--;
//		}
//		else if (arr[left] % 2 == 1 && arr[right] % 2 == 1)
//		{
//			left++;
//		}
//		else
//		{
//			right--;
//		}
//	}
//}
//int main()
//{
//	int arr[] = { 6, 8, 9, 4, 3, 1, 5, 2, 7, 10, 11 };
//	int left = 0;
//	int right = sizeof (arr) / sizeof(arr[0]) - 1;
//	separate(arr,left,right);
//	print(arr, right);
//	system("pause");
//	return 0;
//}
int fun(int(*arr)[3], int row, int col, int k)
{
	assert(arr != NULL);
	int i = row - 1;
	int j = 0;
	while (i < 0 || j < row)
	{
		if (arr[i][j] == k)
		{
			return 1;
		}
		else if (arr[i][j]>k)
		{
			i--;
		}
		else
		{
			j++;
		}
	}
	return 0;
}

int main()
{
	int arr[3][3] = { { 1, 2, 3 },
	{ 2, 3, 4 },
	{ 3, 4, 5 }, };
	int row = sizeof(arr) / sizeof(arr[0]);
	int col = sizeof(arr) / (sizeof(arr[0][0])*row);
	int k = 0;
	scanf("%d", &k);
	int i = fun(arr, row, col, k);
	if (i == 1)
	{
		printf("´æÔÚ\n");
	}
	else
	{
		printf("²»´æÔÚ\n");
	}
	system("pause");
	return 0;
}