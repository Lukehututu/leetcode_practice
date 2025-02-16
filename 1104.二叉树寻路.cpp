/*
 * @lc app=leetcode.cn id=1104 lang=cpp
 *
 * [1104] 二叉树寻路
 */

// @lc code=start
class Solution {
public:
    vector<int> res;

    vector<int> pathInZigZagTree(int label) {
        res.insert(res.begin(), label);
        if(label == 1) {
            return res;
        }
        //去找父节点
        //先算出是第几行第几个 (从上往下 从左往右)
        int level = log2(label) + 1;
        bool isEven = (level % 2 == 0);
        int parent{};
        int num = label / 2;
        if(num == 1) {
            res.insert(res.begin(), 1);
            return res;
        }
        if(isEven) {
            int off = abs(num - (pow(2, level - 1) - 1));
            parent = pow(2, level - 2) + off;
        }
        else {
            int off = abs(num - pow(2, level - 2));
            parent = pow(2, level - 1) - 1 - off;
        }
        pathInZigZagTree(parent);
        return res;
    }
};
// @lc code=end

