# =============================================================================
# Data Structures in C — Root Makefile
# =============================================================================

CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -std=c99 -g

# -----------------------------------------------------------------------------
# Targets
# -----------------------------------------------------------------------------

.PHONY: all linked_list stack queue bst hashmap graph sorting clean

all: linked_list stack queue bst hashmap graph sorting

# --- Linked List -------------------------------------------------------------
linked_list:
	$(CC) $(CFLAGS) \
		linked_list/linked_list.c \
		linked_list/main.c \
		-o linked_list/linked_list_test

# --- Stack -------------------------------------------------------------------
stack:
	$(CC) $(CFLAGS) \
		stack/stack.c \
		stack/main.c \
		-o stack/stack_test

# --- Queue -------------------------------------------------------------------
queue:
	$(CC) $(CFLAGS) \
		queue/queue.c \
		queue/main.c \
		-o queue/queue_test

# --- Binary Search Tree ------------------------------------------------------
bst:
	$(CC) $(CFLAGS) \
		binary_search_tree/bst.c \
		binary_search_tree/main.c \
		-o binary_search_tree/bst_test

# --- Hash Map ----------------------------------------------------------------
hashmap:
	$(CC) $(CFLAGS) \
		hashmap/hashmap.c \
		hashmap/main.c \
		-o hashmap/hashmap_test

# --- Graph -------------------------------------------------------------------
graph:
	$(CC) $(CFLAGS) \
		graph/graph.c \
		graph/main.c \
		-o graph/graph_test

# --- Sorting Algorithms ------------------------------------------------------
sorting:
	$(CC) $(CFLAGS) \
		sorting/sorting.c \
		sorting/main.c \
		-o sorting/sorting_test

# --- Clean -------------------------------------------------------------------
clean:
	rm -f linked_list/linked_list_test
	rm -f stack/stack_test
	rm -f queue/queue_test
	rm -f binary_search_tree/bst_test
	rm -f hashmap/hashmap_test
	rm -f graph/graph_test
	rm -f sorting/sorting_test
