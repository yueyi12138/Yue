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
/* 拷贝字符串 */
char* copy(char* dest, const char* src)
{
	char* tmp = dest;
	while (*dest++ = *src++) {}
	return tmp;
}
/* 字符串比较 */
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
/* 字符串截取：截取从src中的begin下标到end下标的字符串，结果存储在res中 */
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

	/* 根据正负进行添1 或 添0 */
	if (src[0] == '1')
	{
		src[i] = '1';
	}
	else
	{
		src[i] = '0';
	}

}
/* 浮点数加法 */
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
	/* 进位标志 */
	int flag = 0;
	while (i >= 0)
	{
		/* 小数点跳过 */
		if (lhsstr[i] == '.')
		{
			result[i] = '.';
			--i;
			continue;
		}
		/* 小数点跳过 */
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
/* 原码转补码 */
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
/* 补码转原码：最后的结果转换 */
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
		/* 按位取反 */
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
		/* 加一操作 */
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
	/* 拿到末尾添0的乘数副本 */
	copy(index, multiNum);
	/* 计算小数部分起始位置 */
	int num = 0;
	while (index[i] != '.')
	{
		++num;
		++i;
	}
	/* 去掉index的小数点，便于之后进行移位分割 */
	char res[20] = { 0 };
	int len = length(index);
	for (i = num; i < len - 1; ++i)
	{
		index[i] = index[i + 1];
	}
	index[i] = '\0';
	i = length(index) - 1;
	/* 首次计算标志，因为首次计算是与部分积初值的计算 */
	int first = 1;
	/* 存储部分积 */
	char multiRes[20] = { 0 };

	while (i - 1 >= 0)
	{
		/* 移位分割，从低位向高位分割，分割首末位置每次同时向高位移动一位 */
		intercept(index, res, i - 1, i);
		/* 首次是与初值的运算 */
		if (first)
		{
			first = 0;
			if (compare(res, "00") == 0)
			{
				/* 00 --> 初值右移一位 */
				mRight(multiSrc);
			}
			else if (compare(res, "01") == 0)
			{
				/* 01 --> 初值加[x]补，并右移一位 */
				Add(multiSrc, xCom, multiRes);
				mRight(multiRes);
			}
			else if (compare(res, "10") == 0)
			{
				/* 10 --> 初值加[-x]补，并右移一位 */
				Add(multiSrc, mxCom, multiRes);
				mRight(multiRes);
			}
			else if (compare(res, "11") == 0)
			{
				/* 初值右移一位 */
				mRight(multiSrc);
			}
		}
		/* 非首次都是与部分积的运算 */
		else
		{
			/* 00 --> 部分积右移一位 */
			if (compare(res, "00") == 0)
			{
				if (i - 1 != 0)
					mRight(multiRes);
			}
			else if (compare(res, "01") == 0)
			{
				/* 01 --> 部分积加[x]补，并右移一位 */
				Add(multiRes, xCom, multiRes);
				if (i - 1 != 0)
					mRight(multiRes);
			}
			else if (compare(res, "10") == 0)
			{
				/* 10 --> 部分积加[-x]补，并右移一位 */
				Add(multiRes, mxCom, multiRes);
				if (i - 1 != 0)
					mRight(multiRes);
			}
			else if (compare(res, "11") == 0)
			{
				/* 部分积右移一位 */
				if (i - 1 != 0)
					mRight(multiRes);
			}
		}
		--i;
	}

	/* 部分积运算结果 */
	printf("部分积运算结果 : %s\n", multiRes);

	char Ori[20] = { 0 };
	copy(Ori, multiRes);
	/* 通过部分积得到补码 */
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
	printf("[X * Y]补 : %s\n", multiRes);
	/* 通过部分积得到原码 */
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
	// x补码
	copy(origin, inputx);
	calComplement(origin, xCom);
	printf("[x]补 : %s\n", xCom);
	// -x补码
	copy(origin, inputx);
	int lenx = length(origin);
	/* 如果x本身就为负，那么直接将负号去掉即可得到-x */
	if (inputx[0] == '-')
	{
		int i = 0;
		for (; i < lenx - 1; ++i)
		{
			origin[i] = origin[i + 1];
		}
		origin[i] = '\0';
	}
	/* 如果x本身为正，那么添加负号得到-x */
	else
	{
		for (int i = lenx - 1; i >= 0; --i)
		{
			origin[i + 1] = origin[i];
		}
		origin[0] = '-';
	}
	calComplement(origin, mxCom);
	printf("[-x]补 : %s\n", mxCom);
	// y补码
	copy(origin, inputy);
	calComplement(origin, yCom);
	printf("[y]补 : %s\n", yCom);
	// 乘数y的末尾补0
	copy(origin, inputy);
	int leny = length(origin);
	origin[leny] = '0';
	origin[leny + 1] = '\0';
	copy(multiNum, origin);
	printf("乘数y的末尾补0 : %s\n", multiNum);
	// 计算部分积初值
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
	printf("部分积初值: %s\n\n", multiSrc);
	Calculate();
	system("pause");
}
