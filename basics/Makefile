default: bake

bake:
	mkdir -p build 
	cd build; cmake ..; make -j3

run:
	cd bin; ./basics

#docs:
#	doxygen

clean:
	rm -r build
	#rm -r doc
