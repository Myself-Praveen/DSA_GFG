class Solution {
  public:
    string largestSwap(string &s) {
        // code here
        int n = s.size();
        
        vector<int>v(10, 0);
        for(char ch : s){
            v[ch - '0']++;
        }
        
        int j = 9;
        
        for(int i = 0; i < n; i++){
            while(v[j] <= 0){
                j--;
            }
            if(s[i] != j + '0'){
                char ch = s[i];
                s[i] = j + '0';
                i++;
                for(int u = n - 1; u >= 0; u--){
                    if(s[u] == j + '0'){
                        s[u] = ch; return s;
                    }
                }
            }else{
                v[j]--;
            }
        }
        
        return s;
    }
};