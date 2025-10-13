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
    if (root == nullptr)
        return new Node(val); // jika belum ada node, buat node baru
    if (val < root->data)
        root->left = insert(root->left, val); // jika nilai lebih kecil, masukkan ke cabang kiri
    else if (val > root->data)
        root->right = insert(root->right, val); // jika nilai lebih besar, masukkan ke cabang kanan
    return root;
}

// mencari nilai terbesar dalam tree
int findMaxValue(Node* root) {
    if (root == nullptr)
        return -1; // jika tree kosong, kembalikan -1

    // telusuri terus ke cabang kanan sampai habis
    while (root->right != nullptr)
        root = root->right;

    return root->data; // node paling kanan adalah nilai terbesar
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50); // node pertama menjadi root
    insert(root, 30); // node 30 berada di sisi kiri dari 50
    insert(root, 70); // node 70 berada di sisi kanan dari 50
    insert(root, 20); // node 20 berada di sisi kiri dari 30
    insert(root, 80); // node 80 berada di sisi kanan dari 70

    cout << "Nilai terbesar dalam tree adalah: " << findMaxValue(root) << endl;

    return 0;
}
