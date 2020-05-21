//建堆1
 //默认第一个元素为已排好的大根堆
 //标记位走到第二个元素，比较当前元素与其父元素的大小，若大于则交换
 //比较为循环比较，交换后，会将当前元素替换为父元素，再与祖元素进行比较，一直循环，直到小于上级元素，或到根元素。
//最差时间复杂度O（nlong2n）,最好O(nlog2n),平均O(nlog2n),空间复杂度O(1),不稳定
void heap1(vector<int>& num, int n)//从数组插入构建
{
	//int len = num.size();
	for (int i = 0; i < n; i++) {
		int cur_index = i;
		int father_index = (i - 1) / 2;
		while (num[cur_index] > num[father_index]) {
			std::swap(num[cur_index], num[father_index]);
			cur_index = father_index;
			father_index = (cur_index - 1) / 2;
		}
	}
}
void heapSort1(vector<int>& arr) {
	//构造大根堆 
	int size = arr.size();
	heap1(arr, size);
	//heapify(arr, 0, size);
	while (size > 1) {
		//固定最大值
		std::swap(arr[0], arr[size - 1]);
		size--;
		//构造大根堆
		heap1(arr, size);

	}

}
//希尔排序
//最差时间复杂度O（n^2）,最好O(n),平均O(n^1.3),空间复杂度O(1),不稳定
void shellSort(int a[], int n)  //a -- 待排序的数组, n -- 数组的长度
{
	int i, j, gap;   // gap为步长，每次减为原来的一半。
	for (gap = n / 2; gap > 0; gap /= 2)
	{
		// 共gap个组，对每一组都执行直接插入排序
		for (i = 0; i < gap; i++)
		{
			for (j = i + gap; j < n; j += gap)
			{
				// 如果a[j] < a[j-gap]，则寻找a[j]位置，并将后面数据的位置都后移。
				if (a[j] < a[j - gap])
				{
					//插入排序
					int tmp = a[j];
					int k = j - gap;
					while (k >= 0 && a[k] > tmp)
					{
						a[k + gap] = a[k];
						k -= gap;
					}
					a[k + gap] = tmp;
				}
			}
		}
	}
}

//归并排序
//最差时间复杂度O（nlong2n）,最好O(nlog2n),平均O(nlog2n),空间复杂度O(n),稳定
void Merge(int arr[], int l, int q, int r) {
	int n = r - l + 1;//临时数组存合并后的有序序列
	int* tmp = new int[n];
	int i = 0;
	int left = l;
	int right = q + 1;
	while (left <= q && right <= r)
		tmp[i++] = ((arr[left] <= arr[right]) ? arr[left++] : arr[right++]);
	/*for (int k = i; left <= q; k++,left++) {
		tmp[k] = arr[left];
	}*/
	while (left <= q)
		tmp[i++] = arr[left++];
	while (right <= r)
		tmp[i++] = arr[right++];
	for (int j = 0; j < n; ++j)
		arr[l + j] = tmp[j];
	delete[] tmp;//删掉堆区的内存
}

void MergeSort(int arr[], int l, int r) {
	if (l == r)
		return;  //递归基是让数组中的每个数单独成为长度为1的区间
	int q = (l + r) / 2;
	MergeSort(arr, l, q);
	MergeSort(arr, q + 1, r);
	Merge(arr, l, q, r);
}
//快排
//最差时间复杂度O（n^2）,最好O(nlog2n),平均O(nlog2n),空间复杂度O(log2n),不稳定
void quickSort(int s[], int l, int r) {
	if (l < r)
	{
		int i = l, j = r, x = s[l];
		while (i < j)
		{
			while (i < j && s[j] >= x) // 从右向左找第一个小于x的数
				j--;
			if (i < j)
				s[i++] = s[j];
			while (i < j && s[i] < x) // 从左向右找第一个大于等于x的数
				i++;
			if (i < j)
				s[j--] = s[i];
		}
		s[i] = x;
		//一次循环后被放置到数组的中间位置，前面的元素小于基准值，后面的元素大于基准值
		quickSort(s, l, i - 1); // 递归调用
		quickSort(s, i + 1, r);
	}
}