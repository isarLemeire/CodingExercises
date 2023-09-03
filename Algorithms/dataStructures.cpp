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


template<typename K, typename V>
class BinaryTreeElement{
public:
    K key;
    V value;
    BinaryTreeElement<K, V>* left;
    BinaryTreeElement<K, V>*right;
    BinaryTreeElement<K, V>* parent;

    BinaryTreeElement(K key, V value): key(key), value(value), left(nullptr), right(nullptr), parent(nullptr) {};
};

template<typename K, typename V>
class BinaryTree{
private:
    
    void printTreeInOrder(BinaryTreeElement<K, V>* node, int i){
        if(node){
            printTreeInOrder(node->left, i+1);
            cout << "<" << node->key << ", " << node->value << ", " << i << ">" << endl;
            printTreeInOrder(node->right, i+1);
        }
    }

    BinaryTreeElement<K, V>* search(BinaryTreeElement<K, V>* node, K key){
        if(!node)
            return nullptr;

        if(key == node->key)
            return node;
        if(key < node->key)
            return search(node->left, key);
        else
            return search(node->right, key);
    }

    void insert(BinaryTreeElement<K, V>* node, K key, V value){
        if(!node){
            root = new BinaryTreeElement<K, V>(key, value);
            return;
        }
        if(node->key == key)
            return;
        BinaryTreeElement<K, V>*& child = (node->key > key) ? node->left : node->right;
        if (child) {
            insert(child, key, value);
        } else {
            child = new BinaryTreeElement<K, V>(key, value);
            child->parent = node;
            fixUp(child);
        }
    }

    BinaryTreeElement<K, V>* minimum(BinaryTreeElement<K, V>* node){
        if(node->left)
            return minimum(node->left);
        return node;
    }

    BinaryTreeElement<K, V>* maximum(BinaryTreeElement<K, V>* node){
        if(node->right)
            return maximum(node->right);
        return node;
    }

    void transplant(BinaryTreeElement<K, V>* nodeA, BinaryTreeElement<K, V>* nodeB){
        if(!nodeA->parent){
            root = nodeB;
        } else if(nodeA->parent->left == nodeA){
            nodeA->parent->left = nodeB;
        } else {
            nodeA->parent->right = nodeB;
        }

        if(nodeB){
            nodeB->parent = nodeA->parent;
        }
    }
    
    void leftRotate(BinaryTreeElement<K, V>* node){
        BinaryTreeElement<K, V>* newNode = node->right;
        if(!newNode)
            return;

        transplant(node, newNode);

        node->right = newNode->left;
        if(node->right)
            node->right->parent = node;

        newNode->left = node;
        node->parent = newNode;
    }

    void rightRotate(BinaryTreeElement<K, V>* node){
        BinaryTreeElement<K, V>* newNode = node->left;
        if(!newNode)
            return;

        transplant(node, newNode);

        node->left = newNode->right;
        if(node->left)
            node->left->parent = node;

        newNode->right = node;
        node->parent = newNode;
    }

    int height(BinaryTreeElement<K, V>* node){
        if(!node)
            return 0;
        return max(height(node->left), height(node->right)) + 1;
    }

    int balance(BinaryTreeElement<K, V>* node){
        return height(node->left) - height(node->right);
    }

    void fixUp(BinaryTreeElement<K, V>* node){
        int balanced = balance(node);
        if(balanced >= 2 || balanced <= -2){
            if(balanced > 0){
                BinaryTreeElement<K, V>* child = node->left;
                if(balance(child) < 0){
                    leftRotate(child);
                }
                rightRotate(node);
            }
            else{
                BinaryTreeElement<K, V>* child = node->right;
                if(balance(child) > 0){
                    rightRotate(child);
                }
                leftRotate(node);
            }
        }
        else{
            if(node->parent)
                fixUp(node->parent);
        }
    }


public:

    BinaryTreeElement<K, V>* root;

    BinaryTree(): root(nullptr) {};

    void insert(K key, V val){
        insert(root, key, val);
    }

    void printTree(){
        printTreeInOrder(root, 0);
    }

    void remove(K key){
        BinaryTreeElement<K, V>* deletedNode = search(root, key);
        if(!deletedNode)
            return;
        if(!deletedNode->left)
            transplant(deletedNode, deletedNode->right);
        else if(!deletedNode->right)
            transplant(deletedNode, deletedNode->right);
        else{
            BinaryTreeElement<K, V>* newNode = minimum(deletedNode->right);
            
            if(deletedNode->right != newNode){
                transplant(newNode, newNode->right);
                newNode->right = deletedNode->right;
                newNode->right->parent = newNode;
            }
            transplant(deletedNode, newNode);
            newNode->left = deletedNode->left;
            newNode->left->parent = newNode;
            
        }
        if(deletedNode->parent)
            fixUp(deletedNode->parent);
        delete deletedNode;
    }

    V minimum(){
        return minimum(root)->value;
    }

    V maximum(){
        return maximum(root)->value;
    }

    V search(K key){
        BinaryTreeElement<K, V>* node = search(root, key);
        if(!node)
            return nullptr;
        return node->value;
    }

};

int main(){

    return 0;
}