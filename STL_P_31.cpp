/*
Your task is so simple given a string and a pattern. You find the pattern on the given string. If found print how many time found the pattern and their index. Otherwise print ‘Not Found’.

Input
The input   line consists of a number T (1 ≤ T ≤ 50) test cases.

For each case given two string number  A,B. the string and the pattern  1 ≤ |A|, |B| ≤ 106

All character will be lowercase Latin character.  And |  | is the length of string.

Output
For each case print the number  (found pattern from the given string) next line their positions. Otherwise print 'Not Found' without quotes.

Output a blank line between two cases.

Example
  
Input
3
ababab ab
aaaaa bbb
aafafaasf aaf

Output
3
1 3 5

Not Found

1
1

Hints: Here all index is 1 based.
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
#include <limits>
#include <climits>
#include <regex>
#define ll long long

using namespace std;

vector<int> prefix(string pattern) {
	int n = pattern.length();
	vector<int> pi(n);

	for (int i = 1; i < n; i++) 
	{
		int j = pi[i - 1];
		while (j > 0 && pattern[i] != pattern[j])
			j = pi[j - 1];
		if (pattern[i] == pattern[j])
			j++;
		pi[i] = j;
	}

	return pi;
}

vector<int> pattern_find(string& text, string& patt)
{
	int n = patt.size(), m = text.size();
	string s = patt + "#" + text;

	vector<int> pi = prefix(s);
	vector<int> ans;

	for (int i = n + 1; i < s.size(); i++) {
		if (pi[i] == n) {
			ans.push_back(i - 2 * n);
		}
	}

	return ans;
}

int main()
{
	cin.tie(0), cout.tie(0), cin.sync_with_stdio(false), cout.sync_with_stdio(false);

	int T;
	cin >> T;

	while (T--)
	{
		string pat; 
		string str;
		bool found = false; 

		cin >> str >> pat;
		
		vector<int> ans = pattern_find(str, pat);
		
		if (ans.empty())
		{
			cout << "Not Found" << "\n\n";
		}
		else
		{
			cout << ans.size() <<"\n";
			for (auto i: ans)
			{
				cout << ++i <<" ";
			}
			cout << "\n\n";
		}

	}

	return 0;
}
