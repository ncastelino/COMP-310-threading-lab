
# Threading Lab

In this lab, you are going to convert a single-threaded program into a multithreaded program to make it run faster. The program you are starting with takes a bunch of coordinates in 3-space and performs a vector rotation on them. This is basically the same thing that GPUs do when they render scenes for video games.

Each coordinate transformation is done using a matrix-vector product. We use a [special 3x3 matrix](https://en.wikipedia.org/wiki/Rotation_matrix) to rotate a vector in each cartesian demension. The program that I've written to get you started constructs these matrices (one for x, y, and z rotations) and applies them to a few million points. On my laptop, it takes about 850ish milliseconds to apply the three transformations to 24 million points.

An aside: in case you were wondering, that's really f###ing slow. 24 million points is 8 million polygons, roughly what's in a typical video game frame. For comparison, the GTX1080 can process about 11 billion polygons per second---about 100x what my CPU can do. It is also doing shading, lighting, etc. So why is the processor on my laptop so slow when that GPU is so fast? THREADING! Obviously, that's what this whole lab is about.

## How Threading Applies to this Computation

Each coordinate transform is an independent operation. We don't need to know the result of one coordinate transformation in order to do another. Since there are no dependences between transforms, they don't have to be executed sequentially, which means we can use multiple parallel computations to calculate the transforms simultaneously. The threads that we use to perform these parallel computations don't even really need to share any data.

The first thing you should do is build the project and see how it works in single-threaded mode.

Your job in this lab is to modify this program's `main.c` to create several worker threads to execute the `for()` loop in parallel. You should try to make your code parametric so it's easy to control the number of threads that your program creates. Start with 2-3 threads, and see what happens when you increase to 20. Can you make your code run faster by increasing the number of threads from 10 to 20? What about from 20 to 40?




## Structure of the Project

### Source

#### `vector.c`

Has all the matrix-vector and vector-vector multiplication functions. You shouldn't need to edit this.

#### `points.c`

Has all the points that will be processed by the program.

### Tools

#### Makefile

Builds the project. It takes a long time to compile the project from scratch because the `points.c` file is huge. If you run `make clean` every time you rebuild, it will delete `points.o` and rebuild it, which takes forever. **Don't run `make clean` on each rebuild** because it will take forever. Just run `make`, and it will only recompile the files that you've edited. Only exception is if you edit a header file, then you have to run `make clean` or delete the object files that include the header that you edited.

#### `genpoints.py`

This is a python script that generates a C file with a bunch of points in it. You can edit the script to increase/decrease the number of points that it's generating.

#### `runtrials.sh`

This is a shell script that runs your binary a bunch of times and calculates the average runtime for each trial.

