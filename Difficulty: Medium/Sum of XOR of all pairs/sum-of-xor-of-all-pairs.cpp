class Solution {
public:
    long long sumXOR(vector<int> &arr) {
        int n = arr.size();
        long long res = 0;

        for(int i = 0; i < 32; i++) {   
            long long c = 0;

            for(int num : arr) {
                if((num & (1 << i)) != 0) {
                    c++;
                }
            }

            long long cf = n - c;
            res += c * cf * (1LL << i);
        }

        return res;
    }
};