/*
Hackerrank task from https://www.hackerrank.com/challenges/sherlock-and-valid-string/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=strings
*/

#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
    vector<int> char_occur(26, 0);
    for (char ch: s) {
        char_occur[ch - 'a']++;
    }
    
    bool diff_num = false;
    int same_count = 0;
    for (int el: char_occur) {
        if (!same_count && el) same_count = el;
        else if (el != same_count && el) {
            // cout << el << " " << same_count << endl;
            if (!diff_num) {
                if (el - 1 != same_count && el != 1) return "NO";
                else diff_num = true;
            } else return "NO";
        }
    }
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

