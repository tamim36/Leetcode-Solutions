func majorityElement(nums []int) int {
    count := 0;
    candidate := nums[0];

    for _, num := range nums {
        if count == 0 {
            candidate = num
        }

        if candidate == num {
            count++
        } else {
            count--
        }
    }

    return candidate;
}