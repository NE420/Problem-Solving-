/*
Jumping is healthy. But excess of anything is bad. So, You want to jump in a perfect discipline. You become healthy if the absolute values of the difference between every consecutive pair of integers are all numbers from 1 through n-1, where n is the size of the sequence. For example,

4 2 1 -2
is such a sequence that can make you healthy. Because the absolute differences are 2, 1 and 3 respectively. Now can you help yourself to become healthy?

Input
The input consists of multiple lines, each containing an integer n which does not exceed 3000 followed by n integers which represent the sequence.

Output
For each line of input, generate a line of output saying "Jolly" or "Not jolly".

Sample Input
4 1 4 2 3
5 1 4 2 -1 6
Sample Output
Jolly
Not jolly
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <cmath>

using namespace std;

int main()
{
	int n = 0;
	vector<int> vec;
	string line;
	set<int> mySet;
	string ans;

	while (true)
	{
		//cin >> n;
		getline(cin, line);

		if (line.empty()) {
			break;
		}
		
		istringstream iss(line);
		int number;
		while (iss >> number) {
			vec.push_back(number);
		}

		for (int i = 0; i < vec.size()-1; ++i) {
			mySet.insert(abs(vec[i] - vec[i + 1]));
		}
		ans = "Jolly\n";
		for (int i = 1; i < vec.size() - 1; ++i) {
			if (!(mySet.count(i) > 0)) {
				ans = "Not jolly\n";
			}
		}
		cout << ans;
		vec.clear();
		mySet.clear();
	}

}
