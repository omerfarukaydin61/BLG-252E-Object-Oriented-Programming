#include <iostream>
using namespace std;

/* @Author
 * Student Name:  Omer Faruk Aydin
 * Student ID : 150210726
 */

class ALU
{
public:
    ALU(int cores);             // constructor
    int add(int a, int b);      // add function
    int subtract(int a, int b); // subtract function
    int multiply(int a, int b); // multiply function

private:
    int numPerCores; // number of ALU per cores
};

class CUDA
{
public:
    CUDA(int cores);     // constructor
    string render();     // render function
    string trainModel(); // trainModel function

private:
    int numCores; // number of CUDA cores
};

class CPU
{
public:
    CPU(int cores);                // constructor
    int execute(string operation); // execute function

private:
    ALU _alu; // ALU object
};

class GPU
{
public:
    GPU(int cores);                   // constructor
    string execute(string operation); // execute function

private:
    CUDA _cuda; // CUDA object
};

class Computer
{
public:
    Computer();                     // constructor
    void operator+(GPU gpu);        // operator overloading for GPU
    void operator+(CPU other);      // operator overloading for CPU
    void execute(string operation); // execute function

private:
    CPU* attachedCPU = nullptr; // CPU pointer
    GPU* attachedGPU = nullptr; // GPU pointer
};