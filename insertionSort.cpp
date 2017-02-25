#include <iostream>
#include <stdlib.h>

using namespace std;

void insertionSort(int array[],int size){
  for(int i=1; i<size; i++){
    int j=i;
    while(j>0 && array[j]<array[j-1]){
      array[j]^=array[j-1];
      array[j-1]^=array[j];
      array[j]^=array[j-1];
      j--;
    }
  }
}


int main(){
  int size=20;
  int array[size];
  for(int i=0; i<size; i++){
    array[i]=rand()%20+1;
  }
  for(int i=0; i<size; i++){
    cout<<array[i]<<" ";
  }
  cout<<endl;
  insertionSort(array,size);
  for(int i=0; i<size; i++){
    cout<<array[i]<<" ";
  }
  return 0;
}