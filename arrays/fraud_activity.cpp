/*
Hackerrank task from https://www.hackerrank.com/challenges/fraudulent-activity-notifications/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=sorting&h_r=next-challenge&h_v=zen

Pseudo code:

using counting sort store all counts for each value
go thru stored counts and with indeces find the median and check the conditions
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the activityNotifications function below.
int activityNotifications(vector<int> expenditure, int d) {
    if (expenditure.size() <= d) return 0;
    
    vector<int> counts(201, 0);
    int result = 0;
    
    for (int i = 0; i < d; ++i) {
        counts[expenditure[i]]++;
    }
    
    for (int i = d; i < expenditure.size(); ++i) {
        int lower = 0;
        int left_num = 0;
        int upper = counts.size() - 1;
        int right_num = 0;
        
        while ((left_num + counts[lower]) * 2 <= d) {
            left_num += counts[lower++];
        }
        while ((right_num + counts[upper]) * 2 <= d) {
            right_num += counts[upper--];
        }
        result += (expenditure[i] >= upper + lower);
        counts[expenditure[i]]++;
        counts[expenditure[i - d]]--;
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}



