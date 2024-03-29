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

long nearlySimilarRectangles(vector<vector<long>> sides)
{

    long long ans = 0;
    unordered_map<double, int> umap;

    for(const auto& s : sides)
    {
        const double ratio = static_cast<double>(s[0]) / static_cast<double>(s[1]);
        umap[ratio]++;
    }

    for (auto x : umap)
    {
         long long value = x.second;
         if (value > 1)
             ans += (value * (value - 1)) / 2;

    }

    return ans;
}

int main()
{
    std::vector<std::vector<long>> test0 = {{4,8},{15,30},{25,50}};
    long solution0 = 3;
    long mySolution0 = nearlySimilarRectangles(test0);
    assert(mySolution0==solution0);
    std::vector<std::vector<long>> test1 = {{2,1},{10,7},{9,5},{6,9},{7,3}};
    long solution1 = 0;
    long mySolution1 = nearlySimilarRectangles(test1);
    assert(mySolution1==solution1);
    std::vector<std::vector<long>> test2 =
    {
         {50343660338874, 151674376851272}
        ,{17380748052304, 202358760116149}
        ,{46480281687392, 25483816413016}
        ,{36384888524397, 37411888334759}
        ,{447400504650672, 39227860950813}
        ,{334122710765000, 69685924094200}
        ,{286466146302633, 58502255621931  }
        ,{6923316051289, 152117246040637}
        ,{124162617608992, 275728209306662}
        ,{846888356422485, 377360748015498 }
        ,{182084998750327, 107160714457594}
        ,{43636212924612 ,69170102351504}
        ,{139636192789590, 420693139606520}
        ,{97194876061220 ,165151277459510}
        ,{5045805125788 ,3787333389840}
        ,{628580839768761 ,42175407711426}
        ,{87623457806724 ,138896644293008}
        ,{829508273534048, 23138655640576}
        ,{214703156370006 ,232353980177609}
        ,{31841022204900 ,121494800049750}
        ,{920237639158670 ,768263855749040}
        ,{316943877171600 ,129310596027060}
        ,{334836841191048 ,568946988814284}
        ,{9924825631940 ,47586505985500}
        ,{201657281968770, 24277416396150}
        ,{6464137740060 ,8612069756017}
        ,{34351843353688 ,58369854902404}
        ,{254290190373219, 66450849332829}
        ,{89826752919074 ,243703930035265}
        ,{258053291469636, 470666931650832}
        ,{85314149275880 ,38014705176784}
        ,{29254556050000 ,119195261678250}
        ,{99859438504296 ,137668439387259}
        ,{370334553078876, 217949394890472}
        ,{265828943966971, 258360936484980}
        ,{556612088360160, 659918702651944}
        ,{44655881500152 ,53030626678952}
        ,{367561607582736, 165515931230976}
        ,{648035507932848, 56819441489517}
        ,{273232927014789, 256876906515668}
        ,{323013416853402, 120619624159914}
        ,{222829891310042, 850245099406855}
        ,{8407667061101 ,6310715019180}
        ,{737207414095680 ,300774796355088}
        ,{191382154539084 ,166795717688792}
    };
    long solution2 = 11;
    long mySolution2 = nearlySimilarRectangles(test2);
    assert(mySolution2==solution2);
    std::cout<<"All tests passed"<<std::endl;
    return 0;
}
