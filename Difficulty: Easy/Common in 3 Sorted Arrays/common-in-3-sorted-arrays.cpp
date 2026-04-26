class Solution {
  public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        int x = a.size() , y = b.size() , z = c.size();
        int i = 0 , j = 0 , k = 0;
        vector<int>ans;
        while(i < x && j < y && k < z){
            if(a[i] == b[j] && b[j] == c[k]){
                if(ans.empty() || ans.back() != a[i])
                    ans.push_back(a[i]);
                i++;
                j++;
                k++;
            }else{
                int mx = max({a[i] , b[j] , c[k]});
                if(a[i] < mx)
                    i++;
                if(b[j] < mx)
                    j++;
                if(c[k] < mx)
                    k++;
            }
        }
        return ans;
    }
};