#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int hash[10000] = { 0 };
        for (int i : nums) {
            hash[i] = 1;
        }
        vector<int>ans;
        for (int j = 1; j < nums.size() + 1; j++) {
            if (hash[j] == 0)
                ans.push_back(j);
        }
        return ans;
    }
};