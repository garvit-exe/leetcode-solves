/**
 * Encapsulates the logic for finding the minimum number of elements to remove
 * from an array to satisfy a specific condition.
 */
class ArrayProcessor {

    private final int[] nums;
    private final int k;

    public ArrayProcessor(int[] nums, int k) {
        // Create a copy to avoid modifying the original array passed to the constructor.
        this.nums = Arrays.copyOf(nums, nums.length);
        this.k = k;
    }

    /**
     * Calculates the minimum number of elements to remove.
     * This is equivalent to finding the maximum length of a subarray
     * where the condition (nums[right] <= k * nums[left]) is met.
     *
     * @return The minimum number of elements to remove.
     */
    public int findMinRemoval() {
        // Sorting the array is the first step for the sliding window approach.
        Arrays.sort(nums);
        int n = nums.length;
        
        // Handle edge cases where the array is empty or has only one element.
        if (n <= 1) {
            return 0;
        }

        int maxLength = 0;
        int left = 0;
        
        // Use a sliding window to find the longest subarray that meets the condition.
        for (int right = 0; right < n; right++) {
            while (left < n && (long) nums[right] > (long) k * nums[left]) {
                left++;
            }
            // Ensure `left` doesn't cross `right` if all elements are removed.
            if (left <= right) {
                maxLength = Math.max(maxLength, right - left + 1);
            }
        }
        
        return n - maxLength;
    }
}

/**
 * The main solution class. It acts as an entry point, creating an instance
 * of `ArrayProcessor` to solve the problem.
 */
class Solution {
    /**
     * Finds the minimum number of elements to remove from an array
     * such that the maximum element is no more than k times the minimum element.
     *
     * @param nums The input array of integers.
     * @param k    The multiplication factor.
     * @return The minimum number of elements to remove.
     */
    public int minRemoval(int[] nums, int k) {
        ArrayProcessor processor = new ArrayProcessor(nums, k);
        return processor.findMinRemoval();
    }
}