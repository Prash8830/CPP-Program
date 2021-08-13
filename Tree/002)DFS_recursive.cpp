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
    if (element.size() == 0)
        return NULL;
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

/*notes - DFS has three major node traversals which contain :
        1) Inorder - Left Root Right
        2) Preorder - Root Left Right
        3) Postorder - Left Right Root
  It can be done by recursive or iterative aproach 
  But in this file we will see recursive approach for all three      
*/

void inorder(node *root) //left root right
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->value << " "; //root
        inorder(root->right);
    }
}
void preorder(node *root) //root left right
{
    if (root != NULL)
    {
        cout << root->value << " "; //root
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(node *root) //left right root
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->value << " "; //root
    }
}

int main()
{
    fio;

    //input tree
    node *root = tree();
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    return 0;
}