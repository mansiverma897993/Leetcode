
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        int m = logs.size();
        int q = queries.size();t

        vector<pair<int, int>> sortedQueries;

        for (int i = 0; i < q; i++) {
            sortedQueries.push_back({queries[i], i});
        }

        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> freq(n + 1, 0);
        vector<int> ans(q);

        int left = 0, right = 0;
        int active = 0;

        for (auto [time, idx] : sortedQueries) {

            while (right < m && logs[right][1] <= time) {
                int server = logs[right][0];

                if (freq[server] == 0)
                    active++;

                freq[server]++;
                right++;
            }

            while (left < right && logs[left][1] < time - x) {
                int server = logs[left][0];

                freq[server]--;

                if (freq[server] == 0)
                    active--;

                left++;
            }

            ans[idx] = n - active;
        }

        return ans;
    }
};
