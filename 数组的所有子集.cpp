#include<iostream>
using namespace std;
void subset_all(int* a, int len) {
	int t = 1 << len;
	int i, j, k;
	for (i = 0; i < t; i++)
	{
		j = i;
		k = 0;
		cout << "{";
		while (j) {
			if (j & 1)cout << a[k];//子集中的各元素
			j >>= 1;
			++k;
		}//一个子集输出完毕
		cout << "}" << endl;
	}
}
int main()
{
	int a[4] = { 1, 2, 3, 4 };
	subset_all(a, 4);
	return 0;
}
