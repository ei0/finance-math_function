/*
P15数组中出现次数大于等于数组长度一半的数
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int length = numbers.size();
		if (length == 0) {
			return 0;
		}
		//找出数组中最多出现的数
		int result = numbers[0];
		int times = 1;
		for (int i = 1; i < length; i++) {
			if (times == 0) {
				result = numbers[i];
				times = 1;
			}
			else {
				if (numbers[i] == result) {
					times++;
				}
				else {
					times--;
				}
			}
		}
		//判断该数出现的次数是否大于等于数组长度
		times = 0;
		for (int i = 0; i < length; i++) {
			if (result == numbers[i]) {
				times++;
			}
		}

		if (times * 2 < length) {
			result = 0;
		}
		return result;
	}
	

};
int main(){
    Solution a;
    vector<int> nums{1,2,2,2,3,3,2,4,2};
    cout<<a.MoreThanHalfNum_Solution(nums)<<endl;
    return 0;
}