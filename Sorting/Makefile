.PHONY:
	clean
	all

merge.o: merge.cpp
	g++ -c merge.cpp -o merge.o

insertion_sort:
	g++ -DUSE_INSERTION_SORT -o insertion_sort main.cpp

bubble_sort:
	g++ -DUSE_BUBBLE_SORT -o bubble_sort main.cpp

selection_sort:
	g++ -DUSE_SELECTION_SORT -o selection_sort main.cpp

merge_sort: merge.o
	g++ -DUSE_MERGE_SORT merge.o main.cpp -o merge_sort  

clean:
	rm -rf insertion_sort
	rm -rf bubble_sort
	rm -rf selection_sort
	rm -rf merge_sort
	rm -rf merge.o