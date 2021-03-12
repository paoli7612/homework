FILE=main

run: $(FILE).out
	./$(FILE).out

clean: $(FILE).out
	rm -rf *.out

$(FILE).out: $(FILE).cc
	g++ $(FILE).cc -o $(FILE).out