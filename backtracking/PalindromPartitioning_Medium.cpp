// https://www.interviewbit.com/problems/palindrome-partitioning/

bool isPalindrome(string s){
    int size = s.size();
    for(int i = 0;i < size/2+1;i++){
        if(s[i] != s[size-i-1])
            return false;
    }
    return true;
}

void solve(int index, string A, vector<string> v, vector<vector<string> >&ans){
    if(index >= A.size()){
        ans.push_back(v);
        return;
    }
    int size = A.size();
    string temp = "";
    for(int i = index;i < size;i++){
        temp += A[i];
        if(isPalindrome(temp)){
            v.push_back(temp);
            solve(i+1, A, v, ans);
            v.pop_back();
        }
    }
}

vector<vector<string> > Solution::partition(string A) {
    vector<vector<string> >ans;
    vector<string> v;
    int index = 0;
    solve(index, A, v, ans);
    return ans;
}
