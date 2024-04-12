/*
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class CSVReader {
private:
    string filename;
    vector<vector<string>> data;

    // CSV ������ �д� �Լ�
    void readCSV() {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Error: Unable to open file " << filename << endl;
            return;
        }

        string line;
        while (getline(file, line)) {
            stringstream lineStream(line);
            string cell;
            vector<string> rowData;

            while (getline(lineStream, cell, ',')) {
                rowData.push_back(cell);
            }

            data.push_back(rowData);
        }

        file.close();
    }

public:
    CSVReader(const string& filename) : filename(filename) {
        readCSV();
    }

    // �����͸� ��ȯ�ϴ� �Լ�
    vector<vector<string>> getData() const {
        return data;
    }
};

class DataFinder {
public:
    // Ư�� �ڷḦ ã�� �Լ�
    static vector<string> findData(const vector<vector<string>>& data, const string& searchValue) {
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

    // �� ��° �� �Ǵ� ���� �ִ��� Ȯ���ϴ� �Լ�
    static void findIndex(const vector<vector<string>>& data, const string& value) {
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
};

int main() {
    // ���� ���� ������ ��ġ�� ���丮
    string currentDirectory = "./";
    string filename = currentDirectory + "test1.csv";

    CSVReader csvReader(filename);
    vector<vector<string>> data = csvReader.getData();

    // Ư�� �ڷḦ ã�� ����
    string searchValue = "���¹�";
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
    DataFinder::findIndex(data, "�̸�");

    return 0;
}

*/