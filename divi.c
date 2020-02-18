#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdbool.h> 

#include "arbprecision.h"
#define _GNU_SOURCE


void divi(char** parsed)
{
	int arr1[(int) strlen(parsed[1]) + 25];
	int arr2 [(int) strlen(parsed[2])];
	int float1 = 0;
	int float2=0;
	int size1=(int)strlen(parsed[1]) + 25;
	int size2=(int)strlen(parsed[2]);
	for(int i=0; i<size1; i++)
			arr1[i]=0;
	for(int i=0; i<size2; i++)
			arr2[i]=0;

		//forarr1
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

		//forarr2
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

		int size = 100;
		int quot[size];

		for(int i=0; i<size; i++)
			quot[i] = 0;
		int utarnekiindex = 0;
		int dividend[size2+1];
		for(int i=0; i<size2+1; i++)
			dividend[i]=0;

		//dividend ko 1st time values de di start
		bool temp = false;
		int m=0;
		while(m<size2)
		{
			if(arr1[m] < arr2[m])
			{
				temp = true;
				break;
			}
			else if(arr1[m] > arr2[m])
			{
				temp = false;
				break;
			}
			m++;
		}
		if(!temp)
		{
			dividend[0] = 0;
			for(int i=0; i<size2; i++)
			{
				dividend[i+1] = arr1[i];
			}
			utarnekiindex = size2;
		}
		else
		{
			printf("Else me aaya\n");
			for(int i=0; i<size2+1; i++)
				dividend[i] = arr1[i];
			utarnekiindex = size2+1;
		}
		//dividend ko 1st time values de di end
		int quotint = 0;
		// printf("\n printing initial dividend : ");
		// for(int i=0; i<size2+1; i++)
		// 	printf("%d", dividend[i]);
		// printf("\n");

		while(utarnekiindex < size1)
		{
			printf("\n\nnewline\n");
			printf("\n printing initial dividend : ");
			for(int i=0; i<size2+1; i++)
				printf("%d", dividend[i]);
			printf("\n");
			
			if(ismore(dividend, arr2, size2+1, size2) == 1)
			{
				printf("MKCHAUDHARY\n");
				printf("\nwow\n");
				int* a1 = malloc(size2+1);
				a1 = subhelper2(dividend, size2+1,arr2, size2);
				
				// a[size2+1] = '\0';
				// int i=0;
				// printf("manoj\n");
				int akisize=0;
				while(a1[akisize] != -1)
					{
						akisize++;
					}
					int a[akisize];
					for(int i=0; i<akisize; i++)
						a[i] = a1[i];

				// exit(1);
				printf("\nprinting a : \n");
					for(int k=0; k<akisize; k++)
						printf("%d ", a[k]);
					printf("\n");
				quot[quotint]++;
				// int count=0;
				int* b = malloc(1000);
				while(ismore(a, arr2, akisize, size2) == 1)
				{

					printf("while(ismore) me aaya\n");
					
					// a = realloc(a, akisize*sizeof(int));
					printf("\nprinting a : \n");
					for(int k=0; k<akisize; k++)
						printf("%d ", a[k]);
					printf("\n");

					// b = malloc(b, 100);

					b = subhelper2(a, akisize, arr2, size2);
					// free(a);
					// free(b);
					akisize=0;
					// int i=0;
					while(b[akisize] != -1)
						{
							akisize++;
							// printf("manoj%d\n",a[i]);
							// i++;
						}
						a[akisize] = -1;
						for(int i=0; i<akisize; i++)
						a[i] = b[i];
					// free(b);
					// subhelper2(a, size2+1, arr2, size2);
					// exit(1);
					printf("\nprinting a while : ");
					for(int k=0; k<akisize; k++)
						printf("%d", a[k]);
					printf("\n");
					quot[quotint]++;
					// count++;
					// free(b);
					// if(count==10) {printf("count iss 10 \n");break;}
				}

				int j=0;
				for(j=0; j<size2+1-akisize; j++)
					dividend[j]=0;

				for(int i=j; i<size2+1; i++)
					dividend[i] = a[i-j];
				 
				 // free(a1);
				 printf("yupp2\n");
			}
			shift_left(dividend, size2+1);

			dividend[size2] = arr1[utarnekiindex];
			utarnekiindex++;
			printf("utarnekiindex : %d\n", utarnekiindex);
			for(int i=0; i<size2+1; i++)
				printf("dividend%d\n", dividend[i]);
			quotint++;
		}
		for(int i=0; i<100; i++)
			printf("%d", quot[i]);
		printf("\n");

}
