//Avl Trees Changed

#include <iostream>
using namespace std;

struct node
{
private:
    int data;
    node* left, *right;
    static node* root;
    static node* balanceNode(node*);
public:
    node(int val) { data = val; this->left = this->right = nullptr; }
    static void insert(int, node* curr=root);
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

void node::insert(int val, node* curr)
{
    static bool done = false;

    if(curr == root)
        root = new node(val);
    else if(val <= curr->data)
    {
        if(curr->left != nullptr)
        {
            insert(val, curr->left);
        }
        else
        {
            curr->left = new node(val);
            curr = curr->left;
        }
    }
    else if(val > curr->data)
    {
        if(curr->right != nullptr)
        {
            insert(val, curr->right);
        }
        else
        {
            curr->right = new node(val);
            curr = curr->right;
        }
    }

    if(!done)
    {
        if(balanceNode(curr) == nullptr) return;
        else
        {
            done = true;

            //3 cases
            //left left
            // if(curr->left != nullptr)
            // {
            //     if(curr->left->left->data == val)
            //     {

            //     }
            //     else if(curr->left->right-> == val)
            //     {

            //     } 
            // }
            // else if(curr->right != nullptr)
            // {
            //     if(curr->right->right->data == val)
            //     {

            //     }
            // }

            //right right

            //right left

            //left right
        }
    }
}

node* node::balanceNode(node* curr)
{
    static int leftCount = 0;
    static int rightCount = 0;

    if(curr == nullptr)
        return nullptr;
    
    if(curr->left != nullptr)
    {
        ++leftCount;
        //balanceNode(curr->left);
    }
    
    if(curr->right != nullptr)
    {
        ++rightCount;
        //balanceNode(curr->right);
    }

    if(leftCount-rightCount <= 1 || leftCount-rightCount >= -1)
        return nullptr;
    
    return curr;
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
            //node::insert(curr->left->data, curr->left, curr->right);
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
