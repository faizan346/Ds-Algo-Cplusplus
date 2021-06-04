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
int idx;
TreeNode *bstFromPostorder(vector<int> &postorder, int lr, int rr) {

    if(idx == -1 || postorder[idx] < lr || postorder[idx] > rr)
        return NULL;
    TreeNode* root = new TreeNode(postorder[idx--]);
    // preorder from right side == postorder from left side
    root->right = bstFromPostorder(postorder, root->val, rr);
    root->left = bstFromPostorder(postorder, lr, root->val);
    return root;
}

TreeNode *bstFromPostorder(vector<int> &postorder)
{
    int n = postorder.size();
    int lr = INT_MIN;
    int rr = INT_MAX;
    idx = n-1;
    return bstFromPostorder(postorder, lr, rr);
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

    TreeNode *root = bstFromPostorder(pre);
    display(root);
}

int main()
{
    solve();
    return 0;
}