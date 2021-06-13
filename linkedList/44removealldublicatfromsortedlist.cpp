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
    ListNode *dummy = new ListNode(-1);
    ListNode *t1 = dummy;
    ListNode *pre1 = NULL;
    int lastVal = -1;
    while(head) {
        ListNode* temp = head;
        head = head->next;
        temp->next = NULL;
        if(lastVal != temp->val) {
            t1->next = temp;
            pre1 = t1;
            t1 = t1->next;
            lastVal = t1->val;
        } else { // when last value matches
            if(t1->val == lastVal) { // last of ans list has same val as last val remove
                delete t1;
                t1 = pre1;
                t1->next = NULL;
            }
            delete temp;
        }
    }
    ListNode *l = dummy->next;
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