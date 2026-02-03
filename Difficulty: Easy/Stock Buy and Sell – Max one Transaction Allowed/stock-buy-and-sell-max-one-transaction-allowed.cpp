class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
        int mp=0;
        int n=prices.size();
        int a=INT_MAX;
        for(int i=0;i<n;i++){
            a=min(a,prices[i]);
            mp=max(mp,prices[i]-a);
        }
        return mp;
    }
};
