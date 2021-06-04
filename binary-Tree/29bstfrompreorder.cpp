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

TreeNode* bstFromPreorder1(vector<int>& preorder, int start, int end) {
    if(start > end) return NULL;
    int idx = start+1;
    while(idx <= end && preorder[start] >= preorder[idx]) idx++;

    TreeNode* root = new TreeNode(preorder[start]);
    root->left = bstFromPreorder1(preorder, start + 1, idx-1);
    root->right = bstFromPreorder1(preorder, idx, end);
    return root;
}

TreeNode *bstFromPreorder1(vector<int> &preorder)
{
    int n = preorder.size();
    if(n == 0) return NULL;
    return bstFromPreorder1(preorder, 0, n-1);
}

int idx = 0;
TreeNode* bstFromPreorder(vector<int>& preorder, int lr, int rr) {
    
    if(idx >= preorder.size() || preorder[idx] < lr || preorder[idx] > rr)
        return NULL;
    TreeNode* root = new TreeNode(preorder[idx++]);
    root->left = bstFromPreorder(preorder, lr, root->val);
    root->right = bstFromPreorder(preorder, root->val, rr);
    return root;
}

TreeNode *bstFromPreorder(vector<int> &preorder)
{
    int n = preorder.size();
    int lr = INT_MIN;
    int rr = INT_MAX;
    return bstFromPreorder(preorder, lr, rr);
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

    TreeNode *root = bstFromPreorder(pre);
    display(root);
}

int main()
{
    solve();
    return 0;
}