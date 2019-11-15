#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstdio>
#include<cstdlib>
#include <math.h>
//高斯列主元法解n元线性
using namespace std; 
int _87main()
{
	int n;
	cout << "请输入方程组个数：";
	cin >> n;
	
	double **a;
	a = (double**)malloc(sizeof(double)*n);
	double *b = (double*)malloc(sizeof(double)*n);
	for (int i = 1; i <= n; i++){
		a[i] = (double*)malloc(sizeof(double)*n);
		cout << "输入第 "<<i<<" 个方程的左端项系数与右端项系数"<<endl;
		for (int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
		cin >> b[i];
	}
	cout << "打印增广矩阵:" << endl;
	/*打印数据文件*/
	for(int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)  printf("%10f", a[i][j]);
		printf("%10f\n", b[i]);
	}
	cout << endl;
	for (int k = 1; k <= n - 1; k++)  //n - 1列
	{
		int column = k;

		double mainelement = a[k][k];
		for (int i = k; i <= n; i++)  //找主元素
		if (fabs(a[i][k]) > mainelement)
		{
			mainelement = fabs(a[i][k]);
			column = i;
		}
		for (int j = k; j <= n; j++)  //交换两行
		{
			double atemp = a[k][j];
			a[k][j] = a[column][j];
			a[column][j] = atemp;
		}
		double btemp = b[k];
		b[k] = b[column];
		b[column] = btemp;
		for (int i = k + 1; i <= n; i++)  //消元过程
		{
			double Mik = a[i][k] / a[k][k];
			for (int j = k; j <= n; j++)  a[i][j] -= Mik * a[k][j];
			b[i] -= Mik * b[k];
		}
	}
	cout << "打印上三角阵"<<endl;
	for (int i = 1; i <= n; i++)  //经列主元高斯消去法得到的上三角阵(最后一列为常系数)
	{
		for (int j = 1; j <= n; j++)  printf("%10f", a[i][j]);
		printf("%10f\n", b[i]);
	}
	cout << endl;
	b[n] /= a[n][n];  //回代过程
	for (int i = n - 1; i >= 1; i--)
	{
		double sum = 0;
		for (int j = i + 1; j <= n; j++)  sum += a[i][j] * b[j];
		b[i] = (b[i] - sum) / a[i][i];
	}
	cout << "方程组的解为"<<endl;
	for (int i = 1; i <= n; i++)  { 
		printf("x%d = %10f\n", i, b[i]); 
	}
	delete a;
	system("pause");
	return 0;
}
