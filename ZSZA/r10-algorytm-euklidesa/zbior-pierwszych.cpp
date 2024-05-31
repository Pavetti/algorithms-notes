#include <iostream>

using namespace std;

int nwd(int a, int b);

int main()
{

    int z, a, b, nwd_var;
    cin >> z;
    bool wyniki[z];
    for (int i = 0; i < z; i++)
    {
        cin >> a >> b;
        do
        {
            nwd_var = nwd(a, b);
            a /= nwd_var;
        } while (nwd_var != 1);
        wyniki[i] = (a == 1);
    }

    for (int i = 0; i < z; i++)
    {
        if (wyniki[i])
            cout << "TAK" << endl;
        else
            cout << "NIE" << endl;
    }
}

int nwd(int a, int b)
{
    if (a % b == 0)
        return b;
    return nwd(b, a % b);
}