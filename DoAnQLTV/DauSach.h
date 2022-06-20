#pragma once
#include "Define.h"
#include "mylib.h"
#include "BienToanCuc.h"
#include "KiemTra_Nhap.h"
#include "NgayThang.h"
#include "GiaoDien.h"



//............................. DANH MUC SACH(DSLK DON)................................
struct DanhMucSach
{
	string maSach;
	uint ttSach;
	string viTri;
};
typedef struct DanhMucSach DMS;

struct NodeDMS
{
	DMS data;
	struct NodeDMS* pNext;
};
typedef struct NodeDMS NODE_DMS;

struct ListDMS
{
	int n = -1;
	NODE_DMS* pHead, * pTail;
};
typedef struct ListDMS LIST_DMS;



//.................... DAU SACH( DSTT - mang con tro)............................
struct dausach
{
	string tensach;
	string ISBN;
	string tacgia;
	string theloai;
	uint sotrang;
	uint namSB;

};
typedef struct dausach dauSach;

struct DauSach
{
	dauSach info;//thong tin mot dau sach
	LIST_DMS dms;
};
typedef struct DauSach DAU_SACH;
typedef struct DauSach* pDAU_SACH;

struct ListDauSach
{
	// n + 1 = so phan tu , n = chi so index.
	int n = -1;
	// mang con tro dung cap phat dong, vung nho heap
	//pDAU_SACH *ListDS = new pDAU_SACH[MAX_DAUSACH];

	// vi so luong dau sach chi co 100 nen dung mang cap phat tinh luon, vung nho stack.
	pDAU_SACH ListDS[MAX_DAUSACH];
};
typedef struct ListDauSach LIST_DAUSACH;
// typedef struct ListDauSach* pLIST_DAUSACH;

struct  TopSach
{
	string tensach;
	int sosachmuon;
};


//....................HAM XU LY DAU SACH...........................
// Phep toan Empty
int Empty_DauSach(LIST_DAUSACH  l);

//Phep toan Full: 
int Full_DauSach(LIST_DAUSACH  l);

//ham loai bo khoang trang
string getString(string a);

// Them mot phan tu vao trong danh sach
int Insert_DauSach(LIST_DAUSACH& l, pDAU_SACH& pDS);

//Xoa mot phan tu 
void Delete_DauSach(LIST_DAUSACH& l, int pos);

//Tim Kiem phan tu theo ma ISBN
bool SearchISBN_DS(LIST_DAUSACH lDS, string ISBN);

//Tim Kiem thong tin dau sach the ten dau sach, co tra ve con tro chi nut tim thay, khong tra vê NULL
pDAU_SACH SearchTen_DS(LIST_DAUSACH lDS, string tensach);

//Ham Swap dau sach
void swap_DS(pDAU_SACH ds1, pDAU_SACH ds2);

//Ham Sap Xep dau sach - toi da 100 phan tu nen su dung selection sort
void selectionSort_DS(LIST_DAUSACH& lDS);


// ............... ham ho tro cap nhat dau sach...................................
//cap nhat dau sach
void Update_DauSach(LIST_DAUSACH& lDS, pDAU_SACH& pDS, bool isEdited = false);

int ChooseItems_DS(LIST_DAUSACH& lDS, int& tttrang, int tongtrang);

void Xoa_OutDS_1line(int locate);

void Xoa_OutDS_29lines();

//xuat dau sach
void Output_DS(dauSach ds);

//danh sach dau sach tren 1 trang
void OutputDS_PerPage(LIST_DAUSACH& lDS, int index);

//danh sach dau sach theo thu tu
void Output_ListDStheoTT(LIST_DAUSACH lDS);

//QUAN LY MENU DAU SACH
void Menu_DauSach(LIST_DAUSACH& lDS);




// ......................HAM XU LY DANH MUC SACH ..........................................
// ..... khoi tao........
void initList_DMS(LIST_DMS& l);

// kiem tra rong
bool ListDMSIsEmpty(LIST_DMS l);

// get node
NODE_DMS* GetNode_DMS(DMS DATA);

void AddTailList_DMS(LIST_DMS& l, DMS data);

// xac dinh vi tri cua nut co gia tri ma sach bang keySearch trong danh sach lien ket
int position(NODE_DMS* First, string keySearch);

// xac dinh con tro cua nut thu i trong danh sach lien ket
NODE_DMS* nodepointer(NODE_DMS* First, int i);

// Phep toan Delete_first: xoa nut o dau danh sach lien ket
void Delete_first(NODE_DMS*& First);

// xoa nut sau nut p
void Delete_after(NODE_DMS* p);

// xoa 1 node bat ky trong danh sach lien ket.
int Delete_batky(pDAU_SACH& pDS, string keySearch);

// ham kiem tra sach co ai muon hay chua, co thi tra ve true, ko thì false.
bool Check_DMS(NODE_DMS* nDMS);

// tim kiem theo pp tim kiem tuyen tinh, ko thay tra ve NULL, neu thay tra ve con co chi nut tim thay
NODE_DMS* Search_DMS1(pDAU_SACH pDS, string masach);

NODE_DMS* Search_DMS2(NODE_DMS* dms, int pos);

int NhapSach(pDAU_SACH& pDS);

int SuaDanhMucSach(pDAU_SACH& pDS, NODE_DMS* dms);

void Xoa_OutDMS_1line(int locate);

void Xoa_OutDMS_29lines();

int ChooseItems(LIST_DAUSACH& lDS, int& tttrang, int tongtrang);

int ChooseItems1(pDAU_SACH& pDS, int& tttrang, int tongtrang);

void Output_DMS(DMS dms);

void OutputDMS_PerPage(pDAU_SACH pDS, int index);

void Output_ListDMS(pDAU_SACH& pDS);

void NhapDanhMucSach(pDAU_SACH& pDS, int sosach);


//..................quan ly menu danh muc sach...................
void Menu_DMS(LIST_DAUSACH& lDS);

// tong so sach duoc muon cua mot dau sach.
int TongSoSachDuocMuon(LIST_DMS dms);

// xu ly thao tac in ra 10 sach co luoc muon nhieu nhat.(quick sort)
void Sort_Top10(TopSach* top10, int q, int r);

void Top10Sach(LIST_DAUSACH lDS);