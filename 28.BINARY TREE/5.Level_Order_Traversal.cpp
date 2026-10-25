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
Node* buildtree(vector<int> nodes) {
    index++;

    if(nodes[index] == -1) {
        return NULL;
    }

    Node* currnode = new Node(nodes[index]);
    currnode->left = buildtree(nodes);
    currnode->right = buildtree(nodes);

    return currnode;
}

void levelorder(Node* root) {
    if(root == NULL) {
        return;
    }
    queue<Node*> Q;
    Q.push(root);

    Q.push(NULL);


    while(!Q.empty()) {
        Node* currnode = Q.front();
        Q.pop();

        if(currnode == NULL) {
            cout << endl;
            if(Q.empty()) {
                break;
            }
            Q.push(NULL);
        } else {
            cout << currnode->data << " ";

            if(currnode->left != NULL) {
                Q.push(currnode->left);
            }
            if(currnode->right != NULL) {
                Q.push(currnode->right);
            }
        }
    }
}

int main () {
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildtree(nodes);

    cout << root->left->data << endl;
    levelorder(root);
    return 0;
}