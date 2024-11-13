#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

struct MinHeapNode
{
    char data;
    int freq;
    MinHeapNode *left, *right;

    MinHeapNode(char data, int freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

struct compare
{
    bool operator()(MinHeapNode *l, MinHeapNode *r)
    {
        return (l->freq > r->freq);
    }
};

void printCodes(MinHeapNode *root, string str, unordered_map<char, string> &huffmanCode)
{
    if (!root)
        return;
    if (root->data != '$')
    {
        huffmanCode[root->data] = str;
        cout << root->data << ": " << str << "\n";
    }
    printCodes(root->left, str + "0", huffmanCode);
    printCodes(root->right, str + "1", huffmanCode);
}

string encodeString(string &input, unordered_map<char, string> &huffmanCode)
{
    string encodedString;
    for (int i = 0; i < input.length(); i++)
    {
        char ch = input[i];
        encodedString += huffmanCode.at(ch);
    }
    return encodedString;
}

void HuffmanCodes(char data[], int freq[], int size)
{
    MinHeapNode *left, *right, *top;
    priority_queue<MinHeapNode *, vector<MinHeapNode *>, compare> minHeap;

    for (int i = 0; i < size; ++i)
        minHeap.push(new MinHeapNode(data[i], freq[i]));

    while (minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }

    unordered_map<char, string> huffmanCode;
    printCodes(minHeap.top(), "", huffmanCode);

    string input;
    cout << "Enter the string to encode: ";
    cin >> input;
    string encodedString = encodeString(input, huffmanCode);
    cout << "Encoded String: " << encodedString << endl;
}

int main()
{
    int size;
    cout << "Enter the number of characters: ";
    cin >> size;

    char *arr = new char[size];
    int *freq = new int[size];

    cout << "Enter the characters:\n";
    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }

    cout << "Enter the corresponding frequencies:\n";
    for (int i = 0; i < size; ++i)
    {
        cin >> freq[i];
    }

    HuffmanCodes(arr, freq, size);

    delete[] arr;
    delete[] freq;

    return 0;
}