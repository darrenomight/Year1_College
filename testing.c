#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define SIZETEAM 18
#define NAME_SIZE 64
#define LINE 3


//Combined names 
struct TeamMember
{
	char *FirstName[SIZETEAM];
	char *LastName[SIZETEAM];
	char *line[SIZETEAM];
}Workers[SIZETEAM];

struct Certification
{
    char *Employee[LINE];
    char *Line[LINE];
}ID[SIZETEAM];

//functions
void merge(char ** [2][NAME_SIZE], int , int , int );
void mergeSort(char **[2][NAME_SIZE], int , int );

int main()
{
	ID[0].Employee[LINE] = "001";
    ID[0].Line[LINE] = "1","0","0";
    Workers[0].FirstName[SIZETEAM] = "Julius";
    Workers[0].LastName[SIZETEAM] = "Leon";
    Workers[0].line[SIZETEAM] = "1";
    
	ID[1].Employee[LINE] = "002";
    ID[1].Line[LINE] = "0","2","3";
    Workers[1].FirstName[SIZETEAM] = "Marisela";
    Workers[1].LastName[SIZETEAM] = "Solomon";
    Workers[1].line[SIZETEAM] = "2";
    
	ID[2].Employee[LINE] = "003";
    ID[2].Line[LINE] = "1","2","3";
    Workers[2].FirstName[SIZETEAM] = "Lakenya";
    Workers[2].LastName[SIZETEAM] = "Sheryl";
    Workers[2].line[SIZETEAM] = "3";

	ID[3].Employee[LINE] = "004";
    ID[3].Line[LINE] = "1","2","3";
    Workers[3].FirstName[SIZETEAM] = "Paola";
    Workers[3].LastName[SIZETEAM] = "Simone";
    Workers[3].line[SIZETEAM] = "3";

	ID[4].Employee[LINE] = "005";
    ID[4].Line[LINE] = "1","2","3";
    Workers[4].FirstName[SIZETEAM] = "Eleni";
    Workers[4].LastName[SIZETEAM] = "Sterling";
    Workers[4].line[SIZETEAM] = "3";

	ID[5].Employee[LINE] = "006";
    ID[5].Line[LINE] = "1","2","3";
    Workers[5].FirstName[SIZETEAM] = "Gertha";
    Workers[5].LastName[SIZETEAM] = "Frances";
    Workers[5].line[SIZETEAM] = "3";

	ID[6].Employee[LINE] = "007";
    ID[6].Line[LINE] = "1","2","3";
    Workers[6].FirstName[SIZETEAM] = "Nigel";
    Workers[6].LastName[SIZETEAM] = "Emily";
    Workers[6].line[SIZETEAM] = "3";

	ID[7].Employee[LINE] = "008";
    ID[7].Line[LINE] = "1","2","3";
    Workers[7].FirstName[SIZETEAM] = "Kandice";
    Workers[7].LastName[SIZETEAM] = "Ana";
    Workers[7].line[SIZETEAM] = "3";

	ID[8].Employee[LINE] = "009";
    ID[8].Line[LINE] = "1","2","3";
    Workers[8].FirstName[SIZETEAM] = "Rima";
    Workers[8].LastName[SIZETEAM] = "Dwight";
    Workers[8].line[SIZETEAM] = "3";

	ID[9].Employee[LINE] = "010";
    ID[9].Line[LINE] = "1","2","3";
    Workers[9].FirstName[SIZETEAM] = "Garret";
    Workers[9].LastName[SIZETEAM] = "Darrell";
    Workers[9].line[SIZETEAM] = "3";

	ID[10].Employee[LINE] = "011";
    ID[10].Line[LINE] = "1","2","3";
    Workers[10].FirstName[SIZETEAM] = "Edison";
    Workers[10].LastName[SIZETEAM] = "Tanesha";
    Workers[10].line[SIZETEAM] = "3";

	ID[10].Employee[LINE] = "012";
    ID[10].Line[LINE] = "1","2","3";
    Workers[10].FirstName[SIZETEAM] = "Justine";
    Workers[10].LastName[SIZETEAM] = "Colin";
    Workers[10].line[SIZETEAM] = "3";

	ID[11].Employee[LINE] = "013";
    ID[11].Line[LINE] = "1","2","3";
    Workers[11].FirstName[SIZETEAM] = "Jeanie";
    Workers[11].LastName[SIZETEAM] = "Yolanda";
    Workers[11].line[SIZETEAM] = "3";
    
    ID[12].Employee[LINE] = "014";
    ID[12].Line[LINE] = "1","2","3";
    Workers[12].FirstName[SIZETEAM] = "Kimberley";
    Workers[12].LastName[SIZETEAM] = "Christal";
    Workers[12].line[SIZETEAM] = "3";

    ID[13].Employee[LINE] = "015";
    ID[13].Line[LINE] = "1","2","3";
    Workers[13].FirstName[SIZETEAM] = "Jasmine";
    Workers[13].LastName[SIZETEAM] = "Emmanuel";
    Workers[13].line[SIZETEAM] = "3";

	ID[15].Employee[LINE] = "016";
    ID[15].Line[LINE] = "1","2","3";
    Workers[15].FirstName[SIZETEAM] = "Federico";
    Workers[15].LastName[SIZETEAM] = "Daniella";
    Workers[15].line[SIZETEAM] = "3";

	ID[16].Employee[LINE] = "017";
    ID[16].Line[LINE] = "1","2","3";
    Workers[16].FirstName[SIZETEAM] = "Myong";
    Workers[16].LastName[SIZETEAM] = "Salvador";
    Workers[16].line[SIZETEAM] = "3";

	ID[17].Employee[LINE] = "018";
    ID[17].Line[LINE] = "1","2","3";
    Workers[17].FirstName[SIZETEAM] = "Reuben";
    Workers[17].LastName[SIZETEAM] = "Jacqueline";
    Workers[17].line[SIZETEAM] = "3";

}

  
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
  

  
