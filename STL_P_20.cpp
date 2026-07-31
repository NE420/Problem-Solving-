/*
You will be given an integer N, count the number of 1s present in the numbers from 1 to N inclusive if they are written in binary.

For example, if N=4, the numbers from 1 to 4 in binary are: 1, 10, 11, 100. So, there are 5 ones.

Input
First line contains, T, the number of test cases. Each test case consists of one integer per line denoting N.

Output
Print the required answer.

Constraints
1 ≤ T ≤ 1000
1 ≤ N ≤ 1000

Example
  
Input	
1
3
  
Output
4
*/

#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;


int main()
{
	cin.tie(nullptr), cout.tie(nullptr), cin.sync_with_stdio(false), cout.sync_with_stdio(false);

	int T;

	cin >> T;

	int n;
	
	for (int i = 0; i < T; i++) {
		long long sum = 0;
		cin >> n;
		for (int j = 1; j <= n; j++)
		{
			sum += __builtin_popcount(j);
		}
		cout << sum << "\n";
	}
	
	return 0;
}
