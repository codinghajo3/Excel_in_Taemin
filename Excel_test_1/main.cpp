#include <iostream>
#include <QtCore>
#include <QtXlsx>

int main() {
    // Open Excel file
    QXlsx::Document xlsx("test1.xlsx");

    // Read data from Excel file
    QVariant value = xlsx.read("A1");
    qDebug() << "A1 value:" << value.toString();

    return 0;
}