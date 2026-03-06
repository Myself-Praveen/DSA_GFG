class Solution {
public:
    string minWindow(string &s, string &p) {
        int n = s.size(), m = p.size();
        if(m > n) return "";

        unordered_map<char,int> mp;
        for(char &ch : p) mp[ch]++;

        int i = 0, j = 0;
        int count = m;
        int start = 0, minLen = INT_MAX;

        while(j < n){
            if(mp[s[j]] > 0) count--;
            mp[s[j]]--;

            while(count == 0){
                if(j - i + 1 < minLen){
                    minLen = j - i + 1;
                    start = i;
                }

                mp[s[i]]++;
                if(mp[s[i]] > 0) count++;
                i++;
            }

            j++;
        }

        if(minLen == INT_MAX) return "";
        return s.substr(start, minLen);
    }
};