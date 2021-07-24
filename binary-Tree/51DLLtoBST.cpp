#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int val = 0;
    Node *left = nullptr;
    Node *right = nullptr;

    Node(int val)
    {
        this->val = val;
    }
};

Node* midNode(Node* head, Node* &prev) {
    Node *slow = head, *fast = head;
    while(fast->right && fast->right->right) {
        fast = fast->right->right;
        prev = slow;
        slow = slow->right;
    }
    return slow;
}

Node *SortedDLLToBST(Node* head)
{
    if(head == NULL) return head;
    Node *prev = NULL, *mid;
    mid = midNode(head, prev);
    if(prev) prev->right = NULL;
    mid->left = NULL;
    Node *next = mid->right;
    if(next) next->left = NULL;
    mid->right = NULL;
    Node* left = (mid == head) ? NULL : SortedDLLToBST(head);
    Node* right = SortedDLLToBST(next);
    mid->left = left;
    mid->right = right;
    return mid;
}

// input_Section_====================================================================

void display(Node *node)
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

Node* makeList(int n) {
        Node* dummy = new Node(-1);
        Node* prev = dummy;
        while (n-- > 0) {
            int val; cin >> val;
            Node* node = new Node(val);
            prev->right = node;
            node->left = prev;
            prev = prev->right;
        }

        Node *head = dummy->right;
        head->left = dummy->right = nullptr;

        return head;
    }

void solve()
{
    int n;
    cin >> n;
    Node* head = makeList(n);
    
    head = SortedDLLToBST(head);
    display(head);
}

int main()
{
    solve();
    return 0;
}