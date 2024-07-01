#include <iostream>

using namespace std;
bool czyBST(int id, int lewy, int prawy);

int n = 7;
int w[8] = {-1, 8, 3, 15, 1, 5, 10, 16};

int main()
{
    bool chuj = czyBST(1, 1, 1000 * 1000 * 1000);
    cout << chuj;
}

bool czyBST(int id, int lewy, int prawy)
{
    if (id > n)
        return true;
    if (w[id] < lewy || w[id] > prawy)
        return false;

    bool l = czyBST(id * 2, lewy, w[id] - 1);
    bool p = czyBST(id * 2 + 1, w[id] + 1, prawy);

    return l && p;
}
