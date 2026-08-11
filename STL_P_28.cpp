/*
Given a string of digits, find the largest prime number less than or equal to 105 which is a sub-string of the given string. A sub-string is a continuous sequence of characters in a string.

Input
The input will consist of multiple test cases.

Each test case will contain a single string of integers which has length less than 256. Each test case will be on a single line. The last test case will have the string "0" and should not be processed.

Output
For each test case, print ,on a single line, the largest prime number found as a sub-string of the given string.


Input
11245
91321150448
1226406
0

Output
11
1321
2
*/

#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <cmath>
#include <string>


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

    vector<bool> sive = Sieve(1e5+3);
    unordered_set<long long> prime;

    for (long long i = 2; i < sive.size(); i++)
    {
        if (sive[i]) {
            prime.insert(i);
        }
    }

    string n;

    while (cin>>n && n != "0")
    {                        
        long long Max = -1; // up to 6 digits
        for (int sub = 0; sub < n.length(); sub++)
        {
            string subLen = n.substr(sub, 6);
            for (int i = 0; i < subLen.length(); i++)
            {
                for (int j = 1; j <= subLen.length() - i; j++)
                {
                    string substr = subLen.substr(i, j);
                    long long tmp = stoll(substr);
                    if (prime.find(tmp) != prime.end()) {
                        Max = max(Max, tmp);
                    }
                }
            }
            //cout << subLen << "\n";
        }
        cout << Max << "\n";
    }

    
    return 0;
}
