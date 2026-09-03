/*
You are playing a video game and the current level is a two-dimensional grid of size 
n
n by 
m
m. Each cell in this grid either contains an uppercase English letter or the character '@' or the character '#'. There is exactly one cell with the character '#' and one cell with the character '@'.

Your character in the game starts off in the cell marked with '@' and wants to get to the cell marked with '#'. Your character can only go forth (up), left, or right. Your character can go to a cell only if the letter that exists in the cell is one of the letters in the following string "IEHOVA". Find any path that your character can take from his starting cell to the destination cell.

There will always be exactly one valid path that your character can take.

Input
The first line contains a single integer 
T
T which is the number of test cases.

The first line of each test case contains two integers 
n
n and 
m
m which represent the number of rows and the number of columns in the grid. 
2
<
=
n
,
m
<
=
8
2<=n,m<=8

This is followed by 
n
n lines which have 
m
m characters each. Each character will be either an uppercase English letter, '@', or '#'. It is guaranteed that the characters '@' and '#' appear exactly once in each test case. Additionally, there will always be exactly one path from the start to the destination with the letters "IEHOVA" in that order.
Output
For each test case, output a line with the commands given to your character to reach the destination.
Sample Input
2
6 5
PST#T
BTJAS
TYCVM
YEHOF
XIBKU
N@RJB
5 4
JA#X
JVBN
XOHD
DQEM
T@IY
Sample Output
forth forth right right forth forth forth
right forth forth left forth forth right
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

unordered_set<char> sol = { 'I','E','H','O','V','A' };

bool maze(vector<vector<char>>& items, int i,int j,vector<string>& taken)
{
	if (!sol.count(items[i][j]) && items[i][j] != '@' && items[i][j] != '#') {
		return 0;
	}

	if (items[i][j] == '$') {
		return 0;
	}

	if (items[i][j] == '#') {
		return 1;
	}

		items[i][j] = '$';

		if (i == 0) {
			if (j == items[i].size()-1) {
				if (maze(items, i, j - 1, taken))
				{
					taken.push_back("left");
					return 1;
				}
			}
			else if (j == 0) {
				if (maze(items, i, j + 1, taken))
				{
					taken.push_back("right");
					return 1;
				}
			}
			else
			{
				if (maze(items, i, j + 1, taken))
				{
					taken.push_back("right");
					return 1;
				}

				if (maze(items, i, j - 1, taken))
				{
					taken.push_back("left");
					return 1;
				}
			}
				
		}
		
		else if (j == items[i].size()-1) {
			if (maze(items, i - 1, j, taken))
			{
				taken.push_back("forth");
				return 1;
			}

			if (maze(items, i, j - 1, taken))
			{
				taken.push_back("left");
				return 1;
			}
		}
		else if (j == 0) {
			if (maze(items, i - 1, j, taken))
			{
				taken.push_back("forth");
				return 1;
			}

			if (maze(items, i, j + 1, taken))
			{
				taken.push_back("right");
				return 1;
			}
		}
		else
		{
			if (maze(items, i - 1, j, taken))
			{
				taken.push_back("forth");
				return 1;
			}

			if (maze(items, i, j + 1, taken))
			{
				taken.push_back("right");
				return 1;
			}

			if (maze(items, i, j - 1, taken))
			{
				taken.push_back("left");
				return 1;
			}
		}

}

int main()
{
	//cin.tie(0), cout.tie(0), cin.sync_with_stdio(false), cout.sync_with_stdio(false);

	int n,m,T;

	cin >> T;

	while (T--) {

		cin >> n >> m;

		vector<vector<char>> items(n, vector<char>(m, ' '));
		vector<string> taken;
		int strtrw = 0, strtcol = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
			{
				cin >> items[i][j];
				if (items[i][j] == '@') {
					strtrw = i;
					strtcol = j;
				}
			}
		}

		/*for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
			{
				cout<< items[i][j] << " ";
			}
			cout << "\n";
		}*/
		
		maze(items, strtrw, strtcol,taken);
		
		for (int i = taken.size() - 1; i >= 0; i--) {
			if (i != 0) {
				cout << taken[i] << " ";
			}
			else {
				cout << taken[i];
			}
			
		}
		
			cout << "\n";
		
		
		taken.clear();
	}

	return 0;
}
