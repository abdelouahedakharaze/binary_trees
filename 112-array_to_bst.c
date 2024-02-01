#include "binary_trees.h"

/**
 * array_to_bst - Costruisce un Albero di Ricerca Binaria da un array
 *
 * @array: Puntatore al primo elemento dell'array da convertire
 * @size: Numero di elementi nell'array
 * Return: Puntatore al nodo radice dell'Albero di Ricerca Binaria creato,
 *         o NULL in caso di errore
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t lunghezza;
	bst_t *albero = NULL;

	for (lunghezza = 0; lunghezza < size; lunghezza++)
		bst_insert(&albero, array[lunghezza]);

	return (albero);
}
