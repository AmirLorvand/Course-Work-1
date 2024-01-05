CXXFLAGS = -std=c++11

main: main.o Librarian.o Member.o Person.o Book.o SharedData.o Additional_Functions.o ReadCSV.o
	g++ $(CXXFLAGS) main.o Librarian.o Member.o Person.o Book.o SharedData.o Additional_Functions.o ReadCSV.o -o main

Librarian.o: Librarian.cpp
	g++ $(CXXFLAGS) -c Librarian.cpp

Member.o: Member.cpp
	g++ $(CXXFLAGS) -c Member.cpp

Person.o: Person.cpp
	g++ $(CXXFLAGS) -c Person.cpp

SharedData.o: SharedData.cpp
	g++ $(CXXFLAGS) -c SharedData.cpp

Additional_Functions.o: Additional_Functions.cpp
	g++ $(CXXFLAGS) -c Additional_Functions.cpp

ReadCSV.o: ReadCSV.cpp
	g++ $(CXXFLAGS) -c ReadCSV.cpp

clean:
	rm *.o main