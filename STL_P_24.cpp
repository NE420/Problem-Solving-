/*
William Macfarlane wants to look at an array.

You are given a list of N numbers and Q queries. Each query is specified by two numbers i and j; the answer to each query is the sum of every number between the range [i, j] (inclusive).

Note: the query ranges are specified using 0-based indexing.

Input
The first line contains N, the number of integers in our list (N ≤ 100,000). The next line holds N numbers that are guaranteed to fit inside an integer. Following the list is a number Q (Q ≤ 10,000). The next Q lines each contain two numbers i and j which specify a query you must answer (0 ≤ i, j ≤ N-1).

Output
For each query, output the answer to that query on its own line in the order the queries were made.

Example
  
Input	
3
1 4 1
3
1 1
1 2
0 2

Output
4
5
6
*/

#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	cin.tie(nullptr), cout.tie(nullptr), cin.sync_with_stdio(false), cout.sync_with_stdio(false);

	int n;
	cin >> n;

	deque<long long> arr;
	for (int i = 0; i < n; i++)
	{
		long long num;
		cin >> num;
		arr.push_back(num);
	}

	deque<long long> prefixSum(n);
	prefixSum.push_front(arr[0]);
	for (int i = 1; i < n; i++)
		prefixSum[i] = prefixSum[i - 1] + arr[i];

	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{		
		int l, r;
		cin >> l >> r;
		if (l == 0) {
			cout << prefixSum[r] << "\n";
		}
				
		else {			
			cout << prefixSum[r] - prefixSum[l - 1] << "\n";
		}
	}

	return 0;
}
