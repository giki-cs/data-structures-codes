#include <iostream>
using namespace std;

class node
{
private:
    int data;
    node *left, *right;

    static node* root;

public:
    node(int val) { data = val; left = right = nullptr; }
    static void insert(int val, node*& curr = root, node* addThis=root);
    static void deleteNode(int val, node* curr=root, node*& prev=root);
    static void print(node*& curr = root);
};

node* node::root = nullptr;

int main()
{
    node::insert(6);
    node::insert(7);
    node::insert(5);
    node::insert(24);
    node::insert(8);
    node::insert(10);
    node::insert(75);
    node::insert(554);

    cout << "Before: ";
    node::print();

    // node::deleteNode(75);
    // cout << "\nAfter: \n";
    // node::print();

    node::deleteNode(24);
    cout << "\nAfter: \n";
    node::print();



    return 0;
}

void node::print(node*& curr)
{
    if(curr==nullptr)
        return;

    print(curr->left);
    cout << curr->data << " ";
    print(curr->right);
}

void node::deleteNode(int val, node* curr, node*& prev)
{
    if(val == curr->data)
    {
        //no child
        if(curr->left == nullptr && curr->right == nullptr)
        {
            if(val < prev->data)
            { 
                prev->left = nullptr;
            }
            else
            {
                prev->right = nullptr;
            }

            delete curr;
        }
        //double
        else if(curr->left != nullptr && curr->right != nullptr)
        {
            insert(curr->left->data, curr->right, curr->left);
            curr->left = nullptr;
            
            if(curr->data < prev->data)
            {
                prev->left = curr->right;
            }
            else
            {
                prev->right = curr->right;
            }

            curr->right = nullptr;

            delete curr;
        }
        else if(curr->left != nullptr)
        {
            if(curr->data < prev->data)
            {
                prev->left = curr->left;
            }
            else
            {
                prev->right = curr->left;
            }

            delete curr;
        }
        else if(curr->right != nullptr)
        {
            if(curr->data < prev->data)
            {
                prev->left = curr->right;
            }
            else
            {
                prev->right = curr->right;
            }

            delete curr;
        }
    }
    else if(val < curr->data)
    {
        deleteNode(val, curr->left, curr);
    }
    else
        deleteNode(val, curr->right, curr);
}

void node::insert(int val, node*& curr, node* addThis)
{
    if(curr == nullptr)
    {
        if(addThis != root)
        {
            curr = addThis;
        }
        else
            curr = new node(val);
    }
    else if(val < curr->data)
    {
        insert(val, curr->left, addThis);
    }
    else
    {
        insert(val, curr->right, addThis);
    }
}