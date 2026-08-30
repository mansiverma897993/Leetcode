class Solution {
public:
    int minimumDeletions(vector<int>& a) {
        int n=a.size(),mn=0,mx=0;
        for(int i=1;i<n;i++){
            if(a[i]<a[mn]) mn=i;
            if(a[i]>a[mx]) mx=i;
        }
        if(mn>mx) swap(mn,mx);
        return min({mx+1,n-mn,mn+1+n-mx});
    }
};