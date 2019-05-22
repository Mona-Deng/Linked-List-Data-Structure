/*
 * sllist is a sorted doubly-linked list.
 */
struct sllist;

/* 
 * list_create() creates and returns new (empty) sorted doubly-linked list.
 * effects: allocates heap memory (caller has to free with list_destroy(..))
 * time:    O(1)
 */
struct sllist *list_create(void);

/*
 * list_destroy(list) frees the memory allocated by [list].
 * effects: deallocates [list]
 * time:    O(n), where n is the length of [list]
 */
void list_destroy(struct sllist *list);

/* 
 * list_insert(list, value) adds [value] to [list]. [list] must remain sorted
 *   after inserting [value].
 * effects: mutates [list]
 * time:    O(n), where n is the length of [list]
 */
void list_insert(struct sllist *list, const int value);

/* 
 * list_remove(list, value) attempts to remove the first occurance of [value]
 *   from [list]. It returns true if [value] was removed from [list]; otherwise,
 *   it returns false.
 * effects: might mutate [list]
 * time:    O(n), where n is the length of [list]
 */
bool list_remove(struct sllist *list, const int value);

/*
 * list_print(list) writes out the content of [list] to standard output.
 * effects: modifies standard output
 * time:    O(n), where n is the length of [list]
 */
void list_print(const struct sllist *list);
