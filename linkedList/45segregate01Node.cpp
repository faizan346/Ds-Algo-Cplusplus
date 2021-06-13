#include <iostream>
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

ListNode *segregate01(ListNode *head)
{
    if(head == NULL || head->next == NULL) return head;
    
    ListNode* dummy0 = new ListNode(-1);
    ListNode* dummy1 = new ListNode(-1);
    ListNode *t0 = dummy0, *t1 = dummy1;
    ListNode *curr = head;
    while(curr) {
        if(curr->val == 0) {
            t0->next = curr;
            t0 = t0->next;
        } else {
            t1->next = curr;
            t1 = t1->next;
        }
        curr = curr->next;
    }
    t1->next = NULL;
    t0->next = dummy1->next;
    ListNode* l = dummy0->next;
    delete dummy0;
    delete dummy1;
    return l;
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
    ListNode *h1 = createList(n);
    h1 = segregate01(h1);
    printList(h1);

    return 0;
}