#include <iostream>
using namespace std;



struct Node {
    string data;
    Node* next;

    Node(string _data) : data(_data), next(nullptr) {}
};

struct list {
    Node* head;
    Node* tail;


    list() : head(nullptr), tail(nullptr) {}

    bool is_exist() {
        return head == nullptr;
    }

    void push_back(string _data) {
        Node* pointer = new Node(_data);
        if (is_exist()) {
            head = pointer;
            tail = pointer;
            return;
        }
        tail->next = pointer;
        tail = pointer;
    }

    void print() {
        string a[100];
        if (is_exist()) return;
        Node* pointer = head;
        int i = 0;
        while (pointer) {
            a[i] = pointer->data;
            i++;
            bool exists = std::count(std::begin(a), std::end(a), pointer->data) > 1;
            if (!exists) {
                cout << pointer->data << " ";
            }
            pointer = pointer->next;
        }
        cout << endl;
    }

    Node* find(string _data) {
        Node* pointer = head;
        while (pointer && pointer->data != _data) pointer = pointer->next;
        return (pointer && pointer->data == _data) ? pointer : nullptr;
    }

    void remove_head() {
        if (is_exist()) return;
        Node* pointer = head;
        head = pointer->next;
        delete pointer;
    }

    void remove_tail() {
        if (is_exist()) return;
        if (head == tail) {
            remove_head();
            return;
        }
        Node* pointer = head;
        while (pointer->next != tail) pointer = pointer->next;
        pointer->next = nullptr;
        delete tail;
        tail = pointer;
    }

    void delete_counters(string _data) {
        
    }

    void remove(string _data) {
        if (is_exist()) return;
        if (head->data == _data) {
            remove_head();
            return;
        }
        else if (tail->data == _data) {
            remove_tail();
            return;
        }
        Node* current = head;
        Node* current_new = head->next;
        while (current_new && current_new->data != _data) {
            current_new = current_new->next;
            current = current->next;
        }
        if (!current_new) {
            cout << "This element does not exist" << endl;
            return;
        }
        current->next = current_new->next;
        delete current_new;
    }


    Node* operator[](const int index) {
        if (is_exist()) return nullptr;
        Node* pointer = head;
        for (int i = 0; i < index; i++) {
            pointer = pointer->next;
            if (!pointer) return nullptr;
        }
        return pointer;
    }
};



int main()
{
    list l;
    l.push_back("3");
    l.push_back("3");
    l.push_back("3");
    l.push_back("3");
    l.push_back("3");
    l.remove_head();
    l.print();
    l.remove_head();
    l.print();
    l.remove_head();
    l.print();
    l.print();
    l.push_back("123");
    l.print();
    l.push_back("8");
    l.push_back("123");
    l.print();
    l.push_back("8");
    l.print();
    l.remove("123");
    l.print();
    l.push_back("1234");
    l.push_back("3");
    l.print();
    l.remove_head();
    l.print();
    l.remove_tail();
    l.print();
    return 0;
}