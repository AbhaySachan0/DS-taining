#include <iostream>
using namespace std;

// Node definition
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Create a new node
Node* createNode(int x) {
    Node* p = new Node;
    p->data = x;
    p->prev = p->next = NULL;
    return p;
}

// Insert at beginning
void insertBeg(Node*& start, int x) {
    Node* p = createNode(x);
    if (start == NULL) {
        start = p;
    } else {
        p->next = start;
        start->prev = p;
        start = p;
    }
}

// Insert at end
void insertEnd(Node*& start, int x) {
    Node* p = createNode(x);
    if (start == NULL) {
        start = p;
    } else {
        Node* q = start;
        while (q->next) q = q->next;
        q->next = p;
        p->prev = q;
    }
}

// Insert after a given node
void insertAfter(Node* q, int x) {
    if (q == NULL) return;
    Node* p = createNode(x);
    Node* r = q->next;
    p->prev = q;
    p->next = r;
    q->next = p;
    if (r != NULL) r->prev = p;
}

// Insert before a given node
void insertBefore(Node*& start, Node* q, int x) {
    if (q == NULL) return;
    Node* p = createNode(x);
    Node* r = q->prev;
    p->next = q;
    p->prev = r;
    q->prev = p;
    if (r != NULL) {
        r->next = p;
    } else {
        start = p; // Inserted before the first node
    }
}

// Delete from beginning
void delBeg(Node*& start) {
    if (start == NULL) return;
    Node* p = start;
    start = start->next;
    if (start != NULL) start->prev = NULL;
    delete p;
}

// Delete from end
void delEnd(Node*& start) {
    if (start == NULL) return;
    Node* q = start;
    if (q->next == NULL) {
        delete q;
        start = NULL;
        return;
    }
    while (q->next) q = q->next;
    q->prev->next = NULL;
    delete q;
}

// Delete node after a given node
void delAfter(Node* q) {
    if (q == NULL || q->next == NULL) return;
    Node* p = q->next;
    Node* r = p->next;
    q->next = r;
    if (r != NULL) r->prev = q;
    delete p;
}

// Delete node before a given node
void delBefore(Node*& start, Node* q) {
    if (q == NULL || q->prev == NULL) return;
    Node* p = q->prev;
    Node* r = p->prev;
    q->prev = r;
    if (r != NULL) {
        r->next = q;
    } else {
        start = q; // Node before was the first node
    }
    delete p;
}

// Display the list
void display(Node* start) {
    Node* temp = start;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


int main() {
    Node* start = NULL;

    insertBeg(start, 10);
    insertEnd(start, 20);
    insertEnd(start, 30);
    insertBeg(start, 5);

    cout << "List after insertions: ";
    display(start);

    insertAfter(start->next, 15);  // Insert after 10
    // insertBefore(start->next->next, 12); // Insert before 15

    cout << "List after insertAfter and insertBefore: ";
    display(start);

    delBeg(start);
    delEnd(start);
    delBefore(start, start->next);  // Delete before 15
    delAfter(start->next);          // Delete after 15

    cout << "List after deletions: ";
    display(start);

    return 0;
}
