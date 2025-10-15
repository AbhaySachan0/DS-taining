#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* next;
};

Node* GetNode(int x) {
    Node* p = new Node;
    p->info = x;
    p->next = NULL;
    return p;
}

void InsBeg(Node*& CSTART, int x) {
    Node* p = GetNode(x);
    if (CSTART == NULL) {
        p->next = p;
        CSTART = p;
    } else {
        p->next = CSTART->next;
        CSTART->next = p;
    }
}

void InsAft(Node* Q, int x) {
    if (Q == NULL) return;
    Node* p = GetNode(x);
    p->next = Q->next;
    Q->next = p;
}

void InsEnd(Node*& CSTART, int x) {
    Node* p = GetNode(x);
    if (CSTART == NULL) {
        p->next = p;
        CSTART = p;
    } else {
        p->next = CSTART->next;
        CSTART->next = p;
        CSTART = p;
    }
}

void DelBeg(Node*& CSTART) {
    if (CSTART == NULL) return;
    Node* p = CSTART->next;
    if (CSTART == p) {
        delete p;
        CSTART = NULL;
    } else {
        CSTART->next = p->next;
        delete p;
    }
}

void DelEnd(Node*& CSTART) {
    if (CSTART == NULL) return;
    Node* q = CSTART->next;
    if (q == CSTART) {
        delete CSTART;
        CSTART = NULL;
        return;
    }
    while (q->next != CSTART)
        q = q->next;
    Node* p = CSTART;
    q->next = CSTART->next;
    CSTART = q;
    delete p;
}

void DelAft(Node*& CSTART, Node* Q) {
    if (CSTART == NULL || Q == NULL || Q->next == NULL) return;
    Node* p = Q->next;
    Q->next = p->next;
    if (p == CSTART)
        CSTART = Q;
    delete p;
}

void Traverse(Node* CSTART) {
    if (CSTART == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Node* p = CSTART->next;
    do {
        cout << p->info << " ";
        p = p->next;
    } while (p != CSTART->next);
    cout << endl;
}

int main() {
    Node* CSTART = NULL;

    // Insert at beginning
    InsBeg(CSTART, 10);
    InsBeg(CSTART, 20);
    InsBeg(CSTART, 30);
    InsBeg(CSTART, 40);

    // Insert at end
    InsEnd(CSTART, 50);
    InsEnd(CSTART, 60);

    // Insert after a node
    InsAft(CSTART->next, 25);  // After 40

    cout << "Initial List: ";
    Traverse(CSTART);

    // Delete beginning
    DelBeg(CSTART);
    cout << "After DelBeg: ";
    Traverse(CSTART);

    // Delete end
    DelEnd(CSTART);
    cout << "After DelEnd: ";
    Traverse(CSTART);

    // Delete after a node
    DelAft(CSTART, CSTART->next); // After first node
    cout << "After DelAft: ";
    Traverse(CSTART);

    // More insertions
    InsEnd(CSTART, 70);
    InsEnd(CSTART, 80);
    InsBeg(CSTART, 5);

    cout << "After more insertions: ";
    Traverse(CSTART);

    return 0;
}
