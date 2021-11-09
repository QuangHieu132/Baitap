#include<iostream>
using namespace std;

//Dang nhap va Dang Ki
struct thanhVien{
	int taiKhoan;
	int matKhau;
};
thanhVien dk;
void dangKi();

thanhVien dn;
void dangNhap();


//MeNu Chinh va MeNu Thu Vien
void luaChonChinh();
void menuChinh();
void menu();
void luaChon();



int main(){
	menuChinh();
	
}


void menuChinh(){
	cout << "               +-------------------------------------------------+ \n";
    cout << "               |      		CHUONG TRINH THU VIEN      	 | \n";
    cout << "               |-------------------------------------------------| \n";
    cout << "               |                                                 | \n";
	cout << "               |  1. Dang ky tai khoan.                     	 | \n";
	cout << "               |  2. Dang nhap tai khoan.                     	 | \n";
	cout << "               |  3.Thoat chuong trinh                           | \n";
    cout << "               +-------------------------------------------------+ \n";
	luaChonChinh();
	
}


void luaChonChinh(){
	int key;
	cout<<"Nhap lua chon cua ban:  ";
	cin>>key;
	switch(key){
		case 1:dangKi();menuChinh();break;
		case 2:dangNhap();break;
		case 3:cout<<"========================"<<endl<<"Xin cam on ,hen gap lai quy khach";break;
		
	}
}

void dangKi(){
	cout<<"Nhap tai khoan: ";
	cin>>dk.taiKhoan;
	
	cout<<"Nhap mat khau: ";
	cin>>dk.matKhau;

	cout<<"Tai khoan tao thanh cong"<<endl;
	cout<<"Tai Khoan: "<<dk.taiKhoan<<endl;
	cout<<"Mat Khau: "<<dk.matKhau<<endl;
}

void dangNhap(){
	cout<<"Nhap Tai khoan: ";
	cin>>dn.taiKhoan;
	cout<<"Nhap Mat khau: ";
	cin>>dn.matKhau;
	
	if(dn.taiKhoan==dk.taiKhoan && dn.matKhau==dk.matKhau ) 
		return menu();
	else 
		cout<<"Sai tai khoan hoac mat khau";
}


// Sau Khi Da Dang Nhap Thanh Cong

void menu(){
 cout <<  endl;
    cout << "               +-------------------------------------------------+ \n";
    cout << "               |      GIAO DIEN QUAN LY SACH TRONG THU VIEN      | \n";
    cout << "               |-------------------------------------------------| \n";
    cout << "               |                                                 | \n";
    cout << "               |  1. Nhap sach vao thu vien.                     | \n";
    cout << "               |  2. Xoa sach khoi thu vien.                     | \n";
    cout << "               |  3. Xuat Danh sach sach.                        | \n";
  	cout << "               |  4. Muon sach tu thu vien.                      | \n";
    cout << "               |  5. Tra sach.                    		 | \n";
    cout << "               |  6. Tim sach trong Thu vien.                    | \n";
    cout << "               |  7. Quay lai dang nhap.                         | \n";
    cout << "               |                                                 | \n";
    cout << "               +-------------------------------------------------+ \n";

	luaChon();


}



void luaChon(){
	int key;
	cout<<"Nhap lua chon cua ban:  ";
	cin>>key;
	switch (key){
		case 1:cout<<"Nhap sach vao thu vien"<<endl;break;
		case 2:cout<<"Xoa sach khoa thu vien"<<endl;break;
		case 3:cout<<"Xuat Danh sach sach"<<endl;break;
		case 4:cout<<"Muon sach vao thu vien"<<endl;break;
		case 5:cout<<"Tra sach"<<endl;break;
		case 6:cout<<"Tim sach trong Thu vien"<<endl;break;
		case 7:menuChinh();break;
		
		
	}
	
}
