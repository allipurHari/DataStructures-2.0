// https://www.interviewbit.com/problems/merge-overlapping-intervals/

bool comp(Interval a, Interval b){
    return a.start <= b.start;
}

vector<Interval> Solution::merge(vector<Interval> &A) {
    sort(A.begin(), A.end(), comp);
    int j = 0, k;
    for(int i = 0;i < A.size();i++){
        int mn = A[i].start;
        int mx = A[i].end;
        for(k = i+1;k < A.size();k++){
            if(A[k].start <= mx){
                mn = min(A[k].start, mn);
                mx = max(A[k].end, mx);
            }
            else{
                k--;
                break;
            }
        }
        i = k;
        A[j].start = mn;
        A[j].end = mx;
        j++;
    }
    A.erase(A.begin()+j, A.end());
    return A;
}
