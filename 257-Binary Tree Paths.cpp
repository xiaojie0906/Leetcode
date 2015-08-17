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
    vector<string> vs;
public:
    void helper(TreeNode * root,string s){
        if(!s.empty())
            s += "->";
        stringstream ss;
        ss << root->val;
        string tmp;
        ss>>tmp;
        s += tmp;
        if(root->left)
            helper(root->left,s);
        if(root->right)
            helper(root->right,s); 
            
        if(!root->left && !root->right){
            vs.push_back(s);
            return;
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root)
            return vs;
        string s;
        helper(root,s);
        return vs;
    }
};