#include<bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val = 0;
    ListNode *next = nullptr;
    ListNode *random = nullptr;

    ListNode(int val)
    {
        this->val = val;
    }
};

ListNode *copyRandomList(ListNode *head)
{
    if(head == NULL) return NULL;
    ListNode* headCopy = NULL;
    ListNode* temp = head;
    ListNode* tempc = headCopy;
    unordered_map<ListNode*, ListNode*> umap; // original, copy
    while(temp != NULL) {
        ListNode* node = new ListNode(temp->val);
        umap[temp] = node;
        if(tempc == NULL) {
            headCopy = tempc = node;
        } else {
            tempc->next = node;
            tempc = node;
        }
        temp = temp->next;
    }
    temp = head;
    tempc = headCopy;
    while(temp != NULL) {
        tempc->random = umap[temp->random];
        temp = temp->next;
        tempc = tempc->next;
    }
    return headCopy;
}

int main()
{
    int n;
    cin >> n;

    vector<ListNode *> arr(n);
    ListNode *prev = nullptr;
    for (int i = 0; i < n; i++)
    {
        arr[i] = new ListNode(0);
        if (prev != nullptr)
            prev->next = arr[i];
        prev = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        int val, idx;
        cin >> val >> idx;

        arr[i]->val = val;
        if (idx != -1)
            arr[i]->random = arr[idx];
    }

    ListNode *head = copyRandomList(arr[0]);
    while (head != nullptr)
    {
        cout << "(" + to_string(head->val) + ", " + (head->random != nullptr ? to_string(head->random->val) : to_string(-1)) + ") ";
        head = head->next;
    }
    cout << endl;
    return 0;
}