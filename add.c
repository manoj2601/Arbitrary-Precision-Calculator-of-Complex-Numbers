#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdbool.h> 

#include "arbprecision.h"
#define _GNU_SOURCE

void add ( char** parsed, FILE* ft)// char* array1, char* array2, int* finalarray, int size)
{		//parsing with respect to point
		bool isfloat = false;
		bool iscarry = false;
		bool isparsed11fill = false;
		bool isparsed10fill = false;
		bool isparsed21fill = false;
		bool isparsed20fill = false;

		// fprintf(ft, "add me aaya\n");
		//parsed
		char* parsed1[2];
		char* parsed2[2];
		parsePoint(parsed[1], parsed1);
		parsePoint(parsed[2], parsed2);
		// if(parsed1[0][(int)strlen(parsed1[0]) -1] )
			// printf("last of parsed1[0] is : %c\n",parsed1[0][(int)strlen(parsed1[0]) -1]);
		char* parsed11;
		char* parsed21;

		if(parsed1[1] != NULL || parsed2[1] != NULL)
			isfloat = true;
		//one int one float case start
		if(isfloat && parsed1[1] ==NULL)
			{
				parsed11 = malloc(strlen(parsed2[1]));
				for(int i=0; i<strlen(parsed2[1]); i++)
					parsed11[i] = '0';
				parsed21 = parsed2[1];
				isparsed21fill = true;
				isparsed11fill = true;
			}
		else if(isfloat && parsed2[1] ==NULL)
			{
				parsed21 = malloc(strlen(parsed1[1]));
				for(int i=0; i<strlen(parsed1[1]); i++)
					parsed21[i] = '0';
				parsed11 = parsed1[1];
				isparsed11fill = true;
				isparsed21fill = true;
			}
			if(isfloat){
			if(!isparsed11fill) {
				parsed11 = parsed1[1];}
			if(!isparsed21fill) {
				parsed21 = parsed2[1];}
		}

			//one int one float case end
			//parsedi[0] ko same size ka bnana hai
		int a = maximum((int)strlen(parsed1[0]), (int)strlen(parsed2[0]));
		char* parsed20;
		char* parsed10;
	    if(a>(int)strlen(parsed1[0]))
	    {
	      parsed10 = malloc(a-(int)strlen(parsed1[0]));
	      for(int i=0; i<a-(int)strlen(parsed1[0]); i++)
			parsed10[i]='0';
	      for(int j=0; j<(int)strlen(parsed1[0]); j++)
	      	parsed10[a-(int)strlen(parsed1[0])+j] = parsed1[0][j];
	      parsed20 = parsed2[0];
	      isparsed20fill = true;
	      isparsed10fill = true;

	      // strcat(parsed10, parsed1[0]);
	    }
	    else if(a>(int)strlen(parsed2[0]))
	    {
	      parsed20 = malloc(a-(int)strlen(parsed2[0]));
	      for(int i=0; i<a-(int)strlen(parsed2[0]); i++)
			parsed20[i]='0';

	      for(int j=0; j<(int)strlen(parsed2[0]); j++)
	      	parsed20[a-(int)strlen(parsed2[0])+j] = parsed2[0][j];

	      parsed10 = parsed1[0];
	      // printf("are u here %c\n",parsed1[0][a-3]);
			isparsed20fill = true;
	      isparsed10fill = true;	      
	    }
	    if(!isparsed20fill) parsed20 = parsed2[0];

	    if(!isparsed10fill) {
	    	// printf("are u here\n");
	    		parsed10 = parsed1[0];
	    	}
		//parsedi[0] ko same size ka bna diya
	    int a2 = 0;
	    if(isfloat)
	    {
	    	a2 = maximum(strlen(parsed11), strlen(parsed21));
	    }
	    int finalarray2 [a2];
	    

		//parsedi[1] ko same size ka bnana hai and resultant finalarray2 bhi nikalna hai
	    if(isfloat)
	    {
		    if(a2>strlen(parsed11))
		    {
		      char* temp2 = malloc(a2);
		      for(int j=0; j<strlen(parsed11); j++)
		      	temp2[j] = parsed11[j];
		      for(int i=0; i<a2-(int)strlen(parsed11); i++)
				temp2[(int)strlen(parsed11) + i] = '0';
		   
		      parsed11 = temp2;
		    }

		    else if(a2>strlen(parsed21))
		    {
		      char* temp2 = malloc(a2);
		      for(int j=0; j<strlen(parsed21); j++)
		      	temp2[j] = parsed21[j];
		      for(int i=0; i<a2-(int)strlen(parsed21); i++)
				temp2[strlen(parsed21) + i] = '0';
		      parsed21 = temp2;

		    }

		    
		    int carry = 0;
			  for(int i=a2-1; i>=0; i--)
			  {
			    finalarray2[i] = (int)parsed11[i]+(int)parsed21[i] + carry - 48 -48;
			    carry = finalarray2[i]/10;
			    finalarray2[i] = finalarray2[i]%10;
			  }
			 	if(carry == 1) iscarry = true;
		}
		// printf("resulatant finalarray2 ki size %d\n", a2);
		//parsedi[1] ko same size ka bna diya
		//floats ka sum ho gyaa
			    //integers ka sum
		//parsedi[0] ko same size ka bna diya
		int finalarray1[a+1];
		  int carry = 0;
		if(iscarry)
		{
			carry++;
		}
		
		  for(int i=a-1; i>=0; i--)
		  {
		    int b = (int)parsed10[i]+(int)parsed20[i] + carry - 48 -48;
		    // if(i==a-1) printf("(int)parsed10[i] is : %c\n", parsed10[i]);
		    carry = b/10;
		    finalarray1[i+1] = b%10;
		  }
		    finalarray1[0] = carry;
		//printing result
		if(finalarray1[0] != 0 && a!= 0)
			fprintf(ft,"%d",finalarray1[0]);

		for(int i=1; i<a+1; i++)
			fprintf(ft,"%d",finalarray1[i]);
		if(isfloat)
		{
			fprintf(ft,".");
			for(int i=0; i<a2; i++)
				fprintf(ft,"%d", finalarray2[i]);
		}
		// free(parsed11);
		// free(parsed21);
		// free(parsed10);
		// free(parsed10);
		// printf("\n");
}
