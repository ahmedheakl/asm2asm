int issame(char** arr1, int n1, char** arr2, int n2){

  int i;
  if(n1 != n2) return 0;

  for(i=0; i<n1; i++){
    if(strcmp(arr1[i], arr2[i]) != 0) return 0;
  }

  return 1;

}

// Main function
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char** func0(char** arr1, int n1, char** arr2, int n2);

int main(){

  char* arr1[] = {};
  char* arr2[] = {};
  int n1 = 0, n2 = 0;
  issame(func0(arr1, n1, arr2, n2), n1, arr2, n2);

  char* arr3[] = {"hi", "admin"};
  char* arr4[] = {"hi", "hi"};
  n1 = 2; n2 = 2;
  issame(func0(arr3, n1, arr4, n2), n1, arr4, n2);

  char* arr5[] = {"hi", "admin"};
  char* arr6[] = {"hi", "hi", "admin", "project"};
  n1 = 2; n2 = 4;
  issame(func0(arr5, n1, arr6, n2), n1, arr5, n1);

  // Other test cases

  return 0;
}