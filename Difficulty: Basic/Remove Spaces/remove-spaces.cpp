class Solution {
  public:
    string removeSpaces(string& s) {
        int n = s.size(), j = 0;
        for(int i=0; i<n; ++i) {
            if(s[i] != ' ') {
                s[j] = s[i];
                j++;
            }
        }
        s.resize(j);
        return s;
    }
};