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

Node* buildtree(vector<int> nodes) {
    index++;

    if(nodes[index] == -1) {
        return NULL;
    }

    Node* curr = new Node(nodes[index]);
    curr->left = buildtree(nodes);
    curr->right = buildtree(nodes);

    return curr;
}

bool identical (Node* root1, Node* root2) {
    if(root1 == NULL && root2 == NULL) {
        return true;
    } else if(root1 == NULL || root2 == NULL) {
        return false;
    }


    if(root1->data != root2->data) {
        return false;
    }

    return identical(root1->left, root2->left) && identical(root1->right, root2->right);
}


bool isSubtree(Node* root, Node* subRoot) {
    if(root == NULL && subRoot == NULL) {
        return true;
    } else if(root == NULL || subRoot == NULL) {
        return false;
    }

    if(root->data == subRoot->data) {
        if(identical(root,subRoot)) {
            return true;
        }
    }

    bool isleftsubtree = isSubtree(root->left,subRoot);

    if(!isleftsubtree) {
        return isSubtree(root->right, subRoot);
    }

    return true;
}

int main () {
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildtree(nodes);

    // cout << root->data << endl;

    Node* subRoot = new Node(2);
    subRoot->left = new Node(4);
    subRoot->right = new Node(5);

    cout << isSubtree(root,subRoot) << endl;

    return 0;
}