/*
Hmmmmmm.......... strings again :) Then it must be an easy task for you. Well . . . you are given with
a string S of length not more than 100,000 (only ‘a’-‘z’ and ‘A’-‘Z’). Then follows q (q < 1000) queries
where each query contains a string T of maximum length 1,000 (also contains only ‘a’-‘z’ and ‘A’-‘Z’).
You have to determine whether or not T is a sub-string of S.
Input
First line contains an integer k (k < 10) telling the number of test cases to follow. Each test case begins
with S. It is followed by q. After this line there are q lines each of which has a string T as defined
before.
Output
For each query print ‘y’ if it is a sub-string of S or ‘n’ otherwise followed by a new line. See the sample
output below.
Sample Input
2
abcdefghABCDEFGH
2
abc
abAB
xyz
1
xyz
Sample Output
y
n
y
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

struct Aho
{
    vector<int> pi;
    vector<vector<int>> trie, patterns;
    int states = 0;

    Aho(int n, int m = 52)// m num of alphabit
    {
        pi = vector<int>(n + 10, -1);
        patterns = vector<vector<int>>(n + 10);
        trie = vector<vector<int>>(n + 10, vector<int>(m, -1));
    }

    Aho(vector<string>& patt, int n, int m = 52)
    {      
        patterns = vector<vector<int>>(n + 10);
        trie = vector<vector<int>>(n + 10, vector<int>(m, -1));
        pi = vector<int>(n + 10, -1);

        for (int i = 0; i < patt.size(); i++)
        {
            insert(patt[i], i);
        }
            
        build();
    }

    int getIndex(char c)
    {
        if (c >= 'a' && c <= 'z') 
        {
            return c - 'a';
        }
           
        else if (c >= 'A' && c <= 'Z')
        {
            return c - 'A' + 26;
        }
 
        return -1; // invlid
    }

    void insert(string& stri, int indeX)
    {
        int cur = 0;
        for (auto& it : stri)
        {
            int charIndex = getIndex(it);
            if (charIndex == -1) continue; // Skip invalid characters

            if (trie[cur][charIndex] == -1)
                trie[cur][charIndex] = ++states;
            cur = trie[cur][charIndex];
        }
        patterns[cur].push_back(indeX);
    }

    int nextState(int trieNode, int nxt)
    {
        int cur = trieNode;
        while (trie[cur][nxt] == -1)
            cur = pi[cur];
        return trie[cur][nxt];
    }

    void build()
    {
        queue<int> q;
        for (int i = 0; i < 52; i++)
        {
            if (trie[0][i] != -1)
                pi[trie[0][i]] = 0, q.push(trie[0][i]);
            else
                trie[0][i] = 0;
        }

        while (q.size())
        {
            int cur = q.front();
            q.pop();
            for (int i = 0; i < 52; i++)
            {
                if (trie[cur][i] == -1)
                    continue;
                int f = nextState(pi[cur], i);
                pi[trie[cur][i]] = f;
                patterns[trie[cur][i]].insert(patterns[trie[cur][i]].end(), patterns[f].begin(), patterns[f].end());
                q.push(trie[cur][i]);
            }
        }
    }

    vector<vector<int>> search(string& s, vector<string>& p, int n)
    {
        int cur = 0;
        vector<vector<int>> ret(n);
        for (int i = 0; i < s.length(); i++)
        {
            int charIndex = getIndex(s[i]);
            if (charIndex == -1) continue; // Skip invalid characters

            cur = nextState(cur, charIndex);
            if (cur == 0 || patterns[cur].empty())
                continue;

            for (auto& it : patterns[cur])
                ret[it].push_back(i - p[it].length() + 1);
        }
        return ret;
    }
};

int main()
{
	cin.tie(0), cout.tie(0), cin.sync_with_stdio(false), cout.sync_with_stdio(false);

	int T;
	cin >> T;

	while (T--)
	{
		string str;
		int q;
		cin >> str;
		cin >> q;
        vector<string> query;
		for (int i = 0; i < q; i++)
		{
			string pat;
			cin >> pat;
            query.push_back(pat);
		}

        int totalLength = 0;
        for (auto patt : query) {
            totalLength += patt.size();
        }

        Aho aho(query, totalLength);

        vector<vector<int>> matches = aho.search(str, query, query.size());

        for (int i = 0; i < query.size(); ++i)
        {
            if (matches[i].empty()) 
            {            
                cout << "n\n";
            }
            else 
            {
                cout << "y\n";             
            }
        }

	}

	return 0;
}
