#include    <stdio.h>
#include    <assert.h>
#include    <stdlib.h>
#include    <time.h>
#include    <string.h>
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
//#ifdef _WIN32
//#include <Windows.h>
//#else
//#include <unistd.h>
//#endif

#define     MAX_TEAM_SIZE       20
#define     MIN_TEAM_SIZE       10
#define     TOTAL_NUM_LINES     3
#define     TOTAL_NUM_TEAMS     4
#define     NAME_SIZE           14
#define     LINES_COUNT         3
#define     fatass              unsigned int
#define     mint                unsigned __int8
#define     true                1
#define     false               0
#define     SLEEP               _sleep
#define     STEP                /*printf(".");_sleep(10);*/

#define     How_many_random_names_have_been_made    360



typedef enum {FIRST_NAME, LAST_NAME} NAME_TYPE;



typedef struct CERTIFICATE
{
    unsigned short  EMPLOYEE_ID;
    mint            ASSOSIATED_LINE;
} CERTIFICATE;

typedef struct  EMPLOYEE
{
    char                    prenom[NAME_SIZE];
    char                    nom[NAME_SIZE];
    mint                    Held_Certificate_Count;
    CERTIFICATE             Certificates[LINES_COUNT];
    unsigned short          ID;
} EMPLOYEE;

typedef struct TEAM
{
    mint                    How_Many_Members;
    EMPLOYEE                Employees[MAX_TEAM_SIZE];
    mint                    Line_We_Do_Be_Working_On;
} TEAM;



    
///////  PASSED CHECK, WORKS ///////
void Generate_Random_Name(char*, NAME_TYPE);
////////////////////////////////////
    



///////  PASSED CHECK, WORKS ///////
void Generate_Random_Team_Data (TEAM*, mint, mint);
void test_random_team_func(TEAM*, mint, mint);
////////////////////////////////////


/*
void Merge(char* arr[],int low,int mid,int high) //Merging the Array Function
{
    int left_size = mid - (low + 1);
    int nR = high - mid;

    char** L = malloc( sizeof(char *) * left_size );
    char** R = malloc( sizeof(char *) * nR );

    
    for(int i = 0;      i<left_size;   i++)
    {
        L[i]=malloc(sizeof(arr[low+i]));
        strcpy(L[i],arr[low+i]);
    }

    for(int i = 0;      i<nR;   i++)
    {
        R[i]=malloc(sizeof(arr[mid+i+1]));
        strcpy(R[i],arr[mid+i+1]);
    }

    int rPoint = 0;
    int lPoint = 0;
    int k = low;

    while(  (lPoint < left_size)    &&    (rPoint < nR) )
    {
        if(strcmp(L[lPoint],R[rPoint])<0)
        {
            strcpy(arr[k++],L[lPoint++]);
        }
        else 
        {
            strcpy(arr[k++],R[rPoint++]);
        }
    }

    while( lPoint < left_size )
    {
        strcpy(arr[k++],L[lPoint++]);
    }

    while( rPoint < nR )
    {
        strcpy(arr[k++],R[rPoint++]);
    }
}
void Merge2(EMPLOYEE* arr[],int low,int mid,int high) //Merging the Array Function
{
    int left_size = mid - (low + 1);
    int nR = high - mid;

    //printf("\nHey, left and right size is d and &d\n",left_size,nR);
    
    EMPLOYEE** L = malloc( sizeof(EMPLOYEE*) * left_size );
    EMPLOYEE** R = malloc( sizeof(EMPLOYEE*) * nR );
    
    for(int i = 0;      i<left_size;   i++)
    {
        L[i] = arr[low+i];
    }

    for(int i = 0;      i<nR;   i++)
    {
        R[i] = arr[mid+i+1] ;
    }

    int rPoint = 0;
    int lPoint = 0;
    int k = low;

    while(  (lPoint < left_size)    &&    (rPoint < nR) )
    {
        if(strcmp( L[lPoint]->nom, R[rPoint]->nom ) < 0)
        {
            arr[k++] = L[lPoint++];
        }
        else 
        {
            arr[k++] = R[rPoint++];
        }
    }

    //while( lPoint < left_size )
    //{
    //    arr[k++] = L[lPoint++];
    //}

    //while( rPoint < nR )
    //{
    //    arr[k++] = R[rPoint++];
    //}
}
void MergeSort(char* arr[],int low,int high) //Main MergeSort function
{
    if(low<high)
    {
        int mid=(low+high)/2;
        MergeSort(arr,low,mid);
        MergeSort(arr,mid+1,high);
        Merge(arr,low,mid,high);
    }
}
void MergeSort2(EMPLOYEE* arr[],int low,int high) //Main MergeSort function
{
    if(low<high)
    {
        int mid=(low+high)/2;
        MergeSort2(arr,low,mid);
        MergeSort2(arr,mid+1,high);
        Merge2(arr,low,mid,high);
    }
}
void Combine(char**, fatass, fatass, fatass);
*/


void ShitMerge(EMPLOYEE[], int, int, int);

void ShitSort(EMPLOYEE everyone[], int left, int right)
{
    if (left < right)
    {
        int middle = left + (right-left) / 2;
        
        ShitSort(everyone, left, middle);
        ShitSort(everyone, (middle+1), right);

        ShitMerge(everyone, left, middle, right);
    }
}

void ShitMerge(EMPLOYEE everyone[], int left, int middle, int right)
{
    int i,j,k;
    int left_size = middle - left + 1;
    int right_size = right - middle;

    
    EMPLOYEE *leftARR = malloc(sizeof(EMPLOYEE) * left_size);
    EMPLOYEE *rightARR = malloc(sizeof(EMPLOYEE) * right_size);

    if(leftARR == NULL || rightARR == NULL)
    { 
        printf("\nFUCK\n");
    }
    for (i = 0; i < left_size; i++)
    {
        leftARR[i] = everyone[left+i];
    }

    for (j = 0; j < right_size; j++)
    {
        rightARR[j] = everyone[middle + 1 + j];
    }
    
    i = j = 0;
    k = 0; 
    while (i < left_size && j < right_size)
    {
        if (strcmp(leftARR[i].nom, rightARR[j].nom) < 0 )
        {
            printf("\n%s %s\t%d\t->\t%s %s\t%d", everyone[k].prenom, everyone[k].nom, everyone[k].ID, leftARR[i].prenom, leftARR[i].nom, leftARR[i].ID);
            everyone[k] = leftARR[i];
            printf("_");
            i++;
        }
        else if(strcmp(leftARR[i].nom, rightARR[j].nom) > 0)
        {      
            printf("\n%s %s\t%d\t->\t%s %s\t%d", everyone[k].prenom, everyone[k].nom, everyone[k].ID, rightARR[j].prenom, rightARR[j].nom, rightARR[j].ID);
            everyone[k] = rightARR[j];
            printf(",");
            j++;
        }

        k++;       
    }
    printf(".");

    while (i < left_size)
    {
        everyone[k++] = leftARR[i++];
    }
    
    while (j < right_size)
    {
        everyone[k++] = rightARR[j++];
    }
    
}


void Get_Name_From_Teams(TEAM*,TEAM*,TEAM*,TEAM*, unsigned short, NAME_TYPE, char*);



///////  PASSED CHECK, WORKS ///////
int char_to_int (char char_to_check)
{
    int     ascii_val   =   (int)char_to_check;
    return  ascii_val;
} 
////////////////////////////////////



int main()
{
    printf("Starting");

    srand(time(NULL));
    STEP


    unsigned int SEEDS[9];
    STEP

    //for (int i = 0; i < 9; i++)
    //{   SEEDS[i] = rand() % (i + 9);   }
    //STEP


    TEAM Team_1;     STEP
    TEAM Team_2;     STEP
    TEAM Team_3;     STEP
    TEAM Team_4;     STEP

    SLEEP(500);
    printf("\nGenerating Team Data");
    //////////      TEAM    1   line 1
    //srand(SEEDS[1]);                            STEP
    Generate_Random_Team_Data(&Team_1,  1,1);   STEP 
    test_random_team_func(&Team_1,  1,  false);
    


    //////////      TEAM    2   line 2
    //srand(SEEDS[2]);                            STEP
    Generate_Random_Team_Data(&Team_2,  2,2);   STEP
    test_random_team_func(&Team_2,  2,  false);
    

    //////////      TEAM    3   line 3
    //srand(SEEDS[3]);                            STEP
    Generate_Random_Team_Data(&Team_3,  3,3);   STEP
    test_random_team_func(&Team_3,  3,  false);


    //////////      TEAM    4   line 1
    //srand(SEEDS[4]);                            STEP
    Generate_Random_Team_Data(&Team_4,  1,4);   STEP  
    test_random_team_func(&Team_4,  4,  false);

    int total_num_employees = Team_1.How_Many_Members;
    total_num_employees += Team_2.How_Many_Members;
    total_num_employees += Team_3.How_Many_Members;
    total_num_employees += Team_4.How_Many_Members;



    printf("\n\n\nAll %d Employees can be seen here before sorting\n", total_num_employees);
    
    ///////     gather up all the first and last names
    char** fnames = malloc( sizeof(char*) * total_num_employees );
    char** lnames = malloc( sizeof(char*) * total_num_employees );
    EMPLOYEE* everyone = malloc( sizeof(EMPLOYEE*) * total_num_employees );


    for (int i = 0; i < total_num_employees; i++)
    {   
        fnames[i] = malloc( sizeof(char) * NAME_SIZE );    
        lnames[i] = malloc( sizeof(char) * NAME_SIZE );    
    }

    for (fatass x = 0; x < total_num_employees; x++)
    {
        if (x < Team_1.How_Many_Members)
        {
            fnames[x] = Team_1.Employees[x].prenom;
            lnames[x] = Team_1.Employees[x].nom;
            everyone[x] = Team_1.Employees[x];
        }
        else if (x < (Team_1.How_Many_Members+Team_2.How_Many_Members))
        {
            fnames[x] = Team_2.Employees[(x-Team_1.How_Many_Members)].prenom;
            lnames[x] = Team_2.Employees[(x-Team_1.How_Many_Members)].nom;
            everyone[x] = Team_2.Employees[(x-Team_1.How_Many_Members)];
        }
        else if (x < (Team_1.How_Many_Members+Team_2.How_Many_Members+Team_3.How_Many_Members))
        {
            fnames[x] = Team_3.Employees[(x-(Team_1.How_Many_Members + Team_2.How_Many_Members))].prenom;
            lnames[x] = Team_3.Employees[(x-(Team_1.How_Many_Members + Team_2.How_Many_Members))].nom;
            everyone[x] = Team_3.Employees[(x-(Team_1.How_Many_Members + Team_2.How_Many_Members))];
        }
        else
        {
            fnames[x] = Team_4.Employees[(x-(Team_1.How_Many_Members + (Team_2.How_Many_Members+Team_3.How_Many_Members)))].prenom;
            lnames[x] = Team_4.Employees[(x-(Team_1.How_Many_Members + (Team_2.How_Many_Members+Team_3.How_Many_Members)))].nom;
            everyone[x] = Team_4.Employees[(x-(Team_1.How_Many_Members + (Team_2.How_Many_Members+Team_3.How_Many_Members)))];
        }
    }
    

    for (int i = 0; i < total_num_employees; i++)
    {   printf("\n%d:\t%s %s\t\t%d", i, everyone[i].prenom, everyone[i].nom, everyone[i].ID );   }

    
    ShitSort(everyone, 0, (total_num_employees-1) );


    for (int i = 0; i < total_num_employees; i++)
    {   printf("\n%d:\t%s %s\t\t%d", i, everyone[i].prenom, everyone[i].nom, everyone[i].ID );   }

    printf("\nAll Done\n\t\tPress Enter to Exit  ");
    getchar();
    
    return 0;
}



void Generate_Random_Team_Data (TEAM* team_to_change,    mint line,  mint team_num)
{
    mint    how_many_members = rand() % (MAX_TEAM_SIZE - MIN_TEAM_SIZE) + MIN_TEAM_SIZE;
    team_to_change->How_Many_Members            =   how_many_members; 
    team_to_change->Line_We_Do_Be_Working_On    =   line;

    for (mint i = 0; i < team_to_change->How_Many_Members; i++)
    {
        Generate_Random_Name(team_to_change->Employees[i].prenom,   FIRST_NAME);
        Generate_Random_Name(team_to_change->Employees[i].nom,      LAST_NAME);

        team_to_change->Employees[i].ID = (MAX_TEAM_SIZE * team_num)+i;
        team_to_change->Employees[i].Held_Certificate_Count = (rand() % LINES_COUNT) + 1;
        
        for (mint x = 0; x < team_to_change->Employees[i].Held_Certificate_Count; x++)
        {
            team_to_change->Employees[i].Certificates[x].EMPLOYEE_ID        =   team_to_change->Employees[i].ID;
            team_to_change->Employees[i].Certificates[x].ASSOSIATED_LINE    =   x+1;
        }
        
        
    }
    
    if (team_to_change->Line_We_Do_Be_Working_On == 2)
    {
        for (mint i = 0; i < team_to_change->How_Many_Members; i++)
    
        if (team_to_change->Employees[i].Held_Certificate_Count == 1)
        {
            team_to_change->Employees[i].Certificates[0].ASSOSIATED_LINE = 2;
        }
    }
    else if (team_to_change->Line_We_Do_Be_Working_On == 3)
    {
        for (mint i = 0; i < team_to_change->How_Many_Members; i++)
        {
            if (team_to_change->Employees[i].Held_Certificate_Count < 3)
            {
                team_to_change->Employees[i].Certificates[0].ASSOSIATED_LINE = 3;
            }
        }
    }
    
}


    
void test_random_team_func(TEAM* team_to_check,  mint which_team,    mint display_employees_too)
{
    if (display_employees_too)
    {   printf("\n\n\n\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");   }
    else
    {   printf("\n\n");     }
    
    printf("Team %d\n____________________________________________________________",   which_team);
    printf("\n%d employees\t\t",    team_to_check->How_Many_Members);
    printf("Line: %d\t\t\t%d Bytes\n",            team_to_check->Line_We_Do_Be_Working_On,    sizeof(*team_to_check));
    

    if (display_employees_too)
    {
        printf("\nFirst Name\t|\tLast Name \t|\t# of certs\t|\tID-self   \t|\tID-cert   \t|\tAuth Lines:\n");
        for (mint i = 0; i < team_to_check->How_Many_Members; i++)
        {
            mint prenomL    = strlen(team_to_check->Employees[i].prenom);
            mint nomL       = strlen(team_to_check->Employees[i].nom);

            printf("%s",    team_to_check->Employees[i].prenom);
            
            for (mint x = 0; x < (NAME_SIZE - prenomL); x++)
            {   printf(" ");    }

            printf("\t\t");
            printf("%s",    team_to_check->Employees[i].nom);
            
            for (mint x = 0; x < (NAME_SIZE - nomL); x++)
            {   printf(" ");    }

            printf("\t\t    %d\t\t", team_to_check->Employees[i].Held_Certificate_Count);
            printf("\t  %d\t\t\t", team_to_check->Employees[i].ID);
            
            mint char_spaces = 1; //first comma
            char_spaces += (team_to_check->Employees[i].Held_Certificate_Count) -1; //subsequent commas
            
            for (mint x = 0; x < team_to_check->Employees[i].Held_Certificate_Count; x++)
            {
                if (team_to_check->Employees[i].Certificates[x].EMPLOYEE_ID < 10)
                {   char_spaces++;  }
                else if(team_to_check->Employees[i].Certificates[x].EMPLOYEE_ID < 100)
                {   char_spaces++;char_spaces++;    }
                else if(team_to_check->Employees[i].Certificates[x].EMPLOYEE_ID < 1000)
                {   char_spaces += 3; }
                else
                {   char_spaces += 4; }
                //end if-else

                printf("%d,", team_to_check->Employees[i].Certificates[x].EMPLOYEE_ID);
            }//end for

            if (char_spaces < 7)
            {   printf("\t");   }
            
            printf("\t\t");

            for (mint x = 0; x < team_to_check->Employees[i].Held_Certificate_Count; x++)
            {   printf("%d,",   team_to_check->Employees[i].Certificates[x].ASSOSIATED_LINE);   }

            printf("\n");
        }
    }

    else
    {   printf("____________________________________________________________\n");  }    
}



void Generate_Random_Name (char* array_to_write_to, NAME_TYPE name_type)
{
    int name_index = rand() % How_many_random_names_have_been_made;

    //      ALL Names here were copy pasted and then a few constanants were changed, like a G to a Sh... That's why Shodzilla is a name     //
    char first_names[How_many_random_names_have_been_made][NAME_SIZE]     =   
                                            {   "Billy",                "Kyle",                     "Ander",
                                                "Prian",                "Godzilla",                 "Habzdulla",
                                                "Kronk",                "Pastry",                   "Ali",
                                                "Bob",                  "Dilly",                    "Dyle",
                                                "Kalder",               "Drian",                    "Dodzilla",
                                                "Dabzdulla",            "Dronk",                    "Dastry",
                                                "Dli",                  "Dob",                      "Milly",
                                                "Myle",                 "Onder",                    "Mian",
                                                "Modzilla",             "Mabzdulla",                "Mronk",
                                                "Mastry",               "Mli",                      "Mob",
                                                "Shilly",               "Chyle",                    "Brander",
                                                "Shrian",               "Chodzilla",                "Brabzdulla",
                                                "Shronk",               "Chastry",                  "Brali",
                                                "Shob",                 "Chilly",                   "Bryle",
                                                "Shynder",              "Chrian",                   "Brodzilla",
                                                "Shabzdulla",           "Chronk",                   "Brastry",
                                                "Shli",                 "Chob",                     "Brilly",
                                                "Shyle",                "Chander",                  "Brimian",
                                                "Shodzilla",            "Chabzdulla",               "Bronk",
                                                "Shastry",              "Chli",                     "Broob",
                                                "Colilly",              "Valyle",                   "Salnder",
                                                "Colrian",              "Valodzilla",               "Soldulla",
                                                "Colronk",              "Valastry",                 "Salli",
                                                "Colob",                "Valilly",                  "Salyle",
                                                "Colnder",              "Valrian",                  "Sodzilla",
                                                "Doodoo",               "Valronk",                  "Salastry",
                                                "Colli",                "Valob",                    "Salilly",
                                                "Colyle",               "Valnder",                  "Salian",
                                                "Colodzilla",           "Valabzdulla",              "Salronk",
                                                "Colastry",             "Valli",                    "Salob",
                                                "Colhilly",             "Valhyle",                  "Salrander",
                                                "Colhrian",             "Valhodzilla",              "Saldulla",
                                                "Colhronk",             "Valhastry",                "Salrali",
                                                "Colhob",               "Valhilly",                 "Salryle",
                                                "Colhynder",            "Valhrian",                 "Bigrod",
                                                "Hatdulla",             "Valhronk",                 "Salrastry",
                                                "Colhli",               "Valhob",                   "Salrilly",
                                                "Colhyle",              "Valhander",                "Salrimian",
                                                "Colhodzilla",          "Vall",                     "Salronk",
                                                "Colhastry",            "Valhli",                   "Salroob",
                                                "Brally",               "Modle",                    "Wavder",
                                                "Bralan",               "Moddzilla",                "Wavdulla",
                                                "Bralark",              "Modstry",                  "Wavi",
                                                "Bral",                 "Modlly",                   "Wavle",
                                                "Bralder",              "Modian",                   "Wavdzilla",
                                                "Brodulla",             "Modonk",                   "Wavstry",
                                                "Bral",                 "Modab",                    "Wavlly",
                                                "Brale",                "Modder",                   "Wavan",
                                                "Bralzilla",            "Modbzdulla",               "Wavonk",
                                                "Braltry",              "Modi",                     "Wavb",
                                                "Brallly",              "Modyle",                   "Wavander",
                                                "Bralian",              "Mododzilla",               "Wavabzdulla",
                                                "Bralonk",              "Modastry",                 "Wavali",
                                                "Bralbee",              "Modilly",                  "Wavyle",
                                                "Bralnder",             "Modrian",                  "Wavodzilla",
                                                "Bralbzdulla",          "Modronk",                  "Wavastry",
                                                "Brali",                "Modob",                    "Wavilly",
                                                "Bralle",               "Modander",                 "Wavimian",
                                                "Braldzilla",           "Modabzo",                  "Wavonk",
                                                "Bralstry",             "Modli",                    "Wavoob",
                                                "Bralilly",             "Modlyle",                  "Wavlnder",
                                                "Bralrian",             "Modlodzila",               "Wavdulla",
                                                "Bralronk",             "Modlastry",                "Wavlli",
                                                "Bralob",               "Modlilly",                 "Wavlye",
                                                "Bralnder",             "Modlrian",                 "Wavzilla",
                                                "Bralabzdulla",         "Modlronk",                 "Wavlastry",
                                                "Bralli",               "Modlob",                   "Wavlilly",
                                                "Bralyle",              "Modlnder",                 "Wavlian",
                                                "Bralodzilla",          "Modladulla",               "Wavlronk",
                                                "Bralastry",            "Modlli",                   "Wavlob",
                                                "Bralhilly",            "Modlhyle",                 "Wavlrander",
                                                "Bralhrian",            "Madzilla",                 "Wavldulla",
                                                "Bralhronk",            "Modlhastry",               "Wavlrali",
                                                "Bralhob",              "Modlhilly",                "Wavlryle",
                                                "Bralhynder",           "Modlhrian",                "Poozilla",
                                                "Brodulla",             "Modlhronk",                "Wavlrastry",
                                                "Bralhli",              "Modlhob",                  "Wavlrilly",
                                                "Bralhyle",             "Modlhander",               "Wavlrimian",
                                                "Bralhodzilla",         "Modulla",                  "Wavlronk",
                                                "Bralhastry",           "Modlhli",                  "Strelok",
                                                "Hjornlly",             "Bjorne",                   "Jabier",
                                                "Hjornian",             "Bjornzilla",               "Jabidulla",
                                                "Hjornonk",             "Bjorntry",                 "Jabimi",
                                                "Hjornb",               "Bjornly",                  "Jabies",
                                                "Hjornler",             "Bjornan",                  "Jabizilla",
                                                "Hornie",               "Bjornnk",                  "Jabitry",
                                                "Hjorni",               "Bjorn",                    "Jabily",
                                                "Hjornle",              "Bjorner",                  "Jabin",
                                                "Hjornzilla",           "Bjorndulla",               "Jabink",
                                                "Hjornstry",            "Bjornnie",                 "Jabi",
                                                "Brikilly",             "Brownie",                  "Jabinder",
                                                "Brikrian",             "Bjornzila",                "Jabidulla",
                                                "Brikronk",             "Bjornstry",                "Jabili",
                                                "Brikob",               "Bjornlly",                 "Jabile",
                                                "Brikynder",            "Bjornian",                 "Jabiela",
                                                "Brikabz",              "Bjornonk",                 "Jabistry",
                                                "Brikli",               "Bjornb",                   "Jabilly",
                                                "Brikyle",              "Bjornnder",                "Jabimian",
                                                "Brick",                "Sillyman",                 "Jabink",
                                                "Brikastry",            "Bjorni",                   "Jabiob",
                                                "Nrokilly",             "Bjornyle",                 "Jabinder",
                                                "Nrokrian",             "Bjornzilla",               "Jazzdulla",
                                                "Nrokronk",             "Bjornastry",               "Jabili",
                                                "Nrokob",               "Bjornilly",                "Jabiyle",
                                                "Nroknder",             "Bjornrian",                "Jazzilla",
                                                "fakeman",              "Bjornronk",                "Jabiastry",
                                                "Nrokli",               "Bjornob",                  "Jabiilly",
                                                "Nrokyle",              "Bjornder",                 "Jabiian",
                                                "Nrokodzilla",          "Bjarnaz",                  "Jabironk",
                                                "Nrokastry",            "Bjornli",                  "Jabiob",
                                                "Nrokhilly",            "Bjornhyle",                "Jabirander",
                                                "Nrokhrian",            "Todzilla",                 "Jabzdulla",
                                                "Nrokhronk",            "Bjornhastry",              "Jabirali",
                                                "Nrokhob",              "Bjornhilly",               "Jabiryle",
                                                "Nrokhynder",           "Bjornhrian",               "Jabirodzilla",
                                                "Necron",               "Bjornhronk",               "Jabirastry",
                                                "Nrokhli",              "Bjornhob",                 "Jabirilly",
                                                "Nrokhyle",             "Bjirn",                    "Jabirimian",
                                                "Private",              "Strelok",                  "Jabironk",
                                                "Nrokhastry",           "Bjornhli",                 "Captain",
                                            };

    char last_names[How_many_random_names_have_been_made][NAME_SIZE]      =   
                                            {   "Joel",                 "Jenner",                   "Jooba",
                                                "Jones",                "Jiant",                    "Jeejee",
                                                "Jiantman",             "Jill",                     "Jee",
                                                "Jillan",               "Woel",                     "Wenner",
                                                "Wooba",                "Wones",                    "Wiant",
                                                "Weejee",               "Wiantman",                 "Will",
                                                "Wee",                  "Willan",                   "Boel",
                                                "Benner",               "Booba",                    "Bones",
                                                "Biant",                "Beejee",                   "Biantman",
                                                "Bill",                 "Bee",                      "Billan",
                                                "Broel",                "Chenner",                  "Shooba",
                                                "Brones",               "Chiant",                   "Sheejee",
                                                "Briantman",            "Chill",                    "Shee",
                                                "Brillan",              "Choel",                    "Shenner",
                                                "Brooba",               "Chones",                   "Shiant",
                                                "Breejee",              "Chiantman",                "Shill",
                                                "Bree",                 "Chillan",                  "Shoel",
                                                "Brenner",              "Chooba",                   "Shones",
                                                "Briant",               "Cheejee",                  "Shiantman",
                                                "Brill",                "Chee",                     "Shillan",
                                                "Loloel",               "Chozenner",                "Chadooba",
                                                "Lolones",              "Choziant",                 "Chadeejee",
                                                "Loliantman",           "Chozill",                  "Chadee",
                                                "Lolillan",             "Chozoel",                  "Chadenner",
                                                "Lolooba",              "Chozones",                 "Chadiant",
                                                "Loleejee",             "Choziantman",              "Chadill",
                                                "Lolee",                "Chozillan",                "Chadoel",
                                                "Lolenner",             "Chozooba",                 "Chadones",
                                                "Loliant",              "Chozeejee",                "Chadiantman",
                                                "Lolill",               "Chozee",                   "Chadillan",
                                                "Lolroel",              "Chozhenner",               "Chadhooba",
                                                "Lolrones",             "Chozhiant",                "Chadheejee",
                                                "Lolriantman",          "Chozhill",                 "Chadhee",
                                                "Lolrillan",            "Chozhoel",                 "Chadhenner",
                                                "Lolrooba",             "Chozhones",                "Chadhiant",
                                                "Lolreejee",            "Choziantman",              "Chadhill",
                                                "Lolree",               "Chozhillan",               "Chadhoel",
                                                "Lolrenner",            "Chozhooba",                "Chadhones",
                                                "Lolriant",             "Chozheejee",               "Chadchad",
                                                "Lolrill",              "Chozhee",                  "Chadhillan",
                                                "Pookoel",              "Krabnner",                 "Snooba",
                                                "Pookones",             "Krabant",                  "Snoejee",
                                                "Pooman",               "Krabll",                   "Snoe",
                                                "Pookillan",            "Krabel",                   "Snonner",
                                                "Pookooba",             "Krabnes",                  "Snoant",
                                                "Pookeejee",            "Krabantman",               "Snoll",
                                                "Pookee",               "Krabllan",                 "Snoel",
                                                "Pookenner",            "Kraboba",                  "Snones",
                                                "Pookiant",             "Krabejee",                 "Snoantman",
                                                "Pookill",              "Krabe",                    "Snollan",
                                                "Pookroel",             "Krabenner",                "Snoooba",
                                                "Pookrones",            "Krabiant",                 "Snoeejee",
                                                "Poopeeman",            "Krabill",                  "Snoee",
                                                "Pookrillan",           "Kraboel",                  "Snoenner",
                                                "Pookrooba",            "Krabones",                 "Snoiant",
                                                "Pookreejee",           "Krabiantman",              "Snoill",
                                                "Pookree",              "Krabillan",                "Snooel",
                                                "Pookrenner",           "Krabooba",                 "Snoones",
                                                "Pookriant",            "Krabeejee",                "Snoiantman",
                                                "Pookrill",             "Krabee",                   "Snoillan",
                                                "Pookoloel",            "Krabozenner",              "Snoadooba",
                                                "Pookolones",           "Kraboziant",               "Snoojee",
                                                "Pookoliant",           "Krabozill",                "Snoadee",
                                                "Pookolian",            "Krabozoel",                "Snoadenner",
                                                "Pookolooba",           "Krabozones",               "Snoadiant",
                                                "Pookoleejee",          "STALKER",                  "Snoadill",
                                                "Pookolee",             "Krabozillan",              "Snoadoel",
                                                "Pooner",               "Krabozooba",               "Snoadones",
                                                "Pookoliant",           "Krabozeejee",              "Snoadman",
                                                "Pookolill",            "Krabozee",                 "Snoadillan",
                                                "Pookolroel",           "Krabenner",                "Snoadhooba",
                                                "Pokolones",            "Krabozhiant",              "Poepoe",
                                                "Armyman",              "Krabozhill",               "Snoadhee",
                                                "Pookolillan",          "Krabozhoel",               "Snoadhenner",
                                                "Pookolrooba",          "Krabozhones",              "Snoadhiant",
                                                "Raj",                  "Jones",                    "Snoadhill",
                                                "Pookolree",            "Krabozhili",               "Snoadhoel",
                                                "Poopeer",              "Krabozhooba",              "Snoadhones",
                                                "Pookolriant",          "Keeheejee",                "Sniper",
                                                "Pookolrill",           "Krabozhee",                "Snoadhillan",
                                                "Gaoel",                "Linner",                   "Quooba",
                                                "Gaones",               "Liant",                    "Queejee",
                                                "Gaiantman",            "Lill",                     "Quee",
                                                "Gaillan",              "Liel",                     "Quenner",
                                                "Gaooba",               "Lines",                    "Quiant",
                                                "Gaeejee",              "Liantman",                 "Quill",
                                                "Gaee",                 "Lillan",                   "Quoel",
                                                "Gaenner",              "Lioba",                    "Quones",
                                                "Gaiant",               "Liejee",                   "Quiantman",
                                                "Gaill",                "WooJee",                   "Quillan",
                                                "Garoel",               "Lienner",                  "Quhooba",
                                                "Garones",              "Liiant",                   "Quheejee",
                                                "Gariantman",           "Liill",                    "Quhee",
                                                "Garillan",             "Lioel",                    "Quhenner",
                                                "Garooba",              "Liones",                   "Quhiant",
                                                "Gareejee",             "Liiantman",                "Quhill",
                                                "Garee",                "Liillan",                  "Quhoel",
                                                "Garenner",             "Liooba",                   "Quhones",
                                                "Gariant",              "Lieejee",                  "Quhiantman",
                                                "Garill",               "Liee",                     "Quhillan",
                                                "Gaoloel",              "Liozenner",                "Quhadooba",
                                                "Gaolones",             "Lioziant",                 "Quhadeejee",
                                                "Gaoliantman",          "Liozill",                  "Quhadee",
                                                "Gaolillan",            "Liozoel",                  "Quhadenner",
                                                "Gaolooba",             "Liozones",                 "Quhadiant",
                                                "Gaoleejee",            "Lioman",                   "Quhadill",
                                                "Gaolee",               "Liozillan",                "Quhadoel",
                                                "Gaolenner",            "Liozooba",                 "Quhadones",
                                                "Gaoliant",             "Liozeejee",                "Quhadiantman",
                                                "Gaolill",              "Liozee",                   "Quhadillan",
                                                "Gaolroel",             "Liozhenner",               "Quhadhooba",
                                                "Gaolrones",            "Liozhiant",                "Quhadheejee",
                                                "Gaolrianman",          "Liozhill",                 "Quhadhee",
                                                "Gaolrillan",           "Liozhoel",                 "Quhadhenner",
                                                "Gaolrooba",            "Liozhones",                "Quhadhiant",
                                                "Gaolreejee",           "Liowee",                   "Quhadhill",
                                                "Gaolree",              "Liozhillan",               "Quhadhoel",
                                                "Gaolrenner",           "Liozhooba",                "Quhadhones",
                                                "Gaolriant",            "Liozheejee",               "Peasant",
                                                "Gaolrill",             "Liozhee",                  "Quhadhillan"
                                            };

    
    switch (name_type)
    {
        case FIRST_NAME:
        
            for (int i = 0; i < (NAME_SIZE-1); i++)
            {
                *(array_to_write_to + i) = *(first_names[name_index] + i);
            }
            *(array_to_write_to + NAME_SIZE) = '\0';
            
            break;
            

        case LAST_NAME:
        
            for (int i = 0; i < (NAME_SIZE-1); i++)
            {
                *(array_to_write_to + i) = *(last_names[name_index] + i);
            }
            *(array_to_write_to + NAME_SIZE) = '\0';
            
            break;
    

        default:
            printf("\n\nNAME_ERROR IN RAND NAME FUNCTION\n\n");
            break;
    }
}



void Get_Name_From_Teams(TEAM* t1ptr,TEAM* t2ptr,TEAM* t3ptr,TEAM* t4ptr,     unsigned short  employee_id,  NAME_TYPE FLpart,  char* array_to_overwrite )
{
    mint found = false;
    for (mint i = 0; i < TOTAL_NUM_TEAMS; i++)
    {
        switch (i)
        {
            case 0:
                for (mint x = 0; x < t1ptr->How_Many_Members; x++)
                {   if (t1ptr->Employees[x].ID  ==  employee_id)
                    {   if (FLpart == FIRST_NAME)   { for (int y = 0; y < NAME_SIZE; y++){*(array_to_overwrite + y) = *(t1ptr->Employees[x].prenom + y);}}
                        else                        { for (int y = 0; y < NAME_SIZE; y++){*(array_to_overwrite + y) = *(t1ptr->Employees[x].nom + y);}}
                        found=true;
                    }
                }
                break;
            
            case 1:
                for (mint x = 0; x < t2ptr->How_Many_Members; x++)
                {   if (t2ptr->Employees[x].ID  ==  employee_id)
                    {   if (FLpart == FIRST_NAME)   { for (int y = 0; y < NAME_SIZE; y++){*(array_to_overwrite + y) = *(t2ptr->Employees[x].prenom + y);}}
                        else                        { for (int y = 0; y < NAME_SIZE; y++){*(array_to_overwrite + y) = *(t2ptr->Employees[x].nom + y);}}
                        found=true;
                    }
                }
                break;
            
            case 2:
                for (mint x = 0; x < t3ptr->How_Many_Members; x++)
                {   if (t3ptr->Employees[x].ID  ==  employee_id)
                    {   if (FLpart == FIRST_NAME)   { for (int y = 0; y < NAME_SIZE; y++){*(array_to_overwrite + y) = *(t3ptr->Employees[x].prenom + y);}}
                        else                        { for (int y = 0; y < NAME_SIZE; y++){*(array_to_overwrite + y) = *(t3ptr->Employees[x].nom + y);}}
                        found=true;
                    }
                }
                break;

            case 3:
                for (mint x = 0; x < t4ptr->How_Many_Members; x++)
                {   if (t4ptr->Employees[x].ID  ==  employee_id)
                    {   if (FLpart == FIRST_NAME)   { for (int y = 0; y < NAME_SIZE; y++){*(array_to_overwrite + y) = *(t4ptr->Employees[x].prenom + y);}}
                        else                        { for (int y = 0; y < NAME_SIZE; y++){*(array_to_overwrite + y) = *(t4ptr->Employees[x].nom + y);}}
                        found=true;
                    }
                }
                break;
            
            default:
                printf("\nERROR IN Find_Name_From_Teams FUNCTION\n");
                break;
        }
    }
    if (!found)
    {
        printf("\nNOT A VALID EMPLOYEE ID\n");
    }   
}






