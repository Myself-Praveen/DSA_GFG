class Solution {
  public:
    int binary(int n)
    {
        int count = 0;
        while(n > 0)
        {
            int div = n % 2;
            if(div == 1)
            {
                count++;
            }
            n = n / 2;
        }
        return count;
    }

    vector<int> sortBySetBitCount(vector<int>& arr) {
        int n = arr.size();   
        
        vector<pair<int,int>> ans;
        
        for(int i = 0; i < n; i++)
        {
            ans.push_back(make_pair(arr[i], binary(arr[i])));
        }
        
        stable_sort(ans.begin(), ans.end(), [](const auto &a, const auto &b)
        {
            return a.second > b.second;
        });
        
        for(int i = 0; i < n; i++)
        {
            arr[i] = ans[i].first;
        }
        
        return arr;   
    }
};