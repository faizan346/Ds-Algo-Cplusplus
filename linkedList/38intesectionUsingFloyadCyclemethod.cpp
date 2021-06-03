
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

ListNode* cyclePresentInLL(ListNode *head)
{
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast) {
            return slow;
        }
    }
    return NULL;;
}
// a = c + (b+c)(m-1)
ListNode *CycleNode(ListNode *head)
{
    ListNode* ref = cyclePresentInLL(head);
    if(ref == NULL) return NULL;
    ListNode* temp = head;
    while(temp != ref) {
        temp = temp->next;
        ref = ref->next;
    }
    return temp;
}

ListNode *IntersectionNodeInTwoLL(ListNode *headA, ListNode *headB)
{
    ListNode* tail = headB;
    while(tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = headB;
    ListNode* intersect = CycleNode(headA);
    tail->next = NULL;
    return intersect;
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

int main()
{
    int n;
    cin >> n;
    ListNode *head1 = makeList(n);
    int idx;
    cin >> idx;
    int m;
    cin >> m;
    ListNode *head2 = makeList(m);

    
    if (idx >= 0)
    {
        ListNode *curr = head1;

        while (idx-- > 0)
            curr = curr->next;

        ListNode *prev = head2;
        while (prev->next != nullptr)
            prev = prev->next;

        prev->next = curr;
    }

    ListNode *ans = IntersectionNodeInTwoLL(head1, head2);
    cout << (ans != nullptr ? ans->val : -1) << endl;
    return 0;
}
