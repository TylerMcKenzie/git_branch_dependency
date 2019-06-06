package app.util;

class Formatter {
    public static function printTable(headers:Array<String>, rows:Array<String>)
    {
        
    }

    private static function getLongestStringLength(array:Array<String>) : Int
    {
        var max = 0;
        for (i in 0...array.length) {
            if (array[i].length > max) {
                max = array[i].length;
            }
        }

        return max;
    }
}