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

ListNode *takeInput()
{
    int n;
    cin >> n;
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;
    while (n-- > 0)
    {
        int val;
        cin >> val;
        prev->next = new ListNode(val);
        prev = prev->next;
    }
    int idx;
    cin >> idx;
    if (idx >= 0)
    {
        ListNode *curr = dummy->next;
        while (idx-- > 0)
        {
            curr = curr->next;
        }
        prev->next = curr;
    }
    return dummy->next;
}

int main()
{
    ListNode *head = takeInput();
    ListNode *ans = CycleNode(head);
    cout << (ans != nullptr ? ans->val : -1) << endl;
    return 0;
}