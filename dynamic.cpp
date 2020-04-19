#if 1 //question 1
//动态规划1
//只能向右或下走
//n*n的矩阵，求从（0，0）到（n，n）路径中每格数据累计的最大值
#include<iostream>
#include<vector>
using namespace std;
class Bonus {
public:
	int getMost(vector<vector<int> > board) {
		int up_num = 0;
		int left_num = 0;
		int row = (int)board.size();
		int lin = (int)board[0].size();
		if (row != lin) {
			return -1;
		}
		for (int i = 1; i < row; i++) {
			board[i][0] += board[i - 1][0];
		}
		for (int i = 1; i < lin; i++) {
			board[0][i] += board[0][i - 1];
		}
		for (int i = 1; i < row; i++) {
			for (int j = 1; j < lin; j++) {
				up_num = board[i - 1][j];
				left_num = board[i][j - 1];
				if (up_num < left_num) {
					board[i][j] += left_num;
				}
				else {
					board[i][j] += up_num;
				}
			}
		}
		return board[row - 1][lin - 1];
	}
};
int main() {
	int a[6][6] = { 426,306,641,372,477,409 ,223, 172, 327, 586, 363, 553,292, 645, 248, 316, 711, 295,
		127, 192, 495, 208, 547, 175,
		131, 448, 178, 264, 207, 676,
		655, 407, 309, 358, 246, 714 };


	vector<vector<int>> p(6, vector<int>(6));
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			p[i][j] = a[i][j];
		}
	}
	Bonus aa;
	cout << aa.getMost(p);
	return 0;
} 
#else//question 2
 //动态规划—最佳路径问题  
//0为可通过1为不可通过，可向上下左右四方向走
#include<iostream>
#include<vector>
using namespace std;
int main() {
	int row = 0, lin = 0;
	while (cin >> row >> lin) {
		vector<vector<int>> map(row, vector<int>(lin));
		cout << endl;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < lin; j++) {
				cin >> map[i][j];
			}
			cout << endl;
		}
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < lin; j++) {

			}
		}
		int i = 0, j = 0;
		while (1) {
			if (map[i + 1][j] == 0) {
				i++;
			}
		}
	}
	return 0;
}
#endif