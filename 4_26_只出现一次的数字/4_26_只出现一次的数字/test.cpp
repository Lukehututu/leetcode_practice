using namespace std;
#include<iostream>
#include<vector>
#include<algorithm>


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size() < 3)
            return nums[0];

        //如果不相等，那该数字一定是在奇数位
        sort(nums.begin(), nums.end());
        int pre = 0;
        int post = 1;
        for (; post < nums.size(); post += 2, pre += 2) {
            if (nums[pre] != nums[post])
                break;
        }
        return nums[pre];
    }
};


int main() {
    vector<int> nums = { 2,2,1 };
    cout << Solution().singleNumber(nums) << endl;

}
