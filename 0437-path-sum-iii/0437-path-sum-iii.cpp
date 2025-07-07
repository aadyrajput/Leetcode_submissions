class Solution {
private:
    int countFromNode(TreeNode* node, long long currSum, int targetSum) {
        if (!node) return 0;

        currSum += node->val;
        int count = (currSum == targetSum) ? 1 : 0;

        count += countFromNode(node->left, currSum, targetSum);
        count += countFromNode(node->right, currSum, targetSum);

        return count;
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;

        // Try starting the path from root
        int pathsFromRoot = countFromNode(root, 0, targetSum);

        // Try starting from the left and right children
        int pathsFromLeft = pathSum(root->left, targetSum);
        int pathsFromRight = pathSum(root->right, targetSum);

        return pathsFromRoot + pathsFromLeft + pathsFromRight;
    }
};
