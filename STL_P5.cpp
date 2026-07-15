/*
You are a mathematician who has been fascinated with palindromic numbers since childhood. One day, while working on a research project, you come across a new type of number called the Palindrome Extension number. Intrigued, you decide to investigate further.

After some research, you discover that a Palindrome Extension number is a number that can be transformed into a palindrome by adding some leading zeros (possibly none). You begin to wonder how many numbers around you are Palindrome Extension.

For example, numbers 131 and 2010200 are Palindrome Extension numbers, they can be transformed to strings "131" and "002010200", respectively, which are palindromes.

One day, while walking to your office, you come across a poster for a math competition. The competition is based on palindromic and Palindrome Extension numbers. Excited by the opportunity, you decide to participate.

During the competition, You are given some integer number n. Check if it's a Palindrome Extension number.

Input
The only line contains an integer n (1 ≤ n ≤ 10^9). This number does not begin with a zero.

Output
Print “YES” if number n is Palindrome Extension number. Otherwise, print “NO” (without quotes).

Sample 1
InputCopy	OutputCopy
676
YES
Sample 2
InputCopy	OutputCopy
4420
NO
Sample 3
InputCopy	OutputCopy
4020400
YES
Explanation
In the first example, 676 is already palindrome.

In the third example, 4020400 can be transformed into 004020400 and the number become palindrome after transformation. Thus the answer is YES.
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
	long long n;
	bool ans = true;
	map<int, int> freq;
	vector<int> number;
	vector<int> number2;

	cin >> n;
	
	while (n > 0) {
		number.insert(number.begin(), n % 10);
		number2.insert(number2.begin(), n % 10);
		n /= 10;
	}

	while (number.back() == 0 && !(number.empty())) {
		number.pop_back();
		number2.pop_back();
	}

	reverse(number2.begin(), number2.end());

	if (number != number2) {
		ans = false;
	}

	if (ans) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	
	return 0; 
}
