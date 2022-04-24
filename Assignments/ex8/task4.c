#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

 //prints all the keys which in the given range [low_bound,...,high_bound].
void PrintInRange(struct TreeNode* root, int low_bound, int high_bound)
{

if (root == NULL)
	return;

if (low_bound <= root->val && high_bound >= root->val )
	printf("%d ", root->val );
if (low_bound > root->val) 
{
    printf("NULL ");

}
if (high_bound < root->val)
{
    printf("NULL ");
}
PrintInRange(root->left, low_bound, high_bound);
PrintInRange(root->right, low_bound, high_bound);
}

struct TreeNode* create(int item)
{
    struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode*));
    temp->val = item;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}


int main()
{

struct TreeNode* root = malloc(sizeof(struct TreeNode*));
int low_bound = 17, high_bound = 45;


root = create(12);
root->right = create(35);
root->right->left = create(17);
root->right->right = create(45);
root->right->left->left = create(9);
root->right->left->right = create(29);
root->right->left->right->left = create(28);
root->right->right->right = create(50);

PrintInRange(root, low_bound, high_bound);

return 0;
}


