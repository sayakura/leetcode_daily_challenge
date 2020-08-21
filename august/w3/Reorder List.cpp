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
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode *> vt;
        vector<ListNode *> vt2;

        if (!head)
            return ;
        while (head) {
            vt.push_back(head);
            head = head->next;
        }
        const int n = vt.size(); 
        vt2 = vector<ListNode *>(n);
        for (int i = 0, end = n - 1, start = 0; i < n; i++) {
            if (i & 1) vt2[i] = vt[end--];
            else vt2[i] = vt[start++];
        }
        for (int i = 0; i < n  - 1; i++) 
            vt2[i]->next = vt2[i + 1];
        vt2.back()->next = nullptr;
        return ;
    }
};