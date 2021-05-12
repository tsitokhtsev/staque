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

        /* Adding first node */
        this->front = this->end = new (nothrow) Node(obj.front->data);

        /* Adding remainig nodes */
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

    /* print() - prints out staque */
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

        /* If staque is empty */
        if (size == 0) {
            front = end = new_node;
            cout << val << " was added to staque...\n";
        }
        /* If new value is even */
        else if (val % 2 == 0) {
            new_node->next = front;
            front->prev = new_node;
            front = new_node;
            cout << val << " was added to the front of staque...\n";
        }
        /* If new value is odd */
        else {
            new_node->prev = end;
            end->next = new_node;
            end = new_node;
            cout << val << " was added to the end of staque...\n";
        }

        size++;
        print();
    }

    /* pop_front() - removes one or more numbers from the front of staque */
    void pop_front(const int quant = 1) {
        if (empty()) {
            cout << "Can't remove numbers...\n"
                 << "*** Staque is empty ***\n\n";
            return;
        }

        int i;
        for (i = 0; i < quant; i++) {
            if (i != 0) cout << ", ";
            cout << front->data;
            size--;

            /* Removing number from the front */
            Node* curr = front;
            front = front->next;
            delete curr;

            /* If there are no numbers left */
            if (front == nullptr) {
                end = nullptr;
                i++;
                break;
            }

            /* Removing pointer to deleted number */
            front->prev = nullptr;
        }

        i == 1 ? cout << " was removed from the front of staque...\n"
               : cout << " were removed from the front of staque...\n";
        print();
    }

    /* pop_end() - removes one or more numbers from the end of staque */
    void pop_end(const int quant = 1) {
        if (empty()) {
            cout << "Can't remove numbers...\n"
                 << "*** Staque is empty ***\n\n";
            return;
        }

        int i;
        for (i = 0; i < quant; i++) {
            if (i != 0) cout << ", ";
            cout << end->data;
            size--;

            /* Removing number from the end */
            Node* curr = end;
            end = end->prev;
            delete curr;

            /* If there are no numbers left */
            if (end == nullptr) {
                front = nullptr;
                i++;
                break;
            }

            /* Removing pointer to deleted number */
            end->next = nullptr;
        }

        i == 1 ? cout << " was deleted from the end of staque...\n"
               : cout << " were deleted from the end of staque...\n";
        print();
    }

    /* pop_even() - removes one or more even numbers from staque */
    void pop_even(const int quant = 1) {
        if (empty()) {
            cout << "Can't remove numbers...\n"
                 << "*** Staque is empty ***\n\n";
            return;
        }

        int i;
        for (i = 0; i < quant; i++) {
            if (i != 0) cout << ", ";
            cout << front->data;
            size--;

            /* Removing number from the front */
            Node* curr = front;
            front = front->next;
            delete curr;

            /* If there are no numbers left */
            if (front == nullptr) {
                end = nullptr;
                i++;
                break;
            }

            /* Removing pointer to deleted number */
            front->prev = nullptr;

            /* If there are no even numbers left */
            if (front->data % 2 != 0) break;
        }

        i == 1 ? cout << " was removed from the front of staque...\n"
               : cout << " were removed from the front of staque...\n";
        if (!empty() && front->data % 2 != 0) {
            cout << "*** No even numbers left in staque ***\n";
        }
        print();
    }

    /* pop_odd() - removes one or more odd numbers from staque */
    void pop_odd(const int quant = 1) {
        if (empty()) {
            cout << "Can't remove numbers...\n"
                 << "*** Staque is empty ***\n\n";
            return;
        }

        int i;
        for (i = 0; i < quant; i++) {
            if (i != 0) cout << ", ";
            cout << end->data;
            size--;

            /* Removing number from the end */
            Node* curr = end;
            end = end->prev;
            delete curr;

            /* If there are no numbers left */
            if (end == nullptr) {
                front = nullptr;
                i++;
                break;
            }

            /* Removing pointer to deleted number */
            end->next = nullptr;

            /* If there are no odd numbers left */
            if (end->data % 2 == 0) break;
        }

        i == 1 ? cout << " was removed from the front of staque...\n"
               : cout << " were removed from the front of staque...\n";
        if (!empty() && end->data % 2 == 0) {
            cout << "*** No odd numbers in staque ***\n";
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