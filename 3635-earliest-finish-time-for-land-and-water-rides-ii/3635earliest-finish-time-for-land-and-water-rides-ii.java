/**
 * A utility class to find the earliest finish time for a set of tasks.
 * This helper class provides a clear separation of concerns.
 */
class TaskSchedulerUtils {

    /**
     * Finds the minimum finish time for a given set of tasks.
     * The finish time for a task is its start time plus its duration.
     * @param startTimes An array of task start times.
     * @param durations An array of task durations.
     * @return The minimum finish time among all tasks, or 0 if no tasks exist.
     */
    public static int findMinFinishTime(int[] startTimes, int[] durations) {
        if (startTimes == null || startTimes.length == 0) {
            return 0; // Or a sentinel value like -1 to indicate no tasks.
        }
        int minFinish = Integer.MAX_VALUE;
        for (int i = 0; i < startTimes.length; i++) {
            minFinish = Math.min(minFinish, startTimes[i] + durations[i]);
        }
        return minFinish;
    }

    /**
     * Calculates the earliest finish time for a sequence of tasks.
     * This assumes the first task has an existing finish time and the second
     * task is drawn from a set of available tasks.
     * @param firstTaskFinishTime The finish time of the first task.
     * @param secondTaskStartTimes An array of start times for the second task.
     * @param secondTaskDurations An array of durations for the second task.
     * @return The minimum finish time for this sequence of tasks.
     */
    public static int calculateSequenceFinishTime(int firstTaskFinishTime, int[] secondTaskStartTimes, int[] secondTaskDurations) {
        int minFinishTime = Integer.MAX_VALUE;
        if (secondTaskStartTimes.length == 0) {
            return firstTaskFinishTime;
        }
        for (int i = 0; i < secondTaskStartTimes.length; i++) {
            int secondTaskStartTime = Math.max(firstTaskFinishTime, secondTaskStartTimes[i]);
            int finishTime = secondTaskStartTime + secondTaskDurations[i];
            minFinishTime = Math.min(minFinishTime, finishTime);
        }
        return minFinishTime;
    }
}

/**
 * The main solution class. It uses the utility class to perform the calculations.
 */
class Solution {
    /**
     * Calculates the earliest possible finish time for completing a set of tasks on both land and water.
     * The method determines the finish time by considering the optimal sequencing of tasks.
     *
     * @param landStartTime An array of start times for land tasks.
     * @param landDuration An array of durations for the land tasks.
     * @param waterStartTime An array of start times for water tasks.
     * @param waterDuration An array of durations for the water tasks.
     * @return The earliest possible finish time for all tasks.
     */
    public int earliestFinishTime(int[] landStartTime, int[] landDuration, int[] waterStartTime, int[] waterDuration) {
        // Handle edge cases where one or both task types are missing.
        if (landStartTime.length == 0 && waterStartTime.length == 0) {
            return 0;
        } else if (landStartTime.length == 0) {
            return TaskSchedulerUtils.findMinFinishTime(waterStartTime, waterDuration);
        } else if (waterStartTime.length == 0) {
            return TaskSchedulerUtils.findMinFinishTime(landStartTime, landDuration);
        }

        // Find the single earliest-finishing land task.
        int minLandFinish = TaskSchedulerUtils.findMinFinishTime(landStartTime, landDuration);
        
        // Find the single earliest-finishing water task.
        int minWaterFinish = TaskSchedulerUtils.findMinFinishTime(waterStartTime, waterDuration);
        
        // Scenario 1: The earliest-finishing land task is done first.
        // Then, we find the best possible water task to follow it.
        int minFinishTimeLandFirst = TaskSchedulerUtils.calculateSequenceFinishTime(minLandFinish, waterStartTime, waterDuration);
        
        // Scenario 2: The earliest-finishing water task is done first.
        // Then, we find the best possible land task to follow it.
        int minFinishTimeWaterFirst = TaskSchedulerUtils.calculateSequenceFinishTime(minWaterFinish, landStartTime, landDuration);
        
        // The overall earliest finish time is the minimum of the two scenarios.
        return Math.min(minFinishTimeLandFirst, minFinishTimeWaterFirst);
    }
}