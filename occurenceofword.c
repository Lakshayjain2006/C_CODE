#include <stdio.h>
#include <stdlib.h>
int main()
{
 FILE *fp;
 char filename[100];
 int ch, i;
 int count[256] = {0};
 printf("Enter file name: ");
 scanf("%s", filename);
  fp = fopen(filename, "r");
 if (fp == NULL)
 {
 printf("Unable to open file.\n");
 return 1;
 }
 while ((ch = fgetc(fp)) != EOF)
 {
 count[ch]++;
 }
 fclose(fp);
 printf("\nCharacter Occurrences:\n");
 for (i = 0; i < 256; i++)
 {
 if (count[i] != 0)
 {
 if (i == '\n')
 printf("\\n : %d\n", count[i]);
 else if (i == '\t')
 printf("\\t : %d\n", count[i]);
 else if (i == ' ')
 printf("' ' (Space) : %d\n", count[i]);
 else
 printf("%c : %d\n", i, count[i]);
 }
 }
 return 0;
}