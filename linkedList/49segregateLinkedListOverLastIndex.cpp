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

ListNode *segregateOnLastIndex(ListNode *head)
{
    if(head == NULL || head->next == NULL) return head;
    ListNode *pivot = head;
    while(pivot->next) {
        pivot = pivot->next;
    }
    ListNode *dummyl = new ListNode(-1);
    ListNode *dummyr = new ListNode(-1);
    ListNode *tl = dummyl, *tr = dummyr;
    ListNode *curr = head;
    while(curr) {
        if(curr->val <= pivot->val) {
            tl->next = curr;
            tl = tl->next;
        } else {
            tr->next = curr;
            tr = tr->next;
        }
        curr = curr->next;
    }
    tr->next = NULL;
    tl->next = dummyr->next;
    //ListNode* l = dummyl->next;
    delete dummyl;
    delete dummyr;
    return tl;
    
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
    h1 = segregateOnLastIndex(h1);
    printList(h1);

    return 0;
}