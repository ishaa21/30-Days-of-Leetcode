#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) return result;

        vector<string> mapping = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };

        backtrack(result, mapping, digits, 0, "");
        return result;
    }

private:
    void backtrack(vector<string>& result, const vector<string>& mapping, const string& digits, int index, string current) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        string letters = mapping[digits[index] - '0'];
        for (char c : letters) {
            backtrack(result, mapping, digits, index + 1, current + c);
        }
    }
};
