#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEFT  0
#define RIGHT 1

typedef struct node_ {
    int data;
    struct node_ *link[2];
} node_t;

node_t *findmax(node_t *root)
{
    if (root == NULL) return NULL;
    else if (root->link[RIGHT] == NULL) return root;
    else {
        return findmax(root->link[RIGHT]);
    }
}

node_t *findmin(node_t *root)
{
    if (root == NULL) return NULL;
    else if (root->link[LEFT] == NULL) return root;
    else {
        return findmin(root->link[LEFT]);
    }
}

node_t *deletenode(node_t *root, int val)
{
    if(root == NULL) return root;
    if (root->data > val) {
        root->link[LEFT] = deletenode(root->link[LEFT], val);
    } else if (root->data < val) {
        root->link[RIGHT] = deletenode(root->link[RIGHT], val);
    } else { // matched the data
        // case 1, no children
        if (root->link[LEFT] == NULL && root->link[RIGHT] == NULL) {
            free(root);
            root = NULL;
        }
        // case 2.a, one child - left
        else if (root->link[LEFT] != NULL && root->link[RIGHT] == NULL) {
            node_t *temp = root->link[LEFT];
            free(root);
            root = temp;
        }
        // case 2.b, one child - right
        else if (root->link[LEFT] == NULL && root->link[RIGHT] != NULL) {
            node_t *temp = root->link[RIGHT];
            free(root);
            root = temp;
        }
        // case 3, both children
        else {
            node_t *temp = findmin(root->link[RIGHT]);
            root->data = temp->data;
            root->link[RIGHT] = deletenode(root->link[RIGHT], temp->data);
        }
    }

    return root;
}

node_t *make_node(int val) 
{
    node_t *temp = malloc(sizeof(struct node_));
    temp->data = val;
    temp->link[LEFT] = NULL;
    temp->link[RIGHT] = NULL;
    return temp;
}

node_t *insert(node_t *root, int val)
{
    if (root == NULL) root = make_node(val);
    else {
        if (root->data > val) {
            root->link[LEFT] = insert(root->link[LEFT], val);
        } else if (root->data < val) {
            root->link[RIGHT] = insert(root->link[RIGHT], val);
        } else if (root->data == val) {
            printf("Duplicate data detected [%d]\n", val);
        }
    }
    return root;
}

void postorder(node_t *root)
{
    if (root == NULL) return;
    postorder(root->link[LEFT]);
    postorder(root->link[RIGHT]);
    printf("%d, ", root->data);
}

void preorder(node_t *root)
{
    if (root == NULL) return;
    printf("%d, ", root->data);
    preorder(root->link[LEFT]);
    preorder(root->link[RIGHT]);
}

void inorder(node_t *root)
{
    if (root == NULL) return;
    inorder(root->link[LEFT]);
    printf("%d, ", root->data);
    inorder(root->link[RIGHT]);
}

void levelorder(node_t *root, int level)
{
    if (root == NULL) return;
    if (level == 1) printf("%d|", root->data);
    levelorder(root->link[LEFT], level);
    levelorder(root->link[RIGHT], level);


}

void spiralorder(node_t *root, int level, int toggle)
{
   if (root == NULL) return;
   if (level == 1) printf("%d ", root->data);

   if (toggle == 1) {
       spiralorder(root->link[LEFT], level-1, toggle);
       spiralorder(root->link[RIGHT], level-1, toggle);
   } else if (toggle == -1) {
       spiralorder(root->link[RIGHT], level-1, toggle);
       spiralorder(root->link[LEFT], level-1, toggle);
   }
}

int maxdepth(node_t *root) 
{
    if(root == NULL) return 0;
    int ldepth = maxdepth(root->link[LEFT]);
    int rdepth = maxdepth(root->link[RIGHT]);

    if (ldepth > rdepth) return (ldepth+1);
    else return (rdepth+1);
}

int main(void) 
{ 
    node_t *tree_root = NULL;
    int i = 0;
    int toggle = 1;
    int array[] = {1, 9, 8, 6, 100, 150, 20, 25, 9, 16, -1, 3, 5, 7, 11, 13, 210, 23, 45, 38, 93, 0};

    printf("Inserting the following in tree \n");
    for (i=0;i<sizeof(array)/sizeof(int);i++) {
        printf("%d, ", array[i]);
        tree_root = insert(tree_root, array[i]);
    }
    printf("\nInOrder : \n");
    inorder(tree_root);
    printf("\nPreOrder : \n");
    preorder(tree_root);
    printf("\nPostOrder : \n");
    postorder(tree_root);
    printf("\nLevel order: \n");
    for (i=0;i<=maxdepth(tree_root); i++) {
        levelorder(tree_root, i);
    }
    printf("\nSpiral Order: \n");
    for (i=0;i<=maxdepth(tree_root); i++) {
        toggle = toggle * (-1);
        spiralorder(tree_root, i, toggle);
    }

    printf("\nDeleting 1 from the nodes \n");
    deletenode(tree_root, 1);
    printf("\nInorder: \n");
    inorder(tree_root);
    printf("\nLevel Order: \n");
    for (i=0;i<=maxdepth(tree_root); i++) {
        levelorder(tree_root, i);
    }

    printf("\nheight of tree is %d\n", maxdepth(tree_root));
    printf("min in the tree is %d\n", findmin(tree_root)->data);
    printf("max in the tree is %d\n", findmax(tree_root)->data);
};
