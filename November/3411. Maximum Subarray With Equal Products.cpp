class Solution {
public:
    int maxLength(vector<int>& nums) {
        constexpr int mask[11] = {
            0, 0, 1, 2, 1, 4, 3, 8, 1, 2, 5
        };

        int ans = 2, left = 0, used = 0;

        for (int right = 0; right < nums.size(); ++right) {
            int curr = mask[nums[right]];

            while (used & curr) {
                used ^= mask[nums[left++]];
            }

            used |= curr;
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};