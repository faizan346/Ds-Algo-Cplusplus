#include <iostream>
#include <vector>
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

TreeNode* constructFromInOrder(vector<int>& inorder, int start, int end) {
    if(start > end) return NULL;
    int mid = (start + end) / 2;
    TreeNode* root = new TreeNode(inorder[mid]);
    root->left = constructFromInOrder(inorder, start, mid-1);
    root->right = constructFromInOrder(inorder, mid+1, end);
    return root;
}

TreeNode *constructFromInOrder(vector<int> &in) {
    int n = in.size();
    if(n == 0) return NULL;
    return constructFromInOrder(in, 0, n-1);
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
    vector<int> in(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }

    TreeNode *root = constructFromInOrder(in);
    display(root);
}

int main()
{
    solve();
    return 0;
}