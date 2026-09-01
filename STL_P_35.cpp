/*
Azzam is a well known thief who decided to rob a Jewelry Shop and fill his bag with a lot of jewels .

Azzam has a bag with a capacity of 
N
N and there is 
m
m Jewels in the jewelry shop where the 
i
t
i 
t
​
 
h
h
​
  jewel takes capacity 
m
i
m 
i
​
  .

Well, Azzam is too greedy and he wants to fill the bag with the highest possible capacity (make it as full as possible), this means that he wants to minimize the empty space in the bag.
Assumptions
• Number of Jewels in the shop does not exceed 20.
• No Jewel's capacity is more than 
N
N.
• Jewels' capacity do not repeat (distinct).
• Capacity of each Jewel is expressed as an integer number.
Inputs
Any number of lines.
Each one contains value 
N
N, followed by the number of Jewels and capacity of Jewels .
For example from first line in sample data: N = 5, number of Jewels = 3, first capcity = 1, second one = 3, next one = 4.
Outputs
Set of Jewels' capacity which are the correct solutions and string ‘sum:’ and sum of jewels' capacity.
Sample Input
5 3 1 3 4
10 4 9 8 4 2
20 4 10 5 7 4
90 8 10 23 1 2 3 4 5 7
45 8 4 10 44 43 12 9 8 2
Sample Output
1 4 sum:5
8 2 sum:10
10 5 4 sum:19
10 23 1 2 3 4 5 7 sum:55
4 10 12 9 8 2 sum:45
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

using namespace std;

unordered_set<int> sol;

int bag(vector<int>& items, int index, int sum,int max_cap, vector<int>& taken)
{
	if (sum > max_cap) {
		taken.clear();
		return 0;
	}

	if (index == items.size()) {
		return sum;
	}

	if (index <= items.size()-1) {
		taken.push_back(items[index]);
	}

	vector<int> with_elems;
	int with_sum = bag(items, index + 1, sum + items[index], max_cap, with_elems);

	vector<int> without_elems;
	int without_sum = bag(items, index + 1, sum, max_cap, without_elems);

	if (with_sum > without_sum) {
		taken = with_elems;
		taken.push_back(items[index]);
		return with_sum;
	}
	else {
		taken = without_elems;
		return without_sum;
	}

}

int main()
{
	//cin.tie(0), cout.tie(0), cin.sync_with_stdio(false), cout.sync_with_stdio(false);

	int n,m;

	while (cin>> n >> m) {
		
		vector<int> items(m);
		vector<int> taken;
		for (int i = 0; i < m; i++) {
			cin >> items[i];
		}

		int max_items_sum = bag(items, 0, 0, n, taken);

		for (auto i : taken) {
			cout << i << " ";
		}
		cout << "sum:" << max_items_sum << "\n";

	}

	return 0;
}
