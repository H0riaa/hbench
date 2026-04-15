clean:
	del main
all:
	g++ main.cpp -o main.exe
run:
	./main.exe
alls:
	g++ main.cpp timer.cpp -o main.exe	