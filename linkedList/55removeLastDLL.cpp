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
    
public:
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
  }

  dll.display();

  return 0;
}