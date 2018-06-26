/*

Leetcode task from https://leetcode.com/problems/remove-invalid-parentheses/description/

Pseudo code:

init queue q
init visited
init res_arr

while (!q.empty()):
    str = q.front
    q.pop
    if (isValid(str)):
        res_arr.push(str)
        continue
    for i in 0..n:
        if str[i] == '(' or str[i] == ')':
            temp = str.substr(0, i) + str.substr(i+1, str.size())
            if (temp is not in visited):
                q.push(temp)
return res_arr
*/

class Solution {
public:
    
    bool is_valid(string str) {
        int cnt = 0;
        for (char ch: str) {
            if (ch == '(') cnt++;
            if (ch == ')') cnt--;
            if (cnt < 0) return false;
        }
        return cnt == 0;
    }
    
    vector<string> removeInvalidParentheses(string s) {
        queue<string> q;
        vector<string> res_arr;
        set<string> visited;
        bool found = false;
        
        q.push(s);
        visited.insert(s);
        
        string str, temp;
        
        while (!q.empty()) {
            str = q.front();
            q.pop();
            if (is_valid(str)) {
                res_arr.push_back(str);
                found = true;
            } 
            if (found) continue;
            for (int i = 0; i < str.length(); ++i) {
                if (str[i] == '(' || str[i] == ')') {
                    temp = str.substr(0, i) + str.substr(i+1);
                    if (visited.find(temp) == visited.end()) {
                        q.push(temp);
                        visited.insert(temp);
                    }
                }
            }
        }
        return res_arr;
    }
};

