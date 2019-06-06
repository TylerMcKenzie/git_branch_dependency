package app.util;

class Formatter {
    private static var CELL_PAD:Int = 2;

    private var _displayColor:Bool;
    private var _columnData:Array<Int> = [];


    public function new(displayColor:Bool = false)
    {
        _displayColor = displayColor;
    }

    public function printTable(headers:Array<String>, rows:Array<Array<String>>)
    {
        if (validateColumnCount(headers, rows) == false) {
            Sys.println("Each Row's column count must match the header count.");
            return;
        }

        // Get longest word for each column for column width
        setColumnWidths(headers, rows);

        var formattedRows = [];
        var formattedHeaders = getFormattedRowOutput([for (h in headers) h.toUpperCase()]);
        var divider = [for (i in 0...formattedHeaders.length) "-"].join("");

        formattedRows.push(divider);
        formattedRows.push(formattedHeaders);
        formattedRows.push(divider);

        for (row in rows) {
            formattedRows.push(getFormattedRowOutput(row));
        }

        formattedRows.push(divider);

        for (formattedRow in formattedRows) {
            Sys.println(formattedRow);
        }
    }

    private function getFormattedRowOutput(row:Array<String>) : String
    {
        var formattedStringArray = [];
        for (colIndex in 0...row.length) {
            var formattedString = getPadding() + row[colIndex] + getPadding((_columnData[colIndex] - (row[colIndex].length + CELL_PAD)));
            formattedStringArray.push(formattedString);
        }
        
        var formattedRow = formattedStringArray.join("|");
        return "|" + formattedRow + "|";
    }

    private function getPadding(?length:Int) : String
    {
        var padLen = (length != null) ? length : CELL_PAD;

        var padding = "";
        for (i in 0...padLen) {
            padding += " ";
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

    private function setColumnWidths(headers:Array<String>, rows:Array<Array<String>>) : Void
    {
        for (colIndex in 0...headers.length) {
            var col = getRowColumnByIndex(colIndex, rows);
            var maxRowWidth = getLongestStringLength(col);
            var maxWidth = (headers[colIndex].length > maxRowWidth) ? headers[colIndex].length : maxRowWidth;
            _columnData[colIndex] = maxWidth + CELL_PAD*2;
        }
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
