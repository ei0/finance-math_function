#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstdio>
#include<cstdlib>
#include <math.h>
//��˹����Ԫ����nԪ����
using namespace std; 
int _87main()
{
	int n;
	cout << "�����뷽���������";
	cin >> n;
	
	double **a;
	a = (double**)malloc(sizeof(double)*n);
	double *b = (double*)malloc(sizeof(double)*n);
	for (int i = 1; i <= n; i++){
		a[i] = (double*)malloc(sizeof(double)*n);
		cout << "����� "<<i<<" �����̵������ϵ�����Ҷ���ϵ��"<<endl;
		for (int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
		cin >> b[i];
	}
	cout << "��ӡ�������:" << endl;
	/*��ӡ�����ļ�*/
	for(int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)  printf("%10f", a[i][j]);
		printf("%10f\n", b[i]);
	}
	cout << endl;
	for (int k = 1; k <= n - 1; k++)  //n - 1��
	{
		int column = k;

		double mainelement = a[k][k];
		for (int i = k; i <= n; i++)  //����Ԫ��
		if (fabs(a[i][k]) > mainelement)
		{
			mainelement = fabs(a[i][k]);
			column = i;
		}
		for (int j = k; j <= n; j++)  //��������
		{
			double atemp = a[k][j];
			a[k][j] = a[column][j];
			a[column][j] = atemp;
		}
		double btemp = b[k];
		b[k] = b[column];
		b[column] = btemp;
		for (int i = k + 1; i <= n; i++)  //��Ԫ����
		{
			double Mik = a[i][k] / a[k][k];
			for (int j = k; j <= n; j++)  a[i][j] -= Mik * a[k][j];
			b[i] -= Mik * b[k];
		}
	}
	cout << "��ӡ��������"<<endl;
	for (int i = 1; i <= n; i++)  //������Ԫ��˹��ȥ���õ�����������(���һ��Ϊ��ϵ��)
	{
		for (int j = 1; j <= n; j++)  printf("%10f", a[i][j]);
		printf("%10f\n", b[i]);
	}
	cout << endl;
	b[n] /= a[n][n];  //�ش�����
	for (int i = n - 1; i >= 1; i--)
	{
		double sum = 0;
		for (int j = i + 1; j <= n; j++)  sum += a[i][j] * b[j];
		b[i] = (b[i] - sum) / a[i][i];
	}
	cout << "������Ľ�Ϊ"<<endl;
	for (int i = 1; i <= n; i++)  { 
		printf("x%d = %10f\n", i, b[i]); 
	}
	delete a;
	system("pause");
	return 0;
}
