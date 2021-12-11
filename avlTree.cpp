#include <iostream>
using namespace std;

class avlNode
{
private:
    int height;
    int data;
    avlNode *left, *right;

    static avlNode* root;

public:
    avlNode(int val): data(val), left(nullptr), right(nullptr), height(0) {} // initialize (not assign)
    static void insert(int val, avlNode*& curr = root, avlNode*& prev=root);
    static int heightOf(avlNode*& curr) { if(!curr) return -1; return curr->height; }
    static avlNode* lr(avlNode*& curr);
    static avlNode* rr(avlNode*& curr);
    static avlNode* rl(avlNode*& curr);
    static avlNode* ll(avlNode*& curr);
    static void setHeight(avlNode*& curr);
};

avlNode* avlNode::root = nullptr;

int main()
{

    return 0;
}

void avlNode::insert(int val, avlNode*& curr, avlNode*& prev)
{
    if(curr == nullptr)
    {
        curr = new avlNode(val);
    }
    else if(val < curr->data)
    {
        insert(val, curr->left, curr);
        curr->height = heightOf(curr->left) - heightOf(curr->right);

        if(curr->height == 2)
        {
            if(heightOf(curr->right) == -1)
            {
                //ll
                prev->left = ll(curr);

            }
            else
            {
                //lr
                prev->left = lr(curr);
            }
        }
    }
    else // take care for duplicate data
    {
        insert(val, curr->right, curr);
        curr->height = heightOf(curr->right) - heightOf(curr->left);

        if(curr->height == 2)
        {
            //rr or //rl
            if(heightOf(curr->right) == 1)
            {

            }
            else
            {
                curr->right = rl(curr);
                prev->right = rr(curr);
            }
        }
    }
}

avlNode* avlNode::lr(avlNode*& curr)
{
    avlNode* b = curr->left;
    avlNode* c = b->right;

    b->right = c->left;
    c->left = b;

    return c;
}

avlNode* avlNode::rl(avlNode*& curr)//done
{
    avlNode* b = curr->right;
    avlNode* c = b->left;

    b->left = c->right;
    c->right = b;

    setHeight(b);
    setHeight(c);
    setHeight(curr);

    return c;
}

avlNode* avlNode::ll(avlNode*& curr)//done
{
    avlNode* b = curr->left;

    curr->left = b->right;
    b->right = curr;

    setHeight(curr);
    setHeight(b);

    return b;
}

avlNode* avlNode::rr(avlNode*& curr)//done
{
    avlNode* b = curr->right;

    curr->right = b->left;
    b->left = curr;

    setHeight(curr);
    setHeight(b);

    return b;
}

void avlNode::setHeight(avlNode*& curr)
{
    curr->height = heightOf(curr->left) - heightOf(curr->right);
}