//Avl Trees Changed

#include <iostream>
using namespace std;

struct node
{
private:
    static node* balanceNode(node*);
public:
    int diff;
    node* left, *right;
    static node* root;
    int data;
    node(int val) { data = val; this->left = this->right = nullptr; diff = 0; }
    static void insert(int, node*& curr=root);
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
    
    cout << "root " << node::root << " " << node::root->data << " " << node::root->left << " " << node::root->right << " " << node::root->diff << endl;
    cout << "left " << node::root->left << " " << node::root->left->data << " " << node::root->left->left << " " << node::root->left->right << " " << node::root->left->diff << endl;
    cout << "right " << node::root->right << " " << node::root->right->data << " " << node::root->right->left << " " << node::root->right->right << " " << node::root->right->diff << endl;
    // node::insert(7);
    // node::insert(12);
    // node::insert(2);
    // node::insert(0);
    
    cout << "AVL: ";
    node::print();
    cout << endl;

    cout << "AVL: ";
    node::print();
    cout << endl;

    return 0;
}

void node::insert(int val, node*& curr)
{
    static int l = 0;
    static int r = 0;
    static bool notBalanced = 0;
    static node* notBalancedNode = nullptr;
    static char firstOne = 'l';

    if(curr==nullptr)
    {
        curr = new node(val);
        return;
    }

    if(val <= curr->data)
    {
        ++curr->diff;
    }
    else
        --curr->diff;

    if(curr->diff == 2 || curr->diff == -2)
    {
        notBalanced = true;
        notBalancedNode = curr;
        if(val <= curr->data)
        {
            firstOne = 'l';
        }
        else
            firstOne = 'r';
    }

    if(val <= curr->data)
    {
        if(notBalanced) ++l;
        insert(val, curr->left);
    }
    else
    {
        if(notBalanced) ++r;
        insert(val, curr->right);
    }

    if(notBalancedNode == curr)
    {
        node* temp;
        if( l == 2 ) // means l-l
        {
            temp = curr->left;
            temp->right = curr;
            curr->left = nullptr;
        }
        else if( r == 2 ) // means r-r
        {
            cout << "a";
        }
        else
        {
            if(firstOne == 'l') // means l-r
            {
                temp = curr->left->right;
                temp->right = curr;
                temp->left = curr->left;
                curr->left->right = nullptr;
                curr->left = nullptr;
                ++temp->left->diff;
                
            }
            else // means r-l
            {
                cout << "a";
            }
        }
        l = r = notBalanced = curr->diff = 0;

        if(curr == root)
            root = temp;   
    }
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
