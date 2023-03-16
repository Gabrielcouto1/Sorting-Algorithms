$(CC) := gcc
C_FILES := $(wildcard *.c)
O_FILES := $(wildcard *.o)

main: 
	$(CC) -c $(C_FILES)
	$(CC) $(O_FILES) -o main
	rm *.o 
	
exe:
	i686-w64-mingw32-gcc -o ordenacao.exe $(C_FILES) 
	
clean:
	rm main
	rm ordenacao.exe