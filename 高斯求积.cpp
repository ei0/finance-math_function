#include<iostream>
#include<vector>
using namespace std;
vector<double> A;
vector<double> t;
void choice(int m){
	double a1[] = { 0.5556, 0.8889, 0.5556 };
	double tt1[] = { -0.7746, 0, 0.7746 };
	double a2[] = { 0.347855, 0.652145, 0.652145, 0.347855 };
	double tt2[] = { -0.861136, -0.339981, 0.339981, 0.861136 };
	double a3[] = { 0.236927, 0.478629, 0.568889, 0.478629, 0.236927 };
	double tt3[] = { -0.906180, -0.538469, 0, 0.538469, 0.906180 };
	double a4[] = { 0.171325, 0.360762, 0.467914, 0.467914, 0.360762, 0.171325 };
	double tt4[] = { -0.93247, -0.661209, -0.238619, 0.238619, 0.661209, 0.932470 };
	switch (m)
	{
	case 1:
		A.push_back(1);
		t.push_back(0);
		break;
	case 2:
		A.push_back(1);
		A.push_back(1);
		t.push_back(-0.5773);
		t.push_back(0.5773);
		break;
	case 3:
		for (int i = 0; i < 3; i++)
			A.push_back(a1[i]);
		for (int i = 0; i < 3; i++)
			t.push_back(tt1[i]);
		break;
	case 4:
		for (int i = 0; i < 4; i++)
			A.push_back(a2[i]);
		for (int i = 0; i < 4; i++)
			t.push_back(tt2[i]);
		break;
	case 5:
		for (int i = 0; i < 5; i++)
			A.push_back(a3[i]);
		for (int i = 0; i < 5; i++)
			t.push_back(tt3[i]);
		break;
	case 6:
		for (int i = 0; i < 6; i++)
			A.push_back(a4[i]);
		for (int i = 0; i < 6; i++)
			t.push_back(tt4[i]);
		break;
	default:
		break;
	}
}
double s_sum(double a,double b){
	vector<double> x1;
	x1.resize(t.size());
	vector<double> y;
	y.resize(t.size());
	for (size_t i = 0; i < t.size(); i++){
		if (t[i] == 0){
			x1[i] = (a + b) / 2;
			y[i] = 4 / (1 + x1[i] * x1[i]);
		}
		else{
			x1[i] = (t[i]*(b - a) / 2 ) + ((a + b) / 2);
			y[i] = 4 / (1 + x1[i] * x1[i]);//fname
		}
		
	}
	double tmp =0;
	for (size_t i = 0; i < A.size(); i++){
		tmp = tmp+A[i] *y[i];
	}
	return tmp;
}
int _9main(){
	int m;
	cout << "请输入高斯点数1~6：";
	cin >> m;
	choice(m);
	     if (m >=1 && m<=6 ){
	            int n;
	            double a, b;
	            cout << "请输入积分下限a：";
	            cin >> a;
	            cout << "请输入积分上限b：";
	            cin >> b;
	            cout << "请输入等分数n：";
	            cin >> n;
	            double tmp = a;
	            vector<double> x;
	            x.push_back(tmp);
	            for (int i = 1; i < n ; i++){
	            	tmp = tmp + (a + b) / (n + 1);
	            	x.push_back(tmp);
	            }
	            x.push_back(b);
	            double g = 0;
	            for (int i = 0; i < n; i++){
	            	g = g + (x[i+1] - x[i]) / 2 * s_sum(x[i],x[i+1]); 
	            }
	            cout << "积分结果为："<<g;
	            }
	     else{
		        cout << "本程序高斯点只能取1~6";
	            }
    system("pause");
	return 0;
}