#include <bits/stdc++.h>
#include<chrono>
#include <unordered_map>
using namespace std;

int mWR(int wt[], int val[], int K,
                  map<pair<int, int>, int>& mp,
                            int last, int diff)
{
   
    if (last == -1)
    {
        if (diff == 0)
            return 0;
        else
            return INT_MIN;
    }
 
   
    pair<int, int> tmp = make_pair(last, diff);
    if (mp.find(tmp) != mp.end()) {
         return mp[tmp];
    }
       
    
    
    mp[tmp] = max(mWR(wt, val, K, mp, last - 1, diff),
                   wt[last] + mWR(wt, val, K, mp,
                   last - 1, diff + wt[last] - val[last] * K));
    return mp[tmp];
}
 

int mW(int wt[], int val[], int K, int N)
{
    map<pair<int, int>, int> mp;
    return mWR(wt, val, K, mp, N - 1, 0);
}
 

int main()
{
    
    int N ,  wt[10],val[10],K;
    cout << "Enter number of objects: ";
    cin >> N;

    cout << "Enter the max ratio: ";
    cin >> K;

    cout << "Enter first weight and then value " << endl;

    for (int i = 0; i < N; i++)
    {
        cin >> wt[i] >> val[i];
    }
    
    auto start = std::chrono::high_resolution_clock::now();
    int k = mW(wt, val, K, N); 
    
    cout << k;
    auto end = std::chrono::high_resolution_clock::now();
    double elapsed_time = double(std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count());
    std::cout<< "Elapsed Time "<< elapsed_time/1e5  << " ns "<<endl;
    
    return 0;                                                                                                    
}
