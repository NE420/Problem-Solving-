/*
A boolean matrix has the parity property when each row and each column has an even sum, i.e. contains
an even number of bits which are set. Here’s a 4 × 4 matrix which has the parity property:
1 0 1 0
0 0 0 0
1 1 1 1
0 1 0 1
The sums of the rows are 2, 0, 4 and 2. The sums of the columns are 2, 2, 2 and 2.
Your job is to write a program that reads in a matrix and checks if it has the parity property. If
not, your program should check if the parity property can be established by changing only one bit. If
this is not possible either, the matrix should be classified as corrupt.
Input
The input file will contain one or more test cases. The first line of each test case contains one integer
n (n < 100), representing the size of the matrix. On the next n lines, there will be n integers per line.
No other integers than ‘0’ and ‘1’ will occur in the matrix. Input will be terminated by a value of 0 for
n.
Output
For each matrix in the input file, print one line. If the matrix already has the parity property, print
‘OK’. If the parity property can be established by changing one bit, print ‘Change bit (i,j)’ where i
is the row and j the column of the bit to be changed. Otherwise, print ‘Corrupt’.
Sample Input
4
1 0 1 0
0 0 0 0
1 1 1 1
0 1 0 1
4
1 0 1 0
0 0 1 0
1 1 1 1
0 1 0 1
4
1 0 1 0
0 1 1 0
1 1 1 1
0 1 0 1
0
Sample Output
OK
Change bit (2,3)
Corrupt
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
	int n;

	while (true) {
		bool ans = true;
		cin >> n;
		if (n == 0) {
			break;
		}
		vector<vector<bool>> matrix(n, vector<bool>(n));

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				bool bit;
				cin >> bit;
				matrix[i][j] = bit;
			}
		}
		pair<int, int> change;
		bool ch = false;
		int count_row = 0;
		for (int i = 0; i < n; i++) {
			int rowSum = 0;
			for (int j = 0; j < n; j++) {
				rowSum += matrix[i][j];
			}
			if (rowSum % 2 != 0) { //check the row sum
				count_row += 1;//needs change
				change.first = i;
				ch = true;
			}
			if (count_row == 2) {
				ans = false;
				break;
			}
		}

		if (ans) { // if row sum was was even check column sum
			int count_col = 0;
			for (int i = 0; i < n; i++) {
				int colSum = 0;
				for (int j = 0; j < n; j++) {
					colSum += matrix[j][i];
				}
				if (colSum % 2 != 0) { //check the column sum
					count_col += 1;
					change.second = i;
					ch = true;
				}
				if (count_col == 2) {
					ans = false;
					break;
				}
			}

		}
		
		if (ans && ch == false) {
			cout << "OK" << "\n";
		}
		else if(ch && ans == true){	//if ans is false try to change bits	
			cout << "Change bit (" << change.first + 1 << "," << change.second + 1 << ")\n";
		}
		else if(ans == false){
			cout << "Corrupt" << "\n";
		}

	}

	return 0;
}
