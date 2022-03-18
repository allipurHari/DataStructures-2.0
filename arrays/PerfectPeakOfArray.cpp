// https://www.interviewbit.com/problems/perfect-peak-of-array/

int Solution::perfectPeak(vector<int> &A) {
    vector<int>left(A.size(), 0);
    stack<int> s;
    for(int i = 0;i < A.size();i++){
        while(!s.empty() && s.top() < A[i]){
            s.pop();
        }
        if(s.empty()) left[i] = 1;
        s.push(A[i]);
    }
    for(int i = A.size()-1;i >= 0;i--){
        while(!s.empty() && s.top() > A[i]){
            s.pop();
        }
        if(s.empty() && left[i] && i != 0 && i != A.size()-1)return 1;
        s.push(A[i]);
    }
    return 0;
}
