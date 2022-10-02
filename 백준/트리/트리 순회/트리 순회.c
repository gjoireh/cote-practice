#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable: 4996)

struct node
{
    char data;
    struct node* left;
    struct node* right;
}typedef NODE;


void preoder(NODE* node)
{
    if (node == NULL)
        return;

    printf("%c", node->data);
    preoder(node->left);
    preoder(node->right);
}

void inoder(NODE* node)
{
    if (node == NULL)
        return;

    inoder(node->left);
    printf("%c", node->data);
    inoder(node->right);
}

void postorder(NODE* node)
{
    if (node == NULL)
        return;

    postorder(node->left);
    postorder(node->right);
    printf("%c", node->data);
}

int main()
{
    int N;
    scanf("%d", &N);
    char n, l, r;
    char new_line;

    NODE* nodes = (struct node*)malloc(sizeof(NODE) * 26);

    for (int i = 0; i < N; i++)
    {
        scanf("%c", &new_line);
        scanf("%c %c %c", &n, &l, &r);
        
        nodes[n - 'A'].data = n;
        if (l == '.')
            nodes[n - 'A'].left = NULL;
        else
            nodes[n - 'A'].left = &nodes[l - 'A'];

        if (r == '.')
            nodes[n - 'A'].right = NULL;
        else
            nodes[n - 'A'].right = &nodes[r - 'A'];
    }
    preoder(&nodes[0]);
    printf("\n");
    inoder(&nodes[0]);
    printf("\n");
    postorder(&nodes[0]);
    printf("\n");
    return 0;
}