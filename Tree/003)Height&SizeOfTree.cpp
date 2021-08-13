#include <bits/stdc++.h>
using namespace std;

#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

struct node //structure of node
{
    int value;   //value of node
    node *left;  //left child reference
    node *right; //right child reference

    node(int v) //initialize value of node
    {
        value = v;
        left = right = NULL;
    }
};

node *constructTree(vector<string> element) //it will creat tree from node
{
    queue<node *> q;
    int i = 0;
    node *root = new node(stoi(element[i++]));
    q.push(root);
    while (q.size() != 0) //untill q is empty insert element make node set left right and push into queue
    {
        int s = q.size();
        while (s--)
        {
            node *curr = q.front();
            q.pop();
            if (i < element.size()) //for left
            {
                if (element[i] != "NULL")
                {
                    node *temp = new node(stoi(element[i++]));
                    curr->left = temp;
                    q.push(temp);
                }
                else
                    i++;
            }
            if (i < element.size()) //for right
            {
                if (element[i] != "NULL")
                {
                    node *temp = new node(stoi(element[i++]));
                    curr->right = temp;
                    q.push(temp);
                }
                else
                    i++;
            }
        }
    }
    return root;
}
node *tree() //tree
{
    int n;
    cin >> n;
    vector<string> nodes(n);
    for (int i = 0; i < n; i++) //Note --> if you want NULL value then insert NULL
    {
        cin >> nodes[i];
    }
    node *root = constructTree(nodes);
    return root;
}

int heightR(node *root)
{
    if (root == NULL)
        return 0;
    else
        return max(heightR(root->left), heightR(root->right)) + 1;
}

int heightI(node *root)
{
    if (root == NULL)
        return 0;
    queue<node *> q;
    q.push(root);
    int height = 0;
    while (q.size() != 0)
    {
        int s = q.size();
        height++;
        for (int i = 0; i < s; i++)
        {
            node *curr = q.front();
            q.pop();
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
    }
    return height;
}
int sizeR(node *root)
{
    if (root == NULL)
        return 0;
    else
        return (sizeR(root->left) + sizeR(root->right)) + 1;
}

int sizeI(node *root)
{
    if (root == NULL)
        return 0;
    queue<node *> q;
    q.push(root);
    int size = 0;
    while (q.size() != 0)
    {
        int s = q.size();
        size += s;
        for (int i = 0; i < s; i++)
        {
            node *curr = q.front();
            q.pop();
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
    }
    return size;
}

int main()
{
    fio;

    node *root = tree();
    //recursive
    cout << heightR(root) << endl;
    //iterative
    cout << heightI(root) << endl;
    //recursive
    cout << sizeR(root) << endl;
    //iterative
    cout << sizeI(root) << endl;

    return 0;
}