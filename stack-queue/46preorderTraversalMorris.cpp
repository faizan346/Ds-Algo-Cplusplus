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

vector<int> morrisPreTraversal(TreeNode* root) {
    vector<int> pre;
    if(root == NULL) return pre;
    TreeNode *curr = root;
    while(curr != NULL) {
        TreeNode *leftNode = curr->left;
        if(leftNode == NULL) {
            pre.push_back(curr->val);
            curr = curr->right;
        } else {
            while(leftNode->right != NULL && leftNode->right != curr) {
                leftNode = leftNode->right;
            }
            if(leftNode->right == curr) {
                leftNode->right = NULL; // break thread;
                curr = curr->right;
            } else if(leftNode->right == NULL) {
                leftNode->right = curr; // make thread
                pre.push_back(curr->val);
                curr = curr->left;
            }
        }
    }
    return pre;
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

  vector<int> ans = morrisPreTraversal(root);

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