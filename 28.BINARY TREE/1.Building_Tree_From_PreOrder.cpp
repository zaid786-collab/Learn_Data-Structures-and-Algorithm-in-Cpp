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

Node* buildtree(vector<int>& nodes){
    index++;

    if(nodes[index] == -1){
        return NULL;
    }

    Node* currnode = new Node(nodes[index]);
    currnode->left = buildtree(nodes);
    currnode->right = buildtree(nodes);

    return currnode;
}

int main () {
    vector<int> nodes = {1,2,3,-1,-1,6,-1,-1,9,-1,-1,4,5,-1,-1};
    Node* root = buildtree(nodes);

    cout << root->data << endl;

    return 0;
}