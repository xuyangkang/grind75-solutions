/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

using int64 = int64_t;
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<int64> seen;
        for (ListNode *i = head; i; i = i->next) {
            int64 ptr_i = (int64)i;
            if (seen.count(ptr_i)) {
                return true;
            }
            seen.insert(ptr_i);
        }
        return false;
    }
};