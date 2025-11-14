class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length())
        {
            return false;
        }

        unordered_map<char,int> freq1, freq2;
        unordered_set<char> chars1, chars2;
        for(char c : word1)
        {
            freq1[c]++;
            chars1.insert(c);
        } 
        for(char c : word2)
        {
            freq2[c]++;
            chars2.insert(c);
        }   
        if(chars1 != chars2)
        {
            return false;
        }
        vector<int> count1, count2;
        for(auto& [ch, count] : freq1)
        {
            count1.push_back(count);
        }
        for(auto& [ch, count] : freq2)
        {
            count2.push_back(count);
        }
        sort(count1.begin(), count1.end());
        sort(count2.begin(), count2.end());

        return count1 == count2;
    }
};