#include<iostream>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

vector <int> vec;
map < char , bool > check;
bool imp = 0;

int main(){
    int n, m, f, g;
    string s, t, r, sr;
    cin >> s >> t;
    r = s;
    reverse(r.begin() , r.end());
    for( int i = 0; i < s.size(); i++)
        check[s[i]] = 1;
    check['='] =1;
    t = t + '=';
    for( int i = 0; i < t.size() ; i++)
        {
            if( !check[t[i]])
                imp = 1;

            sr += t[i];
            if( s.find(sr) >= s.size() && r.find(sr) >= r.size())
                {

                    sr.resize(sr.size() - 1);
                    if( s.find(sr) < s.size())
                    {
                    vec.push_back(s.find(sr) + 1);
                    vec.push_back(s.find(sr) + sr.size());
                    }
                    else
                        {
                            vec.push_back(r.size() - r.find(sr));
                            vec.push_back(r.size() - r.find(sr)- sr.size() + 1);
                        }
                    sr = t[i];
                }
        }
    if( imp)
        {
            cout << -1; return 0;
        }
    cout << vec.size() / 2; cout << endl;
    for( int i = 0; i < vec.size(); i += 2)
        {
            cout << vec[i] << " " << vec[i + 1] << endl;
        }

}
