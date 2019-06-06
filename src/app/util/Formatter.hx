package app.util;

class Formatter {
    private static var CELL_PAD:Int = 2;

    private var _displayColor:Bool = false;
    private var _columnData:Array<Map<String, Dynamic>>;


    public function new(?displayColor:Bool)
    {
        _displayColor = displayColor;
    }

    public function printTable(headers:Array<String>, rows:Array<Array<String>>)
    {
        if (validateColumnCount(headers, rows) == false) {
            throw "Each Row's column count must match the header count.";
        }

        // Get longest word for each column for column width
        for (colIndex in 0...headers.length) {
            var col = getRowColumnByIndex(colIndex, rows);
            var colWidth = getLongestStringLength(col) + CELL_PAD*2;
            _columnData[colIndex] = ["colWidth" => colWidth];
        }

        var formattedRows = [];
        var formattedHeadersRow = getFormattedRowOutput(headers);
        formattedRows.push(formattedHeadersRow);

        for (row in rows) {
            var formattedRowString = getFormattedRowOutput(row);
            formattedRows.push(formattedRowString);
        }

        for (formattedRow in formattedRows) {
            Sys.println(formattedRow);
        }
    }

    private function getFormattedRowOutput(row:Array<String>) : String
    {
        var formattedStringArray = [];
        for (colIndex in 0...row.length) {
            var formattedString = getPadding() + row[colIndex] + getPadding((_columnData[colIndex].colWidth - (row[colIndex].length + CELL_PAD)));
            formattedStringArray.push(formattedString);
        }
        
        var formattedRow = formattedStringArray.join("|");
        return "|" + formattedRow + "|";
    }

    private function getPadding(?length:Int) : String
    {
        var padLen = length ? length : CELL_PAD;

        var padding = "";
        for (i in 0...padLen) {
            padding += "";
        }

        return padding;
    }

    private function getRowColumnByIndex(index:Int, rows:Array<Array<String>>) : Array<String>
    {
        var column = [];

        for (i in 0...rows.length) {
            column.push(rows[i][index]);
        }

        return column;
    }

    private function getLongestStringLength(array:Array<String>) : Int
    {
        var max = 0;
        for (i in 0...array.length) {
            if (array[i].length > max) {
                max = array[i].length;
            }
        }

        return max;
    }

    private function validateColumnCount(headers:Array<Dynamic>, rows:Array<Array<Dynamic>>) : Bool
    {
        var colCount = headers.length;

        for (row in rows) {
            if (row.length != colCount) {
                return false;
            }
        }

        return true;
    }
}
