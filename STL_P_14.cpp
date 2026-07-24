/*
Our good friend Mole is trying to code a big message. He is typing on an unusual keyboard with characters arranged in following way:


qwertyuiop
asdfghjkl;
zxcvbnm,./
Unfortunately Mole is blind, so sometimes it is problem for him to put his hands accurately. He accidentally moved both his hands with one position to the left or to the right. That means that now he presses not a button he wants, but one neighboring button (left or right, as specified in input).

We have a sequence of characters he has typed and we want to find the original message.

Input
First line of the input contains one letter describing direction of shifting ('L' or 'R' respectively for left or right).

Second line contains a sequence of characters written by Mole. The size of this sequence will be no more than 100. Sequence contains only symbols that appear on Mole's keyboard. It doesn't contain spaces as there is no space on Mole's keyboard.

It is guaranteed that even though Mole hands are moved, he is still pressing buttons on keyboard and not hitting outside it.

Output
Print a line that contains the original message.

Examples
Input	
R
s;;upimrrfod;pbr
Output
allyouneedislove
*/

#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;


int main()
{
	cin.tie(nullptr), cout.tie(nullptr), cin.sync_with_stdio(false), cout.sync_with_stdio(false);
	
    vector<string> alpha = { "qwertyuiop","asdfghjkl;","zxcvbnm,./" };

    map<char, char> left, right;
    for (auto& line : alpha) {
        for (int i = 0; i < line.size(); i++) {
            if (i - 1 >= 0)
                left[line[i]] = line[i - 1];
            if (i + 1 < line.size())
                right[line[i]] = line[i + 1];
        }
    }

    char direction;
    string input;
    cin >> direction >> input;
    for (auto c : input) {
        if (direction == 'L')
            cout << right[c];
        else
            cout << left[c];
    }
	
	return 0; 

}
