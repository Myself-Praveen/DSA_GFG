class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // code here
        int mx = 0;
        for(int pos : left){
            mx = max(mx, pos);
        }
        for(int pos : right){
            mx = max(mx, n - pos);
        }
        
        return mx;
    }
};