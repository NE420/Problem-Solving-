/*
Your task is to write a program that can decide whether you can find an arithmetic expression consisting
of five given numbers ai (1 ≤ i ≤ 5) that will yield the value 23.
For this problem we will only consider arithmetic expressions of the following from:
(((aπ(1) o1 aπ(2)) o2 aπ(3)) o3 aπ(4)) o4 aπ(5)
where π : {1, 2, 3, 4, 5} → {1, 2, 3, 4, 5} is a bijective function and oi ∈ {+, −, ∗}(1 ≤ i ≤ 4)
Input
The Input consists of 5-Tupels of positive Integers, each between 1 and 50.
Input is terminated by a line containing five zero’s. This line should not be processed. Input file
will have no more than 25 lines.
Output
For each 5-Tupel print ‘Possible’ (without quotes) if their exists an arithmetic expression (as described
above) that yields 23. Otherwise print ‘Impossible’.
Sample Input
1 1 1 1 1
1 2 3 4 5
2 3 5 7 11
0 0 0 0 0
Sample Output
Impossible
Possible
Possible
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

using namespace std;

unordered_set<int> sol;

bool maze(vector<int>& items, int index, long long sum)
{
	/*cout << sum << "\n";
	if (sum > Max) {
		Max = sum;
	}*/

	if (sum == 23 && index == items.size()) {
		return 1;
	}

	if (index >= items.size()) {
		return 0;
	}

	if (maze(items, index + 1, sum + items[index]))
	{
		return 1;
	}


	if (maze(items, index + 1, sum - items[index]))
	{
		return 1;
	}


	if (maze(items, index + 1, sum * items[index]))
	{
		return 1;
	}

	return 0;
}

int main()
{
	//cin.tie(0), cout.tie(0), cin.sync_with_stdio(false), cout.sync_with_stdio(false);
	vector<int> nums(5);

	while (1) {

		bool found = false;

		for (int i = 0; i < 5; i++)
		{
			cin >> nums[i];
		}

		if (nums[0] == 0) {
			break;
		}

		sort(nums.begin(), nums.end());

		if (maze(nums, 1, nums[0]))
		{
			found = true;
		}

		while (next_permutation(nums.begin(), nums.end()))
		{
			/*for (auto i : nums) {
				cout << i << " ";
			}
			cout << "\n";*/
			if (maze(nums, 1, nums[0]))
			{
				found = true;
				break;
			}
		}

		if (found) {
			cout << "Possible\n";
		}
		else
		{
			cout << "Impossible\n";
		}

	}

	return 0;
}
