#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <Windows.h>
#pragma warning(disable:4996)
int my_add(int x, int y)//�ӷ�����
{
	return x + y;
}
int my_sub(int x, int y)//��������
{
	return x - y;
}
int my_mul(int x, int y)//�˷�����
{
	return x*y;
}
int my_div(int x, int y)//��������
{
	if (y == 0){     //��ĸΪ��
		printf("div zero!error!");
		return 0;
	}
	return x / y;
}
void menu()   //��ҳ��
{
	printf("#############################\n");
	printf("### 1.�ӷ�          2.����###\n");
	printf("### 3.�˷�          4.����###\n");
	printf("###         0.�˳�        ###\n");
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
					  printf("���������������");
					  scanf("%d%d", &x, &y);
					  ret = my_add(x, y);
					  break;
			}
			case 2:
			{
					  printf("���������������");
					  scanf("%d%d", &x, &y);
					  ret = my_sub(x, y);
					  break;
			}
			case 3:
			{
					  printf("���������������");
					  scanf("%d%d", &x, &y);
					  ret = my_mul(x, y);
					  break;
			}
			case 4:
			{
					  printf("���������������");
					  scanf("%d%d", &x, &y);
					  ret = my_div(x, y);
					  break;
			}
			default:
				printf("�������\n");
				break;
			}
			printf("%d\n", ret);
		}
		else if (select == 0){    //�˳�
			printf("goodbye!\n");
			break;
		}
		else{
			printf("you enter select error![1,4]\n");//���������ʾ
		}
	} while (1);

	system("pause");
	return 0;
}