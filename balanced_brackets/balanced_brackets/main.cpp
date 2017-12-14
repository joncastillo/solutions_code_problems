//
//  main.cpp
//  balanced_brackets
//
//  Created by Jonathan Castillo on 14/12/17.
//  Copyright © 2017 joncastillo.org. All rights reserved.
//

#include <iostream>
#include <stack>
#include <map>

using namespace std;

bool solution(string input) {
    bool output = false;
    stack<char> brackets;
    
    map<char,char> bracket_pair;
    bracket_pair['('] = ')';
    bracket_pair['['] = ']';
    bracket_pair['{'] = '}';

    
    for (string::iterator it = input.begin();
         it!= input.end();
         ++it )
    {
        char newBracket = * it;
        
        if (!brackets.empty())
        {
            char currentBracket = brackets.top();

            if ( bracket_pair[currentBracket] == newBracket )
            {
                brackets.pop();
                continue;
            }
        }

        if (bracket_pair.find(newBracket)==bracket_pair.end())
        {
            // not found
            return false;
        }
        else
        {
            brackets.push(newBracket);
        }

    }
    
    if (brackets.empty())
        output = true;
    
    return output;
}

int main(int argc, const char * argv[]) {
    string input;
    bool output;
    
    cout << "Enter expression:" <<endl;
    getline(cin, input);
    
    output = solution(input);

    cout << ( output == true ? "true":"false" ) << endl;

    return 0;
}
