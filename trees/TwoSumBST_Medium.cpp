// https://www.interviewbit.com/problems/2sum-binary-tree/

bool solve(TreeNode *root, int B, unordered_set<int> &s){
    if(!root)return false;
    if(s.find(B - root->val) != s.end())
        return true;
    s.insert(root->val);
    return solve(root->left, B, s) || solve(root->right, B, s);
}

int Solution::t2Sum(TreeNode* A, int B) {
    unordered_set<int>s;
    return solve(A, B, s);
}
