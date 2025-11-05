#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Node class for Huffman Tree
class Node {
public:
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

// Comparator for PriorityQueue (min-heap)
struct CompareFreq {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq; // smaller freq has higher priority
    }
};

// Recursive function to print Huffman Codes
void printCodes(Node* root, string code) {
    if (root == nullptr)
        return;

    // If leaf node
    if (root->left == nullptr && root->right == nullptr) {
        cout << root->ch << " : " << code << endl;
        return;
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

// Function to build Huffman Tree
void buildHuffmanTree(vector<char>& chars, vector<int>& freq, int n) {
    priority_queue<Node*, vector<Node*>, CompareFreq> pq;

    // Step 1: Create leaf nodes
    for (int i = 0; i < n; i++) {
        pq.push(new Node(chars[i], freq[i]));
    }

    // Step 2: Build the tree
    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        Node* newNode = new Node('-', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    // Step 3: Print Huffman Codes
    cout << "\nHuffman Codes:\n";
    printCodes(pq.top(), "");
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    vector<char> chars(n);
    vector<int> freq(n);

    cout << "Enter characters:\n";
    for (int i = 0; i < n; i++)
        cin >> chars[i];

    cout << "Enter their frequencies:\n";
    for (int i = 0; i < n; i++)
        cin >> freq[i];

    buildHuffmanTree(chars, freq, n);

    return 0;
}
