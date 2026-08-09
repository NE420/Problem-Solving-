/*
Some positive integers can be represented by a sum of one or more consecutive prime numbers. How
many such representations does a given positive integer have? For example, the integer 53 has two
representations 5+7+11+13+17 and 53. The integer 41 has three representations 2+3+5+7+11+13,
11 + 13 + 17, and 41. The integer 3 has only one representation, which is 3. The integer 20 has no
such representations. Note that summands must be consecutive prime numbers, so neither 7 + 13 nor
3 + 5 + 5 + 7 is a valid representation for the integer 20. Your mission is to write a program that reports
the number of representations for the given positive integer.
Input
The input is a sequence of positive integers each in a separate line. The integers are between 2 and
10000, inclusive. The end of the input is indicated by a zero.
Output
The output should be composed of lines each corresponding to an input line except the last zero. An
output line includes the number of representations for the input integer as the sum of one or more
consecutive prime numbers. No other characters should be inserted in the output.
Sample Input
2
3
17
41
20
666
12
53
0
Sample Output
1
1
2
3
0
0
1
2
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

    vector<bool> sive = Sieve(10000);
    vector<int> prime;

    for (int i = 2; i < sive.size(); i++)
    {
        if (sive[i]) {
            prime.push_back(i);
        }
    }
       
    int n;

    while (cin>>n && n != 0)
    {
        int count = 0;
        /*if (isPrime(n)) {
            count++;
        } */    
            vector<long long> prefixSum(n);
            prefixSum[0] = prime[0];
            for (int j = 1; j < n; j++) {               
                prefixSum[j] = prefixSum[j - 1] + prime[j];
                if (prefixSum[j] > n) {
                    break;
                }
            }
            /*if (n == 2) {
                count--;
            }*/

            for (auto i : prefixSum)
            {
                if (prefixSum.back() != 0) {
                    break;
                }
                else {
                    prefixSum.pop_back();
                }
            }
            
            int l;
            l = 0;
            //r = prefixSum.size()-1;
            while (!(prefixSum.front() > n)) {
                if (l == 0) {
                    auto itr = find(prefixSum.begin(), prefixSum.end(), n);
                    if (itr != prefixSum.end()) {
                        count++;
                    }
                }
                else {
                    /*if (prefixSum[r] - prefixSum[l - 1] == n) {
                        count++;
                    }*/
                    vector<long long> prefixSum(n-l);
                    prefixSum[0] = prime[l];
                    for (int j = 1; j < n-l; j++) {
                        prefixSum[j] = prefixSum[j - 1] + prime[j+l];
                        if (prefixSum[j] >= n) {
                            break;
                        }
                    }
                    prefixSum.erase(remove(prefixSum.begin(), prefixSum.end(), 0), prefixSum.end());
                    auto itr = find(prefixSum.begin(), prefixSum.end(), n);
                    if (itr != prefixSum.end()) {
                        count++;
                    }
                }
                
                l++;
                if (l >= n) {
                    break;
                }
                
            }

            cout << count << "\n";
        /*for (int i = 0; i < n; i++)
        {
            if (prime[i]) {
                cout << i << "\n";
            }
        }*/
    }  

    return 0;
}
