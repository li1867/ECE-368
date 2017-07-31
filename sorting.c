#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sorting.h"
int power(int base, int temp);
int * sequence(int * length, int size);

long *Load_From_File(char * Filename, int *Size)
{
    FILE * fp = fopen(Filename, "rb");
    if(fp == NULL)
    {
        return NULL;
    }
    fseek(fp, 0, SEEK_END);
    *Size = ftell(fp) / sizeof(long);
    if(*Size == 0)
    {
        return NULL;
    }
    
    long * array = malloc(sizeof(long) * (*Size));
    int num = 0;
    fseek(fp, 0, SEEK_SET);
    num = fread(array, sizeof(long), *Size, fp);
    if(num != *Size)
    {
        fclose(fp);
        return NULL;
    }
    fclose(fp);
    
    return array;
}

int Save_To_File(char * Filename, long * Array, int Size)
{
    FILE * fp = fopen(Filename, "wb");
    if(fp == NULL)
    {
        fclose(fp);
        return 0;
    }
    int num = 0;
    fseek(fp, 0, SEEK_SET);
    num = fwrite(Array, sizeof(long), Size, fp);
    if(num != Size)
    {
        fclose(fp);
        return 0;
    }
    fclose(fp);
    
    return num;
}

int power(int base, int temp)
{
    int count = 1;
    int result = 1;
    if(temp == 0)
    {
        return result;
    }
    else
    {
        while(count <= temp)
        {
            result *= base;
            count++;
        }
    }
    return result;
}

int * sequence(int * length, int size)
{
    if(size == 0)
    {
        return NULL;
    }
    if(size == 1)
    {
        return NULL;
    }
    
    int last_num = 2;
    int height = 0;
    while(last_num < size)
    {
        last_num = last_num * 2;
        height++;
    }
    
    int * seq = malloc(sizeof(*seq) * 1);
    int i, p, q;
    
    for(i = 0; i <= height; i++)
    {
        p = i;
        q = 0;
        
        while(p >= 0)
        {
            int num = power(2 , p) * power(3, q);
           
            if(num < size)
            {
                if(*length == 0)
                {
                    seq[*length] = num;
                }
                else{
                    seq = realloc(seq, sizeof(*seq) * (*length+1));
                    seq[*length] = num;
                }
                (*length)++;
                p = p - 1;
                q = q + 1;
            }
            else{
                break;
            }
        }
    }
    
    return seq;
}

void Shell_Insertion_Sort(long * Array, int Size, double * N_Comp, double * N_Move)
{
    int length = 0;  //length of seq
    int * seq = sequence(&length, Size);
    
    int in;
    int k;
    in = length - 1;
	
	for (int m = in; m >=0; m--){
		int k = seq[m];
		for (int j = k; j <= Size-1; j++){
			int temp_r = Array[j];
			int i = j;
			while (i >= k && Array[i-k] > temp_r){
				Array[i] = Array[i-k];
				i = i - k;
			}
			Array[i] = temp_r;
		}
	}

    free(seq);
}

void Shell_Selection_Sort(long * Array, int Size, double * N_Comp, double * N_Move)
{
	int length = 0;
	int * seq = sequence(&length, Size);
	int in = length - 1;

	for(int m = in; m >= 0; m--)
	{
		//int k = seq[m];
		
		int k = seq[m];
		for(int j = 0; j < (Size - k); j++)
		{
			int temp = j;
			int z = j + k;
			if(Array[temp] > Array[z])
			{
				temp = z;
			}
			(*N_Comp)++;
			int temp1 = Array[j];
			(*N_Move)++;
			Array[j] = Array[temp];
			(*N_Move)++;
			Array[temp] = temp1;
			(*N_Move)++;
		}
	}
	free(seq);
}

int Print_Seq(char* Filename, int Size)
{
    if(Size == 0 || Size == 1)
    {
        return 0;
    }
    
    FILE * fp = fopen(Filename, "w");
    int length = 0;
    int * seq = sequence(&length, Size);
    int ct = 0;
    while(ct < length)
    {
        fprintf(fp, "%d\n", seq[ct]);
        ct++;
    }
    
    fclose(fp);
    free(seq);
    
    return length;
}












