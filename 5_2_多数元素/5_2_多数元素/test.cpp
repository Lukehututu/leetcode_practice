using namespace std;
#include<iostream>
#include<vector>
#include<algorithm>


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int right = nums.size() - 1;
        int left = 0;
        sort(nums.begin(), nums.end());
        while (nums[left] != nums[right]) {
            left++;
            right--;
        }
        return nums[left];
    }
};