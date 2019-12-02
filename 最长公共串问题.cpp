//查找两字符串中最长公共串
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a, b;//两字符串a,b
	while (cin >> a >> b)
	{
		if (a.size() > b.size())
			swap(a, b);       //确保前面的一个字符串短;
		string str_m;//保存最长公共串
		for (int i = 0; i < a.size(); i++)
		{
			for (int j = i; j < a.size(); j++)
			{
				string temp = a.substr(i, j - i + 1);//临时保存目前最长公共串，用于更新
				if (int(b.find(temp)) < 0)
					break;
				else if (str_m.size() < temp.size())
					str_m = temp;
			}
		}
		cout << str_m << endl;//输出结果
	}
	return 0;
}
//基于上面的代码输出最长公共串的长度，函数实现
#include<iostream>
#include<string>
using namespace std;
int getCommonStrLength(char* pFirstStr, char* pSecondStr) {
	const char* p1 = (const char*)pFirstStr;
	const char* p2 = (const char*)pSecondStr;
	string a = p1;
	string b = p2;
	if (a.size() > b.size())
		swap(a, b);       //确保前面的一个字符串短;
	string str_m;
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = i; j < a.size(); j++)
		{
			string temp = a.substr(i, j - i + 1);
			if (int(b.find(temp)) < 0)
				break;
			else if (str_m.size() < temp.size())
				str_m = temp;
		}
	}
	return (int)str_m.size();
}
int main()
{
	string a, b;
	while (cin >> a >> b)
	{
		char* aa = (char*)a.c_str();
		char* bb = (char*)b.c_str();
		cout << getCommonStrLength(aa,bb)<<endl;
	}
	return 0;
}