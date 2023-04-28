#include "Header.h"
int main() {
	int ok, dinh;
	DANHSACHKE dsk;
	DANHSACHCANH dsc= layDSC(dsk);
	do {
		system("cls");
		cout << "\n===================================";
		cout << "\n0.Ket thuc";
		cout << "\n1.Doc file do thi co trong so";
		cout << "\n2.Doc file do thi khong trong so";
		cout << "\n3.Ghi file";
		cout << "\n4.Tinh so bac vao cua dinh";
		cout << "\n5.Lay tap canh cua do thi";
		cout << "\n6.Tinh so bac ra cua dinh";
		cout << "\n7.Tinh so bac cua do thi vo huong";
		cout << "\n8.Xuat do thi khong trong so Tu Tap Canh ";
		cout << "\n9.Xuat do thi tu dinh va tap canh";
		cout << "\n10.Xuat danh sach canh cua do thi";
		cout << "\n11.Dinh ke co trong so nho nhat ";
		cout << "\n12.Dao nguoc do thi ";
		cout << "\nMoi ban chon: ";
		cin >> ok;
		cin.ignore();
		switch (ok) {
		case 1:
			docFile("dothi2.txt", dsk, 1);
			xuatDSK(dsk);
			dsc = layDSC(dsk);
			break;
		case 2:
			docFile("dothi1.txt", dsk);
			xuatDSK(dsk);
			break;
		case 3:
			cout << "\nGhi file";
			ghiFile("dothi3.txt", dsk, 1);
			xuatDSK(dsk);
			break;
		case 4:
			cout << "\nNhap dinh can tinh bac vao:";
			cin >> dinh;
			cout << "\nSo bac vao cua dinh " << dinh << " la: " << tinhSoBacVao(dsk, dinh);
			break;
		case 5:
			dsc = layDSC(dsk);
			if (dsc.n == 0)
				cout << "\nDo thi ko co canh nao.";
			else {
				cout << "\nTap canh cua do thi: ";
				for (int i = 0; i < dsc.n; i++) {
					cout << endl;
					xuatCanh(dsc.ds[i]);
				}
			}
			cout << endl;
			break;
		case 6:
			cout << "\nNhap dinh can tinh bac ra:";
			cin >> dinh;
			cout << "\nSo bac ra cua dinh " << dinh << " la: " << tinhSoBacRa(dsk, dinh);
			break;
		case 7:
			cout << "\nNhap dinh can tinh bac cua do thi vo huong:";
			cin >> dinh;
			cout << "\nSo bac cua dinh " << dinh << " la " << tinhSoBacVoHuong(dsk, dinh);
			break;
		case 8:
			dsc = TapCanhDoThiKhongTrongSo(dsk);
			if (dsc.n == 0)
				cout << "\nDo thi ko co canh nao.";
			else {
				cout << "\nTap canh cua do thi: ";
				for (int i = 0; i < dsc.n; i++) {
					cout << endl;
					xuatCanhKhongTrongSo(dsc.ds[i]);
				}
			}
			break;
		case 9:
			cout << "\nDo Thi :\n";
			/*xuatDanhSachKeTuDinhVaTapCanh(dsk.n, dsc);*/
			xuatDanhSachKeTuDinhVaTapCanh1(DanhSachKeTuDinhVaTapCanh(dsk.n, dsc));
			break;
		case 10:
			cout << "\nDanh sach Canh cua do thi : \n";
			xuatDanhSachCanh(dsc);
			break;
		case 11:
			cout << "\nNhap Dinh: ";
			cin >> dinh;
			cout << "\nDinh ke voi dinh " << dinh << " co trong so nho nhat la : " << dinhKeNhoNhat(dsk, dinh);
			break;							
		case 12:
			cout << "\nDo Thi :\n";
			xuatDanhSachKeTuDinhVaTapCanh1(daoNguocDoThi(DanhSachKeTuDinhVaTapCanh(dsk.n, dsc)));
			break;
		}
		cout << endl;
		system("pause");
	} while (ok != 0);
	huyDSK(dsk);
	return 0;
}