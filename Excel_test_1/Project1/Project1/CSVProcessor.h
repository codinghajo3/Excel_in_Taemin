#ifndef CSV_PROCESSOR_H
#define CSV_PROCESSOR_H

#include <string>

class CSVProcessor {
private:
    std::string filename;

public:
    CSVProcessor(const std::string& filename);

    // ����� �Է��� ó���ϴ� �Լ�
    void processInput(const std::string& searchValue);
};

#endif // CSV_PROCESSOR_H
