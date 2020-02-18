#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdbool.h>

#include "arbprecision.h"
#define _GNU_SOURCE 

int maximum (int a, int b)
{
  if(a>b) return a;
  else return b;
}

int* shift_left(int dividend[], int size)
{
	
	// printf("size is shift_left%d\n", size);
	for(int i=0; i<size-1; i++)
		dividend[i]= dividend[i+1];

	dividend[size-1] = 0;
}

int* subhelper(int dividend[], int divsize, int arr1[], int arr1size)
{
	char* parsed[3];
	parsed[0] = "SUB";
	int starter = 0;
	int j=0;
		if(dividend[j] == 0 && j<divsize)
		{
			arr1size--;
			starter++;
			j++;
		}
	char* parsed1temp=malloc(divsize);
	for(int i=0; i<divsize; i++)
		parsed1temp[i] = (char) (dividend[i] + 48);

	char* parsed2temp=malloc(arr1size);
	for(int i=0; i<arr1size; i++)
		parsed2temp[i] = (char) (arr1[i] + 48);
	// printf("parse1temp is : %s\n", parsed1temp);
	// printf("parse2temp is : %s\n", parsed2temp);
	parsed[1] = parsed1temp;
	parsed[2] = parsed2temp;

	//copying sub wala code
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
	    
	    //parsedi[1] ko same size ka bnana hai and resultant finalarray2 bhi nikalna hai

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
			    int a = arr1int[i]-arr2int[i];
				if(a<0)
				{
					a=a+10;
					arr1int[i-1] -= 1;
				}
				finalarray1[i] = a;
			  }
			  
			  int i=0;
			  // while(finalarray1[i] == 0 && i!= a-1)
			  // {
			  // 	i++;
			  // 	continue;
			  // }

			  //copy end
			  int* ret = malloc(a-i);
			  for(int j=i; j<a; j++)
			  	ret[j-i] = finalarray1[j];
			  // printf("finalarr1 is : ");
			  // for(int i=0; i<a; i++)
			  // 	printf("%d", ret[i]);
			  	// printf("%d", finalarray1[i]);

			  return ret;
}

int minimum (int a, int b)
{
  if(a>b) return b;
  else return a;
}

int ismore(int* arr, int* arr2, int arrsize1, int arrsize2)
{
	int arr1size = arrsize1;
	int arr2size = arrsize2;

	// int arr1size = ((int)sizeof(arr1))/4;
	// printf("ass1 ki size %d\n", arr1size);
	// int arr2size = sizeof(arr2)/4;
	// 	printf("ass2 ki size %d\n", arr2size);
	bool ssss=true;
	int arr1[arr1size+2];
	for(int i=0; i<arr1size; i++)
		arr1[i] = 0;

	// printf("inside ismore a is : %d\n", arr1size);

	for(int i=0; i<arr1size; i++)
		{
			// printf("%d \n",arr[i]);
			int a = arr[i];
			arr1[i] = a;
		}

	for(int i=0; i<arr1size; i++)
	{
		if(arr1[i] != 0)
		{
			ssss=false;
		}
	}
	
	if(ssss) return 2;
	if(arr1[0] < 0) return 2;
	int j=0;
	int starter = 0;

		while(arr1[j] == 0 && j<arr1size)
		{
			arr1size--;
			starter++;
			j++;
		}
	if(arr1size>arr2size) {
		

		return 1;
	}
	else if(arr1size<arr2size) return 2;

	for(int i=0; i<minimum(arr1size-starter, arr2size); i++)
	{
		if(arr1[i+starter] > arr2[i])
			{
				return 1;
			}
		else if(arr1[i+starter] < arr2[i])
			{
				// printf("dgoewhige111\n");
				return 2;
			}
	}
	return 1;
}

char *rtrim(char *str, const char *seps)
{
    int i;
    if (seps == NULL) {
        seps = "\t\n\v\f\r ";
    }
    i = strlen(str) - 1;
    while (i >= 0 && strchr(seps, str[i]) != NULL) {
        str[i] = '\0';
        i--;
    }
    return str;
}

char *ltrim(char *str, const char *seps)
{
    size_t totrim;
    if (seps == NULL) {
        seps = "\t\n\v\f\r ";
    }
    totrim = strspn(str, seps);
    if (totrim > 0) {
        size_t len = strlen(str);
        if (totrim == len) {
            str[0] = '\0';
        }
        else {
            memmove(str, str + totrim, len + 1 - totrim);
        }
    }
    return str;
}


void parsePoint(char* input, char** parsed)
{
	// 	int y1=0;
	// 	for(int i=0; i<(int)strlen(input); i++)
	// 	{
	// 		if(input[i] == '.')
	// 		{
	// 			break;
	// 		}
	// 		y1++;
	// 	}

	// 	char temp[y1];
	// 	for(int i=0; i<y1; i++)
	// 	{
	// 		temp[i]=input[i];
	// 	}
	// 	parsed[0] = temp;
	// 	if(y1 == (int)strlen(input))
	// 	{
	// 		parsed[1] = NULL;
	// 	}
	// 	else
	// 	{
	// 		char temp2[(int)strlen(input) - y1 - 1];
	// 		for(int i=0; i<(int)strlen(input) - y1 - 1; i++)
	// 		{
	// 			temp2[i] = input[i+y1+1];
	// 		}
	// 		parsed[1] = temp2;
	// 	}
	// 	printf("fdffdfddfd\n");
	// 	parsed[1] = rtrim (parsed[1], NULL);
	// }


	char* inputString = calloc((int)strlen(input)+1,1);

	for(int i=0; i<(int)strlen(input); i++)
		inputString[i]=input[i];
    int i=0;
    while(1)
    {
        parsed[i] = strsep(&inputString, ".\n");
        if(parsed[i] == NULL) break;
        if(strlen(parsed[i]) == 0)
            i--;
        i++;
    }
    free(inputString);
    parsed[i-1] = rtrim (parsed[i-1], NULL);
}


void parseComma(char* input, char** parsed)
{
	char* inputString = malloc((int)strlen(input));
	for(int i=0; i<(int)strlen(input); i++)
		inputString[i]=input[i];
    int i=0;

    while(1)
    {
        parsed[i] = strsep(&inputString, ",");
        if(parsed[i] == NULL) break;
        if(strlen(parsed[i]) == 0)
            i--;
        i++;
    }
    parsed[i-1] = rtrim (parsed[i-1], NULL);
}

void parseSpace(char* input, char** parsed)
{
	char* inputString = malloc((int)strlen(input));
	for(int i=0; i<(int)strlen(input); i++)
		inputString[i]=input[i];
    int i=0;
    while(1)
    {
        parsed[i] = strsep(&inputString, " \n");
        if(parsed[i] == NULL) break;
        if(strlen(parsed[i]) == 0)
            i--;
        i++;
    }
    parsed[i-1] = rtrim (parsed[i-1], NULL);
}

int compare(char** parsed)
{
	int signal = 0;
	char* parsed1[2];
	char* parsed2[2];

	parsePoint(parsed[1], parsed1);
	parsePoint(parsed[2], parsed2);

	int i=0; 
	if((int)strlen(parsed1[0]) > (int)strlen(parsed2[0]))
		return 1;
	else if((int)strlen(parsed1[0]) < (int)strlen(parsed2[0]))
		return -1;


	while(i<(int)strlen(parsed1[0]))
	{
		if(parsed1[0][i] > parsed2[0][i])
			return 1;
		else if(parsed1[0][i] < parsed2[0][i])
			return -1;
		i++;
	}

	i=0;	
	int strlenparsed11 = 0;//strlen(parsed1[1]);
	int strlenparsed21 = 0;
	if(parsed1[1] != NULL) strlenparsed11 = (int)strlen(parsed1[1]);
	if(parsed2[1] != NULL) strlenparsed21 = (int)strlen(parsed2[1]);
	if(strlenparsed11 == 0 && strlenparsed21 == 0)
		return 1;
	if(strlenparsed11 == strlenparsed21)
	{

		while(i<(int) strlenparsed11)
		{
			if(parsed1[1][i] > parsed2[1][i])
				return 1;
			else if(parsed1[1][i] < parsed2[1][i])
				return -1;
			i++;
		}
	}
	else
	{


		int min =0;
		if(strlenparsed11> strlenparsed21)
			min = (int) strlenparsed21;

		if(strlenparsed11 < strlenparsed21)
			min = (int) strlenparsed11;
			
		i=0;
		while(i<min)
		{
			if(parsed1[1][i] > parsed2[1][i])
				return 1;
			else if(parsed1[1][i] < parsed2[1][i])
				return -1;
			i++;
		}
		if(i == (int) strlenparsed21)
			return 1;
		else if(i == (int) strlenparsed11)
			return -1;

	}

}



char* mulhelperac2(char** parsed)
{
	char* ret = malloc((int)strlen(parsed[1]) + (int)strlen(parsed[2]));
	//parsed ki floating length note krke point htao
	//parsed[1] k liye start
	int arr1[(int) strlen(parsed[1])];
	int arr2 [(int) strlen(parsed[2])];
	int float1 = 0;
	int float2=0;
	int size1=(int)strlen(parsed[1]);
	int size2=(int)strlen(parsed[2]);

		for(int i=0; i<(int) strlen(parsed[1]); i++)
			arr1[i]=0;
		for(int i=0; i<(int) strlen(parsed[2]); i++)
			arr2[i]=0;

		//for arr1
		bool ispoint1 = false;
		for(int i=0; i<(int) strlen(parsed[1]); i++)
		{
			if(parsed[1][i] != '.')
			{
				if(ispoint1)
				{
					arr1[i-1]=parsed[1][i]  - 48; 
					float1++;

				}
				else arr1[i] = parsed[1][i] - 48;
			}
			else {
				ispoint1 = true;
				size1--;
			}
		}

		//for arr2
		bool ispoint2 = false;
		for(int i=0; i<(int) strlen(parsed[2]); i++)
		{
			if(parsed[2][i] != '.')
			{
				if(ispoint2)
				{
					arr2[i-1]=parsed[2][i] - 48; 
					float2++;
				}
				else arr2[i] = parsed[2][i] - 48;
			}
			else {
				ispoint2 = true;
				size2--;
			}
		}

		//showing arr1
		// for(int i=0; i<size1; i++)
		// 	printf("%d ", arr1[i]);
		// for(int i=0; i<size2; i++)
		// 	printf("%d ", arr2[i]);
		// printf("\n");

		int size = size1 + size2;

		int final[size];

		for(int i=0; i<size; i++)
			final[i] = 0;
		for(int i=0; i<size2; i++)
		{
			int a = arr2[size2-1-i];
			// printf("a is: %d \n",a);
			int res[size1+1];
			
			for(int j=0; j<size1+1; j++)
				res[j]=0;

			int carry = 0;
			for(int j=size1-1; j>=0; j--)
			{
				int b = (arr1[j])*a + carry;
				res[j+1] = b%10;
				carry = b/10;
			}

			res[0] = carry;

			int res1[size];
			for(int j=0; j<size-i-size1-1; j++)
			{
				res1[j]=0;
			}
			for(int j=0; j<size1+1; j++)
			{
				res1[size-i-size1-1+j] = res[j];
			}
			for(int j=0; j<i; j++)
				res1[j+size-i] = 0;
			
			carry = 0;
			for(int j=size-1; j>=0; j--)
			{
				int b = final[j]+res1[j] + carry;
				final[j] = b%10;
				carry = b/10;
			}
			//result to aa gyaa
		}
		//filing of ret starts
		int man=0;
		if(ispoint1 || ispoint2)
		{
			int b = float1+float2;
			for(int i=0; i<size; i++)
			{
				if(i!=size-b)
				{
					ret[man] = (char)(final[i] + 48);
					man++;
					// printf("%d", final[i]);
				}
				else{
					ret[man] = '.';
					man++;
					int te = final[i];
					ret[man] = te + '0';
					man++;
					// printf(".%d", final[i]);
				}
			}
		}
		else
		{
			for(int i=0; i<size; i++)
					{
						ret[man] = (char)(final[i] + 48);
						man++;
						// printf("%d", final[i]);
					}
					ret[man] = '\0';
				// printf("\n");
		}

		return ret;
}

char* mulhelperac(char* a, char* c)
{
		bool isfinalplus = true;
		bool isp1plus = true;
		bool isp2plus = true;
			if( (int) a[0] == 45)
			{
					a = ltrim (a, "-");
					isp1plus = false;
			}
			if ((int) c[0] == 45) 
			{
				c = ltrim (c, "-");
				isp2plus = false;
			}
			if((isp1plus && isp2plus) || (!isp1plus && !isp2plus) )
				{
					char** parsed=malloc(2);
					parsed[0] = "MUL";
					parsed[1] = a;
					parsed[2] = c;
					char* retu = mulhelperac2(parsed);
					return retu;
				}
			else if((isp1plus && !isp2plus) || (!isp1plus && isp2plus))
			{
				char* ret = malloc((int)strlen(a)+(int)strlen(c));
				int man=0;
				ret[man] = '-';
				man++;
				// printf("-");
				char** parsed=malloc(2);
					parsed[0] = "MUL";
					parsed[1] = a;
					parsed[2] = c;
				char* d2 = mulhelperac2(parsed);
				for(int i=0; i<(int)strlen(d2); i++)
				{
					ret[man] = d2[i];
					man++;
				}
				ret[man] = '\0';
				return ret;
			}
}

char* subhelperac2(char** parsed)
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

			  while(finalarray1[i] == 0 && i< a-1)
			  {
			  	i++;
			  	// printf("removing 1st \n");
			  	continue;
			  }
			  char* ret = malloc(a + a2 - i +2);
			  int man=0;
			  for(i=i; i<a; i++)
			  	{
			  		ret[man] = finalarray1[i] + '0';
			  		man++;
			  	}
			  if(isfloat)
			  {
			  	ret[man] = '.';
			  		man++;
			  	for(i=0; i<a2; i++)
			  	{
			  		ret[man] = finalarray2[i] + '0';
			  		man++;
			  	}
			  }
			  ret[man] = '\0';
			  return ret;
}

char* addhelperac2(char** parsed)
{

		bool isfloat = false;
		bool iscarry = false;
		bool isparsed11fill = false;
		bool isparsed10fill = false;
		bool isparsed21fill = false;
		bool isparsed20fill = false;
		//again copy
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
	      parsed10 = malloc(a);
	      for(int i=0; i<a-(int)strlen(parsed1[0]); i++)
			parsed10[i]='0';

	      for(int j=0; j<(int)strlen(parsed1[0]); j++)
	      	parsed10[a-(int)strlen(parsed1[0])+j] = parsed1[0][j];
	      // printf("\nYha\n");
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
		
		// printf("going to add:\n%s\n%s\n",parsed10,parsed20 );
		  for(int i=a-1; i>=0; i--)
		  {
		    int b = (int)parsed10[i]+(int)parsed20[i] + carry - 48 -48;
		    // if(i==a-2) printf("lol(int)parsed10[i] is : %c\n", parsed10[i]);
		    carry = b/10;
		    finalarray1[i+1] = b%10;
		  }
		    finalarray1[0] = carry;
		 char* ret = malloc(a+1 + a2+10);
		 int man=0;
		//printing result

		if(finalarray1[0] != 0 && a!= 0)
			{
				ret[man]=finalarray1[0]+'0';
				man++;
				// printf("lol%d",finalarray1[0]);
			}

		for(int i=1; i<a+1; i++)
			{
				ret[man]=finalarray1[i]+'0';
				man++;
				 // printf("lool%d",finalarray1[i]);
			}
		if(isfloat)
		{
			// printf(".");
			ret[man]='.';
				man++;
			for(int i=0; i<a2; i++)
				{
					ret[man]=finalarray2[i]+'0';
					man++;
					// printf("loool%d", finalarray2[i]);
				}
		}
		ret[man]='\0';
		// printf("here ret is : %s\n", ret);
		return ret;












		/*


		//parsed
		char* parsed1[2];
		char* parsed2[2];
		parsePoint(parsed[1], parsed1);
		parsePoint(parsed[2], parsed2);

		// 		printf("parsed2[0] : %s\n", parsed2[0]);
		// printf("parsed2[1] : %s\n", parsed2[1]);
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
		    carry = b/10;
		    finalarray1[i+1] = b%10;
		  }
		    finalarray1[0] = carry;
		//printing result
		    char* ret = malloc(a+1 + a2+1 );
		    int man=0;
		if(finalarray1[0] != 0)
			{
				ret[man]= finalarray1[man] + '0';
				man++;
				// printf("%d",finalarray1[0]);
			}
		for(int i=1; i<a+1; i++)
			{
				// printf("yooo");
				ret[man]= finalarray1[i]+'0';
				man++;
				// printf("%d",finalarray1[i]);
			}
		if(isfloat)
		{
			ret[man]= '.';
				man++;
			// printf(".");
			for(int i=0; i<a2; i++)
				{
					ret[man] = finalarray2[i] + '0';
					man++;
					// printf("%d", finalarray2[i]);
				}
		}
		// printf("addhelperac2 : %s\n", ret);
		ret[man] = '\0';
		
		return ret;	*/	
}


char* subhelperac(char* a, char* b)//b is actually c
{
		bool isfinalplus = true;
		bool isp1plus = true;
		bool isp2plus = true;
			
			if( (int) a[0] == 45)
			{
					a = ltrim (a, "-");
					isp1plus = false;
			}
			if ((int) b[0] == 45) 
			{
				b = ltrim (b, "-");
				isp2plus = false;
			}

			char* parsed[3];
				parsed[0] = "SUB";
				parsed[1] = a;
				parsed[2] = b;
				// printf("a is : %s\n",a);
				// printf("b is : %s\n",b);
				char* ret = malloc(maximum((int)strlen(a),(int)strlen(b)) + 1);

				int man=0;
			if(!isp1plus && !isp2plus && compare(parsed) == 1 ) {
				isfinalplus = false;

				// printf("-");
				ret[man]= '-';
				man++;
				char* t = subhelperac2(parsed);
				
				for(int i=0; i<strlen(t); i++)
				{
					ret[man]= t[i];
					man++;
				}
			}
			else if(!isp1plus && !isp2plus && compare(parsed) == -1)
			{
				isfinalplus = true;
				// char** parsedcopy[3];
				// parsedcopy[0] = "SUB";
				char* parsedcopy[3];
				// char t1[3] = "SUB";
				parsedcopy[0] = "SUB";
				parsedcopy[1] = b;
				parsedcopy[2] = a;

				// subhelperac2(parsedcopy);
				// man++;
				char* t = subhelperac2(parsedcopy);
				for(int i=0; i<(int)strlen(t); i++)
				{
					ret[man]= t[i];
					man++;
				}
			}
			else if(isp1plus && isp2plus && compare(parsed) == 1)
			{
				isfinalplus = true;
				// subhelperac2(parsed);	
				char* t = malloc(maximum((int)strlen(parsed[1]), (int)strlen(parsed[2]) ) + 1);
				t = subhelperac2(parsed);
				// printf("yoo %s\n", parsed[1]);
				for(int i=0; i<(int)strlen(t); i++)
				{
					ret[man]= t[i];
					man++;
				}
			}
			else if(isp1plus && isp2plus && compare(parsed) == -1)
			{
				isfinalplus = false;
				// char** parsedcopy[3];
				// parsedcopy[0] = "SUB";
				char* parsedcopy[3];
				// char t1[3] = "SUB";
				parsedcopy[0] = "SUB";
				parsedcopy[1] = b;
				parsedcopy[2] = a;

				// subhelperac2(parsedcopy);
				// printf("-");
				ret[man]='-';
				man++;
				char* t = subhelperac2(parsedcopy);
				for(int i=0; i<(int)strlen(t); i++)
				{
					ret[man]= t[i];
					man++;
				}
			}
			
			else if(isp1plus && !isp2plus)
			{
				isfinalplus = true;
				
				char* t = addhelperac2(parsed);
				// printf("t is : parsed[1]%s\nparsed[2]%s\n",parsed[1], parsed[2]);
				for(int i=0; i<(int)strlen(t); i++)
				{
					ret[man]= t[i];
					man++;
				}
			}
			else if(!isp1plus && isp2plus)
			{
				isfinalplus = false;
				// char** parsedcopy[3];
				// parsedcopy[0] = "SUB";
				// parsedcopy[1] = b;
				// parsedcopy[2] = a;
				// printf("-");
				ret[man]= '-';
				man++;
				char* t = addhelperac2(parsed);

				for(int i=0; i<(int)strlen(t); i++)
				{
					ret[man]= t[i];
					man++;
				}
			}
			// printf("ret %s\n", ret);
			ret[man] = '\0';
			// printf("ret %s\n", ret);
			return ret;
}

void subhelperacvoid(char*a, char* b, char* c)
{
	bool isfinalplus = true;
		bool isp1plus = true;
		bool isp2plus = true;
			
			if( (int) a[0] == 45)
			{
					a = ltrim (a, "-");
					isp1plus = false;
			}
			if ((int) b[0] == 45) 
			{
				b = ltrim (b, "-");
				isp2plus = false;
			}

			char* parsed[3];
				parsed[0] = "SUB";
				parsed[1] = a;
				parsed[2] = b;
				// c = malloc(maximum((int)strlen(a),(int)strlen(b)) + 1);

				int man=0;
			if(!isp1plus && !isp2plus && compare(parsed) == 1 ) {
				isfinalplus = false;

				// printf("-");
				c[man]= '-';
				man++;

				char* t = subhelperac2(parsed);
				
				for(int i=0; i<strlen(t); i++)
				{
					c[man]= t[i];
					man++;
				}
			}
			else if(!isp1plus && !isp2plus && compare(parsed) == -1)
			{

				isfinalplus = true;
				// char** parsedcopy[3];
				// parsedcopy[0] = "SUB";
				char* parsedcopy[3];
				// char t1[3] = "SUB";
				parsedcopy[0] = "SUB";
				parsedcopy[1] = b;
				parsedcopy[2] = a;

				// subhelperac2(parsedcopy);
				// man++;
				char* t = subhelperac2(parsedcopy);
				for(int i=0; i<(int)strlen(t); i++)
				{
					c[man]= t[i];
					man++;
				}
			}
			else if(isp1plus && isp2plus && compare(parsed) == 1)
			{

				isfinalplus = true;
				// subhelperac2(parsed);	
				char* t = malloc(maximum((int)strlen(parsed[1]), (int)strlen(parsed[2]) ) + 1);
				t = subhelperac2(parsed);
				// printf("yoo %s\n", parsed[1]);
				for(int i=0; i<(int)strlen(t); i++)
				{
					c[man]= t[i];
					man++;
				}
			}
			else if(isp1plus && isp2plus && compare(parsed) == -1)
			{

				isfinalplus = false;
				// char** parsedcopy[3];
				// parsedcopy[0] = "SUB";
				char* parsedcopy[3];
				// char t1[3] = "SUB";
				parsedcopy[0] = "SUB";
				parsedcopy[1] = b;
				parsedcopy[2] = a;

				// subhelperac2(parsedcopy);
				// printf("-");
				c[man]='-';
				man++;
				char* t = subhelperac2(parsedcopy);
				for(int i=0; i<(int)strlen(t); i++)
				{
					c[man]= t[i];
					man++;
				}
			}
			
			else if(isp1plus && !isp2plus)
			{

				isfinalplus = true;
				
				char* t = addhelperac2(parsed);
				for(int i=0; i<(int)strlen(t); i++)
				{
					c[man]= t[i];
					man++;
				}
			}
			else if(!isp1plus && isp2plus)
			{

				isfinalplus = false;
				// char** parsedcopy[3];
				// parsedcopy[0] = "SUB";
				// parsedcopy[1] = b;
				// parsedcopy[2] = a;
				// printf("-");
				c[man]= '-';
				man++;
				char* t = addhelperac2(parsed);
				for(int i=0; i<(int)strlen(t); i++)
				{
					c[man]= t[i];
					man++;
				}
			}
			// printf("ret %s\n", c);
			c[man] = '\0';
			// printf("ret %s\n", c);
			// return ret;
}

char* addhelperac(char* a, char* b)
{
		bool isfinalplus = true;
		bool isp1plus = true;
		bool isp2plus = true;
			
			if( (int) a[0] == 45)
			{
					a = ltrim (a, "-");
					isp1plus = false;
			}
			if ((int) b[0] == 45) 
			{
				b = ltrim (b, "-");
				isp2plus = false;
			}

			char* parsed[3];
				parsed[0] = "ADD";
				parsed[1] = a;
				parsed[2] = b;
				char* ret = malloc(maximum((int)strlen(a),(int)strlen(b)) + 1);

				int man=0;
			if(!isp1plus && !isp2plus) {
				isfinalplus = false;

				// printf("-");
				ret[man]= '-';
				man++;
				char* t = addhelperac2(parsed);
				
				for(int i=0; i<strlen(t); i++)
				{
					ret[man]= t[i];
					man++;
				}
			}
			// else if(!isp1plus && !isp2plus && compare(parsed) == -1)
			// {
			// 	isfinalplus = true;
			// 	// char** parsedcopy[3];
			// 	// parsedcopy[0] = "SUB";
			// 	char* parsedcopy[3];
			// 	// char t1[3] = "SUB";
			// 	parsedcopy[0] = "SUB";
			// 	parsedcopy[1] = b;
			// 	parsedcopy[2] = a;

			// 	// subhelperac2(parsedcopy);
			// 	// man++;
			// 	char* t = subhelperac2(parsedcopy);
			// 	for(int i=0; i<(int)strlen(t); i++)
			// 	{
			// 		ret[man]= t[i];
			// 		man++;
			// 	}
			// }
			else if(isp1plus && isp2plus)
			{
				isfinalplus = true;
				// subhelperac2(parsed);	
				char* t = malloc(maximum((int)strlen(parsed[1]), (int)strlen(parsed[2]) ) + 1);
				t = addhelperac2(parsed);
				// printf("yoo %s\n", parsed[1]);
				for(int i=0; i<(int)strlen(t); i++)
				{
					ret[man]= t[i];
					man++;
				}
			}
			// else if(isp1plus && isp2plus && compare(parsed) == -1)
			// {
			// 	isfinalplus = false;
			// 	// char** parsedcopy[3];
			// 	// parsedcopy[0] = "SUB";
			// 	char* parsedcopy[3];
			// 	// char t1[3] = "SUB";
			// 	parsedcopy[0] = "SUB";
			// 	parsedcopy[1] = b;
			// 	parsedcopy[2] = a;

			// 	// subhelperac2(parsedcopy);
			// 	printf("-");
			// 	ret[man]='-';
			// 	man++;
			// 	char* t = subhelperac2(parsedcopy);
			// 	for(int i=0; i<(int)strlen(t); i++)
			// 	{
			// 		ret[man]= t[i];
			// 		man++;
			// 	}
			// }
			
			else if(isp1plus && !isp2plus && compare(parsed) == 1)
			{
				isfinalplus = true;
				
				char* t = subhelperac2(parsed);
				for(int i=0; i<(int)strlen(t); i++)
				{
					ret[man]= t[i];
					man++;
				}
			}
			else if(isp1plus && !isp2plus && compare(parsed) == -1)
			{
				isfinalplus = false;
				// printf("-");
				ret[man]='-';
				man++;
				char* parsedcopy[3];
				char t1[3] = "SUB";
				parsedcopy[0] = "SUB";
				parsedcopy[1] = b;
				parsedcopy[2] = a;
				char* t = subhelperac2(parsedcopy);
				for(int i=0; i<(int)strlen(t); i++)
				{
					ret[man]= t[i];
					man++;
				}
			}
			else if(!isp1plus && isp2plus && compare(parsed) == 1)
			{
				isfinalplus = false;
				// char** parsedcopy[3];
				// parsedcopy[0] = "SUB";
				// parsedcopy[1] = b;
				// parsedcopy[2] = a;
				// printf("-");
				ret[man]= '-';
				man++;
				char* t = subhelperac2(parsed);
				for(int i=0; i<(int)strlen(t); i++)
				{
					ret[man]= t[i];
					man++;
				}
			}
			else if(!isp1plus && isp2plus && compare(parsed) == -1)
			{
				isfinalplus = true;
				char* parsedcopy[3];
				char t1[3] = "SUB";
				parsedcopy[0] = "SUB";
				parsedcopy[1] = b;
				parsedcopy[2] = a;
				char* t = subhelperac2(parsedcopy);
				for(int i=0; i<(int)strlen(t); i++)
				{
					ret[man]= t[i];
					man++;
				}
			}
			// printf("ret123 %s\n", ret);
			ret[man] = '\0';
			// printf("ret123 %s\n", ret);
			return ret;
}



int* subhelper2(int dividend[], int divsize, int arr1[], int arr1size)
{
	
	int manoj=0;
	// while(dividend[manoj] == 0 && manoj < divsize-1)
	// {
	// 	manoj++;
	// }
	int dividend1[divsize];
	// printf("divsize is : %d\n", divsize);
	for(int k=0; k<divsize; k++)
		{
			dividend1[k] = dividend[k];
			// printf("mmma%d\n", dividend[k]);
		}
	// printf("\n");
	char a[divsize - manoj+12];
	for(int i=0; i<divsize - manoj+12; i++)
		a[i] = '0';
	// for(int d=0; d<divsize-manoj; d++)
	// 	a[d] = '0';
	int i=manoj;
	for(i=manoj; i<divsize; i++)
		{
			if(dividend[i] != -1)
				a[i-manoj] = (char) (dividend[i] + 48);
			else {
					break;
				}
		}
		a[i-manoj] = '\0';
	// for(int k=0; k<divsize; k++)
	// 	printf("a%d\n", dividend1[k]);
	// printf("\n");
	
	// printf("shuriti %s\n", a);
	manoj=0;
	while(arr1[manoj] == 0 && manoj < arr1size-1)
	{
		manoj++;
	}

	char b[arr1size-manoj];
	for(int i=manoj; i<arr1size; i++)
		b[i-manoj] = arr1[i] + '0';
	b[arr1size-manoj] = '\0';

	// printf("a is : %s\n", a);
	// printf("b is : %s\n", b);
	 
	 char t [(int)strlen(a) + (int)strlen(b)+100];

	subhelperacvoid(a,b, t);
	// printf("andar%s\n", t);
	int* ret = malloc((int)strlen(t));
	for(int i=0; i<(int)strlen(t); i++)
		ret[i] = (int)t[i]-48;

	ret[(int)strlen(t)] = -1;
	 // free(t);
	 // t = NULL;
	// printf("printign ret\n");
	// for(int i=0; i<(int)strlen(t); i++)
	// 	printf("%d ",ret[i]);
	// printf("\n");
	return ret;
	// return 0;
}


char* longDivision(char* number, long long int divisor) 
{ 
    // As result can be very large store it in string 
    char* ans = malloc((int)strlen(number)); 
    int man=0;
    
    // Find prefix of number that is larger 
    // than divisor. 
    int idx = 0; 
    long long int temp = number[idx] - '0'; 
    while (temp < divisor) 
       {
       	idx++;
       	temp = temp * 10 + (number[idx] - '0'); 
       }
      
    // Repeatedly divide divisor with temp. After  
    // every division, update temp to include one  
    // more digit. 
    while ((int)strlen(number) > idx) 
    { 
        // Store result in answer i.e. temp / divisor 
        ans[man] = ((temp / divisor) + '0');
        // ans = ans+ ((temp / divisor) + '0'); 
        man++;
          idx++;
        // Take next digit of number 
        temp = (temp % divisor) * 10 + number[idx] - '0'; 
    } 
      // printf("ans is : %s\n",ans); 
    // If divisor is greater than number 
    if ((int)strlen(ans) == 0) 
        return "0"; 
      
    // else return ans

    return ans; 
}



char* quotdividehelper(char** parsed)
{
			bool isfinalplus=true;
			bool isp1plus = true;
			bool isp2plus = true;
			// bool isfinalplus=true;
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
			char* retur = malloc(strlen(parsed[1]) + strlen(parsed[2]));
			int man=0;
			if(!isfinalplus) {
				retur[man]='-';
				man++;
					// printf("-");
				}
			

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
				// printf("0.");
				retur[man]='0';
				man++;
				retur[man]='.';
				man++;
				for(int i=0; i<kitna; i++)
				{
						retur[man] = '0';
						man++;
						// printf("0");
				}
				// printf("%s", ret);
				for(int i=0; i<strlen(ret); i++)
				{
					retur[man]=ret[i];
					man++;
				}
			}
			else
			{
			bool tempbool=false;
			int count=0;
			for(int i=0; i<strlen(ret); i++)
			{
				if(i==strlen(ret)-finalfloat)
				{
					count=0;
					tempbool = true;
					retur[man]='.';
					man++;
					// printf(".");
				}
				count++;
				if(tempbool && count == 21) break;
				retur[man]=ret[i];
				man++;
				
				// man++;
				// printf("%c", ret[i]);
			}
			}
			int manj=man-1;
				while(true)
				{
					if(retur[manj] == '0')
					{
						manj--;
					}
					else if(retur[manj] == '.')
					{
						manj--;
						break;
					}
					else break;
				}
				retur[manj+1] = '\0';
			// printf("\n");
			return retur;
}


char* quotprod(char** parsed)
{
			char* parsed1copy[2];
			parseComma(parsed[1], parsed1copy);
			char* parsed2copy[2];
			parseComma(parsed[2], parsed2copy);
			// printf("parsed1copy[0] is : %s\n", parsed2copy[0]);
			// printf("parsed1copy[1] is : %s\n", parsed2copy[1]);
			char* parsed1[2];
			// parsed1[0] = malloc((int)strlen(parsed1copy[0]) -1);
			
			
			// printf("\n filling parsed1copy[0] to parsed1[0]\n");
			int nikita = (int)strlen(parsed1copy[0]) - 1;
			char* tempparsed10= malloc(nikita+1);
			// printf("nikita is : %d\n", nikita);
			for(int i=0; i<nikita ; i++)
				{
					// printf("%c", parsed1copy[0][i+1]);
					tempparsed10[i] = parsed1copy[0][i+1];
					// break;
				}
				tempparsed10[nikita] = '\0';
			char* tempparsed11 = malloc((int)strlen(parsed1copy[1]));
			parsed1[1] = tempparsed11;
			parsed1[0] = tempparsed10;
			// parsed1[0] = rtrim(tempparsed10, NULL);
			// printf("parsed1[0] is : %s\n", parsed1[0]);
			// printf("you should be here %d %d %d\n", (int)strlen(parsed1copy[0]) - 1, (int) strlen(tempparsed10), nikita);
			
			int y=0;
			for(y=0; y<(int)strlen(parsed1copy[1]) - 1; y++)
				{
					// printf("transferring a%ca\n", parsed1copy[1][i]);
					if((int)parsed1copy[1][y] == 41)
						{
							break;
						}
					parsed1[1][y]=parsed1copy[1][y];
				}
			parsed1[1][y] = '\0';

			// for(int i=0; i<(int)strlen(parsed1copy[1]) - 1; i++)
			// 	parsed1[1][i]=parsed1copy[1][i];
			// parsed1[1][(int)strlen(parsed1copy[1]) - 1] = '\0';
			


			char* parsed2[2];
			parsed2[0] = malloc((int)strlen(parsed2copy[0]));
			for(int i=0; i<(int)strlen(parsed2copy[0]) - 1; i++)
				parsed2[0][i]=parsed2copy[0][i+1];

			parsed2[0][(int)strlen(parsed2copy[0]) - 1] = '\0';
			// printf("parsed2[0] is : %s\n", parsed2[0]);
			parsed2[1] = malloc((int)strlen(parsed2copy[1]) -1);
			for(int i=0; i<(int)strlen(parsed2copy[1]) - 1; i++)
				parsed2[1][i]=parsed2copy[1][i];

			parsed2[1][(int)strlen(parsed2copy[1]) - 1] = '\0';


			// printf("parsed1[0] is : %s\n", parsed1[0]);//a
			// printf("parsed1[1] is : %s\n", parsed1[1]);//b
			// printf("parsed2[0] is : %s\n", parsed2[0]);//c
			// printf("parsed2[1] is : %s\n", parsed2[1]);//d




			//real part start
			//finding ac
			// printf("parsed1[0] : %s\n", parsed1[0]);
			// printf("parsed2[0] : %s\n", parsed2[0]);
			char* ac1 = mulhelperac(parsed1[0], parsed2[0]); //a*c
			// char* ac = malloc((int)strlen(ac1));
			
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
			// printf("ac is : %s\n", ac);
			char* bd1 = mulhelperac(parsed1[1], parsed2[1]);
			// printf("ac is : %s\n", ac);
			
			count=0;
			while(bd1[0]=='0' && bd1[1] != '.')
			{
				for(int i=0; i<(int)strlen(bd1)-1; i++)
				{
					bd1[i] = bd1[i+1];
				}
				count++;
				// bd[i] = '\0';
			}

			
			char* bd = malloc((int)strlen(bd1) - count+1);
			for(int i=0; i<(int)strlen(bd1) - count; i++)
			{
				// printf("transferring %c\n",bd1[i]);
				bd[i] = bd1[i];
			}

			bd[(int)strlen(bd1) - count] = '\0';
			// printf("\nbd is %s\n",bd);
			char* ret1 = malloc(maximum((int)strlen(ac), (int)strlen(bd))+2); 
				ret1 = addhelperac(ac, bd); //final ka real
				// printf("ret1 is : %s\n", ret1);
			//real part end

				//imag part start
				//finding ac
			
			char* ad1 = mulhelperac(parsed1[0], parsed2[1]); //a*d
			// char* ac = malloc((int)strlen(ac1));
			
			count=0;
			while((ad1[0]=='0') && (ad1[1] != '.'))
			{
				for(int i=0; i<(int)strlen(ad1)-1; i++)
				{
					ad1[i] = ad1[i+1];
				}
				count++;
				// ac[i] = '\0';
			}
			char* ad = malloc((int)strlen(ad1) - count);

			for(int i=0; i<(int)strlen(ad1) - count; i++)
			{
				ad[i]=ad1[i];
			}

			char* bc1 = mulhelperac(parsed1[1], parsed2[0]);
			// printf("ad is : %s\n", ad);
			
			count=0;
			while(bc1[0]=='0' && bc1[1] != '.')
			{
				for(int i=0; i<(int)strlen(bc1)-1; i++)
				{
					bc1[i] = bc1[i+1];
				}
				count++;
				// bd[i] = '\0';
			}

			char* bc = malloc((int)strlen(bc1) - count);
			for(int i=0; i<(int)strlen(bc1) - count; i++)
			{
				bc[i]=bc1[i];
			}
			// printf("\nbc is %s\n", bc);
			// printf("\nad is %s\n", ad);
			char* ret2 = malloc(maximum((int)strlen(ad), (int)strlen(bc))); 
				ret2 = subhelperac(bc,ad); //final ka imag
				// printf("ret2 is : %s\n", ret2);
				// printf("ret2 is : %s\n", ret2);
				//imag part end
				char* d1 = mulhelperac(parsed2[0], parsed2[0]);
				char* d2 = mulhelperac(parsed2[1], parsed2[1]);
				// printf("d1 is : %s\n", d1);
				// printf("d2 is %s\n", d2);
				char* d = addhelperac(d1, d2);
				// printf("d is %s\n", d);
				char* temp[3];
				temp[0] = "DIV";
				temp[1] = ret1;
				temp[2] = d;
				char* real = quotdividehelper(temp);
				char* temp2[3];
				temp2[0]="DIV";
				temp2[1] = ret2;
				temp2[2] = d;
				char* imag = quotdividehelper(temp2);

				// int divisor = atoi(d);
				// char* real = longDivision(ret1
				// 	, divisor);
				// char* imag = longDivision(ret2, divisor);



				// printf("(%s,%s)\n", real, imag);
				char* ret = malloc(strlen(real)+strlen(imag)+4);
				int man=0;
				ret[man]='(';
				man++;
				for(int i=0; i<strlen(real); i++)
				{
					ret[man] = real[i];
					man++;
				}
				ret[man]=',';
				man++;
				for(int i=0; i<strlen(imag); i++)
				{
					ret[man] = imag[i];
					man++;
				}
				ret[man] = ')';
				man++;
				ret[man] = '\0';
				return ret;
				
}

