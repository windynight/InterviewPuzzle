/*
 Print all the permutations of a string (Or of an array)
 Using BackTrack Algorithm
 */

# include <stdio.h>

/* Function to swap values at two pointers */
void swap (char *x, char *y) {
  char temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

/* Function to print permutations of string
 This function takes three parameters:
 1. String
 2. Starting index of the string
 3. Ending index of the string. */
int count = 0;
void permute(char *a, int i, int size) 
{
  if (i == size) {
    printf("%d : %s\n", count ++, a);
  } else {
    for (int j = i; j < size; j++) {
      swap((a+i), (a+j));
      permute(a, i+1, size);
      swap((a+i), (a+j)); //backtrack
    }
  }
} 

/* Driver program to test above functions */
int main() {
  char a[] = "ABCDEFG";  
  permute(a, 0, 7);
  getchar();
  return 0;
}
