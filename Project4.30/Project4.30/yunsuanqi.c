#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <Windows.h>
#pragma warning(disable:4996)
int my_add(int x, int y)//加法运算
{
	return x + y;
}
int my_sub(int x, int y)//减法运算
{
	return x - y;
}
int my_mul(int x, int y)//乘法运算
{
	return x*y;
}
int my_div(int x, int y)//除法运算
{
	if (y == 0){     //分母为零
		printf("div zero!error!");
		return 0;
	}
	return x / y;
}
void menu()   //主页面
{
	printf("#############################\n");
	printf("### 1.加法          2.减法###\n");
	printf("### 3.乘法          4.除法###\n");
	printf("###         0.退出        ###\n");
	printf("Please select!\n");
}
int main()
{
	int select = 0;
	int x, y;
	int ret = 0;
	do{
		menu();
		scanf("%d", &select);
		if (select >= 1 && select <= 4){
			switch (select){
			case 1:
			{
					  printf("请输入操作的数：");
					  scanf("%d%d", &x, &y);
					  ret = my_add(x, y);
					  break;
			}
			case 2:
			{
					  printf("请输入操作的数：");
					  scanf("%d%d", &x, &y);
					  ret = my_sub(x, y);
					  break;
			}
			case 3:
			{
					  printf("请输入操作的数：");
					  scanf("%d%d", &x, &y);
					  ret = my_mul(x, y);
					  break;
			}
			case 4:
			{
					  printf("请输入操作的数：");
					  scanf("%d%d", &x, &y);
					  ret = my_div(x, y);
					  break;
			}
			default:
				printf("输入错误！\n");
				break;
			}
			printf("%d\n", ret);
		}
		else if (select == 0){    //退出
			printf("goodbye!\n");
			break;
		}
		else{
			printf("you enter select error![1,4]\n");//输入错误并提示
		}
	} while (1);

	system("pause");
	return 0;
}