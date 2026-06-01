class Solution {
public:

int findMaxProduct(vector<int> &arr) {
    const int size = arr.size();
    
    // Size == 1
    if(size == 1) {
        return arr[0];
    }
    
    const int mod = 1e9 + 7;
    int neg = 0;
    int zero = 0;
    int negMin = mod;
    long long ans = 1;
    
    for(int &val: arr) {
        if(val == 0) {
            zero++;
            continue;
        }
        if(val < 0) {
            neg++;
            negMin = min(negMin, abs(val));
        }
        
        ans = (1LL * val * ans) % mod;
    }
    
    // Zero case or Size == 2 case
    if( (size == zero) || (size == 2 && neg == 1 && zero == 1) ) {
        return 0;
    }
    // Odd negative
    if((neg & 1) == 1) {
        ans = abs(ans / (1LL * negMin)) % mod; 
    }
    
    return ans;
}

};