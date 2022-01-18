int Solution::trap(const vector<int> &A) {
    int size = A.size();
    vector<int> leftMax(size, -1);
    int i = 0;
    int max = 0;
    while(i < size){
        if(max > A[i])
            leftMax[i] = max;
        else max = A[i];
        i++;
    }
    int result = 0;
    i = size-1;
    max = 0;
    while(i >= 0){
        if(leftMax[i] != -1 && max > A[i])
            result += min(leftMax[i], max) - A[i];
        if(A[i] > max)max = A[i];
        i--;
    }
    return result;
}
