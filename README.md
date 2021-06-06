# cpp_array_intersection
This program compares three different approaches to identify common characters shared between the two character vectors.

### Executing the program
1. In the project directory, run `make` to generate the file 'main' in the same directory.
2. Run `./main` to run the program.
3. The program will request two relative paths to text documents. Please note that example text documents are provided as 'example1.txt' and 'example2.txt'.
4. After supplying the two relative paths, the two text documents will be read into vectors.
5. Three different approaches as outlined in the "Intersection approaches" section will be executed to assess the common characters shared between both vectors. Execution time in seconds will be outputted.
6. A text document with the common characters will be outputted in the project directory called 'common_characters.txt'.

### Executing the unit tests
1. In the project directory, run `make test` to generate the file 'test' in the same directory.
2. Run `./test` to run units tests.
3. Each unit test will be executed one by one and will output "Success" + the unit test method name if no assertion errors are encountered.

### Intersection approaches
1. bruteForceIntersection - Linearly iterates through one vector. The vector present at a given index will then be linear searched in the second vector. Values shared between both vectors will be inserted into a hash set and will be returned upon completion of this method. This is the ineffecient approach we discussed during the interview.
2. multiThreadedIntersection - Linearly iterates through one vector. The vector present at a given index will then be searched in the second vector using 3 threads (defaulted to 3 for demonstration purposes). Specifically, the second vector will be split into search ranges and each of the 3 threads will be assigned to one of those ranges. Values shared between both vectors will be inserted into a hash set and will be returned upon completion of this method.
3. binaryIntersection - This assumes that the second vector is sorted. Initially, the first vector is iterated through. The vector present at a given index will then be binary searched. Values shared between both vectors will be inserted into a hash set and will be returned upon completion of this method.
   
### Make commands
- `make` for building executable 'main' program
- `make test` for building executable unit test program 'test'
- `make clean` cleans up all object and executable files