#pragma once
#include <cstdint>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string_view>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
using namespace std;
struct Naglowek
{
    short Typ;
    int Rozmiar;
    short Rezerwacja1;
    short Rezerwacja2;
    int bfOffBits;
} Plik;
struct NaglowekObrazu
{
    int Birozmiar;
    int Biszerokosc;
    int Biwysokosc;
    short biPlanes;
    short BIlicznikbitow;
    int Bikompresja;
    int Birozmiarobrazu;
    int biXPelsPerMeter;
    int biYPelsPerMeter;
    int biClrUsed;
    int biClrImportant;
} Obraz;
struct KoloryRGB
{
    char R;
    char G;
    char B;
} Rgb;
int main(int arc, char* argv[])
{
    Plik* p = fopen(argv[1], "rb");
    if (p == nullptr)
    {
        cout << "\n\n Nie mozna otworzyc pliku" << endl;
        return -1;
    }
    else
    {
        cout << "\n\n Plik otwarty!" << endl;
    }
    cout << "\n INFORMACJE \n\n" << endl;
    fread(&Plik.Typ, sizeof(Plik.Typ), 1, p);
    cout << " Typ: %x" << Plik.Typ << endl;
    fread(&Plik.Rozmiar, sizeof(Plik.Rozmiar), 1, p);
    cout << "\n Rozmiar pliku: %d bajtow" << Plik.Rozmiar << endl;
    fread(&Plik.Rezerwacja1, sizeof(Plik.Rezerwacja1), 1, p);
    cout << "\n Zarezerwowane1: %d" << Plik.Rezerwacja1 << endl;
    fread(&Plik.Rezerwacja2, sizeof(Plik.Rezerwacja2), 1, p);
    cout << "\n Zarezerwowane2: %d" << Plik.Rezerwacja2 << endl;
    fread(&Plik.bfOffBits, sizeof(Plik.bfOffBits), 1, p);
    cout << "\n Pozycja danych obrazkowych: %d" << Plik.bfOffBits << endl;
    cout << "\n" << endl;
    fseek(p, 14, SEEK_SET);
    fread(&Obraz.Birozmiar, sizeof(Obraz.Birozmiar), 1, p);
    cout << "\n Wielkosc naglowka informacyjnego: %d" << Obraz.Birozmiar << endl;
    fread(&Obraz.Biszerokosc, sizeof(Obraz.Biszerokosc), 1, p);
    cout << "\n Szerokosc: %d pikseli" << Obraz.Biszerokosc << endl;
    fread(&Obraz.Biwysokosc, sizeof(Obraz.Biwysokosc), 1, p);
    cout << "\n Wysokosc: %d pikseli" << Obraz.Biwysokosc << endl;
    fread(&Obraz.biPlanes, sizeof(Obraz.biPlanes), 1, p);
    cout << "\n Liczba platow: %d" << Obraz.biPlanes << endl;
    fread(&Obraz.BIlicznikbitow, sizeof(Obraz.BIlicznikbitow), 1, p);
    cout << "\n Liczba bitow na piksel: %d (1, 4, 8, or 24)" << Obraz.BIlicznikbitow << endl;
    fread(&Obraz.Bikompresja, sizeof(Obraz.Bikompresja), 1, p);
    cout << "\n Kompresja: %d (0=none, 1=RLE-8, 2=RLE-4)" << Obraz.Bikompresja << endl;
    fread(&Obraz.Birozmiarobrazu, sizeof(Obraz.Birozmiarobrazu), 1, p);
    cout << "\n Rozmiar samego rysunku: %d" << Obraz.Birozmiarobrazu << endl;
    fread(&Obraz.biXPelsPerMeter, sizeof(Obraz.biXPelsPerMeter), 1, p);
    cout << "\n Rozdzielczosc pozioma: %d" << Obraz.biXPelsPerMeter << endl;
    fread(&Obraz.biYPelsPerMeter, sizeof(Obraz.biYPelsPerMeter), 1, p);
    cout << "\n Rozdzielczosc pionowa: %d" << Obraz.biYPelsPerMeter << endl;
    fread(&Obraz.biClrUsed, sizeof(Obraz.biClrUsed), 1, p);
    cout << "\n Liczba kolorow w palecie: %d" << Obraz.biClrUsed << endl;
    fread(&Obraz.biClrImportant, sizeof(Obraz.biClrImportant), 1, p);
    cout << "\n Wazne kolory w palecie: %d" << Obraz.biClrImportant << endl;
    Plik* n = fopen("negative.bmp", "wb");
    if (n == nullptr)
    {
        cout << "\n\n Nie mozna otowrzyc pliku" << endl;
        return -1;
    }
    else
    {
        cout << "\n\nPlik otwarty" << endl;
    }
    fseek(n, 0, SEEK_SET);
    fwrite(&Plik.Typ, sizeof(Plik.Typ), 1, n);
    fwrite(&Plik.Rozmiar, sizeof(Plik.Rozmiar), 1, n);
    fwrite(&Plik.Rezerwacja1, sizeof(Plik.Rezerwacja1), 1, n);
    fwrite(&Plik.Rezerwacja2, sizeof(v.Rezerwacja2), 1, n);
    fwrite(&Plik.bfOffBits, sizeof(Plik.bfOffBits), 1, n);
    fseek(n, 14, SEEK_SET);
    fwrite(&Obraz.Birozmiar, sizeof(Obraz.Birozmiar), 1, n);
    fwrite(&Obraz.Biszerokosc, sizeof(Obraz.Biszerokosc), 1, n);
    fwrite(&Obraz.Biwysokosc, sizeof(Obraz.Biwysokosc), 1, n);
    fwrite(&Obraz.biPlanes, sizeof(Obraz.biPlanes), 1, n);
    fwrite(&Obraz.BIlicznikbitow, sizeof(Obraz.BIlicznikbitow), 1, n);
    fwrite(&Obraz.Bikompresja, sizeof(Obraz.Bikompresja), 1, n);
    fwrite(&Obraz.Birozmiarobrazu, sizeof(Obraz.Birozmiarobrazu), 1, n);
    fwrite(&Obraz.biXPelsPerMeter, sizeof(Obraz.biXPelsPerMeter), 1, n);
    fwrite(&Obraz.biYPelsPerMeter, sizeof(Obraz.biYPelsPerMeter), 1, n);
    fwrite(&Obraz.biClrUsed, sizeof(Obraz.biClrUsed), 1, n);
    fwrite(&Obraz.biClrImportant, sizeof(Obraz.biClrImportant), 1, n);
    fseek(n, sizeof(Plik.bfOffBits), SEEK_SET);
    int bmpImg;
    for (int i = Plik.bfOffBits; i < Plik.Rozmiar; i++)
    {
        fseek(p, i, SEEK_SET);
        fseek(n, i, SEEK_SET);
        fread(&bmpImg, 3, 1, p);
        bmpImg = INT_MAX - bmpImg;
        fwrite(&bmpImg, 3, 1, n);
    }
    cout << "\n" << endl;
    fclose(p);
    fclose(n);
    return 0;
}
