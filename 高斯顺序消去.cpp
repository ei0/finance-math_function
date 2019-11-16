#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
//执行程序前手动改变方程数
void gauss(double** a, double* x,int n)
{
	int i, j, k;
	double s, l;
	for (i = 0; i<n - 1; i++)
	{
		k = i;
		for (j = i + 1; j<n; j++)
		{
			if (fabs(a[j][i])>fabs(a[k][i]))
				k = j;
		}
		if (k != i)
		for (j = i; j <= n; j++)
			swap(a[i][j], a[k][j]);
		for (j = i + 1; j<n; j++)
		{
			l = 1.0*a[j][i] / a[i][i];
			for (k = 0; k<n + 1; k++)
				a[j][k] = a[j][k] - a[i][k] * l;
		}
	}
	x[n - 1] = a[n - 1][n] / a[n - 1][n - 1];
	for (i = n - 2; i >= 0; i--)
	{
		s = 0.0;
		for (j = i; j<n; j++)
		{
			if (j == i)
				continue;
			s += a[i][j] * x[j];
		}
		x[i] = (a[i][n] - s) / a[i][i];
	}
}
int _kmain()
{
	int n;
	cout << "请输入方程组个数: ";
	cin >> n;
	double **a;
	a = (double**)malloc(sizeof(double)*n);
	double *x = (double*)malloc(sizeof(double)*n);
	for (int i = 0; i <= n-1; i++){
		a[i] = (double*)malloc(sizeof(double)*(n+1));
		cout << "输入第"<<i+1<<"个方程组的左端项系数与右端项系数"<<endl;
		for (int j = 0; j <= n; j++){
			cin >> a[i][j];
		}
	}
	gauss(a, x,n);
	for (int i = 0; i < n; i++)
		cout << "X" << i << "=:" << x[i] << endl;
	free(a);
	free(x);
	system("pause");
	return 0;
}
