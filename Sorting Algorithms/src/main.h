#ifndef MAIN_H
#define MAIN_H
#ifdef _WIN32
    #define clean "cls"
#elif __linux__
    #define clean "clear"
#endif

#include "Headers/product.h"
#include "Headers/fill_print.h"
#include "Headers/auxiliar_functions.h"
#include "Headers/bubblesort.h"
#include "Headers/insertionsort.h"
#include "Headers/selectionsort.h"
#include "Headers/selectionsortRec.h"
#include "Headers/quicksort.h"
#include "Headers/quick3.h"
#include "Headers/shellsort.h"
#include "Headers/mergesort.h"
#include "Headers/countingsort.h"
#include "Headers/bucketsort.h"
#include "Headers/combsort.h"
#include "Headers/pancakesort.h"
#include "Headers/heapsort.h"
#include "Headers/cocktailsort.h"
#include "Headers/stoogesort.h"
#include "Headers/bogosort.h"

#endif