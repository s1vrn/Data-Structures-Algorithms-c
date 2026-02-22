/*
 * graph.h — Graph (Adjacency List, Declarations)
 *
 * An integer-labeled directed/undirected graph using adjacency lists.
 * Supports BFS, DFS, and basic connectivity queries.
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>
#include <stddef.h>

/* ── Adjacency List Node ─────────────────────────────────────────────── */

typedef struct AdjNode {
    int             dest;
    int             weight;
    struct AdjNode *next;
} AdjNode;

/* ── Graph Definition ────────────────────────────────────────────────── */

typedef struct {
    int      vertices;
    bool     directed;
    AdjNode **adj;       /* array of adjacency list heads */
} Graph;

/* ── Function Declarations ───────────────────────────────────────────── */

/**
 * Create a graph with `vertices` nodes (labelled 0..vertices-1).
 * If `directed` is false, edges are added in both directions.
 */
Graph *graph_create(int vertices, bool directed);

/**
 * Add an edge from `src` to `dest` with the given weight.
 * For undirected graphs, the reverse edge is also added.
 */
void graph_add_edge(Graph *g, int src, int dest, int weight);

/**
 * Check if an edge exists from `src` to `dest`.
 */
bool graph_has_edge(const Graph *g, int src, int dest);

/**
 * Print the adjacency list representation.
 */
void graph_display(const Graph *g);

/**
 * Breadth-First Search from `start`.
 * Prints the traversal order.
 */
void graph_bfs(const Graph *g, int start);

/**
 * Depth-First Search from `start`.
 * Prints the traversal order.
 */
void graph_dfs(const Graph *g, int start);

/**
 * Free all memory associated with the graph.
 */
void graph_destroy(Graph *g);

#endif /* GRAPH_H */
