class Solution {
public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* pre = nullptr;
        Node* suc = nullptr;
        
        while (root) {
            if (root->data < key) {
                pre = root;
                root = root->right;
            } else if (root->data > key) {
                suc = root;
                root = root->left;
            } else {
                if (root->left) {
                    pre = root->left;
                    while (pre->right) pre = pre->right;
                }
                if (root->right) {
                    suc = root->right;
                    while (suc->left) suc = suc->left;
                }
                break;
            }
        }
        
        return {pre, suc};
    }
};