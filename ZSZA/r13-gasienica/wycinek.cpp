#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
    int n, s;
    cin >> n >> s;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    vector<pair<int, int>> pref;
    pref.push_back(make_pair(a[0], 0));
    for (int i = 1; i < n; ++i)
    {
        pref.push_back(make_pair(a[i] + pref[i - 1].first, i));
    }
    sort(pref.begin(), pref.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.first < b.first; });

    int poc = 0;
    vector<pair<pair<int, int>, pair<int, int>>> dobre;
    for (int kon = 0; kon < n; ++kon)
    {
        while (poc < n && pref[poc].first - pref[kon].first <= s)
        {
            if (pref[poc].first - pref[kon].first == s)
            {
                if (dobre.size() >= 1 && dobre[dobre.size() - 1].second.first == pref[poc].first)
                {
                    dobre[dobre.size() - 1] = make_pair(pref[kon], pref[poc]);
                }
                else
                {
                    dobre.push_back(make_pair(pref[kon], pref[poc]));
                }
            }
            poc++;
        }
    }
    // jesli wycinek bedzie rowny 1 a liczba jest pierwsza to wyswietla BRAK
    //
    // 6 4
    // 4 -2 5 24 53 532

    // for (int i = 0; i < dobre.size(); ++i) {
    //     cout << "kon: " << dobre[i].first.first << " | " << dobre[i].first.second << endl
    //     << "poc: " << dobre[i].second.first << " | " << dobre[i].second.second << endl << "---------------------" << endl;
    // }

    int wynik = 0;
    if (dobre.size() == 0)
    {
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