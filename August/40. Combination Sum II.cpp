class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;

        function<void(int,int)> dfs = [&](int i, int sum) {
            if (sum == target) {
                ans.push_back(temp);
                return;
            }

            for (int j = i; j < candidates.size(); j++) {
                if (j > i && candidates[j] == candidates[j - 1]) continue;
                if (sum + candidates[j] > target) break;

                temp.push_back(candidates[j]);
                dfs(j + 1, sum + candidates[j]);
                temp.pop_back();
            }
        };

        dfs(0, 0);
        return ans;
    }
};