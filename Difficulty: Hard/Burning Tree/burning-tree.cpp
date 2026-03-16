class Solution {
    pair<int,pair<int,int>> solve(Node*root,int &tar){
        if(!root) return {0,{0,-1}};
        
        pair<int,pair<int,int>> l = solve(root->left,tar);
        pair<int,pair<int,int>> r = solve(root->right,tar);
        
        pair<int,pair<int,int>> ans;
        if(root->data == tar){
           
            ans.second.first = 1;
            ans.second.second = max(l.first,r.first);
            ans.first = -1;
        } else {
            if(l.second.second == -1 && r.second.second==-1){
                ans.first = max(l.first,r.first)+1;
                ans.second.first = 0;
                ans.second.second = -1;
            }
            else if(l.second.second != -1 && r.second.second ==-1){
                ans.first = -1;
                ans.second.first = l.second.first + 1;
                ans.second.second = max(l.second.first + r.first,l.second.second);
            }
            else{
                ans.first = -1;
                ans.second.first = r.second.first + 1;
                ans.second.second = max(r.second.first + l.first,r.second.second);
            }
        }
        return ans;
        
    }
  public:
    int minTime(Node* root, int target) {
        // code here
        return solve(root,target).second.second;
    }
};