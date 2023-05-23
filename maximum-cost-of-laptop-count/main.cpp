#include <bits/stdc++.h>


int maxCost(std::vector<int> cost, std::vector<std::string> labels, int dailyCount)
{
    const int n = cost.size();
    int c = 0;
    int maxCost = 0;
    int currentCost = 0;

    for(size_t a = 0; a < n; a++)
    {
        currentCost += cost.at(a);
        // we do not need to compare the whole string
        if(labels.at(a)[0] == 'l') // legal
            c++;
        else // illegal
            continue;

        if(c == dailyCount)
        {
            if(currentCost > maxCost)
                maxCost = currentCost;

            currentCost = 0;
            c = 0;
        }
    }

    return maxCost;
}

void check(int sol0, int sol1, int i)
{
    if(sol0 != sol1)
        std::cout<<"Error in testcase "<< i <<std::endl;
    else
        std::cout<<"Success in testcase " << i <<std::endl;
}

int main()
{
    check(maxCost({2,5,3,11,1},{"legal","illegal","legal","illegal","legal"},2),10,-2);//SampleTestcase 1
    check(maxCost({0,3,2,3,4}, {"legal","legal","illegal","legal","legal"},1),5,-1);//SampleTestcase 2
    check(maxCost({2}, {"illegal"},1),0,0);
    check(maxCost({0,3,2,3,4}, {"legal","legal","illegal","legal","legal"},1),5,1);
    check(maxCost({3,2,0,2,4,0,1,4}, {"legal","illegal","legal","legal","illegal","legal","legal","legal"},4),11,2);
    return 0;
}


