/* Structure of binary tree node
class Node{
public:
    int data;
    Node* left, right;
    Node(int item)
    {
        data = item;
        left = nullptr;
        right = nullptr;
    }
}
*/
class Solution{
  public:
  void f(Node* root,int& a,int& b,int index){
      if(!root)return;
      a = min(a,index);
      b = max(b,index);
      f(root->left,a,b,index-1);
      f(root->right,a,b,index+1);
  }
  
  void solve(Node* root,int index,vector<int>&ans){
      if(!root)return;
      
      int temp = ans[index];
      temp+=root->data;
      ans[index] = temp;
      solve(root->left,index-1,ans);
      solve(root->right,index+1,ans);
  }
    vector <int> verticalSum(Node *root) {
        // add code here.
        int a = INT_MAX;
        int b = INT_MIN;
        f(root,a,b,0);
        int size = 1 + abs(a) + b;
        vector<int>ans(size,0);
        
        solve(root,abs(a),ans);
        return ans;
}
};