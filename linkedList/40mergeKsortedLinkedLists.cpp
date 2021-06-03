#include<bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val = 0;
    ListNode *next = nullptr;

    ListNode(int val)
    {
        this->val = val;
    }
};

class CompareVal {
    public:
    bool operator()(ListNode* const& a, ListNode* const& b) {
        return a->val > b->val;
    }
};

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    priority_queue<ListNode*, vector<ListNode*>, CompareVal> pq;
    for(auto head : lists) {
        if(head) pq.push(head);
    }
    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;
    while(!pq.empty()) {
        ListNode* c = pq.top();
        pq.pop();
        temp->next = c;
        temp = temp->next;
        c = c->next;
        if(c != NULL) {
            pq.push(c);
        }
    }
    ListNode* l1 = dummy->next;
    delete dummy;
    return l1;
}

void printList(ListNode *node)
{
    ListNode *curr = node;
    while (curr != nullptr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

ListNode *createList(int n)
{
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;
    while (n-- > 0)
    {
        int val;
        cin >> val;
        prev->next = new ListNode(val);
        prev = prev->next;
    }
    return dummy->next;
}

int main()
{
    int n;
    cin >> n;
    vector<ListNode *> list(n, 0);
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        list[i] = createList(m);
    }

    ListNode *head = mergeKLists(list);
    printList(head);

    return 0;
}