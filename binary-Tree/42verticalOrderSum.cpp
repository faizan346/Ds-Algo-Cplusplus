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

void diagonalOrderSum(TreeNode* root, int digInd, vector<int> &res) {
    if(root == NULL) return;
    if(res.size() == digInd) { //size should be greater than ind so we have to push currData
        res.push_back(root->val);
    } else {
        res[digInd] += root->val;
    }
    diagonalOrderSum(root->left, digInd+1, res); // digInd increase only when going left
    diagonalOrderSum(root->right, digInd, res);
}

vector<int> diagonalOrderSum(TreeNode *root)
{
    vector<int> res;
    diagonalOrderSum(root, 0, res);
    return res;
} 

vector<int> diagonalOrderSum2(TreeNode *root)
{
    vector<int> res;
    if(root == NULL) return res;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        int n = q.size();
        int sum = 0;
        while(n-- > 0) {
            TreeNode* node = q.front();
            q.pop();
            while(node) {
               sum += node->val;
               if(node->left) q.push(node->left);
               node = node->right;
            }
        }
        res.push_back(sum);
    }
    return res;
    
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

    vector<int> ans = diagonalOrderSum(root);
    for (int j : ans)
    {
        cout << j << " ";
    }
}

int main()
{
    solve();
    return 0;
}