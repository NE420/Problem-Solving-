/*
Given a two-dimensional grid of cells consisting of '1’s and '0’s, ‘1’ donates a filled cell, and ‘0’ donates an empty cell. The filled cells are considered connected if they are adjacent to each other horizontally, vertically, or diagonally. You have to find the largest connected component of filled cells.

Input
The first line contains a single integer 
T
T which is the number of test cases. This line is followed by a blank line, and there is also a blank line between two consecutive inputs.

For each test case, The grid is given as a set of strings, The largest grid that should be considered is a 25×25 grid.

Output
For each test case, output the largest connected component of filled cells. The outputs of two consecutive cases will be separated by a blank line.

Sample Input
2

11000
01100
00101
10001
01011

00110
01111
01111
11001
01011

Sample Output
5

16
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
#define ll long long

using namespace std;

vector<int> sol;

bool isWithinBoundaries(int i, int j, int n, int m)
{
	return (i < n) && (j < m) && (i >= 0) && (j >= 0); // visited in grid is vector<vector<bool>>
}

vector<pair<int, int>> directions = { // just make i + directions.first and j + directions.second
{-1, 0},  // Up
{1, 0},   // Down
{0, -1},  // Left
{0, 1},   // Right
{-1, -1}, // Up-Left
{-1, 1},  // Up-Right
{1, -1},  // Down-Left
{1, 1}    // Down-Right
};

int DFS(int x,int y, vector<vector<char>>& adj_list, vector<vector<bool>>& visited)
{
	visited[x][y] = true;
	int ans = 1;
	for (int i = 0; i < 8; i++)
	{
		int nx = x + directions[i].first;
		int ny = y + directions[i].second;

		if ( isWithinBoundaries(nx, ny, adj_list.size(), adj_list.size()) && !visited[nx][ny] && adj_list[nx][ny] == '1')
		{
			ans += DFS(nx, ny, adj_list, visited);
		}
	}

	return ans;
}

int main()
{
	cin.tie(0), cout.tie(0), cin.sync_with_stdio(false), cout.sync_with_stdio(false);

	int T;

	cin >> T;
	cin.ignore();

	string blank;
	getline(cin, blank);

	while (T--)
	{
		vector<vector<char>> grid;
		string line;

		while (getline(cin, line) && !line.empty()) {
			vector<char> this_line;
			for (int i = 0; i < line.length(); i++)
			{
				this_line.push_back(line[i]);
			}
			grid.push_back(this_line);
		}

		vector<vector<bool>> vis(grid.size(), vector<bool> (grid.size()));

		int ans = 0;
		
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid.size(); j++)
			{
				if (grid[i][j] == '1' && !vis[i][j])
				{
					ans = max((DFS(i,j,grid,vis)), ans);
				}
			}
		}
	
		sol.push_back(ans);
		
	}

	for (int i = 0; i < sol.size(); i++)
	{
		if (i == sol.size() - 1) {
			cout << sol[i] << "\n";
		}
		else
		{
			cout << sol[i] << "\n\n";
		}
		
	}

	return 0;
}
