class Solution {
public:
    void subset(vector<int>&nums, vector<int>&ans, int i,vector<vector<int>>&powerset){
         if(i==nums.size()){
            powerset.push_back(ans);
            return;
        }
        ans.push_back(nums[i]);
        subset(nums,ans,i+1, powerset);

        ans.pop_back();
        subset(nums,ans,i+1,powerset);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>powerset;
        vector<int>ans;
        subset(nums, ans, 0,powerset);
        return powerset;
       
    }

    
};