#include<iostream>
#include<string>
using namespace std;
class Person
{
private:
	string name;
	int year;
public:
	// phuong thuc ao
	virtual void input()
	{
		cout << "Nhap name: ";
		getline(cin, this->name);
		cout << "Nhap nam sinh: ";
		cin >> this->year;
	}
	// phuong thuc ao
	virtual void output()
	{
		cout << "Name: " << this->name << " , Nam Sinh: " << this->year;
	}
	//phuong thuc thuan ao
	virtual float TinhTien() = 0;
	// goi tra ve nam sinh
	int getYear()
	{
		return year;
	}
	// dong goi tra ve ten
	string getName()
	{
		return name;
	}
};
class BenhNhanNgoaiTru : public Person//ke thua
{
private:
	string TenBenh;
	float TienDieuTri;
public:
	void input()
	{
		cout << "\nBNNT" << endl;
		cin.ignore();
		Person::input();
		cin.ignore();
		cout << "Nhap Ten Benh: ";
		cin >> this->TenBenh;
		cin.ignore();
		cout << "Nhap Tien Dieu Tri: ";
		cin >> this->TienDieuTri;
	}
	void output()
	{
		Person::output();
		cout << " , Ten Benh: " << this->TenBenh << " , Tien Dieu Tri: " << this->TienDieuTri;
	}
	float TinhTien()
	{
		if (getYear() <= 1960)
		{
			return this->TienDieuTri - 0.08 * this->TienDieuTri;
		}
		else
		{
			return this->TienDieuTri;
		}
	}
};
class BenhNhanNoiTru : public Person
{
private:
	string TenBenhBanDau;
	float TienThuoc;
	float TienO;
public:
	void input()
	{
		cout << "\nBNNT" << endl;
		cin.ignore();
		Person::input();
		cin.ignore();
		cout << "Nhap Ten Benh: ";
		cin >> this->TenBenhBanDau;
		cin.ignore();
		cout << "Nhap Tien Thuoc: ";
		cin >> this->TienThuoc;
		cout << "Nhap Tien O: ";
		cin >> this->TienO;
	}
	void output()
	{
		Person::output();
		cout << " , Ten Benh Ban Dau: " << this->TenBenhBanDau << " , Tien Thuoc: " << this->TienThuoc << " , Tien O: " << this->TienO;
	}
	float TinhTien()
	{
		float q = 0;
		float p = 0;
		if (getYear() <= 1960)
		{
			q = this->TienThuoc - 0.10 * this->TienThuoc + this->TienO - 0.12 * this->TienO;
			return q;
		}
		else
		{
			p = this->TienThuoc + this->TienO;
			return q;
		}
	}
};
class PhongKham {
private:
	int n;
	Person* list[100];
public:
	void nhap()
	{
		cout << "Nhap so luong benh nhan: ";
		cin >> this->n;
		for (int i = 0; i < n; i++)
		{
			int chon;
			cout << "1.BenhNhanNgoaiTru//2.BenhNhanNoiTru//3.Exit" << endl;
			cin >> chon;
			if (chon == 1)
			{
				system("cls");
				list[i] = new BenhNhanNgoaiTru;
			}
			else if (chon == 2)
			{
				system("cls");
				list[i] = new BenhNhanNoiTru;
			}
			else if (chon == 3)
			{
				break;
			}
			else
			{
				cout << "Error!!!";
			}
			//da hinh
			list[i]->input();
			cout << endl;
		}
	}
	void xuat()
	{
		int dem = 0;
		for (int i = 0; i < n; i++)
		{
			list[i]->output();
			dem++;
			cout << " , Benh nhan thu " << dem;
			cout << endl;
		}
	}
	void TongTien()
	{
		float sum = 0,dem = 0;
		// da hinh
		for (int i = 0; i < n; i++)
		{
			sum += list[i]->TinhTien();
			dem++;
		}
		cout << "\nTong tien kham cua "<< dem << " benh nhan la: " << sum << endl;
	}
	void sapsep()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1 ; j < n; j++)
			{
				if (list[i]->getName() > list[j]->getName())
				{
					swap(list[i], list[j]);
				}
			}
		}
	}
	void clear()
	{
		for(int i = 0 ; i < n ; i++)
		{
			delete list[i];
		}
	}
};
int main()
{
	PhongKham a;
	cout << "\t\tNHAP THONG TIN BENH NHAN\t\t" << endl;
	a.nhap();
	cout << "\n\t\tTHONG TIN BENH NHAN\t\t" << endl;
	a.xuat();
	cout << "\n\t\tTONG TIEN KHAM\t\t" << endl;
	a.TongTien();
	a.sapsep();
	cout << "\n\n\t\tSAP SEP THEO TEN\t\t" << endl;
	a.xuat();
	a.clear();
	system("pause");
	return 0;
}
