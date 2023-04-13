#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'nearlySimilarRectangles' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts 2D_LONG_INTEGER_ARRAY sides as parameter.
 */

long ratio (long a, long b, long c, long d)
{
    const long ac = a / c;
    const long bd = b / d;



}

long nearlySimilarRectangles(vector<vector<long>> sides)
{
    int ans = 0;
    unordered_map<double, int> umap;

    for(const auto& s : sides)
    {
        const double ratio = static_cast<double>(s[0]) / s[1];
        umap[ratio]++;
    }

    for (auto x : umap)
     {
         int value = x.second;
         if (value > 1)
         {
             ans += (value * (value - 1)) / 2;
         }
     }

    return ans;
}

int main()
{
    std::vector<std::vector<long>> test0 = {{4,8},{15,30},{25,50}};
    long solution0 = 3;
    long mySolution0 = nearlySimilarRectangles(test0);

    std::vector<std::vector<long>> test1 = {{2,1},{10,7},{9,5},{6,9},{7,3}};
    long solution1 = 0;
    long mySolution1 = nearlySimilarRectangles(test1);
    return 0;
}
