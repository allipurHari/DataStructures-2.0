// https://www.interviewbit.com/problems/subset/

void getSubsets(int index, vector<int> A, vector<int> v, vector<vector<int> >&ans){
    for(int i = index;i < A.size();i++){
        v.push_back(A[i]);
        ans.push_back(v);
        getSubsets(i+1, A, v, ans);
        v.pop_back();
    }
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    vector<vector<int> >ans;
    vector<int>v;
    int index = 0;

    sort(A.begin(), A.end());
    ans.push_back(v);

    getSubsets(index, A, v, ans);
    return ans;
}
