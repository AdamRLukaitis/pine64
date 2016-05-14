

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fp;

unsigned int data[0x100000];


int main ( int argc, char *argv[] )
{
    unsigned int ra;
    unsigned int rb;


    if(argc<3)
    {
        printf("binto input output\n");
        return(1);
    }


    memset(data,0xFF,sizeof(data));

    fp=fopen(argv[1],"rb");
    if(fp==NULL) return(1);
    rb=fread(data,1,sizeof(data),fp);
    fclose(fp);
    rb+=3;
    rb>>=2;

    fp=fopen(argv[2],"wt");
    if(fp==NULL) return(1);


    for(ra=0;ra<rb;ra++)
    {
        fprintf(fp,"mw.l 0x%08X 0x%08X\n",0x41000000+(ra<<2),data[ra]);
    }
    fclose(fp);

    return(0);
}

