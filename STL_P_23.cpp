/*
Given an array of integers of size N ( 1<=N<=105 ). You are asked to perform 2 types of queries :

(i) Query 1 : 1 l r

Given 2 integers l and r. ( 1 <= l <= r <= the current size of the array ). Print the sum of all the elements with indices between l and r inclusive.

(ii) Query 2 : 2 p

Given a single integer p ( |p| <= 109 ). Add this element to the beginning of the array. Notice that this operation changes the indices of all other elements of the array. All of the indices are increased by 1 and the newly added element has index 1. Also, the size of the array is increased by 1.

 

Input
The first line contains a single integer N ( 1 <= N <= 105 ), the number of elements initially in the array.

The second line contains N space separated integers, a1 a2 .... aN. ( |ai| <= 109 )

The next line contains a single integer Q, the number of operations you will be asked to perform. ( 1 <= Q <= 105 )

The following Q lines each contain a single query. Each such line starts with either the number 1 or the number 2. This indicates the type of operation that you are required to perform. The format of these queries are as described above.

Output
For each query of type 1, output the answer for this query on a new line. No output needs to be printed for queries of type 2.

 
Samples
Input #1:
10
1 2 3 4 5 6 7 8 9 10
4
1 1 10
1 1 1
1 10 10
1 2 7

Output #1:
55
1
10
27


Input #2:
5
6 7 8 9 10
9
2 5
2 4
1 2 7
2 3
2 2
2 1
1 1 10
1 1 1
1 10 10


Output #2:
45
55
1
10
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
	deque<long long> suffixSum(n, 0);
	for (int i = n - 1; i >= 0; --i) {
		suffixSum[i] = arr[i];
		if (i + 1 < n) {
			suffixSum[i] += suffixSum[i + 1];
		} 
	}
  
	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int query;
		cin >> query;
		if (query == 1) {
			//if (!tmpSum.empty()) {
			//	//for (int i = 0; i < tmpSum.size(); i++) {
			//	//	
			//	//	//arr.push_front(tmpSum[i]);
			//	//	prefixSum.push_front(1);
			//	//}
			//	arr.insert(arr.begin(), tmpSum.begin(), tmpSum.end());
			//	//prefixSum.insert(prefixSum.begin(), tmpSum.begin(), tmpSum.end());

			//	prefixSum[0] = arr[0];
			//	for (int i = 1; i < arr.size(); i++) {
			//		prefixSum[i] = prefixSum[i - 1] + arr[i];
			//	}
			//	tmpSum.clear();
			//suffixSum[l] - suffixSum[r + 1];
			//prefixSum[r] - prefixSum[l - 1]
			//}
			int l, r;
			cin >> l >> r;
			l--; r--;
			if (l == r) {
				cout << arr[l] << "\n";
			}
			else if (r == arr.size()-1) {
				cout << suffixSum[l] << "\n";
			}
			else
			{
				cout << suffixSum[l] - suffixSum[r + 1] << "\n";
			}	
		}
		else {
			long long entry;
			cin >> entry;
			arr.push_front(entry);
			suffixSum.push_front(entry + suffixSum.front());
		}
	}

	return 0;
}
