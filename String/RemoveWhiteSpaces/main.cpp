//
//  main.cpp
//  RemoveWhiteSpaces
//
//  Created by Aniket Bhushan on 23/11/19.
//  Copyright © 2019 Aniket Bhushan. All rights reserved.
//

#include <iostream>

void removeWhiteSpaces(std::string& str)
{
    int j=0;
    for (int i=0; i<str.size(); ++i) {
        if (str[i] != ' ')
        {
            str[j] = str[i];
            j++;
        }
    }
    str = str.substr(0, j);
}

void removeExtraWhiteSpaces(std::string& str)
{
    int i = 0;
    
    // Remove starting
    while (str[i] == ' ')
        i++;
    
    int j {i}, beg{i};
    
    bool isSpaceFound {false};
    
    for (; i<str.size(); ++i) {
        if (str[i] == ' ')
        {
            if (!isSpaceFound)
            {
                str[j++] =' ';
                isSpaceFound = true;
            }
        }
        else
        {
            if ((str[i] == '.' || str[i] == ',' || str[i] == '?') &&
                j-1 >= 0 && str[j-1] == ' ')
                str[j-1] = str[i];
            else
                str[j++] = str[i];
            isSpaceFound = false;
        }
    }
    str.erase(str.begin(), str.begin()+beg);
    
    if (str[j-beg-1] == ' ')
        str = str.substr(0, j-beg-1);
    else
        str = str.substr(0, j-beg);
}

int main(int argc, const char * argv[]) {
    std::string str {"g  eeks   for ge  eeks  "};
    removeWhiteSpaces(str);
    
    std::string str1 {"  g  eeks ,  for ge  eeks  ."};
    removeExtraWhiteSpaces(str1);
    
    std::cout << str << std::endl;
    std::cout << str1 << std::endl;
    return 0;
}
