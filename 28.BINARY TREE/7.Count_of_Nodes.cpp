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
Node* buildTree(vector<int> nodes) {
    index++;

    if(nodes[index] == -1) {
        return NULL;
    }

    Node* currnode = new Node(nodes[index]);
    currnode->left = buildTree(nodes);
    currnode->right = buildTree(nodes);

    return currnode;
}

int count (Node* root) {
    if(root == NULL) {
        return 0;
    }

    int leftct = count(root->left);
    int rightct = count(root->right);

    int currct = rightct + leftct + 1;

    return currct;
}

int main () {
    vector<int> nodes = {1,2,4,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};
    Node* root = buildTree(nodes);

    cout << "Number of Nodes in a Tree is : " << count(root) << endl;
    return 0;
}