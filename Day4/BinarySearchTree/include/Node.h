#ifndef NODE_H
#define NODE_H


class Node
{
    public:
        Node* left = NULL;
        Node* right = NULL;
        int data;

        Node(int data) {this->data = data;}

    protected:

    private:
};

#endif // NODE_H
