class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        int freq[128] = {};
        for (char c : t) freq[c]++;

        int left = 0, count = t.size();
        int start = 0, minLen = INT_MAX;

        for (int right = 0; right < s.size(); right++) {
            if (freq[s[right]]-- > 0)
                count--;

            while (count == 0) {
                int len = right - left + 1;

                if (len < minLen) {
                    minLen = len;
                    start = left;
                }

                if (++freq[s[left++]] > 0)
                    count++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};