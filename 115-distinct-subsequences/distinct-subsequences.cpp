class Solution {
public:
    int solve(int ind1, int ind2, vector<vector<int>> &dp, string s, string t){
        //base case: ind2<0
        if(ind2==0){
            return dp[ind1][ind2] =1;
        }

        if(ind1==0){
            return dp[ind1][ind2] =0;
        }

        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

        if(s[ind1-1]==t[ind2-1]){
            //take this occurence or not take (take another occurence)
            return dp[ind1][ind2] = solve(ind1-1, ind2-1, dp,s,t) + solve(ind1-1, ind2, dp,s,t);
        }

        return dp[ind1][ind2] = solve(ind1-1, ind2, dp,s,t);
    }


    int numDistinct(string s, string t) {

        int n = s.size();
        int m = t.size();

        // vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        
        // // we do index shifting
        // return solve(n,m,dp,s,t);

        vector<vector<double>> dp(n+1, vector<double>(m+1,0));

        //base case
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }

        for(int j=1;j<=m;j++){
            dp[0][j]=0;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = dp[i-1][j]+dp[i-1][j-1];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return (int)dp[n][m];
    }
};