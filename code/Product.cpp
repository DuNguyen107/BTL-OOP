#include "product.h"

Product::Product(){
    this->productID = "0";
    this->name = "";
    this->price = 0;
    this->CPU = "";
    this->RAM = 0;
    this->GPU = "";
    this->hardDisk = 0;
    this->importPrice = 0;
    this->screen = "";
    this->quantity = 0;
    this->OS = "";
    this->brand = "";
    //serial duoc tu dong tao bang ham dung;
}
Product::Product(string ID, string name, double price, double importPrice, string CPU, int RAM, 
                string screen, int hardDisk, string GPU, string OS, string brand)
{ 
	this->productID = ID;
	this->name = name;
	this->price = price;
	this->importPrice = importPrice;
	this->CPU = CPU;
	this->RAM = RAM;
    this->screen = screen;
	this->hardDisk = hardDisk;
	this->GPU = GPU;
	this->OS = OS;
	this->brand = brand;
    this->quantity = 0;
    //serial duoc tu dong tao bang ham dung;
}
Product::Product(const Product& other){ 
	this->productID = other.productID;
	this->name = other.name;
	this->quantity = other.quantity;
    this->serial = other.serial;
	this->price = other.price;
	this->importPrice = other.importPrice;
    this->CPU = other.CPU;
	this->RAM = other.RAM;
	this->screen = other.screen;
    this->hardDisk = other.hardDisk;
	this->GPU = other.GPU;
	this->OS = other.OS;
	this->brand = other.brand;
}
Product::~Product()
{ }


Product& Product::operator=(const Product& other)
{
    if (this != &other) {
        this->productID = other.productID;
        this->name = other.name;
        this->quantity = other.quantity;
        this->serial = other.serial;
        this->price = other.price;
        this->importPrice = other.importPrice;
        this->CPU = other.CPU;
        this->RAM = other.RAM;
        this->screen = other.screen;
        this->hardDisk = other.hardDisk;
        this->GPU = other.GPU;
        this->OS = other.OS;
        this->brand = other.brand;
    }
    return *this;
}

void Product::show(){
	cout << setw(50) << " " << string(60, '=') << endl;
	cout << setw(50) << " " << "Thông tin chung:" << endl;
    cout << left
	<< setw(50) << " " << setw(25) << "  Mã sản phẩm: " << productID << endl
    << setw(50) << " " << setw(25) << "  Tên sản phẩm: " << name << endl
    << setw(50) << " " << setw(24) << "  Thương hiệu: " << brand << endl
    << setw(50) << " " << setw(22) << "  Giá bán: " << fixed << setprecision(0) <<  price << " VND" << endl;
    cout << setw(50) << " " << "Thông số kỹ thuật:" << endl;
    cout << left
    << setw(50) << " " << setw(20) << "  CPU: " << CPU << endl
    << setw(50) << " " << setw(20) << "  RAM: " << RAM << "GB" << endl
    << setw(50) << " " << setw(22) << "  Màn hình: " << screen << endl
    << setw(50) << " " << setw(24) << "  Ổ cứng: " << hardDisk << "GB" << endl
    << setw(50) << " " << setw(20) << "  GPU: " << GPU << endl
    << setw(50) << " " << setw(26) << "  Hệ điều hành: " << OS << endl;
    cout << setw(50) << " " << setw(25) << "  Số lượng: " << quantity << " máy" << endl;
    cout << setw(50) << " " << string(60, '=') << endl;
}
ostream& operator<<(ostream& os,const Product& p){
    os << setw(50) << " " << string(60, '=') << endl;
	os << setw(50) << " " << "Thông tin chung:" << endl;
    os << left
	<< setw(50) << " " << setw(25) << "  Mã sản phẩm: " << p.productID << endl
    << setw(50) << " " << setw(25) << "  Tên sản phẩm: " << p.name << endl
    << setw(50) << " " << setw(24) << "  Thương hiệu: " << p.brand << endl
    << setw(50) << " " << setw(22) << "  Giá bán: " << fixed << setprecision(0) <<  p.price << " VND" << endl;
    os << setw(50) << " " << "Thông số kỹ thuật:" << endl;
    os << left
    << setw(50) << " " << setw(20) << "  CPU: " << p.CPU << endl
    << setw(50) << " " << setw(20) << "  RAM: " << p.RAM << "GB" << endl
    << setw(50) << " " << setw(22) << "  Màn hình: " << p.screen << endl
    << setw(50) << " " << setw(24) << "  Ổ cứng: " << p.hardDisk << "GB" << endl
    << setw(50) << " " << setw(20) << "  GPU: " << p.GPU << endl
    << setw(50) << " " << setw(26) << "  Hệ điều hành: " << p.OS << endl;
    os << setw(50) << " " << setw(25) << "  Số lượng: " << p.quantity << " máy" << endl;
    os << setw(50) << " " << setw(22) << "  Số serial: ";
    Node<string>* currentNode = p.serial.getHead();
    int count = 0;
    while (currentNode != nullptr) 
    {
        count++; 
        if(count % 4 == 0){
        	cout << endl;
        	os << setw(70) << " ";
		}
		os << currentNode->data;
        currentNode = currentNode->next;
        if (currentNode != nullptr) {
            os << ", ";
        }
    }
    cout << endl;
    cout << setw(50) << " " << string(60, '=') << endl;
    return os;
}
bool Product::operator!=(const Product& p){
    return (this->productID != p.productID);
}
bool Product::operator==(const Product& p){
    return (this->productID == p.productID);
}
string Product::getName(){
    return this->name;
}
string Product::getID() const
{
    return this->productID;
}
double Product::getPrice(){
    return this->price;
}
double Product::getImportPrice(){
    return this->importPrice;
}
double Product::Profit(){
    return (this->price - this->importPrice); 
}
string Product::getCPU(){
    return this->CPU;
}
int Product::getRAM(){
    return this->RAM;
}
string Product::getScreen(){
    return this->screen;
}
int Product::getHardDisk(){
    return this->hardDisk;
}
string Product::getGPU(){
    return this->GPU;
}
string Product::getOS()
{
    return this->OS;
}
int Product::getQuantity()
{
    return this->quantity;
}
string Product::getBrand()
{
    return this->brand;
}
void Product::setName(string name){
    this->name = name;
}
void Product::setID(string id){
    this->productID = id;
}
void Product::setImportPrice(double p){
    this->importPrice = p;
}
void Product::setPrice(double price){
    this->price = price;
}
void Product::setCPU(string cpu){
    this->CPU = cpu;
}
void Product::setRAM(int ram){
    this->RAM = ram;
}
void Product::setScreen(string screen){
    this->screen = screen;
}
void Product::setHardDisk(int h){
    this->hardDisk = h;
}
void Product::setGPU(string gpu){
    this->GPU = gpu;
}
void Product::setOS(string newOS){
    this->OS = newOS;
}
void Product::setQuantity(int newQuantity)
{
    this->quantity = newQuantity;
}
void Product::setBrand(string& newBrand)
{
    this->brand = newBrand;
}
bool Product::isSerial(string& s)
{
    Node<string>* p = this->serial.getHead();
    while (p != nullptr) {
        if (p->data == s) {
            return true;
        }
        p = p->next;
    }
    return false;
}

void Product::addSerial(string& newSerial)
{
    if (!this->isSerial(newSerial)) 
    {
        this->serial.addTail(newSerial);
        quantity++;
    }
}
void Product::removeSerial(string& seri)
{
    if (this->isSerial(seri)) {
        this->serial.remove(seri);
        quantity--;
    }
}
List<string>& Product::getSerial()
{
    return this->serial;
}
bool Product::operator>(Product& p)
{
    return this->getPrice() > p.getPrice();
}
bool Product::operator<(Product& p)
{
    return this->getPrice() < p.getPrice();
}


