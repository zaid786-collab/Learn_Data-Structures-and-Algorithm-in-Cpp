#include<bits/stdc++.h>
using namespace std;

class NODE {
public:
    int data;
    NODE* left;
    NODE* right;

    NODE(int data) {
        this->data = data;
        left = right = NULL;
    }
};

static int index = -1;

NODE* maketree (vector<int> nodes) {
    index++;

    if(nodes[index] == -1) {
        return NULL;
    }

    NODE* currnode = new NODE(nodes[index]);
    currnode->left = maketree(nodes);
    currnode->right = maketree(nodes);

    return currnode;
}

void preorder (NODE* root) {
    if(root == NULL) {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main () {
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    NODE* root = maketree(nodes);

    cout << root->left->data << endl;
    preorder(root);

    return 0;
}