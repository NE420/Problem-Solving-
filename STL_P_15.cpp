/*
You are playing a video game. In the current level, you must defeat n enemies. You and each of the enemies have a certain power, which is represented by an integer. The result of a duel between you and a certain enemy is determined by your current power and the enemy's power. Initially, your power is r.

If you start dueling with the i-th (1 ≤ i ≤ n) enemy and your power is not greater than the enemy's power pi, then you lose the duel and die. But if your power is greater than the enemy's power, then you defeat the enemy and your power increases by qi.

You can fight the enemies in any order. Can you fight the enemies in an order such that you do not lose any duel?

Input
The first line contains two space-separated integers r and n (1 ≤ r ≤ 104, 1 ≤ n ≤ 103). Then n lines follow: the i-th line contains space-separated integers pi and qi (1 ≤ pi ≤ 104, 0 ≤ qi ≤ 104) — the i-th enemy's power and the bonus for defeating it.

Output
On a single line print "YES", if you can fight the enemies in such a way that you lose no duel and print "NO" otherwise.

Sample 1
  
Input	
2 2
1 99
100 0
  
Output
YES
  
Sample 2

Input	
10 1
100 100
Output
NO
  
Note
In the first sample your power initially equals 2. As the first enemy's power is less than 2, you can fight it and defeat it. After that, your power becomes 101. Now you can defeat the second dragon.
  */

#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;


int main()
{
	//cin.tie(nullptr), cout.tie(nullptr), cin.sync_with_stdio(false), cout.sync_with_stdio(false);
	
	long long r, n;
	bool ans = true;
	multiset<pair<long long, long long>> power2;
	 
	cin >> r >> n;

	for (int i = 0; i < n; i++)
	{
		int p, q;
		cin >> p >> q;
		pair<long long, long long> tmp;
		tmp.first = p;
		tmp.second = q;
		power2.insert(tmp);
	}
	for (auto& i : power2) {
		if (r <= i.first) {
			ans = false;
			break;
		}
		else if (r > i.first) {
			r += i.second;
		}
	}

	if (ans) {
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;

}
