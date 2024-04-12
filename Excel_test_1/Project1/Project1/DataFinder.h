#pragma once
#ifndef DATA_FINDER_H
#define DATA_FINDER_H

#include <vector>
#include <string>

class DataFinder {
public:
    // Ư�� �ڷḦ ã�� �Լ�
    static std::vector<std::string> findData(const std::vector<std::vector<std::string>>& data, const std::string& searchValue);

    // �� ��° �� �Ǵ� ���� �ִ��� Ȯ���ϴ� �Լ�
    static void findIndex(const std::vector<std::vector<std::string>>& data, const std::string& value);
};

#endif // DATA_FINDER_H
