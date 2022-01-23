// https://www.interviewbit.com/problems/subsets-ii/

void getSubsets(int index, vector<int> A, vector<int> v, vector<vector<int> >&ans, set<vector<int> >&s){
    if(s.find(v) == s.end()){
        s.insert(v);
        ans.push_back(v);
    }
    for(int i = index;i < A.size();i++){
        v.push_back(A[i]);
        getSubsets(i+1, A, v, ans,s);
        v.pop_back();
    }
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    vector<vector<int> >ans;
    vector<int>v;
    set<vector<int> >s;
    int index = 0;

    sort(A.begin(), A.end());

    getSubsets(index, A, v, ans, s);
    return ans;
}
