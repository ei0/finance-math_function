#include<iostream>
#include<cmath>
using namespace std;
double func1(double x, double y){
	return x*x - 2 * x - y + 0.5;
}
double func2(double x, double y){
	return x*x + 4 * y*y - 4;
}
const int num = 2;//���̸���
int _23main()
{ 
	int N = 50;
	int t = 0;
	double tol = 0.001;
	double x, y, x0, y0,hls;
	double a[num][num], b[num];
	cout << "�����������ֵ��" << endl;//������ֵ
	cout << "x0=";
	cin >> x0;
	cout << "y0=";
	cin >> y0;
	cout << "����Ĭ��Ϊ0.001����1�޸�����2�����޸�: " ;
	cin >> t;
	if(t ==1){
		cout <<"������������ﵽ����: " ;
		cin >> tol;
	}
	t = 0;
	cout << "����������Ĭ��Ϊ50����1�޸�����2�����޸�: ";
	cin >> t;
	if (t == 1){
		cout << "������������������: ";
		cin >> N;
	}
	t = 0;
	a[0][0] = 8 * y0;//�������
	a[0][1] = 1;
	a[1][0] = -2 * x0;
	a[1][1] = 2 * x0 - 2;
	hls = a[0][0] * a[1][1] - a[0][1] * a[1][0];
	for (int  i = 0; i<N; i++)//���漰����
	{
		b[0] = (a[0][0] * func1(x0, y0) + a[0][1] * func2(x0, y0)) / hls;
		b[1] = (a[1][0] * func1(x0, y0) + a[1][1] * func2(x0, y0)) / hls;
	    x0 -= b[0];
		y0 -= b[1];	
		cout <<"�� "<< i+1 << " �ε�����X = " << x0 << ",Y = " << y0 << endl;
		if ((fabs(-b[0]) < tol)||(fabs(-b[1])<tol)){
			x = x0; y = y0;
			break;
		}
	}
	cout << "���Է�����Ľ�Ϊ��" << " x=" << x << "," << "y=" << y << endl;
	system("pause");
	return 0;
}