#define _CRT_SECURE_NO_WARNINGS 1

void insert_sort(int a[], int sz)
{
	int j = 0;
	int tmp = 0;
	for (int i = 1; i < sz; i++)
	{
		tmp = a[i];
		for (j = i - 1; j >= 0 && tmp < a[j]; j--)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = tmp;
	}
}

void shell_sort(int a[], int sz)
{
	int j = 0;
	int tmp = 0;
	int jump = sz >> 1;
	while (jump)
	{
		for (int i = jump; i < sz; i++)
		{
			tmp = a[i];
			j = i - jump;
			while (j >= 0 && tmp < a[j])
			{
				a[j + jump] = a[j];
				j -= jump;
			}
			a[j + jump] = tmp;
		}
		jump >>= 1;
	}
}


void quick_sort(int a[], int low, int hight)
{
	int t = a[low];//记录最小的数
	int f = low + 1;//记录low后面的一个位置，a[f]应该是比t要小
	int b = hight;//记录最后一个数的位置，a[b]应该要比t大

	if (low >= hight) return;//当low>hight的时候就直接返回

	int TempVal;
	while (f <= b)
	{
		while (f <= b && a[f] <= t) f++;//当满足条件的时候，就++
		while (f <= b && a[b] >= t) b--;
		if (f < b)
		{
			TempVal = a[f];
			a[f] = a[b];
			a[b] = TempVal;
			f++;
			b--;
		}
	}

	a[low] = a[b];//结束循环的时候，交换a[b]和a[low]
	a[b] = t;

	quick_sort(a, low, b - 1);//递归quick_sort,b的左边和右边
	quick_sort(a, b + 1, hight);
}