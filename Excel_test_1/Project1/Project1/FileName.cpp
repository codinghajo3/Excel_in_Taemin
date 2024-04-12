#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std; // std 네임스페이스를 사용하겠다고 선언

// CSV 파일을 읽는 함수
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

// CSV 파일에 데이터를 쓰는 함수
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
    // 현재 실행 파일이 위치한 디렉토리
    string currentDirectory = "./";

    // CSV 파일 읽기 예제
    vector<vector<string>> readData = readCSV(currentDirectory + "test1.csv");
    for (const auto& row : readData) {
        for (const auto& cell : row) {
            cout << cell << "\t";
        }
        cout << endl;
    }

    // CSV 파일 쓰기 예제
    vector<vector<string>> writeData = { {"No.","이름","성별","나이","전화번호","방문횟수","ID","PW(X)"}, {"1","김태민","1","23","01032343245","2","",""} };
    writeCSV(currentDirectory + "test1.csv", writeData);

    return 0;
}
