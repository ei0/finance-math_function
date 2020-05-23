/*
滑动窗口解题法
维护一个有left和right的窗口
1.先向右扩展直到条件满足
2.再从左缩小窗口，条件满足则一直缩小，直至不满足，记录最优解，
*/
int left = 0, right = 0;

while (right < s.size()) {
		// 1. 增大窗口
		window.add(s[right++]);
		//```
		// 2. 根据题目要求更新数据
		window.update();
		//```
	while (window needs shrink) {
		
		//1. 比较记录最优解
		record_optimal_solution();
		// 2. 缩小窗口
		window.remove(s[left++]);

		// 3.根据题目要求更新数据
		window.update();
	}
}

/*1. 最小覆盖字串问题
给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字符的最小子串。
如果 S 中不存这样的子串，则返回空字符串 ""。
如果 S 中存在这样的子串，我们保证它是唯一的答案。
示例：
输入 : S = "ADOBECODEBANC", T = "ABC"
输出 : "BANC"
*/
string P32(string s, string t) {
	unordered_map<char, int> need, window;
	for (char c : t) need[c]++;

	int left = 0, right = 0;
	int valid = 0;
	// 记录最小覆盖子串的起始索引及长度
	int start = 0, len = INT_MAX;
	while (right < s.size()) {
		// c 是将移入窗口的字符
		char c = s[right];
		// 右移窗口
		right++;
		// 进行窗口内数据的一系列更新
		if (need.count(c)) {
			window[c]++;
			if (window[c] == need[c])
				valid++;
		}

		// 判断左侧窗口是否要收缩
		while (valid == need.size()) {
			// 在这里更新最小覆盖子串
			if (right - left < len) {
				start = left;
				len = right - left;
			}
			// d 是将移出窗口的字符
			char d = s[left];
			// 左移窗口
			left++;
			// 进行窗口内数据的一系列更新
			if (need.count(d)) {
				if (window[d] == need[d])
					valid--;
				window[d]--;
			}
		}
	}
	// 返回最小覆盖子串
	return len == INT_MAX ?
		"" : s.substr(start, len);
}