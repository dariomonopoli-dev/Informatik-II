#include <stdio.h>
#include <stdlib.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct TreeNode* create(int item)
{
    struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode*));
    temp->val = item;
    temp -> left = temp -> right = NULL;
    return temp;
}
struct TreeNode* TreeMin(struct TreeNode* node)
{
    //we search the smallest element in the subtree (left-most element)
    while (node->left != NULL)
        node = node->left;
 
    return node;
}
// Find height of a tree, defined by the root node
int tree_height(struct TreeNode* root) {
    if (root == NULL) 
        return 0;
    else {
        // Find the height of left, right subtrees
        int left_height = tree_height(root->left);
        int right_height = tree_height(root->right);
         
        // Find max(subtree_height) + 1 to get the height of the tree
        return MAX(left_height, right_height) + 1;
    }
}
struct TreeNode* insert(struct TreeNode* root, int val)
{
    /* If the tree is empty, return a new node */
    if (root == NULL)
        return create(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
 
    /* return the (unchanged) node pointer */
    return root;

}

struct TreeNode* search(struct TreeNode* root, int val)
{
    if (root == NULL || root->val == val)
    {
        return root;
    }
    if (val < root->val)
    {
        return search(root->left, val);
    }
    else
    {
        return search(root->left, val);
    }
}

struct TreeNode* delete(struct TreeNode* root, int val)
{
    if (root = NULL)
    {
        return root;
    }
    //if the val to be deleted is smaller than the root's val, then it lies in the left subtree
    if (val < root->val)
    {
        root->left = delete(root->left, val);
    }

    //if the val to be deleted is greater than the root's val, then it lies in the right subtree
    else if (val > root->val)
        root->right = delete(root->right, val);

    //if the value is the same as the root's value, then this is the node that needs to be deleted
    else
    {
       // node with only one child or no child (we just have to delete the root)
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            root = temp;
        }
        else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            root = temp;
        }

        //node with two children: get the inorder successor (smallest in the right subtree)
        struct TreeNode* temp = TreeMin(root->right);

        //we copy the inorder successor's value to this node
        root->val = temp->val;

        // Delete the inorder successor
        root->right = delete(root->right, temp->val);
    }
}
void print_level(struct TreeNode* root, int level_no) {
   
    if (!root){
        return;
    }

    if (level_no == 0) {
        //top of tree (we just have to print the root note)
      
        printf("%d -- ", root->val);
    }
    else{
        print_level(root->left, level_no - 1);
        print_level(root->right, level_no - 1);
        
    }
 
}
void printTree(struct TreeNode* root)
{
    
    int height = tree_height(root);
    for (int i=0; i<height; i++) {
        print_level(root, i);
        printf("\n");
    }
    
    
}

int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct TreeNode* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
 
    printf("Inorder traversal of the given tree: \n");
    printTree(root);
 
    // printf("\nDelete 20\n");
    // root = deleteNode(root, 20);
    // printf("Inorder traversal of the modified tree \n");
    // inorder(root);
 
    // printf("\nDelete 30\n");
    // root = deleteNode(root, 30);
    // printf("Inorder traversal of the modified tree \n");
    // inorder(root);
 
    // printf("\nDelete 50\n");
    // root = deleteNode(root, 50);
    // printf("Inorder traversal of the modified tree \n");
    // inorder(root);



    return 0;
}