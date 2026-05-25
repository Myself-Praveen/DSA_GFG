class Solution {
  public:
    bool checkElements(int start, int end, vector<int> &arr) {
        // code here
          int n = arr.size();
          
          int c= 0;
          for(int i:arr){
               if(i>=start && i<=end) c++;
          }
          return c==(end-start+1);
          
    }
};