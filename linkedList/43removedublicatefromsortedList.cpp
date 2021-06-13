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


ListNode *removeDuplicates(ListNode *head)
{
    if(head == NULL || head->next == NULL) return head;
    ListNode* dummy = new ListNode(-1);
    ListNode *t = dummy;
    while(head) {
        ListNode* temp = head;
        head = head->next;
        temp->next = NULL;
        if(t->val != temp->val) {
            t->next = temp;
            t = t->next;
        } else {
            delete temp;
        }
    }
    ListNode* l = dummy->next;
    delete dummy;
    return l;
}
// Input_code===================================================

ListNode *makeList(int n)
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

int main()
{
    int n;
    cin >> n;
    ListNode *head = makeList(n);

    head = removeDuplicates(head);
    printList(head);

    return 0;
}