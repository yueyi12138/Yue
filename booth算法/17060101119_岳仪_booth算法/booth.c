#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
char xCom[20] = { 0 };
char mxCom[20] = { 0 };
char yCom[20] = { 0 };
char multiNum[20] = { 0 };
char multiSrc[20] = { 0 };
int length(char* ch)
{
	int len = 0;
	while (*ch != '\0')
	{
		++len;
		++ch;
	}
	return len;
}
/* �����ַ��� */
char* copy(char* dest, const char* src)
{
	char* tmp = dest;
	while (*dest++ = *src++) {}
	return tmp;
}
/* �ַ����Ƚ� */
int compare(const char* dest, const char* src)
{
	int tmp = 0;
	while (!(tmp = *dest - *src) && *dest && *src)
	{
		dest++;
		src++;
	}
	if (tmp > 0) { return 1; }
	else if (tmp < 0) { return -1; }
	else { return 0; }
}
/* �ַ�����ȡ����ȡ��src�е�begin�±굽end�±���ַ���������洢��res�� */
char* intercept(char* src, char *res, int begin, int end)
{
	int i = begin;
	int j = 0;
	while (i <= end)
	{
		res[j] = src[i];
		++j;
		++i;
	}
	return res;
}
void mRight(char* src)
{
	int len = length(src);
	int i = len - 1;
	int num = 0;
	char* p = src;
	while (*p != '.')
	{
		++num;
		++p;
	}
	++num;
	for (; i >= num; --i)
	{
		src[i + 1] = src[i];
	}
	++i;

	/* ��������������1 �� ��0 */
	if (src[0] == '1')
	{
		src[i] = '1';
	}
	else
	{
		src[i] = '0';
	}

}
/* �������ӷ� */
void Add(char* lhsstr, char *rhsstr, char *result)
{
	int lhsLen = length(lhsstr);
	int rhsLen = length(rhsstr);
	if (lhsLen < rhsLen)
	{
		int diff = rhsLen - lhsLen;
		int i = lhsLen;
		while (diff > 0)
		{
			lhsstr[i] = '0';
			--diff;
			++i;
		}
	}
	else if (lhsLen > rhsLen)
	{
		int diff = lhsLen - rhsLen;
		int i = rhsLen;
		while (diff > 0)
		{
			rhsstr[i] = '0';
			--diff;
			++i;
		}
	}
	int i = lhsLen <= rhsLen ? rhsLen - 1 : lhsLen - 1;
	int j = i;
	/* ��λ��־ */
	int flag = 0;
	while (i >= 0)
	{
		/* С�������� */
		if (lhsstr[i] == '.')
		{
			result[i] = '.';
			--i;
			continue;
		}
		/* С�������� */
		if (rhsstr[j] == '.')
		{
			result[j] = '.';
			--j;
			continue;
		}

		int lhs = lhsstr[i] - '0';
		int rhs = rhsstr[j] - '0';
		int sum = lhs + rhs;
		if (flag == 1)
		{
			sum += 1;
			flag = 0;
		}
		if (sum == 2)
		{
			flag = 1;
			sum = 0;
		}
		else if (sum == 3)
		{
			flag = 1;
			sum = 1;
		}
		result[i] = sum + '0';
		--i;
		--j;
	}
}
/* ԭ��ת���� */
void calComplement(char *origin, char *recv)
{
	int isMinus = 0;
	if (origin[0] == '-')
	{
		isMinus = 1;
	}
	char* result = origin;
	if (isMinus)
	{
		*origin++ = '1';
		*origin++ = '1';
		while (*origin != '\0')
		{
			if (*origin == '1')
			{
				*origin = '0';
			}
			else if (*origin == '0')
			{
				*origin = '1';
			}
			++origin;
		}
		int len = length(result);
		char rhs[20] = { 0 };
		rhs[0] = '0';
		rhs[1] = '0';
		rhs[2] = '.';
		rhs[len - 1] = '1';
		for (int i = len - 2; i > 2; --i)
		{
			rhs[i] = '0';
		}
		Add(result, rhs, recv);
		return;
	}
	int len = length(origin);
	for (int i = len - 1; i >= 0; --i)
	{
		origin[i + 1] = origin[i];
	}
	origin[0] = '0';
	copy(recv, origin);
}
/* ����תԭ�룺���Ľ��ת�� */
void calOri(char* origin, char* recv)
{
	int isMinus = 0;
	if (origin[0] == '1')
	{
		isMinus = 1;
	}
	char* result = origin;
	if (isMinus)
	{
		*origin++ = '-';
		*origin++ = '0';
		/* ��λȡ�� */
		while (*origin != '\0')
		{
			if (*origin == '1')
			{
				*origin = '0';
			}
			else if (*origin == '0')
			{
				*origin = '1';
			}
			++origin;
		}
		/* ��һ���� */
		int len = length(result);
		char rhs[20] = { 0 };
		rhs[0] = '0';
		rhs[1] = '0';
		rhs[2] = '.';
		rhs[len - 1] = '1';
		for (int i = len - 2; i > 2; --i)
		{
			rhs[i] = '0';
		}
		Add(result, rhs, recv);
		return;
	}
	copy(recv, origin);
}
void Calculate()
{
	int i = 0;
	char index[20] = { 0 };
	/* �õ�ĩβ��0�ĳ������� */
	copy(index, multiNum);
	/* ����С��������ʼλ�� */
	int num = 0;
	while (index[i] != '.')
	{
		++num;
		++i;
	}
	/* ȥ��index��С���㣬����֮�������λ�ָ� */
	char res[20] = { 0 };
	int len = length(index);
	for (i = num; i < len - 1; ++i)
	{
		index[i] = index[i + 1];
	}
	index[i] = '\0';
	i = length(index) - 1;
	/* �״μ����־����Ϊ�״μ������벿�ֻ���ֵ�ļ��� */
	int first = 1;
	/* �洢���ֻ� */
	char multiRes[20] = { 0 };

	while (i - 1 >= 0)
	{
		/* ��λ�ָ�ӵ�λ���λ�ָ�ָ���ĩλ��ÿ��ͬʱ���λ�ƶ�һλ */
		intercept(index, res, i - 1, i);
		/* �״������ֵ������ */
		if (first)
		{
			first = 0;
			if (compare(res, "00") == 0)
			{
				/* 00 --> ��ֵ����һλ */
				mRight(multiSrc);
			}
			else if (compare(res, "01") == 0)
			{
				/* 01 --> ��ֵ��[x]����������һλ */
				Add(multiSrc, xCom, multiRes);
				mRight(multiRes);
			}
			else if (compare(res, "10") == 0)
			{
				/* 10 --> ��ֵ��[-x]����������һλ */
				Add(multiSrc, mxCom, multiRes);
				mRight(multiRes);
			}
			else if (compare(res, "11") == 0)
			{
				/* ��ֵ����һλ */
				mRight(multiSrc);
			}
		}
		/* ���״ζ����벿�ֻ������� */
		else
		{
			/* 00 --> ���ֻ�����һλ */
			if (compare(res, "00") == 0)
			{
				if (i - 1 != 0)
					mRight(multiRes);
			}
			else if (compare(res, "01") == 0)
			{
				/* 01 --> ���ֻ���[x]����������һλ */
				Add(multiRes, xCom, multiRes);
				if (i - 1 != 0)
					mRight(multiRes);
			}
			else if (compare(res, "10") == 0)
			{
				/* 10 --> ���ֻ���[-x]����������һλ */
				Add(multiRes, mxCom, multiRes);
				if (i - 1 != 0)
					mRight(multiRes);
			}
			else if (compare(res, "11") == 0)
			{
				/* ���ֻ�����һλ */
				if (i - 1 != 0)
					mRight(multiRes);
			}
		}
		--i;
	}

	/* ���ֻ������� */
	printf("���ֻ������� : %s\n", multiRes);

	char Ori[20] = { 0 };
	copy(Ori, multiRes);
	/* ͨ�����ֻ��õ����� */
	if (multiRes[0] == '1')
	{
		int mlen = length(multiRes);
		i = 0;
		for (; i < mlen - 1; i++)
		{
			multiRes[i] = multiRes[i + 1];
		}
		multiRes[i] = '\0';
	}
	printf("[X * Y]�� : %s\n", multiRes);
	/* ͨ�����ֻ��õ�ԭ�� */
	char finalRes[20] = { 0 };
	calOri(Ori, finalRes);
	printf("X * Y : %s\n", finalRes);
}
int main()
{
	char inputx[20] = { 0 };
	char inputy[20] = { 0 };
	printf("input x : ");
	scanf("%s", inputx);
	printf("input y : ");
	scanf("%s", inputy);
	char origin[20] = { 0 };
	// x����
	copy(origin, inputx);
	calComplement(origin, xCom);
	printf("[x]�� : %s\n", xCom);
	// -x����
	copy(origin, inputx);
	int lenx = length(origin);
	/* ���x�����Ϊ������ôֱ�ӽ�����ȥ�����ɵõ�-x */
	if (inputx[0] == '-')
	{
		int i = 0;
		for (; i < lenx - 1; ++i)
		{
			origin[i] = origin[i + 1];
		}
		origin[i] = '\0';
	}
	/* ���x����Ϊ������ô��Ӹ��ŵõ�-x */
	else
	{
		for (int i = lenx - 1; i >= 0; --i)
		{
			origin[i + 1] = origin[i];
		}
		origin[0] = '-';
	}
	calComplement(origin, mxCom);
	printf("[-x]�� : %s\n", mxCom);
	// y����
	copy(origin, inputy);
	calComplement(origin, yCom);
	printf("[y]�� : %s\n", yCom);
	// ����y��ĩβ��0
	copy(origin, inputy);
	int leny = length(origin);
	origin[leny] = '0';
	origin[leny + 1] = '\0';
	copy(multiNum, origin);
	printf("����y��ĩβ��0 : %s\n", multiNum);
	// ���㲿�ֻ���ֵ
	multiSrc[0] = '0';
	multiSrc[1] = '0';
	multiSrc[2] = '.';
	int len = length(xCom) - 3;
	int i = 0;
	int j = 3;
	for (; i < len; ++i, ++j)
	{
		multiSrc[j] = '0';
	}
	printf("���ֻ���ֵ: %s\n\n", multiSrc);
	Calculate();
	system("pause");
}
