#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class TreeNode
{
public:
  int val = 0;
  TreeNode* left = nullptr;
  TreeNode* right = nullptr;

  TreeNode(int val)
  {
    this->val = val;
  }
};

vector<vector<int>> rootToAllLeafPath(TreeNode* root)
{
    vector<vector<int>> res;
    if(root == NULL) return res;
    if(!root->left && !root->right) {
        vector<int> v({root->val});
        res.push_back(v);
        return res;
    }
    vector<vector<int>> left = rootToAllLeafPath(root->left);
    vector<vector<int>> right = rootToAllLeafPath(root->right);
    for(auto r : left) {
        vector<int> v;
        v.push_back(root->val);
        for(auto x : r) {
            v.push_back(x);
        }
        res.push_back(v);
    }
    for(auto r : right) {
        vector<int> v;
        v.push_back(root->val);
        for(auto x : r) {
            v.push_back(x);
        }
        res.push_back(v);
    }
    return res;
}

// input_section=================================================

TreeNode* createTree(vector<int>& arr, vector<int>& IDX)
{

  if (IDX[0] > arr.size() || arr[IDX[0]] == -1)
  {
    IDX[0]++;
    return nullptr;
  }

  TreeNode* node = new TreeNode(arr[IDX[0]++]);
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
  TreeNode* root = createTree(arr, IDX);

  vector<vector<int>> ans = rootToAllLeafPath(root);
  if (ans.size() == 0)  cout << endl;
    for(auto &y : ans) {
        for(auto x : y) cout << x << " ";
        cout << endl;
    }
}

int main()
{
  solve();
  return 0;
}