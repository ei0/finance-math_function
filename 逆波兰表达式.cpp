#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cstdlib>
#include <stack>
using namespace std;

//逆波兰算式
//可将算式按次序放进二叉树中，再后续遍历得到逆波兰表达式
int evalRPN(vector<string>& tokens)
{
	stack<int> tmp;
	int a, b;

	for (auto & vsi : tokens)
	{
		if (isdigit(vsi[0]) || vsi.size() > 1)
		{
			tmp.push(atoi(vsi.c_str()));
		}
		else
		{
			a = tmp.top();
			tmp.pop();
			b = tmp.top();

			switch (vsi[0])
			{
			case '+':
				tmp.top() = b + a;
				break;
			case '-':
				tmp.top() = b - a;
				break;
			case '*':
				tmp.top() = b * a;
				break;
			case '/':
				tmp.top() = b / a;
				break;
			}
		}
	}
	return tmp.top();
}

int main()
{
	vector<string> vs{ "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" };

	cout << evalRPN(vs);
	return 0;
}