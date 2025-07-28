public class Solution {
    public bool CheckValidCuts(int n, int[][] rectangles) {
        var xIntervals = rectangles.Select(rect => new int[]{
            rect[0], rect[2]
        }).ToArray();

        var yIntervals = rectangles.Select(rect => new int[]{
            rect[1], rect[3]
        }).ToArray();

        return Check(xIntervals) || Check(yIntervals); 
    }

    private bool Check(int[][] intervals){
        Array.Sort(intervals, (a, b) => a[0].CompareTo(b[0]));

        int gapCount = 0;
        int lastEnd = intervals[0][1];

        foreach (var interval in intervals){
            if (interval[0] >= lastEnd)
                gapCount++;

            lastEnd = Math.Max(lastEnd, interval[1]);
        }

        return gapCount >= 2;
    }
}