using namespace std;
#include<iostream>
#include<vector>
#include<algorithm>


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size() < 3)
            return nums[0];

        //�������ȣ��Ǹ�����һ����������λ
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
