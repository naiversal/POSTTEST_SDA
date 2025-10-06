#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

// fungsi buat menukar posisi head dan tail
void exchangeHeadAndTail(Node *&head_ref) {
    // kalau list kosong atau cuma punya 1 node, ga perlu ditukar
    if (head_ref == nullptr || head_ref->next == head_ref) {
        return;
    }

    Node* head = head_ref;
    Node* tail = head_ref->prev;

    // kalau cuma ada 2 node, cukup ubah pointer head aja
    if (head->next == tail) {
        head_ref = tail;
        return;
    }

    // kalau node lebih dari 2, simpan node tetangga sebelum ubah koneksi
    Node* head_next = head->next;
    Node* tail_prev = tail->prev;

    // atur ulang koneksi untuk tail (yang bakal jadi head baru)
    tail->next = head_next;
    tail->prev = head;
    head_next->prev = tail;

    // atur ulang koneksi untuk head (yang bakal jadi tail baru)
    head->prev = tail_prev;
    head->next = tail;
    tail_prev->next = head;

    // ubah referensi head ke node tail lama (yang sekarang jadi head baru)
    head_ref = tail;
}

// fungsi buat menampilkan isi list
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

// fungsi buat menambahkan node baru di bagian akhir list
void insertEnd(Node *&head_ref, int data) {
    Node *newNode = new Node{data, nullptr, nullptr};

    // kalau list masih kosong, node pertama menunjuk ke dirinya sendiri
    if (head_ref == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }

    // sambungkan node baru di antara tail dan head
    Node *tail = head_ref->prev;
    newNode->next = head_ref;
    newNode->prev = tail;
    head_ref->prev = newNode;
    tail->next = newNode;
}

int main() {
    Node *head = nullptr;

    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);

    cout << "List sebelum exchange: ";
    printList(head);

    // menukar posisi head dan tail
    exchangeHeadAndTail(head);

    cout << "List setelah exchange head dan tail: ";
    printList(head);

    return 0;
}
