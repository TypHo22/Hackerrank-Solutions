#include <bits/stdc++.h>
#include <ctype.h>
#include <algorithm>
#include <string>
/*
 * Complete the 'getMinCost' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY crew_id
 *  2. INTEGER_ARRAY job_id
 */

std::string decryptPassword(std::string password)
{
    size_t i = password.length();
    int zeroCount = 0;
    while(i != 0)
    {
        if(password[i] == '0')
        {
            password[i] = password[zeroCount];
            zeroCount++;
        }
        else if(password[i] == '*')
        {
            std::swap(password[i - 1], password[i - 2]);
        }

        i--;
    }


    password = password.substr(zeroCount,password.length());
    password.erase(std::remove(password.begin(), password.end(), '*'), password.end());
    return password;
}

void check(std::string sol0, std::string sol1, int i)
{
    if(sol0 != sol1)
        std::cout<<"Error in testcase "<< i <<std::endl;
    else
        std::cout<<"Success in testcase " << i <<std::endl;
}

int main()
{
    check(decryptPassword("51Pa*0Lp*0e"),"aP1pL5e",0);
    check(decryptPassword("pTo*Ta*O"),"poTaTO",1);
    check(decryptPassword("1Bl*Kg*u0"),"lBgKu1",2);
    check(decryptPassword("6UDTyn0Hm*BqBp*ur"),"UDTyn6mHBqpBur",3);
    check(decryptPassword("487RESx*Fpd0Xukr0m0Du"),"RExSFpd7Xukr8m4Du",4);
    check(decryptPassword("a"),"a",5);

    return 0;
}


