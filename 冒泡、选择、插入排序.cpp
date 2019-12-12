1.冒泡排序
//对arr数组，从小到大排序
//第一趟，从第一个到最后一个元素，两相邻元素打擂台，找到最大值，并把它放在数组末尾
//第二趟，从第一个到倒数第二个，两相邻元素打擂台，找到最大值，并把它放在数组次尾
//第N趟，待排序数组为0，排序结束
//算法平均时间复杂度O(n^2),空间复杂度O(1)，排序稳定
vector<int> bubbling_sort(vector<int> arr){
    int size_ = (int)arr.size();
    for(int i = 0; i < size_- 1; i++){
        for(int j = 0; j< size_- 1 - i; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    return arr;
}
2.选择排序
//对arr数组，从小到大排序
//第一趟，从第一个到最后一个，选出最小值，放在第一个位置
//第二趟，从第二个到最后一个，选出最小值，放在第二个位置
//算法平均时间复杂度O(n^2),空间复杂度o(1)，排序不稳定
vector<int> select_sort(vector<int> arr){
    int size_ = (int)arr.size();
    int min_index;
    for(int i = 0; i< size_ - 1;i++){
        min_index = i;
        for(int j = i + 1; j < size_; j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        swap(arr[i],arr[min_index]);
    }
    return arr;
}
3.插入排序
//将元素分为已排序与未排序两部分
//默认第一个元素为已排序元素
//拿到未排序的第一个元素，进入已排序元素中，依次比较，找到相应的位置，插入
//时间复杂度O(n^2),空间复杂度O(1),稳定
vector<int> insertion_sort(vector<int> arr){
    int size_ = (int)arr.size();
    int pre_index,current;
    for(int i = 1; i < size_; i++){
        pre_index = i - 1;
        current = arr[i];
        while(pre_index >= 0 && arr[pre_index] > current){
            arr[pre_index + 1] = arr[pre_index];
            pre_index--;
        } 
        arr[pre_index + 1] = curremt;
    }
    return 0;
}