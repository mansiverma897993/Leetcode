class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size(), mx = *max_element(nums.begin(), nums.end());
        vector<int> spf(mx + 1);
        for (int i = 0; i <= mx; i++) spf[i] = i;
        for (int i = 2; i * i <= mx; i++)
            if (spf[i] == i)
                for (int j = i * i; j <= mx; j += i)
                    if (spf[j] == j) spf[j] = i;

        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            unordered_set<int> s;
            while (x > 1) {
                int p = spf[x];
                if (!s.count(p)) mp[p].push_back(i), s.insert(p);
                while (x % p == 0) x /= p;
            }
        }

        queue<int> q;
        vector<int> d(n, -1);
        unordered_set<int> used;
        q.push(0), d[0] = 0;

        while (!q.empty()) {
            int i = q.front(); q.pop();
            if (i == n - 1) return d[i];

            for (int ni : {i - 1, i + 1}) {
                if (ni >= 0 && ni < n && d[ni] == -1)
                    d[ni] = d[i] + 1, q.push(ni);
            }

            if (nums[i] > 1 && spf[nums[i]] == nums[i] && !used.count(nums[i])) {
                used.insert(nums[i]);
                for (int j : mp[nums[i]])
                    if (d[j] == -1)
                        d[j] = d[i] + 1, q.push(j);
            }
        }
        return -1;
    }
};