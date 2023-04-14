
#include <bits/stdc++.h>
#include <chrono>
#include <fstream>
#include <thread>
using namespace std;


/*
 * Complete the 'filledOrders' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY order
 *  2. INTEGER k
 */
std::map<char,int> lookUp =
{
  {'a',1},{'b',2}
 ,{'c',3},{'d',4}
 ,{'e',5},{'f',6}
 ,{'g',7},{'h',8}
 ,{'i',9},{'j',10}
 ,{'k',11},{'l',12}
 ,{'m',13},{'n',14}
 ,{'o',15},{'p',16}
 ,{'q',17},{'r',18}
 ,{'s',19},{'t',20}
 ,{'u',21},{'v',22}
 ,{'w',23},{'x',24}
 ,{'y',25},{'z',26}
};

std::vector<int> calcStrToNums(const string& str)
{
    std::vector<int> nums;
    for(const auto& c : str)
        nums.push_back(lookUp.find(c)->second);

    std::sort(nums.begin(),nums.end());
    return nums;
}
void toUmap(const string& str, unordered_map<int,std::vector<std::vector<int>>>& umap)
{
     int sum = str.size();

     auto it = umap.find(sum);

     if(it == umap.end())
     {
         umap.insert({sum,{calcStrToNums(str)}});
     }
     else
     {
        it->second.emplace_back(calcStrToNums(str));
     }
}

vector<int> parallelizedTask(vector<string> dictionary, vector<string> query)
{
    vector<int> subSolution;
    subSolution.resize(query.size());
    unordered_map<int,std::vector<std::vector<int>>> umapDic; //size of strings, strings

    for(const auto& str : dictionary)
        toUmap(str,umapDic);

    int count = 0;
    for(const auto& str : query)
    {
        auto it = umapDic.find(str.size());

        if(it != umapDic.end())
        {
            std::vector<int> nums;
            for(const auto& c : str)
                nums.push_back(lookUp.find(c)->second);

            std::sort(nums.begin(),nums.end());
            for(const auto& c : it->second)
            {
                if(c == nums)
                    subSolution[count]++;
            }
        }
        count++;
    }
    return subSolution;
}

vector<int> stringAnagram(vector<string> dictionary, vector<string> query)
{
    vector<int> solution;
    solution.resize(query.size(),0);
    if(dictionary.size() > 500)
    {
        std::size_t const half_size = dictionary.size() / 2;
        vector<string> subDictionary0(dictionary.begin(),dictionary.begin() + half_size);
        vector<string> subDictionary1(dictionary.begin() + half_size,dictionary.end());
        auto future0 = std::async(parallelizedTask,subDictionary0,query);
        auto future1 = std::async(parallelizedTask,subDictionary1,query);
        vector<int> subSolution0 = future0.get();
        vector<int> subSolution1 = future1.get();

        std::transform (subSolution0.begin(), subSolution0.end(), subSolution1.begin(), subSolution0.begin(), std::plus<int>());
        solution = subSolution0;
    }
    else
    {
        unordered_map<int,std::vector<std::vector<int>>> umapDic; //size of strings, strings

        for(const auto& str : dictionary)
            toUmap(str,umapDic);

        int count = 0;
        for(const auto& str : query)
        {
            auto it = umapDic.find(str.size());

            if(it != umapDic.end())
            {
                std::vector<int> nums;
                for(const auto& c : str)
                    nums.push_back(lookUp.find(c)->second);

                std::sort(nums.begin(),nums.end());
                for(const auto& c : it->second)
                {
                    if(c == nums)
                        solution[count]++;
                }
            }
            count++;
        }

    }
    return solution;
}



void check(vector<int> v0 , vector<int> v1,int testNo)
{
    if(v0.size() != v1.size())
    {
        cout<<"ERROR IN TESTCASE "<< testNo<<endl;
        return;
    }

    for(size_t a = 0; a < v0.size(); a++)
    {
        if(v0[a] != v1[a])
        {
            cout<<"ERROR IN TESTCASE "<< testNo<<endl;
            return;
        }
    }
    cout<<"SUCCESS IN TESTCASE "<< testNo<<endl;
}

int main()
{
    vector<string> dictionary0 = {"heater","cold","clod","reheat","docl"};
    vector<string> query0      = {"codl","heater","abcd"};
    vector<int> solution0 = {3,2,0};
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    vector<int> mySolution0 = stringAnagram(dictionary0,query0);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    check(mySolution0,solution0,0);
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;


    vector<string> dictionary1 = {"listen","tow","silent","lisent","two","abc","no","on"};
    vector<string> query1      = {"two","bca","no","listen"};
    vector<int> solution1 = {2,1,2,3};
    begin = std::chrono::steady_clock::now();
    vector<int> mySolution1 = stringAnagram(dictionary1,query1);
    end = std::chrono::steady_clock::now();
    check(mySolution1,solution1,1);
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;

    vector<string> dictionary2 = {"love","stairs","sitars","cool","looc"};
    vector<string> query2      = {"pick","stair","abcd"};
    vector<int> solution2 = {0,0,0};
    begin = std::chrono::steady_clock::now();
    vector<int> mySolution2 = stringAnagram(dictionary2,query2);
    end = std::chrono::steady_clock::now();
    check(mySolution2,solution2,2);
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;

    vector<string> dictionary3;
    vector<string> query3;
    vector<int> solution3;

    std::fstream f;
    f.open("/home/andreas.bernatzky/Programming/HackerRank/input3");
    if(f.is_open())
    {
        std::string str;
        while(f >>  str)
        {
            dictionary3.push_back(str);
        }
    }
    f.close();


    f.open("/home/andreas.bernatzky/Programming/HackerRank/input3Query");
    if(f.is_open())
    {
        std::string str;
        while(f >>  str)
        {
            query3.push_back(str);
        }
    }
    f.close();

    f.open("/home/andreas.bernatzky/Programming/HackerRank/sol3");
    if(f.is_open())
    {
        std::string str;
        while(f >>  str)
        {
            solution3.push_back(std::stoi(str));
        }
    }
    f.close();
    begin = std::chrono::steady_clock::now();
    vector<int> mySolution3 = stringAnagram(dictionary3,query3);
    end = std::chrono::steady_clock::now();
    check(mySolution3,solution3,3);
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;

    return 0;
}

