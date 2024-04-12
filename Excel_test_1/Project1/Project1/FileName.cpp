#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

// CSV 파일을 읽는 함수
std::vector<std::vector<std::string>> readCSV(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<std::vector<std::string>> data;

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream lineStream(line);
        std::string cell;
        std::vector<std::string> rowData;

        while (std::getline(lineStream, cell, ',')) {
            rowData.push_back(cell);
        }

        data.push_back(rowData);
    }

    return data;
}

// CSV 파일에 데이터를 쓰는 함수
void writeCSV(const std::string& filename, const std::vector<std::vector<std::string>>& data) {
    std::ofstream file(filename);

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
    std::string currentDirectory = "./";

    // CSV 파일 읽기 예제
    std::vector<std::vector<std::string>> readData = readCSV(currentDirectory + "test1.csv");
    for (const auto& row : readData) {
        for (const auto& cell : row) {
            std::cout << cell << "\t";
        }
        std::cout << std::endl;
    }

    // CSV 파일 쓰기 예제
    std::vector<std::vector<std::string>> writeData = { {"Name", "Age", "City"}, {"John", "25", "New York"}, {"Alice", "30", "Los Angeles"} };
    writeCSV(currentDirectory + "output.csv", writeData);

    return 0;
}

