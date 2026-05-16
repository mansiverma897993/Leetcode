class Solution {
public:
    // int count(int amount, vector<int> &coins, int i){
    //     if(amount ==0){
    //         return 1;
    //     }
    //     if(amount<0 || coins.size() <= i){
    //         return 0;
    //     }
    //     int include = count(amount - coins[i], coins, i);
    //     int exclude =count(amount, coins, i+1);
    //     return include + exclude;
    // }
    int change(int amount, vector<int>& coins) {
        //return count(amount, coins, 0);
        vector<unsigned int> dp(amount+1, 0);
        dp[0]=1;
        for(auto coin: coins){
            if(coin > amount){
                continue;
            }
            for(auto c = coin; c<=amount;c++){
                dp[c] += dp[c-coin];
            }
        }
        return (int)dp[amount];
    }
};