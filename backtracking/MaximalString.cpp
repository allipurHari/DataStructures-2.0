// https://www.interviewbit.com/problems/maximal-string/

void recurse(string A, int B, int swaps, string &maxString){
    int size = A.size();
    if(swaps >= B){
        maxString = max(maxString, A);
        return;
    }
    for(int i = 0;i < size-1;i++){
        for(int j = i+1;j < size;j++){
            if(A[j] > A[i]){
                swap(A[j], A[i]);
                recurse(A, B, swaps+1, maxString);
                swap(A[j], A[i]);
            }
        }
    }
}

string Solution::solve(string A, int B) {
    string result = A;
    recurse(A, B, 0, result);
    return result;
}
