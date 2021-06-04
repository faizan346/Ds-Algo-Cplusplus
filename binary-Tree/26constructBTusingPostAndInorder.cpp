#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    TreeNode(int val)
    {
        this->val = val;
    }
};

unordered_map<int, int> umap;

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder,
    int is, int ie, int ps, int pe) {

    if(is > ie) return NULL; // or ps > pe
    int idx = umap[postorder[pe]];
    int slst = idx - is; // sizeleftSubTree;
    TreeNode* root = new TreeNode(postorder[pe]);
    root->left = buildTree(inorder, postorder, is, idx-1, ps, ps+slst-1);
    root->right = buildTree(inorder, postorder, idx+1, ie, ps+slst, pe-1);
    return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    int n = inorder.size();
    if(n == 0) return NULL;
    for(int i = 0; i < n; i++) umap[inorder[i]] = i;
    return buildTree(inorder, postorder, 0, n-1, 0, n-1);
}

// input_Section_====================================================================

void display(TreeNode *node)
{
    if (node == nullptr)
        return;

    string str = "";
    str += ((node->left != nullptr ? to_string(node->left->val) : "."));
    str += (" -> " + to_string(node->val) + " <- ");
    str += ((node->right != nullptr ? to_string(node->right->val) : "."));

    cout << str << endl;

    display(node->left);
    display(node->right);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> post(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> post[i];
    }

    vector<int> in(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }

    TreeNode *root = buildTree(in, post);
    display(root);
}

int main()
{
    solve();
    return 0;
}