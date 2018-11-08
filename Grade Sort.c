#include <stdio.h>
#include <string.h>

void average(int grades[100][10], int final_grades[100])
{
	int i = 0;
	/*  Loops through each row of the array and adds the column values then divides to get average */
  	for(i; i < 100; i++)
	{
		final_grades[i] = (grades[i][0]+grades[i][1]+grades[i][2]+grades[i][3]+grades[i][4]+grades[i][5]+grades[i][6]+grades[i][7]+grades[i][8]+grades[i][9])/10;		
	}
}

void process(char f_name[1000], char l_name[1000], int grades[100][10], char names[1000][1000])
{
  int c;
  int i;
  /*  opens file pointer */
  FILE *my_file;
  /*  pass the input file */
  my_file = fopen("input.txt", "r");
  if(my_file == NULL)
  {
	  printf("Error opening file.");
  }
  
  for(i = 0; i < 100; i++)
  {
	  /*  scans through each line of the text and assigns names into two char arrays, and puts grades to a int array */
    fscanf(my_file, "%s %s %d %d %d %d %d %d %d %d %d %d", f_name, l_name, &grades[i][0], &grades[i][1], &grades[i][2], &grades[i][3], &grades[i][4], &grades[i][5], &grades[i][6], &grades[i][7], &grades[i][8], &grades[i][9]);
	/*  concatenates the first name then a space then last name to each row of char array */
	strcat(names[i], f_name);
	strcat(names[i], " ");
	strcat(names[i], l_name);
  }
  fclose(my_file);	
}

void final(char names[1000][1000], int final_grades[100], char A[100][1000], char B[1000][1000], char C[1000][1000], char D[1000][1000], char F[1000][1000])
{
  int i;
  /* counters that increments when a grade average has been added to letter array */
  int counterA = 0;
  int counterB = 0;
  int counterC = 0;
  int counterD = 0;
  int counterF = 0;
  /*  Will loop through the array averages and copies the row according to the location it was found in the array into letter grade array*/
  for(i = 0; i < 100; i++)
  {
    if(final_grades[i] >= 90)
	{
		strcpy(A[counterA], names[i]);
		counterA++;
	}
    else if(final_grades[i] >= 80)
	{
		strcpy(B[counterB], names[i]);
		counterB++;
	}		
	else if(final_grades[i] >= 70)
	{
		strcpy(C[counterC], names[i]);
		counterC++;
	}	
	else if(final_grades[i] >= 60)
	{
		strcpy(D[counterD], names[i]);
		counterD++;
	}	
	else
	{
		strcpy(F[counterF], names[i]);
		counterF++;
	}	
  }	  
}

void letter_grade(char A[100][1000], char letter)
{
	int i = 0;
	printf("Students who received %c:\n", letter);
	int counter = 0;
	for(i; i < 100; i++)
	{
		/* Will loop until an empty value in the array is found */
		if(strlen(A[i]) == 0)
		{
			break;
		}
		printf("%s\n", A[i]);
	}
	printf("\n\n");
}

int main(void)
{
	/*  Initialize all array sizes to pass to array */
  char names[1000][1000];
  int grades[100][10];
  int final_grades[100];
  char f_name[1000];
  char l_name[1000];
  char a[100][1000];
  char b[100][1000];
  char c[100][1000];
  char d[100][1000];
  char f[100][1000];
  char A = 'A';
  char B = 'B';
  char C = 'C';
  char D = 'D';
  char F = 'F';
 
  /* Processes the text file into arrays  */
  process(f_name, l_name, grades, names);
  /*  Gets averages of all the grades for each student */
  average(grades, final_grades);
  /* Returns final letter grade into array of each student  */
  final(names, final_grades, a,b,c,d,f);
  /*  Print each student according to their letter grade */
  printf("\n\n");
  letter_grade(a,A);
  letter_grade(b,B);
  letter_grade(c,C);
  letter_grade(d,D);
  letter_grade(f,F);
   
  return 0;
}