class Solution {
public:
    string intToRoman(int num) {
        // Arrays of Roman numeral symbols and their corresponding values
        vector<int> values    = {1000, 900, 500, 400, 100,  90,  50,  40,  10,   9,   5,   4,   1};
        vector<string> symbols = {"M",  "CM","D", "CD","C", "XC","L", "XL","X", "IX","V", "IV","I"};

        string roman;

        // Convert the number to Roman numeral
        for (int i = 0; i < values.size() && num > 0; ++i) {
            while (num >= values[i]) {
                roman += symbols[i]; // Append symbol
                num -= values[i];    // Subtract value
            }
        }

        return roman;
    }
};
