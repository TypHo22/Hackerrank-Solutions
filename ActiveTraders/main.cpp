#include <bits/stdc++.h>
#include <iterator>
using namespace std;


/*
 * Complete the 'mostActive' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY customers as parameter.
 */

vector<string> mostActive(vector<string> customers)
{
    const float n = customers.size();
    const float threshHold = 0.05;

    map<string,float> shareByStakeHolder;

    for(const auto& a : customers)
    {
        auto isAlreadyIn = shareByStakeHolder.find(a);

        if(isAlreadyIn == shareByStakeHolder.end())
            shareByStakeHolder.insert({a,1});
        else
            isAlreadyIn->second++;
    }

    vector<string> result;
    for(const auto& b : shareByStakeHolder)
    {
        if(b.second / n < threshHold)
            continue;
        else
            result.push_back(b.first);
    }

    std::sort(result.begin(),result.end());

    return result;
}

void check(vector<string> a, vector<string> b, int caseNO)
{
    if(a.size() != b.size())
    {
        cout<<"ERROR in test case "<<caseNO<<endl;
        return;
    }

    for(size_t c = 0; c < a.size(); c++)
    {
        if(a[c] != b[c])
        {
            cout<<"ERROR in test case "<<caseNO<<endl;
            return;
        }
    }
     cout<<"SUCCESS in test case "<<caseNO<<endl;
}

int main()
{
    vector<string> input_0 = {"Omega","Alpha","Omega","Alpha","Omega","Alpha","Omega","Alpha","Omega","Alpha","Omega","Alpha","Omega","Alpha","Omega","Alpha","Omega","Alpha","Omega","Beta"};
    vector<string> sol_0 = {"Alpha","Beta","Omega"};
    check(sol_0,mostActive(input_0),0);

    vector<string> input_1 = {"Alpha","Beta","Zeta","Beta","Zeta","Zeta","Epsilon","Beta","Zeta","Beta","Zeta","Beta","Delta","Zeta","Beta","Zeta","Beta","Zeta","Beta","Zeta","Beta"};
    vector<string> sol_1 = {"Beta","Zeta"};
    check(sol_1,mostActive(input_1),1);

    vector<string> input_2 = {
     "Goes"
    ,"Woof"
    ,"Cat"
    ,"Goes"
    ,"Meow"
    ,"Bird"
    ,"Goes"
    ,"Tweet"
    ,"And"
    ,"Mouse"
    ,"Goes"
    ,"Squeek"
    ,"Cow"
    ,"Goes"
    ,"Moo"
    ,"Frog"
    ,"Goes"
    ,"Croak"
    ,"And"
    ,"The"
    ,"Elephant"
    ,"Goes"
    ,"Toot"
    };

    vector<string> sol_2 = {"And","Goes"};
    check(sol_2,mostActive(input_2),2);

    vector<string> input_3 = {
    "Bey"
    ,"Ddtlcouegmdbyfwu"
    ,"Ppuvhifnuap"
    ,"Ppuvhifnuap"
    ,"Ppuvhifnuap"
    ,"Ppuvhifnuap"
    ,"Ddtlcouegmdbyfwu"
    ,"Ddtlcouegmdbyfwu"
    ,"Ppuvhifnuap"
    ,"Ppuvhifnuap"
    ,"Ppuvhifnuap"
    ,"Ppuvhifnuap"
    ,"Ddtlcouegmdbyfwu"
    ,"Ppuvhifnuap"
    ,"Ddtlcouegmdbyfwu"
    ,"Ppuvhifnuap"
    ,"Ppuvhifnuap"
    ,"Ppuvhifnuap"
    ,"Ppuvhifnuap"
    ,"Ppuvhifnuap"
    };

    vector<string> sol_3 = {"Bey"
                           ,"Ddtlcouegmdbyfwu"
                           ,"Ppuvhifnuap"};
    check(sol_3,mostActive(input_3),3);

    vector<string> input_4 =
    {
     "Bfeo"
    ,"Xjgwxtrxi"
    ,"Pnnpmud"
    ,"Pnnpmud"
    ,"Xjgwxtrxi"
    ,"Wdswxxrx"
    ,"Wdswxxrx"
    ,"Xjgwxtrxi"
    ,"Wdswxxrx"
    ,"Xjgwxtrxi"
    ,"Pnnpmud"
    ,"Wdswxxrx"
    ,"Xjgwxtrxi"
    ,"Wdswxxrx"
    ,"Xjgwxtrxi"
    ,"Xjgwxtrxi"
    ,"Wdswxxrx"
    ,"Wdswxxrx"
    ,"Xjgwxtrxi"
    ,"Xjgwxtrxi"
    };

    vector<string> sol_4 = { "Bfeo"
                            ,"Pnnpmud"
                            ,"Wdswxxrx"
                            ,"Xjgwxtrxi"};
    check(sol_4,mostActive(input_4),4);

    vector<string> input_5 = {
        "Ampprswkdkobdagw"
       ,"Wcfa"
       ,"Zooot"
       ,"Zn"
       ,"Zooot"
       ,"Wufeesrvn"
       ,"Zn"
       ,"Xillkfdvpfpxabqlngd"
       ,"Zn"
       ,"Zn"
       ,"Qvwdrm"
       ,"Zn"
       ,"Zooot"
       ,"Qvwdrm"
       ,"Zooot"
       ,"Zn"
       ,"Zn"
       ,"Zooot"
       ,"Xillkfdvpfpxabqlngd"
       ,"Rskcw"
    };

    vector<string> sol_5 = {
         "Ampprswkdkobdagw"
        ,"Qvwdrm"
        ,"Rskcw"
        ,"Wcfa"
        ,"Wufeesrvn"
        ,"Xillkfdvpfpxabqlngd"
        ,"Zn"
        ,"Zooot"
    };
    check(sol_5,mostActive(input_5),5);

    vector<string> input_6 = {
        "Exouyfjhnwp"
        ,"Van"
        ,"Tanwwyoosxtnex"
        ,"Omkfnkswrawkjxw"
        ,"Zskzazjqtlkiqydpt"
        ,"Omkfnkswrawkjxw"
        ,"Van"
        ,"Sndpvannrywfrnrghlj"
        ,"Tanwwyoosxtnex"
        ,"Van"
        ,"Qpxnlkcwdpdksw"
        ,"Qpxnlkcwdpdksw"
        ,"Tanwwyoosxtnex"
        ,"Zskzazjqtlkiqydpt"
        ,"Sndpvannrywfrnrghlj"
        ,"Zskzazjqtlkiqydpt"
        ,"Tanwwyoosxtnex"
        ,"Sndpvannrywfrnrghlj"
        ,"Van"
        ,"Zskzazjqtlkiqydpt"
    };

    vector<string> sol_6 = {
        "Exouyfjhnwp"
        ,"Omkfnkswrawkjxw"
        ,"Qpxnlkcwdpdksw"
        ,"Sndpvannrywfrnrghlj"
        ,"Tanwwyoosxtnex"
        ,"Van"
        ,"Zskzazjqtlkiqydpt"
    };
    check(sol_6,mostActive(input_6),6);

    vector<string> input_7 =
    {
         "Ami"
        ,"Wuxavlwftgyxxhpygs"
        ,"Wk"
        ,"Vwfnbngh"
        ,"Wmzheqx"
        ,"Wuxavlwftgyxxhpygs"
        ,"Oxhaiafmvkb"
        ,"Wk"
        ,"Wuxavlwftgyxxhpygs"
        ,"Wmzheqx"
        ,"Vwfnbngh"
        ,"Vwfnbngh"
        ,"Wmzheqx"
        ,"Ocni"
        ,"Xjmornquma"
        ,"Wmzheqx"
        ,"Xjmornquma"
        ,"Ltpwmhqw"
        ,"Wk"
        ,"Ocni"
    };

    vector<string> sol_7 = {
        "Ami"
        ,"Ltpwmhqw"
        ,"Ocni"
        ,"Oxhaiafmvkb"
        ,"Vwfnbngh"
        ,"Wk"
        ,"Wmzheqx"
        ,"Wuxavlwftgyxxhpygs"
        ,"Xjmornquma"
    };

    check(sol_7,mostActive(input_7),7);
    return 0;
}
