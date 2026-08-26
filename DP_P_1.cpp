/*
Given a list of numbers 
A
A, find the length of the longest increasing subsequence in it. A subsequence is a sequence that can be derived from the given sequence by deleting zero or more elements without changing the order of the remaining elements. An increasing subsequence is a subsequence in which each element is greater than all previous elements.

For example, in the list {33 , 11 , 22 , 44}:

The subsequences {33 , 44} and {11} are increasing subsequences while {11 , 22 , 44} is the longest increasing subsequence.

Input
First line contains a single integer 
N
N (1 <= 
N
N <= 10) the length of the list 
A
A.

The second line contains 
N
N numbers (1 <= each number <= 20), the numbers in the list 
A
A separated by spaces.

Output
One line containing the lenght of the longest increasing subsequence in 
A
A.

Sample
Input:
5
1 4 2 4 3
Output:
3
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

const int N = 10 + 7;

vector<int> dp(N, 1);

int LIS(vector<int> nums)
{
    int Max = 1;
    for (int i = 1; i < nums.size(); i++) 
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                Max = max(dp[i], Max);
            }        
        }            
    }

    return Max;
}

int main()
{
    cin.tie(0), cout.tie(0), cin.sync_with_stdio(false), cout.sync_with_stdio(false);
    
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
	
    cout << LIS(nums);

    return 0;
}
