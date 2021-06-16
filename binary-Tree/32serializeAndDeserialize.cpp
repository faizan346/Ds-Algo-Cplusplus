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

void serialize(TreeNode *root, string& s) {
    if(root == NULL) {
        s += "null,";
        return;
    }
    s += to_string(root->val) + ",";
    serialize(root->left, s);
    serialize(root->right, s);
}

// Encodes a tree to a single string.
string serialize(TreeNode *root)
{
    string str = "";
    serialize(root, str);
    return str;
}

vector<int> separate(string& s, char del) {
    vector<int> res;
    int i = 0;
    int j = s.find(del);
    while(j != -1) {
        string t = s.substr(i, j-i);
        if(t == "null") {
            res.push_back(-1);
        } else {
            res.push_back(stoi(t));
        }
        i = j+1;
        j = s.find(del, i);
    }
    return res;
}

TreeNode *deserialize(vector<int>& v) {
    stack<pair<TreeNode*,int>> st;
    int idx = 0;
    TreeNode *root = new TreeNode(v[idx++]);
    st.push({root,1});
    while(!st.empty()) {
        pair<TreeNode*, int> &p = st.top();
        TreeNode* &node = p.first;
        int &state = p.second;
        if(state == 1) {
            node->left = (v[idx] == -1) ? NULL : new TreeNode(v[idx]);
            if(node->left) st.push({node->left, 1});
            idx++; state++;
        } else if(state == 2) {
            node->right = (v[idx] == -1) ? NULL : new TreeNode(v[idx]);
            if(node->right) st.push({node->right, 1});
            idx++; state++;
        } else {
            st.pop();
        }

    }
    return root;
}

TreeNode *deserialize(vector<int>&v, int &idx) {
    if(v[idx] == -1 || idx >= v.size()) {
        idx++;
        return NULL;
    }
    TreeNode *node = new TreeNode(v[idx++]);
    node->left = deserialize(v, idx);
    node->right = deserialize(v, idx);
    return node;
}

// Decodes your encoded data to tree.
TreeNode *deserialize(string s)
{
    vector<int> v = separate(s, ',');
    TreeNode *root1 = deserialize(v);
    int idx = 0;
    TreeNode *root = deserialize(v, idx);
    return root;
}

// input_Section_====================================================================

void display(TreeNode *node)
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

    string s = serialize(root);
    display(deserialize(s));
}

int main()
{
    solve();
    return 0;
}