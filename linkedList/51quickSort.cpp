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


ListNode* segregate(ListNode* head, ListNode* pi)
{
    if(head == NULL || head->next == NULL) return head;
    
    ListNode* dummyl = new ListNode(-1);
    ListNode* dummyr = new ListNode(-1);
    ListNode *tl = dummyl, *tr = dummyr;
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

ListNode *randomPivotNode(ListNode *head) {
    int size = 0;
    ListNode* temp = head;
    while(temp) {
        temp = temp->next;
        size++;
    }
    srand(time(0));
    int pivotIndex = rand() % size;
    ListNode* pi = head;
    for(int i = 0; i < pivotIndex; i++) {
        pi = pi->next;
    }
    return pi;
}

ListNode *quickSort(ListNode *head)
{
    if(head == NULL || head->next == NULL) return head;
    
    ListNode* pi = randomPivotNode(head);
    ListNode* plist = segregate(head, pi); // partition list;
    
    //find pre of partition node
    ListNode *pre = NULL, *curr = plist;
    while(curr != pi) {
        pre = curr;
        curr = curr->next;
    }
    // separate the lists;
    if(pre != NULL) pre->next = NULL; 
    ListNode *left = (pre == NULL) ? NULL : plist;
    ListNode* right = pi->next;
    //sort them separately
    left = quickSort(left);
    right = quickSort(right);
    //join the two lists with partition node;
    ListNode *tl = left;
    while(tl && tl->next) tl = tl->next;
    if(tl != NULL) tl->next = pi;
    pi->next = right;
    ListNode* sortedList = (left != NULL) ? left : pi;
    return sortedList;
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

    ListNode *head = quickSort(h1);
    printList(head);

    return 0;
}