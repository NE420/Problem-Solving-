/*
There is a network of 
N
N people. Each person has an ID from 0 to 
N
−
1
N−1. In this network, some people are friends with each other. A person can ask a favor of another person directly if they are friends.

If a person wants to ask a favor of someone who is not his friend, he needs to use intermediate people. For example, if 
B
B is friends with both 
A
A and 
C
C and 
A
A wants to ask a favor of 
C
C, but 
A
A and 
C
C are not friends, then 
A
A can ask a favor of 
B
B and 
B
B can ask the favor of 
C
C.

It is guaranteed that there always exist a way for every person to ask a favor of every other person.

Given the list of friends of each person in the network, and two IDs 
A
A and 
B
B where person 
A
A wants to ask person 
B
B a favor, find the minimum number of intermediate people needed for 
A
A to ask a favor of 
B
B.
Input
The input consists of multiple test cases. The first line is the number of test cases 
T
T.

The first line of each test case consists of a single integer 
N
N which is the number of people in the network.
Then, 
N
N lines follow, 1 <= 
N
N <= 105. Each line contains a description of the friends list of a person in the network. The line starts with a integer 
c
c which represents the ID of the person whose friends list is on this line. Then, a integer 
n
nc follows. This represents the number of people in the list. Then 
n
nc integers follow (
n
nc <= 100), these are the IDs of the friends of 
c
c.

Finally, a line with two integers 
A
A and 
B
B. These are the IDs mentioned in the question.

Output
For each test case, output three integers: 
A
A, 
B
B, and the minimum number of intermediate people for 
A
A to ask a favor of 
B
B. Note that the outputs of two consecutive cases should be separated by a blank line, but the last test case should not be followed by a blank line.
Sample Input
1

4
0 3 1 2 3
1 1 0
2 2 0 3
3 2 0 2
1 2
Sample Output
1 2 1
*/

#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#define ll long long

using namespace std;

vector<int> sol;

void bfs(int src, vector<vector<int>>& adj, int& target, int& out)
{
	// number of nodes in the graph
	int n = adj.size();

	// initialize INF with a large value
	const int INF = 1e9;

	// distance from the source to each node
	vector<int> dist(n, INF);

	// queue to hold the current nodes
	queue<int> q;

	// push the source node to the queue and set its distance to 0
	q.push(src);
	dist[src] = 0;
	if (src == target) 
	{
		out = dist[src];
	}
	while (!q.empty()) 
	{
		// get the front node in the queue and pop it
		int u = q.front();

		q.pop();

		// add the next nodes to the queue
		for (int v : adj[u]) 
		{
			// if the node is not visited yet
			if (dist[v] == INF) 
			{
				dist[v] = dist[u] + 1; // to get the distace to any node in dist[node]
				if (v == target) 
				{
					out = dist[v];
				}
				q.push(v);
			}
		}

	}

}

int main()
{
	cin.tie(0), cout.tie(0), cin.sync_with_stdio(false), cout.sync_with_stdio(false);

	int n, T;

	cin >> T;

	while (T--)
	{
		int A, B;
		cin >> n;

		vector<vector<int>> adj_list(n);
		//vector<bool> vis(n);

		for (int i = 0; i < n; ++i)
		{
			int a, num;
			cin >> a >> num;
			for (int j = 0; j < num; j++)
			{
				int a_friend;
				cin >> a_friend;
				adj_list[a].push_back(a_friend);
			}
		}
		cin >> A >> B;
		int out = 0;
		bfs(A, adj_list, B, out);
		

			if (T == 0) {
				cout << A << " " << B << " " << out - 1 << "\n";
			}
			else
			{
				cout << A << " " << B << " " << out - 1 << "\n\n";
			}
		
	}

	return 0;
}
