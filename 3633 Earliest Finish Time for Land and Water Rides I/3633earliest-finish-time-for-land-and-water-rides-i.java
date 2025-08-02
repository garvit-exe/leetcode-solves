/**
 * Represents a single task with a start time and a duration.
 */
class Task {
    private final int startTime;
    private final int duration;

    public Task(int startTime, int duration) {
        this.startTime = startTime;
        this.duration = duration;
    }

    public int getStartTime() {
        return startTime;
    }

    public int getDuration() {
        return duration;
    }

    public int getFinishTime() {
        return startTime + duration;
    }
}

/**
 * Calculates the earliest possible finish time for a set of land and water tasks.
 * This class handles the core logic of determining the optimal sequence.
 */
class TaskScheduler {
    private final List<Task> landTasks;
    private final List<Task> waterTasks;

    public TaskScheduler(int[] landStartTime, int[] landDuration, int[] waterStartTime, int[] waterDuration) {
        this.landTasks = createTasks(landStartTime, landDuration);
        this.waterTasks = createTasks(waterStartTime, waterDuration);
    }

    private List<Task> createTasks(int[] startTimes, int[] durations) {
        List<Task> tasks = new ArrayList<>();
        if (startTimes != null && durations != null) {
            for (int i = 0; i < startTimes.length; i++) {
                tasks.add(new Task(startTimes[i], durations[i]));
            }
        }
        return tasks;
    }

    public int calculateEarliestFinishTime() {
        int minTotalFinishTime = Integer.MAX_VALUE;

        // If there are no tasks, the finish time is 0.
        if (landTasks.isEmpty() && waterTasks.isEmpty()) {
            return 0;
        }

        // Iterate through all pairs of a single land and a single water task.
        for (Task landTask : landTasks) {
            for (Task waterTask : waterTasks) {
                // Scenario 1: Land task is completed first.
                int finishTimeIfLandFirst = Math.max(landTask.getFinishTime(), waterTask.getStartTime()) + waterTask.getDuration();

                // Scenario 2: Water task is completed first.
                int finishTimeIfWaterFirst = Math.max(waterTask.getFinishTime(), landTask.getStartTime()) + landTask.getDuration();
                
                int currentPairFinishTime = Math.min(finishTimeIfLandFirst, finishTimeIfWaterFirst);
                minTotalFinishTime = Math.min(minTotalFinishTime, currentPairFinishTime);
            }
        }
        
        return minTotalFinishTime;
    }
}

/**
 * The main solution class that uses the TaskScheduler to solve the problem.
 * This class now acts as an entry point, adhering to a typical LeetCode class structure.
 */
class Solution {
    public int earliestFinishTime(int[] landStartTime, int[] landDuration, int[] waterStartTime, int[] waterDuration) {
        TaskScheduler scheduler = new TaskScheduler(landStartTime, landDuration, waterStartTime, waterDuration);
        return scheduler.calculateEarliestFinishTime();
    }
}