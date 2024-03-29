#include <bits/stdc++.h>

/*
 * Complete the 'longestSubarray' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */


int longestSubarray(std::vector<int> arr) {
    int n = arr.size();
    int ans = 0;

    for(size_t i = 0; i < n; i++)
    {
        std::vector<int> w;
        int cnt = 0;

        for(size_t j = i; j < n; j++)
        {
            auto it = std::find_if(w.begin(),w.end(),[&arr,j](const int val){return arr[j] == val;});

            if(it != w.end())
            {
                cnt++;
                continue;
            }

            if(w.size() == 0)
                w.push_back(arr[j]);
            else if(w.size() == 1)
            {
                if(std::abs(w[0] - arr[j]) > 1)
                    break;
                else
                    w.push_back(arr[j]);
            }
            else
                break;

            cnt++;
        }

        ans = std::max(ans,cnt);
    }

    return ans;
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
    std::vector<int> input_ex = {0, 1, 2, 1, 2, 3};
    check(longestSubarray(input_ex),4,-1);

    std::vector<int> input_0 = {1, 2 ,3, 4, 5};
    check(longestSubarray(input_0),2,0);

    std::vector<int> input_1 = {2, 2, 1};
    check(longestSubarray(input_1),3,1);

    std::vector<int> input_2 = {295331535};
    check(longestSubarray(input_2),1,2);

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
    check(longestSubarray(input_3),31,3);

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


