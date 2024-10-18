#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** func0(char** arr1, int n1, char** arr2, int n2){

  int i, sum1 = 0, sum2 = 0;

  for(i=0; i<n1; i++){
    sum1 += strlen(arr1[i]);
  }
  
  for(i=0; i<n2; i++){
    sum2 += strlen(arr2[i]); 
  }

  if(sum1 < sum2){
    return arr1;
  }
  else if(sum1 > sum2){
    return arr2;
  }
  else{
    return arr1;
  }

}
