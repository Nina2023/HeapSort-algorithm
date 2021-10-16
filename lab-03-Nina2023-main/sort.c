// -----------------------------------
// COMP 211
//
// -----------------------------------
// PID: 730334594
// I pledge the COMP211 honor code.

// ----------------------------------------------
// These are the only libraries that can be 
// used. Under no circumstances can additional 
// libraries be included
#include <stdio.h>	// IO functions
#include <stdlib.h> // atof function
#include <math.h>	// math functions
#include <string.h>	// string functions
#include "sort.h"	// your own functions

// DO NOT MODIFY: Swaps position of two v_structs in an array.
void swap (v_struct* p1, v_struct* p2) {
  v_struct  temp = *p1;
  *p1 = *p2;
  *p2 = temp;
  p1->count++;
  p2->count++;
}

// DO NOT MODIFY: Prints the contents of each v_struct in an array; used for grading.
void print_array(v_struct* v_array, int array_length) {
   for(int i = 0; i < array_length; i++) {
      printf("[priority: %d value: %d count: %d]\n", v_array[i].priority, v_array[i].value, v_array[i].count);
   }
}

// PART 1: HEAPIFICATION

// TO-DO: Sort array such that values form a maximum heap.
void max_heapify_value( v_struct* v_array, int array_length){
	int n = array_length;

	
	for (int i = floor((n-2)/2); i >= 0; i--)
	 {
	 	int k = i;
	 	int v = v_array[k].value;
	 	int heap = 1;
	 	 while(heap == 1 && 2*k +2 <= n) {
	 	 	int j = 2*k+1;
	 	 	if( j+1 < n){
	 	 		if(v_array[j].value <  v_array[j+1].value){
	 				j++;
	 	 		}
	 	 	}
          
	 	 	if( v >= v_array[j].value){
	 	 	heap = 0;
            } else {
	 	   swap(&v_array[k],&v_array[j]);
             k = j;
	 	 	}
	 	 	v_array[k].value  = v;
	 	 }

	}
}

// TO-DO: Sort array such that values form a minimum heap.
void min_heapify_value( v_struct* v_array, int array_length ) {
int n = array_length;

	
	for (int i = floor((n-2)/2); i >= 0; i--)
	 {
	 	int k = i;
	 	int v = v_array[k].value;
	 	int heap = 1;
	 	 while(heap == 1 && 2*k +2 <= n) {
	 	 	int j = 2*k+1;
	 	 	if( j+1 < n){
	 	 		if(v_array[j].value >  v_array[j+1].value){
	 	 			j++;
	 	 		}
	 	 	}
	 	 	if( v <= v_array[j].value){
	 	 		heap = 0;
	 	 	} else {
	 	 		swap(&v_array[k],&v_array[j]);
	 	 		k = j;
	 	 	}
	 	 	v_array[k].value = v;
	 	 }

	}
}

// TO-DO: Sort array such that priorities form a maximum heap.
void max_heapify_priority( v_struct* v_array, int array_length ) {
int n = array_length;

	
	for (int i = floor((n-2)/2); i >= 0; i--)
	 {
	 	int k = i;
	 	unsigned int v = v_array[k].priority;
	 	int heap = 1;
	 	 while(heap == 1 && 2*k +2 <= n) {
	 	 	int j = 2*k+1;
	 	 	if( j+1 < n){
	 	 		if(v_array[j].priority < v_array[j+1].priority){
	 	 			j++;
	 	 		}
	 	 	}
	 	 	if( v >= v_array[j].priority){
	 	 		heap = 0;
	 	 	} else {
	 	 		swap(&v_array[k],&v_array[j]);
	 	 		k = j;
	 	 	}
	 	 	v_array[k].priority = v;
	 	 }

	}
	
}

// TO-DO: Sort array such that priorities form a minimum heap.
void min_heapify_priority( v_struct* v_array, int array_length ) {
	int n = array_length;

	
	for (int i = floor((n-2)/2); i >= 0; i--)
	 {
	 	int k = i;
	 	unsigned int v = v_array[k].priority;
	 	int heap = 1;
	 	 while(heap == 1 && 2*k +2 <= n) {
	 	 	int j = 2*k+1;
	 	 	if( j+1 < n){
	 	 		if(v_array[j].priority > v_array[j+1].priority){
	 	 			j++;
	 	 		}
	 	 	}
	 	 	if( v <= v_array[j].priority){
	 	 		heap = 0;
	 	 	} else {
	 	 		swap(&v_array[k],&v_array[j]);
	 	 		k = j;
	 	 	}
	 	 	v_array[k].priority = v;
	 	 }

	}
}

// PART 2: HEAPSORT

// ------------------------------------
// Function prototype
// description: sort (using heap sort algo) the array using value field 
// return:
//	 error code: -1=error or 0=no error
// arguments:
//	 sort_type = "ascend" or "descend"
// 	 v_struct* = array 
//   array_length = number of v_struct elements in array

int sort_value( char* sort_type, v_struct* v_array, int array_length ) {
	int n = array_length;
  	char* ascend = "ascend";
  	char* descend = "descend";
  	int is_ascend_one;
  	int is_descend_one;
  	is_ascend_one = strncmp(sort_type, ascend, n);
  	is_descend_one = strncmp(sort_type,descend, n);



  	if(is_descend_one != 0 && is_ascend_one != 0 ){
  		return -1;
  	}

  	if(is_ascend_one == 0){
        while(n > 1){
        max_heapify_value(v_array, n);
  			swap(&v_array[0],&v_array[n-1]);
  			n--;

  			}
  		}

 
	if(is_descend_one == 0 ){
		while(n > 1){
  			min_heapify_value(v_array, n);
  			swap(&v_array[0],&v_array[n-1]);
  			n--;

  			}

	}

	return 0;}

// ------------------------------------
// Function prototype
// description: sort (using heap sort algo) the array using priority field
// return:
//	 error code: -1=error or 0=no error)
// arguments:
//	 sort_type = "ascend" or "descend"
// 	 v_struct* = array 
//   array_length = number of v_struct elements in array

int sort_priority( char* sort_type, v_struct* v_array, int array_length ) {
 	int n = array_length;
  	char* ascend = "ascend";
  	char* descend = "descend";
  	int is_ascend_one;
  	int is_descend_one;
  	is_ascend_one = strncmp(sort_type, ascend, n);
  	is_descend_one = strncmp(sort_type,descend, n);



  	if(is_descend_one != 0 && is_ascend_one != 0 ){
  		return -1;
  	}

  	if(is_ascend_one == 0){

  		while(n > 1){
  			max_heapify_priority(v_array, n);
  			swap(&v_array[0],&v_array[n-1]);
  			n--;

  			}
  		}

 
	if(is_descend_one == 0 ){
		while(n > 1){
  			min_heapify_priority(v_array, n);
  			swap(&v_array[0],&v_array[n-1]);
  			n--;

  			}

	}

	return 0;}
