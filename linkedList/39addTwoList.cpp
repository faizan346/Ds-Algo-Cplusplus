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

ListNode *midNode(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

ListNode* reverseList(ListNode* head) {
    ListNode* pre = NULL;
    ListNode* curr = head;
    while(curr) {
        ListNode* next = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;
    }
    return pre;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    l1 = reverseList(l1);
    l2 = reverseList(l2);
    ListNode* dummy = new ListNode(-1);
    ListNode *t1 = l1, *t2 = l2, *t3 = dummy;
    int c = 0;
    while(t1 && t2) {
        int digitValue = (t1->val + t2->val + c) % 10;
        c = (t1->val + t2->val + c) / 10;
        t3->next = new ListNode(digitValue);
        t1 = t1->next;
        t2 = t2->next;
        t3 = t3->next;
    }
    while(t1) {
        int digitValue = (t1->val + c) % 10;
        c = (t1->val + c) / 10;
        t3->next = new ListNode(digitValue);
        t1 = t1->next;
        t3 = t3->next;
    }
    while(t2) {
        int digitValue = (t2->val + c) % 10;
        c = (t2->val + c) / 10;
        t3->next = new ListNode(digitValue);
        t2 = t2->next;
        t3 = t3->next;
    }
    if(c > 0) {
        t3->next = new ListNode(c);
    }
    ListNode* l3 = dummy->next;
    delete dummy;
    l1 = reverseList(l1);
    l2 = reverseList(l2);
    l3 = reverseList(l3);
    return l3;
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
    ListNode *head1 = makeList(n);

    int m;
    cin >> m;
    ListNode *head2 = makeList(m);

    ListNode *head = addTwoNumbers(head1, head2);
    printList(head);

    return 0;
}