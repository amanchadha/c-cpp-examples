#include <stdio.h>
#include <stdlib.h>
#define path "test3.bin"

/*
struct bit_field
{
    unsigned x1: 12; // 10 bits
    unsigned x2: 12; // 10 bits
    unsigned x3: 12; // 10 bits
    unsigned x4: 12; // 10 bits
    unsigned x5: 12; // 10 bits
    unsigned x6: 12; // 10 bits
};*/

int main(void)
{
  FILE *f=NULL;
  int a[]={4,7,12,34},i,n=4,k;
  char c;
  uint32_t data;
  //bit_field b;
  
  /* testing by writing data in a[] to the file
  f=fopen(path,"wb");
  if(f==NULL)
  {
    perror("Error");
    exit(1);
  }
  for(i=0;i<n;i++)  // or I could use fwrite(a,sizeof(int),n,f);
    fwrite(&a[i],sizeof(int),1,f);
  fclose(f);
  */
  
  f=fopen(path,"rb");
  if(f==NULL)
  {
    perror("Error");
    exit(1);
  }
  i=0;

  printf("Hi: %d", sizeof(c));
  while(0 != fread(&data,sizeof(c)*3,1,f))
  {
    printf("a[%d] = %x\n",++i,data);
  }

  printf("\n");
  fclose(f);
  return 0;
}
