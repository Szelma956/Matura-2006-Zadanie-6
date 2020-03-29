

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;
string reverse(string napis) {
    string s = "";
    for (int n = napis.length() - 1; n >= 0; n--) {
        char znak = napis[n];
        s = s + znak;
    }
    return s;

}
bool czy_parzysta(char znak) {
    if (znak == 'A')
        return true;
    else if (znak == 'C')
        return true;
    else if (znak == 'E')
        return true;
    return false;
}

int main()
{
    ifstream dane("dane.txt");
    ofstream wynik("wynik.txt");
    vector<string> slowa;
    set<string> wieloslowa;
    int l_slow = 0;
    string naj_slowo = "";
    int pow_slow = 0;
    int l_parz = 0;
    int l_pal = 0;
    for (int licznik = 0; !dane.eof() ; licznik++) {
        string linia;
        dane >> linia;
        if (!linia.empty()) 
            slowa.push_back(linia);
    }
    for (int i = 0; i < slowa.size(); i++) {
        string analiz_slowo = slowa[i];

        if (wieloslowa.count(analiz_slowo) == 0) {
            int licznik = 0;
            for (int j = 0; j < slowa.size(); j++) {
                if (analiz_slowo == slowa[j])
                    licznik++;
            }
            if (licznik > 1) {
                wieloslowa.insert(analiz_slowo);
                if (licznik > pow_slow) {
                    pow_slow = licznik;
                    naj_slowo = analiz_slowo;
                }
            }

        }
        

        if (analiz_slowo.length() > 0) {
            char ost_znak = analiz_slowo[analiz_slowo.length()-1];
            if (czy_parzysta(ost_znak))
                l_parz++;
        }


        if (analiz_slowo == reverse(analiz_slowo))
            l_pal++;
    }
    l_slow = wieloslowa.size();
    wynik << "Odpowiedzi do podpunktu a)\n" << "Liczba slow wystepujacych wiecej niz jeden raz:" << ' ' << l_slow << '\n' << "Slowo o najwiekszej liczbie wystapien to:" << ' ' << naj_slowo << '\n' << "Liczba jego wystapien jest rowna:" << ' ' << pow_slow << '\n' << '\n';
    wynik << "Odpowiedz do podpunktu b)\n" << "Liczb parzystych jest:" << l_parz << '\n' << '\n';
    wynik << "Odpowiedz do podpunktu c)\n" << "Liczba palindromow w pliku:" << l_pal << '\n' << '\n';
    return 0;
}
