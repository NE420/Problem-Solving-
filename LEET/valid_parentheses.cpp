/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

Example 5:

Input: s = "([)]"

Output: false

 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> open;
        stack<char> close;
        for(auto i : s){
            if(open.empty() && (i == ')' || i == ']' || i == '}' )){
                return false;
            }
            if(i == '('){
                open.push('(');
                close.push(')');
            }
            if(i == ')' || i == ']' || i == '}'){
                if(close.top() != i ){
                    return false;
                }
                if(i == ')' && close.top() == ')')
                {
                    if(open.top() != '('){
                        return false;
                    }
                    close.pop();
                    open.pop();
                }
                if(i == ']' && close.top() == ']')
                {
                    if(open.top() != '['){
                        return false;
                    }
                    close.pop();
                    open.pop();
                }
                if(i == '}' && close.top() == '}')
                {
                    if(open.top() != '{'){
                        return false;
                    }
                    close.pop();
                    open.pop();
                }
            }
            if(i == '['){
                open.push('[');
                close.push(']');
            }
            if(i == '{'){
                open.push('{');
                close.push('}');
            }
        }
        if(open.size() > 0 || close.size() > 0){
            return false;
        }
        return true;
    }
};
