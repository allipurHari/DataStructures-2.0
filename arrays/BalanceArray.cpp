// https://www.interviewbit.com/old/problems/balance-array/

int Solution::solve(vector<int> &A) {
    vector<int> e(A.size()+1, 0);
    vector<int> o(A.size()+1, 0);
    for(int i = A.size()-1; i >= 0; i--){
        if(i&1){
            o[i] = o[i+1] + A[i];
            e[i] = e[i+1];
        }
        else{
            e[i] = e[i+1] + A[i];
            o[i] = o[i+1];    
        }
    }
    int ce = 0;
    int co = 0;
    int ans = 0;
    for(int i = 0; i < A.size(); i++){
        if(co + e[i+1] == ce + o[i+1]) ans++;
        if(i&1) co += A[i];
        else ce += A[i];
    }
    return ans;
}
