/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    long M = 1e9 + 7;
    long SUm = 0, maxP = 0;


    // Tree Total Sum
    int SUM(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }

        int leftsubTreeSum = SUM(root->left);
        int rightsubTreeSum = SUM(root->right);
        int sum = root->val + leftsubTreeSum + rightsubTreeSum;

        maxP = max(maxP, (SUm - sum) * sum);

        return sum;
    }

    int maxProduct(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }

        SUm = SUM(root);
        SUM(root);
        return maxP % M;
    }
};