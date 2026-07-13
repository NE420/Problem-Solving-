/*
Rafi and his girlfriend go to the mall. They get in to a stall. Rafi thinks that if he buys her the cheapest product, it will disgrace him. But, he does not have enough money at this moment to buy the expensive products. So, he decides to buy the product with the second lowest price. He also decides that the price of the product should be strictly greater than the lowest one. If no such product exist, they will leave the shop, telling the shop owner ‘NO’. Help Rafi choose the product.

Input
The input consists of two lines. The first of which contains a single integer n (1 ≤ n ≤ 100) which denotes the number of products. The second line contains n space-separated integers which denote the prices of the products. These may be negative but their absolute value is less that or equal to 100.

Output
If the given pricelist has a product with the second lowest price, output this price, otherwise output NO.

Examples
Input
4
1 2 2 -4
Output
1
Input
5
1 2 3 1 1
Output
2
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int n = 0;
	vector<int> vec;
	
	cin >> n;
	for (int i = 0; i < n;++i) {
		int num;
		cin >> num;
		vec.push_back(num);
	}

	sort(vec.begin(), vec.end());
	
	int minVal = vec[0];

	vec.erase(remove(vec.begin(), vec.end(), minVal), vec.end());

	if (vec.empty()) {
		cout << "NO";
	}
	else {
		cout << vec[0];
	}
	
}
