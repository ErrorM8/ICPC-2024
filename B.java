import java.util.*;

class Wire {
    int x1, y1, x2, y2, color;

    public Wire(int x1, int y1, int x2, int y2, int color) {
        this.x1 = x1;
        this.y1 = y1;
        this.x2 = x2;
        this.y2 = y2;
        this.color = color;
    }
}

public class MinimumWireRemoval {

    public static boolean doLinesIntersect(Wire line1, Wire line2) {
        // Implementation of line intersection algorithm (e.g., using vector cross products)
        // ...
    }

    public static int minWireRemoval(List<Wire> wires) {
        int n = wires.size();
        boolean[][] graph = new boolean[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (wires.get(i).color != wires.get(j).color && doLinesIntersect(wires.get(i), wires.get(j))) {
                    graph[i][j] = true;
                    graph[j][i] = true;
                }
            }
        }

        // Use a min-cut/max-flow algorithm (e.g., Ford-Fulkerson)
        return fordFulkerson(graph, 0, n - 1);
    }

    public static int fordFulkerson(boolean[][] graph, int s, int t) {
        // Implementation of Ford-Fulkerson algorithm
        // ...
    }

    public static void main(String[] args) {
        // Example usage (replace with your actual wire data)
        List<Wire> wires = new ArrayList<>();
        // ... add wires to the list ...

        int minRemovals = minWireRemoval(wires);
        System.out.println("Minimum wires to remove: " + minRemovals);
    }
}