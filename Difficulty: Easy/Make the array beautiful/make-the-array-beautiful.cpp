class Solution {
public:
    vector<int> makeBeautiful(vector<int> arr) {
        vector<int> v;

        for (int x : arr) {
            if (!v.empty() && ((v.back() >= 0 && x < 0) || (v.back() < 0 && x >= 0))) {
                v.pop_back();  
            } else {
                v.push_back(x);
            }
        }

        return v;
    }
};