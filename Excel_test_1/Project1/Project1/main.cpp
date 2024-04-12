#include <iostream>
#include "CSVProcessor.h"

using namespace std;

int main() {
    // CSV ������ ���
    string filename = "test1.csv";

    // CSVProcessor ��ü ����
    CSVProcessor csvProcessor(filename);

    // ����� �Է� �ޱ�
    cout << "Enter the value you want to search: ";
    string searchValue;
    getline(cin, searchValue);

    // ����� �Է� ó��
    csvProcessor.processInput(searchValue);

    return 0;
}
