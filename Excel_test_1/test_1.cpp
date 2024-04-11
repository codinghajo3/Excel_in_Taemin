#include <QXlsx/xlsxdocument.h>
#include <QXlsx/xlsxcell.h>

int main() {
  QXlsxDocument doc("test1.xlsx");

  // 첫 번째 시트 가져오기
  QXlsxSheet *sheet = doc.sheet(0);

  // 첫 번째 행의 첫 번째 셀의 값 가져오기
  QString value = sheet->cellAt(0, 0)->value().toString();

  // 모든 셀을 반복 처리
  for (int i = 0; i < sheet->rowCount(); i++) {
    for (int j = 0; j < sheet->columnCount(); j++) {
      QXlsxCell *cell = sheet->cellAt(i, j);
      // 셀 값 처리
    }
  }

  return 0;
}
