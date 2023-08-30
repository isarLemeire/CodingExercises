#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

template<typename V>
class StackItem{
private:
    V val;
    StackItem<V>* prev;
public:
    StackItem(V val, StackItem<V>* prev= nullptr): val(val), prev(prev) {};

    V getVal(){
        return val;
    }

    StackItem<V>* getPrev(){
        return prev;
    }

    void setPrev(StackItem<V>* newPrev){
        prev = newPrev;
    }
};


template<typename V>
class Stack{
private:
    StackItem<V>* top;
public:

    void push(V val){
        StackItem<V>* item = new StackItem<V>(val, top);
        top = item;
    }

    V pop(){
        if(!top)
            throw runtime_error("Stack underflow: Cannot pop from an empty stack.");
        V val = top->getVal();
        StackItem<V>* prev = top->getPrev();
        delete top;
        top = prev;
        return val;
    }

    ~Stack(){
        while (top)
        {
            StackItem<V>* prev = top->getPrev();
            delete top;
            top = prev;
        }
    }
};

template<typename V>
class Queue{
private:
    StackItem<V>* top;
    StackItem<V>* tail;
public:
    void enqueue(V val){
        StackItem<V>* item = new StackItem<V>(val);
        if(top)
            tail->setPrev(item);
        else
            top = item;
        tail = item;
    }

    V dequeue(){
        if(!top)
            throw runtime_error("Queue underflow: Cannot dequeue from an empty queue.");
        V val = top->getVal();
        StackItem<V>* prev = top->getPrev();
        delete top;
        top = prev;
        return val;
    }

    ~Queue(){
        while(top)
        {
            StackItem<V>* prev = top->getPrev();
            delete top;
            top = prev;
        }
    }
};

template<typename K, typename V>
class LinkedListItem{
private:
    V val;
    K key;
    LinkedListItem<K, V>* prev = nullptr;
    LinkedListItem<K, V>* next = nullptr;
public:
    LinkedListItem(K key, V val): key(key), val(val) {};

    V getVal(){
        return val;
    }

    K getKey(){
        return key;
    }

    void setNext(LinkedListItem<K, V>* next){
        this->next = next;
    }

    void setPrev(LinkedListItem<K, V>* prev){
        this->prev = prev;
    }

    LinkedListItem<K, V>* getPrev(){
        return prev;
    }

    LinkedListItem<K, V>* getNext(){
        return next;
    }

};

template<typename K, typename V>
class LinkedList{
private:
    LinkedListItem<K, V>* head = nullptr;
public:
    LinkedList(){};

    void insert(K key, V val){
        LinkedListItem<K, V>* item =  new LinkedListItem<K, V>(key, val);
        item->setNext(head);
        if(head){
            head->setPrev(item);
        }
        head = item;
    }

    void remove(K key){
        if(!head)
            throw runtime_error("Linked list: remove in empty list");
        LinkedListItem<K, V>* item = head;
        while (item->getKey() != key)
        {
            item = item->getNext();
            if(!item)
                throw runtime_error("Linked list: attempted to remove an unexisting key");
        }
        LinkedListItem<K, V>* next = item->getNext();
        LinkedListItem<K, V>* prev = item->getPrev();
        if(next){
            next->setPrev(prev);
        }
        if(prev){
            prev->setNext(next);
        } else{
            head = next;
        }
        delete item;
    }

    V search(K key){
        if(!head)
            throw runtime_error("Linked list: search in empty list");
        LinkedListItem<K, V>* item = head;
        while (item->getKey() != key)
        {
            item = item->getNext();
            if(!item)
                throw runtime_error("Linked list: Element not found");
        }
        return item->getVal();
    }

    ~LinkedList(){
        while(head)
        {
            LinkedListItem<K, V>* next = head->getNext();
            delete head;
            head = next;
        }
    };

};







int main(){

    Stack<int> stack{};
    stack.push(50);
    stack.push(30);

    cout << "Stack: " << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;

    Queue<int> queue{};
    queue.enqueue(100);
    queue.enqueue(1);
    cout << "Queue: " << endl;
    cout << queue.dequeue() << endl;
    cout << queue.dequeue() << endl;
    queue.enqueue(50);
    cout << queue.dequeue() << endl;
    queue.enqueue(10);

    LinkedList<int, char> l{};
    l.insert(1, 'A');
    l.insert(2, 'B');
    l.insert(3, 'C');
    cout << "List: " << endl;
    cout << l.search(1) << endl;
    cout << l.search(2) << endl;
    cout << l.search(3) << endl;
    l.remove(2);
    cout << l.search(1) << endl;
    cout << l.search(3) << endl;

    return 0;
}