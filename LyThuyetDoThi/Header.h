#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
const int MAXDSK = 15; //so dinh toi da
const int MAXDSC = MAXDSK * MAXDSK; // so canh toi da
struct NODE {
	int dinhke;
	int trongso = 0;
	NODE* link;
};
struct DANHSACHKE {
	NODE* dsk[MAXDSK];
	int n = 0;//so dinh cua do thi
};
struct CANH {
	int dau;
	int cuoi;
	int trongso = 0;
};
struct DANHSACHCANH {
	CANH ds[MAXDSC];
	int n = 0;//so canh cua do thi
};
//Ham tao danh sach ke tu file
// flag = 0:do thi khong trong so; 1:do thi co trong so
int docFile(const char*, DANHSACHKE&, int flag = 0);
//Ham ghi danh sach ke ra file
int ghiFile(const char*, DANHSACHKE&, int flag = 0);
//Ham xuat danh sach ke
void xuatDSK(DANHSACHKE);
//Ham huy danh sach ke
void huyDSK(DANHSACHKE&);
//Ham dem so dinh ke cua mot node
int demNode(NODE*);
//Ham lay tap canh cua do thi
DANHSACHCANH layDSC(DANHSACHKE);
//Ham xuat canh theo dinh dang: (dau, cuoi, trong so)
void xuatCanh(CANH);
//Ham tinh so bac vao cua mot dinh
int tinhSoBacVao(DANHSACHKE, int);
/*
 Biên dịch và thực thi chương trình trên.
 Viết hàm tính bậc ra của một đỉnh trong đồ thị có hướng
 Viết hàm tính bậc của một đỉnh trong đồ thị vô hướng
 Cho danh sách kề đồ thị không trọng số. Viết hàm trả về tập cạnh của đồ thị
*/
int tinhSoBacRa(DANHSACHKE, int);
int tinhSoBacVoHuong(DANHSACHKE, int);
DANHSACHCANH TapCanhDoThiKhongTrongSo(DANHSACHKE);
void xuatCanhKhongTrongSo(CANH);

/*
3/ Bài tập tổng hợp:
1) Cho số đỉnh và tập cạnh của đồ thị vô hướng. Viết hàm trả về danh sách kề của đồ thị.
2) Cho số đỉnh và tập cạnh của đồ thị có hướng. Viết hàm trả về danh sách kề của đồ thị.

*/
void xuatDanhSachCanh(DANHSACHCANH);
DANHSACHKE DanhSachKeTuDinhVaTapCanh(int soDinh, DANHSACHCANH c);
void xuatDanhSachKeTuDinhVaTapCanh1(DANHSACHKE);
/*
3) Cho đồ thị trọng số biểu diễn bằng danh sách kề. Viết hàm tìm một đỉnh kề với đỉnh u mà
có trọng số nhỏ nhất.

*/
int dinhKeNhoNhat(DANHSACHKE ,int);
/*
4) Đồ thị có hướng G’ được xây dựng từ đồ thị có hướng G bằng cách đổi hướng tất cả các
cạnh của đồ thị G. Cho danh sách kề của đồ thị G, viết hàm trả về danh sách kề của đồ thị
G’.
5) Cho danh sách kề của đồ thị. Viết hàm duyệt đồ thị theo chiều rộng (BFS) với đỉnh xuất
phát v và xuất ra màn hình thứ tự các đỉnh duyệt được.
*/
DANHSACHKE daoNguocDoThi(DANHSACHKE);

void duyet_bfs(DANHSACHKE dsk,int dinh);
bool duyetCanhTrung(int x, visited ds);
