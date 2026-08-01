/*
Statement
You are given a function G(x) which is defined as follows:

At x = 0, G(x) = 0
At x = 1, G(x) = 1
At x = 2, G(x) = 2
If x is an odd prime, G(x) = 0
Otherwise, x can be represented as a * b where the sum of a and b is minimum, then G(x) = G(a) + G(b).

Given an integer n, evaluate G(n).

Constraints
1 <= n <= 100000

Input
The input consists of a single integer n.

Output
Output the value of G(n) on a single line.

Sample Input
4

Sample Output
4
*/

#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>

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

deque <int> get_divisors(int n) {

    deque<int> divisors;

    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }

    return divisors;
}

int G(int x) {

    if (x < 3) {
        return x;
    }
    if (isPrime(x)) {
        return 0;
    }

    deque<int> divs = get_divisors(x);
    sort(divs.begin(), divs.end());
    int Min = 1e5;
    int ele1 = 0, ele2 = 0;
    for (int i = 0; divs.size() > 0 ; i++)
    {
        if (divs.size() == 1) {
            if (Min > divs.front() + divs.back()) {
                ele1 = divs.front();
                ele2 = divs.back();

                divs.pop_front();
            }
        }
        else if (Min > divs.front() + divs.back()) {
            ele1 = divs.front();
            ele2 = divs.back();

            divs.pop_front();
            divs.pop_back();
        }
        else {
            divs.pop_front();
            divs.pop_back();
        }
    }
   
    return G(ele1) + G(ele2);
}

int main()
{
    cin.tie(nullptr), cout.tie(nullptr), cin.sync_with_stdio(false), cout.sync_with_stdio(false);

    int n;
    cin >> n;

    cout << G(n) << "\n";



    return 0;
}
