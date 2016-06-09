all: TestBinPackingAlgorithms

TestBinPackingAlgorithms:
	g++ TestBinPackingAlgorithms.cpp -o TestBinPackingAlgorithms

clean:
	rm TestBinPackingAlgorithms
