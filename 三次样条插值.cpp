#if 0
#include<iostream>
#include<cmath>
using namespace std;
const int max = 50;
double x[max], y[max], z[max];
double j[max], k[max], l[max];
double s[3][4] = {0};
double chafen(int x1, int x2, int x3)
{
	double a = (y[x3] - y[x2]) / (x[x3] - x[x2]);
	double b = (y[x2] - y[x1]) / (x[x2] - x[x1]);
	return (a - b) / (x[x3] - x[x1]);
}//求差分
void chase(int n)//追赶法
{
	double A[max];
	A[0] = j[0] / 2;
	for (int i = 1; i<n; i++)
		A[i] = j[i] / (2 - k[i] * A[i - 1]);
    l[0] = l[0] / 2;
	for (int i = 0; i <= n; i++)
		l[i] = (l[i] - k[i] * l[i - 1]) / (2 - k[i] * A[i - 1]);
	for (int i = n - 1; i >= 0; i--)
		l[i] = l[i] - A[i] * l[i + 1];
}
void print(int n)
{//方程式打印
	cout << "\n输出三阶样条插值函数：\n";
	for (int i = 0; i<n; i++)
	{
		cout << i + 1 << ":[" << x[i] << "," << x[i + 1] << "]\n" << "\t";
		cout << "S" << i + 1 << "=";
		 s[i][0] = l[i] / (6 * z[i]);
		 if (s[i][0]>0)
			cout << -s[i][0] << "*(x-" << x[i + 1] << ")^3";
		else
			cout << -s[i][0] << "*(x-" << x[i + 1] << ")^3";
		s[i][1] = l[i + 1] / (6 * z[i]);
		if (s[i][1]>0)
			cout << "+" << s[i][1] << "*(x-" << x[i] << ")^3";
		else
			cout << s[i][1] << "*(x-" << x[i] << ")^3";
		/*cout << "\i\t";*/
		s[i][2] = (y[i] - l[i] * z[i] * z[i] / 6) / z[i];
		if (s[i][2]>0)
			cout << "-" << s[i][2] << "*(x-" << x[i + 1] << ")";
		else
			cout << s[i][2] << "*(x-" << x[i + 1] << ")";
		s[i][3] = (y[i + 1] - l[i + 1] * z[i] * z[i] / 6) / z[i];
		if (s[i][3]>0)
			cout << "+" << s[i][3] << "*(x-" << x[i] << ")";
		else
			cout << s[i][3] << "*(x-" << x[i] << ")";
		    cout << endl;
	}
	        cout << endl;
}
void bianjie_choice(int n){
	for (int i = 0; i<n; i++)//求步长
	z[i] = x[i + 1] - x[i];
	cout << "请输入边界条件\n 1 :已知两端的一阶导数\n 2 :两端的二阶导数已知\n 默认：边界条件\n";
	int s;
	double chafen1, chafen2;
	cin >> s;
	switch (s)
	{
	case 1:cout << "输入Y0\' Y" << n << "\'\n";
		cin >> chafen1 >> chafen2;
		j[0] = 1;
		k[n] = 1;
		l[0] = 6 * ((y[1] - y[0]) / (x[1] - x[0]) - chafen1) / z[0];
		l[n] = 6 * (chafen2 - (y[n] - y[n - 1]) / (x[n] - x[n - 1])) / z[n - 1];
		break;
	case 2:cout << "输入Y0\" Y" << n << "\"\n";
		cin >> chafen1 >> chafen2;
		j[0] = k[n] = 0;
		l[0] = 2 * chafen1;
		l[n] = 2 * chafen2;
		break;
	default:cout << "不可用\n";
	};
}
int scanf_parameter(){//输入参数

	int n;
	cout << "下标从0开始，请输入最大下标：";
	cin >> n;
	cout << "请输入插值点的x坐标从0到"<< n << endl;
	for (int i = 0; i <= n; i++)
	{
		cin >> x[i];
	}
	cout << "请输入插值点的y坐标从0到" << n << endl;
	for (int i = 0; i <= n; i++)
	{
		cin >> y[i];
	}
	return n;
}
void sanciyangtiao(int n){

	for (int i = 1; i<n; i++)
		l[i] = 6 * chafen(i - 1, i, i + 1);
	for (int i = 0; i<n; i++)
	{
		k[i] = z[i - 1] / (z[i] + z[i - 1]);
		j[i] = 1 - k[i];
	}
	k[n] = z[n - 1] / (z[n - 1] + z[n]);
}
double test(double xx){
	double yy =0;
	
	if (xx<x[0] || (xx>x[0] && xx < x[1])){
		yy = s[0][0] * pow((xx - x[1]), 3) + s[0][1] * pow((xx - x[0]), 3) + s[0][2] * (xx - x[1]) + s[0][3] * (xx - x[0]);
	}
	if (xx>x[1] && xx < x[2]){
		yy = s[1][0] * pow((xx - x[2]), 3) + s[1][1] * pow((xx - x[1]), 3) + s[1][2] * (xx - x[2]) +s[1][3] * (xx - x[1]);
	}
	if (xx>x[3] || (xx>x[2] && xx < x[3])){
		yy = s[2][0] * pow((xx - x[3]), 3) + s[2][1] * pow((xx - x[2]), 3) + s[2][2] * (xx - x[3]) + s[2][3] * (xx - x[2]);
	}
	return yy;
}
int main()
{
	    int n;
		double yy;
		double yy1;
		double yy2;
		double yy3;
		double yy4;
	    n = scanf_parameter();
	bianjie_choice(n);
	chase(n);//追赶法
	sanciyangtiao(n);//样条插值
	
		print(n);//打印求得的方程式
		yy = test(-0.8);
		cout << yy;
		yy1 = test(-0.3);
		cout << yy1;
		yy2 = test(0.2);
		cout << yy2;
		yy3 = test(0.7);
		cout << yy3;
		yy4 = test(1.2);
		cout << yy4;

	    system("pause");
	    return 0;
}
#endif
#if 0
#include<iostream>
using namespace std;
const int max = 50;
float x[max], y[max], z[max];
float c[max], a[max], fs[max];
float ff(int x1, int x2, int x3)
{
	float a = (y[x3] - y[x2]) / (x[x3] - x[x2]);
	float b = (y[x2] - y[x1]) / (x[x2] - x[x1]);
	return(a - b) / (x[x3] - x[x1]);
}//求差分
void chase(int n)//追赶法
{
	int i;
	float A[max];
	A[0] = c[0] / 2;
	for (int i = 1; i<n; i++)
		A[i] = c[i] / (2 - a[i] * A[i - 1]);
	fs[0] = fs[0] / 2;
	for (i = 0; i <= n; i++)
		fs[i] = (fs[i] - a[i] * fs[i - 1]) / (2 - a[i] * A[i - 1]);
	for (i = n - 1; i >= 0; i--)
		fs[i] = fs[i] - A[i] * fs[i + 1];
}
int main()
{
	void print(int n);
	int n, i;
	char t;
	do{
		cout << "输入x的最大下标：";
		cin >> n;
		for (i = 0; i <= n; i++)
		{
			cout << "please put in X" << i << ':';
			cin >> x[i];
			cout << "please put in Y" << i << ':';
			cin >> y[i];
		}
		for (i = 0; i<n; i++)//求步长
			z[i] = x[i + 1] - x[i];
		cout << "请输入边界条件\n 1 :已知两端的一阶导数\n 2 :两端的二阶导数已知\n 默认：边界条件\n";
		int s;
		float ff1, ff2;
		cin >> s;
		switch (s)
		{
		case 1:cout << "输入Y0\' Y" << n << "\'\n";
			cin >> ff1 >> ff2;
			c[0] = 1;
			a[n] = 1;
			fs[0] = 6 * ((y[1] - y[0]) / (x[1] - x[0]) - ff1) / z[0];
			fs[n] = 6 * (ff2 - (y[n] - y[n - 1]) / (x[n] - x[n - 1])) / z[n - 1];
			break;
		case 2:cout << "输入Y0\" Y" << n << "\"\n";
			cin >> ff1 >> ff2;
			c[0] = a[n] = 0;
			fs[0] = 2 * ff1;
			fs[n] = 2 * ff2;
			break;
		default:cout << "不可用\n";
		};
		for (i = 1; i<n; i++)
			fs[i] = 6 * ff(i - 1, i, i + 1);
		for (i = 0; i<n; i++)
		{
			a[i] = z[i - 1] / (z[i] + z[i - 1]);
			c[i] = 1 - a[i];
		}
		a[n] = z[n - 1] / (z[n - 1] + z[n]);
		chase(n);
		cout << "\n输出三阶样条插值函数：\n";
		print(n);
		cout << "Do you need another try?yes/no:";
		cin >> t;
	} while (t == 'y' || t == 'Y');
	return 0;
}
void print(int n)
{
	for (int i = 0; i<n; i++)
	{
		cout << i + 1 << ":[" << x[i] << "," << x[i + 1] << "]\n" << "\t";
		cout << "S" << i + 1 << "=";
		float s = fs[i] / (6 * z[i]);
		if (s>0)
			cout << -s << "*(x-" << x[i + 1] << ")^3";
		else
			cout << -s << "*(x-" << x[i + 1] << ")^3";
		s = fs[i + 1] / (6 * z[i]);
		if (s>0)
			cout << "+" << s << "*(x-" << x[i] << ")^3";
		else
			cout << "-" << s << "*(x-" << x[i] << ")^3";
		cout << "\n\t";
		s = (y[i] - fs[i] * z[i] * z[i] / 6) / z[i];
		if (s>0)
			cout << "-" << s << "*(x-" << x[i + 1] << ")";
		else
			cout << "-" << -s << "*(x-" << x[i + 1] << ")";
		s = (y[i + 1] - fs[i + 1] * z[i] * z[i] / 6) / z[i];
		if (s>0)
			cout << "+" << s << "*(x-" << x[i] << ")";
		else
			cout << "-" << -s << "*(x-" << x[i] << ")";
		cout << endl;
	}
	cout << endl;
}
#endif
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cmath>
using namespace std;



vector<double> zhuigan(int n, vector<double> &a, vector<double> &b, vector<double>&c, vector<double>&d){
	vector<double> x_x (n-2,0);
	const int nn = n - 2;
	for (int i = 1; i < nn; i++){
		b[i] = b[i] - a[i] / b[i - 1] * c[i - 1];
		d[i] = d[i] - a[i] / b[i - 1] * d[i - 1];
	}
	x_x[nn-1] = d[nn-1] / b[nn-1];
	for (int i = nn - 2; i>=0; i--){
		x_x[i] = (d[i] - c[i] * x_x[i + 1]) / b[i];
	}
	return x_x;
}
double funa0(double X){
	return 2 * pow(X, 3) - 3 * pow(X, 2) + 1;
}
double funa1(double X){
	return -2 * pow(X, 3) + 3 * pow(X, 2) ;
}
double funb0(double X){
	return  pow(X, 3) - 2 * pow(X, 2) + X;
}
double funb1(double X){
	return  pow(X, 3) - pow(X, 2) ;
}
int _owqmain(){
	
	double *x, *y;
	int n;
	cout << "请输入节点个数：";
	cin >> n;//输入节点个数
	cout << "请输入各点的x坐标："<<endl;
	x = (double*)malloc(n*sizeof(double));
	for (int i = 0; i < n; i++){
		cin >> x[i];
	}
	cout << "请输入各点的y坐标：" << endl;
	y = (double*)malloc(n*sizeof(double));
	for (int i = 0; i < n; i++){
		cin >> y[i];
	}
	double dy0 , dyn;
	cout << "请输入边界条件"<<endl ;
	cout << "dy0 = ";
	cin >> dy0;
	cout << "dy" << n-1 << " = ";
	cin >> dyn;
	
	vector<double> h(n-1, 0);
	vector<double> lambda(n - 2, 0);
	vector<double> mu(n - 2, 0);
	vector<double> theta(n - 2, 0);
	vector<double> er(n - 2, 2);
	for (int i = 0; i < n - 1; i++){
		h[i] = x[i + 1] - x[i];
	}
	for (int i = 0; i < n - 2; i++){
		lambda[i] = h[i + 1] / (h[i] + h[i + 1]);
	}
	for (int i = 0; i < n - 2; i++){
		mu[i] = 1 - lambda[i];
	}
	for (int i = 0; i < n - 2; i++){
		theta[i] = 3 * (lambda[i] * (y[i+1] - y[i]) / h[i]) + 3 * (mu[i] * (y[i + 2] - y[i+1]) / h[i + 1]);
	}
	theta[0] = theta[0] - lambda[0] * dy0;
	theta[n - 3] = theta[n - 3] - lambda[n - 3] * dyn;
	vector<double> u(n - 2, 0);
	u = zhuigan(n, lambda, er, mu, theta);
	vector<double> mm;
	mm.push_back(dy0);
	mm.push_back(dyn);
	vector<double>::iterator pos = mm.begin()+1;
	mm.insert(pos, u.begin(), u.begin() + 2);
	cout << "追赶法解三对角矩阵所得m阵为：" <<endl ;
	for (int i = 0; i <mm.size(); i++){
		cout << 'm'<<i+1<<'='<< mm[i] << endl;
	}
	int tt = 1;
	while (tt==1){
	double X_x;
	cout << "请输入插值点的x坐标：";
	cin >> X_x;
	int  l,r;
	for (int i = 0; i < n; i++){
		if (X_x>x[i] && X_x < x[i + 1]){
			l = i; r = i + 1;
			break;
		}
		if (X_x < x[0]){
			l = 0; r = 1;
		}
		if (X_x > x[n-1]){
			l = n - 2; r = n - 1;
		}
	}
	double X_ba = (X_x - x[l]) / h[r-1];
	double S = funa0(X_ba)*y[l] + funa1(X_ba)*y[r] + h[r-1] * funb0(X_ba)*mm[l] + h[r-1] * funb1(X_ba)*mm[r];
	cout <<"给出插值点的y坐标："<< S << endl;
	cout << "输入1再次输入插值点" << endl;
	cout << "输入2退出" << endl;
	cin >> tt;
	}
	free(x); free(y); 
	system("pause");
	return 0;
}