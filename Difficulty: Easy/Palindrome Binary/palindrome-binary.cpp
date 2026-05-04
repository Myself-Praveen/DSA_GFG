class Solution {
  public:
    bool isBinaryPalindrome(int n) {
        // code here
        if(n==0) return true;
        int og=n;
        int rev=0;
        while(n>0){
            rev<<=1;
            rev|=(n&1);
            n>>=1;
        }
        return rev==og;
    }
};