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

vector<TreeNode*> nodeToRootPath(TreeNode* root, int data)
{   
    if(root == NULL) return vector<TreeNode*>();
    if(root->val == data) {
        return vector<TreeNode*>({root});
    }
    vector<TreeNode*> left = nodeToRootPath(root->left, data);
    vector<TreeNode*> right = nodeToRootPath(root->right, data);
    if(left.size() != 0) {
        left.push_back(root);
        return left;
    } else if(right.size() != 0) {
        right.push_back(root);
        return right;
    }
    return vector<TreeNode*>();;
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

  int data;
  cin >> data;
  vector<TreeNode*> ans = nodeToRootPath(root, data);
  if (ans.size() == 0)
    cout << endl;
  for (TreeNode* node : ans)
  {
    cout << node->val << " ";
  }
}

int main()
{
  solve();
  return 0;
}