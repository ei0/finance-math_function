#include<iostream>
#include<cmath>
using namespace std;
double fun(double x){
	return x*exp(x) - 1;
}
int _imain(){
	double a, b;
	double pre = 1e-3;
	while (1)
	{ 
		int s;
		cout << "����������������� a = ";
		cin >> a;
		cout << "����������������� b = ";
		cin >> b; 
		if (a > b){
			cout << "����Ĭ��1e-3\n��Ҫ�޸�����1\n�����޸�����0" << endl;
			cin >> s;
			if (s == 1){
				cout << "�����뾫��";
				cin >> pre;
			}
			break;
		}
		else{
			cout << "���������������";
			continue;
		}
		
		
	}
	double y=1;
	double d=1;
	double x;
	while ((y != 0) && (d>pre)){
	 x = (a + b) / 2;
	 y = fun(x);
	 if ((fun(x)*fun(b)) < 0){
		 a = x;
	 }
	 if ((fun(x)*fun(a)) < 0){
		 b = x;
	 }
	 d = fabs(b - a);
	}
	cout << "�����Ϊx = " << x<<endl;

	system("pause");
	return 0;
}