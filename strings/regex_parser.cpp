/*
Basic Regex Parser from pramp.com website

Implement a regular expression function isMatch that supports the '.' and '*' symbols. 
The function receives two strings - text and pattern - and should return true 
if the text matches the pattern as a regular expression. For simplicity, 
assume that the actual symbols '.' and '*' do not appear in the text string and 
are used as special symbols only in the pattern string.

In case you aren’t familiar with regular expressions, the function determines 
if the text and pattern are the equal, where the '.' is treated as a single a character wildcard (see third example), 
and '*' is matched for a zero or more sequence of the previous letter (see fourth and fifth examples). 
For more information on regular expression matching, see the Regular Expression Wikipedia page.

Explain your algorithm, and analyze its time and space complexities.

Examples:

input:  text = "aa", pattern = "a"
output: false

input:  text = "aa", pattern = "aa"
output: true

input:  text = "abc", pattern = "a.c"
output: true

input:  text = "abbb", pattern = "ab*"
output: true

input:  text = "acd", pattern = "ab*c."
output: true
Constraints:

[time limit] 5000ms
[input] string text
[input] string pattern
[output] boolean
*/

/*
Pseudo testing

- - a . b
- 1 0 0 0
a 0 1 0 0 
a 0 0 1 0
b 0 0 0 1

- - a b * c .
- 1 0 0 0 0 0
a 0 1 0 1 0 0
c 0 0 0 0 1 0
d 0 0 0 0 0 1

- - a b * 
- 1 0 0 0 
a 0 1 0 1
b 0 0 1 1
b 0 0 0 1
b 0 0 0 1

- - . *
- 1 0 1
a 0 1 1

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_match(const string &text, const string &pattern) {
    if (!text.size()) {
        return (pattern.size() == 2 && pattern[1] == '*') || (!pattern.size());
    }
    
    vector<vector<bool>> D(text.size() + 1, vector<bool> (pattern.size() + 1, false));
    D[0][0] = true;
    
    for (int i = 1; i < D.size(); ++i) {
        for (int j = 1; j < D[i].size(); ++j) {
            if (text[i-1] == pattern[j-1] || pattern[j-1] == '.') {
                D[i][j] = D[i-1][j-1];
            } else if (pattern[j-1] == '*') {
                if (i >= 2 && text[i-1] == text[i-2]) D[i][j] = D[i-1][j];
                else D[i][j] = D[i][j-2] || D[i-1][j-2]; // assume that j >= 2, because star has one char before itself
            }
        }
    }
    return D[text.size()][pattern.size()];
}



