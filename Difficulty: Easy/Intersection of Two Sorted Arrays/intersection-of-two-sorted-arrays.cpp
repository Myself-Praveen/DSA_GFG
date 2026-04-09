class Solution {
  public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        // code here
        int n=a.size();
        int m=b.size();
        
        int i=0,j=0;
        vector<int>ans;
        while(i<n&& j<m)
        {
            if(a[i]==b[j])
            {
                int temp=a[i];
                ans.push_back(temp);
                while(i<n && a[i]==temp)
                {
                    i++;
                }
                 while(j<m && b[j]==temp)
                {
                    j++;
                }
                continue;
            }
            
            if(a[i]<b[j])
            {
                i++;
            }
            else
            {
               j++; 
            }
        
        }
        return ans;
    }
};