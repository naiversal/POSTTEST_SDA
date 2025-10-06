#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

// fungsi untuk menyisipkan node baru secara terurut pada circular doubly linked list
void sortedInsert(Node *&head_ref, int data) {
    Node* newNode = new Node{data, nullptr, nullptr};

    // kalau list masih kosong, node pertama langsung menunjuk ke dirinya sendiri
    if (head_ref == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }

    // kalau data baru lebih kecil dari data di head, node baru jadi head baru
    if (data < head_ref->data) {
        Node* tail = head_ref->prev;
        
        newNode->next = head_ref;
        newNode->prev = tail;
        head_ref->prev = newNode;
        tail->next = newNode;
        
        head_ref = newNode;
        return;
    }

    // cari posisi yang sesuai di tengah atau di akhir list
    Node* current = head_ref;
    
    // loop sampai ketemu posisi yang pas (di depan node dengan data lebih besar)
    while (current->next != head_ref && current->next->data < data) {
        current = current->next;
    }
    
    // sisipkan node baru setelah node current
    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;
}

// fungsi untuk menampilkan isi circular doubly linked list
void printList(Node *head_ref) {
    if (head_ref == nullptr) {
        cout << "List kosong" << endl;
        return;
    }

    Node *current = head_ref;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head_ref);
    cout << endl;
}

int main() {
    Node *head = nullptr;

    sortedInsert(head, 30);
    sortedInsert(head, 10);
    sortedInsert(head, 40);
    sortedInsert(head, 20);

    cout << "Circular Doubly Linked List (sorted): ";
    printList(head);

    return 0;
}
