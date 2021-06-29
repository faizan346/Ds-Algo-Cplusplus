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

vector<int> TopView(TreeNode *root)
{
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    int minl = 0;
    int maxr = 0;
    unordered_map<int, int> umap;
    while(!q.empty()) {
        int n = q.size();
        while(n-- > 0) {
            pair<TreeNode*, int> p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int order = p.second;
            minl = min(minl, order);
            maxr = max(maxr, order);
            if(umap.count(order) == 0) umap[order] = node->val;
            if(node->left) q.push({node->left, order-1});
            if(node->right) q.push({node->right, order+1});
        }
    }
    vector<int> res;
    for(int i = minl; i<= maxr; i++) {
        res.push_back(umap[i]);
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

    vector<int> ans = TopView(root);

    for (int i : ans)
    {
        cout << i << " ";
    }
}

int main()
{
    solve();
    return 0;
}