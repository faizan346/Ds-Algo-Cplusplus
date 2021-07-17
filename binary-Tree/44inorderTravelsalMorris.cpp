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

vector<int> morrisInTraversal(TreeNode* root) {
    vector<int> inorder;
    if(root == NULL) return inorder;
    TreeNode *curr = root;
    while(curr != NULL) {
        TreeNode *leftNode = curr->left;
        if(leftNode == NULL) { // no left go right
            inorder.push_back(curr->val);
            curr = curr->right;
        } else {
            // go rightmost of leftnode to make thread OR break if thread is present
            while(leftNode->right != NULL && leftNode->right != curr) { 
                leftNode = leftNode->right;
            }
            if(leftNode->right == curr) { // thread exist go right
                leftNode->right = NULL; // break thread;
                inorder.push_back(curr->val);
                curr = curr->right;
            } else { // no thread leftNode->right == NULL
                leftNode->right = curr; // make thread
                curr = curr->left;
            }
        }
    }
    return inorder;
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

  vector<int> ans = morrisInTraversal(root);

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