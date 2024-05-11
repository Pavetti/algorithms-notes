#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <windows.h>
#include <cmath>

using namespace std;


void bouble_sort(int *tab, int n);
void print_tab(int *tab, int n);
void quick_sort(int *tab, int left, int right);
void main_1();
void main_2();
void przyciski();
void przyciski_ksiazka();
void chomiki();
void gwozdzie();
void ryby();
void cukiernia();
void dwie_czesci();
void flaga_bajtocka();
void lider_prefixsowy();


int amout;
float period;
clock_t start,stop;



int main() {
    lider_prefixsowy();

    return 0;
}

void lider_prefixsowy() {
    int n;
    cin >> n;
    int krotnosc = 0;
    int wartosc = 0;
    int liderzy[n];

    int number;
    for (int i = 0; i < n; ++i) {
        cin >> number;

        if(krotnosc == 0) {
            krotnosc = 1;
            wartosc = number;
        }
        else {
            if(wartosc == number) {
                krotnosc++;
            }else krotnosc--;
        }

        if(krotnosc > 0) {
            liderzy[i] = wartosc;
        }else {
            liderzy[i] = INT_MAX;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << liderzy[i] << endl;
    }
}

void flaga_bajtocka() {
    int n;
    cin >> n;

    int pierwszy,drugi;
    if(n % 2 == 0) {
        pierwszy = n/2;
        drugi = pierwszy;
    }
    else {
        pierwszy = n/2 +1;
        drugi = n/2;
    }
    int zliczacz_1[n] = {0};
    int zliczacz_2[n] = {0};
    int first[pierwszy];
    int second[drugi];
    int licznik_1 = 0;
    int licznik_2 = 0;
    for (int i = 0; i < n; ++i) {
        if(i % 2 == 0) {
            cin >> first[licznik_1];
            licznik_1++;
        }else {
            cin >> second[licznik_2];
            licznik_2++;
        }
    }
    for (int i = 0; i < pierwszy; ++i) {
        zliczacz_1[first[i]]++;
    }
    for (int i = 0; i < drugi; ++i) {
        zliczacz_2[second[i]]++;
    }

    int max_1[2][2] = {{0,0},{0,0}};
    int max_2[2][2] = {{0,0},{0,0}};
    int pomocnik[2]={0};
    for (int i = 0; i < n; ++i) {
        if(max_1[1][1] < zliczacz_1[i]) {
            max_1[1][1] = zliczacz_1[i];
            max_1[1][0] = i;
        }
        if(max_1[0][1] < max_1[1][1]) {
            pomocnik[0] = max_1[0][0];
            pomocnik[1] = max_1[0][1];

            max_1[0][1] = max_1[1][1];
            max_1[0][0] = max_1[1][0];

            max_1[1][1] = pomocnik[1];
            max_1[1][0] = pomocnik[0];
        }


        if(max_2[1][1] < zliczacz_2[i]) {
            max_2[1][1] = zliczacz_2[i];
            max_2[1][0] = i;
        }
        if(max_2[0][1] < max_2[1][1]) {
            pomocnik[0] = max_2[0][0];
            pomocnik[1] = max_2[0][1];

            max_2[0][1] = max_2[1][1];
            max_2[0][0] = max_2[1][0];

            max_2[1][1] = pomocnik[1];
            max_2[1][0] = pomocnik[0];
        }
    }


    int wynik = 0;
    int p = 0;
    if(max_1[0][0] != max_2[0][0]) {
        wynik += pierwszy-max_1[0][1];
        wynik += drugi-max_2[0][1];
    }
    else {
        wynik += pierwszy-max_1[0][1];
        wynik += pierwszy-max_2[1][1];

        p += pierwszy-max_1[1][1];
        p += pierwszy-max_2[0][1];
        wynik = min(wynik,p);
    }

    cout << wynik;






    // for (int i = 0; i < n; ++i) {
    //     max_1[1] = max(zliczacz_1[i],max_1[1]);
    //     if(max_1[1] > max_1[0]) {
    //         pomocnik = max_1[0];
    //         max_1[0] = max_1[1];
    //         max_1[1] = pomocnik;
    //     }
    //
    //     max_2[1] = max(zliczacz_2[i],max_2[1]);
    //     if(max_2[1] > max_2[0]) {
    //         pomocnik = max_2[0];
    //         max_2[0] = max_2[1];
    //         max_2[1] = pomocnik;
    //     }
    // }






}


void dwie_czesci() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int ile = 0;
    int wartosc = 0;
    int wynik = 0;
    for (int i = 0; i < n; ++i) {
        if(ile == 0) {
            ile = 1;
            wartosc = a[i];
        }
        else {
            if(wartosc == a[i]) ile++;
            else ile--;
        }
    }
    if(ile > 0) {
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if(a[i] == wartosc) {
                count++;
            }
        }
        if( count > n/2) {
            int prefixes[n-1];
            int sufixes[n-1];
            int prefsum = 0;
            int sufsum = 0;
            // prefix
            for (int i = 0; i < n-1; ++i) {
                if(a[i] == wartosc) {
                    prefsum++;
                }
                prefixes[i] = prefsum;
            }
            // sufixes
            for (int i = n-1; i > 0; --i) {
                if(a[i] == wartosc) {
                   sufsum++;
                }
                sufixes[i-1] = sufsum;
            }
            for (int i = 0; i < n-1; ++i) {
                if(prefixes[i] > (i+1)/2
                    && sufixes[i] > (n - (i+1))/2 ) {
                    wynik++;
                }
            }
        }
    }else {
        cout << 0;
    }

    cout << wynik;


}




void cukiernia() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int os = a[n-1];

    int stos[n][2];
    int rozmiar = 1;
    stos[0][0] = a[n-1];
    stos[0][1] = n;

    int wynik = 0;
    int miejsce = 0;

    for (int i = n-2; i >= 0; --i) {
        if(a[i] < os) {
            os = a[i];
            stos[rozmiar][0] = os;
            stos[rozmiar][1] = i+1;
            rozmiar++;
        }
    }
    int cena;
    int pozycja;
    int rozmiar_true = rozmiar;
    for (int i = 0; i < rozmiar_true; ++i) {
        cena = stos[rozmiar-1][0];
        pozycja = stos[rozmiar-1][1];
        rozmiar--;

        wynik += (pozycja - miejsce)*cena;
        miejsce =pozycja;
    }

    cout << wynik;
}

void ryby() {
    int n;
    int wynik = 0;
    bool zjedzona = false;
    cin >> n;
    int ryby[n];
    int kierunek[n];
    int stos[n+1] = {0};
    int rozmiar = 0;

    for (int i = 0; i < n; ++i) {
        cin >> ryby[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> kierunek[i];
    }

    for (int i = 0; i < n; ++i) {
        if(kierunek[i] == 1) {
            stos[rozmiar] = ryby[i];
            rozmiar++;
        }
        else {
            while(rozmiar > 0) {
                if(ryby[i] > stos[rozmiar-1]) {
                    rozmiar--;
                }
                else {
                    zjedzona = true;
                    break;
                }
            }
            if(!zjedzona) wynik++;
            zjedzona = false;
        }
    }
    wynik += rozmiar;
    cout << wynik;
}

void gwozdzie() {
    int n,k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a,a+n);
    int maksimum = 0;
    int ile = 0;
    int wynik;
    for (int i = 0; i < n-k-1; ++i) {
        if(a[i] == a[i + 1])
            ile ++;
        else
            ile = 0;
        maksimum = max(maksimum, ile);
    }
    wynik = min(n,maksimum + k +1);
    cout << wynik;
}
void chomiki() {
    int n,m;
    cin >> n >> m;
    int c[n] = {0};
    int p[5+1][n+1] = {{0},{0},{0},{0},{0},{0}};

    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    for (int i = 1; i <= 5; ++i) {
        for (int k = 1; k <= n; ++k) {
            if(c[k-1] == i) {
                p[i][k] = p[i][k-1] + 1;
            }
            else {
                p[i][k] = p[i][k-1];
            }
        }
    }
    int a,b;
    int wyniki[m];
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        a--;
        for (int w = 1; w <= 5; ++w) {
            if(p[w][b] - p[w][a] > 0) {
                wyniki[i] = w;
                break;
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        cout << wyniki[i] << endl;
    }
}

void przyciski() {
    int n,m;
    cin >> n >> m;
    int a[m];
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }

    int naj = 0;
    int zlicz[n + 1] = {0};
    int toSet = 0;
    for (int i = 0; i < m; ++i) {
        if(a[i] == n+1) {
            toSet += naj;
            naj = 0;
            for (int i = 0; i < n+1; ++i) {
                zlicz[i] = 0;
            }
            continue;
        }

        zlicz[a[i]]++;
        if(zlicz[a[i]] > naj) naj = zlicz[a[i]];
    }
    for (int i = 1; i < n+1; ++i) {
        zlicz[i] = zlicz[i] + toSet;
    }


    // Print

    for (int i = 1; i < n+1; ++i) {
        cout << zlicz[i] << " ";
    }

}

void przyciski_ksiazka() {
    int n,m;
    cin >> n >> m;
    int p[m];
    for (int i = 0; i < m; ++i) {
        cin >> p[i];
    }

    int licznik[n+1] = {0};
    int minimum = 0;
    int maksimum = 0;
    for (int i = 0; i < m; ++i) {
        if(p[i] == n + 1) {
            minimum = maksimum;
        }
        else {
            licznik[p[i]] = max(minimum,licznik[p[i]]) + 1;
            maksimum = max(maksimum, licznik[p[i]]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        licznik[i] = max(minimum, licznik[i]);
    }


    for (int i = 1; i <= n; ++i) {
        cout << licznik[i] << " ";
    }
}


void main_2() {
    int n;
    cin >> n;
    int tab[5] = {3,1,2,4,3};

    int s;
    int l;
    int p;
    for (int i = 0; i < n; ++i) {
        s += tab[i];
    }
    int najminejsza = s -tab[0];
    for (int i = 0; i < n; ++i) {
        l += tab[i];
        p = s-l;
        if(abs(l-p) < najminejsza) {
            najminejsza = abs(l-p);
        }
    }
    cout << najminejsza;

}


void main_1() {
    cout << "Ile elemntow? " << endl;
    cin >> amout;

    int *tab;
    int *tab2;
    tab = new int [amout];
    tab2 = new int [amout];

    // losowe wartosci dla tablicy
    srand(time(NULL));
    int r;
    for (int i = 0; i < amout; ++i) {
        r = rand()%1000 + 1;
        tab[i] =r;
        tab2[i] = r;
    }
    print_tab(tab2, amout);

    // start = clock();
    // bouble_sort(tab, amout);
    // stop = clock();
    // period = (float) (stop - start) / CLOCKS_PER_SEC;
    // //print_tab(tab, amout);
    // cout << "Czas sortowania bombelkowego: " << period << " sekund" << endl;


    start = clock();
    quick_sort(tab2, 0,amout-1);
    stop = clock();
    period = (float) (stop - start) / CLOCKS_PER_SEC;
    print_tab(tab2, amout);
    cout << "Czas sortowania szybkiego: " << period << " sekund" << endl;

    delete [] tab;
    delete [] tab2;
}

void bouble_sort(int *tab, int n) {
    for (int i = 0; i < n; ++i) {

        for (int j = 1; j < n; ++j) {
            int bufor; bufor = tab[j];
            if(bufor < tab[j-1]) {
                tab[j] = tab[j-1];
                tab[j-1]  = bufor;
            }
        }
    }
}

void quick_sort(int *tablica, int lewy, int prawy)
{

    int v=tablica[(lewy+prawy)/2];
    int i,j,x;
    i=lewy;
    j=prawy;
    do{
        while (tablica[i]<v) i++;
        while (tablica[j]>v) j--;
        if (i<=j){
            x=tablica[i];
            tablica[i]=tablica[j];
            tablica[j]=x;
            i++; j--;
        }
    }while (i<=j);
    if (j>lewy) quick_sort(tablica,lewy, j);
    if (i<prawy) quick_sort(tablica, i, prawy);
}

void print_tab(int *tab, int n) {
    for (int i = 0; i < n; ++i) {
        cout << tab[i] << " ";
    }
    cout << endl << endl;
}







