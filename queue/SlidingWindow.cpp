vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    deque<int>deque;
    int size = A.size();
    vector<int>result;
    for(int i = 0;i < size;i++){
        while(!deque.empty() && A[deque.back()] < A[i]){
            deque.pop_back();
        }
        deque.push_back(i);
        if(i >= B-1){
            while(deque.front() < i-B+1)deque.pop_front();
            result.push_back(A[deque.front()]);
        }
    }
    return result;
}
