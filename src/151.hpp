
#ifdef HH_PRACTISE
#pragma once
#include "practise/preheader.h"
#endif // HH_PRACTISE

class Solution {
public:
    string reverseWords(string s) {

        string result;
        reverse(s.begin(), s.end());

        string::size_type index = 0;
        while ((index = s.find(' ')) != string::npos) {
            string tmp = std::move(s.substr(0, index));
            s = std::move(s.substr(index + 1));
            //cout << tmp.c_str() << "\n" << s.c_str() << endl;
            if (!tmp.empty()) {
                reverse(tmp.begin(), tmp.end());
                result += tmp + " ";
            }
        }
        if (!s.empty()) {
            reverse(s.begin(), s.end());
            result += s;
        }
        else if(!result.empty() && result[result.length()-1] == ' ') {
            result.erase(result.end() - 1);
        }

        return result;
    }

    void stub() {
        auto result = reverseWords("  hello world!  ");
        cout << "\"" <<result.c_str() << "\"" << endl;
    }

};