/*
Leetcode task from https://leetcode.com/problems/brick-wall/description/

Pseudo code:

end_places = [max length in array]

for each array line:
    i = 0
    for each num in line:
        i += num
        end_places[i] += 1
        
counter = 0
for end in end_places[:-1]:
    counter = max(counter, end)
    
return array size - counter        
*/

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        map<int, int> end_places;
        
        for (vector<int> line: wall) {
            int i = 0;
            for (int ind = 0; ind < line.size() - 1; ++ind) {
                i += line[ind];
                if (end_places.count(i)) end_places[i] ++;
                else end_places[i] = 1;
            }
        }
        
        int counter = 0;
        for (map<int, int>::iterator it = end_places.begin(); it != end_places.end(); ++it)  {
            counter = max(counter, it->second);
        }
        return wall.size() - counter;
    
    }
};

