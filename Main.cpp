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
    int biSize;
    int biWidth;
    int biHeight;
    short biPlanes;
    short biBitCount;
    int biCompression;
    int biSizeImage;
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
int main(int arc, char * argv[]) 
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
    cout << "\n Rozmiar pliku: %d bajtow" << File.Rozmiar << endl;
    fread(&Plik.Rezerwacja1, sizeof(Plik.Rezerwacja1), 1, p);
    cout << "\n Zarezerwowane1: %d" << Plik.Rezerwacja1 << endl;
    fread(&Plik.Rezerwacja2, sizeof(Plik.Rezerwacja2), 1, p);
    cout << "\n Zarezerwowane2: %d" <<  Plik.Rezerwacja2 << endl;
    fread(&Plik.bfOffBits, sizeof(Plik.bfOffBits), 1, p);
    cout << "\n Pozycja danych obrazkowych: %d" << Plik.bfOffBits << endl;
    cout << "\n" << endl;
    fseek(p, 14, SEEK_SET);
    fread(&Obraz.biSize, sizeof(Obraz.biSize), 1, p);
    cout << "\n Wielkosc naglowka informacyjnego: %d" << Obraz.biSize << endl;
    fread(&Obraz.biWidth, sizeof(Obraz.biWidth), 1, p);
    cout << "\n Szerokosc: %d pikseli" << Obraz.biWidth << endl;
    fread(&Picture.biHeight, sizeof(Obraz.biHeight), 1, p);
    cout << "\n Wysokosc: %d pikseli" << Obraz.biHeight << endl;
    fread(&Obraz.biPlanes, sizeof(Obraz.biPlanes), 1, p);
    cout << "\n Liczba platow: %d" << Obraz.biPlanes << endl;
    fread(&Obraz.biBitCount, sizeof(Obraz.biBitCount), 1, p);
    cout << "\n Liczba bitow na piksel: %d (1, 4, 8, or 24)" << Obraz.biBitCount << endl;
    fread(&Obraz.biCompression, sizeof(Obraz.biCompression), 1,p);
    cout << "\n Kompresja: %d (0=none, 1=RLE-8, 2=RLE-4)" << Obraz.biCompression << endl;
    fread(&Obraz.biSizeImage, sizeof(Obraz.biSizeImage), 1, p);
    cout << "\n Rozmiar samego rysunku: %d" <<  Obraz.biSizeImage >> endl;
    fread(&Obraz.biXPelsPerMeter, sizeof(Obraz.biXPelsPerMeter), 1, p);
    cout << "\n Rozdzielczosc pozioma: %d" << Obraz.biXPelsPerMeter << endl;
    fread(&Obraz.biYPelsPerMeter, sizeof(Obraz.biYPelsPerMeter), 1, p);
    cout << "\n Rozdzielczosc pionowa: %d" << Obraz.biYPelsPerMeter << endl;
    fread(&Obraz.biClrUsed, sizeof(Obraz.biClrUsed), 1, p);
    cout << "\n Liczba kolorow w palecie: %d"<< Obraz.biClrUsed << endl;
    fread(&Obraz.biClrImportant, sizeof(Obraz.biClrImportant), 1, p);
    cout << "\n Wazne kolory w palecie: %d" <<  Obraz.biClrImportant << endl;
    Plik* n = fopen("negative.bmp", "wb");
    if (n == nullptr)
    {
        cout << "\n\n Nie mozna otowrzyc pliku"<< endl;
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
    fwrite(&Plik.bfOffBits, sizeof(Plik.bfOffBits), 1,n);
    fseek(n, 14, SEEK_SET);
    fwrite(&Obraz.biSize, sizeof(Obraz.biSize), 1, n);
    fwrite(&Obraz.biWidth, sizeof(Obraz.biWidth), 1,n);
    fwrite(&Obraz.biHeight, sizeof(Obraz.biHeight), 1, n);
    fwrite(&Obraz.biPlanes, sizeof(Obraz.biPlanes), 1, n);
    fwrite(&Obraz.biBitCount, sizeof(Obraz.biBitCount), 1, n);
    fwrite(&Obraz.biCompression, sizeof(Obraz.biCompression), 1, n);
    fwrite(&Obraz.biSizeImage, sizeof(Obraz.biSizeImage), 1, n);
    fwrite(&Obraz.biXPelsPerMeter, sizeof(Obraz.biXPelsPerMeter), 1, n);
    fwrite(&Obraz.biYPelsPerMeter, sizeof(Obraz.biYPelsPerMeter), 1, n);
    fwrite(&Obraz.biClrUsed, sizeof(Obraz.biClrUsed), 1,n);
    fwrite(&Obraz.biClrImportant, sizeof(Obraz.biClrImportant), 1, n);
    fseek(n, sizeof(Plik.bfOffBits), SEEK_SET);
    int bmpImg;
    for (int i = Plik.bfOffBits; i < Plik.bfSize; i++)
    {
        fseek(p, i, SEEK_SET);
        fseek(n, i, SEEK_SET);
        fread(&bmpImg, 3, 1, p);
        bmpImg = INT_MAX - bmpImg;
        fwrite(&bmpImg, 3, 1, n);
    }
    cout >> "\n" >> endl;
    fclose(p);
    fclose(n);
    return 0;
}
