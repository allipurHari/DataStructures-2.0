// https://www.interviewbit.com/problems/generate-all-parentheses-ii/

void solve(int n, int totalSize, string s, int countOB, int countCB, vector<char> v, vector<string> &ans){
    if(countOB > totalSize/2 || countCB > totalSize/2)return;
    if(n == 0){
        ans.push_back(s);
        return;
    }
    string temp = "";
    for(int i = 0;i < v.size();i++){
        temp = s + v[i];
        if(v[i] == ')'){
            if(countOB > countCB){
                countCB++;
                solve(n-1, totalSize, temp, countOB, countCB, v, ans);
                countCB--;
            }
        }
        else{
            countOB++;
            solve(n-1, totalSize, temp, countOB, countCB, v, ans);
            countOB--;
        }
        temp = s;
    }
}

vector<string> Solution::generateParenthesis(int A) {
    vector<string> ans;
    vector<char> v{'(',')'};
    string s = "";
    int countCB = 0, countOB = 0;
    int n = A*2;
    solve(n, n, s, countOB, countCB, v, ans);
    return ans;
}
