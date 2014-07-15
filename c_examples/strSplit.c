/* strtok example */
#include <stdio.h>
#include <string.h>

int main ()
{
  unsigned char str[] ="00:01:02:03:04:05";
  unsigned char * pch;
  unsigned char mac[6];
  int i=0;
  printf ("Splitting string \"%s\" into tokens:\n",str);
  pch = strtok (str,":");
  while (pch != NULL)
  {
    mac[i]=atoi(pch);
    pch = strtok (NULL, ":");
    i++;
  }
  for(i=0 ; i<6; i++)
      printf("%02x:",mac[i]);
  printf("\n");
  return 0;
}
