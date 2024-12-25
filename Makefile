clean:
        rm -f *.o bin/testDrawing

Point2D.o: Point2D.h Point2D.cpp
	g++ -c Point2D.cpp

Shape.o: Shape.h Shape.cpp
	g++ -c Shape.cpp

Circle.o: Circle.h Circle.cpp Shape.h Point2D.h
	g++ -c Circle.cpp

Rectangle.o: Rectangle.h Rectangle.cpp Shape.h Point2D.h
	g++ -c Rectangle.cpp

Square.o: Square.h Square.cpp Rectangle.h Shape.h Point2D.h
	g++ -c Square.cpp

Drawing.o: Drawing.h Drawing.cpp Shape.h ListArray.h
	g++ -c Drawing.cpp

testDrawing.o: testDrawing.cpp Drawing.h Shape.h Point2D.h
	g++ -c testDrawing.cpp

bin/testDrawing: testDrawing.o Drawing.o Square.o Rectangle.o Circle.o Shape.o Point2D.o
	mkdir -p bin
	g++ -o bin/testDrawing testDrawing.o Drawing.o Square.o Rectangle.o Circle.o Shape.o Point2D.o

