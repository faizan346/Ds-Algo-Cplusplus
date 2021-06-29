#include <iostream>
#include <vector>
#include <queue>
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

void sizeLeftView(TreeNode* node, int order, int& minl, int& s) {
    if(node == NULL) return;
    if(order <= minl) {
        s++;
        minl = order;
    }
    sizeLeftView(node->left, order-1, minl, s);
    sizeLeftView(node->right, order+1, minl, s);
}

vector<vector<int>> diagonalOrder2(TreeNode *root)
{   
    if(root == NULL) return vector<vector<int>>();
    int size = 0;
    int minl = 0;
    sizeLeftView(root, 0, minl, size);
    vector<vector<int>> res(size, vector<int>());
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    int level = -1;
    while(!q.empty()) {
        int n = q.size();
        level++;
        while(n-- > 0) {
            pair<TreeNode*, int> p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int order = p.second;
            int ind = abs(order - level) / 2;
            res[ind].push_back(node->val);
            if(node->left) q.push({node->left, order-1});
            if(node->right) q.push({node->right, order+1});
        }
    }
    return res;
}

vector<vector<int>> diagonalOrder(TreeNode *root)
{   
    vector<vector<int>> res;
    if(root == NULL) return res;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        int n = q.size();
        vector<int> r;
        while(n-- > 0) { // traverse all component of curr diagonal
            TreeNode *node = q.front();
            q.pop();
            while(node) { 
                // store curr diagonal values.
                r.push_back(node->val);
                // push node component of next diagonal
                if(node->left) q.push(node->left);
                node = node->right;
            }
        }
        res.push_back(r);
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

    vector<vector<int>> ans = diagonalOrder(root);
    int idx = 0;
    for (vector<int> &i : ans)
    {
        cout << idx++ << " -> ";
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{
    solve();
    return 0;
}