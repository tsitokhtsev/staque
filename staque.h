#pragma once
#include <iostream>

using namespace std;

/* Node Class */
class Node {
   public:
    int data;
    Node* next;
    Node* prev;

    Node(const int d, Node* n = nullptr, Node* p = nullptr)
        : data(d), next(n), prev(p) {}
};

/* Staque Class */
class Staque {
    Node *front = nullptr, *end = nullptr;
    int size = 0;

   public:
    Staque() {}

    Staque(const Staque& obj) {
        if (obj.empty()) {
            cout << "*** Staque is empty ***\n\n";
            return;
        }

        this->front = new (nothrow) Node(obj.front->data);

        Node *this_curr = this->front, *obj_curr = obj.front->next;
        while (obj_curr != nullptr) {
            this_curr->next = new (nothrow) Node(obj_curr->data);
            this_curr = this_curr->next;
            obj_curr = obj_curr->next;
        }

        this->end = this_curr;
        size = obj.size;

        cout << "New staque was created using copy constructor...\n";
        this->print();
    }

    ~Staque() {
        Node* curr = front;
        while (curr != nullptr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }

    bool empty() const { return size == 0; }

    /* Getters */
    int get_size() const { return size; }

    int get_front() const { return front->data; }

    int get_end() const { return end->data; }

    /* print() - displays staque */
    void print() const {
        if (empty()) {
            cout << "*** Staque is empty ***\n\n";
            return;
        }

        Node* curr = front;
        cout << "front -> | ";
        for (curr; curr != nullptr; curr = curr->next) {
            cout << curr->data << " | ";
        }
        cout << "<- end\n\n";
    }

    /* push() - gets value and decides where to add it */
    void push(const int val) {
        Node* new_node = new (nothrow) Node(val);

        if (new_node == nullptr) {
            cout << "*** Out of memory ***\n";
            return;
        }

        if (size == 0) {  // If staque is empty
            front = end = new_node;
            cout << val << " was added to staque...\n";
        } else if (val % 2 == 0) {  // If new value is even
            new_node->next = front;
            front->prev = new_node;
            front = new_node;
            cout << val << " was added to the front of staque...\n";
        } else {  // If new value is odd
            new_node->prev = end;
            end->next = new_node;
            end = new_node;
            cout << val << " was added to the end of staque...\n";
        }

        size++;
        print();
    }

    /* pop_front() - removes one or more numbers from the front of queue */
    void pop_front(const int quant = 1) {
        int i;
        for (i = 0; i < quant; i++) {
            if (empty()) {
                cout << "*** Staque is empty ***\n\n";
                return;
            }

            if (i != 0) {
                cout << ", ";
            }
            cout << front->data;

            Node* curr = front;
            front = front->next;
            front->prev = nullptr;
            delete curr;
			if (front == nullptr){
				end = nullptr;
				break;
			}
            size--;
        }

        i == 1 ? cout << " was deleted from the front of staque...\n"
               : cout << " were deleted from the front of staque...\n";
        print();
    }

    /* pop_end() - removes one or more numbers from the end of queue */
    void pop_end(const int quant = 1) {
        int i = 0;
        for (i = 0; i < quant; i++) {
            if (empty()) {
                cout << "*** Staque is empty ***\n\n";
                return;
            }

			if (i != 0) {
                cout << ", ";
            }
            cout << end->data;

            Node* curr = end;
            end = end->prev;
            delete curr;
            if (end == nullptr) {
                front = nullptr;
                break;
            }
            end->next = nullptr;
            size--;
        }

        i == 1 ? cout << " was deleted from the end of staque...\n"
               : cout << " were deleted from the end of staque...\n";
        print();
    }

    /* pop_even() - removes one or more even numbers from queue */
    void pop_even(const int quant = 1) {
        int i = 0;
        while (i != quant) {
            if (empty()) {
                break;
            }
            if (front->data % 2 != 0) {
                cout << "*** No even numbers left in staque ***\n";
                break;
            }

            i++;
            cout << front->data << " was deleted from staque...\n";

            size--;

            Node* curr = front;
            front = front->next;
            delete curr;
            if (front == nullptr) {
                end = nullptr;
                break;
            }
            front->prev = nullptr;
        }

        print();
    }

    /* pop_odd() - removes one or more odd numbers from queue */
    void pop_odd(const int quant = 1) {
        int i;
        for (i = 0; i < quant; i++) {
            if (empty()) {
                cout << "*** Staque is empty ***\n\n";
                return;
            }
            if (end->data % 2 == 0) {
                cout << "*** No odd numbers in staque ***\n\n";
                return;
            }

            if (i != 0) {
                cout << ", ";
            }
            cout << front->data << " was deleted from staque...\n";
            cout << end->data;

            size--;

            Node* curr = end;
            end = end->prev;
            delete curr;
            if (end == nullptr) { // If 
                front = nullptr;
                return;
            }
            end->next = nullptr;
        }

        print();
    }

    /* Overloading '=' operator */
    Staque& operator=(const Staque& obj) {
        if (this != &obj) {
            Staque(obj);
        } else {
            cout << "*** Can't assign an object to the same object ***\n\n";
        }
        return *this;
    }
};