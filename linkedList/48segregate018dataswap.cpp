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

ListNode *segregate012(ListNode *head)
{
    if(head == NULL || head->next == NULL) return head;
    ListNode *i, *j;
    i = j = head;
    while(i) {
        if(i->val == 0) {
            int temp = i->val;
            i->val = j->val;
            j->val = temp;
            j = j->next;
        }
        i = i->next;
    }
    i = head;
    while(i->val == 0) {
        i = i->next;
    }
    j = i;
    while(i) {
        if(i->val == 1) {
            int temp = i->val;
            i->val = j->val;
            j->val = temp;
            j = j->next;
        }
        i = i->next;
    }
    return head;
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
    h1 = segregate012(h1);
    printList(h1);

    return 0;
}