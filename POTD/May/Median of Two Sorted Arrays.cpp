class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if (a.size() > b.size()) return findMedianSortedArrays(b, a);
        
        int n = a.size(), m = b.size();
        int l = 0, r = n;
        
        while (l <= r) {
            int cut1 = (l + r) / 2;
            int cut2 = (n + m + 1) / 2 - cut1;
            
            int l1 = (cut1 == 0) ? INT_MIN : a[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : b[cut2 - 1];
            int r1 = (cut1 == n) ? INT_MAX : a[cut1];
            int r2 = (cut2 == m) ? INT_MAX : b[cut2];
            
            if (l1 <= r2 && l2 <= r1) {
                if ((n + m) % 2 == 0)
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                return max(l1, l2);
            }
            else if (l1 > r2) r = cut1 - 1;
            else l = cut1 + 1;
        }
        
        return 0.0;
    }
};