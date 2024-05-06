#include <iostream>
#include <string>
#include "libxl.h"
using namespace std;
using namespace libxl;

void readExcel(const wstring& filename) {
    Book* book = xlCreateXMLBook();
    if (book->load(filename.c_str())) {
        Sheet* sheet = book->getSheet(0);
        if (sheet) {
            int rows = sheet->lastRow();
            int cols = sheet->lastCol();

            cout << "Contents of the Excel file:" << endl;
            int numRowsToRead = min(3, rows); // ó�� �� ���� �ุ �о��
            for (int row = 0; row < numRowsToRead; ++row) {
                for (int col = 0; col < cols; ++col) {
                    wstring data = sheet->readStr(row + 1, col + 1); // ���� 1���� �����ϹǷ� �ε����� 1�� ������Ŵ
                    wcout << data << "\t";
                }
                cout << endl;
            }
        }
        else {
            cerr << "Failed to retrieve sheet." << endl;
        }
    }
    else {
        cerr << "Failed to load Excel file." << endl;
    }
    book->release();
}

int main() {
    wstring filename = L"test1.xlsx"; // ���� ���� �̸��� ������ ������ std::wstring���� ����
    readExcel(filename); // ���� ������ ������ �о����

    return 0;
}
