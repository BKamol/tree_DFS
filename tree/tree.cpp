#include <fstream>
#include <iostream>
//17.7 а, б, в, д, е
using namespace std;

struct node
{
    int info;
    node* left;
    node* right;
};
typedef node* tinfo;

struct elem
{
    tinfo info;
    elem* next;
};
typedef elem* stack;

stack create_stack()
{
    stack top = NULL;

    return top;
}

void push(stack& top, tinfo info)
{
    stack q = new elem;
    q->next = top;
    q->info = info;
    top = q;
}

tinfo pop(stack& top)
{
    stack q = top;
    top = top->next;
    tinfo info = q->info;
    delete q;
    return info;
}

bool isEmpty(stack top)
{
    return top == NULL;
}

node* create_node(int x)
{
    node* p = new node;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void DFS(node* root)
{
    stack s = create_stack();
    node* p;
    push(s, root);

    while (!isEmpty(s))
    {
        p = pop(s);
        cout << p->info << ' ';
        if (p->right) push(s, p->right);
        if (p->left) push(s, p->left);
    }
    cout << endl;
}

int task_a(node* root)
{
    int E;
    node* p = root;
    while (p->left != NULL || p->right != NULL)
    {
        if (p->left) p = p->left;
        else p = p->right;
    }
    E = p->info;
    return E;
}

int task_b(node* root, int E)
{
    int c = 0;

    stack s = create_stack();
    node* p;
    push(s, root);

    while (!isEmpty(s))
    {
        p = pop(s);
        if (p->info == E) c++;
        if (p->right) push(s, p->right);
        if (p->left) push(s, p->left);
    }

    return c;
}

int sum(node* root)
{
    int sum = 0;

    stack s = create_stack();
    node* p;
    push(s, root);

    while (!isEmpty(s))
    {
        p = pop(s);
        sum += p->info;
        if (p->right) push(s, p->right);
        if (p->left) push(s, p->left);
    }

    return sum;
}

int count_nodes(node* root)
{
    int c = 0;
    stack s = create_stack();
    node* p;

    push(s, root);
    while (!isEmpty(s))
    {
        p = pop(s);
        c++;
        if (p->right != NULL) push(s, p->right);
        if (p->left != NULL) push(s, p->left);
        
    }
    return c;
}

double average(node* root)
{
    return sum(root)/count_nodes(root);
}

void replace_max_min(node* root)
{
    int min = root->info;
    int max = root->info;
    node* p;

    stack s = create_stack();
    push(s, root);
    while (!isEmpty(s))
    {
        p = pop(s);
        if (p->info < min) min = p->info;
        if (p->info > max) max = p->info;
        if (p->right) push(s, p->left);
        if (p->left) push(s, p->right);
    }

    push(s, root);
    while (!isEmpty(s))
    {
        p = pop(s);
        if (p->right) push(s, p->left);
        if (p->left) push(s, p->right);
        if (p->info == max) p->info = min;
        else if (p->info == min) p->info = max;
    }
}

void print_leaves(node* root)
{
    stack s = create_stack();
    node* p;
    push(s, root);

    while (!isEmpty(s))
    {
        p = pop(s);
        if (p->right) push(s, p->right);
        if (p->left) push(s, p->left);
        if (!p->right && !p->left) cout << p->info << ' ';
    }
}

int main()
{
    node* root = create_node(5);
    root->left = create_node(3);
    root->right = create_node(6);
    root->left->left = create_node(1);
    root->left->right = create_node(7);
    root->right->left = create_node(2); 
    root->right->right = create_node(9);


    DFS(root);
    //cout << task_a(root) << endl;
    //cout << task_b(root, 3) << endl;
    //cout << sum(root) << endl;
    //replace_max_min(root);

    print_leaves(root);
}
