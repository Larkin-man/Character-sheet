//---------------------------------------------------------------------------

#ifndef MainFormH
#define MainFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <Mask.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include "Dice.h"
#include <Menus.hpp>
#include <CheckLst.hpp>
#include <ValEdit.hpp>
#include "Inventory.h"
#include "CSPIN.h"
#include "About.h"
#include <ImgList.hpp>
#include <ToolWin.hpp>
#include <TabNotBk.hpp>
#include <Graphics.hpp>
#include <ActnList.hpp>
#include <ExtActns.hpp>
#include <StdActns.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
//---------------------------------------------------------------------------
int const mhFF = 0;
int const mhLuck = 1;
int const mhCharm = 2;
int const mhLuckSq = 3;
int const mhGR = 4;

int const SPINSSAVE = 20;
int const HFF = 52;
int const HPr = 64;
int const ParTop[] = {136, 168, 200, 232, 264, 296, 328};
int const ParLeft[] = {120, 296};

int const LPDef = 0;
int const LPFabled = 1;
int const LPShpaga = 2;
					  //  0 1  2   3   4   5    6
int const SumMR[] = {0,0, 100,300,600,1000,1500,2100,2600,3000,3300,3500,3600 };
double const ALLVAR = 36;


class TBaseForm : public TForm
{
__published:	// IDE-managed Components
   TPopupMenu *POPUP;
     TMenuItem *N1;
   TMenuItem *NSetStore;
   TMenuItem *NGetStore;
   TMenuItem *NNewtable;
   TSplitter *Splitter1;
	TPanel *PanelRight;
   TSplitter *Splitter2;
   TImageList *ImageList1;
   TPageControl *PageControl2;
   TTabSheet *PBattle;
   TTabSheet *PInvent;
   TStaticText *StaticText1;
	TStringGrid *fight;
   TStaticText *StaticText3;
   TCheckListBox *Inventory;
   TMemo *Descript;
   TTabSheet *PBook;
   TToolBar *ToolBar1;
   TToolButton *ToolButton1;
   TStaticText *StaticText4;
   TMemo *Memo1;
   TMenuItem *N2;
   TSpeedButton *DICEbtn;
   TRichEdit *RichEdit1;
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
   TImageList *ImageList2;
   TToolButton *ToolButton9;
   TToolButton *ToolButton10;
   TToolButton *ToolButton11;
   TToolButton *ToolButton12;
   TToolButton *ToolButton13;
   TToolButton *ToolButton14;
   TToolButton *ToolButton15;
   TToolButton *ToolButton2;
   TToolButton *ToolButton3;
   TToolButton *ToolButton4;
   TToolButton *ToolButton5;
   TFileOpen *FileOpen1;
   TFileSaveAs *FileSaveAs1;
	TToolButton *ToolButton6;
   TToolButton *ToolButton7;
   TToolButton *ToolButton8;
	TPanel *PanelLEFT;
	TPageControl *PageControl1;
	TTabSheet *Options;
	TLabel *Label2;
	TValueListEditor *Parameters;
	TCheckBox *BoxInv;
	TRadioGroup *LP;
	TCheckListBox *MH;
	TButton *AddParBtn;
	TTabSheet *List;
	TNotebook *Notebook1;
	TLabel *Label7;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TPanel *PanelFF;
	TGroupBox *HeroParam;
	TGroupBox *GroupBox2;
	TLabel *Label5;
	TLabel *Label6;
	TButton *OneRoundBtn;
	TButton *BattleBtn1;
	TButton *CharmBtn;
	TButton *LuckBtn;
	TPanel *Panel1;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label8;
	TGroupBox *GroupBox3;
	TButton *Button2;
	TMemo *Memo2;
	TGroupBox *GroupBox4;
	TLabeledEdit *Def;
	TButton *Button4;
	TMemo *Memo3;
	TGroupBox *GroupBox5;
	TLabel *Label1;
	TStaticText *StaticText2;
	TGroupBox *GroupBox7;
	TGroupBox *GroupBox8;
	TButton *BattleBtnSh;
	TButton *Button8;
	TMemo *Memo4;
	TComboBox *MoneyType;
	TButton *Button5;
	TButton *Button7;
	TButton *ShpagaLuckBtn;
	TPanel *PanelGameReader;
	TSplitter *Splitter3;
	TGroupBox *LuckSq;
	TStaticText *q1;
	TStaticText *q2;
	TStaticText *q3;
	TStaticText *q4;
	TStaticText *q5;
	TStaticText *q6;
	TButton *LuckSQBtn;
	TLabel *Label12;
	TLabel *Label13;
	TLabel *Label14;
	TLabel *Label15;
	TPanel *Panel3;
	TImage *Image1;
	TPanel *PanelItemsBottom;
	TLabel *ItemsMet;
	TButton *NewItemBtn;
	TButton *RemoveItemsBtn;
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
	TImageList *BtnsGR;
	TImageList *DisBtnsGR;
	TRichEdit *Out;
	TPopupMenu *PopupMenu1;
	TMenuItem *NEdit;
	TMenuItem *NPrintBook;
	TMenuItem *NClearPath;
	TMenuItem *NNoCheat;
	TOpenTextFileDialog *OpenTextFileDialog1;
	TFontDialog *FontDialog1;
	TToolButton *ToolButton19;
	TToolButton *MacrosBtn;
	TMenuItem *NNewBegin;
	TMenuItem *debug1;
   void __fastcall RadioPar2Click(TObject *Sender);
	void __fastcall Par2Change(TObject *Sender);
   void __fastcall Panel1Exit(TObject *Sender);
   void __fastcall N2Click(TObject *Sender);
	void __fastcall debug1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
   __fastcall TBaseForm(TComponent* Owner);
   struct Item
   {
      AnsiString Name;
      bool HasWeight;
      bool HasAtStart;
      int Count;
      AnsiString Description;
   };
   int InBackpack;
   int def;
   int clear;
   TStaticText *quad[6];
   int Feku, Fsu;
	int Store[SPINSSAVE + 2];
	int MacrosStore[SPINSSAVE + 2];
	bool Lucker[6];
	TCSpinEdit *Spins[SPINSSAVE];
	TLabel *Labels[SPINSSAVE];
   void SetEku(int eku)
   {
      Feku = eku;
      if (Feku < 0)
         Feku = 0;
      Label1->Caption = "Δενόγθ: "+IntToStr(Feku)+" έκώ, " +IntToStr(Fsu)+" Ρσ.";
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
      Label1->Caption = "Δενόγθ: "+IntToStr(Feku)+" έκώ, " +IntToStr(Fsu)+" Ρσ.";
   }
   __property int Eku = {read = Feku, write=SetEku, default = 15};
   __property int Su = {read = Fsu, write=SetSu, default = 0};
	AnsiString MyFName;
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

};
//---------------------------------------------------------------------------
extern PACKAGE TBaseForm *BaseForm;
//---------------------------------------------------------------------------
#endif
