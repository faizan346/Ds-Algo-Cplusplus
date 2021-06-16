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

void width(TreeNode* node, int order, int &minl, int &maxr) {
    if(node == NULL) return;
    minl = min(minl, order);
    maxr = max(maxr, order);
    width(node->left, order-1, minl, maxr);
    width(node->right, order+1, minl, maxr);
}
// trees left child and right child makes 45degree angle 
int width(TreeNode *root)
{
    if(root == NULL) return 0;
    int minl = 0;
    int maxr = 0;
    width(root, 0, minl, maxr);
    return maxr - minl + 1; //  width
}

// input_section=================================================

TreeNode *createTree(vector<int> &arr, vector<int> &IDX)
{

    if (IDX[0] > arr.size() || arr[IDX[0]] == -1)
    {
        IDX[0]++;
        return nullptr;
    }

    TreeNode *node = new TreeNode(arr[IDX[0]++]);
    node->left = createTree(arr, IDX);
    node->right = createTree(arr, IDX);

    return node;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> IDX(1, 0);
    TreeNode *root = createTree(arr, IDX);

    cout << width(root) << endl;
}

int main()
{
    solve();
    return 0;
}