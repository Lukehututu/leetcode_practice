#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include<iostream>



//ð������취
int removeDuplicates(int* nums, int numsSize) {

	//����ָ��һ��ָ��������λ�ã���һ��ָ��������Ԫ��
	int* pos = nums;
	int* val = nums + 1;
	int cnt = 0;//������¼��������ĳ���

	while (true)//��ʼ��val��λ��
	{
		if (*val == *pos)
			val++;
		else
			break;
	}
	pos++;//��һ���������λ�þ��ǵڶ�λ

	while (val-nums<numsSize)
	{
		*pos = *val;
		while (true)//����val��λ��
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
