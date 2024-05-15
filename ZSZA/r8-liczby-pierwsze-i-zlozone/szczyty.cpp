#include <iostream>

using namespace std;

int n;

int main()
{
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int wynik = 0;
    for (int i = 1; i * i < n; i++)
    {
        if (n % i == 0)
        {
            int a = i;
            int b = n / i;
            bool final_a = true;
            bool final_b = true;
            bool zgodnosc_a = false;
            bool zgodnosc_b = false;
            for (int t = 1; t < n - 1; t++)
            {
                if (a[t] > a[t - 1] && a[t] > a[t + 1])
                {
                    zgodnosc_a = true;
                    zgodnosc_b = true;
                    i++;
                }
                if (a % (t + 1) == 0 && zgodnosc_a == false)
                {
                    final_a = false;
                    break;
                }
                else
                {
                    zgodnosc_a = false;
                }
                if (b % (t + 1) == 0 && zgodnosc_b == false)
                {
                    final_b = false;
                    break;
                }
                else
                {
                    zgodnosc_b = false;
                }
            }
        }
    }
}