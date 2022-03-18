// https://www.interviewbit.com/old/problems/spiral-order-matrix-ii/

vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int> >ans(A, vector<int>(A, 0));
    if(!A)return ans;
    int i = 0, j = 0;
    ans[0][0] = 1;
    int x = 1;
    while(x < A*A){
        while(j+1<A && ans[i][j+1] == 0){
            x++;
            j++;
            ans[i][j] = x;
        }
        while(i+1<A && ans[i+1][j] == 0){
            x++;
            i++;
            ans[i][j] = x;
        }
        while(j-1>=0 && ans[i][j-1] == 0){
            x++;
            j--;
            ans[i][j] = x;
        }
        while(i-1>=0 && ans[i-1][j] == 0){
            x++;
            i--;
            ans[i][j] = x;
        }
    }
    return ans;
}
