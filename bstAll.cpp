#include <iostream>
using namespace std;

struct node
{
private:
    int data;
    node* left, *right;
    static node* root;
public:
    node(int val) { data = val; this->left = this->right = nullptr; }
    static void insert(int, node* addThis=nullptr, node* temp = root);
    static void print(node* temp = root);
    static void deleteNode(int, node* prev = root, node* curr = root);


};

node* node::root = nullptr;

int main()
{
    node::insert(6);
    node::insert(4);
    node::insert(5);
    node::insert(8);
    node::insert(7);
    node::insert(1);
    node::insert(2);
    node::insert(0);
    
    cout << "BST: ";
    node::print();
    cout << endl;

    node::deleteNode(6);
    node::deleteNode(4);
    node::deleteNode(5);
    node::deleteNode(8);
    node::deleteNode(7);
    node::deleteNode(1);
    node::deleteNode(2);
    node::deleteNode(0);

    cout << "BST: ";
    node::print();
    cout << endl;

    return 0;
}

void node::insert(int val, node* addThis, node* temp)
{
    if(temp == nullptr)
        root = new node(val);

    else if(val <= temp->data)
        if(temp->left != nullptr)
            insert(val, addThis, temp->left);
        else
            if(addThis != nullptr)
                temp->left = addThis;
            else
                temp->left = new node(val);
    else
        if(temp->right != nullptr)
            insert(val, addThis, temp->right);
        else
            temp->right = new node(val);
}

void node::print(node* temp)
{
    if(temp==nullptr)
        return;

    print(temp->left);
    cout << temp->data << " ";
    print(temp->right);
}

void node::deleteNode(int val, node* prev, node* curr)
{
    if(curr == nullptr)
    {
        return;
    }

    else if(val < curr->data)
    {
        if(curr->left != nullptr)
        {
            deleteNode(val, curr, curr->left);
        }
    }
    else if(val > curr->data)
    {
        if(curr->right != nullptr)
        {
            deleteNode(val, curr, curr->right);
        }
    }
    else if(val == curr->data)
    {
        if(curr->left == nullptr && curr->right == nullptr)
        {
            if(curr == root)
            {
                root = nullptr;
            }
            else if(curr == prev->right)
                prev->right = nullptr;
            else
                prev->left = nullptr;

            delete curr;
        }
        else if(curr->left != nullptr && curr->right != nullptr)
        {
            node::insert(curr->left->data, curr->left, curr->right);
            if(curr == root)
            {
                root = curr->right;
            }
            else
            {
                if(prev->left == curr)
                {
                    prev->left = curr->right;
                }
                else
                    prev->right = curr->right;
            }
            delete curr;
        }
        else if(curr->left != nullptr)
        {
            if(root == curr)
            {
                root = curr->left;
            }
            else if(curr->data > prev->data)
            {
                prev->right = curr->left;
            }
            else
            {
                prev->left = curr->left;
            }
            delete curr;
        }
        else
        {
            if(root == curr)
            {
                root = curr->right;
            }
            else if(curr->data > prev->data)
            {
                prev->right = curr->right;
            }
            else
            {
                prev->left = curr->right;
            }
            delete curr;
        }
    }
}