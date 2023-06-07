#include <iostream>
#include "Computer.h"
using namespace std;

/* @Author
 * Student Name:  Omer Faruk Aydin
 * Student ID : 150210726
 */

 // ALU class
 // constructor
ALU::ALU(int cores) : numPerCores{ cores }
{
    cout << "ALU is ready" << endl;
}
// add function
int ALU::add(int a, int b)
{
    return a + b;
}
// subtract function
int ALU::subtract(int a, int b)
{
    return a - b;
}
// multiply function
int ALU::multiply(int a, int b)
{
    return a * b;
}

// CUDA class
// constructor
CUDA::CUDA(int cores) : numCores{ cores }
{
    cout << "CUDA is ready" << endl;
}
// render function
string CUDA::render()
{
    return "Video is rendered";
}
// trainModel function
string CUDA::trainModel()
{
    return "AI Model is trained";
}

// CPU class
// constructor
CPU::CPU(int cores) : _alu{ cores }
{
    cout << "CPU is ready" << endl;
}
// execute function
int CPU::execute(string operation)
{
    int a, b;
    cout << "Enter two integers\n";
    cin >> a >> b;
    if (operation == "add")
    {
        return _alu.add(a, b);
    }
    else if (operation == "subtract")
    {
        return _alu.subtract(a, b);
    }
    else if (operation == "multiply")
    {
        return _alu.multiply(a, b);
    }
    return 0;
}

// GPU class
GPU::GPU(int cores) : _cuda{ cores }
{
    cout << "GPU is ready" << endl;
}
// execute function
string GPU::execute(string operation)
{
    if (operation == "render")
    {
        return _cuda.render();
    }
    else if (operation == "trainModel")
    {
        return _cuda.trainModel();
    }
    return 0;
}

// Computer class
// constructor
Computer::Computer()
{
    cout << "Computer is ready" << endl;
};
// operator overloading for GPU
void Computer::operator+(GPU gpu)
{
    if (this->attachedGPU == nullptr)
    {
        this->attachedGPU = &gpu;
        cout << "GPU is attached" << endl;
    }
    else
    {
        cout << "There is already a GPU" << endl;
    }
}
// operator overloading for CPU
void Computer::operator+(CPU other)
{
    if (this->attachedCPU == nullptr)
    {
        this->attachedCPU = &other;
        cout << "CPU is attached" << endl;
    }
    else
    {
        cout << "There is already a CPU" << endl;
    }
}
// execute function
void Computer::execute(string operation)
{
    if (operation == "add" || operation == "subtract" || operation == "multiply")
    {
        cout << attachedCPU->execute(operation) << endl;
    }
    else if (operation == "render" || operation == "trainModel")
    {
        cout << attachedGPU->execute(operation) << endl;
    }
}
