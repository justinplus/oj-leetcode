#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
  for( int i = 0; i < matrixRowSize; i++ ){
    if( target <= matrix[i][matrixColSize - 1] ){
      for( int j=0; j < matrixColSize; j++ ){
        if( matrix[i][j] == target )
          return true;
        else if( matrix[i][j] > target )
          return false;
      }
      return false;
    }
  }
  return false;
} 

/* WA: [[1]], 1 */
bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
  for( int i = 0; i < matrixRowSize; i++ ){
    if( target <= *((int*)matrix + (i+1)*matrixColSize - 1) ){
      for( int j=0; j < matrixColSize; j++ ){
        if( *((int*)matrix + i*matrixColSize + j) == target )
          return true;
        else if( *((int*)matrix + i*matrixColSize + j) > target )
          return false;
      }
      return false;
    }
  }
  return false;
} 

/* TODO: int *, int *[], int (*)[], int **
 * 
 * To comprehend the differences??
 */

