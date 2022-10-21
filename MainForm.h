//---------------------------------------------------------------------------

#ifndef MainFormH
#define MainFormH
//---------------------------------------------------------------------------
#include <Buttons.hpp>
#include <CheckLst.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <ExtActns.hpp>
#include <ExtCtrls.hpp>
#include <ExtDlgs.hpp>
#include <Graphics.hpp>
#include <Grids.hpp>
#include <Menus.hpp>
#include <StdActns.hpp>
#include <ToolWin.hpp>
#include <ValEdit.hpp>
#include <ActnList.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <ImgList.hpp>
#include <StdCtrls.hpp>
#include "Dice.h"
#include "NewItem.h"
//---------------------------------------------------------------------------
int const chkCustomList = 2;
int const mhFF = 0;
int const mhLuck = 1;
int const mhCharm = 2;
int const mhLuckSq = 3;
int const mhGR = 4;

int const SPINSSAVE = 20;
//int const HFF = 52;
//int const HPr = 64;
//int const ParTop[] = {136, 168, 200, 232, 264, 296, 328};
//int const ParLeft[] = {120, 296};

int const LPDef = 0;
int const LPFabled = 1;
int const LPShpaga = 2;
					  //  0 1  2   3   4   5    6
int const SumMR[] = {0,0, 100,300,600,1000,1500,2100,2600,3000,3300,3500,3600 };
double const ALLVAR = 36;

class TBaseForm : public TForm
{
__published:	// IDE-managed Components
	TImageList *ImageList1;
	TImageList *ImageList2;
	TPopupMenu *POPUP;
	TMenuItem *N1;
	TMenuItem *NNewtable;
	TMenuItem *NSetStore;
	TMenuItem *NGetStore;
	TActionList *ActionList1;
	TEditCut *EditCut1;
	TEditCopy *EditCopy1;
	TEditPaste *EditPaste1;
	TEditSelectAll *EditSelectAll1;
	TEditUndo *EditUndo1;
	TEditDelete *EditDelete1;
	TRichEditBold *RichEditBold1;
	TRichEditItalic *RichEditItalic1;
	TRichEditUnderline *RichEditUnderline1;
	TRichEditStrikeOut *RichEditStrikeOut1;
	TRichEditBullets *RichEditBullets1;
	TRichEditAlignLeft *RichEditAlignLeft1;
	TRichEditAlignRight *RichEditAlignRight1;
	TRichEditAlignCenter *RichEditAlignCenter1;
	TRichEditAlignCenter *RichEditAlignCenter2;
	TColorSelect *ColorSelect1;
	TFontEdit *FontEdit1;
	TFileOpen *FileOpen1;
	TFileSaveAs *FileSaveAs1;
	TPanel *PanelRight;
	TPageControl *PageControl2;
	TTabSheet *PInvent;
	TSpeedButton *DICEbtn;
	TStaticText *StaticText3;
	TCheckListBox *Inventory;
	TMemo *Descript;
	TPanel *PanelItemsBottom;
	TLabel *ItemsMet;
	TButton *NewItemBtn;
	TButton *RemoveItemsBtn;
	TTabSheet *PBook;
	TToolBar *ToolBar1;
	TToolButton *ToolButton6;
	TToolButton *ToolButton7;
	TToolButton *ToolButton8;
	TToolButton *ToolButton2;
	TToolButton *ToolButton3;
	TToolButton *ToolButton1;
	TToolButton *ToolButton4;
	TToolButton *ToolButton13;
	TToolButton *ToolButton15;
	TToolButton *ToolButton9;
	TToolButton *ToolButton5;
	TToolButton *ToolButton14;
	TToolButton *ToolButton11;
	TToolButton *ToolButton10;
	TToolButton *ToolButton12;
	TStaticText *StaticText4;
	TRichEdit *RichEdit1;
	TTabSheet *PBattle;
	TStaticText *StaticText1;
	TStringGrid *fight;
	TMemo *Memo1;
	TImageList *BtnsGR;
	TImageList *DisBtnsGR;
	TPopupMenu *PopupMenu1;
	TMenuItem *NEdit;
	TMenuItem *NPrintBook;
	TMenuItem *NClearPath;
	TMenuItem *NNoCheat;
	TMenuItem *NNewBegin;
	TOpenTextFileDialog *OpenTextFileDialog1;
	TFontDialog *FontDialog1;
	TPanel *PanelLEFT;
	TSplitter *Splitter2;
	TPanel *PanelGameReader;
	TToolBar *ToolBar2;
	TToolButton *OpenBtn;
	TToolButton *ToolButton16;
	TEdit *SelPar;
	TSpeedButton *GoBtn;
	TToolButton *ToolButton17;
	TToolButton *FontBtn;
	TToolButton *ToolButton18;
	TToolButton *BackBtn;
	TToolButton *ForwBtn;
	TToolButton *PrintStepsBtn;
	TToolButton *ToolButton19;
	TToolButton *MacrosBtn;
	TRichEdit *Out;
	TSplitter *Splitter3;
	TPageControl *PageControl1;
	TTabSheet *Options;
	TLabel *Label2;
	TLabel *Label12;
	TValueListEditor *Parameters;
	TCheckBox *BoxInv;
	TRadioGroup *LP;
	TCheckListBox *MH;
	TButton *AddParBtn;
	TPanel *Panel3;
	TImage *Image1;
	TTabSheet *List;
	TNotebook *Notebook1;
	TLabel *Label7;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label13;
	TLabel *Label14;
	TLabel *Label15;
	TPanel *PanelFF;
	TGroupBox *HeroParam;
	TGroupBox *GroupBoxEnemy;
	TLabel *Label5;
	TLabel *Label6;
	TButton *OneRoundBtn;
	TButton *BattleBtn1;
	TButton *CharmBtn;
	TButton *LuckBtn;
	TPanel *PanelHero2p;
	TLabel *Label3;
	TLabel *Label4;
	TGroupBox *LuckSq;
	TStaticText *q1;
	TStaticText *q2;
	TStaticText *q3;
	TStaticText *q4;
	TStaticText *q5;
	TStaticText *q6;
	TButton *LuckSQBtn;
	TLabel *Label8;
	TGroupBox *GroupBox3;
	TButton *ZProvBtn;
	TMemo *Memo2;
	TGroupBox *GroupBox4;
	TLabeledEdit *Def;
	TButton *FabledFight;
	TMemo *Memo3;
	TGroupBox *GroupBox5;
	TLabel *Label1;
	TStaticText *StaticText2;
	TGroupBox *GroupBoxGaskon;
	TButton *BattleBtnSh;
	TButton *ButtonShotGaskon;
	TMemo *Memo4;
	TComboBox *MoneyType;
	TButton *ButtonEkuP;
	TButton *ButtonEkuGive;
	TButton *ShpagaLuckBtn;
	TButtonedEdit *Luck;
	TImageList *ImagesSpin;
	TButtonedEdit *ammo;
	TButtonedEdit *Charizm;
	TButtonedEdit *you1;
	TButtonedEdit *you2;
	TButtonedEdit *gold;
	TButtonedEdit *food1;
	TButtonedEdit *e1;
	TButtonedEdit *e2;
	TButtonedEdit *Par1;
	TButtonedEdit *Par3;
	TButtonedEdit *Par2;
	TButtonedEdit *youz;
	TLabel *Label16;
	TButtonedEdit *ggl;
	TButtonedEdit *gghp;
	TLabel *Label17;
	TLabel *Label18;
	TGroupBox *GroupBoxGug;
	TLabel *Label19;
	TLabel *Label20;
	TButtonedEdit *sh1;
	TButtonedEdit *shhp;
	TButtonedEdit *honor;
	TButtonedEdit *day;
	TButtonedEdit *food;
	TButtonedEdit *nal;
	TLabel *Label21;
	TLabel *Label22;
	TLabel *Label23;
	TLabel *Label24;
	TButtonedEdit *hiez;
	TLabel *Label25;
	TLabel *Label26;
	TLabel *Label27;
	TLabel *Label28;
	TLabel *Label29;
	TButtonedEdit *zrank;
	TButtonedEdit *zbattle;
	TButtonedEdit *zdosp;
	TButtonedEdit *zhp;
	TButtonedEdit *zebattle;
	TButtonedEdit *zedef;
	TButtonedEdit *zehp;
	TLabel *Label30;
	TLabel *Label31;
	TLabel *Label32;
	TButtonedEdit *shards;
	TLabel *Label33;
	TButtonedEdit *MaxInvent;
	void __fastcall LuckLeftButtonClick(TObject *Sender);
	void __fastcall LuckRightButtonClick(TObject *Sender);
	void __fastcall LuckMouseActivate(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y, int HitTest, TMouseActivate &MouseActivate);
	void __fastcall LuckMouseEnter(TObject *Sender);
	void __fastcall LuckKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall ZProvBtnClick(TObject *Sender);
	void __fastcall zrankChange(TObject *Sender);
	void __fastcall FabledFightClick(TObject *Sender);
	void __fastcall LuckBtnClick(TObject *Sender);
	void __fastcall q1Click(TObject *Sender);
	void __fastcall N1Click(TObject *Sender);
	void __fastcall NNewtableClick(TObject *Sender);
	void __fastcall NGetStoreClick(TObject *Sender);
	void __fastcall ButtonEkuPClick(TObject *Sender);
	void __fastcall ButtonEkuGiveClick(TObject *Sender);
	void __fastcall ButtonShotGaskonClick(TObject *Sender);
	void __fastcall CharmBtnClick(TObject *Sender);
	void __fastcall BattleBtn1Click(TObject *Sender);
	void __fastcall ParametersValidate(TObject *Sender, int ACol, int ARow, const UnicodeString KeyName,
          const UnicodeString KeyValue);
	void __fastcall BattleBtnShClick(TObject *Sender);
	void __fastcall NewItemBtnClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall RemoveItemsBtnClick(TObject *Sender);
	void __fastcall InventoryClick(TObject *Sender);
	void __fastcall MaxInventChange(TObject *Sender);
	void __fastcall InventoryClickCheck(TObject *Sender);
	void __fastcall DescriptChange(TObject *Sender);
	void __fastcall InventoryKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall ShpagaLuckBtnClick(TObject *Sender);
	void __fastcall InventoryDblClick(TObject *Sender);
	void __fastcall LuckSQBtnClick(TObject *Sender);
	void __fastcall PageControl1Changing(TObject *Sender, bool &AllowChange);
	void __fastcall MHClickCheck(TObject *Sender);
	void __fastcall AddParBtnClick(TObject *Sender);
	void __fastcall Image1Click(TObject *Sender);
	void __fastcall ToolButton2Click(TObject *Sender);
	void __fastcall ToolButton3Click(TObject *Sender);
	void __fastcall FontEdit1BeforeExecute(TObject *Sender);
	void __fastcall FontEdit1Accept(TObject *Sender);
	void __fastcall ColorSelect1Accept(TObject *Sender);
	void __fastcall FileOpen1Accept(TObject *Sender);
	void __fastcall FileSaveAs1BeforeExecute(TObject *Sender);
	void __fastcall FileSaveAs1Accept(TObject *Sender);
	void __fastcall OneRoundBtnClick(TObject *Sender);
	void __fastcall OpenBtnClick(TObject *Sender);
	void __fastcall OutClick(TObject *Sender);
	void __fastcall OutDblClick(TObject *Sender);
	void __fastcall NEditClick(TObject *Sender);
	void __fastcall NPrintBookClick(TObject *Sender);
	void __fastcall NClearPathClick(TObject *Sender);
	void __fastcall NNoCheatClick(TObject *Sender);
	void __fastcall NNewBeginClick(TObject *Sender);
	void __fastcall FontBtnClick(TObject *Sender);
	void __fastcall GoBtnClick(TObject *Sender);
	void __fastcall SelParMouseEnter(TObject *Sender);
	void __fastcall BackBtnClick(TObject *Sender);
	void __fastcall ForwBtnClick(TObject *Sender);
	void __fastcall PrintStepsBtnClick(TObject *Sender);
	void __fastcall MacrosBtnClick(TObject *Sender);
	void __fastcall SelParKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall NSetStoreClick(TObject *Sender);
	void __fastcall BoxInvClick(TObject *Sender);
	void __fastcall LPClick(TObject *Sender);



private:	// User declarations
	bool SpinClick;
	bool ActiveLeftSpin;
public:		// User declarations
	__fastcall TBaseForm(TComponent* Owner);
	void MinusClick(TCustomEdit* Sender)
	{
      int value = Sender->Text.ToInt();
		if (value <= 0)
		{
			Sender->Text = "0";
			return;
		}
		Sender->Text = value-1;
	}
	void PlusClick(TCustomEdit* Sender)
	{
		int value = Sender->Text.ToInt();
		if (value >= Sender->Tag)
		{
			Sender->Text = Sender->Tag;
			return;
		}
		Sender->Text = value+1;
	}
	struct Item
   {
		UnicodeString Name;
      bool HasWeight;
      bool HasAtStart;
      int Count;
		UnicodeString Description;
   };
   int InBackpack;
   int def;
   int clear;
   TStaticText *quad[6];
   int Feku, Fsu;
	int Store[SPINSSAVE + 2];
	int MacrosStore[SPINSSAVE + 2];
	bool Lucker[6];
	TButtonedEdit *Spins[SPINSSAVE];
	TLabel *Labels[SPINSSAVE];
   void SetEku(int eku)
   {
      Feku = eku;
      if (Feku < 0)
         Feku = 0;
      Label1->Caption = "������: "+IntToStr(Feku)+" ���, " +IntToStr(Fsu)+" ��.";
   }
   void SetSu(int su)
   {
      Fsu = su;
      if (Fsu < 0)
         if (Feku > 0)
         {
            Feku--;
            Fsu += 30;
         }
         else
         {
            Fsu = 0;
            Feku = 0;
         }
      else if(Fsu >= 30)
      {
         Feku++;
         Fsu -= 30;
      }
      Label1->Caption = "������: "+IntToStr(Feku)+" ���, " +IntToStr(Fsu)+" ��.";
   }
   __property int Eku = {read = Feku, write=SetEku, default = 15};
   __property int Su = {read = Fsu, write=SetSu, default = 0};
	UnicodeString MyFName;
	void SpinsRepos();
	TStringList *Book;
	std::vector<int> ParStartStr;
	int ParCount;
	bool IfParSel;
	bool IsCipher(wchar_t Symb) {	return ((Symb >= '0')&&(Symb <= '9'));	}
	std::vector<int> Path;
	unsigned int Step;
	unsigned int BackStep;
	void RefreshBookName(UnicodeString FileName);
	void DebugFunction(int d);
	bool MacrosWrite;
	void SetMacros();
	int CurrPar;
	struct MacrosData
	{
		int Par;
		int StoreIdx;
		int Mod;
		MacrosData(int par, int storeIdx, int mod)
		{
			Par = par;
			StoreIdx = storeIdx;
			Mod = mod;
      }
	};
	std::vector<MacrosData> MacrosPar;
	void RunMacros(int Par);
	int random(const int& min, const int& max)
{    //�� ��� �� ���� ������������
     //srand(time(NULL));   //������������ ����������. ���� ����� ������
     return (min + rand() % (max+1-min));
}
};
//---------------------------------------------------------------------------
extern PACKAGE TBaseForm *BaseForm;
//---------------------------------------------------------------------------
#endif
