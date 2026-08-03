/*
Statement
You will be given an odd integer x which is greater than 2.

Find the smallest integer p such that p is a prime number and p is a divisor of x.

Constraints
2 <= x <= 100000000

Input
The input consists of multiple test cases.

Each test case consists of a single integer on a line on its own.

The last test case will contain the integer 0. This test case should not be processed.

Output
For each test case, output the answer for this test case on a single line.

Sample Input
5
9
11
3
17
0

Sample Output
5
3
11
3
17
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

void get_prime_divisors(int n) {

    for (int i = 1; i * i <= n; ++i) {

        if (n % i == 0) {
            if(i != 1){
                cout << i << "\n";
                return;
            }
            
            if (i != n / i) {
                if ((n / i) != n) {
                    cout << (n / i) << "\n";
                    return;
                }                      
            }             
        }

    }
    cout << n << "\n";
}


int main()
{
	cin.tie(nullptr), cout.tie(nullptr), cin.sync_with_stdio(false), cout.sync_with_stdio(false);

	int n;
   
	while (cin>>n && n != 0)
	{
        get_prime_divisors(n);
	}

	return 0;
}
