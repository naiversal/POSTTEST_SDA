#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

void push(Node*& top, char data) {
    Node* newNode = new Node{data, top};
    top = newNode;
}

char pop(Node*& top) {
    if (top == nullptr) return '\0';
    Node* temp = top;
    char poppedValue = temp->data;
    top = top->next;
    delete temp;
    return poppedValue;
}

bool areBracketsBalanced(string expr) {
    Node* stackTop = nullptr;

    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];
        
        // kurung buka -> push ke stack
        if (ch == '(' || ch == '{' || ch == '[') {
            push(stackTop, ch);
        }
        // kurung tutup -> cek pasangannya
        else if (ch == ')' || ch == '}' || ch == ']') {
            // kalau stack kosong tapi ada kurung tutup = tidak seimbang
            if (stackTop == nullptr) {
                return false;
            }
            
            char top = pop(stackTop);
            
            // cek apakah pasangan kurung cocok
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }

    // stack harus kosong di akhir (semua kurung buka sudah bertemu pasangannya)
    return (stackTop == nullptr);
}

int main() {
    string expr1 = "{[()]}";
    cout << expr1 << " -> " << (areBracketsBalanced(expr1) ? "Seimbang" : "Tidak Seimbang") << endl;
    
    string expr2 = "{[(])}";
    cout << expr2 << " -> " << (areBracketsBalanced(expr2) ? "Seimbang" : "Tidak Seimbang") << endl;

    return 0;
}
