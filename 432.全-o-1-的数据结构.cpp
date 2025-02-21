/*
 * @lc app=leetcode.cn id=432 lang=cpp
 *
 * [432] 全 O(1) 的数据结构
 */

// @lc code=start
class AllOne {
    list<pair<unordered_set<string>, int>> lst;//双向链表存 一个set 和 对应的cnt
    unordered_map<string, list<pair<unordered_set<string>, int>>::iterator> nodes;
public:
    AllOne() {
    }
    
    void inc(string key) {
        //在list中有没有key
        if(nodes.count(key)) {
            auto cur = nodes[key], nxt = next(cur);
            if(nxt == lst.end() || nxt->second > (cur->second + 1)) {//刚好cnt多一个的节点不存在
                unordered_set<string> s({key});
                nodes[key] = lst.emplace(nxt, s, cur->second + 1); 
            } else {
                //添加到后一个节点中
                nxt->first.emplace(key);
                nodes[key] = nxt;
            }
            //从当前节点移除
            cur->first.erase(key);
            if(cur->first.empty()) {//如果已经空了就删除
                lst.erase(cur);    
            }
        }
        else {//没有key
            if(lst.empty() || lst.begin()->second > 1) {//链表为空或者没有刚好cnt=1的节点
                unordered_set<string> s({key});
                lst.emplace_front(s, 1);
            } else {
                lst.begin()->first.emplace(key);
            }
            nodes[key] = lst.begin();    
        }
    }
    
    void dec(string key) {
        auto cur = nodes[key];
        if(cur->second == 1) {//如果仅出现一次 那就移除
            nodes.erase(key);    
        } else {
            auto pre = prev(cur);
            if(cur == lst.begin() || ((pre->second) < (cur->second - 1))) {//没有刚好cnt少一个的节点
                unordered_set<string> s({key});
                nodes[key] = lst.emplace(cur, s, cur->second - 1);
            } else {
                pre->first.emplace(key);
                nodes[key] = pre;
            }
        }
        cur->first.erase(key);
        if(cur->first.empty()) {//如果删除完当前节点为空那就删除节点
            lst.erase(cur);    
        }
        
    }
    
    string getMaxKey() {
        return lst.empty() ? "" : *lst.rbegin()->first.begin();//获取cnt最大的node的set中第一个 
    }
    
    string getMinKey() {
        return lst.empty() ? "" : *lst.begin()->first.begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
// @lc code=end

