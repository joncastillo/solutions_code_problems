//
//  main.cpp
//  closest_sum_bruteforce
//
//  Created by Jonathan Castillo on 14/12/17.
//  Copyright © 2017 joncastillo.org. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class node;
class node
{
public:
    int level;
    int sum;
    int num;
    
    vector<int> toProcess;
    bool isProcessed;
    
    vector<node> children;
};

// create the tree
void createTree( node& oNode )
{
    for ( vector<int>::iterator it = oNode.toProcess.begin();
         it != oNode.toProcess.end();
         ++it )
    {
        node newNode;
        newNode.level = oNode.level + 1;
        newNode.num = *it;
        newNode.sum = oNode.sum + newNode.num;
        
        std::copy(oNode.toProcess.begin() + (it - oNode.toProcess.begin()) + 1, oNode.toProcess.end(),  std::back_inserter(newNode.toProcess));
        
        
        oNode.children.push_back(newNode);
    }
    oNode.isProcessed = true;

    for ( vector<node>::iterator it = oNode.children.begin();
        it != oNode.children.end();
        ++it)
    {
        createTree (*it);
    }
}

// find number closest to <sum> at <level> of tree
int findClosest(node& oNode, int level, int sum)
{
    bool closestSum_first_found = false;
    int closestSum = 0;
    int shortestDistance = 0;

    //use dfs:
    stack<node*> dfsStack;
    dfsStack.push(&oNode);
    
    while (!dfsStack.empty())
    {
        node* currentNode = dfsStack.top();
        dfsStack.pop();
        
        for (vector<node>::iterator it = currentNode->children.begin();
             it != currentNode->children.end();
             ++it)
        {
            dfsStack.push(&(*it));
        }
        
        if (currentNode->level == level)
        {
            int distance = abs(sum - currentNode->sum);
            if (closestSum_first_found == false)
            {
                //closestSum = distance;
                closestSum = currentNode->sum;
                shortestDistance = distance;
                
                closestSum_first_found = true;
            }
            else
            {
                if (distance < shortestDistance)
                {
                    closestSum = currentNode->sum;
                    shortestDistance = distance;
                }
            }
        }
    }

    return closestSum;
}

int solution(int sum, vector<int> array)
{
    // create primary node
    node primary;
    primary.level = 0;
    primary.sum = 0;
    primary.num = 0;
    
    for (vector<int>::iterator it = array.begin(); it != array.end(); ++it)
    {
        primary.toProcess.push_back(*it);
    }

    createTree( primary );
    int closestSum = findClosest( primary, 3, sum);
    
    return closestSum;
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
