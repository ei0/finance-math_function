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
		cout << "请输入隔根区间上限 a = ";
		cin >> a;
		cout << "请输入隔根区间下限 b = ";
		cin >> b; 
		if (a > b){
			cout << "精度默认1e-3\n想要修改输入1\n不做修改输入0" << endl;
			cin >> s;
			if (s == 1){
				cout << "请输入精度";
				cin >> pre;
			}
			break;
		}
		else{
			cout << "求根区间输入有误";
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
	cout << "所求根为x = " << x<<endl;

	system("pause");
	return 0;
}