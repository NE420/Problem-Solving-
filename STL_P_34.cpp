/*
You are a daring treasure hunter embarking on a quest to find valuable artifacts on a long-forgotten island. Your exploration will be challenging, and you can only carry one backpack with you, which has a limited capacity denoted by S (1 <= S <= 2000). However, you have gathered information about N (1 <= N <= 2000) precious artifacts scattered across the island. Each artifact is unique and comes with its size and value. The size represents how much space it will occupy in your backpack, while the value denotes its worth in terms of gold coins. Unfortunately, you won't be able to carry all the artifacts due to the limited space, so you must carefully choose the ones that will yield the highest total value. Your ultimate goal is to maximize the total value of all the artifacts you decide to bring back from the island.

Input
The first line contains two integers, S and N, representing the capacity of your backpack and the total number of artifacts on the island, respectively. The next N lines each contain two integers, size, and value, describing one artifact per line.

Output
You should output a single integer, which represents the maximum total value you can achieve by selecting the best combination of artifacts for your treasure hunting adventure.

Example
Input:
4 5
1 8
2 4
3 0
2 5
2 3


Output:
13
*/

#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <limits.h>
#define ll long long

using namespace std;

const int M = 2e3+5; // cap
const int N = 2e3+5; // max items

int n, cap;
ll value[N], weight[N];

vector<vector<ll>> dp(N, vector<ll>(M, -1));

ll solve(ll i, ll remain) {

    //base
    if (!i || !remain)
    {
        return 0;
    }

    if (dp[i][remain] != -1)
    {
        return dp[i][remain];
    }

    ll opt1;

    if (remain >= weight[i])// taking the item
    {
        opt1 = value[i] + solve(i - 1, remain - weight[i]);
    }
    else
    {
        opt1 = INT_MIN;
    }

    ll opt2 = solve(i - 1, remain);// not taking the item

    return dp[i][remain] = max(opt1, opt2);

}

int main()
{
    //cin.tie(0), cout.tie(0), cin.sync_with_stdio(false), cout.sync_with_stdio(false);

    cin >> cap >> n;

    for (int i = 1; i <= n; ++i)
    {
        cin >> weight[i] >> value[i];
    }

    cout << solve(n, cap) << "\n";


    return 0;
}
