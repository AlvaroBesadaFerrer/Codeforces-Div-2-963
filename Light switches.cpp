#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll cp;
    cin>>cp;



    while(cp--)
    {
        ll n,k;
        cin>> n>>k;
        vector<ll>v;
        vector<ll>paridad;
        ll res = -2;
        paridad.push_back(0);

        for (ll i = 0 ; i < n ; i++)
        {

            ll a;
            cin>>a;
            v.push_back(a);
            paridad.push_back(-1);

        }
        sort(v.begin(), v.end());

        ll lim = v[n-1];
        ll imparmasalto = -1;

        for (ll i = 0 ; i < n ; i++)
        {
            ll resto = (lim - v[i])%k;
            ll cabe = (lim - v[i])/k;


            if (paridad[resto] == -1)
            {

                paridad[resto] = cabe%2;
                //cout<<"tes"<<resto<<"\n";

            }
            else if (paridad[resto] != cabe%2)
            {
                res = -1;
                break;
            }
            if (cabe%2==1)
            {
                imparmasalto = max(imparmasalto, k*cabe+v[i]);
            }

        }

        bool parito = false;
        for (ll i = n-1 ; i >=0  ; i--)
        {
            if (paridad[i] == -1){
            }
            else if (paridad[i] == 0){
                parito =true;
            }
            else if(parito == true){
                res = -1;
            }

        }


        if(res == -1)
        {
            cout<<-1<<"\n";
        }
        else if (imparmasalto == -1)
        {
            cout<<lim<<"\n";
        }
        else
        {
            cout<<imparmasalto+k<<"\n";
        }

    }

}
