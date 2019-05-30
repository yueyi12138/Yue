#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//unsigned int reverse_bit(unsigned int value)
//{
//	unsigned int sum = 0;
//	int i = 0;
//	for (i = 31; i >= 0; i--)
//	{
//		if (value & 1)
//		{
//			sum = sum + (int)pow(2, i);
//		}
//		value = value >> 1;
//	}
//	return sum;
//}
//int main()
//{
//	int a = 0;
//	unsigned int k = 0;
//	scanf("%d", &a);
//	k = reverse_bit(a);
//	printf("反转的结果为：%u\n", k);
//	system("pause");
//	return 0;
//}


//void average(int *px, int *py, int *pave)
//{
//	*pave = (*px - *py) / 2 + (*py);
//	
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//  int ave=0;
//	printf("请输入a和b的值:\n");
//	scanf("%d %d", &a, &b);
//	average(&a, &b, &ave);
//	printf("平均数为ave:%d\n",ave);
//	system("pause");
//	return 0;
//}

//void Function(int *arr, int len, int *px, int *py)
//{
//	int sum = 0;
//	int pos = 0;
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		sum = sum^arr[i];
//	}
//	for (i = 0; i < 32; i++)
//	{
//		if (((sum >> i) & 1) == 1)
//		{
//			pos = i;
//			break;
//		}
//	}
//	for (i = 0; i < len; i++)
//	{
//		if (((arr[i] >> pos) & 1) == 1)
//		{
//			*px = *px^arr[i];
//		}
//		else
//		{
//			*py = *px^arr[i];
//		}
//	}
//
//}
//int main()
//{
//	int arr[] = { 1, 3, 2, 5, 5, 3, 2, 7, 1, 9 };
//	int x = 0;
//	int y = 0;
//	int len = sizeof(arr) / sizeof(arr[0]);
//	Function(arr, len, &x, &y);
//	printf("%d %d", x, y);
//	system("pause");
//	return 0;
//}

void reserve_string(char *l, char *r)
{
	while (l < r)
	{
		char tmp = *l;
		*l = *r;
		*r = tmp;
		l++;
		r--;
	}
}
void reserve(char ch[], int len)
{
	int i = 0;
	char *chl = ch;
	char *chr = ch;
	while (ch[i])
	{
		if (ch[i] == ' ')
		{
			reserve_string(chl, chr - 1);  //先反转每个单词,函数的嵌套调用 tneduts a ma i
			chl = ++chr; //先给chr +1，再把ch的值付给chl

		}
		else
		{
			chr++;
		}
		i++;
	}
	reserve_string(ch, ch + len - 1);  //再整体反转  i am a student

}
int main()

{
	char ch[] = "student a am i";
	reserve(ch, strlen(ch));
	printf("%s\n", ch);
	system("pause");
	return 0;
}