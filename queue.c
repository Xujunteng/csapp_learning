/* 
 * Code for basic C skills diagnostic.
 * Developed for courses 15-213/18-213/15-513 by R. E. Bryant, 2017
 */

/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a singly-linked list to represent the set of queue elements
 */

#include <stdlib.h>
#include <stdio.h>

#include "queue.h"

/*
  Create empty queue.
  Return NULL if could not allocate space.
*/
queue_t *q_new()
{
	queue_t *q = calloc(1, sizeof(queue_t));
	if (q == NULL) {
		return NULL;
	}
	return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
	if (q == NULL) {
		return;
	}

	list_ele_t *p = q->head;
	while (p != NULL) {
		list_ele_t *next = p->next;
		free(p);
		p = next;
	}

	free(q);
}

/*
  Attempt to insert element at head of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
 */
bool q_insert_head(queue_t *q, int v)
{	
	if (q == NULL) {
		return false;
	}

	list_ele_t *p = malloc(sizeof(list_ele_t));
	if (p == NULL) {
		return false;
	}

	p->value = v;
	p->next = q->head;
	q->head = p;
	if (q->size == 0) {
		q->tail = p;
	}
	q->size += 1;
	return true;
}


/*
  Attempt to insert element at tail of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
 */
bool q_insert_tail(queue_t *q, int v)
{
	if (q == NULL) {
		return false;
	}

	list_ele_t *p = malloc(sizeof(list_ele_t));
	if (p == NULL) {
		return false;
	}

	p->value = v;
	p->next = NULL;
	if (q->size == 0) {
		q->head = p;
		q->tail = p;
	} else {
		q->tail->next = p;
		q->tail = p;
	}
	q->size += 1;

	/* Remember: It should operate in O(1) time */
	return true;
}
/*
  Attempt to remove element from head of queue.
  Return true if successful.
  Return false if queue is NULL or empty.
  If vp non-NULL and element removed, store removed value at *vp.
  Any unused storage should be freed
*/
bool q_remove_head(queue_t *q, int *vp)
{
	if (q == NULL || q->size == 0) {
		return false;
	}

	list_ele_t *p = q->head;
	q->head = p->next;
	if (vp != NULL) {
		*vp = p->value;
	}
	free(p);
	q->size -= 1;
	if (q->size == 0) {
		q->tail = NULL;
	}
	return true;
}

/*
  Return number of elements in queue.
  Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    /* Remember: It should operate in O(1) time */
	if (q == NULL) {
		return 0;
	}
	return q->size;
}

/*
  Reverse elements in queue.

  Your implementation must not allocate or free any elements (e.g., by
  calling q_insert_head or q_remove_head).  Instead, it should modify
  the pointers in the existing data structure.
 */
void q_reverse(queue_t *q)
{
	if (q == NULL || q->size <= 1) {
		return;
	}

	list_ele_t *prev = NULL;
	list_ele_t *cur = q->head;
	q->tail = q->head;
	while (cur != NULL) {
		list_ele_t *next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	q->head = prev;
}

