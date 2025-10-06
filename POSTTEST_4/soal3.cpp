#include <iostream>
#include <string>
using namespace std;

struct Node {
    string document;
    Node* next;
};

void enqueue(Node*& front, Node*& rear, string document) {
    Node* newNode = new Node{document, nullptr};

    // jika antrian masih kosong maka front dan rear menunjuk ke node baru yang sama
    if (front == nullptr) {
        front = newNode;
        rear = newNode;
    }
    // jika antrian sudah berisi maka tambahkan node baru di belakang lalu update rear
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

string dequeue(Node*& front, Node*& rear) {
    // jika antrian kosong maka kembalikan string kosong
    if (front == nullptr) return "";

    // ambil data dokumen dari node paling depan
    string document = front->document;
    Node* temp = front;
    front = front->next;
    
    // jika setelah dihapus antrian menjadi kosong maka rear juga diatur menjadi null
    if (front == nullptr) {
        rear = nullptr;
    }
    
    delete temp;
    return document;
}

void processAllDocuments(Node*& front, Node*& rear) {
    // selama antrian masih ada maka dokumen terus diambil dan diproses
    while (front != nullptr) {
        string doc = dequeue(front, rear);
        cout << "Memproses: " << doc << endl;
    }
}

int main() {
    Node* front = nullptr;
    Node* rear = nullptr;

    enqueue(front, rear, "Document1.pdf");
    enqueue(front, rear, "Report.docx");
    enqueue(front, rear, "Presentation.pptx");

    cout << "Memulai pemrosesan antrian printer:" << endl;
    // memproses seluruh dokumen sampai antrian kosong
    processAllDocuments(front, rear);

    return 0;
}
