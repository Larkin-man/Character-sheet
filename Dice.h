//---------------------------------------------------------------------------

#ifndef DiceH
#define DiceH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <Graphics.hpp>
#include <ImgList.hpp>

//---------------------------------------------------------------------------
class TFormDice : public TForm
{
__published:	// IDE-managed Components
   TButton *SingleDice;
   TButton *TwoDice;
   TLabel *Label1;
   TLabel *res;
   TPopupMenu *PopupMenu1;
   TMenuItem *N6;
   TMenuItem *N10;
   TMenuItem *N20;
   TMenuItem *N100;
   void __fastcall N6Click(TObject *Sender);
   void __fastcall N10Click(TObject *Sender);
   void __fastcall N20Click(TObject *Sender);
   void __fastcall N100Click(TObject *Sender);
   void __fastcall SingleDiceClick(TObject *Sender);
   void __fastcall TwoDiceClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
   __fastcall TFormDice(TComponent* Owner);
   int sides;
   int prev;
   void Deselect()
   {
      N6->Checked = false;
      N10->Checked = false;
      N20->Checked = false;
      N100->Checked = false;
   }            
};
//---------------------------------------------------------------------------
extern PACKAGE TFormDice *FormDice;
//---------------------------------------------------------------------------
#endif
