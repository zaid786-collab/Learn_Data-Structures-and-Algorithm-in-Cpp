#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node (int data) {
        this->data = data;
        left = right = NULL;
    }
};

static int index = -1;
Node* buildtree (vector<int> nodes) {
    index++;

    if(nodes[index] == -1) {
        return NULL;
    }

    Node* currnode = new Node(nodes[index]);
    currnode->left = buildtree(nodes);
    currnode->right = buildtree(nodes);

    return currnode;
}

int height (Node* root) {
    if(root == NULL) {
        return 0;
    }

    int leftht = height(root->left);
    int rightht = height(root->right);

    int currht = max(leftht ,rightht) + 1;

    return currht;
}

int diameter (Node* root) {
    if(root ==  NULL) {
        return 0;
    }

    int currdiameter = height(root->left) + height(root->right) + 1;
    int leftdiameter = diameter(root->left);
    int rightdiameter = diameter(root->right);

    return max(currdiameter,max(leftdiameter,rightdiameter));
}

int main () {
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildtree(nodes);

    cout << "Height of a Tree : " << height(root) << endl;

    cout << "Diameter of a Tree is : " << diameter(root) << endl;
    return 0;
}