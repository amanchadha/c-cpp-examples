#include <stdio.h> //printf
#include <stdlib.h> //malloc 
#include <limits.h> //malloc 

#define true 1
#define false 0

//pointer-to-pointer args are used when the changes in a pointer (such as head node changes due to insertion of a node at the beginning of a LL) are to be reflected back in the caller
//if p is a ptr, updates to *p in a callee are reflected back in the caller, but updates to p are not reflected back in the caller.
//for functions not modifying a pointer, can simply pass a pointer (no need of a p2p).

struct node
{
  int data;
  struct node* left, *right;
};

struct node* newNode(int data)
{
  struct node* newNode = (struct node*) malloc(sizeof(struct node)); //new struct node;
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

//similar to findNum() in LLs
//similar to Binary Search (iteration space split into two for every iteration)
int lookUp(struct node* node, int data)
{
  //base case, i.e., tree not init yet
  if (!node)	
    return false;
    
  //data here?
  if (node->data)
    return true;
  
  //otherwise recur down the tree
  if (node->data > data) //data is smaller? go to LBST
    return lookUp(node->left, data);
  else //data is larger? go to RBST -- same as ((*node)->data <= data)
    return lookUp(node->right, data);
}

//AKA insertNode()
void pushNode(struct node** node, int data)
{
  //base case, i.e., tree not init yet OR
  //reached a left node -- a new key is always inserted at a leaf node
  if (!*node)
  {
    *node = newNode(data);
    return;
  }
  //otherwise recur down the tree
  if ((*node)->data > data)
    //node->left = //dont need to return a value (and hence save the return value) since p2p is passed
    pushNode(&((*node)->left), data);
  else 
    pushNode(&((*node)->right), data);
}

//in-order traversal -- print nodes in ascending order AKA sorted increasing order
void printBST(struct node* node)
{
  //base case, i.e, tree not init yet
  if (!node)
    return;

  //recur down the left subtree
  printBST(node->left);
  //visit the node
  printf("%d ", node->data);
  //recur down the right subtree
  printBST(node->right);
}

//pre-order traversal
void printPreOrderBST(struct node* node)
{
  //base case, i.e, tree not init yet
  if (!node)
    return;

  //visit the node
  printf("%d ", node->data);
  //recur down the left subtree
  printPreOrderBST(node->left);
  //recur down the right subtree
  printPreOrderBST(node->right);
}

//post-order traversal
void printPostOrderBST(struct node* node)
{
  //base case, i.e, tree not init yet
  if (!node)
    return;

  //recur down the left subtree
  printPostOrderBST(node->left);
  //recur down the right subtree
  printPostOrderBST(node->right);
  //then visit the node
  printf("%d ", node->data);
}

//if given a "non-empty BST" no need to check for root == NULL, otherwise need to checl.
//note that the entire tree does not need to be searched
int minValue(struct node* root)
{
    printf("[minValue] Obtaining the minimum value in the BST...\n\t");

    struct node* current = root;

    if (!current)
        return -1;

    //get the leftmost leaf node
    while(current->left)
        current = current->left;

    printf("%d\n", current->data);

    return current->data;
}

int maxValue(struct node* root)
{
    printf("[maxValue] Obtaining the maximum value in the BST...\n\t");

    struct node* current = root;

    if (!current)
        return -1;

    //get the leftmost leaf node
    while(current->right)
        current = current->right;

    printf("%d\n", current->data);

    return current->data;
}

void deleteBST(struct node** root)
{
    struct node* current = *root, *backupLeft, *backupRight;

    while(current->left && current->right)
    {
        backupLeft = current->left;
        backupRight= current->right;
        current->left = current->left->left;
        current->right = current->right->right;
        free(backupLeft);
        free(backupRight);
    }

    free(current);

    *root = NULL;
}

int isBST(struct node* node, int min, int max)
{
    //an empty tree is BST
    if (node == NULL)
        return true;

    //false if the node violates the min/max constraint | if >= min and <= max, then OK
    if (node->data < min || node->data > max) 
        return false;

    //otherwise recur down the left and right subtrees, tightening the min and max constraint (narrowing it down) at each iteration
    return isBST(node->left, min, node->data) && isBST(node->right, (node->data+1), max);
}

int main()
{
  struct node *root = NULL;

  //1 -> 2 -> 3 -> 4 -> 5
  pushNode(&root, 1);
  pushNode(&root, 2);
  pushNode(&root, 3);
  pushNode(&root, 4);
  pushNode(&root, 5);

  //lookUp 5
  printf("[lookUp] Looking up data 5 in the BST...\n\t");  
  lookUp(root, 5) ? printf("Found 5\n") : printf("Can't find 5\n");
  
  //print BST
  printf("[printBST] Printing the BST...\n\t");
  printBST(root);
  printf("\n");

  printf("[printPreOrderBST] Printing the BST by doing a Pre Order Traversal...\n\t");
    printPreOrderBST(root);
  printf("\n");

  printf("[printPostOrderBST] Printing the BST by doing a Post Order Traversal...\n\t");
    printPostOrderBST(root);
  printf("\n");
  
  minValue(root);

  maxValue(root);

  //get length
  //getLength(head);
  
  //add node at pos 2
  //printf("[main] Printing LL after insertion of a node at position 2...\n");
  //addNode(&head, 2, 10);

  //cleanUp
  deleteBST(&root);

  //print BST -- confirm deletion
  printBST(root);

  root                    = newNode(4);
  root->left            = newNode(2);
  root->right          = newNode(5);
  root->left->left    = newNode(1);
  root->left->right  = newNode(3); 

  printf("[printBST] Printing the BST...\n\t");
  printBST(root);
  printf("\n");

  printf("[printPreOrderBST] Printing the BST by doing a Pre Order Traversal...\n\t");
    printPreOrderBST(root);
  printf("\n");

  printf("[printPostOrderBST] Printing the BST by doing a Post Order Traversal...\n\t");
    printPostOrderBST(root);
  printf("\n");

  //check if BST
  printf("[isBST] Checking if the tree is a BST...\n\t");  
  isBST(root, INT_MIN, INT_MAX) ? printf("The tree is a BST\n") : printf("The tree is NOT a BST\n") ;
}
