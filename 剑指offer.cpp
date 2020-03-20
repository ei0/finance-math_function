bool Find(int target, vector<vector<int> > array)//剑指offer 1二维数组中查找
{
	if (array.empty())
		return false;
	int row = array.size();
	for (int i = 0; i < row; i++)
	{
		if (array[i].empty())
			continue;
		if (array[i][0] <= target)
		{
			if (array[i][array[i].size() - 1] >= target)
			{
				for (int j = 0; j < array[i].size(); j++) {
					if (array[i][j] == target)
						return true;
				}
				continue;
			}
			else
				continue;
		}
		else
			continue;
	}
	return false;
}
void replaceSpace(char* str, int length) //剑指offer 2替换字符串中的空格
//逆序替换，减少移动次数
{
	if (str == NULL)
		return;
	int space_conut = 0;
	int str_len = 0;
	while (*str != '\0')
	{
		str_len++;
		if (*str == ' ')
			space_conut++;
		str += 1;
	}
	int len = str_len + space_conut * 2;
	char* p1 = str + len;
	char* p2 = str + str_len;
	while (p1 > p2)
	{
		if (*p2 == ' ')
		{
			*p1-- = '0';
			*p1-- = '2';
			*p1-- = '%';
		}
		else
		{
			//*p1-- = *p2;
			*p1 = *p2;
			p1--;
		}
		p2--;
	}

	//if (str == NULL)
	//	return;
	//int CountOfBlanks = 0;
	//int Originallength = 0;
	//for (int i = 0; str[i] != '\0'; i++)
	//{
	//	Originallength++;
	//	if (str[i] == ' ')
	//		++CountOfBlanks;
	//}
	//int len = Originallength + 2 * CountOfBlanks;
	//if (len + 1 > length)
	//	return;

	//char* pStr1 = str + Originallength;//复制结束符‘\0’12
	//char* pStr2 = str + len;//16
	//while (pStr1 < pStr2)
	//{
	//	if (*pStr1 == ' ')
	//	{
	//		*pStr2-- = '0';
	//		*pStr2-- = '2';
	//		*pStr2-- = '%';
	//	}
	//	else
	//	{
	//		*pStr2-- = *pStr1;
	//	}
	//	--pStr1;
	//}
}
struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

vector<int> printListFromTailToHead(ListNode* head) {//剑指offer 3链表逆序输出
	ListNode* tmp;
	vector<int> num;
	for (tmp = head; tmp; tmp = tmp->next)
	{
		num.push_back(tmp->val);
	}
	vector<int> num1;
	auto e = num.rbegin();
	for (e; e != num.rend(); e++)
	{
		num1.push_back(*e);
	}
	return num1;
}
//利用数组做


struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//
//TreeNode* Tree_son(vector<int> pre_part, vector<int> vin_part)
//{
//	TreeNode* head_p = new TreeNode(0);
//	TreeNode* tmp_c = head_p;
//	int k = -1,m = 0;
//	for (int i = 0; i < pre_part.size() ; i++)
//	{
//		for (int j = 0; j < vin_part.size(); j++)
//		{
//			if (pre_part[i] == vin_part[j])
//			{
//				if (k < 0)
//				{
//					k = j;
//					m = k;
//				}
//				if (m > 0 && m < vin_part.size()-1)
//				{
//					auto pre_i = pre_part.begin();
//					auto vin_i = vin_part.begin();
//					tmp_c->left = Tree_son(vector<int>(pre_i , pre_i + k + 1), vector<int>(vin_i, vin_i + k+1));
//					if(tmp_c->left->right == NULL)
//						tmp_c->left->right = Tree_son(vector<int>(pre_i + k + 1, pre_part.end()), vector<int>(vin_i + k+1, vin_part.end()));
//					else
//						tmp_c->left->left = Tree_son(vector<int>(pre_i + k + 1, pre_part.end()), vector<int>(vin_i + k + 1, vin_part.end()));
//					return head_p->left ? head_p->left : head_p->right;
//				}
//
//				TreeNode* tmp = new TreeNode(vin_part[j]);
//				if (j < k)
//				{
//					tmp_c->left = tmp;
//					tmp_c = tmp_c->left;
//					k = j;
//				}
//				else
//				{
//					tmp_c->right = tmp;
//					tmp_c = tmp_c->right;
//					k = j;
//				}
//
//			}
//
//		}
//	}
//	return head_p->left ? head_p->left : head_p->right;
//}
//
//TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
//	if (pre.empty() || vin.empty())return 0;
//	TreeNode* head = new TreeNode(pre[0]);
//	int k = -1;
//	for (int j = 0; j < vin.size() ; ++j)
//	{
//		if (pre[0] == vin[j])
//		{
//			k = j;
//			break;
//		}
//	}
//	auto pre_i = pre.begin();
//	auto vin_i = vin.begin();
//	head->left = Tree_son(vector<int>(pre_i+1 , pre_i + k+1), vector<int>(vin_i, vin_i+k));
//	head->right = Tree_son(vector<int>(pre_i + k + 1, pre.end()), vector<int>(vin_i + k+1, vin.end()));
//	return head;
//}
TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {//剑指offer 4重组二叉树，给出前序和中序
	if (pre.empty() || vin.empty())return 0;
	TreeNode* head = new TreeNode(pre[0]);
	int k = -1;
	for (int j = 0; j < vin.size(); ++j)
	{
		if (pre[0] == vin[j])
		{
			k = j;
			break;
		}
	}
	auto pre_i = pre.begin();
	auto vin_i = vin.begin();
	head->left = reConstructBinaryTree(vector<int>(pre_i + 1, pre_i + k + 1), vector<int>(vin_i, vin_i + k));
	head->right = reConstructBinaryTree(vector<int>(pre_i + k + 1, pre.end()), vector<int>(vin_i + k + 1, vin.end()));
	return head;
}

class Solution//剑指offer 5用栈实现队列
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		while (!stack1.empty())
		{
			stack2.push(stack1.top());
			stack1.pop();
		}
		int tmp = 0;
		tmp = stack2.top();
		stack2.pop();
		while (!stack2.empty())
		{
			stack1.push(stack2.top());
			stack2.pop();
		}
		return tmp;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};
int Fibonacci(int n) {//剑指offer 7斐波那契数列
	int cur = 0;
	int f0 = 0, f1 = 1;
	if (n == 0 || n == 1) return n;
	while (n - 1)
	{
		cur = f0 + f1;
		f0 = f1;
		f1 = cur;
		n--;
	}
	return cur;
}
int Fibonacci_di(int n) {//剑指offer 7斐波那契数列递归版

	if (n == 0 || n == 1)
		return n;
	else
		return Fibonacci_di(n - 2) + Fibonacci_di(n - 1);
}
int jumpFloor(int n) {//剑指offer 8跳台阶---一次一格或两个
	int cur = 0;
	int f0 = 1, f1 = 1;
	if (n == 0 || n == 1) return n;
	while (n - 1)
	{
		cur = f0 + f1;
		f0 = f1;
		f1 = cur;
		n--;
	}
	return cur;
}

int jumpFloorII(int number)//剑指offer 9跳台阶--一次随意格
{
	if (number <= 0)
		return -1;
	if (number == 1 || number == 2)
		return number;
	return 2 * jumpFloorII(number - 1);
}
int rectCover(int number) {//剑指offer 10矩形覆盖
	//我们可以用2 * 1的小矩形横着或者竖着去覆盖更大的矩形。
	//请问用n个2 * 1的小矩形无重叠地覆盖一个2 * n的大矩形，总共有多少种方法
	//斐波那契数列问题变种
	int cur = 0;
	int f0 = 1, f1 = 1;
	if (number == 0 || number == 1) return number;
	while (number - 1)
	{
		cur = f0 + f1;
		f0 = f1;
		f1 = cur;
		number--;
	}
	return cur;
}