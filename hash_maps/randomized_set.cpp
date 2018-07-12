/*
Leetcode task from https://leetcode.com/problems/insert-delete-getrandom-o1/description/

*/

class RandomizedSet {
private:
    map<int, int> value_indeces;
    vector<int> values;
    
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (value_indeces.count(val)) return false;
        
        value_indeces[val] = (int)values.size();
        values.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!value_indeces.count(val)) {
            return false;
        }
        
        int last_el = values.back();
        // swap indeces in the array of last and val
        value_indeces[last_el] = value_indeces[val];
        // change place of var to last 
        values[value_indeces[val]] = last_el;
        
        // remove last (new last saved)
        values.pop_back();
        // remove index of var
        value_indeces.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return values[rand() % (int)values.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

