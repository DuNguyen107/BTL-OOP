#ifndef KHACHTRO_H
#define KHACHTRO_H

#include <string>

class KhachTro {
private:
    std::string maKhach;
    std::string hoTen;
    std::string CMND;
    std::string diaChi;
    std::string gioiTinh;
    std::string ngheNghiep;

public:
    KhachTro(std::string maKhach, std::string hoTen, std::string CMND, std::string diaChi, std::string gioiTinh, std::string ngheNghiep);
    
    // Getter và Setter
    std::string getMaKhach() const;
    std::string getHoTen() const;
    std::string getCMND() const;
    std::string getDiaChi() const;
    std::string getGioiTinh() const;
    std::string getNgheNghiep() const;

    void setHoTen(std::string hoTen);
    void setDiaChi(std::string diaChi);
    void setNgheNghiep(std::string ngheNghiep);

    void hienThiThongTin() const;
};

#endif
