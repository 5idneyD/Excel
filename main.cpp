#include <stdio.h>
#include <stdlib.h>
#include <OpenXLSX.hpp>
#include <string.h>

using namespace OpenXLSX;

int main() {

    XLDocument doc;
    // doc.create("../Spreadsheet.xlsx");
    try{
        doc.open("./Spreadsheet.xlsx");
    } catch(...) {
    doc.create("./Spreadsheet.xlsx");
    }

    auto wks = doc.workbook().worksheet("Sheet1");
    auto rng = wks.range(XLCellReference("A1"), XLCellReference("B2"));
    
    int i = 0;

    for (auto &cell: rng) {
        cell.value() = i;
        i++;
    };



    XLCellValue A1 = wks.cell("A1").value();

    std::cout<<A1<<std::endl;

    doc.save();

    printf("Done!");

    return 0;
}