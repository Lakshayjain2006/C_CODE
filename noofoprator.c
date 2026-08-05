#include <stdio.h>
#include <stdlib.h>
int main()
{
 FILE *fp;
 char filename[100];
 char ch;
 int count = 0;
 printf("Enter the file name: ");
  scanf("%s", filename);
 fp = fopen(filename, "r");
 if (fp == NULL)
 {
 printf("Unable to open file.\n");
 return 1;
 }
 while ((ch = fgetc(fp)) != EOF)
 {
 if (ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
 ch == '%' || ch == '=' || ch == '<' || ch == '>' ||
 ch == '&' || ch == '|' || ch == '!' || ch == '^')
 {
 count++;
 }
 }
 fclose(fp);
 printf("Total number of operators = %d\n", count);
 return 0;
}
