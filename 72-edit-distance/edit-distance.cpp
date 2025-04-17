class Solution {
public:
    int solve(int ind1, int ind2, string word1, string word2, vector<vector<int>> &dp){
        if(ind2==0){
            //those many to remove from word1
            return dp[ind1][ind2]=ind1;
        }

        if(ind1==0){
            //those many to add to word1
            return dp[ind1][ind2]=ind2;
        }

        if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2];
        }

        if(word1[ind1-1]==word2[ind2-1]){
            return dp[ind1][ind2]=solve(ind1-1, ind2-1, word1,word2, dp);
        }
        
        //insert, delete, replace
        return dp[ind1][ind2]=1+min(solve(ind1, ind2-1, word1,word2, dp),min(solve(ind1-1, ind2, word1,word2, dp),solve(ind1-1, ind2-1, word1,word2, dp)));
    }


    int minDistance(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();
        
        //index shifting
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));

        return solve(n,m,word1,word2,dp);
    }
};