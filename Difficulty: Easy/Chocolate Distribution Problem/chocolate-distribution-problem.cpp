class Solution{
    public:
 int findMinDiff(vector<int>& a, int m) {
        // code here

        int mini=INT_MAX;
        sort(a.begin(), a.end());


        int i=0, j=m-1;


        while(j<a.size()){
            mini=min(mini, a[j]-a[i]);
            i++, j++;
        }
        return mini;
    }  
};