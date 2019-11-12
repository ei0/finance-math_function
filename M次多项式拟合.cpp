// Note:Your choice is C++ IDE
#include<iostream>
#include<cmath>
#define n 20
using namespace std;
//求解任意可逆矩阵的逆
void inv(double X[n][n], int m, double L[n][n])
{
	int i, j, k;
	double temp = 0;
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n; j++)
		if (i == j)
			L[i][j] = 1;
	}
	for (i = 0; i<m - 1; i++)
	{
		temp = X[i][i];
		for (j = 0; j<m; j++)
		{
			X[i][j] = X[i][j] / temp;
			L[i][j] = L[i][j] / temp;
		}
		for (k = 0; k<m; k++)
		{
			if (k == i)
				continue;
			temp = -X[i][i] * X[k][i];
			for (j = 0; j<m; j++)
			{
				X[k][j] = X[k][j] + temp*X[i][j];
				L[k][j] = L[k][j] + temp*L[i][j];
			}
		}
	}
}

int main()
{
	int m, M, i, j, k;
	double X[n] = { 0 }, Y[n] = { 0 }, F[n][n] = { 0 }, B[n] = { 0 };
	double A[n][n] = { 0 }, BM[n][n] = { 0 }, C[n] = { 0 }, E[n][n] = { 0 };
	cout << "M次多项式曲线拟合" << endl;
	cout << "请输入需要拟合的点的个数:";
	cin >> m;
	cout << "请输入" << m << "个点的X坐标:" << endl;
	for (i = 0; i<m; i++)
		cin >> X[i];
	cout << endl;
	cout << "请输入" << m << "个点的Y坐标序列:" << endl;
	for (i = 0; i<m; i++)
		cin >> Y[i];
	cout << endl;
	cout << "请输入需要拟合的次数:";
	cin >> M;
	for (i = 0; i<m; i++)
	for (k = 1; k <= M + 1; k++)
		F[i][k - 1] = pow(X[i], k - 1);//对X[i]求k-1次幂
	//求转置
	for (i = 0; i<m; i++)
	{
		for (j = 0; j<M + 1; j++)
		{
			BM[j][i] = F[i][j];
		}
	}
	//计算其转置BM与F的乘
	for (i = 0; i<M + 1; i++)
	for (j = 0; j<M + 1; j++)
	for (k = 0; k<m; k++)
		A[i][j] += BM[i][k] * F[k][j];
	//计算F的转置BM与Y的乘
	for (i = 0; i<M + 1; i++)
	for (j = 0; j<m; j++)
		B[i] += BM[i][j] * Y[j];
	//使用inv函数求解矩阵A的逆矩阵E
	inv(A, m, E);
	//计算A的逆BM与B的乘
	for (i = 0; i<M + 1; i++)
	for (j = 0; j<m; j++)
		C[i] += E[i][j] * B[j];
	
	cout << "拟合后的" << M << "次多项式系数为，幂次由高到低：" << endl;
	for (i = M; i >= 0; i--)
		cout << C[i] << "\t";
	cout << endl;
	cout << "拟合后的" << M << "次多项式为:" << endl;
	cout << endl;
	cout << "P(x)=";
	for (i = M; i >= 0; i--)
	{
		if (i == 0)
		{
			if (C[i] >= 0)
				cout << "+" << C[i];
			else
				cout << C[i];
		}
		else
		{
		if (C[i] >= 0)
				cout << "+" << C[i] << "*x^" << i;
			else
				cout << C[i] << "*x^" << i;
		}

	}
	cout << endl;
	system("pause");
	return 0;
}

