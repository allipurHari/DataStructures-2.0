// https://www.interviewbit.com/problems/nqueens/submissions/

vector<string> allocateQueen(int indexI, int indexJ, int n, vector<string> v){
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(i == indexI || j == indexJ || i-j == indexI-indexJ || i+j == indexI+indexJ)
                v[i][j] = '1';
        }
    }
    v[indexI][indexJ] = 'Q';
    return v;
}

vector<string> getDotVector(vector<string> v){
    for(int i = 0;i < v.size();i++){
        for(int j = 0;j < v.size();j++){
            if(v[i][j] != 'Q')
                v[i][j] = '.';
        }
    }
    return v;
}

void solve(int i, int n, vector<string> v, vector<vector<string> >&ans){
    if(i >= n){
        ans.push_back(getDotVector(v));
        return;
    }
    vector<string> temp;
    for(int j = 0;j < n;j++){
        if(v[i][j] != '1'){
            temp = allocateQueen(i, j, n, v);
            solve(i+1, n, temp, ans);
        }
    }
} 

vector<vector<string> > Solution::solveNQueens(int A) {
    vector<vector<string> >ans;
    vector<string> v;
    string str = "";
    for(int i = 0;i < A;i++)
        str += '0';
    for(int i = 0;i < A;i++)
        v.push_back(str);
    int i = 0;
    solve(i, A, v, ans);
    return ans;    
}
