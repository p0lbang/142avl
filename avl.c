#include<stdio.h>
#include<malloc.h>
#define N 10
#define BALANCED 0
#define LEFT_LEANING 1
#define RIGHT_LEANING 2
typedef struct node_tag
{
    int x, height;
    struct node_tag *parent;
    struct node_tag *left;
    struct node_tag *right;
} avl_node;

int max(int a, int b)
{
    return (a > b ? a : b);
}
void updateheight(avl_node *temp)
{
    if (temp != NULL)
        temp->height = max(temp->left == NULL ? -1 : temp->left->height,
                           temp->right == NULL ? -1 : temp->right->height) +
                       1;
}

void left_rotate(avl_node **rootptr)
{
    avl_node *temp1;
    if (rootptr != NULL && *rootptr != NULL && (*rootptr)->right != NULL)
    {
        temp1 = (*rootptr)->right;

        (*rootptr)->right = temp1->left;
        if (temp1->left != NULL)
            temp1->left->parent = (*rootptr);

        temp1->parent = (*rootptr)->parent;

        (*rootptr)->parent = temp1;
        temp1->left = (*rootptr);

        if (temp1->parent != NULL)
        {
            if (temp1->parent->right == *rootptr)
                temp1->parent->right = temp1;
            else
                temp1->parent->left = temp1;
        }
        *rootptr = temp1;
        updateheight(temp1->left);
        updateheight(temp1);
    }
}

void right_rotate(avl_node **rootptr)
{
    avl_node *temp1;
    if (rootptr != NULL && rootptr != NULL && (*rootptr)->left != NULL)
    {
        temp1 = (*rootptr)->left;

        (*rootptr)->left = temp1->right;
        if (temp1->right != NULL)
            temp1->right->parent = (*rootptr);
        temp1->parent = (*rootptr)->parent;

        (*rootptr)->parent = temp1;
        temp1->right = (*rootptr);

        if (temp->parent != NULL)
        {
            if (temp1->parent->left rootptr)
                temp1->parent->left = temp1;
            else
                temp1->parent->right = temp1;
        }
    *rootptr = temp1;
    updateheight(temp1->right);
    updateheight(temp1);
    }
}