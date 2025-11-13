#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for (char ch : s) {
            // Push opening brackets
            if (ch == '(' || ch == '{' || ch == '[') {
                stk.push(ch);
            } 
            // For closing brackets, check top of stack
            else {
                if (stk.empty()) return false;

                char top = stk.top();
                stk.pop();

                if ((ch == ')' && top != '(') ||
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '[')) {
                    return false;
                }
            }
        }

        // If stack is empty, all brackets matched
        return stk.empty();
    }
};
