#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

class MyNode {
    public:
    char data;
    int freq;
    MyNode *left, *right;

    MyNode(char data, int freq){
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

unordered_map<char, string> map1;

class compare {
    public:
    bool operator()(MyNode* l, MyNode* r){
        return (l->freq > r->freq);
    }
};


void printCode(MyNode* root, string str){
    if (root == NULL)
        return;

    if (root->data != '~'){
        cout << root->data << ": " << str << "\n";
        map1[root->data] = str;
    }

    printCode(root->left, str + "0");
    printCode(root->right, str + "1");
}


void HuffmanCode(char data[], int freq[], int size)
{
    struct MyNode *left, *right, *top;

    priority_queue<MyNode*, vector<MyNode*>, compare> minHeap;

    for (int i = 0; i < size; ++i)
        minHeap.push(new MyNode(data[i], freq[i]));

    // Iterating while size of heap doesn't become 1
    while (minHeap.size() != 1) {

        // Extract the two minimum freq items from heap
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        top = new MyNode('~', left->freq + right->freq);

        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    // Printing Huffman codes
    printCode(minHeap.top(), "");
}

int main()
{
    cout<<"Enter the number of characters: ";
    int n; cin>>n;
    char arr[n];
    int freq[n];
    cout<<"Enter the characters: \n";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Enter the frequencies: \n";
    for(int i=0; i<n; i++){
        cin>>freq[i];
    }

    cout<<"\nThe Huffman codes are: \n";
    HuffmanCode(arr, freq, n);

    //compressed format of the string
    cout<<"\nEnter a string: ";
    string s;
    cin>>s;
    cout<<"Compressed format: ";
    for(int i=0; i<s.size(); i++)
        cout<<map1[s[i]];

    return 0;
}
