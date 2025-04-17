class Solution {
public:
    bool solve(int ind1, int ind2, string p, string s, vector<vector<int>> &dp){
        if(ind2==0){
            int k=ind1;
            while(k--){
                if(p[k]!='*') return dp[ind1][ind2]=false;
            }

            return dp[ind1][ind2]=true;
        }

        if(ind1==0){
            return dp[ind1][ind2]=false;
        }

        if(p[ind1-1]==s[ind2-1]||p[ind1-1]=='?'){
            return dp[ind1][ind2]=solve(ind1-1,ind2-1,p,s,dp);
        }

        if(p[ind1-1]=='*'){
            //take it as empty string, or 1 char or 2 char...
            return dp[ind1][ind2]=solve(ind1-1,ind2,p,s,dp)||solve(ind1,ind2-1,p,s,dp);
        }

        //mismatch
        return dp[ind1][ind2]=false;
    }


    bool isMatch(string s, string p) {
        
        int n = p.size();
        int m = s.size();

        // vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        
        // return solve(n,m,p,s,dp);

        // vector<vector<int>> dp(n+1, vector<int>(m+1,0));

        // //base case
        // for(int i=0;i<=n;i++){
        //     int k=i;
        //     dp[i][0]=true;
        //     while(k--){
        //         if(p[k]!='*'){ 
        //             dp[i][0]=false;
        //             break;
        //         }
        //     }
        // }

        // for(int j=1;j<=m;j++){
        //     dp[0][j]=false;
        // }

        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         if(p[i-1]==s[j-1]||p[i-1]=='?'){
        //             dp[i][j]=dp[i-1][j-1];
        //         }else if(p[i-1]=='*'){
        //             dp[i][j]=dp[i-1][j]||dp[i][j-1];
        //         }else{
        //             dp[i][j]=false;
        //         }
        //     }
        // }

        // return dp[n][m];

        vector<int> prev(m+1,0), curr(m+1,0);

        //base case
        // for(int i=0;i<=n;i++){
        //     int k=i;
        //     dp[i][0]=true;
        //     while(k--){
        //         if(p[k]!='*'){ 
        //             dp[i][0]=false;
        //             break;
        //         }
        //     }
        // }

        prev[0]=true;

        for(int j=1;j<=m;j++){
            prev[j]=false;
        }

        for(int i=1;i<=n;i++){
            curr[0] = true;
            for(int k = 0; k < i; k++) {
                if(p[k] != '*') {
                    curr[0] = false;
                    break;
                }
            }

            for(int j=1;j<=m;j++){
                if(p[i-1]==s[j-1]||p[i-1]=='?'){
                    curr[j]=prev[j-1];
                }else if(p[i-1]=='*'){
                    curr[j]=prev[j]||curr[j-1];
                }else{
                    curr[j]=false;
                }
            }

            prev=curr;
        }

        return prev[m];
    }
};