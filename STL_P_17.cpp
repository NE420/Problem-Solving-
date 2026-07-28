/*
You own a website, some users on the website want to change their usernames. For a user to change their username, they must provide their old username and their new username. The new username must not have been used by anyone at any point up to the username change request. Given a list of username change requests, output the initial and final usernames of all users who requested username changes.

Input
The first line contains integer n (1 ≤ n ≤ 1000), the number of username change requests.

The following n lines will contain the descriptions of the requests.

Each request consists of two strings s and t, separated by a space. The strings may have lowercase and uppercase letters and digits. The two strings of each requests are not the same. The length of both strings does not exceed 20.

The requests are given chronologically. So, it is guaranteed that by the moment of a query there is a single person with username s, and handle t is not used and has not been used by anyone.

Output
Output the integer l — the number of users that changed their handles at least once.

In the next l lines print the mapping between the old and the new usernames of the users. You may output lines in any order.

Each user who changes the username must occur exactly once in this description.

Sample 1
  
Input	
5
ahmed hassan
khaled khaledB
khaledB khaledB123
hassan gamal
rana malak

Output
3
ahmed gamal
khaled khaledB123
rana malak
*/

#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;


int main()
{
	cin.tie(nullptr), cout.tie(nullptr), cin.sync_with_stdio(false), cout.sync_with_stdio(false);

	int n;
	vector<pair<string, string>> name;
	vector<pair<string, string>> changed_name;

	/*set<string> all_name;
	map<string, string> tmp;
	vector<string> new_name;*/
	cin >> n;

	vector<bool> changed(n);

	for (int i = 0; i < n; i++)
	{
		string s, t;
		cin >> s >> t;
		pair<string, string> tmp;
		tmp.first = s;
		tmp.second = t;
		name.push_back(tmp);
		changed[i] = false;

		for (int j = 0; j < name.size(); j++) {

			if (name[j].second == s) { // if name was found

				string new_val = name[i].second;
				string old_key = name[j].first;
				changed[j] = true;
				changed[i] = true;

				pair<string, string> tmp2;
				tmp2.first = old_key;
				tmp2.second = new_val;
				
				name[i].first = name[j].first;
				for (int k = 0; k < changed_name.size(); k++) {
					if (changed_name[k].first == name[j].first) {
						changed_name.erase(changed_name.begin() + k);
					}
				}
				changed_name.push_back(tmp2);
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (!changed[i]) {
			sum++;
		}
	}
	sum += changed_name.size();
	cout << sum << "\n";
	for (auto i : changed_name) {
		cout << i.first << " " << i.second << "\n";
	}
	for (int i = 0; i < n; i++) {
		if (!changed[i]) {
			cout << name[i].first << " " << name[i].second << "\n";
		}
	}
	
	return 0;

}
