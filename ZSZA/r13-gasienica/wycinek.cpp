#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
    int n, s, u, pierwszy, wynik;
    cin >> n >> s;

    vector<pair<int, int>> pref_s;
    vector<pair<int, int>> pref;
    cin >> u;
    pref_s.push_back(make_pair(u, 0));
    pierwszy = u;
    for (int i = 1; i < n; ++i)
    {
        cin >> u;
        pref_s.push_back(make_pair(u + pref_s[i - 1].first, i));
    }

    sort(pref_s.begin(), pref_s.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.first < b.first; });

    // usuwanie duplikatow i zostawianie tych z najwiekszym indeksem
    for (int i = 0; i < pref_s.size(); ++i)
    {
        while (i < pref_s.size() - 1 && pref_s[i].first == pref_s[i + 1].first)
        {
            i++;
        }
        pref.push_back(pref_s[i]);
    }

    vector<pair<pair<int, int>, pair<int, int>>> dobre;
    int poc = 0;
    for (int kon = 0; kon < pref.size(); ++kon)
    {
        while (poc < pref.size() && pref[poc].first - pref[kon].first <= s)
        {
            if (pref[poc].first - pref[kon].first == s)
            {
                dobre.push_back(make_pair(pref[kon], pref[poc]));
            }
            poc++;
        }
    }

    // int kon;
    // kon = pref.size() -1;
    // int sr;
    // for (int start = 0; start < pref.size(); ++start) {
    //     while (poc <= kon) {
    //         sr = (poc + kon)/2;
    //         if(pref[sr].first - pref[start].first >= s) {
    //             if(pref[sr].first - pref[start].first ==s)
    //                 dobre.push_back(make_pair(pref[start],pref[sr]));
    //             kon = sr - 1;
    //         }
    //         poc = sr + 1;
    //     }
    //     poc = 0;
    //     kon = pref.size() -1;
    // }

    wynik = 0;
    if (dobre.size() == 0)
    {
        if (s == pierwszy)
            cout << 1;
        else
            cout << "BRAK";
    }
    else
    {
        for (int i = 0; i < dobre.size(); ++i)
        {
            wynik = max(dobre[i].second.second - dobre[i].first.second, wynik);
        }
        cout << wynik;
    }
}