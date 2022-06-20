#pragma once
#include "NgayThang.h"
#include "DauSach.h"

//..........................MUON TRA ( DSLK KEP )...........................
struct MuonTra
{
	string MASACH;
	NGAY_THANG ngaymuon;
	NGAY_THANG ngaytra;
	uint trangthai = 0;

	// them vao... khong co trong yeu cau
	string tensach;
	string vitrisach;

};
typedef struct MuonTra MUON_TRA;

struct NodeMuonTra
{
	MUON_TRA data;
	struct NodeMuonTra* pNext;
	struct NodeMuonTra* pPre;
};
typedef struct NodeMuonTra NODE_MT;

struct ListMT
{
	int n;//so phan tu
	NODE_MT* pHead;
	NODE_MT* pTail;

};
typedef struct ListMT LIST_MT;

// ..... khoi tao........
void initList_MT(LIST_MT& l);

// kiem tra rong
bool ListMTIsEmpty(LIST_MT l);

// get node
NODE_MT* GetNode_MT(MUON_TRA DATA);

void AddHeadList_MT(LIST_MT& l, MUON_TRA data);

void AddTailList_MT(LIST_MT& l, MUON_TRA data);

// thieu cai them sau nua	
//xoa dau danh sach
void DelHeadList_MT(LIST_MT& l, MUON_TRA data);

void DelTailList_MT(LIST_MT& l, MUON_TRA data);

void ClearAll_ListMT(LIST_MT& l);

bool SearchTenSach_MT(LIST_MT lMT, string tensach);

int SoSachDangMuon(LIST_MT lMT);

// ham kiem tra doc gia co lam mat sach hay khong? .Co thi tra lai 1, khong thi tra lai 0.
int MatSach(LIST_MT lMT);

int SoNgayMuon_Max(LIST_MT lMT);

int SoNgayQuaHan(LIST_MT lMT);

void Output_MT(NODE_MT* p, int i);

void XoaDisplay_MT(int i);

void OutputList_MT(LIST_MT lMT);

void EffectiveMenu_MT(LIST_MT lMT, int pos, int flag);

int chonItem_MT(LIST_MT lMT);