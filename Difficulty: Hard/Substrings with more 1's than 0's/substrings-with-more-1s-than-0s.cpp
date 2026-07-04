class Solution {
  public:
    void update(vector<int>&bit, int num){
        for(int i=num;i<bit.size();i+=(i & (-i))){
            bit[i]++;
        }
    }
    int sum(vector<int>&bit, int num){
        int temp=0;
        for(int i=num;i>=1;i-=(i & (-i))){
            temp+=bit[i];
        }
        return temp;
    }
    int countSubstring(string& s) {
        // Code Here
        vector<int>v;
        for(char c:s){
            if(c=='1'){
                v.push_back(1);
            }
            else{
                v.push_back(-1);
            }
        }
        v.insert(v.begin(),0);
        v[0]+=v.size()+1;
        for(int i=1;i<v.size();i++){
            v[i]+=v[i-1];
        }
        vector<int>bit(2*v.size()+2);
        int ans=0;
        for(int i:v){
            ans+=sum(bit,i-1);
            //cout<<ans<<" ";
            update(bit,i);
        }
        //cout<<"\n";
        return ans;
    }
};
