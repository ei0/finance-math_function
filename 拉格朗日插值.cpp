#include<iostream>
#include<vector>
using namespace std;

double la(vector<double> x, vector<double> y, double xx){
	if (x.size() != y.size()){
		return 0;
	}
	double s = 0;
	for (size_t i = 0; i < y.size(); i++){
		double t =1;
		for (size_t j = 0; j < y.size(); j++){
			if (j != i){
				t = t*(xx - x[j]) / (x[i] - x[j]);
			}
		}
		s = s + t*y[i];
	}
	return s;
}
int _mimain(){
	vector<double> x;
	vector<double> y;
	double yy,xx;
	int n;
	cout << "��������֪�ڵ������";
	cin >> n;
	cout << "��������ڵ��x���꣺";
	for (int i=0; i < n; i++){
		double m1;
		cin >> m1;
		x.push_back(m1);
	}
	cout << "��������ڵ��y���꣺";
	for (int i=0; i < n; i++){
		double m2;
		cin >> m2;
		y.push_back(m2);
	}
	cout << "������Ҫ��ڵ��x���꣺";
	cin >> xx;
	yy = la(x, y, xx);
	cout <<"����ڵ��y����Ϊ��"<< yy;
	system("pause");
	return 0;
}