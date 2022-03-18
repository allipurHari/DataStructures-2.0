// https://www.interviewbit.com/problems/merge-intervals/discussion/

vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> result;
    result.push_back(newInterval);
 
    for(int i = 0; i < intervals.size(); i++){
        int j = result.size()-1;
        Interval a = result[j];
        Interval b = intervals[i];
        
        if(a.end < b.start){
            result.push_back(b);
        }
        else if(b.end < a.start){
            result[j] = b;
            result.push_back(a);
        }
        else{
            int mn = min(a.start, b.start);
            int mx = max(a.end, b.end);
            result[j].start = mn;
            result[j].end = mx;
        }
    }
    return result;
}
