/*
 * main.c — Graph Test Driver
 */

#include "graph.h"
#include <stdio.h>
#include <assert.h>

int main(void)
{
    printf("=== Graph Tests ===\n\n");

    /* ── Undirected Graph ────────────────────────────────────────────── */
    printf("--- Undirected Graph (6 vertices) ---\n");
    Graph *ug = graph_create(6, false);
    assert(ug != NULL);

    /*
     *    0 --- 1 --- 2
     *    |     |
     *    3 --- 4 --- 5
     */
    graph_add_edge(ug, 0, 1, 1);
    graph_add_edge(ug, 1, 2, 1);
    graph_add_edge(ug, 0, 3, 1);
    graph_add_edge(ug, 1, 4, 1);
    graph_add_edge(ug, 3, 4, 1);
    graph_add_edge(ug, 4, 5, 1);

    graph_display(ug);

    assert(graph_has_edge(ug, 0, 1));
    assert(graph_has_edge(ug, 1, 0));   /* undirected */
    assert(!graph_has_edge(ug, 0, 5));

    printf("\n");
    graph_bfs(ug, 0);
    graph_dfs(ug, 0);

    graph_destroy(ug);

    /* ── Directed Graph ──────────────────────────────────────────────── */
    printf("\n--- Directed Graph (5 vertices) ---\n");
    Graph *dg = graph_create(5, true);
    assert(dg != NULL);

    /*
     *  0 -> 1 -> 3
     *  |         ^
     *  v         |
     *  2 ------> 4
     */
    graph_add_edge(dg, 0, 1, 1);
    graph_add_edge(dg, 0, 2, 1);
    graph_add_edge(dg, 1, 3, 1);
    graph_add_edge(dg, 2, 4, 1);
    graph_add_edge(dg, 4, 3, 1);

    graph_display(dg);

    assert(graph_has_edge(dg, 0, 1));
    assert(!graph_has_edge(dg, 1, 0));  /* directed */

    printf("\n");
    graph_bfs(dg, 0);
    graph_dfs(dg, 0);

    graph_destroy(dg);

    printf("\n✅ All graph tests passed!\n");
    return 0;
}
