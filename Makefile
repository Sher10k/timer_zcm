

all: build_timer
	@echo ' --- build completed'

build_timer: 
	@echo ' --- build timer'
	mkdir -p build
	g++ -std=c++11 main.cpp -lzcm -o build/timer_zcm


rebuild: clear all
	@echo ' --- rebuild project completed'

clear: 
	@echo ' --- clear build'
	rm -rf ./build/