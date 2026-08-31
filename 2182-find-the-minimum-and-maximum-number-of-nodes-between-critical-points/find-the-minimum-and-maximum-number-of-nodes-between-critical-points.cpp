class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int idx = 1;
        int first = -1, last = -1;
        int minDist = INT_MAX;

        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr->next) {
            ListNode* next = curr->next;

            bool critical =
                (curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val);

            if (critical) {
                if (first == -1) {
                    first = idx;
                } else {
                    minDist = min(minDist, idx - last);
                }
                last = idx;
            }

            prev = curr;
            curr = next;
            idx++;
        }

        if (first == last)
            return {-1, -1};

        return {minDist, last - first};
    }
};