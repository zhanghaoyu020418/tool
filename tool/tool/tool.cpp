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
	int t = a[low];//��¼��С����
	int f = low + 1;//��¼low�����һ��λ�ã�a[f]Ӧ���Ǳ�tҪС
	int b = hight;//��¼���һ������λ�ã�a[b]Ӧ��Ҫ��t��

	if (low >= hight) return;//��low>hight��ʱ���ֱ�ӷ���

	int TempVal;
	while (f <= b)
	{
		while (f <= b && a[f] <= t) f++;//������������ʱ�򣬾�++
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

	a[low] = a[b];//����ѭ����ʱ�򣬽���a[b]��a[low]
	a[b] = t;

	quick_sort(a, low, b - 1);//�ݹ�quick_sort,b����ߺ��ұ�
	quick_sort(a, b + 1, hight);
}