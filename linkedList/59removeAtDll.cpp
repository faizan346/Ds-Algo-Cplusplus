#include <bits/stdc++.h>
using namespace std;

class DoublyLinkedList
{
  class Node
  {
  public:
    int data = 0;
    Node* prev = nullptr;
    Node* next = nullptr;

    Node(int data)
    {
      this->data = data;
    }
  };

  Node* head = nullptr;
  Node* tail = nullptr;
  int size = 0;

public:
  void display()
  {
    string str = "";
    Node* curr = this->head;
    str += "[";
    while (curr != nullptr)
    {
      str += to_string(curr->data);
      if (curr->next != nullptr)
        str += ", ";
      curr = curr->next;
    }
    str += "]";

    cout << str << endl;
  }

private:
  void addFirstNode(Node* node)
  {
    if (this->size == 0)
      this->head = this->tail = node;
    else
    {
      node->next = this->head;
      this->head->prev = node;
      this->head = node;
    }
    this->size++;
  } 
  
  void addLastNode(Node* node) {
      if(!head) {
          head = tail = node;
      } else {
          tail->next = node;
          node->prev = tail;
          tail = node;
      }
      size++;
  }
  
  Node *getFirstNode() {
      return head;
  }
  
  Node *getLastNode() {
      return tail;
  }
  
  Node *getNodeAt(int ind) {
        Node *temp = head;
        while(ind-- > 0) {
            temp = temp->next;
        }
        return temp;
  }
  
  void addNodeAt(int ind, Node *node) {
      if(ind == 0) {
          if(size == 0) {
              head = tail = node;
          } else {
              node->next = head;
              head->prev = node;
              head = node;
          }
      } else if(ind == size) {
          tail->next = node;
          node->prev = tail;
          tail = node;
      } else {
          Node *temp = head;
          while(ind-- > 1) {
              temp = temp->next;
          }
          node->prev = temp;
          node->next = temp->next;
          temp->next = node;
          node->next->prev = node;
      }
      size++;
  }
  
  int removeNodeAt(int ind) {
      Node *toRemove = NULL;
      if(ind == 0) {
            toRemove = head;
            if(size == 1) {
                head = tail = NULL;    
            } else {
                head = head->next;
                head->prev = NULL;
            }
      } else if(ind == size-1) {
            toRemove = tail;
            tail = tail->prev;
            tail->next = NULL;
      } else {
          toRemove = head;
          while(ind-- > 0) {
              toRemove = toRemove->next;
          }
          toRemove->prev->next = toRemove->next;
          toRemove->next->prev = toRemove->prev;
      }
      int data = toRemove->data;
      delete toRemove;
      size--;
      return data;
  }
    
public:
    
  bool isEmpty() {
      if(size == 0) return true;
      return false;
  }
  
  int getSize() {
      return size;
  }
    
  void addFirst(int data)
  {
    Node* node = new Node(data);
    addFirstNode(node);
  }

  void addLast(int data)
  {
    Node* node = new Node(data);
    addLastNode(node);
  }
  
  int removeFirst() {
    if(head == NULL) {
      cout << "ListIsEmpty: ";
      return -1;
    }
    Node *toRemove = head;
    int data = toRemove->data;
    if(head == tail) {
      head = tail = NULL;
    } else {
      head = head->next;
      head->prev = NULL;
    }
    delete toRemove;
    size--;
    return data;
  }
  
  int removeLast() {
    if(head == NULL) {
        cout << "ListIsEmpty: ";
        return -1;
    }
    Node *toRemove = tail;
    int data = toRemove->data;
    if(head == tail) {
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }
    delete toRemove;
    size--;
    return data;
  }
  
  int getFirst() {
    if(head == NULL) {
        cout << "ListIsEmpty: ";
        return -1;
    }
    return getFirstNode()->data;
  }
  
  int getLast() {
    if(head == NULL) {
        cout << "ListIsEmpty: ";
        return -1;
    }
    return getLastNode()->data;
  }
  
  int getAt(int ind) {
    if(isEmpty()) {
        cout << "ListIsEmpty: ";
        return -1;
    }
    if(ind < 0 || ind >= size) {
        cout << "IndexIsInValid: ";
        return -1;
    }
    return getNodeAt(ind)->data;
  }
  
  void addAt(int ind, int data) {
        if(ind < 0 || ind > size) {
            cout << "IndexIsInValid: -1" << endl;
            return;
        }
        Node *node = new Node(data);
        addNodeAt(ind, node);
  }
  
  int removeAt(int ind) {
        if(isEmpty()) {
            cout << "ListIsEmpty: ";
            return -1;
        }
        if(ind < 0 || ind >= size) {
            cout << "IndexIsInValid: ";
            return -1;
        }
        removeNodeAt(ind);
  }
};


int main()
{
  DoublyLinkedList dll;
  string s;
  while (getline(cin, s))
  {
    stringstream ss(s);
    string word;
    ss >> word;
    if (word == "stop")
      break;
    if (word == "addFirst")
    {
      int data;
      ss >> data;
      dll.addFirst(data);
    }
    else if (word == "addLast")
    {
      int data;
      ss >> data;
      dll.addLast(data);
    }
    else if(word == "removeFirst")
    {
        cout << dll.removeFirst() << endl;
    }
    else if(word == "removeLast") 
    {
        cout << dll.removeLast() << endl;
    } 
    else if(word == "getFirst")
    {
        cout << dll.getFirst() << endl;
    }
    else if(word == "getLast") 
    {
        cout << dll.getLast() << endl;
    }
    else if(word == "getAt")
    {
        int ind;
        ss >> ind;
        cout << dll.getAt(ind) << endl;
    }
    else if(word == "isEmpty")
    {
        cout << (dll.isEmpty() ? "true" : "false") << endl;
    }
    else if(word == "size")
    {
        cout << dll.getSize() << endl;
    }
    else if(word == "addAt")
    {
        int ind, data;
        ss >> ind;
        ss >> data;
        dll.addAt(ind, data);
    }
    else if(word == "removeAt") 
    {
        int ind;
        ss >> ind;
        cout << dll.removeAt(ind) << endl;
    }
  }

  dll.display();
  return 0;
}