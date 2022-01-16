#include <stdio.h>
#include <stdlib.h>
#define newnode (struct node *)malloc(sizeof(struct node))

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;
}

struct node *insert(struct node *node, int data)
{
    if (node == NULL)
    {
        printf("Inserted..!\n");
        return create(data);
    }
    else if (data > node->data)
    {
        node->right = insert(node->right, data);
    }
    else if (data < node->data)
    {
        node->left = insert(node->left, data);
    }
    return node;
}

void inorder(struct node *root)
{
    struct node *ptr = newnode;
    ptr = root;
    if (ptr == NULL)
    {
        return;
    }
    else
    {
        inorder(ptr->left);
        printf("%d\t", ptr->data);
        inorder(ptr->right);
    }
}

void preorder(struct node *root)
{
    struct node *ptr = newnode;
    ptr = root;
    if (ptr == NULL)
    {
        return;
    }
    else
    {
        printf("%d\t", ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void postorder(struct node *root)
{
    struct node *ptr = newnode;
    ptr = root;
    if (ptr == NULL)
    {
        return;
    }
    else
    {
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%d\t", ptr->data);
    }
}

struct node *findmax(struct node *root)
{
    struct node *current = (struct node *)malloc(sizeof(struct node));
    current = root;
    if (current != NULL)
    {
        while (current->right != NULL)
        {
            current = current->right;
        }
        return current;
    }
    else
    {
        printf("Tree is empty..!");
    }
}

struct node *findmin(struct node *root)
{
    struct node *current = (struct node *)malloc(sizeof(struct node));
    current = root;
    if (current != NULL)
    {
        while (current->left != NULL)
        {
            current = current->left;
        }
        return current;
    }
    else
    {
        printf("Tree is empty..!\n");
    }
}

struct node *delete (struct node *root, int data)
{
    struct node *temp = newnode;
    if (root == NULL)
    {
        return NULL;
    }
    else if (data < root->data)
    {
        root->left = delete (root->left, data);
    }
    else if (data > root->data)
    {
        root->right = delete (root->right, data);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            temp = findmin(root->right);
            root->data = temp->data;
            root->right = delete (root->right, temp->data);
        }
    }
    return root;
}

void main()
{
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root = NULL;
    struct node *current = (struct node *)malloc(sizeof(struct node));
    current = NULL;
    int choice, data;

    printf("1)Insert\n2)Display\n3)Findmax\n4)Findmin\n5)Delete\n6)Exit\n");

    do
    {
        printf("\nEnter your choice: \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data: \n");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 2:
            printf("Inorder\n");
            inorder(root);

            printf("\nPreorder\n");
            preorder(root);

            printf("\nPostorder\n");
            postorder(root);
            break;
        case 3:
            current = findmax(root);
            printf("the largest number: %d\n", current->data);
            break;
        case 4:
            current = findmin(root);
            printf("the Smallest number: %d\n", current->data);
            break;
        case 5:
            printf("Enter element to be deleted:\n");
            scanf("%d", &data);
            root = delete (root, data);
            break;
        case 6:
            exit(0);
            break;
        }
    } while (choice != 6);
}