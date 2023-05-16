#include <bits/stdc++.h>

/*
 * Complete the 'longestSubarray' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int evaluate(std::map<int,int>& subArray)
{
    if(subArray.empty())
        return 0;

    if(subArray.size() == 1)
        return subArray.begin()->second;
    else
        return subArray.begin()->second + std::prev(subArray.end())->second;
}


bool addToSubArray(int val,std::map<int,int>& subArray)
{
    auto it = subArray.find(val) ;
    if(it == subArray.end())
    {
        subArray.insert({val,1});
    }
    else
    {
        it->second++;
    }

    if(subArray.size() == 2)
    {
        if(std::abs(subArray.begin()->first - std::prev(subArray.end())->first) != 1)
        {

            return false;
        }
    }

    return true;
}

int longestSubarray(std::vector<int> arr) {

    std::set<int> lengthSubArrays;
    std::map<int,int> subArray;//subArray can only consist of TWO distinct numbers

    for(size_t a = 0; a < arr.size(); a++)
    {
        std::map<int,int>::iterator it = subArray.find(arr[a]);

        //check if value is already in subArray
        if(it == subArray.end())
        {
            int lastInsert;
            if(subArray.size() < 2)
            {
                lastInsert = arr[a];
                subArray.insert({arr[a],1});

                if(subArray.size() == 2)
                {
                    const int diff = std::abs(subArray.begin()->first - std::prev(subArray.end())->first);
                    if(diff != 1) //difference is not 1 (we do not have to check for zero because map ensures that each key is unique)
                    {
                        lengthSubArrays.insert(evaluate(subArray) - 1);
                        subArray.clear();

                        subArray.insert({lastInsert,1});
                        auto itA = subArray.find(arr[a]);
                        if(itA == subArray.end())
                            subArray.insert({arr[a],1});
                        else
                            subArray.find(arr[a])->second++;

                        continue;
                    }
                }
            }
            else //we need two distinct numbers, a third one would be wrong
            {
                lengthSubArrays.insert(evaluate(subArray));
                subArray.clear();
                subArray.insert({lastInsert,1});
                auto itA = subArray.find(arr[a]);
                if(itA == subArray.end())
                    subArray.insert({arr[a],1});
                else
                    subArray.find(arr[a])->second++;

                continue;
            }
        }
        else
        {
            it->second++;
        }

        lengthSubArrays.insert(evaluate(subArray));

    }

    return *lengthSubArrays.rbegin();
}
/*
void insertSubArray(const int val, std::map<int,int>& subArray, std::set<int>& length, std::pair<int,int>& lastInsert)
{
    if(subArray.size() == 0)
    {
        subArray.insert({val,1});
        lastInsert = {val, 1};
    }
    else if(subArray.size() == 1)
    {
        auto it = subArray.find(val);

        if(it == subArray.end()) //not already in
        {
            if(std::abs(subArray.begin()->second - val) != 1) //not allowed to continue with that subArray
            {
                length.insert(evaluate(subArray));//evaluate current subArray
                subArray.clear();
                subArray.insert({val,1});
                lastInsert = {val,1};
            }
            else //allowed to be inserted because diff == 1
            {
                subArray.insert({val,1});
                lastInsert = {val,1};
            }
        }
        else//already in
        {
            it->second++;
            lastInsert = *it;
        }
    }
    else if(subArray.size() == 2)
    {
        auto it = subArray.find(val);

        if(it == subArray.end()) // not already in, because of third number we have to start a new subArray
        {
            if(std::abs(lastInsert.first - val) != 1)
            {
                length.insert(evaluate(subArray));//evaluate current subArray
                subArray.clear();
                subArray.insert({val,1});
                lastInsert = {val,1};
            }
            else
            {
                length.insert(evaluate(subArray));//evaluate current subArray
                subArray.clear();
                subArray.insert(lastInsert);
                subArray.insert({val,1});
                lastInsert = {val,1};
            }
        }
        else //already in
        {
            it->second++;
            lastInsert = *it;
        }
    }
}

int longestSubarray(std::vector<int> arr) {

    std::set<int> length;
    std::map<int,int> subArray;

    std::pair<int,int> lastInsert;
    for(std::vector<int>::iterator it0 = arr.begin(); it0 != arr.end(); it0++)
    {
        auto alreadyIn = subArray.find(*it0);

        if(alreadyIn != subArray.end())
        {
            alreadyIn->second++;
            lastInsert = *alreadyIn;
        }
        else
        {
            insertSubArray(*it0,subArray,length,lastInsert);
        }
    }

    length.insert(evaluate(subArray));
    return *length.rbegin();
}
*/
void check(int sol0, int sol1, int i)
{
    if(sol0 != sol1)
        std::cout<<"Error in testcase "<< i <<std::endl;
    else
        std::cout<<"Success in testcase " << i <<std::endl;
}

int main()
{
    std::vector<int> input_ex = {0, 1, 2, 1, 2, 3};
    //check(longestSubarray(input_ex),4,-1);

    std::vector<int> input_0 = {1, 2 ,3, 4, 5};
    //check(longestSubarray(input_0),2,0);

    std::vector<int> input_1 = {2, 2, 1};
    //check(longestSubarray(input_1),3,1);

    std::vector<int> input_2 = {295331535};
    //check(longestSubarray(input_2),1,2);

    std::vector<int> input_3 = {
        157793605
       ,157793605
       ,157793604
       ,157793604
       ,157793604
       ,157793604
       ,157793605
       ,157793605
       ,157793605
       ,157793604
       ,157793605
       ,157793604
       ,157793605
       ,157793605
       ,157793604
       ,157793604
       ,157793604
       ,157793605
       ,157793605
       ,157793605
       ,157793605
       ,157793604
       ,157793604
       ,157793605
       ,157793604
       ,157793605
       ,157793605
       ,157793605
       ,157793604
       ,157793605
       ,157793605
    };
    //check(longestSubarray(input_3),31,3);

    std::vector<int> input_4 = {
        157793605
       ,195593459
       ,195593459
       ,195593458
       ,195593457
       ,195593459
       ,195593459
       ,195593458
       ,195593459
       ,195593458
       ,195593459
       ,195593457
       ,195593458
       ,195593458
       ,195593457
       ,195593457
       ,195593457
       ,195593457
       ,195593458
       ,195593457
       ,195593459
       ,195593457
       ,195593457
       ,195593458
       ,195593457
       ,195593457
       ,195593458
       ,195593458
       ,195593457
       ,195593458
       ,195593457
       ,195593457
       ,195593457
       ,195593459
       ,195593459
       ,195593459
       ,195593458
       ,195593458
       ,195593458
       ,195593458
       ,195593458
       ,195593457
       ,195593459
       ,195593459
       ,195593458
       ,195593457
       ,195593459
       ,195593459
       ,195593457
       ,195593459
       ,195593459
       ,195593457
       ,195593457
       ,195593459
       ,195593459
       ,195593457
       ,195593459
       ,195593458
       ,195593458
       ,195593458
       ,195593457
       ,195593458
       ,195593458
       ,195593458
       ,195593458
       ,195593457
       ,195593458
       ,195593459
       ,195593458
       ,195593459
       ,195593458
       ,195593459
       ,195593458
       ,195593458
       ,195593459
       ,195593459
       ,195593458
       ,195593457
       ,195593459
       ,195593459
       ,195593459
       ,195593459
       ,195593457
       ,195593459
       ,195593459
       ,195593459
       ,195593459
       ,195593459
       ,195593457
       ,195593459
       ,195593457
       ,195593458
       ,195593457
       ,195593458
       ,195593458
       ,195593457
       ,195593459
       ,195593457
       ,195593457
       ,195593459
       ,195593457
       ,195593459
       ,195593459
       ,195593458
       ,195593457
       ,195593459
       ,195593458
       ,195593459
       ,195593459
       ,195593458
       ,195593458
       ,195593459
       ,195593458
       ,195593459
       ,195593458
       ,195593457
       ,195593459
       ,195593458
       ,195593457
       ,195593457
       ,195593457
       ,195593458
       ,195593457
       ,195593459
       ,195593457
       ,195593458
       ,195593459
       ,195593458
       ,195593458
       ,195593459
       ,195593457
       ,195593459
       ,195593459
       ,195593459
       ,195593458
       ,195593459
       ,195593458
       ,195593458
       ,195593459
       ,195593458
       ,195593459
       ,195593458
       ,195593457
       ,195593457
       ,195593457
       ,195593459
       ,195593458
       ,195593459
       ,195593458
       ,195593457
    };
    check(longestSubarray(input_4),12,4);

    std::vector<int> input_5 =
    {
         914498436
        ,914498434
        ,914498435
        ,914498436
        ,914498436
        ,914498434
        ,914498435
        ,914498435
        ,914498435
        ,914498435
        ,914498436
        ,914498434
        ,914498435
        ,914498434
        ,914498435
        ,914498434
        ,914498435
        ,914498434
        ,914498436
        ,914498436
        ,914498434
        ,914498434
        ,914498436
        ,914498434
        ,914498434
        ,914498436
        ,914498435
        ,914498435
        ,914498436
        ,914498435
        ,914498434
        ,914498435
        ,914498436
        ,914498436
        ,914498435
        ,914498436
        ,914498434
        ,914498434
        ,914498434
        ,914498436
        ,914498435
        ,914498436
        ,914498435
        ,914498434
        ,914498435
        ,914498436
        ,914498435
        ,914498434
        ,914498434
        ,914498435
        ,914498436
        ,914498434
        ,914498435
        ,914498434
        ,914498436
        ,914498435
        ,914498436
        ,914498434
        ,914498434
        ,914498435
        ,914498436
        ,914498435
        ,914498434
        ,914498436
        ,914498435
        ,914498435
        ,914498435
        ,914498436
        ,914498435
        ,914498435
        ,914498436
        ,914498435
        ,914498436
        ,914498434
        ,914498435
        ,914498434
        ,914498434
        ,914498434
        ,914498434
        ,914498434
        ,914498436
        ,914498435
        ,914498436
        ,914498435
        ,914498435
        ,914498435
        ,914498434
        ,914498434
        ,914498436
        ,914498436
        ,914498436
        ,914498435
        ,914498434
        ,914498436
        ,914498434
        ,914498436
        ,914498434
        ,914498436
        ,914498435
        ,914498434
        ,914498434
        ,914498434
        ,914498435
        ,914498434
        ,914498435
        ,914498434
        ,914498434
        ,914498435
        ,914498436
        ,914498436
        ,914498434
        ,914498435
        ,914498434
        ,914498436
        ,914498434
        ,914498435
        ,914498435
        ,914498436
        ,914498435
        ,914498435
        ,914498435
        ,914498435
        ,914498436
        ,914498436
        ,914498434
        ,914498434
        ,914498435
        ,914498435
        ,914498434
        ,914498434
        ,914498435
        ,914498434
        ,914498435
        ,914498434
        ,914498435
        ,914498436
        ,914498436
        ,914498436
        ,914498436
        ,914498436
        ,914498435
        ,914498436
        ,914498435
        ,914498436
        ,914498436
        ,914498436
        ,914498434
        ,914498435
        ,914498436
        ,914498436
        ,914498436
        ,914498435
        ,914498434
        ,914498436
        ,914498435
        ,914498435
        ,914498436
        ,914498436
        ,914498434
        ,914498434
        ,914498436
        ,914498436
        ,914498434
        ,914498435
        ,914498434
        ,914498436
        ,914498436
        ,914498434
        ,914498434
        ,914498436
        ,914498436
        ,914498436
        ,914498435
        ,914498434
        ,914498436
        ,914498435
        ,914498434
        ,914498434
        ,914498436
        ,914498434
        ,914498435
        ,914498435
        ,914498435
        ,914498436
        ,914498435
        ,914498436
        ,914498435
        ,914498435
        ,914498436
        ,914498435
        ,914498435
        ,914498434
        ,914498435
        ,914498435
        ,914498436
        ,914498435
        ,914498436
        ,914498435
        ,914498436
        ,914498434
        ,914498434
        ,914498435
        ,914498436
        ,914498436
        ,914498434
        ,914498436
        ,914498434
        ,914498434
        ,914498434
        ,914498434
        ,914498435
        ,914498436
        ,914498436
        ,914498434
        ,914498435
        ,914498434
        ,914498434
        ,914498436
        ,914498435
        ,914498434
        ,914498435
        ,914498436
        ,914498434
        ,914498434
        ,914498436
        ,914498434
        ,914498436
        ,914498435
        ,914498436
        ,914498436
        ,914498436
        ,914498434
        ,914498435
        ,914498435
        ,914498434
        ,914498435
        ,914498435
        ,914498435
        ,914498436
        ,914498436
        ,914498436
        ,914498435
        ,914498435
        ,914498436
        ,914498435
        ,914498436
        ,914498436
        ,914498436
        ,914498434
        ,914498436
        ,914498434
        ,914498435
        ,914498435
        ,914498435
        ,914498435
        ,914498434
        ,914498436
        ,914498436
        ,914498436
        ,914498436
        ,914498435
        ,914498435
        ,914498434
        ,914498436
        ,914498435
        ,914498434
        ,914498436
        ,914498434
        ,914498436
        ,914498436
        ,914498434
        ,914498436
        ,914498434
        ,914498435
        ,914498436
        ,914498436
        ,914498435
        ,914498436
        ,914498436
        ,914498435
        ,914498435
        ,914498434
        ,914498435
        ,914498434
        ,914498436
        ,914498434
        ,914498435
        ,914498436
        ,914498436
        ,914498436
        ,914498435
        ,914498434
        ,914498435
        ,914498435
        ,914498435
        ,914498436
        ,914498435
        ,914498434
        ,914498434
        ,914498435
        ,914498436
        ,914498434
        ,914498435
        ,914498434
        ,914498435
        ,914498434
        ,914498436
        ,914498435
        ,914498436
        ,914498436
        ,914498434
        ,914498435
        ,914498434
        ,914498435
        ,914498436
        ,914498434
        ,914498436
        ,914498435
        ,914498436
        ,914498435
        ,914498434
        ,914498435
        ,914498434
        ,914498436
        ,914498436
        ,914498436
        ,914498436
        ,914498435
        ,914498436
        ,914498434
        ,914498436
        ,914498436
        ,914498434
        ,914498435
        ,914498436
        ,914498434
        ,914498435
        ,914498436
        ,914498435
        ,914498435
        ,914498434
        ,914498436
        ,914498434
        ,914498434
        ,914498435
        ,914498436
        ,914498435
        ,914498434
        ,914498434
        ,914498434
        ,914498436
        ,914498436
        ,914498436
        ,914498434
        ,914498436
        ,914498435
        ,914498436
        ,914498435
        ,914498434
        ,914498436
        ,914498436
        ,914498434
        ,914498436
        ,914498435
        ,914498436
        ,914498435
        ,914498435
        ,914498435
        ,914498436
        ,914498434
        ,914498436
        ,914498436
        ,914498436
        ,914498436
    };

    check(longestSubarray(input_5),13,5);
    return 0;
}


