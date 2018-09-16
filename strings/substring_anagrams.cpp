#include <bits/stdc++.h>
#include <iostream>
#include <string>

/*

Hackerrank task from https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dictionaries-hashmaps

Pseudo code:

write separate function for checking if anagram

check for every length of string 
    if pair of strings are anagrams
*/

using namespace std;

bool is_anagram(string s1, string s2) {
    vector<int> chars1(26, 0);
    vector<int> chars2(26, 0);
    
    for (int i = 0; i < s1.length(); ++i) {
        chars1[s1[i] - 'a']++;
        chars2[s2[i] - 'a']++;
    }

    for (int i = 0; i < 26; ++i) {
        if (chars1[i] != chars2[i]) return false;
    }
    return true;
}

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
    int counter = 0;
    
    for (int len = 1; len < s.length(); ++len) {
        for (int i = 0; i < s.length() - len; ++i) {
            for (int j = i + 1; j <= s.length() - len; ++j) {
                cout << len << " " << i << " " << j << " " << counter << endl;
                string s1 = s.substr(i, len);
                string s2 = s.substr(j, len);
                cout << s1 << " " << s2 << endl;
                counter += is_anagram(s1, s2);
            }
        }
    }
    return counter;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

