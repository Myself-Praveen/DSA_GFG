class Solution {
  public:
  int longest;
  void traversal(Node* root,int parent,int length)
  {
      if(!root)
        return;
      length = (parent+1 == root->data)?(length+1):1;
      longest = max(longest,length);
      traversal(root->left,root->data,length);
      traversal(root->right,root->data,length);
  }
    int longestConsecutive(Node* root) {
        // code here
        longest = 0;
        traversal(root,-1,0);
        return (longest == 1)?-1:longest;
        
    }
};