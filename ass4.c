#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdbool.h> 
#include <math.h>
#include <time.h>

#include "arbprecision.h"
#define _GNU_SOURCE


// void testing(char** parsed)
// {

// 		bool isfinalplus = true;
// 		bool isp1plus = true;
// 		bool isp2plus = true;
// 			char* parsed1copy[2];
// 			parseComma(parsed[1], parsed1copy);
// 			char* parsed2copy[2];
// 			parseComma(parsed[2], parsed2copy);
// 			// printf("parsed1copy[0] is : %s\n", parsed2copy[0]);
// 			// printf("parsed1copy[1] is : %s\n", parsed2copy[1]);
// 			char* parsed1[2];
// 			// parsed1[0] = malloc((int)strlen(parsed1copy[0]) -1);
			
			
// 			// printf("\n filling parsed1copy[0] to parsed1[0]\n");
// 			int nikita = (int)strlen(parsed1copy[0]) - 1;
// 			char* tempparsed10= malloc(nikita+1);
// 			// printf("nikita is : %d\n", nikita);
// 			for(int i=0; i<nikita ; i++)
// 				{
// 					// printf("%c", parsed1copy[0][i+1]);
// 					tempparsed10[i] = parsed1copy[0][i+1];
// 					// break;
// 				}
// 				tempparsed10[nikita] = '\0';
// 			char* tempparsed11 = malloc((int)strlen(parsed1copy[1]));
// 			parsed1[1] = tempparsed11;
// 			parsed1[0] = tempparsed10;
// 			// parsed1[0] = rtrim(tempparsed10, NULL);
// 			// printf("parsed1[0] is : %s\n", parsed1[0]);
// 			// printf("you should be here %d %d %d\n", (int)strlen(parsed1copy[0]) - 1, (int) strlen(tempparsed10), nikita);
			
// 			int y=0;
// 			for(y=0; y<(int)strlen(parsed1copy[1]) - 1; y++)
// 				{
// 					// printf("transferring a%ca\n", parsed1copy[1][i]);
// 					if((int)parsed1copy[1][y] == 41)
// 						{
// 							break;
// 						}
// 					parsed1[1][y]=parsed1copy[1][y];
// 				}
// 			parsed1[1][y] = '\0';

// 			// for(int i=0; i<(int)strlen(parsed1copy[1]) - 1; i++)
// 			// 	parsed1[1][i]=parsed1copy[1][i];
// 			// parsed1[1][(int)strlen(parsed1copy[1]) - 1] = '\0';
			


// 			char* parsed2[2];
// 			parsed2[0] = malloc((int)strlen(parsed2copy[0]));
// 			for(int i=0; i<(int)strlen(parsed2copy[0]) - 1; i++)
// 				parsed2[0][i]=parsed2copy[0][i+1];

// 			parsed2[0][(int)strlen(parsed2copy[0]) - 1] = '\0';
// 			// printf("parsed2[0] is : %s\n", parsed2[0]);
// 			parsed2[1] = malloc((int)strlen(parsed2copy[1]) -1);
// 			for(int i=0; i<(int)strlen(parsed2copy[1]) - 1; i++)
// 				parsed2[1][i]=parsed2copy[1][i];

// 			parsed2[1][(int)strlen(parsed2copy[1]) - 1] = '\0';


// 			// printf("parsed1[0] is : %s\n", parsed1[0]);//a
// 			// printf("parsed1[1] is : %s\n", parsed1[1]);//b
// 			// printf("parsed2[0] is : %s\n", parsed2[0]);//c
// 			// printf("parsed2[1] is : %s\n", parsed2[1]);//d
// 			char* uper[2];
// 			char* temp1 = malloc(100);
// 			temp1[0] = '(';
// 			int i=0;
// 			for(i=0; i<strlen(parsed1[0]); i++)
// 			{
// 				temp1[i] - parsed1[0][i];
// 			}
// 			temp1[i] = ',';
// 			int j=0;
// 			for(j=0; j<strlen(parsed1[1]); j++)
// 			{
// 				temp1[i+j] = parsed1[1][j];
// 			}

// 			temp1[i+j]=')';
// 			temp1[i+j+1] = '\0';



// 			char* temp2 = malloc(100);
// 			temp2[0] = '(';
// 			i=0;
// 			for(i=0; i<strlen(parsed2[0]); i++)
// 			{
// 				temp2[i] = parsed2[0][i];
// 			}
// 			temp2[i] = ',';

// 			if(parsed2[1][0] != '-')
// 			{
// 				temp2[i+1] = '-';
// 				int j=0;
// 				for(j=0; j<strlen(parsed2[1]); j++)
// 				{
// 					temp2[i+j+1] = parsed2[1][j];
// 				}

// 				temp2[i+j+1]=')';
// 				temp2[i+j+2] = '\0';
// 			}

// 			else
// 			{
// 				int j=0;
// 				for(j=1; j<strlen(parsed2[1]); j++)
// 				{
// 					temp2[i+j-1] = parsed2[1][j];
// 				}
// 				temp2[i+j-1] = ')';
// 				temp2[i+j] = '\0';
// 			}





// 			//real part start
// 			//finding ac
// 			char* ac1 = mulhelperac(parsed1[0], parsed2[0]); //a*c
// 			// char* ac = malloc((int)strlen(ac1));
			
// 			int count=0;
// 			while((ac1[0]=='0') && (ac1[1] != '.'))
// 			{
// 				for(int i=0; i<(int)strlen(ac1)-1; i++)
// 				{
// 					ac1[i] = ac1[i+1];
// 				}
// 				count++;
// 				// ac[i] = '\0';
// 			}
// 			char* ac = malloc((int)strlen(ac1) - count);

// 			for(int i=0; i<(int)strlen(ac1) - count; i++)
// 			{
// 				ac[i]=ac1[i];
// 			}
// 			// printf("ac is : %s\n", ac);
// 			char* bd1 = mulhelperac(parsed1[1], parsed2[1]);
// 			// printf("ac is : %s\n", ac);
			
// 			count=0;
// 			while(bd1[0]=='0' && bd1[1] != '.')
// 			{
// 				for(int i=0; i<(int)strlen(bd1)-1; i++)
// 				{
// 					bd1[i] = bd1[i+1];
// 				}
// 				count++;
// 				// bd[i] = '\0';
// 			}

			
// 			char* bd = malloc((int)strlen(bd1) - count+1);
// 			for(int i=0; i<(int)strlen(bd1) - count; i++)
// 			{
// 				// printf("transferring %c\n",bd1[i]);
// 				bd[i] = bd1[i];
// 			}

// 			bd[(int)strlen(bd1) - count] = '\0';
// 			// printf("\nbd1 is %s\n",bd);
// 			char* ret1 = malloc(maximum((int)strlen(ac), (int)strlen(bd))+2); 
// 				ret1 = subhelperac(ac, bd); //final ka real

// 			//real part end

// 				//imag part start
// 				//finding ac
			
// 			char* ad1 = mulhelperac(parsed1[0], parsed2[1]); //a*d
// 			// char* ac = malloc((int)strlen(ac1));
			
// 			count=0;
// 			while((ad1[0]=='0') && (ad1[1] != '.'))
// 			{
// 				for(int i=0; i<(int)strlen(ad1)-1; i++)
// 				{
// 					ad1[i] = ad1[i+1];
// 				}
// 				count++;
// 				// ac[i] = '\0';
// 			}
// 			char* ad = malloc((int)strlen(ad1) - count);

// 			for(int i=0; i<(int)strlen(ad1) - count; i++)
// 			{
// 				ad[i]=ad1[i];
// 			}

// 			char* bc1 = mulhelperac(parsed1[1], parsed2[0]);
// 			// printf("ad is : %s\n", ad);
			
// 			count=0;
// 			while(bc1[0]=='0' && bc1[1] != '.')
// 			{
// 				for(int i=0; i<(int)strlen(bc1)-1; i++)
// 				{
// 					bc1[i] = bc1[i+1];
// 				}
// 				count++;
// 				// bd[i] = '\0';
// 			}

// 			char* bc = malloc((int)strlen(bc1) - count);
// 			for(int i=0; i<(int)strlen(bc1) - count; i++)
// 			{
// 				bc[i]=bc1[i];
// 			}
// 			char* ret2 = malloc(maximum((int)strlen(ad), (int)strlen(bc))); 
// 				ret2 = addhelperac(ad, bc); //final ka imag
// 				// printf("ret2 is : %s\n", ret2);
// 				//imag part end

// 				printf("(%s,%s)\n", ret1, ret2);
				
// 		}


int main(int argc, char* argv[])
{
    char ch;//, file_name[25];
    FILE *fp;

    // printf("Enter name of a file you wish to see\n");
    // gets(argv[1]);
    char* file_name = argv[1];
    // printf("file_name : %s\n",file_name);
    fp = fopen(file_name, "r"); // read mode
    FILE *ft;
    char* file_nameout = argv[2];
    // printf("outputfile name : %s\n", file_nameout);

    ft = fopen(file_nameout, "w");
  if (fp == NULL)
  {
     perror("Error while opening the file.\n");
     exit(EXIT_FAILURE);
  }
  // fprintf(ft, "Manoj");
  
	// printf("The contents of %s file are:\n", file_name);
	char* wholestr = NULL;
	char str[1];
	int i=0;
	size_t len = 0;
	size_t read;

	while ((read = getline(&wholestr, &len, fp)) != -1) 
	{
		// printf("line is : %s\n", wholestr);
		bool isfinalplus = true;
		bool isp1plus = true;
		bool isp2plus = true;

	        // printf("Retrieved line of length %zu:\n", read);
	        // printf("%s", wholestr);
		 	// printf ("The input string is : %s ", wholestr);
			char* parsed[3];
		  parseSpace(wholestr, parsed);

		  if(parsed[0] == NULL) 
		  	continue;
		// printf("Case is : %s\n", parsed[0]);
			//all cases of ADD
		if(strcmp(parsed[0], "ADD") == 0)
		{
			char* parsed1copy[2];
			parseComma(parsed[1], parsed1copy);
			char* parsed2copy[2];
			parseComma(parsed[2], parsed2copy);

			char* parsed1[2];
			int nikita = (int)strlen(parsed1copy[0]) - 1;
			char* tempparsed10= malloc(nikita+1);
			for(int i=0; i<nikita ; i++)
				{
					tempparsed10[i] = parsed1copy[0][i+1];
				}

				tempparsed10[nikita] = '\0';
			char* tempparsed11 = malloc((int)strlen(parsed1copy[1])+1);
			parsed1[1] = tempparsed11;
			parsed1[0] = tempparsed10;

			// parsed1[0] = rtrim(tempparsed10, NULL);			
			int y=0;
			for(y=0; y<(int)strlen(parsed1copy[1]) - 1; y++)
				{
					if((int)parsed1copy[1][y] == 41)
						{
							break;
						}
					parsed1[1][y]=parsed1copy[1][y];
				}
			parsed1[1][y] = '\0';

			char* parsed2[2];
			parsed2[0] = malloc((int)strlen(parsed2copy[0]));
			for(int i=0; i<(int)strlen(parsed2copy[0]) - 1; i++)
				parsed2[0][i]=parsed2copy[0][i+1];

			parsed2[0][(int)strlen(parsed2copy[0]) - 1] = '\0';
			
			parsed2[1] = malloc((int)strlen(parsed2copy[1]));
			for(int i=0; i<(int)strlen(parsed2copy[1]) - 1; i++)
				parsed2[1][i]=parsed2copy[1][i];

			parsed2[1][(int)strlen(parsed2copy[1]) - 1] = '\0';
			//result 1 start by adding parsed1[0] and parsed2[0]
			char** add1 = malloc(3);
			add1[0] = "ADD";
			add1[1] = parsed1[0];
			add1[2] = parsed2[0];
			fprintf(ft, "(");

					bool isfinalplus = true;
					bool isp1plus = true;
					bool isp2plus = true;

				if( (int) add1[1][0] == 45)
			{
					add1[1] = ltrim (add1[1], "-");
					isp1plus = false;
			}
			if ((int) add1[2][0] == 45) 
			{
				add1[2] = ltrim (add1[2], "-");
				isp2plus = false;
			}

			if(!isp1plus && !isp2plus ) {
				isfinalplus = false;
				fprintf(ft,"-");
				add(add1, ft);
			}
			else if(isp1plus && isp2plus)
			{
				isfinalplus = true;
				add(add1, ft);	
			}

			else if(isp1plus && !isp2plus && (compare(add1) == 1))
			{

				isfinalplus = true;
				sub(add1,ft);
			}
			else if(!isp1plus && isp2plus && (compare(add1) == -1))
			{
				
				char* parsedcopy[3];
				char t[3] = "SUB";
				parsedcopy[0] = t;
				parsedcopy[1] = add1[2];
				parsedcopy[2] = add1[1];

				sub(parsedcopy,ft);
			}	
			else if(!isp1plus && isp2plus && (compare(add1) == 1))
			{
				isfinalplus = false;
				fprintf(ft, "-");

				sub(add1,ft);
			}	
			fprintf(ft, ",");
			//result 1 ends
			//result 2 starts
			char** add2 = malloc(3);
			add2[0] = "ADD";
			add2[1] = parsed1[1];
			add2[2] = parsed2[1];
					isfinalplus = true;
					isp1plus = true;
					isp2plus = true;
			if( (int) add2[1][0] == 45)
			{
					add2[1] = ltrim (add2[1], "-");
					isp1plus = false;
			}
			if ((int) add2[2][0] == 45) 
			{
				add2[2] = ltrim (add2[2], "-");
				isp2plus = false;
			}
			if(!isp1plus && !isp2plus ) {
				isfinalplus = false;
				fprintf(ft, "-");
				add(add2,ft);
			}
			else if(isp1plus && isp2plus)
			{
				isfinalplus = true;
				add(add2, ft);	
			}
			else if(isp1plus && !isp2plus && (compare(add2) == 1))
			{
				isfinalplus = true;
				sub(add2,ft);
			}
			else if(!isp1plus && isp2plus && (compare(add2) == -1))
			{
				char* parsedcopy[3];
				char t[3] = "SUB";
				parsedcopy[0] = t;
				parsedcopy[1] = add2[2];
				parsedcopy[2] = add2[1];

				sub(parsedcopy,ft);
			}
			else if(!isp1plus && isp2plus && (compare(add2) == 1))
			{
				isfinalplus = false;
				fprintf(ft, "-");

				sub(add2,ft);
			}
			fprintf(ft, ")\n");
			free(tempparsed10);

		}

		else if(strcmp(parsed[0], "SUB") == 0)
		{
			clock_t start, end;
			start = clock();
			char* parsed1copy[2];
			parseComma(parsed[1], parsed1copy);
			char* parsed2copy[2];
			parseComma(parsed[2], parsed2copy);
			char* parsed1[2];
			// parsed1[0] = malloc((int)strlen(parsed1copy[0]) -1);
			int nikita = (int)strlen(parsed1copy[0]) - 1;
			char* tempparsed10= malloc(nikita+1);
			for(int i=0; i<nikita ; i++)
				{
					tempparsed10[i] = parsed1copy[0][i+1];
				}
				tempparsed10[nikita] = '\0';
			char* tempparsed11 = malloc((int)strlen(parsed1copy[1]));
			parsed1[1] = tempparsed11;
			parsed1[0] = tempparsed10;
			// parsed1[0] = rtrim(tempparsed10, NULL);		

			for(int i=0; i<(int)strlen(parsed1copy[1]) - 1; i++)
				parsed1[1][i]=parsed1copy[1][i];
			parsed1[1][(int)strlen(parsed1copy[1]) - 1] = '\0';



			char* parsed2[2];
			parsed2[0] = malloc((int)strlen(parsed2copy[0]));
			for(int i=0; i<(int)strlen(parsed2copy[0]) - 1; i++)
				parsed2[0][i]=parsed2copy[0][i+1];

			parsed2[0][(int)strlen(parsed2copy[0]) - 1] = '\0';

			parsed2[1] = malloc((int)strlen(parsed2copy[1]));
			for(int i=0; i<(int)strlen(parsed2copy[1]) - 1; i++)
				parsed2[1][i]=parsed2copy[1][i];

			parsed2[1][(int)strlen(parsed2copy[1]) - 1] = '\0';
			//result 1 start by adding parsed1[0] and parsed2[0]
			char** add1 = malloc(3);
			add1[0] = "SUB";
			add1[1] = parsed1[0];
			add1[2] = parsed2[0];
			fprintf(ft, "(");
					bool isfinalplus = true;
					bool isp1plus = true;
					bool isp2plus = true;
			if( (int) add1[1][0] == 45)
			{
					add1[1] = ltrim (add1[1], "-");
					isp1plus = false;
			}
			if ((int) add1[2][0] == 45) 
			{
				add1[2] = ltrim (add1[2], "-");
				isp2plus = false;
			}
			if(!isp1plus && !isp2plus && compare(add1) == 1 ) {
				isfinalplus = false;
				fprintf(ft, "-");
				sub(add1,ft);
			}
			else if(!isp1plus && !isp2plus && compare(add1) == -1)
			{
				isfinalplus = true;
				char* parsedcopy[3];
				char t[3] = "SUB";
				parsedcopy[0] = t;
				parsedcopy[1] = add1[2];
				parsedcopy[2] = add1[1];

				sub(parsedcopy,ft);
			}
			else if(isp1plus && isp2plus && compare(add1) == 1)
			{
				isfinalplus = true;
				sub(add1,ft);	
			}
			else if(isp1plus && isp2plus && compare(add1) == -1)
			{
				isfinalplus = false;
				char* parsedcopy[3];
				parsedcopy[0] = "SUB";
				parsedcopy[1] = add1[2];
				parsedcopy[2] = add1[1];
				fprintf(ft, "-");
				sub(parsedcopy,ft);

			}

			else if(isp1plus && !isp2plus)
			{
				isfinalplus = true;
				add(add1, ft);
			}
			else if(!isp1plus && isp2plus)
			{
				isfinalplus = false;
				fprintf(ft, "-");
				add(add1, ft);
			}


			fprintf(ft, ",");
			//result 1 ends
			//result 2 starts
			char** add2 = malloc(3);
			add2[0] = "ADD";
			add2[1] = parsed1[1];
			add2[2] = parsed2[1];

					isfinalplus = true;
					isp1plus = true;
					isp2plus = true;
			if( (int) add2[1][0] == 45)
			{
					add2[1] = ltrim (add2[1], "-");
					isp1plus = false;
			}
			if ((int) add2[2][0] == 45) 
			{
				add2[2] = ltrim (add2[2], "-");
				isp2plus = false;
			}


			if(!isp1plus && !isp2plus && compare(add2) == 1 ) {
				isfinalplus = false;
				fprintf(ft, "-");
				sub(add2,ft);
			}
			else if(!isp1plus && !isp2plus && compare(add2) == -1)
			{
				isfinalplus = true;
				char* parsedcopy[3];
				char t[3] = "SUB";
				parsedcopy[0] = t;
				parsedcopy[1] = add2[2];
				parsedcopy[2] = add2[1];

				sub(parsedcopy,ft);
			}
			else if(isp1plus && isp2plus && compare(add2) == 1)
			{
				
				isfinalplus = true;
				sub(add2,ft);	
			}

			else if(isp1plus && !isp2plus)
			{
				isfinalplus = true;
				add(add2, ft);
			}

			else if(isp1plus && isp2plus && compare(add2) == -1)
			{
				isfinalplus = false;
				char* parsedcopy[3];
				char t[3] = "SUB";
				parsedcopy[0] = "SUB";
				parsedcopy[1] = add2[2];
				parsedcopy[2] = add2[1];
				fprintf(ft, "-");
				sub(parsedcopy,ft);

			}

			else if(!isp1plus && isp2plus)
			{
				isfinalplus = false;
				fprintf(ft, "-");
				add(add2, ft);
			}
			fprintf(ft, ")\n");
			end = clock();
			double time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
			// printf("time_taken in sub : %f\n", time_taken);
		}

		else if(strcmp(parsed[0], "PROD") == 0)
		{
			clock_t start, end;
			start = clock();
			char* parsed1copy[2];
			parseComma(parsed[1], parsed1copy);
			char* parsed2copy[2];
			parseComma(parsed[2], parsed2copy);
			char* parsed1[2];
			int nikita = (int)strlen(parsed1copy[0]) - 1;
			char* tempparsed10= malloc(nikita+1);
			for(int i=0; i<nikita ; i++)
				{
					tempparsed10[i] = parsed1copy[0][i+1];
				}
				tempparsed10[nikita] = '\0';
			char* tempparsed11 = malloc((int)strlen(parsed1copy[1]));
			parsed1[1] = tempparsed11;
			parsed1[0] = tempparsed10;
			
			int y=0;
			for(y=0; y<(int)strlen(parsed1copy[1]) - 1; y++)
				{
					if((int)parsed1copy[1][y] == 41)
						{
							break;
						}
					parsed1[1][y]=parsed1copy[1][y];
				}
			parsed1[1][y] = '\0';
			char* parsed2[2];
			parsed2[0] = malloc((int)strlen(parsed2copy[0]));
			for(int i=0; i<(int)strlen(parsed2copy[0]) - 1; i++)
				parsed2[0][i]=parsed2copy[0][i+1];

			parsed2[0][(int)strlen(parsed2copy[0]) - 1] = '\0';
			parsed2[1] = malloc((int)strlen(parsed2copy[1]) -1);
			for(int i=0; i<(int)strlen(parsed2copy[1]) - 1; i++)
				parsed2[1][i]=parsed2copy[1][i];

			parsed2[1][(int)strlen(parsed2copy[1]) - 1] = '\0';


			// printf("parsed1[0] is : %s\n", parsed1[0]);//a
			// printf("parsed1[1] is : %s\n", parsed1[1]);//b
			// printf("parsed2[0] is : %s\n", parsed2[0]);//c
			// printf("parsed2[1] is : %s\n", parsed2[1]);//d
			char* uper[2];
			char* temp1 = malloc(100);
			temp1[0] = '(';
			int i=0;
			for(i=0; i<strlen(parsed1[0]); i++)
			{
				temp1[i] - parsed1[0][i];
			}
			temp1[i] = ',';
			int j=0;
			for(j=0; j<strlen(parsed1[1]); j++)
			{
				temp1[i+j] = parsed1[1][j];
			}

			temp1[i+j]=')';
			temp1[i+j+1] = '\0';



			char* temp2 = malloc(100);
			temp2[0] = '(';
			i=0;
			for(i=0; i<strlen(parsed2[0]); i++)
			{
				temp2[i] = parsed2[0][i];
			}
			temp2[i] = ',';

			if(parsed2[1][0] != '-')
			{
				temp2[i+1] = '-';
				int j=0;
				for(j=0; j<strlen(parsed2[1]); j++)
				{
					temp2[i+j+1] = parsed2[1][j];
				}

				temp2[i+j+1]=')';
				temp2[i+j+2] = '\0';
			}

			else
			{
				int j=0;
				for(j=1; j<strlen(parsed2[1]); j++)
				{
					temp2[i+j-1] = parsed2[1][j];
				}
				temp2[i+j-1] = ')';
				temp2[i+j] = '\0';
			}





			//real part start
			//finding ac
			char* ac1 = mulhelperac(parsed1[0], parsed2[0]); //a*c
			
			int count=0;
			while((ac1[0]=='0') && (ac1[1] != '.'))
			{
				for(int i=0; i<(int)strlen(ac1)-1; i++)
				{
					ac1[i] = ac1[i+1];
				}
				count++;
				// ac[i] = '\0';
			}
			char* ac = malloc((int)strlen(ac1) - count);

			for(int i=0; i<(int)strlen(ac1) - count; i++)
			{
				ac[i]=ac1[i];
			}
			ac[(int)strlen(ac1) - count] = '\0';
			char* bd1 = mulhelperac(parsed1[1], parsed2[1]);
			
			count=0;
			while(bd1[0]=='0' && bd1[1] != '.')
			{
				for(int i=0; i<(int)strlen(bd1)-1; i++)
				{
					bd1[i] = bd1[i+1];
				}
				count++;
			}

			
			char* bd = malloc((int)strlen(bd1) - count+1);
			for(int i=0; i<(int)strlen(bd1) - count; i++)
			{
				bd[i] = bd1[i];
			}

			bd[(int)strlen(bd1) - count] = '\0';
			char* ret1 = malloc(maximum((int)strlen(ac), (int)strlen(bd))+2); 
				ret1 = subhelperac(ac, bd); //final ka real

			//real part end

				//imag part start
				//finding ac
			
			char* ad1 = mulhelperac(parsed1[0], parsed2[1]); //a*d
			
			count=0;
			while((ad1[0]=='0') && (ad1[1] != '.'))
			{
				for(int i=0; i<(int)strlen(ad1)-1; i++)
				{
					ad1[i] = ad1[i+1];
				}
				count++;
			}
			char* ad = malloc((int)strlen(ad1) - count);

			for(int i=0; i<(int)strlen(ad1) - count; i++)
			{
				ad[i]=ad1[i];
			}
			ad[(int)strlen(ad1) - count] = '\0';
			char* bc1 = mulhelperac(parsed1[1], parsed2[0]);
			
			count=0;
			while(bc1[0]=='0' && bc1[1] != '.')
			{
				for(int i=0; i<(int)strlen(bc1)-1; i++)
				{
					bc1[i] = bc1[i+1];
				}
				count++;
			}

			char* bc = malloc((int)strlen(bc1) - count);
			for(int i=0; i<(int)strlen(bc1) - count; i++)
			{
				bc[i]=bc1[i];
			}
			char* ret2 = malloc(maximum((int)strlen(ad), (int)strlen(bc))); 
				ret2 = addhelperac(ad, bc); //final ka imag
				//imag part end

				fprintf(ft, "(%s,%s)\n", ret1, ret2);
				end = clock();
			double time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
			printf("time_taken in PROD : %f\n", time_taken);
		}


		else if(strcmp(parsed[0], "QUOT") == 0)
		{

			clock_t start, end;
			start = clock();
			char* ret = quotprod(parsed);
			fprintf(ft, "%s\n", ret);
			end = clock();
			double time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
			printf("time_taken in QUOT : %f\n", time_taken);
			// char* parseed[3];

		 	// parseSpace(ret, parseed);
		 	// parseed[2] = parsed[2];
		 	// parseed[1] = ret;
		 	// parseed[0] = "MUL";
		 	// printf("%s %s %s\n", parseed[0], parseed[1], parseed[2]);
		 	// printf("FINAL\n");
		 	// testing(parseed);

		}
		else if(strcmp(parsed[0], "DIV") == 0)
		{
			bool isfinalplus=true;
			if( (int) parsed[1][0] == 45)
			{	isfinalplus = false;
					parsed[1] = ltrim (parsed[1], "-");
					isp1plus = false;
			}
			if ((int) parsed[2][0] == 45) 
			{
				if(isfinalplus) isfinalplus=false;
				else isfinalplus=true;
				parsed[2] = ltrim (parsed[2], "-");
				isp2plus = false;
			}
			if(!isfinalplus) fprintf(ft, "-");

			

			int float1 =25;
			int float2=0;
			bool ispoint1 = false;
			char* newstr = malloc((int)strlen(parsed[1])+25);
			for(int i=0; i<(int)strlen(parsed[1])+25; i++)
				newstr[i]='0';



			for(int i=0; i<strlen(parsed[1]); i++)
			{
				if(parsed[1][i] == '.')
				{
					ispoint1=true;
				}
				else if(ispoint1)
				{
					float1++;
					newstr[i-1] = parsed[1][i];
				}
				else
				{
					newstr[i] = parsed[1][i];
				}
			}

			bool ispoint2 = false;
			char* newstr2 = malloc((int)strlen(parsed[2]));
			for(int i=0; i<strlen(parsed[2]); i++)
			{
				if(parsed[2][i] == '.')
				{
					ispoint2=true;
				}
				else if(ispoint2)
				{
					float2++;
					newstr2[i-1] = parsed[2][i];
				}
				else
				{
					newstr2[i] = parsed[2][i];
				}
			}

			int divisor = atoi(newstr2);
			// printf("newstr : %s\n",newstr);
			char* ret = longDivision(newstr, divisor);
			int finalfloat = float1-float2;
			// printf("final ret : %s %d\n",ret, divisor);
			if(finalfloat >=(int)strlen(ret))
			{
				int kitna  = finalfloat-(int)strlen(ret);
				fprintf(ft, "0.");
				for(int i=0; i<kitna; i++)
					fprintf(ft, "0");
				fprintf(ft, "%s", ret);
			}
			else{


			bool tempbool=false;
			int count=0;
			for(int i=0; i<strlen(ret); i++)
			{
				if(i==strlen(ret)-finalfloat)
				{
					count=0;
					tempbool = true;
					fprintf(ft, ".");
				}
				count++;
				if(tempbool && count == 21) break;
				fprintf(ft, "%c", ret[i]);
			}
			}
			fprintf(ft, "\n");

			//divi(parsed);
		}

		else if(strcmp(parsed[0], "ABS") == 0)
		{
			// printf("ManojKumarABS\n");
			char* parsed1copy[2];
			parseComma(parsed[1], parsed1copy);

			char* parsed1[2];
			int nikita = (int)strlen(parsed1copy[0]) - 1;
			char* tempparsed10= malloc(nikita+1);
			for(int i=0; i<nikita ; i++)
				{
					tempparsed10[i] = parsed1copy[0][i+1];
				}
				tempparsed10[nikita] = '\0';
			char* tempparsed11 = malloc((int)strlen(parsed1copy[1]));
			parsed1[1] = tempparsed11;
			parsed1[0] = tempparsed10;
			
			int y=0;
			for(y=0; y<(int)strlen(parsed1copy[1]) - 1; y++)
				{
					if((int)parsed1copy[1][y] == 41)
						{
							break;
						}
					parsed1[1][y]=parsed1copy[1][y];
				}
			parsed1[1][y] = '\0';


			// printf("parsed1[0] is : %s\n", parsed1[0]);//a
			// printf("parsed1[1] is : %s\n", parsed1[1]);//b
			clock_t start, end;
			start = clock();
			char* d1 = mulhelperac(parsed1[0], parsed1[0]);
			char* d2 = mulhelperac(parsed1[1], parsed1[1]);
			char* d = addhelperac(d1, d2);
			char* str;
			double t = strtod(d, &str);
			double t2 = sqrt(t);
			fprintf(ft, "(%lf,0)\n", t2);
			end = clock();
			double time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
			printf("time_taken in ABS : %f\n", time_taken);
		// printf("end of loop\n");
		}
	}
	fclose(fp);
	fclose(ft);
/*
FILE *gnuplotPipe=popen("gnuplot -persistent", "w");
fprintf(gnuplotPipe, "%s\n","set ylabel \"Time (milisecond)\"");
fprintf(gnuplotPipe, "%s\n","set xlabel \"Complex Arithmetic\"");
fprintf(gnuplotPipe, "%s\n","set terminal pdf");
fprintf(gnuplotPipe, "%s \"%s\" \n","set output", argv[3]);
fprintf(gnuplotPipe, "%s\n","plot 'data.txt' using with lines title \"speed km/her\" lw 2, 'data.txt' using 1:3 with linespoints title \"Age\"");


*/


// char* map = "\"ADD\" 0.25, \"SUB\" 1.75, \"PROD\" 3.25, \"QUOT\" 4.75, \"ABS\" 6.0,";
	FILE *gnuplotPipe=popen("gnuplot -persistent", "w");
	// fprintf(gnuplotPipe, "plot [-4:4] exp(-x**2 / 2)");
	fprintf(gnuplotPipe, "%s\n","set ylabel \"Time (milisecond)\"");
	fprintf(gnuplotPipe, "%s\n","set xlabel \"Complex Arithmetic(ADD, SUB, PROD, QUOT, ABS)\"");
	fprintf(gnuplotPipe, "%s\n","set style line 1 lc rgb 22851769");
	fprintf(gnuplotPipe, "%s\n","set style line 2 lc rgb 82490951");
	fprintf(gnuplotPipe, "set xtics (%s)\n", "\"ADD\" 0.25, \"SUB\" 1.75, \"PROD\" 3.25, \"QUOT\" 4.75, \"ABS\" 6.0,");
	fprintf(gnuplotPipe, "%s\n","set boxwidth 0.5");
	fprintf(gnuplotPipe, "%s\n","set style fill solid");
	fprintf(gnuplotPipe, "%s\n","set terminal png size 1180, 630");
	fprintf(gnuplotPipe, "%s \"%s\" \n","set output", argv[3]);

	// fprintf(gnuplotPipe, "%s\n","set style line 2 lc rgb 82490951");
	fprintf(gnuplotPipe, "%s\n","plot 'data.txt' every 2 using 1:2 with boxes ls 1 title \"arbprecision\", 'data.txt' every 2::1 using 1:2 with boxes ls 2 title\"standard c library\"");
    return 0;
}
