#ifndef TREE_H
#define TREE_H
#include "Node.h"
#include "Queue.h"

using namespace std;

class Tree
{
    public:
        Node* root = NULL;
        Tree() {}

        void add(int data) {
            Node* newNode = new Node(data);
            Node* parent;

            if (root == NULL)
                root = newNode;
            else {
                Node* current = root;

                while (current != NULL) {
                    parent = current;

                    if (newNode->data > current->data)
                        current = current->right;
                    else
                        current = current->left;
                }

                if (newNode->data > parent->data)
                    parent->right = newNode;
                else
                    parent->left = newNode;
            }
        }

        void remove(int data) {
            Node* node = getNode(data);

            if (node == NULL) return;

            if (node == root) {
                if (root->left == NULL && root->right == NULL)
                    root = NULL;
                else if (root->left == NULL)
                    root = root->right;
                else if (root->right == NULL)
                    root = root->left;
                else {
                    // get first left child (FLC)
                    Node* flc = root->left;

                    // get first right child (FRC)
                    Node* frc = root->right;

                    // get max right child of (FLC)
                    Node* maxRightNode = getMaxRightNode(flc);

                    //maxRight => right ----- first right child
                    maxRightNode->right = frc;

                    root = flc;
                }
            } else {
                Node* parent = getNodeParent(node);
                Node* newChild;

                if (node->left == NULL && node->right == NULL)
                    newChild = NULL;
                else if (node->left == NULL)
                    newChild = node->right;
                else if (node->right == NULL)
                    newChild = node->left;
                else {
                    // get first left child (FLC)
                    Node* flc = node->left;

                    // get first left child (FRC)
                    Node* frc = node->right;

                    // get max right child of (FLC)
                    Node* maxRightNode = getMaxRightNode(flc);

                    //maxRight => right ----- first right child
                    maxRightNode->right = frc;

                    newChild = flc;
                }

                if (parent->left == node)
                    parent->left = newChild;
                else
                    parent->right = newChild;
            }
        }

        /*
        Traversal Tree
        Order
        LDR ==> Left Data Right
        RDL ==> Right Data Left
        */

        void displayAll() {
            Queue queu;

            sortTreeAsc(root, queu);

            queu.display();
        }

        void getMin() {
            Queue queu;

            sortTreeAsc(root, queu);

            cout << "Min value in tree is: " << queu.peakFirst() << endl;
        }

        void getMax() {
            Queue queu;

            sortTreeDesc(root, queu);

            cout << "Max value in tree is: " << queu.peakFirst() << endl;
        }

    protected:

    private:
        Node* getNode(int data) {
            Node* current = root;

            while (current != NULL) {
                if (current->data == data)
                    return current;
                else if (data > current->data)
                    current = current->right;
                else
                    current = current->left;
            }

            return NULL;
        }

        Node* getNodeParent(Node* node) {
            Node* parent = root;

            while (parent != NULL) {
                if (parent->left == node || parent->right == node)
                    return parent;
                else if (node->data > parent->data)
                    parent = parent->right;
                else
                    parent = parent->left;
            }

            return NULL;
        }

        void display(Node* node) {
            if (node == NULL)
                return;

            display(node->left);

            cout << node->data << "\t";

            display(node->right);
        }

        void sortTreeAsc(Node* node, Queue& queu) {
            if (node == NULL)
                return;

            sortTreeAsc(node->left, queu);

            queu.enqueue(node->data);

            sortTreeAsc(node->right, queu);
        }

        void sortTreeDesc(Node* node, Queue& queu) {
            if (node == NULL)
                return;

            sortTreeDesc(node->right, queu);

            queu.enqueue(node->data);

            sortTreeDesc(node->left, queu);
        }

        Node* getMaxRightNode(Node* node) {
            Node* current = node;

            while (current->right != NULL) {
                current = current->right;
            }

            return current;
        }

        Node* getMaxLeftNode(Node* node) {
            Node* current = node;

            while (current->left != NULL) {
                current = current->left;
            }

            return current;
        }
};

#endif // TREE_H
