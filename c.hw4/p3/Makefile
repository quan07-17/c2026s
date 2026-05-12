all:	SouvenirShopMain.c ProductInfo.o
	cc SouvenirShopMain.c ProductInfo.o

ProductInfo.o: ProductInfo.c ProductInfo.h
	cc ProductInfo.c -c
	
clean: 
	rm -f *.c~ *.h~ *~ *.o a.out
	
	