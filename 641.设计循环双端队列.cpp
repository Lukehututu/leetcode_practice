/*
 * @lc app=leetcode.cn id=641 lang=cpp
 *
 * [641] 设计循环双端队列
 */

// @lc code=start
class MyCircularDeque {
    struct Node
    {
        Node(int v)
            :val(v)
            ,next(nullptr)
            ,pre(nullptr)
        {}
        int val;
        Node* next;
        Node* pre;   
    };
    
public:
    MyCircularDeque(int k) {
        size_ = 0;
        cap_ = k;
        head_ = new Node(0);
        tail_ = new Node(0);
        head_->next = tail_;
        tail_->pre = head_;
        head_->pre = tail_;
        tail_->next = head_;
    }
    
    bool insertFront(int value) {
        if(size_ == cap_)
            return false;
        auto node = new Node(value);
        node->next = head_->next;
        node->next->pre = node;
        head_->next = node;
        node->pre = head_;
        size_++;
        return true;
    }
    
    bool insertLast(int value) {
        if(size_ == cap_)
            return false;
        auto node = new Node(value);
        node->pre = tail_->pre;
        node->pre->next = node;
        node->next = tail_;
        tail_->pre = node;
        size_++;
        return true;
    }
    
    bool deleteFront() {
        if(size_ == 0)  
            return false;
        auto node = head_->next->next;
        auto del = head_->next;
        head_->next = node;
        node->pre = head_;
        size_--;
        delete del;
        return true;
    }
    
    bool deleteLast() {
        if(size_ == 0)
            return false;
        auto node = tail_->pre->pre;
        auto del = tail_->pre;
        node->next = tail_;
        tail_->pre = node;
        size_--;
        delete del;
        return true;
    }
    
    int getFront() {
        if(size_ == 0)
            return -1;
        return head_->next->val;
    }
    
    int getRear() {
        if(size_ == 0) 
            return -1;
        return tail_->pre->val;    
    }
    
    bool isEmpty() {
        return size_ == 0;
    }
    
    bool isFull() {
        return size_ == cap_;
    }

    Node* head_;
    Node* tail_;
    int size_;
    int cap_;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
// @lc code=end

