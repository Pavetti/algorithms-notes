#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    int n;
    cin >> n;
    unordered_map<int, pair<int, int>> bracia;
    int queue[n] = {0};
    int q = 0;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    for (int i = n - 1; i >= 0; --i)
    {
        if (bracia.find(a[i]) == bracia.end())
        {
            bracia[a[i]] = make_pair(i, i);
            queue[q] = a[i];
            q++;
        }
        else
            bracia[a[i]].first = i;
    }

    int wynik = 1;
    int q_ind = q - 1;
    int end_last = bracia[queue[q_ind]].second;
    for (int i = q_ind; i >= 0; --i)
    {
        if (end_last < bracia[queue[i]].first)
        {
            wynik++;
            end_last = bracia[queue[i]].second;
        }
    }

    cout << wynik;
}