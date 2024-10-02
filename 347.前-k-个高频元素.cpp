/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 *
 * https://leetcode.cn/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (63.97%)
 * Likes:    1895
 * Dislikes: 0
 * Total Accepted:    610.3K
 * Total Submissions: 952.9K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * 给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums = [1,1,1,2,2,3], k = 2
 * 输出: [1,2]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: nums = [1], k = 1
 * 输出: [1]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * k 的取值范围是 [1, 数组中不相同的元素的个数]
 * 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的
 * 
 * 
 * 
 * 
 * 进阶：你所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //	建立元素与频率的键值对
        unordered_map<int, int> hash;
        for (auto i : nums)
        {
            hash[i]++;
        }

        //	提供比较方法（根据second来比较）
        auto _less = [](pair<int, int> pair_a, pair<int, int> pair_b) {
            return pair_a.second > pair_b.second; 
            };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(_less)> pq(_less);
        auto it = hash.begin();
        for (int i = 0; i < k; it++, i++)
        {
            pq.push(*it);
        }

        //	构建好了k个元素的小根堆后，往后遍历hash
        for (; it != hash.end(); it++)
        {
            //	如果比堆顶元素大，就入堆
            if (pq.top().second < it->second)
            {
                pq.push(*it);
                pq.pop();
            }
        }

        //	此时pq中的就是出现频率最高的k个元素
        vector<int> ret;
        while (!pq.empty())
        {
            ret.emplace_back(pq.top().first);
            pq.pop();
        }
        return ret;
    }
};
// @lc code=end

