all:
	g++ -fdiagnostics-color=always -g main.cpp -o ./Plotter Stack.cpp -ISFML-2.5.1/include -LSFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system