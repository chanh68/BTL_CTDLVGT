#include <iostream>
#include <string>
#include <fstream>
#include "dlist.cpp"
using namespace std;
class HocSinh
{
	public:
		string ten;
		string lop;
		string sdt;
		float dtb;
		HocSinh()
		{
			ten = "";
			lop = "";
			sdt = "";
			dtb = 0.0;
		}
		HocSinh(string ten, string lop, string sdt, float dtb)
		{
			this->ten = ten;
			this->lop = lop;
			this->sdt = sdt;
			this->dtb = dtb;
		}
	
		string getTen()
		{
			return ten;
		}
		string getLop()
		{
			return lop;
		}
		string getSdt()
		{
			return sdt;
		}
		float getDtb()
		{
			return dtb;
		}
		
		bool operator<(HocSinh& hs)
		{
			return this->dtb < hs.dtb;
		}
};
	
class DS_HocSinh
	{
	private:
		dlist<HocSinh> ds;
		int n;
	
	public:
		DS_HocSinh()
		{
		}
		void Nhap_DSHocSinh()
		{
			do
			{
				cout << "Nhap so luong hoc sinh: ";
				cin >> n;
			} while (n < 1);
	
			for (int i = 0; i < n; i++)
			{
				cout << "Nhap thong tin hoc sinh thu " << i + 1 << ":" << endl;
				ThemHocSinh();
			}

			cout << "~ Danh sach hoc sinh da duoc them!" << endl;
		}
	
		void ThemHocSinh()
		{
			HocSinh hs;
			cin.ignore();
			cout << "Nhap ten hoc sinh: ";
			getline(cin, hs.ten);
			cout << "Nhap lop hoc: ";
			getline(cin, hs.lop);
			cout << "Nhap so dien thoai: ";
			getline(cin, hs.sdt);
			cout << "Nhap diem trung binh: ";
			cin >> hs.dtb;
			HocSinh s(hs.ten, hs.lop, hs.sdt, hs.dtb);
			ds.push_back(s);
			cout << "~ Hoc sinh moi da duoc them vao danh sach!" << endl;
		}
		
		void docTuFile(const string &tenFile)
		{
			ifstream file(tenFile);
			if (!file.is_open())
			{
				cerr << "Khong the mo file " << tenFile << " de doc.\n";
				return;
			}
			HocSinh hs;
			while ((getline(file, hs.ten, ';') && getline(file, hs.lop, ';')) && (getline(file, hs.sdt, ';') && file >> hs.dtb))
			{
				HocSinh s(hs.ten, hs.lop, hs.sdt, hs.dtb);
				ds.push_back(s);
			}
			file.close();
			cout << "Danh sach trong file da duoc doc xong!" << endl;
		}
			
		void inThongTin()
		{
			dlist<HocSinh>:: iterator it;
			for (it=ds.begin(); it!=ds.end(); it++)
			{
				HocSinh hs = *it; 
				cout << "Ho va ten: " << hs.getTen() << endl;
				cout << "Lop: " << hs.getLop() << endl;
				cout << "So dien thoai: " << hs.getSdt() << endl;
				cout << "Diem TB: " << hs.getDtb() << endl;
				cout << endl;
			}
		}
				
		void ghiRaFile(const string &tenFile) 
		{
	        ofstream file(tenFile);
	        if (!file.is_open()) 
			{
	            cerr << "Khong the mo file " << tenFile << " de ghi.\n";
	            return;
	        }
	
	        dlist<HocSinh>::iterator it;
	        for (it = ds.begin(); it != ds.end(); it++) 
			{
	            HocSinh hs = *it;
	            file << hs.getTen() << ";" << hs.getLop() << ";" << hs.getSdt() << ";" << hs.getDtb() << endl;
	        }
	
	        file.close();
	        cout << "Danh sach hoc sinh da duoc ghi ra file." << endl;
   	}

		void inTenVaXepLoai() 
		{
			dlist<HocSinh>::iterator it;
			for (it = ds.begin(); it != ds.end(); it++) 
			{
				HocSinh hs = *it;
				cout << "Ho va ten: " << hs.getTen() << " - Xep loai: " << xepLoai(hs.getDtb()) << endl;
        	}
    	}

		string xepLoai(float dtb) 
		{
			if (dtb >= 8.5)
				return "Gioi";
			else if (dtb >= 7.0)
				return "Kha";
			else if (dtb >= 5.5)
				return "Trung Binh";
			else if (dtb >= 4.0)
				return "Trung Binh Yeu";
			else
				return "Yeu";
		}

		string timHocSinhTheoTenVaLop(string& ten, string& lop) 
		{
			dlist<HocSinh>::iterator it;
			for (it = ds.begin(); it != ds.end(); it++) 
			{
				HocSinh hs = *it;
				if (hs.getTen() == ten && hs.getLop() == lop) 
				{
					return hs.getSdt(); 
				}
			}
			return ""; 
		}

		void xoaHocSinhTheoLop(string& lop)
		{
		 	bool daLoaiBo = false;
		 	dlist<HocSinh>::iterator it;
			for (it = ds.begin(); it != ds.end(); it++)
		 	{
		 		if ((*it).getLop() == lop)
		 		{
		 			ds.erase(it);
		 			daLoaiBo = true;
		 		} 
		 	}
		 	if (daLoaiBo) {
		 		cout << "Da loai bo hoc sinh cua lop " << lop << " khoi danh sach.\n";
		 	} 
		 	else {
		 		cout << "Khong tim thay hoc sinh nao cua lop " << lop << " trong danh sach.\n";
		 	}
		}

		void sapXepTheoDiem() {
			ds.sort(false);
			cout << "Da sap xep danh sach theo diem giam dan.\n";
		}

		void ChenHocSinh()
		{
			HocSinh hs;
			cin.ignore();
			cout << "Nhap ten hoc sinh: ";
			getline(cin, hs.ten);
			cout << "Nhap lop hoc: ";
			getline(cin, hs.lop);
			cout << "Nhap so dien thoai: ";
			getline(cin, hs.sdt);
			cout << "Nhap diem trung binh: ";
			cin >> hs.dtb;

			dlist<HocSinh>::iterator it;
			for (it = ds.begin(); it != ds.end(); it++)
			{
				if (hs.getDtb() >= (*it).getDtb())
				{
					ds.insert(it, hs);
					return;
				}
			}

			// Nếu đã duyệt hết danh sách mà chưa chèn, thì chèn vào cuối danh sách
			ds.push_back(hs);

			cout << "~ Hoc sinh moi da duoc chen vao danh sach!" << endl;
		}




};

int main()
{
	    DS_HocSinh ds;
    int luaChon;

    do {
        cout << "\n--------------------------- MENU ---------------------------------\n";
        cout << "|| 1. Nhap danh sach hoc sinh tu ban phim.\n";
        cout << "|| 2. Nhap danh sach hoc sinh tu file.\n";
        cout << "|| 3. In danh sach hoc sinh gom ten va xep loai.\n";
        cout << "|| 4. In danh sach hoc sinh gom thong tin day du.\n";
        cout << "|| 5. Tim kiem so dien thoai theo ten va lop.\n";
        cout << "|| 6. Bo sung hoc sinh moi vao danh sach.\n";
        cout << "|| 7. Loai bo hoc sinh theo lop.\n";
        cout << "|| 8. Sap xep danh sach theo diem giam dan.\n";
        cout << "|| 9. Chen hoc sinh moi vao danh sach ma khong lam thay doi thu tu.\n";
        cout << "||10. Luu danh sach hoc sinh vao file.\n";
        cout << "|| 0. Thoat.\n";
        cout << "---------------------------- MENU ---------------------------------\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;
        

        switch (luaChon) 
		{
            case 1:
                ds.Nhap_DSHocSinh();
                break;
           case 2: 
			{
               string tenFile;
               cout << "Nhap ten file: ";
               cin >> tenFile;
               ds.docTuFile(tenFile);
               break;
           }
            case 3:
                ds.inTenVaXepLoai();
                break;
            case 4:
            	cout << "\nDanh sach hoc sinh:\n";
                ds.inThongTin();
                break;
            case 5:
			{
				string ten, lop;
				cout << "Nhap ten hoc sinh: ";
				cin.ignore();
				getline(cin, ten);
				cout << "Nhap ten lop: ";
				getline(cin, lop);
                string sdt = ds.timHocSinhTheoTenVaLop(ten, lop);
				if (sdt != "") 
				{
					cout << "Sdt cua hoc sinh " << ten << " trong lop " << lop << " la: " << sdt << endl;
				} 
				else {
					cout << "Khong tim thay hoc sinh " << ten << " trong lop " << lop << endl;
				}
                break;
			}

            case 6:
                ds.ThemHocSinh();
                break;
             case 7:
             {
			 	string lop;
			 	cout << "Nhap ten lop can loai bo: ";
			 	cin.ignore();
			 	getline(cin, lop);
			 	ds.xoaHocSinhTheoLop(lop);
			 	break;
			 }   
            case 8:
                ds.sapXepTheoDiem();
                break;
            case 9:
			{
				ds.ChenHocSinh();
				cout << "\nDanh sach hoc sinh sau khi chen them hoc sinh: " << endl;
				ds.inThongTin();
                break;
			}

           case 10: {
               string tenFile;
               cout << "Nhap ten file: ";
               cin >> tenFile;
               ds.ghiRaFile(tenFile);
               break;
           }
            case 0:
                cout << "Chuong trinh ket thuc.\n";
                break;
            default:
                cout << "Lua chon khong hop le. Vui long nhap lai.\n";
        }
    } while (luaChon != 0);

    return 0;
}
