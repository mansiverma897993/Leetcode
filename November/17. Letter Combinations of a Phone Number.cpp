
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> mp = {
            "", "", "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> ans;
        string path;

        function<void(int)> dfs = [&](int idx) {
            if (idx == digits.size()) {
                ans.push_back(path);
                return;
            }

            string letters = mp[digits[idx] - '0'];

            for (char ch : letters) {
                path.push_back(ch);
                dfs(idx + 1);
                path.pop_back();
            }
        };

        dfs(0);

        return ans;
    }
};
