#include "CSVProcessor.h"
#include "CSVReader.h"
#include "DataFinder.h"
#include <iostream>

using namespace std;

CSVProcessor::CSVProcessor(const string& filename) : filename(filename) {}

void CSVProcessor::processInput(const string& searchValue) {
    CSVReader csvReader(filename);
    vector<vector<string>> data = csvReader.getData();

    // Ư�� �ڷḦ ã�� ����
    vector<string> searchData = DataFinder::findData(data, searchValue);
    if (!searchData.empty()) {
        cout << "Data found: ";
        for (const auto& data : searchData) {
            cout << data << " ";
        }
        cout << endl;
    }
    else {
        cout << "Data not found." << endl;
    }

    // �� ��° �� �Ǵ� ���� �ִ��� Ȯ���ϴ� ����
    DataFinder::findIndex(data, searchValue);
}
