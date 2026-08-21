class Solution {
public:
    long long findKthSmallest(vector<int>& c, long long k) {
        auto f = [&](long long x) {
            long long s = 0;
            for (int m = 1; m < (1 << c.size()); m++) {
                long long l = 1; int b = 0;
                for (int i = 0; i < c.size(); i++)
                    if (m >> i & 1)
                        b++, l = l / gcd(l, (long long)c[i]) * c[i];
                if (l <= x) s += (b & 1 ? 1 : -1) * (x / l);
            }
            return s;
        };

        long long l = 1, r = 1LL * *min_element(c.begin(), c.end()) * k;
        while (l < r) {
            long long m = (l + r) / 2;
            if (f(m) >= k) r = m;
            else l = m + 1;
        }
        return l;
    }
};