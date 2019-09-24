/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root){
    if (root == NULL) {
        return 0;
    }
    
    int leftMaxDepth = maxDepth(root->left);
    int rightMaxDepth = maxDepth(root->right);
    
    if (leftMaxDepth > rightMaxDepth) {
        return 1 + leftMaxDepth;
    } else {
        return 1 + rightMaxDepth;
    }
}
