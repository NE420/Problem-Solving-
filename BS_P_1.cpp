/*
Polycarpus loves hamburgers very much. He especially adores the hamburgers he makes with his own hands. Polycarpus thinks that there are only three decent ingredients to make hamburgers from: a bread, sausage and cheese. He writes down the recipe of his favorite "Le Hamburger de Polycarpus" as a string of letters 'B' (bread), 'S' (sausage) и 'C' (cheese). The ingredients in the recipe go from bottom to top, for example, recipe "ВSCBS" represents the hamburger where the ingredients go from bottom to top as bread, sausage, cheese, bread and sausage again.

Polycarpus has nb pieces of bread, ns pieces of sausage and nc pieces of cheese in the kitchen. Besides, the shop nearby has all three ingredients, the prices are pb rubles for a piece of bread, ps for a piece of sausage and pc for a piece of cheese.

Polycarpus has r rubles and he is ready to shop on them. What maximum number of hamburgers can he cook? You can assume that Polycarpus cannot break or slice any of the pieces of bread, sausage or cheese. Besides, the shop has an unlimited number of pieces of each ingredient.

Input
The first line of the input contains a non-empty string that describes the recipe of "Le Hamburger de Polycarpus". The length of the string doesn't exceed 100, the string contains only letters 'B' (uppercase English B), 'S' (uppercase English S) and 'C' (uppercase English C).

The second line contains three integers nb, ns, nc (1 ≤ nb, ns, nc ≤ 100) — the number of the pieces of bread, sausage and cheese on Polycarpus' kitchen. The third line contains three integers pb, ps, pc (1 ≤ pb, ps, pc ≤ 100) — the price of one piece of bread, sausage and cheese in the shop. Finally, the fourth line contains integer r (1 ≤ r ≤ 1012) — the number of rubles Polycarpus has.

Please, do not write the %lld specifier to read or write 64-bit integers in С++. It is preferred to use the cin, cout streams or the %I64d specifier.

Output
Print the maximum number of hamburgers Polycarpus can make. If he can't make any hamburger, print 0.

Examples
  
Input
BBBSSC
6 4 1
1 2 3
4

Output
2
  
Input
BBC
1 10 1
1 10 1
21

Output
7
  
Input
BSC
1 1 1
1 1 3
1000000000000

Output
200000000001
*/

#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

set<string> sol;

bool ok(long long num_burgers, long long money, vector<int> ing, vector<int> have, vector<int> price) {

    long long money_needed = 0;

    for (int i = 0 ; i < 3 ; i++)
    {
        long long money_needed_ing = (have[i] - ing[i] * num_burgers) * price[i];
        if (money_needed_ing < 0) {
            money_needed += abs(money_needed_ing);
        }
    }
    if (money_needed <= money) {
        return true;
    }
   
    return false;
}

int main()
{
	cin.tie(0), cout.tie(0), cin.sync_with_stdio(false), cout.sync_with_stdio(false);

    string burger;

    cin >> burger;

    vector<int> ing(3);
    vector<int> have(3);
    vector<int> price(3);

    for (auto i : burger) {
        if (i == 'B') {
            ing[0]++;
        }
        if (i == 'S') {
            ing[1]++;
        }
        if (i == 'C') {
            ing[2]++;
        }   
    }

    int b,s,c, pb, ps, pc;

    long long money;
   
    cin >> b >> s >> c;

    have[0] = b;
    have[1] = s;
    have[2] = c;

    cin >> pb >> ps >> pc;

    price[0] = pb;
    price[1] = ps;
    price[2] = pc;

    cin >> money;
    
    
            
    long long left = 0, right = 1e13+8, ans = 0;

    while (left <= right) {
        long long mid = (left + right) / 2;
        if (ok(mid, money, ing, have, price)) {
            left = mid + 1;
            ans = mid;
        }
        else {
            right = mid - 1;
        } 
    }
    cout << ans << "\n";

	return 0;
}
