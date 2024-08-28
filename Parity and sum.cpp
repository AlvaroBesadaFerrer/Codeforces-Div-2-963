#include <bits/stdc++.h>

using namespace std;


int main()
{

    long long cp;
    cin>>cp;

    while(cp--)
    {
        long long n;
        long long res =0;
        cin>>n;
        vector<long long>v;
        long long mi = 0;
        long long par =0;

        for (long long i = 0 ; i < n ; i ++)
        {
            long long a;
            cin>>a;
            v.push_back(a);
            if (a % 2 == 1)
            {
                mi = max(mi, a);
            }
            else
            {
                par +=1;
            }
        }

        if(mi ==0 or par ==0)
        {
            cout<<0<<"\n";
        }
        else
        {

            sort(v.begin(), v.end());


            for (long long i = 0 ; i < n ; i ++)
            {
                long long a = v[i];
                if(a % 2 == 0)
                {
                    if(mi< a)
                    {
                        res+=1;
                        mi += v[n-1];
                    }
                    res += 1;
                    mi += a;
                }
            }
            cout<<res<<"\n";
        }
    }
}
