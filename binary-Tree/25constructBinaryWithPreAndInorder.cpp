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
TreeNode *buildTree_(vector<int> &preorder, vector<int> &inorder, 
    int ps, int pe, int is, int ie) {

    if(is > ie || ps > pe) return NULL; // if is > ie then also, ps > pe

    //int idx = is;
    //while(preorder[ps] != inorder[idx]) idx++;
    int idx = umap[preorder[ps]];
    int clst = idx - is; //countLeftSubTree

    TreeNode* root = new TreeNode(preorder[ps]);
    root->left = buildTree_(preorder, inorder, ps+1, ps+clst, is, idx-1);
    root->right = buildTree_(preorder, inorder, ps+clst+1, pe, idx+1, ie);
    return root;
   
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {

    if(preorder.size() == 0) return NULL;
    int ps = 0, pe = preorder.size()-1;
    int is = 0, ie = inorder.size()-1;
    for(int i = 0; i < inorder.size(); i++) umap[inorder[i]] = i;
    TreeNode* root = buildTree_(preorder, inorder, ps, pe, is, ie);
    return root;
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
    vector<int> pre(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }

    vector<int> in(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }

    TreeNode *root = buildTree(pre, in);
    display(root);
}

int main()
{
    solve();
    return 0;
}