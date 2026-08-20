class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        return max(rob1(nums, 0, nums.size() - 2),
                   rob1(nums, 1, nums.size() - 1));
    }

    int rob1(vector<int>& nums, int l, int r) {
        int prev = 0, curr = 0;

        for (int i = l; i <= r; i++) {
            int take = nums[i] + prev;
            int skip = curr;

            int next = max(take, skip);
            prev = curr;
            curr = next;
        }

        return curr;
    }
};