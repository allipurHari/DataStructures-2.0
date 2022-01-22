// https://www.interviewbit.com/problems/kth-permutation-sequence/

string Solution::getPermutation(int A, int B) {
    vector<int>factorial(A), num(A);
    factorial[0] = 1;
    num[0] = 1;
    for(int i = 1;i < A;i++){
        if(i>12) factorial[i]=INT_MAX;
        else factorial[i] = factorial[i-1]*i;
        num[i] = i+1;
    }
    B = B-1;
    string ans = "";
    int size = A;
    for(int i = 0;i < size;i++){
        ans += to_string(num[B/factorial[A-1]]);
        num.erase(num.begin() + B/factorial[A-1]);
        B = B%factorial[A-1];
        A--;
    }
    return ans;
}
