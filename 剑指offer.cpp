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