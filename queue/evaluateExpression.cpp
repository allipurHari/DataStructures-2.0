// https://www.interviewbit.com/problems/evaluate-expression/

int getNumber(string s){
    int size = s.size();
    int result = 0;
    int flag = 1;

    // If string is a negative value, we calculate the number then we multiply with -1 at the end with help of -1.
    for(int i = 0;i < size;i++){
        if(s[i] == '-'){
            flag = -1;
            i++;
        }
        result = result * 10 + (s[i] - '0');
    }
    return result*flag;
}

pair<int, int> getFirstAndSecondValues(stack<string> &s){
    int after = getNumber(s.top());
    s.pop();
    int before = getNumber(s.top());
    s.pop();
    return make_pair(before, after);
}

int Solution::evalRPN(vector<string> &A) {
    int size = A.size();

    // base case
    if(!size)return 0;

    stack<string> s;

    for(int i = 0;i < size;i++){
        pair<int, int> p;
        if(A[i] == "+"){
            p = getFirstAndSecondValues(s);
            int temp = p.first + p.second;
            s.push(to_string(temp));
        }
        else if(A[i] == "*"){
            p = getFirstAndSecondValues(s);
            int temp = p.first * p.second;
            s.push(to_string(temp));
        }
        else if(A[i] == "-"){
            p = getFirstAndSecondValues(s);
            int temp = p.first - p.second;
            s.push(to_string(temp));
        }
        else if(A[i] == "/"){
            p = getFirstAndSecondValues(s);
            int temp = p.first/p.second;
            s.push(to_string(temp));
        }else{
            s.push(A[i]);
        }
    }
    return getNumber(s.top());
}
