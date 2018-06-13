/*
Leetcode task from https://leetcode.com/problems/valid-parentheses/description/

Pseudo code:

init stack for open parentheses
for ch in string:
    if ch is in ['[', '{', '(']:
        push ch to stack
    else:
        get top stack bracket
        if top_bracket is not opening bracket for ch:
            return false
            
return true  

*/

class Solution {
public:
    
    bool check_equal(char open_parent, char close_parent) {
        return open_parent == '(' && close_parent == ')' ||
            open_parent == '{' && close_parent == '}' ||
            open_parent == '[' && close_parent == ']';
    }
    
    
    bool isValid(string s) {
        stack<char> open_parent;
        char top_parent;
        
        for (char ch: s) {
            if (ch == '[' || ch == '{' || ch == '(') {
                open_parent.push(ch);
            } else {
                if (open_parent.empty()) return false;
                
                top_parent = open_parent.top();
                open_parent.pop();
                if (!check_equal(top_parent, ch)) {
                    return false;
                }
            }
        }
        return open_parent.empty();
    }
};

