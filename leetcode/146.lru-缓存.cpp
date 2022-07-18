/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
#include <cstddef>
#include <unordered_map>
/*
    LRU cache通过双向链表维护
    unordered_map查找时间为O(1)
    通过unordered_map存储key对应在cache中的位置,而不用遍历链表
 */
class DLinkedNode {
   public:
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(){};
    DLinkedNode(int k, int v) : key(k), value(v){};
};
class LRUCache {
   private:
    int capacity, size;
    DLinkedNode *head, *tail;
    std::unordered_map<int, DLinkedNode*> cache;

   public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!cache[key]) {
            return -1;
        } else {
            DLinkedNode* node = cache[key];
            //移除节点
            removeNode(node);
            //插入到head
            insertToHead(node);
            return node->value;
        }
    }

    void put(int key, int value) {
        if (!cache[key]) {
            //创建并插入节点
            DLinkedNode* node = new DLinkedNode(key, value);
            //插入到head
            insertToHead(node);
            // cache
            cache[key] = node;
            ++size;
            if (size > capacity) {
                //移除末尾节点
                DLinkedNode* nodeToBeRemoved = tail->prev;
                removeNode(nodeToBeRemoved);
                // cache
                cache.erase(nodeToBeRemoved->key);
                delete nodeToBeRemoved;
                --size;
            }
        } else {
            DLinkedNode* node = cache[key];
            node->value = value;
            //移除节点
            removeNode(node);
            //插入到head
            insertToHead(node);
        }
    }
    void removeNode(DLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void insertToHead(DLinkedNode* node) {
        node->prev = head;
        node->next = head->next;
        node->prev->next = node;
        node->next->prev = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
