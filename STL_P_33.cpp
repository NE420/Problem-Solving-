/*
You are given a list of N numbers and Q queries. Each query is specified by two numbers i and j; the answer to each query is the minimum number between the range [i, j] (inclusive).

Note: the query ranges are specified using 0-based indexing.

Input
The first line contains N, the number of integers in our list (N <= 100,000). The next line holds N numbers that are guaranteed to fit inside an integer. Following the list is a number Q (Q <= 10,000). The next Q lines each contain two numbers i and j which specify a query you must answer (0 <= i, j <= N-1).

Output
For each query, output the answer to that query on its own line in the order the queries were made.

Example
  
Input	
3
1 4 1
2
1 1
1 2

Output
4
1
*/

#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <cstring>
#define ll long long

using namespace std;

const int N = 1e4 + 5;

int main() {

    cin.tie(nullptr), cout.tie(nullptr), cin.sync_with_stdio(false), cout.sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> list(n);
    for (int i = 0; i < n; i++)
    {
        cin >> list[i];
    }
    int q;
    cin >> q;
    
    for (int i = 0; i < q; i++)
    {
        pair<int, int> query;
        cin >> query.first >> query.second;
        cout << *min_element(list.begin() + query.first, list.begin() + query.second + 1) << "\n";
    }

    return 0;
}
