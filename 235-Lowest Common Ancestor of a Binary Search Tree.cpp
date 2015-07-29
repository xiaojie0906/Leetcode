/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode * iter = root;
        if(p->val > q->val){
            TreeNode * tmp = p;
            p = q;
            q = tmp;
        }
        while(iter){
            if(iter->val < p->val)
                iter = iter->right;
            else if(iter ->val > q->val)
                iter = iter->left;
            else
                return iter;
        }
        return iter;
    }
};