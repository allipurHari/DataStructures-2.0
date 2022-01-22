// https://leetcode.com/problems/binary-watch/

string createString(int hours, int minutes){
        string stringHour = to_string(hours);
        string stringMinute = to_string(minutes);

        if(minutes < 10){
            stringMinute = "0" + stringMinute;
        }
        return stringHour + ":" + stringMinute;
    }
    
    
    void function(vector<int> hourVector, vector<int> minuteVector, int hourIndex, int minuteIndex, int hours, int minutes, int noOfCount, int totalCount, vector<string>&ans, int dp[12][60]){
        
        if(hours > 11 || minutes > 59 || dp[hours][minutes])return;
        
        if(noOfCount == totalCount){
            dp[hours][minutes] = 1;
            ans.push_back(createString(hours, minutes));
            return;
        }
        
        if(hourIndex == hourVector.size() || minuteIndex == minuteVector.size())return;
        
        if(hourIndex+1 != hourVector.size()){
            hours += hourVector[hourIndex+1];
            function(hourVector, minuteVector, hourIndex+1, minuteIndex, hours, minutes, noOfCount+1, totalCount, ans, dp);
            hours -= hourVector[hourIndex+1];
            function(hourVector, minuteVector, hourIndex+1, minuteIndex, hours, minutes, noOfCount, totalCount, ans, dp);
        }
        
        if(minuteIndex+1 != minuteVector.size()){
            minutes += minuteVector[minuteIndex+1];
            function(hourVector, minuteVector, hourIndex, minuteIndex+1, hours, minutes, noOfCount+1, totalCount, ans, dp);
            minutes -= minuteVector[minuteIndex+1];
            function(hourVector, minuteVector, hourIndex, minuteIndex+1, hours, minutes, noOfCount, totalCount, ans, dp);
        }
        
    }
    
    
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string>ans;
        
        vector<int>hourVector{1, 2, 4, 8};
        vector<int>minuteVector{1, 2, 4, 8, 16, 32};
        int dp[12][60] = {0};
        
        int hourIndex = -1, minuteIndex = -1;
        int hours = 0, minutes = 0;
        int noOfCount = 0, totalCount = turnedOn;
        
        function(hourVector, minuteVector, hourIndex, minuteIndex, hours, minutes, noOfCount, totalCount, ans, dp);
        
        return ans;
    }


// Optimized solution

class Solution {
public:
    string createString(int hours, int minutes){
        string stringHour = to_string(hours);
        string stringMinute = to_string(minutes);

        if(minutes < 10){
            stringMinute = "0" + stringMinute;
        }
        return stringHour + ":" + stringMinute;
    }
    
    
    void function(string s, int index, int count, vector<string>&ans){
        
        int hours = stoi(s.substr(0,4),0,2);
        int minutes = stoi(s.substr(4,6),0,2);
        
        if(hours > 11 || minutes > 59)return;
        
        if(count == 0){
            ans.push_back(createString(hours, minutes));
            return;
        }
        
        for(int i = index;i < s.size();i++){
            s[i] = '1';
            function(s, i+1, count-1, ans);
            s[i] = '0';
        }
        
    }
    
    
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string>ans;
        int dp[12][60] = {0};
        
        string s = "0000000000";
        
        function(s, 0, turnedOn, ans);
        
        return ans;
    }
};
