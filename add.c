#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdbool.h> 

#include "arbprecision.h"
#define _GNU_SOURCE

void add ( char** parsed, FILE* ft) 
	//parsed is an array with size 3, parsed[0] is "ADD", parsed[1] is the first number in string form, parsed[2] is the second numebr in string form.
	//and ft to print output in a file.
{
		bool isfloat = false;	//boolean that indicates whether the resulant is a floating point number or an integer.
		bool iscarry = false;	//boolean that will be used later when we will add one to one digit.
		bool isparsed11fill = false; 
		bool isparsed10fill = false;
		bool isparsed21fill = false;
		bool isparsed20fill = false;

		//parsed
		char* parsed1[2];	//it is an array of string with size 2, it will use to store the both sides of point in the first number(parsed[1]).
		char* parsed2[2];	//it is an array of string with size 2, it will use to store the both sides of point in the second number(parsed[2]).
		parsePoint(parsed[1], parsed1); //this function call fills parsed1
		parsePoint(parsed[2], parsed2);	//this function call fills parsed2
		char* parsed11; //equivalent to parsed1[1] i.e. fraction part of first number.
		char* parsed21; //fraction part of second number
		if(parsed1[1] != NULL || parsed2[1] != NULL) //if any one of both numbers is not an integer, then change isfloat to true.
			isfloat = true;
//one int one float case start
		if(isfloat && parsed1[1] ==NULL) //if first number is integer and 2nd one is not.
			{
				parsed11 = malloc(strlen(parsed2[1])); 
				for(int i=0; i<strlen(parsed2[1]); i++) //assign parsed11 to be "00000.....0000"
					parsed11[i] = '0';
				parsed21 = parsed2[1]; //filled with fraction part of second number
				isparsed21fill = true;	//boolean that indicates that parsed21 is not null
				isparsed11fill = true;	//boolean that indicates that parsed11 is not null
			}
		else if(isfloat && parsed2[1] ==NULL)	//if second number is integer and 1st one is not.
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

//making parsed1[0] and parsed2[0] of same size(length) start
		int a = maximum((int)strlen(parsed1[0]), (int)strlen(parsed2[0])); //maximum size of both integer parts.
		char* parsed20; //integer part of 2nd number.
		char* parsed10;	//integer part of 1st number.
	    if(a>(int)strlen(parsed1[0])) //if the length of parsed2[0] is greater than parsed1[0]
	    {
	      parsed10 = malloc(a-(int)strlen(parsed1[0]));
	      for(int i=0; i<a-(int)strlen(parsed1[0]); i++)
			parsed10[i]='0';
	      for(int j=0; j<(int)strlen(parsed1[0]); j++)
	      	parsed10[a-(int)strlen(parsed1[0])+j] = parsed1[0][j];
	      parsed20 = parsed2[0];
	      isparsed20fill = true;
	      isparsed10fill = true;
	    }
	    else if(a>(int)strlen(parsed2[0])) //if the length of parsed1[0] is greater than parsed2[0]
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
	    	//now the length of parsed10 and parsed20 is same by adding necessary 0s in begin.
//making parsed1[0] and parsed2[0] of same size(length) end

//In case of float, making parsed11 and parsed21 of same length by adding 0s on left side.
	    int a2 = 0;
	    if(isfloat)
	    {
	    	a2 = maximum(strlen(parsed11), strlen(parsed21));
	    }
	    int finalarray2 [a2]; //fractional part of the final result will be stored here.
	    if(isfloat) //if final result is true.
	    {
		    if(a2>strlen(parsed11)) //making parsed11 of same length as parsed21.
		    {
		      char* temp2 = malloc(a2);
		      for(int j=0; j<strlen(parsed11); j++)
		      	temp2[j] = parsed11[j];
		      for(int i=0; i<a2-(int)strlen(parsed11); i++)
				temp2[(int)strlen(parsed11) + i] = '0';
		      parsed11 = temp2;
		    }

		    else if(a2>strlen(parsed21)) //making parsed21 of same length as parsed11.
		    {
		      char* temp2 = malloc(a2);
		      for(int j=0; j<strlen(parsed21); j++)
		      	temp2[j] = parsed21[j];
		      for(int i=0; i<a2-(int)strlen(parsed21); i++)
				temp2[strlen(parsed21) + i] = '0';
		      parsed21 = temp2;

		    }
		    //Now parsed11 and parsed21 are of same length.
		  	//Addition process begins
		    int carry = 0;
			  for(int i=a2-1; i>=0; i--)
			  {
			    finalarray2[i] = (int)parsed11[i]+(int)parsed21[i] + carry - 48 -48;
			    carry = finalarray2[i]/10;
			    finalarray2[i] = finalarray2[i]%10;
			  }
			 	if(carry == 1) iscarry = true;
		}
		//fraction part of the final resultant is calculated.
//sum of integer part
		int finalarray1[a+1];
		  int carry = 0;
		if(iscarry)
		{
			carry++;
		}
		
		  for(int i=a-1; i>=0; i--)
		  {
		    int b = (int)parsed10[i]+(int)parsed20[i] + carry - 48 -48;
		    carry = b/10;
		    finalarray1[i+1] = b%10;
		  }
		    finalarray1[0] = carry;
//Final result calculated.

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
}
