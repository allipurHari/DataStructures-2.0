// https://www.interviewbit.com/problems/kth-smallest-element-in-tree/

void getKthSmallest(TreeNode* root, int B, int &nodeNo, int &ans){
    if(!root)return;
    getKthSmallest(root->left, B, nodeNo, ans);
    nodeNo++;
    if(nodeNo == B)ans = root->val;
    getKthSmallest(root->right, B, nodeNo, ans);

}

int Solution::kthsmallest(TreeNode* A, int B) {
    int ans = 0, nodeNo = 0;
    getKthSmallest(A, B, nodeNo, ans);
    return ans;
}
