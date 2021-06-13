#include <iostream>
using namespace std;

class ListNode
{
public:
  int val = 0;
  ListNode* next = nullptr;

  ListNode(int val)
  {
    this->val = val;
  }
};

ListNode* segregate(ListNode* head, int pivotIdx)
{
    if(head == NULL || head->next == NULL) return head;
    
    ListNode* dummyl = new ListNode(-1);
    ListNode* dummyr = new ListNode(-1);
    ListNode *tl = dummyl, *tr = dummyr;
    ListNode *pi = head;
    for(int i = 0; i < pivotIdx; i++) {
        pi = pi->next;
    }
    ListNode *curr = head;
    while(curr) {
        if(curr == pi);
        else if(curr->val <= pi->val) {
            tl->next = curr;
            tl = tl->next;
        } else {
            tr->next = curr;
            tr = tr->next;
        }
        curr = curr->next;
    }
    tl->next = pi;
    tl = tl->next; 
    
    tr->next = NULL;
    tl->next = dummyr->next;
    ListNode* l = dummyl->next;
    delete dummyl;
    delete dummyr;
    return l;
}

void printList(ListNode* node)
{
  ListNode* curr = node;
  while (curr != nullptr)
  {
    cout << curr->val << " ";
    curr = curr->next;
  }
  cout << endl;
}

ListNode* createList(int n)
{
  ListNode* dummy = new ListNode(-1);
  ListNode* prev = dummy;
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
  int n, pivotIdx;
  cin >> n;
  ListNode* h1 = createList(n);
  cin >> pivotIdx;
  h1 = segregate(h1, pivotIdx);
  printList(h1);

  return 0;
}