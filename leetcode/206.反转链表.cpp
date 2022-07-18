/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/* class ListNode {
   public:
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
}; */

class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        //特殊情况
        if (!head || head->next == nullptr) {
            return head;
        }
        if (head->next->next == nullptr) {
            head->next->next = head;
            head = head->next;
            head->next->next = nullptr;
            return head;
        }
        // 始终维护三个指针
        ListNode* next1 = head->next;
        ListNode* next2 = head->next->next;
        // 处理第一个
        head->next = nullptr;
        while (next2->next != nullptr) {
            //没到尾部
            next1->next = head;
            head = next1;
            next1 = next2;
            next2 = next2->next;
        }
        //处理最后一个
        next1->next = head;
        next2->next = next1;
        head = next2;
        return head;
    }
};
// @lc code=end
