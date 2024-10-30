#include <iostream>
#include <iomanip>
#include <string>
#include "list.cpp"
#pragma once
using namespace std;

class Product
{
    protected:
        string productID;
        string name;
        int quantity;
        List<string> serial;
        double price;
    private:    
        double importPrice;
        string CPU;
        int RAM;
        string screen;
        int hardDisk;
        string GPU;
        string OS;
        string brand;
    public:
        Product();
        Product(string ID, string name, double price, double importPrice, string CPU, int RAM, string screen, int hardDisk, string GPU , string OS, string brand);
        Product(const Product& other);
        ~Product();
        Product& operator=(const Product& other);
        void show();
        friend ostream& operator<<(ostream&, const Product&);
        bool operator!=(const Product&);
        bool operator==(const Product&);
        string getName();
        string getID() const;
        double getPrice();
        double getImportPrice();
        double Profit();
        string getCPU();
        int getRAM();
        string getScreen();
        int getHardDisk();
        string getGPU();
        string getOS();
        int getQuantity();
        string getBrand();
        void setName(string);
        void setID(string);
        void setPrice(double);
        void setImportPrice(double);
        void setCPU(string);
        void setRAM(int);
        void setScreen(string);
        void setHardDisk(int);
        void setGPU(string);
        void setOS(string);
        void setQuantity(int);
        void setBrand(string&);
        void addSerial(string&);
        void removeSerial(string&);
        bool isSerial(string&);
        List<string>& getSerial();
        bool operator>(Product&); //so sanh gia
        bool operator<(Product&); //so sanh gia
};