
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdbool.h> 

#include "arbprecision.h"
#define _GNU_SOURCE

void mult(char** parsed, FILE* ft)
{
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
		if(ispoint1 || ispoint2)
		{
			int b = float1+float2;
			for(int i=0; i<size; i++)
			{
				if(i!=size-b)
				{
					fprintf(ft,"%d", final[i]);
				}
				else{
					fprintf(ft,".%d", final[i]);
				}
			}
		}
		else
		{
			for(int i=0; i<size; i++)
					fprintf(ft,"%d", final[i]);
				fprintf(ft,"\n");
		}
}
