/*
There is a hidden number p, you are given a list of all of the divisors of p except 1 and p.

Find the minimum possible value of p that satisfies this list, or say that no such number exists.

Input
The input consists of multiple test cases. The first line of input contains the number of test cases 1 <= t <= 25. Then t test cases follow.

Each test case is described with two lines. The first line of each test case contains the integer n, which is the number of divisors of p, 1 <= n <= 300. The second line contains n integers which are the divisors of p. All divisors given will be between 2 and 106 and will be distinct.

Output
For each query print the answer to it on a single line. If it is impossible to find such number p that satisfies the given list of divisors, print -1. Otherwise print the minimum possible p.

Sample 1
  
Input	
2
8
8 2 12 6 4 24 16 3
1
2
  
Output
48
4
*/

#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>

using namespace std;

set<unsigned long long> get_divisors(unsigned long long n) {

    set<unsigned long long> divisors;

    for (unsigned long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            
            divisors.insert(i);
            if (i != n / i) {
                divisors.insert(n / i);
            }
        }
    }

    return divisors;
}

int main()
{
    cin.tie(nullptr), cout.tie(nullptr), cin.sync_with_stdio(false), cout.sync_with_stdio(false);

    int n,t;
    cin >> t;

    while (t--)
    {
        cin >> n;
        set<unsigned long long> divs;
        bool found = false;
        for (int i = 0; i < n; i++)
        {
            int inp;
            cin >> inp;
            divs.insert(inp);
        }        

        set<unsigned long long> tmp = get_divisors((*divs.rbegin()) * (*divs.begin()));
        tmp.erase(1);
        tmp.erase((*divs.rbegin()) * (*divs.begin()));
        if (tmp == divs) {
            cout << (*divs.rbegin())* (*divs.begin()) << "\n";
            found = true;
        }
        /*for (int i = 2; i < 300; i++) {
            set<unsigned long long> tmp = get_divisors(*divs.rbegin() * i);
            tmp.erase(1);
            tmp.erase(*divs.rbegin() * i);
            if (tmp == divs) {
                cout << *divs.rbegin() * i << "\n";
                found = true;
                break;
            }           
        } */
        if (!found) {
            cout << -1 << "\n";
        }
    }

    return 0;
}
