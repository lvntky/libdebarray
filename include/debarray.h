/**
 * @file debarray.h
 * @brief debarray — Public API
 *
 * A C99 library for debugging and visualizing arrays in the terminal.
 *
 * @example
 * @code
 *   #include <debarray.h>
 *   deb_print(arr, len, DEB_INT);
 *   deb_stats(arr, len, DEB_INT);
 *   deb_histogram(arr, len, DEB_INT);
 * @endcode
 */

#ifndef DEBARRAY_H_
#define DEBARRAY_H_

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Supported element types for debarray functions.
 *
 * Pass one of these tags alongside your @c void* pointer so debarray
 * knows how to interpret the raw memory.
 */
typedef enum {
    DEB_INT,    /**< Interpret array as @c int[]    */
    DEB_LONG,   /**< Interpret array as @c long[]   */
    DEB_FLOAT,  /**< Interpret array as @c float[]  */
    DEB_DOUBLE  /**< Interpret array as @c double[] */
} deb_type_t;

/**
 * @brief Dump every element of an array to stdout with its index.
 *
 * @param arr   Pointer to the first element of the array.
 * @param len   Number of elements in the array.
 * @param type  Type tag describing the element type (@see deb_type_t).
 */
void deb_print(const void *arr, size_t len, deb_type_t type);

/**
 * @brief Print a statistics summary of an array to stdout.
 *
 * Computes and displays the following metrics:
 * - Count
 * - Minimum and maximum
 * - Sum
 * - Mean
 * - Median
 * - Standard deviation
 *
 * @param arr   Pointer to the first element of the array.
 * @param len   Number of elements in the array.
 * @param type  Type tag describing the element type (@see deb_type_t).
 */
void deb_stats(const void *arr, size_t len, deb_type_t type);

/**
 * @brief Render an ANSI-colored horizontal bar chart of an array to stdout.
 *
 * Bar widths scale automatically to the current terminal width.
 * Each bar is color-coded relative to the value range of the array.
 *
 * @param arr   Pointer to the first element of the array.
 * @param len   Number of elements in the array.
 * @param type  Type tag describing the element type (@see deb_type_t).
 */
void deb_histogram(const void *arr, size_t len, deb_type_t type);

#ifdef __cplusplus
}
#endif

#endif /* DEBARRAY_H_ */
