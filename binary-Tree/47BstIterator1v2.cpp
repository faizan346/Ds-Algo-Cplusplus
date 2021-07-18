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

class BSTIterator {
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        // push all leftside node into stack
        while(root != NULL) {
            st.push(root);
            root = root->left;
        }
    }
    
    int next() {
        // pop and return data while push all leftnodes of right node into stack
        int data = -1;
        TreeNode *node = st.top();
        st.pop();
        data = node->val;
        node = node->right; // right node
        while(node != NULL) { // push leftnodes of right node
            st.push(node);
            node = node->left;
        }
        return data;
    }
    
    bool hasNext() {
        if(st.empty()) return false;
        return true;
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