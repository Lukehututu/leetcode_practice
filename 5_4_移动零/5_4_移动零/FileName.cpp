#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() == 1)
            return;
        int cnt = nums.size();

        for (vector<int>::iterator it = nums.begin(); it < nums.end();) {
            if (*it == 0)
                it = nums.erase(it);
            else
                ++it;
        }

        int cnt2 = nums.size();
        nums.insert(nums.end(), cnt - cnt2, 0);
        return;
    }
};

void swap(int& a, int& b) {
    int emp = a;
    a = b;
    b = emp;
}

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow, fast;
        slow = 0;
        fast = slow;
        while (fast < nums.size()) {
            if (nums[fast]) {
                swap(nums[slow], nums[fast]);
                slow++;
            }
            fast++;
        }
    }
};

int main() {
    vector<int> nums = { 0,0,1 };

    Solution().moveZeroes(nums);



}
