#include <bits/stdc++.h>
#include <iostream>
#include <chrono>
using namespace std;



/*
 * Complete the 'findSum' function below.
 *
 * The function is expected to return a LONG_INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY numbers
 *  2. 2D_INTEGER_ARRAY queries
 */

vector<long> findSum(vector<int> numbers, vector<vector<int>> queries) {
    std::vector<long> sol;
    sol.resize(queries.size(),0);
    size_t queryNo = 0;
    for(const auto& query : queries)
    {
        std::unordered_map<long,int> umap;
        for(int q = query[0]; q <= query[1]; q++)
            umap[numbers[q]]++;

        std::for_each(umap.begin(),umap.end(),[queryNo,&sol,&query](const std::pair<long,int>& p)
        {
            if(p.first == 0)
                sol[queryNo] += query[2] * p.second;
            else
                sol[queryNo] += p.first * p.second;

        });
        queryNo++;
    }

    return sol;
}

void check(const vector<long>& vec0 ,const vector<long> vec1, int testNo)
{
    if(vec0.size() != vec1.size())
    {
        cout<<"ERROR IN TESTCASE "<< testNo<<endl;
        return;
    }

    for(int a = 0; a < vec0.size(); a++)
    {
        if(vec0[a] != vec1[a])
        {
            cout<<"ERROR IN TESTCASE "<< testNo<<endl;
            return;
        }
    }
     cout<<"SUCCESS IN TESTCASE "<< testNo<<endl;
}

int main()
{

    vector<int> numbers0 = {3, 5, 10, 10, 1, 3};
    vector<vector<int>> queries0 = {{1, 2, 5}};
    vector<long> solution0 = {15};

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    vector<long> mySolution0 = findSum(numbers0,queries0);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    check(solution0,mySolution0,0);

    vector<int> numbers1 = {2, -5, 0, 2, 3};
    vector<vector<int>> queries1 = {{2, 2, 20},{1, 2, 10}};
    vector<long> solution1 = {20, 5};
    begin = std::chrono::steady_clock::now();
    vector<long> mySolution1 = findSum(numbers1,queries1);
    end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    check(solution1,mySolution1,1);

    vector<int> numbers2 = {7, -1, -1, 1, -4, 3, -3, -4, 1, 3};
    vector<vector<int>> queries2 = {{1, 4, 2}};
    vector<long> solution2 = {-5};
    begin = std::chrono::steady_clock::now();
    vector<long> mySolution2 = findSum(numbers2,queries2);
    end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    check(solution2,mySolution2,2);

    vector<int> numbers3 = {1, 1000000000, 1, 3};
    vector<vector<int>> queries3 = {{1, 1, 100}};
    vector<long> solution3 = {1000000000};
    begin = std::chrono::steady_clock::now();
    vector<long> mySolution3 = findSum(numbers3,queries3);
    end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    check(solution3,mySolution3,3);

    vector<int> numbers4 = {1, -1000000000, 1, 3};
    vector<vector<int>> queries4 = {{1, 1, 100}};
    vector<long> solution4 = {-1000000000};
    begin = std::chrono::steady_clock::now();
    vector<long> mySolution4 = findSum(numbers4,queries4);
    end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    check(solution4,mySolution4,4);

    vector<int> numbers5 = {1, 8, 1, 3,6,3,1,7,9,4,1,6,0,0,0,0,0,3,5,8};
    vector<vector<int>> queries5 = {{0, 1, 5},{12, 16, 5},{15, 19, 5},{0,19,5}};
    vector<long> solution5 = {9,25,26,91};
    begin = std::chrono::steady_clock::now();
    vector<long> mySolution5 = findSum(numbers5,queries5);
    end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    check(solution5,mySolution5,5);

    return 0;
}

