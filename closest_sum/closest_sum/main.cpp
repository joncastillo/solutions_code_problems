//
//  main.cpp
//  closest_sum
//
//  Created by Jonathan Castillo on 15/12/17.
//  Copyright © 2017 joncastillo.org. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int solution(int sum, vector<int> array)
{
    map<int,int> count_elements;
    vector<int> newArray;
    
    for (vector<int>::iterator it = array.begin();
         it!= array.end();
         ++it)
    {
        count_elements[*it]++;
        newArray.push_back(sum-*it);
    }

    for (vector<int>::iterator it = newArray.begin();
         it!= newArray.end();
         ++it)
    {
        int index = it - newArray.begin();
        if (array[index] == newArray[index])
        {
            if (count_elements[array])
        }
    }

    
    
}

int main(int argc, const char * argv[]) {
    int n;
    int sum;
    vector<int> input;
    int output;
    
    cout << "input sum: ";
    cin >> sum;
    cout << "element count: ";
    cin >> n;
    
    for (int i = 0 ; i < n ; i++)
    {
        int number;
        cout << "element[" << i <<"]: ";
        cin >> number;
        input.push_back(number);
    }
    
    output = solution (sum, input);
    
    cout << "closest sum: " << output << endl;
    return 0;
}
