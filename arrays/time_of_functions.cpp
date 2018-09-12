/*
Leetcode task from https://leetcode.com/problems/exclusive-time-of-functions/description/

Pseudo code:

make func to return if start and id + time

for each task:
    if start:
        put in stack as [id, timestamp]
    if end:
        put in answ
        if stack is not empty:
            substract the last extracted func duration
*/

class Solution {
public:
    
    void get_id_state_time (string log, int& id, bool& start, int& time) {
        int delim1 = log.find(":");
        int delim2 = log.find(":", delim1 + 1);
                
        id = stoi(log.substr(0, delim1));
        time = stoi(log.substr(delim2 + 1));
        start = (log.substr(delim1 + 1, delim2 - delim1 - 1) == "start");
    }
    
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<pair<int, int>> starts;
        vector<int> res(n, 0);
        int id, time;
        bool start;
        
        for (string log: logs) {
            get_id_state_time(log, id, start, time);
            if (start) {
                starts.push({id, time});
            } else {
                int start_time = starts.top().second;
                starts.pop();
                
                int duration = time - start_time + 1;
                res[id] += duration;
                if (!starts.empty()) {
                    res[starts.top().first] -= duration;
                }
            }
        }
        return res;
    }
};

