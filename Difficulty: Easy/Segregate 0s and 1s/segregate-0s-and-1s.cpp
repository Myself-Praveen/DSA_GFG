class Solution {
public:
    void segregate0and1(vector<int>& a) {
        int l = 0, r = a.size() - 1;
        while (l < r) {
            while (l < r && !a[l]) l++;
            while (l < r && a[r]) r--;
            if (l < r) { a[l++] = 0; a[r--] = 1; }
        }
    }
};