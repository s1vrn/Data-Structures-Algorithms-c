# Graph (Adjacency List)

A **graph** is a non-linear data structure consisting of vertices (nodes) connected by edges. This implementation uses an **adjacency list** — an array of linked lists — supporting both directed and undirected weighted graphs.

## Operations

| Operation       | Time Complexity | Space Complexity |
|-----------------|:--------------:|:----------------:|
| Add Edge        | O(1)           | O(1)             |
| Has Edge        | O(V)           | O(1)             |
| BFS             | O(V + E)       | O(V)             |
| DFS             | O(V + E)       | O(V)             |
| Display         | O(V + E)       | O(1)             |

Space: **O(V + E)**

## API

```c
Graph *graph_create(int vertices, bool directed);
void   graph_add_edge(Graph *g, int src, int dest, int weight);
bool   graph_has_edge(const Graph *g, int src, int dest);
void   graph_display(const Graph *g);
void   graph_bfs(const Graph *g, int start);
void   graph_dfs(const Graph *g, int start);
void   graph_destroy(Graph *g);
```

## Use Cases

- **Social networks** (friends, followers).
- **Route planning** (maps, GPS navigation).
- **Dependency resolution** (build systems, package managers).
- **Web crawling** (link graph traversal).
- **Network topology** and flow analysis.

## Build & Run

```bash
make graph
./graph/graph_test
```
