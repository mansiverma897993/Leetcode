class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size(), m = words.size(), k = words[0].size();
        vector<int> ans;
        if (m * k > n) return ans;

        unordered_map<string_view, int> need;
        for (auto& w : words) ++need[w];

        string_view sv(s);

        for (int i = 0; i < k; ++i) {
            unordered_map<string_view, int> cnt;
            int l = i, total = 0;

            for (int r = i; r + k <= n; r += k) {
                auto w = sv.substr(r, k);

                if (!need.count(w)) {
                    cnt.clear();
                    total = 0;
                    l = r + k;
                    continue;
                }

                ++cnt[w];
                ++total;

                while (cnt[w] > need[w]) {
                    --cnt[sv.substr(l, k)];
                    l += k;
                    --total;
                }

                if (total == m) ans.push_back(l);
            }
        }
        return ans;
    }
};