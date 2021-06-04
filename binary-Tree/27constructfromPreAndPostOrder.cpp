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
unordered_map<int, int> umapr;

TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post,
    int ps, int pe, int pos, int poe) {

    if(ps > pe) return NULL; // or pos > poe
    TreeNode* root = new TreeNode(pre[ps]);
    if(ps == pe) return root;
    int idx = umapr[post[poe-1]];
    int slst = idx - (ps+1); // size left sub treee
    root->left = constructFromPrePost(pre, post, ps+1, idx-1, pos, pos+slst-1);
    root->right = constructFromPrePost(pre, post, idx, pe, pos+slst, poe-1);
    return root;
}

TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post) {
    int n = pre.size();
    if(n == 0) return NULL;
    for(int i = 0; i < n; i++) umapr[pre[i]] = i;
    return constructFromPrePost(pre, post, 0, n-1, 0, n-1);
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

    vector<int> pre(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }

    TreeNode *root = constructFromPrePost(pre, post);
    display(root);
}

int main()
{
    solve();
    return 0;
}