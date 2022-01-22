// https://www.interviewbit.com/problems/combination-sum/

void solve(int index, vector<int> A, int target, int size, int sum, vector<int> v, vector<vector<int> > &ans){
    if(sum > target)return;
    if(sum == target){
        ans.push_back(v);
    }
    for(int i = index;i < size;i++){
        sum += A[i];
        v.push_back(A[i]);
        solve(i, A, target, size, sum, v, ans);
        v.pop_back();
        sum -= A[i];
    }
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    vector<vector<int> > ans;
    vector<int> v;
    int sum = 0;
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    solve(0, A, B, A.size(), sum, v, ans);
    return ans;
}
