#include <iostream>

using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int value) {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BST {
private:
    Node* insertRec(Node* currNode, int value) {
        if (currNode == nullptr) {
            return new Node(value);
        }
        if (currNode -> value > value) {
            currNode -> left = insertRec(currNode->left, value);
        } else if (currNode -> value < value) {
            currNode -> right = insertRec(currNode->right, value);
        }
        return currNode;
    }
    bool isLeaf(Node* currNode) {
        return !(currNode->right || currNode->left);
    }
    bool oneChild(Node* currNode) {
        if (currNode->left && currNode->right) return false;
        return currNode->left || currNode->right;
    }
    Node* removeRec(Node* currNode, int value) {
        if (currNode == nullptr) {
            return nullptr;
        }
        if (currNode->value == value) {
            if (isLeaf(currNode)) {
                delete currNode;
                return nullptr;
            } else if (oneChild(currNode)) {
                Node* saved = nullptr;
                if (currNode -> left) {
                    saved = currNode-> left;
                    delete currNode;
                } else {
                    saved = currNode -> right;
                    delete currNode;
                }
                return saved;
            } else {
                Node* temp = currNode->left;
                while (temp->right != nullptr) {
                    temp = temp->right;
                }
                currNode->value = temp->value;
                currNode->left = removeRec(currNode->left, currNode->value);
            }
        } else if (currNode->value > value) {
            currNode->left = removeRec(currNode->left, value);
        } else {
            currNode->right = removeRec(currNode->right, value);
        }
        return currNode;
    }
    bool searchRec(Node* currNode, int value) {
        if (currNode == nullptr) {
            return false;
        }
        if (currNode->value == value) {
            return true;
        } else if (currNode->value > value) {
            return searchRec(currNode->left, value);
        } else {
            return searchRec(currNode->right, value);
        }
        return false;
    }
    int maxRec(Node* currNode) {
        if (currNode->right == nullptr) {
            return currNode->value;
        }
        return maxRec(currNode->right);
    }
    int minRec(Node* currNode) {
        if (currNode->left == nullptr) {
            return currNode->value;
        }
        return maxRec(currNode->left);
    }
    void inorderRec(Node* currNode) {
        if (currNode == nullptr) {
            return;
        }
        inorderRec(currNode->left);
        cout << currNode->value << " "; 
        inorderRec(currNode->right);
    }

    void preorderRec(Node* currNode) {
        if (currNode == nullptr) {
            return;
        }
        cout << currNode -> value << " "; 
        preorderRec(currNode -> left);
        preorderRec(currNode -> right);
    }
    void postorderRec(Node* currNode) {
        if (currNode == nullptr) {
            return;
        }
        postorderRec(currNode -> left);
        postorderRec(currNode -> right);
        cout << currNode -> value << " "; 
    }
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    int fillGst(Node* node, int currSum) {
        if (node == nullptr) {
            return currSum;
        }
        currSum = fillGst(node->right, currSum);
        currSum += node->value;
        cout << currSum << endl;
        node->value = currSum;
        currSum = fillGst(node->left, currSum);
        return currSum;
    }

    void insert(int value) {
        root = insertRec(root, value);
    }

    void remove(int value) {
        root = removeRec(root, value);
    }

    int max() {
        Node* currNode = this->root;
        return maxRec(currNode);
    } 

    int min() {
        Node* currNode = this->root;
        return minRec(currNode);
    } 

    bool search(int value) {
        Node* currNode = this->root;
        return searchRec(currNode, value);
    }

    void inorder() {
        Node* currNode = this->root;
        inorderRec(currNode);
    }

    void inorder(Node* node, vector<int> &values) {
        if (node == nullptr) {
            return;
        }
        inorder(node->left, values);
        values.push_back(node->value);
        inorder(node->right, values);
    }


    void preorder() {
        Node* currNode = this->root;
        preorderRec(currNode);
    }

    void postorder() {
        Node* currNode = this->root;
        postorderRec(currNode);
    }
};

Node* doBalanced(vector<int>& arr, int left, int right) {
    if (left > right) return nullptr;

    int mid = left + (right - left) / 2;
    
    Node* node = new Node(arr[mid]);
    node -> left = doBalanced(arr, left, mid - 1);
    node -> right = doBalanced(arr, mid + 1, right);
    return node;
}

int main() {
    BST* tree = new BST();

    tree->insert(1);
    tree->insert(2);
    tree->insert(3);
    tree->insert(4);

    tree->inorder();
    cout << endl;

    vector<int> values;

    Node* currNode = tree->root;
    tree->inorder(currNode, values);

    for (int i=0; i < values.size(); ++i) {
        cout << values[i] << " ";
    }
    cout << endl;

    Node* balancedNode = doBalanced(values, 0, values.size()-1);

    BST* newTree = new BST();
    newTree->root = balancedNode;

    newTree -> inorder();

    return 0;
}