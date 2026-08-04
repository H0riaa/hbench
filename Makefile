all:
	g++ -Iinclude src/main.cpp src/timer.cpp -o main.exe

clean:
	del main.exe

run:
	./main.exe
