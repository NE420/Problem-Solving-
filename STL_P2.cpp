/*
Write a program, that, given a board, and a list of rectangular sub-portions of the board, returns the
number of positions that belong to no sub-portion.
Input
The input consists of a series of test sets separated by blank lines. A test set starts with a line with
three numbers W , H and N , giving respectively the width, the height and the number of sub-boards.
These values satisfy the following constraints: 1 ≤ W, H ≤ 500 and 0 ≤ N ≤ 99. Follow then N
lines, composed of four integers X1, Y1, X2, Y2, such that (X1, Y1) and (X2, Y2) are the positions of two
opposite corners of a sub-board. These values satisfy the following constraints: 1 ≤ X1, X2 ≤ W and
1 ≤ Y1, Y2 ≤ H. The end of the input is reached when the numbers W , H and N are equal to 0.
This last line shall not be considered as a test set.
Output
The program shall output each result on a line by its own, following the format given in the sample
output.
Sample Input
1 1 1
1 1 1 1
2 2 2
1 1 1 2
1 1 2 1
493 182 3
349 148 363 146
241 123 443 147
303 124 293 17
0 0 0
Sample Output
There is no empty spots.
There is one empty spot.
There are 83470 empty spots.
*/

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;


int main()
{
	cin.tie(nullptr), cout.tie(nullptr), cin.sync_with_stdio(false), cout.sync_with_stdio(false);

	int w, h, n = -1;
	w = h = n;

	while( (cin >> w >> h >> n) && (w != 0 || h != 0 || n != 0) ) {
		
		vector<vector<bool>> square(w + 1, vector<bool>(h + 1, true));

		for (int i = 0; i < n; ++i) {
			int x1, y1, x2, y2;

			cin >> x1 >> y1 >> x2 >> y2;

			int widthmin = min(x1, x2);
			int widthmax = max(x1, x2);
			int hightmin = min(y1, y2);
			int hightmax = max(y1, y2);

			for (int j = widthmin; j <= widthmax; ++j) {
				for (int k = hightmin; k <= hightmax; ++k) {
					square[j][k] = false;
				}
			}
		}
		long long sum = 0;
		for (int i = 1; i <= w; ++i) {
			for (int j = 1; j <= h; ++j) {
				if (square[i][j]) {
					sum++;
				}
			}
		}

		if (sum == 0) {
			cout << "There is no empty spots.\n";		
		}
		else if (sum == 1) {
			cout<< "There is one empty spot.\n";
		}
		else {
			cout << "There are " << sum << " empty spots.\n";
		}
	}

	return 0;
}
