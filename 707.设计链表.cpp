/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
class MyLinkedList {
    struct Node
    {
        Node(int v)
            :val(v)
            ,next(nullptr)
        {}
        int val;
        Node* next;
    };
    
public:
    MyLinkedList() {
        size_ = 0;
        head_ = new Node(-1);
        m_.clear();
    }
    
    int get(int index) {
        if(index >= size_)
            return -1;
        return m_[index]->val;
    }
    
    void addAtHead(int val) {
        auto node = new Node(val);
        node->next = head_->next;
        head_->next = node;
        size_++;
        m_.insert(m_.begin(), node);
    }
    
    void addAtTail(int val) {
        auto node = new Node(val);
        if(size_ == 0) {
            addAtHead(val);
        }
        else {
            auto last = m_[size_ - 1];
            last->next = node;
            m_.push_back(node);
            size_++;
        }
    }
        
    void addAtIndex(int index, int val) {
        if(index > size_) return;
        if (size_ == 0) {
            addAtHead(val);
        }
        else if(index == size_) {
            addAtTail(val);
        }
        else {
            if(index != 0) {
                auto pre = m_[index - 1];
                auto node = new Node(val);
                node->next = pre->next;
                pre->next = node;
                m_.insert(m_.begin() + index, node);
                size_++;
            }
            else {
                addAtHead(val);
            }
        }
        return;
    }
    
    void deleteAtIndex(int index) {
        if(index >= size_)
            return;
        if(index == 0) {
            auto node = head_->next;
            head_->next = node->next;
            m_.erase(m_.begin() + index);
            delete node;
        }
        else {
            auto node = m_[index - 1];
            auto del = node->next;
            node->next = del->next;
            m_.erase(m_.begin() + index);
            delete del;
        }
        size_--;
        return;
    }

    int size_;
    Node* head_;
    // [index, node*]
    vector<Node*> m_;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

