#include<iostream>
using namespace std;


void Bubblesort(int arr[], int size){
 for(int i=0; i<size-1; i++){
    for(int j=0; j<size-i-1; j++){
           if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
    }
 }
};

void Bubble(int arr[], int size){
 for(int i=0; i<size-1; i++){
    for(int j=0; j<size-i-1; j++){
           if(arr[j] < arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
    }
 }
};

void magicSorter(int arr[], int size){

    int evennum[20];
    int oddnum[20];
    int temp[20];

    int e = 0, o = 0, k = 0;

    for(int i=0; i<size; i++){
        if(arr[i] % 2 == 0){
            evennum[e++] = arr[i];
        }
        else{
            oddnum[o++] = arr[i];
        }
    }


    Bubblesort(evennum, e); 
    Bubble(oddnum, o);      

    for(int i=0; i<e; i++){
        temp[k++] = evennum[i];
    }
    for(int i=0; i<o; i++){
        temp[k++] = oddnum[i];
    }
    for(int i=0; i<size; i++){
        arr[i] = temp[i];
    }
}




int main(){

    // Question - 1
  int arr[] = {10,20,30,40,20,5,10};
  int length = sizeof(arr)/ sizeof(arr[0]);

    for(int i = 0; i< length; i++){
         for(int j = i+1; j< length;){
            if(arr[i] == arr [j]){
                 for(int k = j; k< length; k++){
                    arr[k] = arr[k+1];
                 }
                 length--;
            }
            else{
                j++;
            }
          }
    }

  for(int i=0; i<length; i++){
    cout << arr[i] << " ";
  }

//Question - 2
   int array[] = {9,55,30,21,40,5,90,35};
  int arrsize = sizeof(array) / sizeof(array[0]);
  int largest = 0;
  int secondlarge = 0;
  for(int i=0; i<arrsize; i++){
    if(array[i] > largest){
      largest = array[i];
    }
    else{
      continue;
    }
  }

   for(int i=0; i<arrsize; i++){
    if(array[i] > secondlarge && array[i] < largest){
      secondlarge = array[i];
    }
    else{
      continue;
    }
  }
  
  
  cout << "\n Largest Element is : " << largest<<endl;
  cout << " Second Largest Element is : " << secondlarge<<endl;


// Question-3
   int arr1[] = {9,55,30,21,40,5,90,35};
  int size = sizeof(arr1) / sizeof(arr1[0]);
  Bubblesort(arr1, size);
  cout  << " Ascending Order : " ;
  for(int i=0; i<size; i++){
    cout << arr1[i] << " ";
  } 

  Bubble(arr1, size);
    cout << endl << " Descending Order : " ;

   for(int i=0; i<size; i++){
    cout << arr1[i] << " ";
  }


// Question -4
  int arr2[] = {10,50,-30,20,-40,-5,90,35};
  int size1 = sizeof(arr1) / sizeof(arr1[0]);
  int positive=0;
  int negative =0;

  for(int i=0; i<size1; i++){
    if(arr2[i] < 0){
      negative++;
    }
    else if (arr2[i] >= 0){
      positive++;
    }
   
  }
  cout<<endl << "Positive values are : " << positive << endl;
  cout << "Negative values are : " << negative << endl;

// Ouestion-5
    int arr3[] = {9,55,30,21,40,5,90,35};
    int size2 = sizeof(arr3)/sizeof(arr3[0]);

    magicSorter(arr3, size2);

    for(int i=0; i<size2; i++){
        cout << arr3[i] << " ";
    }
    }
