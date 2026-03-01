class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
     int non=0;
     for(int i=0 ; i<arr.size();i++){
         if(arr[i]!=0)arr[non++]=arr[i];
     }
     while(non<arr.size()){
         arr[non++]=0;
         
     }
     }
};