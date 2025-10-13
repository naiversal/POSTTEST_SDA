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

// mencari nilai terkecil dalam tree
int findMinValue(Node* root) {
    if (root == nullptr)
        return -1; // jika tree kosong, kembalikan -1 sebagai penanda

    // telusuri terus ke cabang kiri sampai habis
    while (root->left != nullptr)
        root = root->left;

    return root->data; // node paling kiri adalah nilai terkecil
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50); // node pertama menjadi root
    insert(root, 30); // node 30 berada di sisi kiri dari 50
    insert(root, 70); // node 70 berada di sisi kanan dari 50
    insert(root, 20); // node 20 berada di sisi kiri dari 30
    insert(root, 40); // node 40 berada di sisi kanan dari 30

    cout << "Nilai terkecil dalam tree adalah: " << findMinValue(root) << endl;

    return 0;
}
