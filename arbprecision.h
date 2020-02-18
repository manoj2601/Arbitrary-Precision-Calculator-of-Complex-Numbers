//File mydemo.h

  #ifndef ARBPRECISION_H

  #define ARBPRECISION_H

   int maximum(int, int);

   int minimum(int, int);

   char* rtrim(char*, const char*);

   void parsePoint(char*, char**);

   void parseComma(char*, char**);

   void add(char**, FILE*);

   void sub(char**, FILE*);

   char* ltrim(char*, const char*);

   void parseSpace(char*, char**);

   int compare(char**);

   void mult(char**, FILE*);

   void divi(char**);

   int ismore(int[], int[], int, int);

   int* subhelper(int[], int, int[], int);

   int* shift_left(int [], int);

   char* mulhelperac2(char**);

   char* mulhelperac(char*, char*);

   char* subhelperac2(char** );

   char* addhelperac2(char** );

   char* subhelperac(char* , char* );

   void subhelperacvoid(char*, char*, char*);

   char* addhelperac(char* , char* );

   int* subhelper2(int[], int, int[], int);

   char* longDivision(char*, long long int);

   char* quotprod(char**);
#endif
