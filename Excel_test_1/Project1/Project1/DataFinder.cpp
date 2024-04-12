#include "DataFinder.h"
#include <iostream>

using namespace std;

vector<string> DataFinder::findData(const vector<vector<string>>& data, const string& searchValue) {
    vector<string> result;
    for (const auto& row : data) {
        for (const auto& cell : row) {
            if (cell == searchValue) {
                result = row;
                return result;
            }
        }
    }
    return result; // ã�� ������ ��� �� ���� ��ȯ
}

void DataFinder::findIndex(const vector<vector<string>>& data, const string& value) {
    for (size_t i = 0; i < data.size(); ++i) {
        for (size_t j = 0; j < data[i].size(); ++j) {
            if (data[i][j] == value) {
                cout << "Value '" << value << "' found at Row: " << i + 1 << ", Column: " << j + 1 << endl;
                return;
            }
        }
    }
    cout << "Value '" << value << "' not found in the CSV." << endl;
}
