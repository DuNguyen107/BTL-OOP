#include <iostream>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <iomanip>
#pragma once
using namespace std;

template<typename T>
class Manage{
    protected:
        virtual void add(const T&) = 0;
        virtual void display() = 0;
        virtual void update(T&) = 0;
        virtual void remove(T&) = 0;
};