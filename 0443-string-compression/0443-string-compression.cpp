class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int index = 0;

        while(i < chars.size())
        {
            char currChar = chars[i];
            int count = 0;

            while(i < chars.size() && chars[i] == currChar )
            {
                count++;
                i++;
            }

            chars[index++] = currChar;

            if(count > 1)
            {
                string cnt = to_string(count);

                for(char ch : cnt)
                {
                    chars[index++] = ch;
                }
            }
        }
        return index;
    }
};