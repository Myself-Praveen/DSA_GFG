class Solution {
  public:
    int maxArea(vector<int> &height) {
        // code here
        int n=height.size();
        int r=n-1;
        int l=0;
        int area=0;
        while(l<r){
            if(height[l]<height[r]){
                area=max(area,(r-l-1)*height[l]);
                l++;
            }
            else{
                area=max(area,(r-l-1)*height[r]);
                r--;
            }
            
        }
        return area;
    }
};