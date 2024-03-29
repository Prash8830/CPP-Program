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
                if (element[i] != "N")
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
                if (element[i] != "N")
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

bool ChildrenSumProperty(node *root)
{
    if (root == NULL) //for null values
        return true;
    if (root->left == NULL && root->right == NULL) //for left children
        return true;
    int sum = 0;
    if (root->left != NULL) //for some missing childrens
        sum += root->left->value;
    if (root->right != NULL)
        sum += root->right->value;
    return (sum == root->value) && (ChildrenSumProperty(root->left)) && (ChildrenSumProperty(root->right));
}

//time complexity =  ◯ n
//Auxillary Space time complexity =  ◯ h

int main()
{
    fio;

    node *root = tree();

    cout << ChildrenSumProperty(root);

    return 0;
}