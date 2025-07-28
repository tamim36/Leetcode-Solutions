function checkValidCuts(n: number, rectangles: number[][]): boolean {
    function checkCuts(intervals: [number, number][]): boolean {
        intervals.sort((a, b) => a[0] - b[0]);
        let lastEnd = intervals[0][1];
        let gapCount = 0;

        for (let interval of intervals){
            if (interval[0] >= lastEnd)
                gapCount++;

            lastEnd = Math.max(lastEnd, interval[1]);
        }

        return gapCount >= 2;
    }

    const xIntervals: [number, number][] = [];
    const yIntervals: [number, number][] = [];

    for (let rect of rectangles){
        xIntervals.push([rect[0], rect[2]]);
        yIntervals.push([rect[1], rect[3]]);
    }

    return checkCuts(xIntervals) || checkCuts(yIntervals);

};