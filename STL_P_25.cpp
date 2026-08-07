/*
Twin primes are pairs of integers p, p+2 such that p and p+2 are both prime. Some examples of twin prime pairs are (11, 13), (17, 19), and (29, 31).

Given an integer n, find the nth twin prime pair.

Input
Input will consist of multiple test cases. Each test case will be on a single line and will consist of a single integer n, 1<=n<=105. There will be at most 104 test cases.
Output
For each test case, output the n-th twin prime pair on a single line in the following format :
(p, q)
You can assume that the 100000th twin prime pair is less than 2 * 107.
Sample Input
1
2
3
4
Sample Output
(3, 5)
(5, 7)
(11, 13)
(17, 19)
*/

#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;


bool isPrime(int n)
{

    if (n <= 1)
        return false;

    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return false;

    return true;
}

vector<bool> Sieve(long long n)
{
    vector<bool> prime(n, true);

    for (long long p = 2; p * p < n; p++) {
        if (prime[p]) {
            for (unsigned long long i = p * p; i < n; i += p) {
                prime[i] = false;
            }
        }
    }

    return prime;
}

int main()
{
    cin.tie(nullptr), cout.tie(nullptr), cin.sync_with_stdio(false), cout.sync_with_stdio(false);

    vector<bool> prime = Sieve(20000002);
    vector<pair<int, int>> twins;
    for (int i = 2 ; i < prime.size();i++)
    {
        if (prime[i] && prime[i + 2]) {          
            twins.emplace_back(i,i+2);
        }
    }
    int n;    

    while (cin>>n)
    {       
        cout << "(" << twins[n-1].first << ", " << twins[n-1].second << ")\n";                   
    }  

    return 0;
}
