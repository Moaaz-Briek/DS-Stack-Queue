#ifndef QUEUENODE_H
#define QUEUENODE_H


class QueueNode
{
    public:
        int data;
        QueueNode* next = NULL;
        QueueNode(int data) {this->data = data;}

    protected:

    private:
};

#endif // QUEUENODE_H
