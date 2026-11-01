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

Node* buildtree(vector<int> Nodes) {
    index++;

    if(Nodes[index] == -1) {
        return NULL;
    }

    Node* currnode = new Node(Nodes[index]);
    currnode->left = buildtree(Nodes);
    currnode->right = buildtree(Nodes);

    return currnode;
}

int height (Node* root) {
    if(root == NULL) {
        return 0;
    }

    int leftht = height(root->left);
    int rightht = height(root->right);

    return max(leftht, rightht) + 1;
}

pair<int, int> diameter(Node* root) {
    if(root == NULL) {
        return make_pair(0,0);
    }
    
    // ( Diameter,Height )
    pair<int,int> leftinfo = diameter(root->left);
    pair<int,int> rightnfo = diameter(root->right);

    int currdiameter = leftinfo.second + rightnfo.second + 1;

    int finaldm = max(currdiameter, max(leftinfo.first, rightnfo.first));
    int finalht = max(leftinfo.second , rightnfo.second) + 1;

    return make_pair(finaldm , finalht);
}

int main () {
    vector<int> Nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildtree(Nodes);

    cout << "Height of a Tree : " << diameter(root).second << endl;

    cout << "Diameter of a Tree is : " << diameter(root).first << endl;
    return 0;
}