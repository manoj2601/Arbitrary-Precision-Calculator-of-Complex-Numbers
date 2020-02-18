#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdbool.h> 

#include "arbprecision.h"
#define _GNU_SOURCE

void sub (char** parsed, FILE* ft)  //parsed[1] is always greater than parsed[2]
{
		bool isfloat = false;
		bool iscarry = false;
		bool isparsed11fill = false;
		bool isparsed10fill = false;
		bool isparsed21fill = false;
		bool isparsed20fill = false;


		//parsed
		char* parsed1[2];
		char* parsed2[2];
		parsePoint(parsed[1], parsed1);
		parsePoint(parsed[2], parsed2);

		char* parsed11;
		char* parsed21;

		if((parsed1[1] != NULL) || (parsed2[1] != NULL))
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
				// printf("lol%send\n", parsed1[1]);
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

			isparsed20fill = true;
	      isparsed10fill = true;	      
	    }

	    if(!isparsed20fill) parsed20 = parsed2[0];

	    if(!isparsed10fill) {
	    		parsed10 = parsed1[0];
	    	}
		//parsedi[0] ko same size ka bna diya
	    int a2 = 0;
	    if(isfloat)
	    {
	    	a2 = maximum((int)strlen(parsed11), (int)strlen(parsed21));
	    }
	    // printf("a2 is : %d\n", (int)strlen(parsed21));
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

		    int arr1int[a2];
		    int arr2int[a2];
		    for(int i=0; i<a2; i++)
		    {
		    	arr1int[i] = (int)parsed11[i] - 48;
		    	arr2int[i] = (int)parsed21[i] - 48;
		    }

		      for(int i=a2-1; i>0; i--)
			  {
				if(arr1int[i]<0)
				{
					arr1int[i] += 10;
					arr1int[i-1] -= 1;
				}
			    int a3 = arr1int[i]-arr2int[i];
				if(a3<0)
				{
					a3=a3+10;
					arr1int[i-1] -= 1;
				}
				finalarray2[i] = a3;
			  }

			  //last loop
			  if(arr1int[0] < 0)
			  {
			  	arr1int[0] += 10;
			  	iscarry = true;
			  }
			  int a3 = arr1int[0] - arr2int[0];
			  if(a3<0)
			  {
			  	a3 = a3+10;
			  	iscarry = true;
			  }
			  finalarray2[0] = a3;
			}
			// printf("\nfinalarray2 is : ");
			// for(int h=0; h<a2; h++)
			// {
			// 	printf("%d", finalarray2[h]);
			// }
			// printf("\n");
			  //last loop ends here
			  //parsedi[1] ko same size ka bna diya
		//floats ka sub ho gyaa
			    //integers ka sub
		//parsedi[0] ko same size ka bna diya
		int finalarray1[a];
		  int carry = 0;
		if(iscarry)
		{
			carry--;
		}
		int arr1int[a];
		int arr2int[a];
		    for(int i=0; i<a; i++)
		    {
		    	arr1int[i] = (int)parsed10[i] - 48;
		    	arr2int[i] = (int)parsed20[i] - 48;
		    }
		    if(iscarry)
		    {
		    	arr1int[a-1]--;
		    }
		      for(int i=a-1; i>=0; i--)
			  {
				if(arr1int[i]<0)
				{
					arr1int[i] += 10;
					arr1int[i-1] -= 1;
				}
			    int a3 = arr1int[i]-arr2int[i];
				if(a3<0)
				{
					a3=a3+10;
					arr1int[i-1] -= 1;
				}
				finalarray1[i] = a3;
			  }
			  int i=0;
			  while(finalarray1[i] == 0 && i < a-1)
			  {
			  	i++;
			  	continue;
			  }

			  for(i=i; i<a; i++)
			  	fprintf(ft,"%d", finalarray1[i]);
			  if(isfloat)
			  {

			  	fprintf(ft,".");
			  	for(i=0; i<a2; i++)
			  	{
			  		fprintf(ft,"%d", finalarray2[i]);
			  	}
			  }
			  // printf("\n");
}
