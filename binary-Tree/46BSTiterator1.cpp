#include <iostream>
#include <vector>
#include <stack>
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

class BSTIterator
{
    stack<pair<TreeNode*, int>> st;
public:
  BSTIterator(TreeNode* root)
  {
      st.push({root, 1});
      // state = 1 => print and push left child 
      // state = 2 => push right child
      // state = 3 => pop
  }

  int next()
  {
      int data = -1;
      while(!st.empty()) {
          pair<TreeNode*, int> &p = st.top();
          TreeNode* &node = p.first;
          if(p.second == 1) {
                if(node->left) st.push({node->left, 1});
                p.second = 2;
                
          } else if(p.second == 2) {
                if(node->right) st.push({node->right, 1});
                p.second = 3;
                data = node->val;
                break;
          } else {
                st.pop();
          }
      }
      return data;
  }

  bool hasNext()
  {
      while(!st.empty()) {
          pair<TreeNode*, int> &p = st.top();
          if(p.second == 3) st.pop();
          else return true;
      }
      return false;
  }
};

// input_Section_====================================================================

void display(TreeNode* node)
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

TreeNode* buildTree(vector<int>& inOrder, int si, int ei)
{
  if (si > ei)
    return nullptr;

  int mid = (si + ei) / 2;
  TreeNode* node = new TreeNode(inOrder[mid]);

  node->left = buildTree(inOrder, si, mid - 1);
  node->right = buildTree(inOrder, mid + 1, ei);

  return node;
}

TreeNode* constructFromInOrder(vector<int>& in)
{
  int n = in.size();
  return buildTree(in, 0, n - 1);
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

  TreeNode* root = constructFromInOrder(in);

  BSTIterator itr(root);
  while (itr.hasNext())
  {
    cout << (itr.next()) << endl;
  }
}

int main()
{
  solve();
  return 0;
}