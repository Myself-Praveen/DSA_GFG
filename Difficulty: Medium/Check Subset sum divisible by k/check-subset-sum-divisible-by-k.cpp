class Solution {
  public:
    bool divisibleByK(vector<int>& arr, int k) {
        vector<bool> dp(k, false);

        for (int num : arr) {

            vector<bool> next = dp;

            next[num % k] = true;

            for (int r = 0; r < k; r++) {
                if (dp[r]) {
                    int newRem = (r + num) % k;
                    next[newRem] = true;
                }
            }

            dp = next;

            if (dp[0])
                return true;
        }

        return false;
    }
};