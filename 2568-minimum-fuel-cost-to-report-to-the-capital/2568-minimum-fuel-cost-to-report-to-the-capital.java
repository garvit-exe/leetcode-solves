class Solution {
    private long fuelcost = 0;
    public long minimumFuelCost(int[][] roads, int seats) {
        int V =  roads.length+1;
        List<List<Integer>> adjList = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            adjList.add(new ArrayList<>());
        }
        for (int i = 0; i < roads.length; i++) {
            int u = roads[i][0], v = roads[i][1];
            adjList.get(u).add(v);
            adjList.get(v).add(u);
        }
        dfs(adjList, 0, -1, seats);
        return fuelcost;
    }
    private int dfs(List<List<Integer>> adjList, int u, int p, int seats) {
        int people = 1;
        for (int neighbor : adjList.get(u)) {
            if (neighbor == p) continue;

            int neighborP = dfs(adjList, neighbor, u, seats);
            fuelcost += (long) Math.ceil((double)neighborP/seats);
            people += neighborP;
        }
        return people;
    }
}