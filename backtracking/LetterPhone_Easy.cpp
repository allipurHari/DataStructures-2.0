// https://www.interviewbit.com/problems/letter-phone/

void solve(string A, int index, string resultString, unordered_map<char, string>mp, vector<string> &ans){
    if(index >= A.size()){
        ans.push_back(resultString);
        return;
    }
    string s = mp[A[index]], tempString;
    int size = s.size();
    for(int i = 0;i < size;i++){
        tempString = resultString + s[i];
        solve(A, index+1, tempString, mp, ans);
        tempString = resultString;
    }
}

vector<string> Solution::letterCombinations(string A) {
    unordered_map<char, string>mp;
    mp['0'] = "0";
    mp['1'] = "1";
    mp['2'] = "abc";
    mp['3'] = "def";
    mp['4'] = "ghi";
    mp['5'] = "jkl";
    mp['6'] = "mno";
    mp['7'] = "pqrs";
    mp['8'] = "tuv";
    mp['9'] = "wxyz";

    vector<string>ans;
    int index = 0;
    string resultString = "";

    solve(A, index, resultString, mp, ans);
    return ans;
}
