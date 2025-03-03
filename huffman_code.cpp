#include <iostream>
using namespace std;

// Huffman Tree Node
struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char ch, int freq, Node* left = nullptr, Node* right = nullptr) {
        this->ch = ch;
        this->freq = freq;
        this->left = left;
        this->right = right;
    }
};

// Traverse the Huffman Tree and store Huffman Codes
void encode(Node* root, string str, pair<char, string> huffmanCode[], int &index) {
    if (!root) return;
    
    if (!root->left && !root->right) {
        huffmanCode[index++] = {root->ch, str};
    }
    
    encode(root->left, str + "0", huffmanCode, index);
    encode(root->right, str + "1", huffmanCode, index);
}

// Build Huffman Tree and generate codes
void buildHuffmanTree(string text) {
    pair<char, int> freq[256] = {};
    int uniqueChars = 0;
    
    for (char ch : text) {
        if (freq[ch].second == 0) {
            freq[ch].first = ch;
            uniqueChars++;
        }
        freq[ch].second++;
    }
    
    Node* nodes[256];
    int nodeCount = 0;
    
    for (int i = 0; i < 256; i++) {
        if (freq[i].second > 0) {
            nodes[nodeCount++] = new Node(freq[i].first, freq[i].second);
        }
    }
    
    while (nodeCount > 1) {
        // Simple manual sorting
        for (int i = 0; i < nodeCount - 1; i++) {
            for (int j = i + 1; j < nodeCount; j++) {
                if (nodes[i]->freq > nodes[j]->freq) {
                    swap(nodes[i], nodes[j]);
                }
            }
        }
        
        Node* left = nodes[0];
        Node* right = nodes[1];
        
        for (int i = 2; i < nodeCount; i++) {
            nodes[i - 2] = nodes[i];
        }
        nodeCount -= 2;
        
        nodes[nodeCount++] = new Node('\0', left->freq + right->freq, left, right);
    }
    
    Node* root = nodes[0];
    
    pair<char, string> huffmanCode[256];
    int index = 0;
    encode(root, "", huffmanCode, index);
    
    cout << "Huffman Codes:\n";
    for (int i = 0; i < index; i++) {
        cout << huffmanCode[i].first << " : " << huffmanCode[i].second << endl;
    }
}

int main() {
    string text;
    cout << "Enter text: ";
    getline(cin, text);
    
    buildHuffmanTree(text);
    
    return 0;
}
