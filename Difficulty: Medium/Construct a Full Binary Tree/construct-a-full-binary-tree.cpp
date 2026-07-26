class Solution {
public:
    unordered_map<int, int> pos;
    int preIdx = 0;

    Node* build(vector<int>& pre, vector<int>& preMirror, int l, int r) {
        if (preIdx >= pre.size() || l > r)
            return nullptr;

        Node* root = new Node(pre[preIdx++]);

        // Leaf node
        if (l == r || preIdx >= pre.size())
            return root;

        int idx = pos[pre[preIdx]];

        // Left subtree
        root->left = build(pre, preMirror, idx, r);

        // Right subtree
        root->right = build(pre, preMirror, l + 1, idx - 1);

        return root;
    }

    Node* constructBinaryTree(vector<int>& pre, vector<int>& preMirror) {
        int n = pre.size();

        for (int i = 0; i < n; i++)
            pos[preMirror[i]] = i;

        preIdx = 0;
        return build(pre, preMirror, 0, n - 1);
    }
};