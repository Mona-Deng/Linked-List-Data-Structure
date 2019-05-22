#include <stdbool.h>

/*
 * llist is a doubly-linked list.
 */
struct llist;

/* 
 * list_create() creates and returns new (empty) doubly-linked list.
 * effects: allocates heap memory (caller must free by calling list_destroy)
 * time:    O(1)
 */
struct llist *list_create(void);

/*
 * list_destroy(list) frees the memory allocated by [list].
 * effects: deallocates [list]
 * time:    O(n), where n is the length of [list]
 */
void list_destroy(struct llist *list);

/* 
 * list_insert_front(list, value) adds [value] to the front of [list].
 * effects: mutates [list]
 * time:    O(1)
 */
void list_insert_front(struct llist *list, const int value);

/* 
 * list_insert_back(list, value) adds [value] to the back of [list].
 * effects: mutates [list]
 * time:    O(1)
 */
void list_insert_back(struct llist *list, const int value);

/* 
 * list_remove_front(list, value) stores the value of the first node of [list]
 *   in [value] and than removes the node from [list]. It returns true if
 *   [list] was not empty before the removal; otherwise, it returns false.
 *   and leaves [value] unchanged.
 * effects: might mutate [list]
 *          might mutate [value]
 * time:    O(1)
 */
bool list_remove_front(struct llist *list, int *value);

/* 
 * list_remove_back(list, value) stores the value of the last node of [list] in
 *   [value] and than removes the node from [list]. It returns true if [list]
 *   was not empty before the removal; otherwise, it returns false and leaves
 *   [value] unchanged.
 * effects: might mutate [list]
 *          might mutate [value]
 * time:    O(1)
 */
bool list_remove_back(struct llist *list, int *value);

/* 
 * list_remove_occ_first(list, value) attempts to remove the first occurance of
 *   [value] from [list]. It returns true if [value] was removed from [list];
 *   otherwise, it returns false.
 * effects: might mutate [list]
 * time:    O(n), where n is the length of [list]
 */
bool list_remove_occ_first(struct llist *list, int value);

/* 
 * list_remove_occ_last(list, value) attempts to remove the last occurance of
 *   [value] from [list]. It returns true if [value] was removed from [list];
 *   otherwise, it returns false.
 * effects: might mutate [list]
 * time:    O(n), where n is the length of [list]
 */
bool list_remove_occ_last(struct llist *list, int value);

/*
 * list_print(list, reverse) writes out the content of [list] to standard
 *   output. If [reverse] is false, [list] is written front to back; if
 *   [reverse] is true, [list] is written back to front.
 * effects: modifies standard output
 * time:    O(n), where n is the length of [list]
 */
void list_print(const struct llist *list, bool reverse);
