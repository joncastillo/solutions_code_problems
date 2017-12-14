//
//  main.cpp
//  stack_machine
//
//  Created by Jonathan Castillo on 15/12/17.
//  Copyright © 2017 joncastillo.org. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

string solution(string input)
{
    stack<string> stackMachine;
    string output;
    
    for (string::iterator it = input.begin();
         it != input.end();
         ++it)
    {
        char current = *it;
        if (current >= '0' && current <='9')
        {
            string temp;
            temp+=current;
            stackMachine.push(temp);
        }
        else
        {
            int answer = -1;
            if (stackMachine.size() >= 2)
            {
                string strright = stackMachine.top();
                stackMachine.pop();
                string strleft = stackMachine.top();
                stackMachine.pop();
                
                stringstream ssright(strright);
                stringstream ssleft(strleft);
                
                int left;
                int right;
                ssleft >> left;
                ssright >> right;
            
                switch (*it)
                {
                    case '*':
                        answer = left * right;
                        break;
                    case '+':
                        answer = left + right;
                        break;
                    default:
                        return "-1";
                }
                stringstream ssanswer;
                ssanswer << answer;
                stackMachine.push(ssanswer.str());
            }
            else
            {
                return "-1";
            }
            if (stackMachine.size()==1)
            {
                string stranswer = stackMachine.top();
                output = stranswer;
            }
        }
    }
    
    return output;
}

int main(int argc, const char * argv[]) {
    string input;
    cout << "Enter string:" <<endl;
    getline(cin,input);

    string output = solution(input);
    cout << "Simplified:" <<endl;
    cout << output << endl;
    
    return 0;
}
