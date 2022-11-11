$(CC) := gcc
C_FILES := $(wildcard *.c)
O_FILES := $(wildcard *.o)

main: 
	$(CC) -c $(C_FILES)
	$(CC) $(O_FILES) -o main
	rm *.o 
	
clean:
	rm main