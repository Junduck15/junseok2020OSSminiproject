CC = gcc
CFLAGS = -W -Wall
TARGET = product
OBJECTS = main.c product.o manager.o
DTARGET = product_debug


$(TARGET) : $(OBJECTS) 
	$(CC) $(CFLAGS) -o $@ $^
$(DTARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -DDEBUG -o $@ $^

clean :
	rm *.o $(TARGET) $(DTARGET) *.txt
