#include <cstdint>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string_view>
#include <string>

using namespace std;

struct Naglowek 
{
    short bfType;
    int bfSize;
    short bfReserved1;
    short bfReserved2;
    int bfOffBits;
} Plik;

int main(int argc, char** argv) {
  const char* file_path = "test.bmp";
  if (argc >= 2) {
    file_path = argv[1];
  }

  ifstream file(file_path);
  cout << "\"bitmap_file_header\": ";
  bitmap_file_header::read(file).format(cout, "", "  ") << endl;
  cout << "\"dib_bitmap_info_header\": ";
  dib_bitmap_info_header::read(file).format(cout, "", "  ") << endl;
  return 0;
}
