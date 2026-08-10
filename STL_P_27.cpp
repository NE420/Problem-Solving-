/*
The sequence of n  1 consecutive composite numbers (positive integers that are not prime and not
equal to 1) lying between two successive prime numbers p and p + n is called a prime gap of length n.
For example, ⟨24, 25, 26, 27, 28⟩ between 23 and 29 is a prime gap of length 6.
Your mission is to write a program to calculate, for a given positive integer k, the length of the
prime gap that contains k. For convenience, the length is considered 0 in case no prime gap contains k.
Input
The input is a sequence of lines each of which contains a single positive integer. Each positive integer
is greater than 1 and less than or equal to the 100000th prime number, which is 1299709. The end of
the input is indicated by a line containing a single zero.
Output
The output should be composed of lines each of which contains a single non-negative integer. It is the
length of the prime gap that contains the corresponding positive integer in the input if it is a composite
number, or ‘0’ otherwise. No other characters should occur in the output.
Sample Input
10
11
27
2
492170
0
Sample Output
4
0
6
0
114
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

    vector<bool> prime = Sieve(1299709);
    /*for (int i = 2; i < sive.size(); i++)
    {
        if (sive[i]) {
            prime.push_back(i);
        }
    }

    for (int i = 0; i < prime.size(); i++)
    {
        
    }*/

    int n;

    while (cin>>n && n != 0)
    {
        if (prime[n]) {
            cout << 0 << "\n";
        }
        else if (!prime[n]) {
            int l = 0,r = 0;
      
            for (int i = n+1; i < prime.size(); i++)
            {
                if (prime[i]) {
                    r++;
                    break;
                }
                r++;
            }

            for (int i = n-1; i >= 0; i--)
            {
                if (prime[i]) {
                    l++;
                    break;
                }
                l++;
            }

            cout << l + r <<"\n";
        }
              
    }  

    return 0;
}
