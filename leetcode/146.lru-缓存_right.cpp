/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
/*
        要求get和put的时间复杂度为O(1),不能通过map进行存储
        key 最大1000 直接开数组
 */

#include <cstddef>
#include <cstdio>
#include <unordered_map>
using namespace std;

struct DLinkedNode {
    int key, value;
    DLinkedNode* prev = nullptr;
    DLinkedNode* next = nullptr;
    DLinkedNode() : key(0), value(0){};
    DLinkedNode(int k, int v) : key(k), value(v){};
};

class LRUCache {
   public:
    LRUCache(int capacity) {
        size = 0;
        this->capacity = capacity;
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    };
    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        //访问,需要修改位置
        moveToHead(cache[key]);
        return cache[key]->value;
    };
    void put(int key, int value) {
        if (cache.count(key)) {
            //访问，需要修改位置
            cache[key]->value = value;
            moveToHead(cache[key]);
        } else {
            // 插入
            ++size;
            DLinkedNode* node = new DLinkedNode(key, value);
            cache[key] = node;
            //添加到头部
            addToHead(node);
            if (size > capacity) {
                //删除末尾
                DLinkedNode* removed = removeTail();
                cache.erase(removed->key);  //这里值得注意
                delete removed;
                --size;
            }
        }
    };
    void addToHead(DLinkedNode* node) {
        node->prev = head;
        node->next = head->next;
        head->next = node;
        node->next->prev = node;
    }
    void removeNode(DLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }
    DLinkedNode* removeTail() {
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }

   private:
    DLinkedNode *head, *tail;
    unordered_map<int, DLinkedNode*> cache;
    int capacity, size;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
