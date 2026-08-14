/*
Write a program that finds all occurrences of a given pattern in a given input string. This is often referred to as finding a needle in a haystack.

The program has to detect all occurrences of the needle in the haystack. It should take the needle and the haystack as input, and output the positions of each occurrence, as shown below. The suggested implementation is the KMP algorithm, but this is not a requirement. However, a naive approach will probably exceed the time limit, whereas other algorithms are more complicated... The choice is yours.

Input
The input consists of a number of test cases. Each test case is composed of three lines, containing:

the length of the needle,
the needle itself,
the haystack.
The length of the needle is only limited by the memory available to your program, so do not make any assumptions - instead, read the length and allocate memory as needed. The haystack is not limited in size, which implies that your program should not read the whole haystack at once. The KMP algorithm is stream-based, i.e. it processes the haystack character by character, so this is not a problem.

The test cases come one after another, each occupying three lines, with no additional space or line breaks in between.

Output
For each test case your program should output all positions of the needle's occurrences within the haystack. If a match is found, the output should contain the position of the first character of the match. Characters in the haystack are numbered starting with zero.

For a given test case, the positions output should be sorted in ascending order, and each of these should be printed in a separate line. For two different test cases, the positions should be separated by an empty line.

Example
  
Input	
2
na
banananobano
6
foobar
foo
9
foobarfoo
barfoobarfoobarfoobarfoobarfoo

Output
2
4

3
9
15
21
Note the empty line in the output, which means that no match was found for the second test case.

Warning: large Input/Output data, be careful with certain languages
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
#include <queue>
#include <cstring>
#define ll long long

using namespace std;

const int N = 2e7 + 5;

char pat[N], str[N];
int f[N];

int getLen(int len, char c) 
{
	while (len && pat[len] != c)
		len = f[len - 1];
	if (pat[len] == c)
		++len;
	return len;
}

void calcF() 
{
	f[0] = 0;
	for (int i = 1; pat[i]; ++i)
		f[i] = getLen(f[i - 1], pat[i]);

}

vector<int> match() 
{
	calcF();
	int len = 0;
	vector<int> ret;
	for (int i = 0; str[i]; ++i) 
	{
		len = getLen(len, str[i]);
		if (!pat[len]) 
		{
			ret.push_back(i - len + 1);
		}
	}
	return ret;
}

int main()
{
	cin.tie(0), cout.tie(0), cin.sync_with_stdio(false), cout.sync_with_stdio(false);

	ll n;
	
	while (cin >> n >> pat >> str)
	{
		for (auto i : match())
		{
			cout << i <<"\n";
		}
	}

	return 0;
}
