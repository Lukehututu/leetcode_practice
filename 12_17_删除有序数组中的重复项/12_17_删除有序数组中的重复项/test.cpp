#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include<iostream>



//冒泡排序办法
int removeDuplicates(int* nums, int numsSize) {

	//两个指针一个指向待插入的位置，另一个指向待插入的元素
	int* pos = nums;
	int* val = nums + 1;
	int cnt = 0;//用来记录有新数组的长度

	while (true)//初始化val的位置
	{
		if (*val == *pos)
			val++;
		else
			break;
	}
	pos++;//第一个待插入的位置就是第二位

	while (val-nums<numsSize)
	{
		*pos = *val;
		while (true)//更新val的位置
		{
			if (*val == *pos)
				val++;
			else
				break;
		}
		pos++;
		cnt++;
	}
	numsSize = cnt + 1;
	return numsSize;
}

int main()
{
	int nums[3] = { 1,1,2 };
	int numsSize = 3;
	cout <<removeDuplicates(nums, numsSize);
	
}
