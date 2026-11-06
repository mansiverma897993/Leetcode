class Solution {
public:
    ListNode* mergeTwo(ListNode* a, ListNode* b) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (a && b) {
            if (a->val <= b->val) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }

            tail = tail->next;
        }

        tail->next = a ? a : b;

        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();

        if (k == 0) return nullptr;

        for (int gap = 1; gap < k; gap *= 2) {
            for (int i = 0; i + gap < k; i += gap * 2) {
                lists[i] = mergeTwo(lists[i], lists[i + gap]);
            }
        }

        return lists[0];
    }
};
