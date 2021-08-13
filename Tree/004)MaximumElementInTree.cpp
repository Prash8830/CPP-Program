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

int maximum(node *root)
{
    if (root == NULL)
        return INT_MIN;
    else
        return max({root->value, maximum(root->left), maximum(root->right)});
}

int main()
{
    fio;

    node *root = tree();

    cout << maximum(root);

    return 0;
}