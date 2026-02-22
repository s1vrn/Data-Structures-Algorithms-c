/*
 * graph.c — Graph (Adjacency List, Implementation)
 */

#include "graph.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ── Helpers ─────────────────────────────────────────────────────────── */

static AdjNode *adjnode_create(int dest, int weight)
{
    AdjNode *node = (AdjNode *)malloc(sizeof(AdjNode));
    if (!node) {
        fprintf(stderr, "Error: malloc failed in adjnode_create\n");
        return NULL;
    }
    node->dest   = dest;
    node->weight = weight;
    node->next   = NULL;
    return node;
}

/* ── Create / Destroy ────────────────────────────────────────────────── */

Graph *graph_create(int vertices, bool directed)
{
    Graph *g = (Graph *)malloc(sizeof(Graph));
    if (!g) {
        fprintf(stderr, "Error: malloc failed in graph_create\n");
        return NULL;
    }

    g->vertices = vertices;
    g->directed = directed;
    g->adj = (AdjNode **)calloc((size_t)vertices, sizeof(AdjNode *));
    if (!g->adj) {
        fprintf(stderr, "Error: calloc failed for adjacency lists\n");
        free(g);
        return NULL;
    }

    return g;
}

void graph_destroy(Graph *g)
{
    if (!g) return;

    for (int i = 0; i < g->vertices; i++) {
        AdjNode *curr = g->adj[i];
        while (curr) {
            AdjNode *tmp = curr;
            curr = curr->next;
            free(tmp);
        }
    }
    free(g->adj);
    free(g);
}

/* ── Edge Operations ─────────────────────────────────────────────────── */

void graph_add_edge(Graph *g, int src, int dest, int weight)
{
    if (src < 0 || src >= g->vertices || dest < 0 || dest >= g->vertices) {
        fprintf(stderr, "Error: vertex out of range (%d -> %d)\n", src, dest);
        return;
    }

    /* Add src -> dest */
    AdjNode *node = adjnode_create(dest, weight);
    if (!node) return;
    node->next  = g->adj[src];
    g->adj[src] = node;

    /* If undirected, add dest -> src */
    if (!g->directed) {
        AdjNode *rev = adjnode_create(src, weight);
        if (!rev) return;
        rev->next    = g->adj[dest];
        g->adj[dest] = rev;
    }
}

bool graph_has_edge(const Graph *g, int src, int dest)
{
    if (src < 0 || src >= g->vertices) return false;

    AdjNode *curr = g->adj[src];
    while (curr) {
        if (curr->dest == dest) return true;
        curr = curr->next;
    }
    return false;
}

/* ── Display ─────────────────────────────────────────────────────────── */

void graph_display(const Graph *g)
{
    printf("Graph (%s, %d vertices):\n",
           g->directed ? "directed" : "undirected", g->vertices);

    for (int i = 0; i < g->vertices; i++) {
        printf("  [%d]:", i);
        AdjNode *curr = g->adj[i];
        while (curr) {
            printf(" -> %d(w=%d)", curr->dest, curr->weight);
            curr = curr->next;
        }
        printf("\n");
    }
}

/* ── BFS ─────────────────────────────────────────────────────────────── */

void graph_bfs(const Graph *g, int start)
{
    if (start < 0 || start >= g->vertices) return;

    bool *visited = (bool *)calloc((size_t)g->vertices, sizeof(bool));
    int  *queue   = (int *)malloc(sizeof(int) * (size_t)g->vertices);
    if (!visited || !queue) {
        free(visited);
        free(queue);
        return;
    }

    int front = 0, rear = 0;

    visited[start] = true;
    queue[rear++]  = start;

    printf("BFS from %d: ", start);

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        AdjNode *curr = g->adj[v];
        while (curr) {
            if (!visited[curr->dest]) {
                visited[curr->dest] = true;
                queue[rear++] = curr->dest;
            }
            curr = curr->next;
        }
    }
    printf("\n");

    free(visited);
    free(queue);
}

/* ── DFS (iterative with stack) ──────────────────────────────────────── */

void graph_dfs(const Graph *g, int start)
{
    if (start < 0 || start >= g->vertices) return;

    bool *visited = (bool *)calloc((size_t)g->vertices, sizeof(bool));
    int  *stack   = (int *)malloc(sizeof(int) * (size_t)g->vertices);
    if (!visited || !stack) {
        free(visited);
        free(stack);
        return;
    }

    int top = 0;
    stack[top++] = start;

    printf("DFS from %d: ", start);

    while (top > 0) {
        int v = stack[--top];

        if (visited[v]) continue;
        visited[v] = true;
        printf("%d ", v);

        /* Push neighbours in reverse order for natural ordering */
        AdjNode *curr = g->adj[v];
        while (curr) {
            if (!visited[curr->dest])
                stack[top++] = curr->dest;
            curr = curr->next;
        }
    }
    printf("\n");

    free(visited);
    free(stack);
}
