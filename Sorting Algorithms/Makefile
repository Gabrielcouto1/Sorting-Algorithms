$(CC) := gcc
C_FILES := $(wildcard src/*.c)
O_FILES := $(wildcard *.o)

main: 
	$(CC) -c $(C_FILES)
	$(CC) $(O_FILES) -o main
	i686-w64-mingw32-gcc -o sorting_algorithms.exe $(C_FILES) 
	rm *.o 
	
clean:
	rm main
	rm sorting_algorithms.exe