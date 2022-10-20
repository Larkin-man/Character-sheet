//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvSpin.hpp"
#include <Grids.hpp>
#include <Mask.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include "Dice.h"
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
   TPageControl *PageControl1;
   TTabSheet *TabSheet1;
   TGroupBox *GroupBox1;
   TAdvSpinEdit *you1;
   TAdvSpinEdit *you2;
   TBitBtn *BitBtn1;
   TButton *Button1;
   TGroupBox *GroupBox2;
   TAdvSpinEdit *e1;
   TAdvSpinEdit *e2;
   TMemo *Memo1;
   TTabSheet *TabSheet2;
   TGroupBox *GroupBox3;
   TAdvSpinEdit *youz;
   TAdvSpinEdit *hiez;
   TButton *Button2;
   TMemo *Memo2;
   TGroupBox *GroupBox4;
   TAdvSpinEdit *zrank;
   TAdvSpinEdit *zbattle;
   TAdvSpinEdit *zdosp;
   TLabeledEdit *Def;
   TGroupBox *GroupBox5;
   TAdvSpinEdit *zebattle;
   TAdvSpinEdit *zedef;
   TAdvSpinEdit *zehp;
   TMemo *Memo3;
   TButton *Button4;
   TAdvSpinEdit *zhp;
   TStringGrid *fight;
   TTabSheet *TabSheet3;
   TLabeledEdit *LabeledEdit1;
   TButton *Button6;
   TRadioGroup *RadioPar1;
   TEdit *Par1;
   TAdvSpinEdit *Luck;
   TRadioGroup *RadioPar2;
   TEdit *Par2;
   TButton *Button3;
     TGroupBox *GroupBox6;
     TStaticText *q1;
     TBitBtn *BitBtn2;
     TStaticText *q2;
     TStaticText *q3;
     TStaticText *q4;
     TStaticText *q5;
     TStaticText *q6;
   TPanel *Panel1;
   TStringGrid *out;
   TStaticText *StaticText1;
     TTabSheet *TabSheet4;
     TGroupBox *GroupBox7;
     TAdvSpinEdit *ggl;
     TAdvSpinEdit *gghp;
     TStaticText *StaticText2;
     TPopupMenu *Shpaga;
     TMenuItem *N1;
     TGroupBox *GroupBox8;
     TAdvSpinEdit *AdvSpinEdit3;
   TAdvSpinEdit *shhp;
     TMemo *Memo4;
     TBitBtn *BitBtn3;
   TLabel *Label1;
   TAdvSpinEdit *nal;
   TComboBox *MoneyType;
   TButton *Button5;
   TButton *Button7;
   TAdvSpinEdit *ammo;
   TButton *Button8;
   TAdvSpinEdit *day;
   TAdvSpinEdit *honor;
   TAdvSpinEdit *food;
   void __fastcall BitBtn1Click(TObject *Sender);
   void __fastcall Button1Click(TObject *Sender);
   void __fastcall Button2Click(TObject *Sender);
   void __fastcall zrankChange(TObject *Sender);
   void __fastcall Button4Click(TObject *Sender);
   void __fastcall RadioPar1Click(TObject *Sender);
   void __fastcall Par1Change(TObject *Sender);
   void __fastcall RadioPar2Click(TObject *Sender);
   void __fastcall Par2Change(TObject *Sender);
   void __fastcall Button3Click(TObject *Sender);
     void __fastcall quadratClick(TObject *Sender);
   void __fastcall BitBtn2Click(TObject *Sender);
     void __fastcall N1Click(TObject *Sender);
     void __fastcall BitBtn3Click(TObject *Sender);
   void __fastcall Button5Click(TObject *Sender);
   void __fastcall Button7Click(TObject *Sender);
   void __fastcall Button8Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
   __fastcall TForm1(TComponent* Owner);
   int def;
   int clear;
   TStaticText *quad[6];
   int Feku, Fsu;
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
      else if(Fsu > 30)
      {
         Feku++;
         Fsu -= 30;
      }
      Label1->Caption = "Δενόγθ: "+IntToStr(Feku)+" έκώ, " +IntToStr(Fsu)+" Ρσ.";
   }
   __property int Eku = {read = Feku, write=SetEku, default = 15};
   __property int Su = {read = Fsu, write=SetSu, default = 0};

};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
