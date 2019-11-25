//
//  main.cpp
//  ReverseWordsInSentence
//
//  Created by Aniket Bhushan on 23/11/19.
//  Copyright © 2019 Aniket Bhushan. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stack>

std::string reverseSentence(std::string sentence)
{
    std::stringstream ss(sentence);
    std::string str;
    std::stack<std::string> st;
    
    while (ss >> str) {
        st.push(str);
        st.push(" ");
    }
    st.pop();
    
    std::stringstream ss1;
    while (!st.empty())
    {
        auto top = st.top(); st.pop();
        ss1 << top;
    }
    return ss1.str();
}

int main(int argc, const char * argv[]) {
    std::string sentence("The quick brown fox jumped over the lazy dog.");
    std::cout << reverseSentence(sentence) << std::endl;
    return 0;
}
