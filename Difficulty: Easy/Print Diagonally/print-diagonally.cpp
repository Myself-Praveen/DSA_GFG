class Solution {
  public:
    vector<int> diagView(vector<vector<int>> mat) {
        // code here
        vector<int> ans;
        int cnt = 0;
        int r = 0;
         int c = 0;
        for(int i = 0 ; i < mat.size();i++){
            for(int j = 0 ; j < mat[0].size();j++){
                ans.push_back(mat[r][c]);
                    r++;
                    c--;
                if(c < 0 || r>= mat.size()){
                    cnt++;
                    c = min(cnt,int(mat.size()-1));
                    r = cnt - c;
                }
            }
        }
        return ans;
    }
};