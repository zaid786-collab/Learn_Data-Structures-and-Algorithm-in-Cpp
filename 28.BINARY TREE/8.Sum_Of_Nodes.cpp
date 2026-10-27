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

int sum (Node* root) {
    if(root == NULL) {
        return 0;
    }

    int leftsum = sum(root->left);
    int rightsum = sum(root->right);

    int currsum = leftsum + rightsum + root->data;

    return currsum;
}

int main () {   
    vector<int> nodes = {1,2,3,-1,-1,-1,4,-1,7,-1,-1};

    Node* root = buildtree(nodes);

    cout << "Sum of Nodes : "<< sum(root) << endl;

    return 0;
}