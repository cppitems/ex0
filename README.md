# Exercise EX0

## Prerequisits

Make sure you have a working environment configured with access to:
- git 
- cmake >= 3.0
- compiler/linker for C++17
- recommended: clangd (clang-format, clang-tidy)

### You can use the preconfigured docker-container (Theia-IDE + clang/LLVM) provided here 
https://github.com/cppitems/docker

> What is a 'docker-container'? 

> What is the 'Theia-IDE'?

## Background

In this exercise you have to implement a class which should provide a data structure of dynamically allocated, contiguous memory, usually called a **Vector**.

This exercise is designed to mimic the workflow of software development in a professional setting. You are provided with several [unit tests](https://en.wikipedia.org/wiki/Unit_testing), which are very short programs laying out the required functionality. These tests are stored in the folder `tests` and we have set up CMake to automatically build them. Writing these tests is usually the first step in developement and they should lay out the wanted functionality of a part of software. Oftentimes the tests are written by one programmer and then satisfied by another to avoid an implicit bias by a single programmer. Therefore, we have provided them for you.

Your library and all tests are built using the following commands in the project folder:
```bash
mkdir build && cd build
cmake ..    # this sets up the build system
make        # this builds the library and all tests      
make test   # this runs all tests
```

In order to turn off certain tests, you can uncomment them in the file `tests/CMakeLists.txt`. To turn off the test called "TestA", just add a `#` at the start of the corresponding line:
```bash
...
#list(APPEND MY_TEST_SOURCES "TestA")
list(APPEND MY_TEST_SOURCES "TestB")
...
```
Now, the test "TestB" will still be compiled and run, but not "TestA".

### Coding Task

Your task is to add the implementation of a `Vector` class for a small vector library which will store elements of type `int`. Once you are done, all available test cases should compile and pass without errors.

You can find this C++ project with a CMake configuration at
https://github.com/cppitems/cppitems/tree/master/items/002/ex0

The source and header files for the vector library are initially empty and should be filled by you with the necessary C++ code.
You should **NOT** add any additional files but only modify the existing source files located at:
- `include/vector.hpp`
- `lib/vector.cpp`

There will be a test for every required aspect of the exercise. Tests are ordered with letters and should be finished in this order.
Your `Vector` class should satisfy the following:
- Test A: Constructor `Vector(size_t, int)`, member typedef `value_type` equal to `int`
- Test B: Member function `size_t size()` which returns the number of elements stored in the vector
- Test C: Member function `int *data()` which returns a pointer to the raw data
- Test D: Member function `int &at(size_t i)`, which returns the element at the index i
- Test E: Member function `int sum()` which sums alls elements and returns the results
- Test F: Correct copy constructor `Vector(const Vector &)`
- Test F: Correct copy assignment operator `Vector& operator=(const Vector&)`

*This exercise is not graded and just meant to give us an overview of how advanced each of you is. Do not worry if you do not manage to solve all the parts of the exercise, but please do try your best to pass as many tests as possible. For future exercises, we will have already covered all necessary topics in the lecture, so every one can successfully finish the exercise.*

You can build single tests by using their name as the first argument to make, and run them by executing them directly:
```bash
make TestA_Constructor                      # build test
tests/TestA_Constructor/TestA_Constructor   # execute test
```

Once you have implemented all the necessary features, make sure that all tests pass:
```bash
make buildTests
make test
```
and then push your changes to your Gitea repository.

### Pushing to Gitea

All exercises must be handed in to your repository on our Gitea server at [https://tea.iue.tuwien.ac.at](https://tea.iue.tuwien.ac.at)

#### Initial Setup (only do this once)

git is a software versioning tool and is commonly used in almost all areas of software development.
In order to tell git to watch your project, navigate to your project folder and run
```bash
git init
Initialised empty Git repository in /my/project/folder/.git/
```

In order to upload changes to Gitea to share it with collaborators (or your lecturers), we first have to tell git where to upload them:
```bash
git remote add origin git@tea.iue.tuwien.ac.at:e00000000/ex0.git
```
where `origin` is the name we want to call this remote repository, `e00000000` should be replaced with `e<yourstudentid>` and `ex0` is the name of the repository on the server.
Make sure you have created the repository before trying to upload to it.

#### Upload after working on the project

*FAQ: How often should I push my changes to Gitea?*
*Answer: **Every time you get up from your computer. Every. Single. Time.***

After having done some exhausting coding, we want to add all file changes in the current folder (`.`) to git:
```bash
git add .
```
In order to see what files have changed, you can run
```bash
git status
```
and you can check all changes within files with
```bash
git diff HEAD
```

Once you are happy with all changes you can `commit` them to save them locally using a meaningful message that describes what you have done
```bash
git commit -m "Added flux capacitor."
```

Once all changes are comitted, we can tell git to upload them using

```bash
git push
```
