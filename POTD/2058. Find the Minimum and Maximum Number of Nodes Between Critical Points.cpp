class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1};
        ListNode *prev = head, *cur = head->next;
        int pos = 1, first = -1, last = -1, mn = INT_MAX;

        while (cur && cur->next) {
            if ((cur->val > prev->val && cur->val > cur->next->val) ||
                (cur->val < prev->val && cur->val < cur->next->val)) {
                
                if (first != -1)
                    mn = min(mn, pos - last);
                else
                    first = pos;

                last = pos;
            }

            prev = cur;
            cur = cur->next;
            pos++;
        }

        if (first != -1 && first != last)
            return {mn, last - first};

        return ans;
    }
};