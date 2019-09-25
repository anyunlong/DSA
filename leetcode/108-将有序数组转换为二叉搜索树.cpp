/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    if (nums == NULL || numsSize < 1) {
        return NULL;
    }
    struct TreeNode *rootNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    int middleIndex = numsSize / 2;
    rootNode->val = nums[middleIndex];

    rootNode->left = sortedArrayToBST(nums, middleIndex);
    rootNode->right = sortedArrayToBST(&(nums[middleIndex + 1]), numsSize - middleIndex - 1);

    return rootNode;
}

