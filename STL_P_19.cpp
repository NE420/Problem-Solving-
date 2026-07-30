/*
There are n customers waiting to be serviced in the queue of a certain shop. We know that the ith customer needs time ti to be serviced. A customer is angry if the time he spends waiting in the queue is more than the time needed to serve him. A customer waits in the queue for a time equal to the sum of servicing times of the customers in front of him in the queue. You can swap people in the queue.

What is the maximum number of non angry customers that can be achieved by swapping people in the queue.

Input
The first line contains integer n (1 ≤ n ≤ 105).

The next line contains n integers ti (1 ≤ ti ≤ 109), separated by spaces.

Output
Print a single number — the maximum number of not angry people in the queue.

Sample 1
  
Input	
5
15 2 1 5 3
  
Output
4
  
Note
Value 4 is achieved at such an arrangement, for example: 1, 2, 3, 5, 15. Thus, you can make everything feel not angry except for the person with time 5.
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
	deque<int> line;
	int tmp = n;
	while (n--)
	{
		int input;
		cin >> input;
		line.push_back(input);
	}
	sort(line.begin(), line.end());

	int num = 0, turn = 0;
	
	for (int i = 0; i < tmp; i++)
	{
		if ( line[i] >= turn) 
		{
			turn += line[i];
			num++;
		}
	}
	
	cout << num <<"\n";

	return 0;
}
