#include <iostream>
using namespace std;

// Struktur Node untuk Binary Tree
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Fungsi insert untuk membangun tree
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val); // jika root masih kosong, buat node baru sebagai root
    }
    if (val < root->data) {
        root->left = insert(root->left, val); // jika nilai lebih kecil, masukkan ke cabang kiri
    } else if (val > root->data) {
        root->right = insert(root->right, val); // jika nilai lebih besar, masukkan ke cabang kanan
    }
    return root;
}

int countNodes(Node* root) {
    if (root == nullptr)
        return 0; // jika kosong, berarti tidak ada node
    // menghitung node saat ini + jumlah node di kiri + jumlah node di kanan
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    Node* root = nullptr; // inisialisasi tree dengan kondisi kosong di awal
    root = insert(root, 50); // node pertama menjadi root
    insert(root, 30); // node 30 masuk ke sisi kiri dari 50
    insert(root, 70); // node 70 masuk ke sisi kanan dari 50
    insert(root, 20); // node 20 masuk ke sisi kiri dari 30

    // menampilkan hasil jumlah total node dalam tree
    cout << "Jumlah total node dalam tree adalah: " << countNodes(root) << endl;
    return 0;
}
