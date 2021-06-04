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

    class levelPair
    {
    public:
        TreeNode *par = nullptr;
        int lb = -(int)1e8;
        int rb = (int)1e8;

        levelPair()
        {
        }

        levelPair(TreeNode *par, int lb, int rb)
        {
            this->par = par;
            this->lb = lb;
            this->rb = rb;
        }
    };

    TreeNode *constructBSTFromLevelOrder(vector<int> &arr)
    {
        int n = arr.size();
        if(n == 0) return NULL;
        queue<levelPair> q;
        TreeNode* root = new TreeNode(arr[0]);
        q.push(levelPair(root, INT_MIN, INT_MAX));
        int idx = 1;
        while(!q.empty()) {
            levelPair p = q.front();
            q.pop();
            // range check for the left child for curr idx
            if(idx >= n || arr[idx] < p.lb || arr[idx] >= p.par->val) {
                p.par->left = NULL;
            } else {
                p.par->left = new TreeNode(arr[idx++]);
                q.push(levelPair(p.par->left, p.lb, p.par->val));
            }
            // range check for the right child for curr idx
            if(idx >= n || arr[idx] < p.par->val || arr[idx] > p.rb) {
                p.par->right = NULL;
            } else {
                p.par->right = new TreeNode(arr[idx++]);
                q.push(levelPair(p.par->right, p.par->val, p.rb));
            }
        }
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

    void solve()
    {
        int n;
        cin >> n;
        vector<int> pre(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> pre[i];
        }

        TreeNode *root = constructBSTFromLevelOrder(pre);
        display(root);
    }

    int main()
    {
        solve();
        return 0;
    }