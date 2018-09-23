/*
 Repeatition of major sorting algorithms
 
 - Selection sorting:
 
     At each step find the minimum of unsorted part and put at the right index
 
 - Bubble sort:
 
     At each step compare A[i] and A[i+1] and swap if first bigger than second.
     Compare and swap until all sorted
 
 - Insertion sort:
 
     Keep sorted part to the left and for each element from the right part
     Put it on the right position in the left part
 
 - Merge sort:
 
     Divide and conquer:
        Divide in the middle while possible and
        then merge left and right parts (which should be already sorted)
 
 - Quick sort:
 
    Choose a pivot (randomly, can be the middle element)
    Partition array so that all elements <= pivot are before all elements > pivot
    For parts do quicksort again
 
 - Heap sort:
 
     1. Build heap from the array (for ith node children are: i*2 + 1 and i*2 + 2)
     2. For current heap - heapify (make the root max)
     3. Move current root to the end and repeat with reduced array (without the last)
 
  - Top sort:
 
 
 */

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

// Selection sort
int find_min(vector<int>& arr, int place_index) {
    int min_index = place_index;
    int min = arr[place_index];
    for (int i = place_index + 1; i < arr.size(); ++i) {
        if (arr[i] < min) {
            min = arr[i];
            min_index = i;
        }
    }
    return min_index;
}

void selection_sort(vector<int>& arr) {
    int place_index = 0;
    int curr_min;
    while (place_index < arr.size()) {
        curr_min = find_min(arr, place_index);
        swap(arr[curr_min], arr[place_index]);
        place_index++;
    }
}

// Bubble sort
void bubble_sort(vector<int>& arr) {
    
    for (int i = 0; i < arr.size(); ++i) {
        bool flag = false;
        for (int j = 0; j < arr.size() - i - 1; ++j) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                flag = true;
            }
        }
        if (!flag) return;
    }
}

// Insertion sort
void insertion_sort(vector<int>& arr) {
    int hole = 0;
    for (int i = 0; i < arr.size(); ++i) {
        int mem = arr[i];
        hole = i;
        while (hole > 0 && arr[i] < arr[hole-1]) {
            arr[hole] = arr[hole - 1];
            hole--;
        }
        arr[hole] = mem;
    }
}

// Merge sort
vector<int> merge(vector<int>& left_part, vector<int>& right_part) {
    vector<int> res;
    int left = 0;
    int right = 0;
    while (left < left_part.size() && right < right_part.size()) {
        if (left_part[left] < right_part[right]) {
            res.push_back(left_part[left]);
            left++;
        } else {
            res.push_back(right_part[right]);
            right++;
        }
    }
    while (left < left_part.size()) {
        res.push_back(left_part[left]);
        left++;
    }
    while (right < right_part.size()) {
        res.push_back(right_part[right]);
        right++;
    }
    return res;
}

void merge_sort(vector<int>& arr) {
    if (arr.size() < 2) return;
    
    int mid = arr.size() / 2;
    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());
    merge_sort(left);
    merge_sort(right);
    arr = merge(left, right);
}

// Quick sort
int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[(left + right) / 2];
    
    while (left <= right) {
        while (arr[left] < pivot) {
            left++;
        }
        while (arr[right] > pivot) {
            right--;
        }
        if (left <= right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
    return left;
}

void quick_sort(vector<int>& arr, int left, int right) {
    if ((right - left) < 2) return;
    
    int index = partition(arr, left, right);
    quick_sort(arr, left, index - 1);
    quick_sort(arr, index, right);
}

// Heap sort
void heapify(vector<int>& arr, int end, int root) {
    int largest = root;
    int left = root * 2 + 1;
    int right = root * 2 + 2;
    
    if (left < end && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < end && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != root) {
        swap(arr[root], arr[largest]);
        heapify(arr, end, largest);
    }
}

void heap_sort(vector<int>& arr) {
    // first build a max-heap of the array (starting from the prev-last level)
    for (int i = arr.size() / 2 - 1; i >= 0; --i) {
        heapify(arr, arr.size(), i);
    }
    
    // make max-heap n times
    for (int i = arr.size() - 1; i >= 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Testing
void test_edge(void sorting(vector<int>&)) {
    vector<int> arr = {1};
    vector<int> sorted = {1};
    sorting(arr);
    arr == sorted ? cout << "OK" : cout << "Test edge didn't pass";
    cout << endl;
    
    arr = {};
    sorted = {};
    sorting(arr);
    arr == sorted ? cout << "OK" : cout << "Test edge didn't pass";
    cout << endl;
    
    arr = {1, 1, 1, 1};
    sorted = {1, 1, 1, 1};
    sorting(arr);
    arr == sorted ? cout << "OK" : cout << "Test edge didn't pass";
    cout << endl;
}

void test_edge_quick(void sorting(vector<int>&, int , int)) {
    vector<int> arr = {1};
    vector<int> sorted = {1};
    sorting(arr, 0, arr.size() - 1);
    arr == sorted ? cout << "OK" : cout << "Test edge didn't pass";
    cout << endl;
    
    arr = {};
    sorted = {};
    sorting(arr, 0, arr.size() - 1);
    arr == sorted ? cout << "OK" : cout << "Test edge didn't pass";
    cout << endl;
    
    arr = {1, 1, 1, 1};
    sorted = {1, 1, 1, 1};
    sorting(arr, 0, arr.size() - 1);
    arr == sorted ? cout << "OK" : cout << "Test edge didn't pass";
    cout << endl;
}

void test_random(void sorting(vector<int>&)) {
    vector<int> arr = {1, 5, 2, 3, 7};
    vector<int> sorted = {1, 2, 3, 5 ,7};
    sorting(arr);
    arr == sorted ? cout << "OK" : cout << "Test random didn't pass";
    cout << endl;
    
    arr = {1, 1, 2, 1, 6, 3};
    sorted = {1, 1, 1, 2, 3, 6};
    sorting(arr);
    arr == sorted ? cout << "OK" : cout << "Test random didn't pass";
    cout << endl;
}

void test_random_quick(void sorting(vector<int>&, int, int)) {
    vector<int> arr = {1, 5, 2, 3, 7};
    vector<int> sorted = {1, 2, 3, 5 ,7};
    sorting(arr, 0, arr.size() - 1);
    arr == sorted ? cout << "OK" : cout << "Test random didn't pass";
    cout << endl;
    
    arr = {1, 1, 2, 1, 6, 3};
    sorted = {1, 1, 1, 2, 3, 6};
    sorting(arr, 0, arr.size() - 1);
    arr == sorted ? cout << "OK" : cout << "Test random didn't pass";
    cout << endl;
}

int main() {
    test_edge(heap_sort);
    test_random(heap_sort);
    
//    test_edge_quick(quick_sort);
//    test_random_quick(quick_sort);
    return 0;
}
