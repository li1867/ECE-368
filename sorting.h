//
//  sorting.h
//  PA01
//
//  Created by LIPeiyuan on 6/19/17.
//  Copyright © 2017 LIPeiyuan. All rights reserved.
//

#ifndef sorting_h
#define sorting_h

#include <stdio.h>
long* Load_From_File(char* Filename, int* size);
int Save_To_File(char * Filename, long * Array, int Size);
void Shell_Insertion_Sort(long * Array, int Size, double *N_Comp, double *N_Move);
int Print_Seq(char * Filename, int size);
void Shell_Selection_Sort(long * Array, int Size, double * N_Comp, double * N_Move);
#endif /* sorting_h */
