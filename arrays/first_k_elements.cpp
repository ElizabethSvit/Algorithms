/*
Leetcode task from https://leetcode.com/problems/top-k-frequent-elements/

1 approach: put in the map, sort map, get frist k
2 approach: put in the map and MIN priority queue, pop if queue bigger than k, output reversed k elements of the queue (same as first, but using less space)
*/

class Solution {
public:
    vector<int> topKFrequentMy(vector<int>& nums, int k) {
        map<int, int> freqs;
        for (int num: nums) {
            freqs.count(num) ? freqs[num]++ : freqs[num] = 1;
        }
        
        vector<pair<int, int>> freqs_vec;
        for (map<int, int>::iterator it = freqs.begin(); it != freqs.end(); ++it) {
            freqs_vec.push_back(*it);
        }
        
        sort(freqs_vec.begin(), freqs_vec.end(), 
             [](pair<int, int> first, pair<int, int> sec) {
                 return first.second > sec.second;
             });
        
        vector<int> res;
        for (auto p: freqs_vec) {
            if (!k) break;
            res.push_back(p.first);
            k--;
        }
        
        return res;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freqs;
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
        greater<pair<int, int>> > pq;
        
        for (int num: nums) {
            freqs[num]++;
        }
        
        for (map<int, int>::iterator it = freqs.begin(); it != freqs.end(); ++it) {
            pq.push(make_pair(it->second, it->first));
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

