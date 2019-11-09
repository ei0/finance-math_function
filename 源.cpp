#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
vector<string> a = { "������ֵ", "������ֵ", "�������ֵ", "�������ֵ", "�ȸ������ֵ", "�ȸ������ֵ", "���������ֵ", "���������ֵ" };
vector<string> b = { "������ֵ��ָ��ǰ��һ���ʽ��������ں������еļ�ֵ",
                          "������ֵ��ָδ������յ���֧�����ֽ��ڵ�ǰ�ļ�ֵ�ֳ����֡�����", 
						  "�������ֵ�������ȡ�ı����ͣ�һ��ʱ����ÿ����ĩ�ȶ��ո�����ĸ�����ֵ֮��",
						  "�������ֵ��һ���ڼ�ÿ����ĩ�ȶ��ϵ���ո��������ֵ֮��",
						  "�ȸ����һ��ʱ���ڣ������ڳ��ȶ��ϵ���ո�����",
						  "�ȸ����һ��ʱ���ڣ������ڳ��ȶ��ϵ���ո�����",
						  "������������������û���ո����������£������������еȶ��ϵ���ո���������",
						  "�������ֵ����Ϊ��������"};
vector<string> currency = { "�����","��Ԫ","��Ԫ","ŷԪ","Ӣ��","��Ԫ","��Ԫ"};
vector<string> size = {"Ԫ","ǧԪ","��Ԫ"};
double val = 0;//����
int t = 0; //ʱ��
double inr = 0;//��Ϣ��
int choice_currency = 1;
int choice_size = 1;
void menu_printf(){//��ӡ�˵�
	int i;
	for (i = 0; i < a.size(); i++){
		cout << i + 1 << ',' << a[i] << endl;
	}
	cout << i + 1 << ",���ܽ���" << endl;
	cout << "0,�˳�" << endl;
}
int  menu(){//�˵�����
	int i = -1;
	while (i < 0){
	menu_printf();
	cout << "����������ѡ�";
	cin >> i;
		if (i<0 || i>a.size() + 1){
			cout <<" ������������ ,����������" << endl;
			i = -1;
		}
	}
	return i;
}
void func_printf(){//���ܽ���
	for (int i = 0; i < b.size(); i++){
		cout << i + 1 << ',' << b[i] << endl;
	}
}
class interest//������
{
private:
	double m_val;//����
	int m_t; //ʱ��
	double m_inr;//��Ϣ��
public:
	interest(double val, int t, double inr ) :
		m_val(val),
		m_t(t),
		m_inr(inr)
	{};
	double compound_interest(int i);                                                     
};
double interest::compound_interest(int i){//��ʽ����
	if (i == 1){
		return m_val*pow((1 + m_inr), m_t);
	}
	else if (i == 2){
		return m_val / pow((1 + m_inr), m_t);
	}
	else if (i == 3){
		return (m_val * (pow((1 + m_inr), m_t)-1))/m_inr;
	}
	else if (i == 4){
		return (m_val * (pow((1 + m_inr), m_t) - 1)) / (m_inr * pow((1 + m_inr), m_t));
	}
	else if (i == 5){
		return (m_val * (pow((1 + m_inr), m_t) - 1)) *(1+m_inr)/ m_inr;
	}
	else if (i == 6){
		return (m_val * (pow((1 + m_inr), m_t) - 1)) *(1 + m_inr) /(m_inr * pow((1 + m_inr), m_t));
	}
	else if (i == 7){
		return 0;
	}
	else if (i == 8){
		return m_val / m_inr;
	}

	else{
		return 0;
	}
}

int default_val_curr_choice(){//�����������޸�
	int ch_curr;
	cout << "����ѡ��Ļ������ࣺ1�������(Ĭ��)��2����Ԫ��3����Ԫ��4��ŷԪ��5��Ӣ����6����Ԫ��7����Ԫ/" << endl;
	cout << "���������ѡ��(1~7)��";
	cin >> ch_curr;
	if (ch_curr<1 || ch_curr>7){
		cout <<"�������Ƿ�����ΪĬ��" << endl;
		ch_curr = 1;
	}
	return ch_curr;
}
int default_val_size_choice(){//����С�޸�
	cout << "����ѡ��ĵ�λ��С��1��Ԫ(Ĭ��)��2��ǧԪ��3����Ԫ" << endl;
	int ch_size;
	cout << "���������ѡ��(1~3)��";
	cin >> ch_size;
	if (ch_size<1 || ch_size>3){
		cout << "�������Ƿ�����ΪĬ��" << endl;
		ch_size = 1;
	}
	return ch_size;
}
double default_val(){//����޸�
	choice_currency = default_val_curr_choice();
	choice_size = default_val_size_choice();
	double currency[7] = {1, 1.1152, 0.1423, 0.1274, 0.11, 15.3938, 164.9286 };
	cout << "������Դ����Ѷ�� 2019-11-04"<< endl;
	cout << "����������ֵ��";
	cin >> val;
	return val*currency[choice_currency - 1];
}
int default_t(){//ʱ���޸�
	cout << "����Ϣ���㷽ʽ��ʱ�䵥λ��Ϊ������" << endl;
	cout << "ʱ��Ŀ�ѡ�����뷽ʽ��1��������ʼ�����������2��������Ҫ���������(Ĭ��)"<< endl;
	cout << "���������ѡ��(1/2)��";
	int ch = 0;
	cin >> ch;
	if (ch == 1){
		int start_years = 0,end_years = 0;
		cout << "��������ʼ�����������"<< endl;
		cin >> start_years >> end_years;
		return end_years - start_years;
	}
	else if(ch == 2){
		cout << "��������Ҫ�����������";
		cin >> t;
		return t;
	}
	else{
		cout << "�������Ƿ�����ΪĬ��" << endl;
		cout << "��������Ҫ�����������";
		cin >> t;
		return t;
	}
}
double default_inr(){//��Ϣ���޸�
	cout << "��Ϣ�����룺1����С������ 2�����ٷֱ�����(Ĭ��)"<< endl;
	cout << "���������ѡ��(1/2)��";
	int ch = 0;
	cin >> ch;
	
	if (ch == 1){
		cout << "��������Ϣ�ʣ�";
		cin >> inr;
		return inr;
	}
	else if(ch ==2){
		cout << "��������Ϣ�ʣ�";
		cin >> inr;
		return inr*0.01;
	}
	else{
		cout << "�������Ƿ�����ΪĬ��" << endl;
		cout << "��������Ϣ�ʣ�";
		cin >> inr;
		return inr*0.01;
	}
}
void parameter_input(){//��������
	cout << "���_____(�����|Ԫ)��ʱ��_____(��)����Ϣ��_____(�ٷ���)" << endl;
	int choice = 0;
	cout << "�������Ƿ�Ҫ�����޸ĸ�ֵ��Ĭ�ϵ�λ��1���޸� 2�����޸�"<< endl;
	cout << "���������ѡ��(1/2)��";
	cin >> choice;
	if (choice == 1){
		val = default_val();
		t = default_t();
		inr = default_inr();
	}
	else if(choice ==2){
		cout << "����������Ҫ����Ľ�"; 
			cin >> val;
		cout << "����������Ҫ�����������";
		cin >> t;
		cout << "����������Ҫ�������Ϣ�ʣ�";
		cin>> inr;
		inr = inr*0.01;
	}
	else{
		cout << "�������Ƿ�����ΪĬ��" << endl;
		cout << "����������Ҫ����Ľ�";
		cin >> val;
		cout << "����������Ҫ�����������";
		cin >> t;
		cout << "����������Ҫ�������Ϣ�ʣ�";
		cin >> inr;
		inr = inr*0.01;
	}
}
double deferred_annuity_pre(){
	double temp_val;
	int temp_t1,temp_t2;
	double temp_inr;
	temp_val = default_val();
	cout << "�����벻�軹����Ϣ��������";
	cin >> temp_t1;
	cout << "�����볥����Ϣ��������";
	cin >> temp_t2;
	cout <<"��������Ϣ�ʣ�";
	temp_inr = default_inr();
	interest p1(temp_val,temp_t1+temp_t2,temp_inr);
	interest p2(temp_val, temp_t2, temp_inr);
	return p1.compound_interest(4) - p2.compound_interest(4);
}
double func_realize(){//����ʵ��
	int i = menu();
	if (i > 0 && i < a.size()){
		double aa;
		if (i == 7){
			aa = deferred_annuity_pre();
		}
		else{
			parameter_input();
			interest temp(val, t, inr);
			aa = temp.compound_interest(i);
		}
		cout << b[i - 1] << endl;
		return aa;
	}
	else if (i == a.size()+1){
		func_printf();
		return -1;
	}
	else if (i == 0){
		return 0;
	}
	else{
		return 0;
	}
}
 int func_result(){//�������
	double a_ = func_realize();
	if (a_ == 0){
		cout <<"ллʹ��" << endl;
	}
	else if (a_ == -1){}
	else{
		cout << "you want to get result : " << a_ << '(' << currency[choice_currency-1] << '|' << size[choice_size-1] << ')' << endl;
	}
	return a_;
}

int main(){
	char open = 'o';
	while (open == 'o'){
		if (func_result() != 0){
			cout << "��o������ʹ�ã�������˳���" << endl;
			cin >> open;
		}
		else{
			break;
		}
		system("cls");
	}
	return 0;
}