#include <stdio.h>
#include "ProductInfo.h"

int main()
{
  Product products[10];
  int i=0;
  int id;
  boolean quit=false;
  char cmd;
  
  while(!quit)
  {
    printf("command?");
    cmd=getchar();
    switch(cmd)
    {
      case 'h':
        showHelp();
        getchar();
        break;
      case 'i':
        products[i++]=getAProductInfo();
        break;
      case 'l':
        showAllProductInfo(products, i);
        getchar();
        break;
      case 's':
        printf("ID?");
        scanf(" %d", &id);
        searchProduct(products, i, id);
        getchar();
        break;
      case 'q':
        quit=true;
        break;
      case 10:
        printf("Wrong command!\n");
        break;
      default:
        printf("Wrong command!\n");
        getchar();
        break;
    }
  }
}