using namespace std;
#include<iostream>
#include<vector>

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        int cnt = 0;
        int emp = 0;
        for (int i = 0; i < n + 1; ++i) {
            cnt = 0;
            emp = i;
            while (emp != 0) {
                if ((emp & 1) == 1)
                    cnt++;
                emp = emp >> 1;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};


class Solution1 {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            ans[i] = i & 1 ? ans[i - 1] + 1 : ans[i >> 1];
        }
        return ans;
    }
};

