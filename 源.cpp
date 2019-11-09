#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
vector<string> a = { "复利终值", "复利现值", "后付年金终值", "后付年金现值", "先付年金终值", "先付年金现值", "延期年金现值", "永续年金现值" };
vector<string> b = { "复利终值：指当前的一笔资金在若干期后所具有的价值",
                          "复利现值：指未来年份收到或支付的现金在当前的价值又称折现、贴现", 
						  "后付年金终值：零存整取的本利和，一定时期内每期期末等额收付款项的复利终值之和",
						  "后付年金现值：一定期间每期期末等额的系列收付款项的现值之和",
						  "先付年金：一定时期内，各期期初等额的系列收付款项",
						  "先付年金：一定时期内，各期期初等额的系列收付款项",
						  "延期年金：最初期若干期没有收付款项的情况下，后面若干期有等额的系列收付款项的年金",
						  "永续年金：值期限为无穷的年金"};
vector<string> currency = { "人民币","港元","美元","欧元","英镑","日元","韩元"};
vector<string> size = {"元","千元","万元"};
double val = 0;//本金
int t = 0; //时间
double inr = 0;//利息率
int choice_currency = 1;
int choice_size = 1;
void menu_printf(){//打印菜单
	int i;
	for (i = 0; i < a.size(); i++){
		cout << i + 1 << ',' << a[i] << endl;
	}
	cout << i + 1 << ",功能介绍" << endl;
	cout << "0,退出" << endl;
}
int  menu(){//菜单函数
	int i = -1;
	while (i < 0){
	menu_printf();
	cout << "请输入您的选项：";
	cin >> i;
		if (i<0 || i>a.size() + 1){
			cout <<" 您的输入有误 ,请重新输入" << endl;
			i = -1;
		}
	}
	return i;
}
void func_printf(){//功能介绍
	for (int i = 0; i < b.size(); i++){
		cout << i + 1 << ',' << b[i] << endl;
	}
}
class interest//计算类
{
private:
	double m_val;//本金
	int m_t; //时间
	double m_inr;//利息率
public:
	interest(double val, int t, double inr ) :
		m_val(val),
		m_t(t),
		m_inr(inr)
	{};
	double compound_interest(int i);                                                     
};
double interest::compound_interest(int i){//公式计算
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

int default_val_curr_choice(){//金额货币种类修改
	int ch_curr;
	cout << "金额可选择的货币种类：1、人民币(默认)，2、港元，3、美元，4、欧元，5、英镑，6，日元，7、韩元/" << endl;
	cout << "请输入你的选择(1~7)：";
	cin >> ch_curr;
	if (ch_curr<1 || ch_curr>7){
		cout <<"你的输入非法，改为默认" << endl;
		ch_curr = 1;
	}
	return ch_curr;
}
int default_val_size_choice(){//金额大小修改
	cout << "金额可选择的单位大小：1、元(默认)，2、千元，3、万元" << endl;
	int ch_size;
	cout << "请输入你的选择(1~3)：";
	cin >> ch_size;
	if (ch_size<1 || ch_size>3){
		cout << "你的输入非法，改为默认" << endl;
		ch_size = 1;
	}
	return ch_size;
}
double default_val(){//金额修改
	choice_currency = default_val_curr_choice();
	choice_size = default_val_size_choice();
	double currency[7] = {1, 1.1152, 0.1423, 0.1274, 0.11, 15.3938, 164.9286 };
	cout << "汇率来源：和讯网 2019-11-04"<< endl;
	cout << "请输入金额数值：";
	cin >> val;
	return val*currency[choice_currency - 1];
}
int default_t(){//时间修改
	cout << "因利息计算方式，时间单位须为整年数" << endl;
	cout << "时间的可选择输入方式：1、输入起始年份与结束年份2、输入需要计算的年数(默认)"<< endl;
	cout << "请输入你的选择(1/2)：";
	int ch = 0;
	cin >> ch;
	if (ch == 1){
		int start_years = 0,end_years = 0;
		cout << "请输入起始年份与结束年份"<< endl;
		cin >> start_years >> end_years;
		return end_years - start_years;
	}
	else if(ch == 2){
		cout << "请输入需要计算的年数：";
		cin >> t;
		return t;
	}
	else{
		cout << "你的输入非法，改为默认" << endl;
		cout << "请输入需要计算的年数：";
		cin >> t;
		return t;
	}
}
double default_inr(){//利息率修改
	cout << "利息率输入：1、按小数输入 2、按百分比输入(默认)"<< endl;
	cout << "请输入你的选择(1/2)：";
	int ch = 0;
	cin >> ch;
	
	if (ch == 1){
		cout << "请输入利息率：";
		cin >> inr;
		return inr;
	}
	else if(ch ==2){
		cout << "请输入利息率：";
		cin >> inr;
		return inr*0.01;
	}
	else{
		cout << "你的输入非法，改为默认" << endl;
		cout << "请输入利息率：";
		cin >> inr;
		return inr*0.01;
	}
}
void parameter_input(){//参数输入
	cout << "金额_____(人民币|元)、时间_____(年)、利息率_____(百分制)" << endl;
	int choice = 0;
	cout << "请问您是否要进行修改各值的默认单位：1、修改 2、不修改"<< endl;
	cout << "请输入你的选择(1/2)：";
	cin >> choice;
	if (choice == 1){
		val = default_val();
		t = default_t();
		inr = default_inr();
	}
	else if(choice ==2){
		cout << "请输入您想要计算的金额："; 
			cin >> val;
		cout << "请输入您想要计算的年数：";
		cin >> t;
		cout << "请输入您想要计算的利息率：";
		cin>> inr;
		inr = inr*0.01;
	}
	else{
		cout << "你的输入非法，改为默认" << endl;
		cout << "请输入您想要计算的金额：";
		cin >> val;
		cout << "请输入您想要计算的年数：";
		cin >> t;
		cout << "请输入您想要计算的利息率：";
		cin >> inr;
		inr = inr*0.01;
	}
}
double deferred_annuity_pre(){
	double temp_val;
	int temp_t1,temp_t2;
	double temp_inr;
	temp_val = default_val();
	cout << "请输入不需还本付息的年数：";
	cin >> temp_t1;
	cout << "请输入偿还本息的年数：";
	cin >> temp_t2;
	cout <<"请输入利息率：";
	temp_inr = default_inr();
	interest p1(temp_val,temp_t1+temp_t2,temp_inr);
	interest p2(temp_val, temp_t2, temp_inr);
	return p1.compound_interest(4) - p2.compound_interest(4);
}
double func_realize(){//函数实现
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
 int func_result(){//函数结果
	double a_ = func_realize();
	if (a_ == 0){
		cout <<"谢谢使用" << endl;
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
			cout << "按o键继续使用，任意键退出！" << endl;
			cin >> open;
		}
		else{
			break;
		}
		system("cls");
	}
	return 0;
}