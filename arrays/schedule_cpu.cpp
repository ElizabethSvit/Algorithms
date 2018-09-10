/*
Leetcode task from https://leetcode.com/problems/task-scheduler/description/

Pseudo code:

count maximum frequency for nums
count how many nums have the highest frequency

count the least characters needed to arrange with n interval
if the length of all nums is bigger -> return it instead of the counted least
*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<int, int> stats;
        
        for (char ch: tasks) {
            stats[ch - 'A']++;
        }
        
        int max = 0;
        int num = 0;
        
        for (map<int, int>::iterator it = stats.begin(); it != stats.end(); ++it) {
            if (it->second == max) {
                num++;
            } 
            if (max < it->second) {
                max = it->second;
                num = 1;
            }
        }
        
        // for one character: max - 1 intervals between, n + 1 is length of inteval + char
        int least = (n + 1) * (max - 1) + num;
        
        return least > tasks.size() ? least : tasks.size();
    }
};

