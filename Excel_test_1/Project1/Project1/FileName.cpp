#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std; // std ���ӽ����̽��� ����ϰڴٰ� ����

// CSV ������ �д� �Լ�
vector<vector<string>> readCSV(const string& filename) {
    ifstream file(filename);
    vector<vector<string>> data;

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

    return data;
}

// CSV ���Ͽ� �����͸� ���� �Լ�
void writeCSV(const string& filename, const vector<vector<string>>& data) {
    ofstream file(filename);

    for (const auto& row : data) {
        for (size_t i = 0; i < row.size(); ++i) {
            file << row[i];
            if (i != row.size() - 1) {
                file << ",";
            }
        }
        file << "\n";
    }

    file.close();
}

int main() {
    // ���� ���� ������ ��ġ�� ���丮
    string currentDirectory = "./";

    // CSV ���� �б� ����
    vector<vector<string>> readData = readCSV(currentDirectory + "test1.csv");
    for (const auto& row : readData) {
        for (const auto& cell : row) {
            cout << cell << "\t";
        }
        cout << endl;
    }

    // CSV ���� ���� ����
    vector<vector<string>> writeData = { {"No.","�̸�","����","����","��ȭ��ȣ","�湮Ƚ��","ID","PW(X)"}, {"1","���¹�","1","23","01032343245","2","",""} };
    writeCSV(currentDirectory + "test1.csv", writeData);

    return 0;
}
