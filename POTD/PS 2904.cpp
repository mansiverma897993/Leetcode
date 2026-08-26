class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<int> p;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '1') p.push_back(i);

        if (p.size() < k) return "";

        string ans = "";
        int len = INT_MAX;

        for (int i = 0; i + k <= p.size(); i++) {
            int l = p[i], r = p[i + k - 1];
            string cur = s.substr(l, r - l + 1);

            if (cur.size() < len || (cur.size() == len && cur < ans))
                ans = cur, len = cur.size();
        }
        return ans;
    }
};