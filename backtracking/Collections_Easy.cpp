// https://www.interviewbit.com/problems/combinations/

void solve(int index, int A, int B, vector<int> v, vector<vector<int> >&ans){
    if(B == 0){
        ans.push_back(v);
        return;
    }
    for(int i = index;i < A;i++){
        v.push_back(i+1);
        solve(i+1, A, B-1, v, ans);
        v.pop_back();
    }
}

vector<vector<int> > Solution::combine(int A, int B) {
    vector<vector<int> >ans;
    vector<int>v;
    solve(0, A, B, v, ans);
    return ans;
}
