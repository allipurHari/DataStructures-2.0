// https://www.interviewbit.com/problems/valid-bst-from-preorder/

int Solution::solve(vector<int> &A) {
    stack<int>s;
    int latestRoot = INT_MIN;
    for(int i =0;i < A.size();i++){
        if(latestRoot > A[i])return false;
        while(!s.empty() && A[i] > s.top()){
            latestRoot = s.top();
            s.pop();
        }
        s.push(A[i]);
    }
    return true;
}
