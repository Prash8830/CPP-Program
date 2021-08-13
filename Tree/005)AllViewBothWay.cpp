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

int levelrichL = 0;
void leftviewR(node *root, int currlevel)
{
    if (root == NULL)
        return;
    if (levelrichL == currlevel)
    {
        cout << root->value << " ";
        levelrichL++;
    }
    leftviewR(root->left, currlevel + 1);
    leftviewR(root->right, currlevel + 1);
}
int levelrichR = 0;
void rightviewR(node *root, int currlevel)
{
    if (root == NULL)
        return;
    if (levelrichR == currlevel)
    {
        cout << root->value << " ";
        levelrichR++;
    }
    rightviewR(root->right, currlevel + 1);
    rightviewR(root->left, currlevel + 1);
}
void leftviewI(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    while (q.size() != 0)
    {
        cout << q.front()->value << " ";
        int s = q.size();
        while (s--)
        {
            node *curr = q.front();
            q.pop();
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
    }
}
void rightviewI(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    while (q.size() != 0)
    {
        cout << q.back()->value << " ";
        int s = q.size();
        while (s--)
        {
            node *curr = q.front();
            q.pop();
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
    }
}
//top view
unordered_map<int, pair<int, int>> m;
int mini = INT_MAX;
int maxi = INT_MIN;

void topviewR(node *root, int currlevel, int h)
{
    if (root == NULL)
        return;
    if (m.find(currlevel) == m.end())
    {
        int j = root->value;
        pair<int, int> p(j, h);
        m[currlevel] = p;
    }
    else
    {
        if (h < m[currlevel].second)
        {
            int j = root->value;
            pair<int, int> p(j, h);
            m[currlevel] = p;
        }
    }

    topviewR(root->left, currlevel - 1, h + 1);
    topviewR(root->right, currlevel + 1, h + 1);
    mini = min(mini, currlevel);
    maxi = max(maxi, currlevel);
}

unordered_map<int, pair<int, int>> mb;
int minib = INT_MAX;
int maxib = INT_MIN;

void bottomviewRecursion(node *root, int currlevel, int h)
{
    if (root == NULL)
        return;
    if (mb.find(currlevel) == mb.end())
    {
        int j = root->value;
        pair<int, int> p(j, h);
        mb[currlevel] = p;
    }
    else
    {
        if (h > mb[currlevel].second)
        {
            int j = root->value;
            pair<int, int> p(j, h);
            mb[currlevel] = p;
        }
    }

    bottomviewRecursion(root->left, currlevel - 1, h + 1);
    bottomviewRecursion(root->right, currlevel + 1, h + 1);
    minib = min(minib, currlevel);
    maxib = max(maxib, currlevel);
}
int main()
{
    fio;

    node *root = tree();

    leftviewR(root, 0);
    cout << endl;
    leftviewI(root);
    cout << endl;
    rightviewR(root, 0);
    cout << endl;
    rightviewI(root);
    cout << endl;
    topviewR(root, 0, 0);
    for (int i = mini; i <= maxi; i++)
    {
        cout << m[i].first << " ";
    }
    bottomviewRecursion(root, 0, 0);
    for (int i = minib; i <= maxib; i++)
    {
        cout << mb[i].first << " ";
    }

    return 0;
}