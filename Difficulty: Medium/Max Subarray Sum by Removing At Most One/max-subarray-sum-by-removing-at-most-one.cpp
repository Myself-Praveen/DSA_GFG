class Solution {
  public:
  
    int dp[1000001][2][2];
    int solve(int i, bool started, bool skipUsed, vector<int>& arr) {
        
        if (i == arr.size()) {
            if (started) {
                return 0;
            }
            return INT_MIN;
        }
        
        if (dp[i][started][skipUsed] != -1) {
            return dp[i][started][skipUsed];
        }
        int ans = arr[i];
        
        if (!started) {
            
            ans = max(ans, arr[i] + solve(i+1, true, skipUsed, arr));
            
            ans = max(ans, solve(i+1, started, skipUsed, arr));
        } else {
            
            ans = max(ans, arr[i] + solve(i+1, true, skipUsed, arr));
            
            if (!skipUsed) {
                ans = max(ans, solve(i+1, true, true, arr));
            }
            
        }
        
        return dp[i][started][skipUsed] = ans;
    }
    int maxSumSubarray(vector<int>& arr) {
        // code here
 
        memset(dp, -1, sizeof(dp));
        return solve(0, false, false, arr);
    }
};

