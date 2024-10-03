#ifndef PHONGTRO_H
#define PHONGTRO_H

#include <string>

class PhongTro {
private:
    std::string maPhong;
    std::string loaiPhong;
    double giaPhong;
    int soLuongNguoiToiDa;
    std::string tinhTrang;

public:
    PhongTro(std::string maPhong, std::string loaiPhong, double giaPhong, int soLuongNguoiToiDa, std::string tinhTrang);
    
    // Getter và Setter cho các thuộc tính
    std::string getMaPhong() const;
    std::string getLoaiPhong() const;
    double getGiaPhong() const;
    int getSoLuongNguoiToiDa() const;
    std::string getTinhTrang() const;

    void setLoaiPhong(std::string loaiPhong);
    void setGiaPhong(double giaPhong);
    void setSoLuongNguoiToiDa(int soLuongNguoiToiDa);
    void setTinhTrang(std::string tinhTrang);

    void hienThiThongTin() const;
};

#endif
