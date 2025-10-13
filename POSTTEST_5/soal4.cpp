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

// menelusuri tree secara post-order
void postOrderTraversal(Node* root) {
    if (root == nullptr)
        return; // jika kosong, hentikan rekursi

    // telusuri subtree kiri lalu kanan, baru cetak node saat ini
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50); // node pertama menjadi root
    insert(root, 30); // node 30 berada di sisi kiri dari 50
    insert(root, 70); // node 70 berada di sisi kanan dari 50
    insert(root, 20); // node 20 berada di sisi kiri dari 30
    insert(root, 40); // node 40 berada di sisi kanan dari 30
    insert(root, 60); // node 60 berada di sisi kiri dari 70
    insert(root, 80); // node 80 berada di sisi kanan dari 70

    cout << "Post-order traversal dari tree adalah: ";
    postOrderTraversal(root);
    cout << endl;

    return 0;
}
