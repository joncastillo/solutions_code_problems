//
//  main.cpp
//  array_pair_sum
//
//  Created by Jonathan Castillo on 14/12/17.
//  Copyright © 2017 joncastillo.org. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<int,int> solution( vector<int> inputs, int sum )
{
    map<int,int> mapped_input;
    map<int,int> mapped_output;
    
    for (vector<int>::iterator it = inputs.begin();
         it != inputs.end();
         ++it )
    {
        mapped_input[*it]++;
    }
    
    for (vector<int>::iterator it = inputs.begin();
         it != inputs.end();
         ++it )
    {
        if (*it <= (sum/2))
        {
            int addend = sum - *it;
                if (addend != *it)
                {
                    if ( mapped_input[addend] >0 )
                        mapped_output[*it] = addend;
                }
                else
                {
                    if ( mapped_input[addend] >1 )
                        mapped_output[*it] = addend;
                }
        }
    }

    return mapped_output;
}

int main(int argc, const char * argv[]) {

    vector<int> input;
    map<int,int> output;

    int sum;
    int n;
    
    cout << "Input sum: ";
    cin >> sum;
    
    cout << "Input count of elements: ";
    cin >> n;

    for (int i = 0 ; i < n ; i++){
        cout << "Input element[" << i+1 << "]: ";
        int element;
        cin >> element;
        input.push_back(element);
    }
  
    output = solution(input, sum);
    
    for (map<int,int>::iterator it = output.begin();
         it != output.end();
         ++it)
    {
        cout << "[" << it->first << ", " << it->second << "]" <<endl;
    }
    
    return 0;
}
