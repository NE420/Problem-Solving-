/*
Eve and Alex had an argument about the price and quality of laptops. Eve thinks that the more expensive a laptop is, the better it is. But Alex does not agree with Eve. He thinks that there are two laptops, such that the price of the first laptop is less (strictly smaller) than the price of the second laptop but the quality of the first laptop is higher (strictly greater) than the quality of the second laptop.

Please, check the guess of Alex. You are given descriptions of L laptops. Determine whether two described above laptops exist.

Input
The first line contains an integer L (1 ≤ L ≤ 105) — the number of laptops.

Next L lines contain two integers each, pi and qi (1 ≤ pi, qi ≤ n), where pi denotes the price of the i-th laptop, and qi represents the quality of the i-th laptop (the larger the number is, the higher is the quality).

Note that, all pi are distinct. Alos, all qi are distinct.

Output
You have to output a single line. Output "Poor Alex" if Alex's guess is wrong, but if he is right, output "Happy Alex".

Examples
Input
3
2 2
3 3
1 1
Output
Poor Alex
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int main()
{
	int L;
	
	int p, q;
	map<int,int> laptop;

	cin >> L;
	bool happy = false;
	for (int i = 0; i < L; ++i) {
		cin >> p >> q;	
		laptop[p] = q;
	}
	int min = 0;
	for (auto i: laptop) {
		if (i.second >= min) {
			min = i.second;
		}
		else
		{
			happy = true;
			break;
		}
	}
	/*for (int i = 0; i < L; ++i) {
		for (int j = 0; j < L; ++j) {
			if (i == j) {
				continue;
			}
			if (price[i] < price[j] && quality[i] > quality[j]) {
				happy = true;
				break;
			}
		}
		
	}*/
	if (happy) {
		cout << "Happy Alex";
	}

	else
	{
		cout << "Poor Alex";
	}

}
