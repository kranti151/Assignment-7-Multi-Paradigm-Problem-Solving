/*
 * Statistics Calculator - C Implementation (Procedural Paradigm)
 * 
 * This program calculates mean, median, and mode of a list of integers
 * using a procedural approach with manual memory management.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compare integers for qsort
int compare_int(const void *a, const void *b) {
    int int_a = *((int*)a);
    int int_b = *((int*)b);
    
    if (int_a < int_b) return -1;
    if (int_a > int_b) return 1;
    return 0;
}

// Calculate the mean (average) of integers
double calculate_mean(int *arr, int size) {
    if (size == 0) {
        return 0.0;
    }
    
    long sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    
    return (double)sum / size;
}

// Calculate the median (middle value when sorted)
double calculate_median(int *arr, int size) {
    if (size == 0) {
        return 0.0;
    }
    
    // Create a copy of the array for sorting
    int *sorted = (int*)malloc(size * sizeof(int));
    if (sorted == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 0.0;
    }
    
    memcpy(sorted, arr, size * sizeof(int));
    qsort(sorted, size, sizeof(int), compare_int);
    
    double median;
    if (size % 2 == 0) {
        // Even number of elements: average of two middle values
        median = (sorted[size/2 - 1] + sorted[size/2]) / 2.0;
    } else {
        // Odd number of elements: middle value
        median = sorted[size/2];
    }
    
    free(sorted);
    return median;
}

// Calculate the mode (most frequently occurring value(s))
void calculate_mode(int *arr, int size, int **modes, int *mode_count) {
    if (size == 0) {
        *modes = NULL;
        *mode_count = 0;
        return;
    }
    
    // Create a copy and sort for easier counting
    int *sorted = (int*)malloc(size * sizeof(int));
    if (sorted == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        *modes = NULL;
        *mode_count = 0;
        return;
    }
    
    memcpy(sorted, arr, size * sizeof(int));
    qsort(sorted, size, sizeof(int), compare_int);
    
    // Find maximum frequency
    int max_freq = 1;
    int current_freq = 1;
    
    for (int i = 1; i < size; i++) {
        if (sorted[i] == sorted[i-1]) {
            current_freq++;
        } else {
            if (current_freq > max_freq) {
                max_freq = current_freq;
            }
            current_freq = 1;
        }
    }
    if (current_freq > max_freq) {
        max_freq = current_freq;
    }
    
    // Count how many modes we have
    *mode_count = 0;
    current_freq = 1;
    
    for (int i = 1; i < size; i++) {
        if (sorted[i] == sorted[i-1]) {
            current_freq++;
        } else {
            if (current_freq == max_freq) {
                (*mode_count)++;
            }
            current_freq = 1;
        }
    }
    if (current_freq == max_freq) {
        (*mode_count)++;
    }
    
    // Allocate memory for modes
    *modes = (int*)malloc((*mode_count) * sizeof(int));
    if (*modes == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        free(sorted);
        *mode_count = 0;
        return;
    }
    
    // Collect the modes
    int mode_index = 0;
    current_freq = 1;
    
    for (int i = 1; i < size; i++) {
        if (sorted[i] == sorted[i-1]) {
            current_freq++;
        } else {
            if (current_freq == max_freq) {
                (*modes)[mode_index++] = sorted[i-1];
            }
            current_freq = 1;
        }
    }
    if (current_freq == max_freq) {
        (*modes)[mode_index++] = sorted[size-1];
    }
    
    free(sorted);
}

// Print statistics
void print_statistics(int *arr, int size) {
    printf("\n=== Statistics Results ===\n");
    printf("Data: ");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("\n\n");
    
    // Calculate and print mean
    double mean = calculate_mean(arr, size);
    printf("Mean: %.2f\n", mean);
    
    // Calculate and print median
    double median = calculate_median(arr, size);
    printf("Median: %.2f\n", median);
    
    // Calculate and print mode
    int *modes = NULL;
    int mode_count = 0;
    calculate_mode(arr, size, &modes, &mode_count);
    
    printf("Mode: ");
    if (mode_count == 0) {
        printf("No mode\n");
    } else {
        // Calculate the actual frequency of mode values
        int mode_freq = 0;
        if (mode_count > 0 && modes != NULL) {
            for (int i = 0; i < size; i++) {
                if (arr[i] == modes[0]) {
                    mode_freq++;
                }
            }
        }
        
        for (int i = 0; i < mode_count; i++) {
            printf("%d", modes[i]);
            if (i < mode_count - 1) printf(", ");
        }
        printf(" (frequency: %d)\n", mode_freq);
    }
    
    if (modes != NULL) {
        free(modes);
    }
    printf("========================\n\n");
}

int main() {
    printf("Statistics Calculator - C Implementation\n");
    printf("========================================\n");
    
    // Example 1: Basic example
    int data1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(data1) / sizeof(data1[0]);
    print_statistics(data1, size1);
    
    // Example 2: With duplicates
    int data2[] = {1, 2, 2, 3, 3, 3, 4, 4, 5};
    int size2 = sizeof(data2) / sizeof(data2[0]);
    print_statistics(data2, size2);
    
    // Example 3: Even number of elements
    int data3[] = {10, 20, 30, 40};
    int size3 = sizeof(data3) / sizeof(data3[0]);
    print_statistics(data3, size3);
    
    // Example 4: Single mode
    int data4[] = {5, 5, 5, 2, 2, 1};
    int size4 = sizeof(data4) / sizeof(data4[0]);
    print_statistics(data4, size4);
    
    return 0;
}

