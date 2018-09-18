/*
Hackerrank task from https://www.hackerrank.com/challenges/count-triplets-1/problem

Pseudo code (brute force):

map<int, vector<int>> map (num: indeces)
for each el in array[1:]:
    for index in map[el / r]:
        if index < el index:
            count_lower++
    for index in map[el * r]:
        if index > el index:
            count_upper++
    count += (count_lower * count_upper)
return count

Faster solution:

map2 -> counter for potential triplets (2/3 triplet)
map3 -> counter of triplets

for each el in array:
    if exists in map3:
        count += map3[el]
    if exists in map2:
        map3[el * r] += map2[el]
    map2[el * r]++ 
return count
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the countTriplets function below.
long countTripletsBruteForce(vector<long> arr, long r) {
    unordered_map<long, vector<int>> dict;
    int count = 0;
    
    for (int i = 0; i < arr.size(); ++i) {
        if (!dict.count(arr[i])) dict[arr[i]] = {i};
        else dict[arr[i]].push_back(i);
    }

    for (int i = 1; i < arr.size(); ++i) {
        int count_lower = 0;
        int count_upper = 0;
        
        if (!dict.count(arr[i] / r) || !dict.count(arr[i] * r)) continue;
        for (int index: dict[arr[i] / r]) {
            if (index < i) count_lower++;
        }
        for (int index: dict[arr[i] * r]) {
            if (index > i) count_upper++;
        }
        count += (count_lower * count_upper);
    }
    return count;
}

// Faster solution
long long countTriplets(vector<long> arr, long r) {
    unordered_map<long, long> map2;
    unordered_map<long, long> map3;
    long long count = 0;
    
    for (long el: arr) {
        if (map3.count(el)) count += map3[el]; // triplet exists
        if (map2.count(el)) map3[el * r] += map2[el]; // potential triplet
        map2[el * r]++; // potential 2/3 triplet
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nr_temp;
    getline(cin, nr_temp);

    vector<string> nr = split(rtrim(nr_temp));

    int n = stoi(nr[0]);

    long r = stol(nr[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<long> arr(n);

    for (int i = 0; i < n; i++) {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    long ans = countTriplets(arr, r);

    fout << ans << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}



