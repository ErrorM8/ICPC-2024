import heapq
import sys

class Node:
    def __init__(self, x, y, state, cost):
        self.x = x
        self.y = y
        self.state = state  # state: 0 - no diffuser, 1 - carrying, 2 - placed
        self.cost = cost

    def __lt__(self, other):
        return self.cost < other.cost

def min_cost(grid, mine_grid, build_cost, reuse_cost):
    n = len(grid)
    m = len(grid[0])
    dist = [[[sys.maxsize] * 3 for _ in range(m)] for _ in range(n)]
    pq = []
    heapq.heappush(pq, Node(0, 0, 0, 0))  # Start at (0, 0) with no diffuser

    while pq:
        node = heapq.heappop(pq)
        x, y, state, cost = node.x, node.y, node.state, node.cost

        # If we've reached the bottom-right corner with a placed diffuser, return the cost
        if state == 2 and x == n - 1 and y == m - 1:
            return cost

        # Explore possible moves
        for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:  # Move in 4 directions
            nx, ny = x + dx, y + dy
            if 0 <= nx < n and 0 <= ny < m and mine_grid[nx][ny] != 'M':
                if state == 0:  # No diffuser
                    # Move to adjacent cell
                    if dist[nx][ny][0] > cost + grid[nx][ny]:
                        dist[nx][ny][0] = cost + grid[nx][ny]
                        heapq.heappush(pq, Node(nx, ny, 0, cost + grid[nx][ny]))
                elif state == 1:  # Carrying diffuser
                    # Place diffuser
                    if mine_grid[nx][ny] == 'M' and dist[nx][ny][2] > cost + build_cost:
                        dist[nx][ny][2] = cost + build_cost
                        heapq.heappush(pq, Node(nx, ny, 2, cost + build_cost))
                elif state == 2:  # Placed diffuser
                    # Pick up diffuser
                    if dist[nx][ny][1] > cost + reuse_cost:
                        dist[nx][ny][1] = cost + reuse_cost
                        heapq.heappush(pq, Node(nx, ny, 1, cost + reuse_cost))

    return -1  # No valid solution found
