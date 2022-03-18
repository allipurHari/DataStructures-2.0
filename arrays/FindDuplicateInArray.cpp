// https://www.interviewbit.com/old/problems/find-duplicate-in-array/

int Solution::repeatedNumber(const vector<int> &A) {
    if(A.size() == 1)return -1;
    if(A.size() == 2)return A[0];
    int sq = ceil(sqrt(A.size()-1));
    int tmp = (A.size()-2)/sq;
    unordered_map<int, int> mp;
    for(int i = 0;i < A.size();i++){
        int val = (A[i]-1)/sq;
        mp[val]++;
        if(mp[val] > sq){
            tmp = val;
        }
    }
    unordered_set<int>s;
    for(int i = 0;i < A.size();i++){
        int val = (A[i]-1)/sq;
        if(val == tmp){
            if(s.find(A[i]) != s.end()){
                return A[i];
            }
            s.insert(A[i]);
        }
    }
    return -1;
}
