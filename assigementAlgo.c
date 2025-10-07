#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 6
#define NAME_SIZE 32
#define NAME_Amo 26

//Combined names 
struct ComName
{
    char FirstName[NAME_SIZE];
    char LastName[NAME_SIZE];
};


    const char workerlist1[6][2][NAME_SIZE]={
        "Julius","Leon",
        "Marisela","Solomon",
        "Lakenya","Sheryl",
        "Paola","Simone",
        "Eleni","Sterling",
        "Gertha","Frances"
    };

    const char workerlist2[6][2][NAME_SIZE]={
        "Nigel","Emily",
        "Kandice","Ana",
        "Rima","Dwight",
        "Garret","Darrell",
        "Edison","Tanesha",
        "Justine","Colin"
    };

    
    const char workerlist3[6][2][NAME_SIZE]={
        "Jeanie","Yolanda",
        "Kimberley","Christal",
        "Jasmine","Emmanuel",
        "Federico","Daniella",
        "Myong","Salvador",
        "Granville","Cecil"
    };

    const char workerlist4[6][2][NAME_SIZE]={
        "Reuben","Jacqueline",
        "Irina","Savanna",
        "Arnette","Lori",
        "Gaylord","Sidney",
        "Nilda","Giovanni",
        "Katelin","Tamra"
    };



//functions
void merge(char ** [2][NAME_SIZE], int , int , int );
void mergeSort(char **[2][NAME_SIZE], int , int );

int main()
{
    struct ComName employee[NAME_Amo];

    int i;
    int TempPlacement = (int)floor(NAME_Amo/4);

    //list1
    for (i = 0; i < SIZE; i++)
    {
        printf("%d %d %d %d\n",i,i+TempPlacement,i+2 * TempPlacement,i+3 * TempPlacement);

        strncpy(employee[i].FirstName,workerlist1[i][0],NAME_SIZE);
        strncpy(employee[i].LastName,workerlist1[i][1],NAME_SIZE);
    }
    //list2
    for ( i = 0; i < SIZE; i++)
    {
        strncpy(employee[i + TempPlacement].FirstName,workerlist2[i + TempPlacement][0],NAME_SIZE);
        strncpy(employee[i + TempPlacement].LastName,workerlist2[i + TempPlacement][1],NAME_SIZE);
    }

    //list3
    for ( i = 0; i < SIZE; i++)
    {
        strncpy(employee[i +2 * TempPlacement].FirstName,workerlist3[i + 2 * TempPlacement][0],NAME_SIZE);
        strncpy(employee[i +2 * TempPlacement].LastName,workerlist3[i + 2 * TempPlacement][1],NAME_SIZE);
    }

    //list4
    for ( i = 0; i < SIZE; i++)
    {
        strncpy(employee[i +3 * TempPlacement].FirstName,workerlist4[i + 3 * TempPlacement][0],NAME_SIZE);
        strncpy(employee[i +3 * TempPlacement].LastName,workerlist4[i + 3 * TempPlacement][1],NAME_SIZE);
    }
    
    for ( i = 0; i < NAME_Amo; i++)
    {
        printf("\nFirst Name: %s, Surname: %s",employee[i].FirstName,employee[i].LastName);
    }
    

    

    


}


/*
  
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(char ** arr[2][NAME_SIZE], int min, int mid, int max)
{
    int i, j, k;
    int n1 = mid - min + 1;
    int n2 = max - mid;
  
    // create temp arrays //
    char *Left[n1], *Right[n2];
  
    // Copy data to temp arrays L[] and R[] //
    for (i = 0; i < n1; i++)
        Left[i] = arr[min + i];
    for (j = 0; j < n2; j++)
        Right[j] = arr[mid + 1 + j];
  
    // Merge the temp arrays back into arr[l..r]//
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = min; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (Left[i] <= Right[j]) {
            *arr[k] = Left[i];
            i++;
        }
        else {
            *arr[k] = Right[j];
            j++;
        }
        k++;
    }
  
    // Copy the remaining elements of L[], if there are any //
    while (i < n1) {
        *arr[k] = Left[i];
        i++;
        k++;
    }
  
    // Copy the remaining elements of R[], if there are any 
    while (j < n2) {
        *arr[k] = Right[j];
        j++;
        k++;
    }
}

//l is for left index and r is right index of the sub-array of arr to be sorted //
void mergeSort(char** arr[2][NAME_SIZE], int min, int max)
{
    if (min < max) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int mid = min + (max - min) / 2;
  
        // Sort first and second halves
        mergeSort(arr, min, mid);
        mergeSort(arr, mid + 1, max);
  
        merge(arr, min, mid, max);
    }
}
  

  
*/