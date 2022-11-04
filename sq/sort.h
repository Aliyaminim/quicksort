#pragma once

unsigned partition(int *arr, unsigned low, unsigned high);

void qsort_impl(int *arr, unsigned low, unsigned high);

void qsort(int *arr, unsigned len);
