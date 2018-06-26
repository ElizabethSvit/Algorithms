/*
 Google GetAhead program, week 4 problem
 (leetcode: https://leetcode.com/problems/largest-rectangle-in-histogram/description/)
 
 Given an array of non-negative integers that represent the bars (y value) in a histogram (with the array index being the x value), find the rectangle with the largest area under the curve and above the axis. Return the pair of array indices that represent the rectangle.
 
 Test Cases
 Note that there may be other valid answers.
 For array [2,4,2,1], largest area is 6, with height 2, and width from indices 0 to 2.
 For array [2,4,2,1,10,6,10] the largest area is 18, with height 6 and width from indices 4 to 6.
 
 Pseudo code (O(n^2)):
 
 init sum = 0
 init max_sum = 0
 
 for block in 1..n:
    go left while not left edge and prev_block >= block
        sum += block
    go right while not right edge and next_block >= block
        sum += block
    max_sum = max(sum, max_sum)
 return max_sum
 
 Pseudo code (O(n)):
 
 init stack (of indeces)
 max_area = 0
 L = 0
 
 for i in 1..n:
     while (!stack.empty && (H[i] < H[stack.top()] || i == H.size())):
        L = stack.top
        stack.pop
        max_area = max(max_area, H[L] * (stack.empty() ? i : i - stack.top() - 1))
     stack.push(i)
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int largest_area_slow(const vector<int> &bars) {
    int max_area = 0;
    int area = 0;
    int curr_ind, curr_bar;
    
    for (int i = 0; i < bars.size(); ++i) {
        curr_ind = i;
        curr_bar = bars[curr_ind];
        area = 0;
        while (i >= 0 && bars[i] >= curr_bar) {
            area += curr_bar;
            i--;
        }
        i = curr_ind + 1;
        while (i < bars.size() && bars[i] >= curr_bar) {
            area += curr_bar;
            i++;
        }
        i = curr_ind;
        max_area = max(max_area, area);
    }
    return max_area;
}

int largest_area_fast(const vector<int> &heights) {
    stack<int> st;
    int L = 0;
    int max_area = 0;
    int i = 0;
    
    for (; i <= heights.size(); ++i) {
        while ( !st.empty() && (heights[i] < heights[st.top()] || i == heights.size())) {
            L = st.top();
            st.pop();
            max_area = max(max_area, heights[L] * (st.empty() ? i : i - st.top() - 1));
        }
        st.push(i);
    }
    
    return max_area;
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    vector<int> bars(n);
    for (int i = 0; i < n; ++i) {
        cin >> bars[i];
    }
    cout << largest_area_fast(bars);
    return 0;
}
