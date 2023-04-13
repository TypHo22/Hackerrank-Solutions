#include <bits/stdc++.h>
#include <iterator>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'possibleChanges' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY usernames as parameter.
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

int getOrderOfChar(const char c)
{
    return lookUp.find(c)->second;
}

bool trySwap(const std::string& str)
{
    if(str.size() <= 1)
        return false;

    std::vector<int> orders;

    for(const auto& c : str)
    {
        const int order = getOrderOfChar(c);

        orders.emplace_back(order);

        if(orders.size() > 1)
        {
            auto it = std::find_if(orders.begin(),orders.end(),[order](const int& val)
            {
                return val > order;
            });

            if(it != orders.end())
                return true;
        }
    }

    return false;
}

vector<string> possibleChanges(vector<string> usernames) {
    std::vector<string> v;

    for(const auto& str : usernames)
    {
        bool possible = trySwap(str);

        if(possible)
            v.push_back("YES");
        else
            v.push_back("NO");
    }

    return v;
}

int main()
{
    std::vector<std::string> usernames = {"3","foo","bar","baz","hydra","xxxxxxxxxxxxxxxxx","superhero","bee","ace","ab","ba"};
    std::vector<std::string> solution = {"NO","NO","YES","YES","YES","NO","YES","NO","NO","NO","YES"};
    std::vector<std::string> check = possibleChanges(usernames);

    bool right = true;
    for(size_t a = 0; a < solution.size(); a++)
    {
        if(solution[a] != check[a])
        {
            right = false;
            break;
        }
    }

    if(right)
        std::cout<<"RIGHT"<<std::endl;
    else
        std::cout<<"FALSE"<<std::endl;

    return 0;
}
