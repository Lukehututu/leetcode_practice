#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int maximizeSum(int* nums, int numsSize, int k)
{
    //先得到一个升序数组
    int l = sizeof(nums) / sizeof(nums[0]);
    for (int i = 0; i < l-1; i++)
    {
        for (int j = 0; j < l - i - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                int tmp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = tmp;
            }
        }
    }
    //计算返回值
    int target = 0;
    for (int i = 0; i < k; i++)
    {
        target += nums[l - 1];
        nums[l - 1]++;
    }
    numsSize = l;
    return target;
}

int main()
{
    int arr[] = { 1,2,3,4,5 };
    int i = maximizeSum(arr, 1, 3);
    printf("%d\n", i);


}