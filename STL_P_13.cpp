/*
Given a set of lowercase English letters, count the number of distinct elements in the set.
Input
The first and only line contains the set, beginning with an opening curved bracket, followed by the elements of the set separated by commas then a closing curved bracket. The number of elements in the set does not exceed 1000.
Output
Output the number of distinct letters in the set.

Sample 1
  
Input	
{a, b, c}
Output
3
Sample 2
Input	
{b, a, b, a}
Output
2
Sample 3
Input	
{}
Output
0
*/

#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;


int main()
{
	cin.tie(nullptr), cout.tie(nullptr), cin.sync_with_stdio(false), cout.sync_with_stdio(false);
	
	set<int> levels;
	string line;
	getline(cin, line);

	for (int i = 0; i < line.size(); i++)
	{
		if (line[i] >= 'a' && line[i] <= 'z') {
			levels.insert(line[i]);
		}
	}

	cout << levels.size();
	
	return 0; 

}
