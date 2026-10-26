#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

static int index = -1;
Node* buildTree(vector<int> nodes){
    index++;

    if(nodes[index] == -1) {
        return NULL;
    }

    Node* currnode = new Node(nodes[index]);
    currnode->left = buildTree(nodes);
    currnode->right = buildTree(nodes);

    return currnode;
}

int height (Node* root) {
    if(root == NULL) {
        return 0;
    }

    int leftht = height(root->left);
    int rightht = height(root->right);

    int currht = max(leftht,rightht) + 1;

    return currht;
}

int main () {
    // vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    vector<int> nodes = {1,2,4,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};
    Node* root = buildTree(nodes);

    cout << "Height of a Tree : " << height(root) << endl;
    return 0;
}