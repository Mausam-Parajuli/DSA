#include <stdio.h>
#include <stdlib.h>
struct AVLTree
{
    int data;
    struct AVLTree *left;
    struct AVLTree *right;
    struct AVLTree *parent;
    int height;
};
struct AVLTree *root = NULL;
struct AVLTree* create_node(int value)
{
    struct AVLTree *NewNode;
    NewNode = (struct AVLTree*)malloc(sizeof(struct AVLTree));
    NewNode->data = value;
    NewNode->left = NULL;
    NewNode->right = NULL;
    NewNode->parent = NULL;
    NewNode->height = 1;
    return NewNode;
}
void preorder(struct AVLTree *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct AVLTree *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void postorder(struct AVLTree *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
int getHeight(struct AVLTree *node)
{
    if (node == NULL)
        return 0;
    else
        return node->height;
}
int checkBalance(struct AVLTree *node)
{
    if (node == NULL)
        return 0;
    else
        return getHeight(node->left) - getHeight(node->right);
}
int max(int a, int b)
{
    if (a > b) return a;
    else return b;
}
struct AVLTree* rightRotate(struct AVLTree* y)
{
    struct AVLTree *x = y->left;
    struct AVLTree *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}
struct AVLTree* leftRotate(struct AVLTree* x)
{
    struct AVLTree *y = x->right;
    struct AVLTree *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}
struct AVLTree* insert(struct AVLTree *root, int data)
{
    if (root == NULL)
    {
        return create_node(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
        root->left->parent = root;
    }
    else if(data > root->data)
    {
        root->right = insert(root->right, data);
        root->right->parent = root;
    }
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = checkBalance(root);
    if (balance > 1 && checkBalance(root->left) >= 0)
        return rightRotate(root);
    if (balance > 1 && checkBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && checkBalance(root->right) <= 0)
        return leftRotate(root);
    if (balance < -1 && checkBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
struct AVLTree* search(struct AVLTree *root, int key)
{
    if((root == NULL) || (key == root->data))
        return root;
    else if(key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}
struct AVLTree* find_min(struct AVLTree *root)
{
    while(root->left != NULL)
        root = root->left;
    return root;
}
struct AVLTree* find_max(struct AVLTree *root)
{
    while(root->right != NULL)
        root = root->right;
    return root;
}
struct AVLTree* delete_node(struct AVLTree *root, int value)
{
    if(root == NULL)
        return root;
    if(value < root->data)
    {
        root->left = delete_node(root->left, value);
        if(root->left) root->left->parent = root;
    }
    else if(value > root->data)
    {
        root->right = delete_node(root->right, value);
        if(root->right) root->right->parent = root;
    }
    else
    {
        if(root->left == NULL)
        {
            struct AVLTree *temp = root->right;
            if(temp) temp->parent = root->parent;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            struct AVLTree *temp = root->left;
            if(temp) temp->parent = root->parent;
            free(root);
            return temp;
        }
        else
        {
            struct AVLTree *temp = find_min(root->right);
            root->data = temp->data;
            root->right = delete_node(root->right, temp->data);
            if(root->right) root->right->parent = root;
        }
    }
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = checkBalance(root);
    if(balance > 1 && checkBalance(root->left) >= 0)
        return rightRotate(root);
    if(balance > 1 && checkBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(balance < -1 && checkBalance(root->right) <= 0)
        return leftRotate(root);
    if(balance < -1 && checkBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

int main()
{
    int i, element, choice;
    struct AVLTree *temp;
    int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    do
    {
        printf("1.INSERT\n2.DELETE\n3.SEARCH\n4.INORDER\n");
        printf("5.PREORDER\n6.POSTORDER\n7.FIND MAX\n8.FIND MIN\n");
        printf("9.CREATE\n10.EXIT\nEnter your choice ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to insert ");
            scanf("%d",&element);
            root = insert(root, element);
            printf("%d INSERTED!\n",element);
            break;
        case 2:
            printf("Enter the element to delete ");
            scanf("%d",&element);
            root = delete_node(root, element);
            printf("%d DELETED!\n",element);
            break;
        case 3:
            printf("Enter the element to search ");
            scanf("%d",&element);
            temp = search(root, element);
            if(temp == NULL)
                printf("%d NOT FOUND!!\n",element);
            else
                printf("%d FOUND!\n",element);
            break;
        case 4:
            inorder(root);
            printf("\n");
            break;
        case 5:
            preorder(root);
            printf("\n");
            break;
        case 6:
            postorder(root);
            printf("\n");
            break;
        case 7:
            temp = find_max(root);
            if(temp != NULL)
                printf("%d IS THE LARGEST ELEMENT IN THE BST\n",temp->data);
            break;
        case 8:
            temp = find_min(root);
            if(temp != NULL)
                printf("%d IS THE SMALLEST ELEMENT IN THE BST\n",temp->data);
            break;
        case 9:
            for(i=0;i<9;i++)
                root = insert(root, arr[i]);
            printf("All elements inserted sucessfully!\n");
            break;
        case 10:
            printf("Bye!\n");
        }
    } while (choice!=10);
    return 0;
}
