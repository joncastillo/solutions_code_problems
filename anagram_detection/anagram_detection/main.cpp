//
//  main.cpp
//  anagram_detection
//
//  Created by Jonathan Castillo on 14/12/17.
//  Copyright © 2017 joncastillo.org. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int solution(string strParent, string strChild)
{
    string strSortedChild = strChild;
    sort(strSortedChild.begin(), strSortedChild.end(), [](char a, char b){return a<b;});
    int count = 0;
    
    for (string::iterator it = strParent.begin();
         it != strParent.end() - strChild.size()+1;
         ++it )
    {
        //get substring
        long int index = it - strParent.begin();
        string strProcessed = strParent.substr(index, strChild.size());
        sort(strProcessed.begin(), strProcessed.end(), [](char a, char b){return a<b;});

        if (strProcessed == strSortedChild)
            count++;
    }
    
    return count;
}

int main(int argc, const char * argv[]) {
    string strParent;
    string strChild;
    
    cout << "Input parent string:" << endl;
    getline(cin, strParent);
    
    cout << "Input child string:" << endl;
    getline(cin, strChild);

    int answer = solution(strParent, strChild);

    cout << "Count of anagrams: " << answer << endl;
    
    return 0;
}
