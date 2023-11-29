#include <iostream>
#include <string.h>

using namespace std;

class String{
	private:
		string a;
	public:
		String()
		{
			a = "";
		}
		String(string a)
		{
			this->a = a;
		}
		string getA(){
			return a;
		}
		//Nhap
		void nhap()
		{
			cout << "Nhap xau ki tu can kiem tra: ";
			getline (cin, a);
		}
		//Xuat
		void xuat()
		{
			cout << "\nKet qua: " << getA() << '\n';
		}
		//Cat cac ki tu trang (dau cach) o hai dau cua xau
		void XoaKhoangTrang2Dau() 
		{
			// Xac dinh vi tri dau tien cua chuoi khong phai khoang trang
		    int start = 0;
		    while (start < a.length() && a[start] == ' ') {
		        start++;
		    }
		
		    // Xac dinh vi tri cuoi cung cua chuoi khong phai khoang trang
		    int end = a.length() - 1;
		    while (end >= 0 && a[end] == ' ') {
		        end--;
		    }
		
		    // Cat chuoi loai bo cac khoang trang 2 dau
		    if (start <= end) {
		        a = a.substr(start, end - start + 1);
		    } else {
		        a = "";
		    }
		}
		//Cat bo toan bo ki tu trang thua trong sau
		void XoaKhoangTrangThua() {
		    string ket_qua;
		    bool truoc_la_khoang_trang = false;
		    
		    for (int i = 0; i < a.length(); i++) 
			{
		        if (a[i] == ' ') 
				{
		            if (truoc_la_khoang_trang == false) 
					{
		                ket_qua += a[i];
		            }
		            truoc_la_khoang_trang = true;
		        } 
				else {
		            truoc_la_khoang_trang = false;
		            ket_qua += a[i];
		        }
		    }
		    a = ket_qua;
		}
		// Doi toan bo xau thanh chu hoa		
		void DoiChuHoa() 
		{
		    for (int i = 0; i < a.length(); i++) 
			{
		        if (a[i] >= 'a' && a[i] <= 'z') 
				{
		            a[i] -= 32;
		        }
		    }
		}
		// Doi toan bo xau thanh chu thuong
		void DoiChuThuong() 
		{
		    for (int i = 0; i < a.length(); i++) 
			{
		        if (a[i] >= 'A' && a[i] <= 'Z') 
				{
		            a[i] += 32;
		        }
		    }
		}
		// Noi them xau ky tu vao sau xau hien co
	    void NoiXau(string s) 
		{
	        a += s;
	    }
	    // Trich ra n ki tu o ben phai xau
	    string TrichXau_Phai(int n) 
		{
	        if (n >= a.length()) 
			{
	            return a;
	        }
	        return a.substr(a.length() - n);
	    }
	    // Trich ra n ki tu o ben trai xau
	    string TrichXau_Trai(int n) 
		{
	        if (n >= a.length()) 
			{
	            return a;
	        }
	        return a.substr(0, n);
	    }
	    // Trich ra n ki tu ke tu vi tri i cua xau
	    string TrichXau_Vitri(int vitri, int n) 
		{
	        if (vitri >= a.length())
			{
	            return "";
	        }
	        return a.substr(vitri, n);
	    }		
};

int main()
{
	String x;
    int chon = 0;
    int n = 0; 
    do{
    	cout<<"=======---MENU---=======\n";
    	cout<<"||1. Nhap xau ki tu.\n";
    	cout<<"||2. In ra xau ki tu.\n";
    	cout<<"||3. Cat khoang trang(dau cach) o hai dau xau.\n";
    	cout<<"||4. Cat toan bo khoang trang thua co trong xau.\n";
    	cout<<"||5. Chuyen toan bo xau ki tu thanh xau ki tu hoa.\n";
    	cout<<"||6. Chuyen toan bo xau ki tu thanh xau ki tu thuong.\n";
    	cout<<"||7. Noi them mot xau ki tu vao sau xau ki tu hien co.\n";
    	cout<<"||8. Trich ra N ki tu o phia phai cua xau.\n";
    	cout<<"||9. Trich ra N ki tu o phia trai cua xau.\n";
    	cout<<"||10.Trich ra N ki tu ke tu vi tri thu i cua xau.\n";
    	cout<<"||0. Exit.\n";
    	cout<<"========---MENU---=======\n";
    	cout << "\nNhap lua chon cua ban: ";
		cin>> chon ;
    	cin.ignore();
    	switch (chon) {
            case 1: { 
                x.nhap();
                cout << " ~ Da nhap xong!" << endl;
                break;
            }
            case 2: {
                x.xuat();
                break;
            }
            case 3: {
                x.XoaKhoangTrang2Dau();
                cout << " ~ Da xoa xong khoang trang 2 dau xau!" << endl;
                break;
            }
            case 4: {
                x.XoaKhoangTrangThua();
                cout << " ~ Da xoa xong khoang trang thua trong xau!" << endl;
                break;
            }
            case 5: {
                x.DoiChuHoa();
                cout << " ~ Da doi toan bo ki tu xau thanh chu hoa!" << endl;
                break;
            }
            case 6: {
                x.DoiChuThuong();
                cout << " ~ Da doi toan bo ki tu xau thanh chu thuong!" << endl;
                break;
            }
           case 7: {
                string s;
			    cout << "- Nhap xau can them vao:";
			    getline(cin,s);
			    x.NoiXau(s);
			    cout << "- Xau moi la: " << x.getA() << endl; 
                break;
            }
            case 8: {
			    cout<<"- Trich ra N ki tu ben phai: ";
			    cin>> n;
			    cout << "- Xau moi la: " << x.TrichXau_Phai(n) << endl; 
                break;
            }
            case 9: {
			    cout<<"- Trich ra N ki tu ben trai: ";
			    cin>> n;
			    cout << "-> Xau moi la: " << x.TrichXau_Trai(n) << endl;
                break;
            }
            case 10: {
                int vitri ; 
			    cout<<"- Trich ra N ki tu:";
			    cin>> n;
			    cout<<"- Ke tu vi tri:";
			    cin >> vitri;
			    cout << "-> Xau moi la: " << x.TrichXau_Vitri(vitri, n) << endl; 
				break;
        	}
        	default:
                if (chon < 0 || chon > 10) { 
                    cout << "Ban nhap sai lua chon, vui long nhap lai" << endl;
                    continue; 
                }
                cout << "Ban chon thoat khoi chuong trinh" << endl;
        }
    	
	}while(chon!=0);
	
	return 0;   	
}
