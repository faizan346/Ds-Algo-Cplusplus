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
    while(t1 || t2 || c > 0) {
        int digitValue = (((t1)?t1->val:0) + ((t2)?t2->val:0) + c) % 10;
        c = (((t1)?t1->val:0) + ((t2)?t2->val:0) + c) / 10;
        t3->next = new ListNode(digitValue);
        if(t1) t1 = t1->next;
        if(t2) t2 = t2->next;
        t3 = t3->next;
    }
    
    ListNode* l3 = dummy->next;
    delete dummy;
    l1 = reverseList(l1);
    l2 = reverseList(l2);
    l3 = reverseList(l3);
    return l3;
}
ListNode *multiplyTwoNumbers(ListNode *l1, ListNode *l2)
{
    if(l1 == NULL || l2 == NULL) return NULL;
    l1 = reverseList(l1);
    l2 = reverseList(l2);
    ListNode* listMul = NULL;
    int mulDigit = 1; // of l2
    ListNode* t2 = l2;
    while(t2) {
        ListNode* t1= l1;
        ListNode* dummySum = new ListNode(-1);
        ListNode* t3 = dummySum;
        int c = 0;
        while(t1) {
            int val = (t1->val*t2->val + c)%10;
            c = (t1->val*t2->val + c)/10;
            t3->next = new ListNode(val);
            t1 = t1->next;
            t3 = t3->next;
        }
        if(c > 0) {
            t3->next = new ListNode(c);
            t3 = t3->next;
        }
        t2 = t2->next;
        ListNode* s = dummySum->next;
        ListNode* st = s;
        s = reverseList(s);
        for(int i = 1; i < mulDigit; i++) { // to add aditional zeros.
            st->next = new ListNode(0);
            st = st->next;
        }
        delete dummySum;
        listMul = addTwoNumbers(listMul, s);
        mulDigit++;
    }
    l1 = reverseList(l1);
    l2 = reverseList(l2);
    return listMul;
    
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

    ListNode *head = multiplyTwoNumbers(head1, head2);
    printList(head);

    return 0;
}