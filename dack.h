#ifndef DECK_H
#define DECK_H

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef NULL
#define NULL ((void *)0)
#endif

/**
 * enum kind_e - Represents the kinds of playing cards.
 * @SPADE: The "spade" playing card.
 * @HEART: The "heart" playing card.
 * @CLUB: The "club" playing card.
 * @DIAMOND: The "diamond" playing card.
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Represents a playing card.
 * @value: The value of the card (from "Ace" to "King").
 * @kind: The kind of the card.
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Represents a node in a deck of playing cards.
 * @card: A pointer to the card associated with the node.
 * @prev: A pointer to the previous node in the deck.
 * @next: A pointer to the next node in the deck.
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

/**
 * val_cmp - Performs a case-insensitive comparison of two strings.
 * @str1: The first string to compare.
 * @str2: The second string to compare.
 *
 * Return: The comparison value: -1 if str1 < str2, 1 if str1 > str2, 0 if equal.
 */
int val_cmp(const char *str1, const char *str2);

/**
 * card_key - Computes the sorting key of a playing card.
 * @card: A pointer to the playing card.
 *
 * Return: The key used to sort the card.
 */
int card_key(const card_t *card);

/**
 * swap_nodes - Swaps two nodes in a linked list.
 * @list: A pointer to the head of the linked list.
 * @l: The left node to swap.
 * @r: The right node to swap.
 */
void swap_nodes(deck_node_t **list, deck_node_t *l, deck_node_t *r);

/**
 * sort_deck - Sorts a deck of playing cards using the insertion sort algorithm.
 * @deck: A pointer to the deck of cards to sort.
 */
void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
