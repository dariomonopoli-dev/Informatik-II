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
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}
struct TreeNode* TreeMin(struct TreeNode* root)
{
    struct TreeNode* temp = root;
    //we search the smallest element in the subtree (left-most element)
    while (temp->left != NULL)
        temp = temp->left;
 
    return temp;
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

struct TreeNode* delete(struct TreeNode* root, int item)
{
    //4 Cases:
    //1) The node we want to delete is a leaf node (it has no child)
    //2) The node we want to delete has only a right child
    //3) The node we want to delete has only a left child
    //4) The node we want to delete has both children

    //base case
    if (root == NULL)
    {
        return NULL;
    }
    //we search the node that we want to delete
    if(root->val < item)
        root->right = delete(root->right, item);
  
    else if(root->val > item)
        {
            root->left = delete(root->left, item);
        }
    else
    {
        /*
         * Case 1: Leaf node. Both left and right reference is NULL
         * replace the node with NULL by returning NULL to the calling pointer.
         * free the node
         */
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        /*
         * Case 2: Node has right child.
         * replace the root node with root->right and free the right node
         */
        else if(root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        /*
         * Case 3: Node has left child.
         * replace the node with root->left and free the left node
         */
        else if(root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        /*
         * Case 4: Node has both left and right children.
         * Find the min value in the right subtree
         * replace node value with min.
         * And again call the remove function to delete the node which has the min value.
         * Since we find the min value from the right subtree call the remove function with root->right.
         */
        else
        {
            int InorderSuccessor = TreeMin(root->right);
            root->val = InorderSuccessor;
            root->right = delete(root->right, InorderSuccessor);
        }

    }

    return root;
    
    
    //Further explanation to the different cases:
    //Case 1: if the node is leaf (both left and right child are NULL), we remove the node directly and free its memory
    //Case 2: If the node has only a right child (and left child is NULL), make the node point to the right node and free the node (= copy the value of the child to the node)
    //Case 3: If the node has only  a left child (and right child is NULL), make the node point to the left node and free the node (= copy the value of the child to the node)
    //Case 4: If the node has noth left and right child: find the inorder successor and set the value of the node we want to delete as the inorder successor and then we delete the inorder successor


}
void print_level(struct TreeNode* root, int level_no) {
   
    if (!root){
        return;
    }

    if (level_no == 0) {
        //top of tree (we just have to print the root note)
      
        printf("%d", root->val);
    }
    else{
        print_level(root->left, level_no - 1);
        printf(" -- ");
        print_level(root->right, level_no - 1);
        
    }
 
}
void printTree(struct TreeNode* root) //doesn't work if we delete an element
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
 
    printf("Delete 20\n");
    root = delete(root, 20);
    printf("Inorder traversal of the modified tree \n");
    printTree(root);


    return 0;
}