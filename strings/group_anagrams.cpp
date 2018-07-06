/*
Leetcode task from https://leetcode.com/problems/group-anagrams/description/

Pseudo code

map<string, int> hash

for word in words
    tmp = word
    sort(word)
    if (!hash[word]) hash[word] = new_index
    strings[hash[word]] put tmp
    
    return strings
    
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, int> hash;
        int index = 0;
        
        vector<vector<string>> res_anagrams;
        
        for (string word: strs) {
            string tmp = word;
            sort(word.begin(), word.end());
            
            if (hash.find(word) == hash.end()) {
                hash[word] = index;
                index++;
                vector<string> empty_vec;
                res_anagrams.push_back(empty_vec);
            }
            res_anagrams[hash[word]].push_back(tmp);
        }
        return res_anagrams;
    }
};

