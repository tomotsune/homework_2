#pragma once
#include<iostream>
using namespace std;
template<typename T>
struct Node
{
    T val;
    Node* next;
    explicit Node(T x) :val(x), next(nullptr) {}
};
template<typename T>
class Set
{
private:
    Node<T>* head;
    int length{};
public:
    Set();
    Set (const Set& s);
    void insertHead(T var);
    void insert(T val, const int& pos);
    void add(const T& data);
    void remove(T val);
    int getLength();
    void reverse();
    int find(T val);
    void print();
    Set<T>& operator+(const Set& s);
    Set<T>& operator*(const Set& s);
/*    friend ostream &operator<<(ostream &os, const Set &set){
      set.print();
    }*/

    ~Set();
};

template<typename T>
inline Set<T>::Set()
{
    head = nullptr;
    length == 0;
}

template<typename T>
inline void Set<T>::insertHead(T var)
{
    insert(var, 0);
}

template<typename T>
inline void Set<T>::insert(T val, const int& pos)
{
    if (pos < 0) {
        cout << "pos must be greater than zero" << endl;
        return;
    }
    int index{ 1 };//walking stick of temp
    Node<T>* temp{ head };
    auto* node = new Node<T>{ val };
    if (pos == 0) {
        node->next = temp;
        head = node;
        length++;
        return;
    }
    //将temp置于要插入的节点之前.
    while (temp != nullptr && index < pos) {
        temp = temp->next;
        ++index;
    }
    //插入位置不当
    if (temp == nullptr) {
        cout << "Insert failed!" << endl;
    }
    //交接后续结点.
    node->next = temp->next;
    temp->next = node;
    ++length;
}

template<typename T>
inline void Set<T>::remove(T val)
{
    int pos = find(val);
    if (-1 == pos) {
        cout << "delete failed";
        return;
    }
    if (0==pos) {
        head = head->next;
        --length;
        return;
    }
    int index{ 1 };
    Node<T>* temp = head;
    while (index < pos) {
        temp = temp->next;
    }
    Node<T>* removeNode{ temp->next };
    temp->next == temp->next->next;
    delete removeNode;
    --length;
}

template<typename T>
inline int Set<T>::getLength()
{
    return length;
}

template<typename T>
inline void Set<T>::reverse()
{
    if (head == nullptr) {
        return;
    }
    Node<T>* curNode{ head }, * nextNode{ head->next }, * temp;
    while (nextNode!=nullptr)
    {
        temp = nextNode->next;
        nextNode->next = curNode;
        curNode = nextNode;
        nextNode = temp;
    }
    head->next = nullptr ;
    head = curNode;
}

template<typename T>
inline int Set<T>::find(T val)
{
    Node<T>* temp = head;
    int index{};
    while (temp != nullptr) {
        if (temp->val == val) {
            return index;
        }
        temp = temp->next;
        ++index;
    }
    return -1;
}

template<typename T>
inline void Set<T>::print()
{
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    Node<T>* temp{ head };
    while (temp!=nullptr)
    {
        cout << temp->val << endl;
        temp = temp->next;
    }
    cout << endl;
}

template<typename T>
inline Set<T>::~Set()
{
    Node<T>* temp;
    for (int  i = 0; i < length; i++)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

template<typename T>
Set<T>& Set<T>::operator+(const Set &s) {
    auto temp_1{head},temp_2{s.head};
    auto sum{*this};
    while(temp_2!= nullptr) {
        while (temp_1 != nullptr) {
            if (temp_1->val == temp_2->val){
                break;
            }
            temp_1 = temp_1->next;
        }
        if(temp_1== nullptr){
            sum.add(temp_2->val);
        }
        temp_1=head;
        temp_2=temp_2->next;
    }
    return sum;
}

template<typename T>
void Set<T>::add(const T &t) {
    auto temp {head};
    int index{};
    while(temp!= nullptr){
        temp=temp->next;
        ++index;
    }
    insert(t, index);
}

template<typename T>
Set<T> &Set<T>::operator*(const Set &s) {
    auto temp_1{head},temp_2{s.head};
    Set<T> product{};
    while(temp_1!= nullptr) {
        while (temp_2 != nullptr) {
            if (temp_1->val == temp_2->val){
                product.add{t}
            }
            temp_1 = temp_1->next;
        }
        if(temp_1== nullptr){
            intersection.add(temp_2->val);
        }
        temp_1=head;
        temp_2=temp_2->next;
    }
    return intersection;
}

template<typename T>
Set<T>::Set(const Set &s) {
    auto temp_1{head},temp_2{s.head};
    head=new Node<T>{s.head};
    while(temp_2!= nullptr){
        temp_1->next=new Node<T>(temp_2->next);
        temp_1=temp_1->next;
        temp_2=temp_2->next;
    }
    temp_1= nullptr;
}

