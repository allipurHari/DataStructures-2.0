// https://www.interviewbit.com/problems/permutations/

void solve(int n, vector<int>v, vector<int> resultV, vector<vector<int> >&ans){
    if(n == 0){
        ans.push_back(resultV);
        return;
    }
    int size = v.size();
    vector<int> temp = v;
    for(int i = 0;i < size;i++){
        resultV.push_back(v[i]);
        temp.erase(temp.begin() + i);
        solve(n-1, temp, resultV, ans);
        temp = v;
        resultV.pop_back();
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int> >ans;
    vector<int> resultV;
    solve(A.size(), A, resultV, ans);
    return ans;
}
