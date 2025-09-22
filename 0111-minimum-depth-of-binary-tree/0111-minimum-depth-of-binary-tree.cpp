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
private:
    int Tree(TreeNode* root){
        if(!root) return 0;
        int l = Tree(root->left);
        int r = Tree(root->right);
        if(l == 0 || r == 0) return (1+l+r);
        return 1 + min(l,r);
    }
public:
    int minDepth(TreeNode* root) {
        return Tree(root);
    }
};