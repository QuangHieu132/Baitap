#include <iostream>
#include <cstring>
#include <iomanip>
#include <string>


//Doi ti search gg cai :)

using namespace std;
 
 
 
int total_book_types = 0;        // Tat ca loai sach cua thu vien.
int total_bills = 0;
int total_books = 0;                   // Tong sach thu vien
int info[10];
 
 
////===============================================================================================
//                                                                                                
//  KHAI BAO CAC STRUCT.  
//
////===============================================================================================
 
struct n_DATE {
    int n_day;
    int n_month;
    int n_year;
};
 
struct BOOK {
    char b_ma[50];
    char b_tensach[50];
    char b_tacgia[50];
    char b_theloai[50];
    char b_nhaXB[50];  
    int b_soluong;
};
 
struct BILL {  
    char bill_tenSV[50];
    char bill_maSV[50];
    BOOK bill_sach_muon;
    n_DATE bill_ngaymuon;
};
 

 
 
#define MAX_SIZE 100
typedef BOOK LIST_BOOK[MAX_SIZE];                    // Kieu LIST_BOOK la mang 100 cuon sach.
typedef BILL LIST_BILL[MAX_SIZE];                    // Kieu LIST_BILL la mang 100 phieu muon.
         // Kieu LIST_DETAIL la mang 100 chi tiet phieu muon.
 
 
LIST_BOOK lst_book;             // Bien lst_book la mang 50 cuon sach.
LIST_BILL lst_bill;             // Bien lst_bill la mang 50 phieu muon.
 
 
////===============================================================================================
//
//  KHAI BAO MAU CHO HAM.
//
////===============================================================================================
 
 
//-----------------------------------------------
    void phieu_load_file();
    void phieu_save_file();
    void phieu_nhap();
    void phieu_xuat();
    void phieu_them();
    void phieu_xoa();
    int  phieu_tim(char ma_tam[]);
    void phieu_hieu_chinh();
//-----------------------------------------------
    void ctphieu_nhap();
    void ctphieu_xuat();
    void ctphieu_load_file();
    void ctphieu_save_file();
//-----------------------------------------------
    void sach_load_file();
    void sach_save_file(); 
    void sach_nhap();
    void sach_xuat();
    void sach_hieu_chinh();
    void sach_them();
    void sach_xoa();
    int  sach_tim(char ma_tam[]);
//-----------------------------------------------
    
    void TK_soluong_sach();
//-----------------------------------------------
    void file_info();
    void load_file_info();
    void interface_main();
 
  
    
 
 
 
//// CHUONG TRINH CHINH.
////===============================================================================================
////===============================================================================================
//                                                                                              //         
    int main()                                                                                  //
    {              
        //___________Load previous data_________
        load_file_info();
        sach_load_file();
        phieu_load_file();                                                                      //
        interface_main();                                                                       // 
    }                                                                                           //
//                                                                                              // 
////===============================================================================================
////===============================================================================================
 
 
////===============================================================================================
//
//  DAY DUNG CAC HAM TO CHUC MENU.
//
////===============================================================================================
 
 
void interface_book_manager() {
while(true){
    //system("cls");
    cout << endl << endl;
    cout << "               +-------------------------------------------------+ \n";
    cout << "               |      GIAO DIEN QUAN LY SACH TRONG THU VIEN      | \n";
    cout << "               |-------------------------------------------------| \n";
    cout << "               |                                                 | \n";
    cout << "               |  1. Nhap sach vao thu vien.                     | \n";
    cout << "               |  2. Xoa sach khoi thu vien.                     | \n";
    cout << "               |  3. Xuat Danh sach sach.                        | \n";
    cout << "               |  4. Tim sach trong Thu vien.                    | \n";
    cout << "               |  5. Hieu chinh sach.                            | \n";
    cout << "               |  6. Back.                                       | \n";
    cout << "               |                                                 | \n";
    cout << "               +-------------------------------------------------+ \n";
 
    char chon;
    bool k = true;
    char ma_tam[50];
    int i;
   
    do
    {   if (k == false)
            cout << "Hay chon cong viec theo so tu 1 den 3 :";
        else
            cout << "Chon cong viec theo so: "; cin >> chon;
        k = false;
    } while ((chon < '1') || (chon > '7'));
 
 
    switch (chon) {
        case '1':   sach_nhap();
                    break;
        case '2':
                    sach_xoa();
                    break;
        case '3':                  
                    sach_xuat();
                    break;
        
        case '4':              
                    cin.ignore();
                    cout << "Nhap ma sach can tim : "; cin.getline(ma_tam, 50);
   
                    i = sach_tim(ma_tam);
 
                    if (i == -1)
                        cout << "- Khong tim thay sach co ma so tren. ";
                    else {
                        cout << "\nDa tim thay sach: \n";
                        cout << setw(13) << ".Ma Sach" << setw(13) << "Ten Sach" << setw(13) << "The Loai" << setw(13) << "So Luong" << endl << endl;
                        cout << setw(13) << lst_book[i].b_ma << setw(13) << lst_book[i].b_tensach << setw(13) << lst_book[i].b_theloai << setw(13) << lst_book[i].b_soluong;
                        cout << endl;
                    }
                    break;
        case '5':
                    sach_hieu_chinh();
                    break;
        case '6':
                    return interface_main();
                    
    }
}

}
 
void interface_bill_manager() {
while(true) {
    //system("cls");
    cout << endl << endl;
    cout << "               +-------------------------------------------------+ \n";
    cout << "               |      GIAO DIEN QUAN LY PHIEU MUON SACH          | \n";
    cout << "               |-------------------------------------------------| \n";
    cout << "               |                                                 | \n";
    cout << "               |  1. Phieu Muon Sach.                            | \n";
    cout << "               |  2. Phieu Tra Sach.                             | \n";
    cout << "               |  3. Xuat Phieu.                                 | \n";
    cout << "               |  4. Hieu chinh Phieu.                           | \n";
    cout << "               |  5. Tim Phieu.                                  | \n";
    cout << "               |  6. Back.                                       | \n";
    cout << "               |                                                 | \n";
    cout << "               +-------------------------------------------------+ \n";
 
    char chon;
    bool k = true;
    char ma_tam[50];
    int i;
   
    do
    {   if (k == false)
            cout << "Hay chon cong viec theo so tu 1 den 3 :";
        else
            cout << "Chon cong viec theo so: "; cin >> chon;
        k = false;
    } while ((chon < '1') || (chon > '7'));
 
 
    switch (chon) {
        case '1':   system("cls");
                    phieu_nhap();
                    break;
        
        case '2':                  
                    phieu_xoa();
                    break;
        case '3':
                    system("cls");
                    phieu_xuat();
                    break;
        case '4':
                    system("cls");
                    phieu_hieu_chinh();
                    break;
        case '5':      
                    cin.ignore();
                    cout << "Nhap ma phieu (Ma SV) can tim : "; cin.getline(ma_tam, 50);
   
                    i = phieu_tim(ma_tam);
 
                    if (i == -1)
                        cout << "- Khong tim thay phieu co ma so tren. ";
                    else {
                        cout << "\nDa tim thay phieu: \n";
                        cout << setw(15) << ".Ma Phieu/ Ma SV" 
                             << setw(15) << "Ten SV" 
                             << setw(15) << "Ma sach"
                             << setw(15) << "Ngay muon"
                             << endl << endl;

                        cout << setw(15) << lst_bill[i].bill_maSV 
                             << setw(15) << lst_bill[i].bill_tenSV
                             << setw(15) << lst_bill[i].bill_sach_muon.b_ma
                             << setw(15) << to_string(lst_bill[i].bill_ngaymuon.n_day)+"/"+
                                            to_string(lst_bill[i].bill_ngaymuon.n_day)+"/"+
                                            to_string(lst_bill[i].bill_ngaymuon.n_day);
                        cout << endl;
                    }
                    break;
        case '6':
                    return interface_main();
    }
}
}
 

   
void interface_main() {
while(true){
    system("cls");

    cout << endl << endl;
    cout << "               +=================================================+ \n";
    cout << "               |         CHUONG TRINH QUAN LY THU VIEN           | \n";
    cout << "               |-------------------------------------------------| \n";
    cout << "               |                                                 | \n";
    cout << "               |  1. Quan ly sach trong Thu vien.                | \n";
    cout << "               |  2. Quan ly phieu ban doc.                      | \n";
    cout << "               |  3. Exit.                                       | \n";
    cout << "               |                                                 | \n";
    cout << "               +-------------------------------------------------+ \n";
 
    char chon;
    bool k = true;
 
    do
    {   if (k == false)
            cout << "Hay chon cong viec theo so tu 1 den 3 :";
        else
            cout << "Chon cong viec theo so: "; 
        cin >> chon;
        k = false;
    } while ((chon < '1') || (chon > '3'));
 
 
 
    switch (chon) {
        case '1':
                    system("cls");
                    interface_book_manager();
                    break;
        case '2':
                    system("cls");
                    interface_bill_manager();
                    break;
       
        
        case '3':	exit(0);
                    
                    
    }
}

}
 
 
////===============================================================================================
//
//  DINH NGHIA CAC HAM.
//
////===============================================================================================
 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DINH NGHIA HAM CHO DOI TUONG SACH.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 
void file_info() {
    FILE * f_b;
    info[0] = total_book_types;
    info[1] = total_bills;
    info[2] = total_books;
    f_b = fopen("file_info", "wb");
    fwrite(info, sizeof(info), 1, f_b);
    fclose(f_b);
}

void load_file_info() {
    FILE * f_b;
    f_b = fopen("file_info", "rb");
    fread(info, sizeof(info), 1, f_b);
    total_book_types = info[0];
    total_bills = info[1];
    total_books = info[2];
    fclose(f_b);
}

void sach_load_file() {
    FILE * f_b;
    f_b = fopen("book_file", "rb");
    fread(lst_book, sizeof(lst_book), 1, f_b);
    fclose(f_b);
}
 
void sach_save_file() {
    FILE * f_b;
    f_b = fopen("book_file", "wb");
    fwrite(lst_book, sizeof(lst_book), 1, f_b);
    fclose(f_b);
}
 
int sach_tim(char ma_tam[]) {
    for(int jump = 0; jump < total_book_types; ++jump){
        if(!strcmp(lst_book[jump].b_ma, ma_tam)){
            return jump;
        }
    }
    return -1;
}
 
void sach_nhap() {
    char ma_tam[50];
    int tong_sach_nhap;

    do {
        cout << endl;
        cout << "NHAP SACH. \n";
        cout << "Hay nhap so luong sach se nhap: "; cin >> tong_sach_nhap;
        cout << endl;
    } while(tong_sach_nhap < 0);
 
    for (int i = total_book_types; i < tong_sach_nhap + total_book_types; i++) {
    nhap_ma:;
        cin.ignore(1);
        cout << ". Ma Sach: "; cin.getline(ma_tam, 50);
 
        if (sach_tim(ma_tam) != -1) {
            cout << "   Ma sach da ton tai.";
            cout << "   Nhan Enter de nhap lai !";
            goto nhap_ma;
        }
 
        //cin.ignore(1);
        strcpy(lst_book[i].b_ma, ma_tam);
        cout << ". Ten Sach : "; cin.getline(lst_book[i].b_tensach, 50);
        cout << ". Tac Gia  : "; cin.getline(lst_book[i].b_tacgia, 50);
        cout << ". The Loai : "; cin.getline(lst_book[i].b_theloai, 50);
        cout << ". Nha XB   : "; cin.getline(lst_book[i].b_nhaXB, 50);
        cout << ". So Luong : "; cin >> lst_book[i].b_soluong;
        
        total_books += lst_book[i].b_soluong;
        cin.ignore();
        cout << endl;
    }
    
    total_book_types += tong_sach_nhap;
    sach_save_file();
    file_info();
}
 
void sach_xoa() {
    char ma_tam[50];
    int i;
 
    cin.ignore(1);
    cout << "Nhap ma sach can xoa : "; cin.getline(ma_tam, 50);
    
    i = sach_tim(ma_tam);
 
    if (i == -1)
        cout << "- Khong tim thay sach co ma so tren. ";
    else {
        total_books -= lst_book[i].b_soluong;

        for (int j = i; j < total_book_types; j++)
            lst_book[j] = lst_book[j+1];
 
        total_book_types -= 1;
        cout << "- Da xoa.";
    }

    sach_save_file();
    file_info();
}
 
void sach_xuat() {
    cout << "\n                      DANH SACH SACH TRONG THU VIEN           \n \n";
    cout << setw(13) << ".Ma Sach" << setw(13) << "Ten Sach" << setw(13) << "The Loai" << setw(13) << "So Luong" << endl << endl;
    for(int i = 0; i < total_book_types; i++) {
        cout << setw(13) << lst_book[i].b_ma 
             << setw(13) << lst_book[i].b_tensach 
             << setw(13) << lst_book[i].b_theloai 
             << setw(13) << lst_book[i].b_soluong;
        cout << endl;
    }
    cout <<"   -------------------------------------------------\n";
    cout << setw(10) <<"Types= "<< setw(3) <<total_book_types << setw(36) <<"Total= "<< setw(3) << total_books <<endl;
}
 

 
void sach_hieu_chinh() {
    char ma_tam[50];
    int i;
 
    cin.ignore();
    cout << "Nhap ma sach can hieu chinh : "; cin.getline(ma_tam, 50);
       
    i = sach_tim(ma_tam);
 
    if (i == -1)
        cout << "- Khong tim thay sach co ma so tren. ";
    else {
        //cin.ignore();
        total_books -= lst_book[i].b_soluong;   // Xoa so luong sach cu
        
        char temp[50];
        while(true) {
            cout << ". Ma Sach  : "; cin.getline(temp, 50);
            if(strcmp(temp, lst_book[i].b_ma) && sach_tim(temp) != -1) cout <<" Ma sach da ton tai. Hay nhap ma khac!\n";
            else break;
        }
        strcpy(lst_book[i].b_ma,temp);
        cout << ". Ten Sach : "; cin.getline(lst_book[i].b_tensach, 50);
        cout << ". Tac Gia  : "; cin.getline(lst_book[i].b_tacgia, 50);
        cout << ". The Loai : "; cin.getline(lst_book[i].b_theloai, 50);
        cout << ". Nha XB   : "; cin.getline(lst_book[i].b_nhaXB, 50);
        cout << ". So Luong : "; cin >> lst_book[i].b_soluong;
        cout << endl;

        total_books += lst_book[i].b_soluong;   // Update so luong sach moi
    }

    cout <<"- Hieu chinh thanh cong!\n";
    sach_save_file();

}
 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DINH NGHIA HAM CHO DOI TUONG PHIEU.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 
void phieu_load_file() {
    FILE *f_b;
    f_b = fopen("bill_file","rb");
    fread(lst_bill, sizeof(lst_bill), 1, f_b);
    fclose(f_b);
}
 
void phieu_save_file() {
    FILE * f_b;
    f_b = fopen("bill_file", "wb");
    fwrite(lst_bill, sizeof(lst_bill), 1, f_b);
    fclose(f_b);
}
 
int phieu_tim(char ma_tam[]) {
    for(int jump = 0; jump < total_bills; ++jump){
        if(!strcmp(lst_bill[jump].bill_maSV, ma_tam)){
            return jump;
        }
    }
    return -1;
 
}
 
void phieu_nhap() {
    int so_phieu_muon = 0;
    char ma_phieu[50];
    do {
        cout << ". Nhap so luong phieu muon se dang ki : "; cin >> so_phieu_muon;
        if(so_phieu_muon < 0) cout <<"Vui long nhap so phieu hop le\n";
        cout << endl;
    } while(so_phieu_muon < 0);

    for(int i = total_bills; i < so_phieu_muon + total_bills; ++i){
        while(true){
            cin.ignore(1);
            cout <<". Nhap Ma Phieu(mssv): "; cin.getline(ma_phieu, 50);
            if(phieu_tim(ma_phieu) != -1) cout <<"Ma phieu da ton tai. Hay nhap lai!\n";
            else break;
        }

        strcpy(lst_bill[i].bill_maSV, ma_phieu);
        cout << ". Ten Sinh Vien: "; cin.getline(lst_bill[i].bill_tenSV, 50);
        cout << ". Ngay muon: \n";
        cout <<"    Ngay: ";    cin >> lst_bill[i].bill_ngaymuon.n_day;
        cout <<"    Thang: ";   cin >> lst_bill[i].bill_ngaymuon.n_month;
        cout <<"    Nam: ";     cin >> lst_bill[i].bill_ngaymuon.n_year;

        //____________Xu li sach muon___________
        int index_sach_muon;
        char ma_sach_muon[50];

        while(true){
            cin.ignore(1);
            cout << ". Nhap ma Sach can muon: "; cin.getline(ma_sach_muon, 50);
            index_sach_muon = sach_tim(ma_sach_muon);
            if(index_sach_muon == -1) cout <<"Ma sach khong ton tai. Vui long nhap lai!\n";
            else if(lst_book[index_sach_muon].b_soluong == 0) cout <<"So luong sach khong du. Vui long chon lai\n";
            else break;
        }

        lst_bill[i].bill_sach_muon = lst_book[index_sach_muon];
        lst_bill[i].bill_sach_muon.b_soluong = 1;               //So luong sach muon mac dinh = 1

        --lst_book[index_sach_muon].b_soluong;
        cout <<"- Muon sach thanh cong!\n";
    }

    total_bills += so_phieu_muon;
    total_books -= so_phieu_muon;

    phieu_save_file();
    sach_save_file();
    file_info();
}
 

 
void phieu_xoa() {
    char ma_phieu_tra[50];
    int index_phieu_tra;
    while(true){
        cin.ignore(1);
        cout << ". Nhap ma Phieu(mssv): "; cin.getline(ma_phieu_tra, 50);
        index_phieu_tra = phieu_tim(ma_phieu_tra);
        if(index_phieu_tra == -1) cout <<"Ma phieu khong ton tai. Hay nhap lai!\n";
        else break;
    }

    int index_sach_tra = sach_tim(lst_bill[index_phieu_tra].bill_sach_muon.b_ma);

    if(index_sach_tra == -1){               // Sach bi xoa trong luc muon
        lst_book[total_book_types] = lst_bill[index_phieu_tra].bill_sach_muon;
        ++total_book_types;
    } else {
        ++lst_book[index_sach_tra].b_soluong;
    }

    for(int j = index_phieu_tra; j < total_bills; ++j){
        lst_bill[j] = lst_bill[j+1];
    }

    cout <<"- Xoa thanh cong!\n";

    --total_bills;
    ++total_books;

    phieu_save_file();
    sach_save_file();
    file_info();
}
 
void phieu_xuat() {
    cout << "\n                      DANH SACH PHIEU MUON           \n \n";
    cout << setw(16) << ".Ma Phieu/ Ma SV" 
         << setw(15) << "Ten SV"
         << setw(15) << "Ma sach"
         << setw(15) << "Ngay muon"
         << endl << endl;
    for(int i = 0; i < total_bills; i++) {
        cout << setw(16) << lst_bill[i].bill_maSV
             << setw(15) << lst_bill[i].bill_tenSV
             << setw(15) << lst_bill[i].bill_sach_muon.b_ma
             << setw(15) << to_string(lst_bill[i].bill_ngaymuon.n_day)
                         + "/" + to_string(lst_bill[i].bill_ngaymuon.n_month)
                         + "/" + to_string(lst_bill[i].bill_ngaymuon.n_year);
        cout << endl;
    }
    cout << "----------------\n";
    cout << setw(12)<<"Total= " <<setw(3) << total_bills <<endl;
}

 
void phieu_hieu_chinh() {
    char ma_tam[50];
    int i;

    cin.ignore();
    cout << "Nhap ma phieu can hieu chinh : "; cin.getline(ma_tam, 50);
       
    i = phieu_tim(ma_tam);
 
    if (i == -1)
        cout << "- Khong tim thay phieu co ma so tren. ";
    else {
        //cin.ignore();
        cout << ". Ma phieu/Ma SV: "; cin.getline(lst_bill[i].bill_maSV, 50);
        cout << ". Ten Sinh Vien : "; cin.getline(lst_bill[i].bill_tenSV, 50);
        cout << endl;
    }
    cout <<"- Hieu chinh thanh cong!\n";

    phieu_save_file();
}
 


 




