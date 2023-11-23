#include <bits/stdc++.h>
#include <iomanip>
#define ll long long int
using namespace std;
ll mod = (ll)(1e9 + 7);
void solve()
{
    ll n;
    cin >> n;
    stack<ll> s;
    string st, prev;
    for (int i = 0; i < n; ++i)
    {
        ll a;
        cin >> a;
        if (s.empty())
        {
            s.push(a);
            st += to_string(a);
            cout << st << endl;
            prev = st;
            st += '.';
        }
        else if (a == 1)
        {
            s.push(a);
            st.push_back('1');
            cout << st << endl;
            st.push_back('.');
        }
        else
        {
            if (a != (s.top() + 1))
            {
                /*
                if (a == s.top() + 1)
                {
                    ll sz = s.top();
                    s.pop();
                    string lk = to_string(sz);
                    sz = lk.size();

                    while (sz != 0)
                    {
                        st.pop_back();
                        --sz;
                    }

                    st.pop_back();
                    st += to_string(a);
                    s.push(a);
                    cout << st << endl;
                    prev = st;
                    st += '.';
                }
                else
                {*/
                while (a != (s.top() + 1))
                {
                    ll sz = s.top();
                    s.pop();
                    st.pop_back();

                    string lk = to_string(sz);
                    sz = lk.size();

                    while (sz != 0)
                    {
                        st.pop_back();
                        --sz;
                    }
                }

                ll sz = s.top();
                s.pop();
                st.pop_back();

                string lk = to_string(sz);
                sz = lk.size();

                while (sz != 0)
                {
                    st.pop_back();
                    --sz;
                }

                s.push(a);
                st += to_string(a);
                cout << st << endl;
                st += '.';
                // }
            }
            /*
            else if (a == s.top() and a != 1)
            {

                while ((s.top() + 1) != a)
                {
                    s.pop();

                    ll sz = s.top();
                    s.pop();

                    string lk = to_string(sz);
                    sz = lk.size();

                    while (sz != 0)
                    {
                        st.pop_back();
                        --sz;
                    }

                    st.pop_back();
                }

                st.pop_back();
                st.pop_back();
                s.pop();

                st += to_string(a);
                s.push(a);
                cout << st << endl;
                st += '.';
                prev = st;
            }*/
            else
            {
                // cout << st << endl;
                ll sz = s.top();
                s.pop();
                st.pop_back();

                string lk = to_string(sz);
                sz = lk.size();
                // cout << sz << endl;
                while (sz != 0)
                {
                    st.pop_back();
                    --sz;
                }

                s.push(a);
                st += to_string(a);

                /*
                s.push(a);
                */
                cout << st << endl;
                prev = st;
                st += '.';
            }
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    // solve();
    return 0;
}