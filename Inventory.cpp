//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Inventory.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TInventoryForm *InventoryForm;
//---------------------------------------------------------------------------
__fastcall TInventoryForm::TInventoryForm(TComponent* Owner)
   : TForm(Owner)
{
   NewItem = true;
}
//---------------------------------------------------------------------------
void __fastcall TInventoryForm::FormShow(TObject *Sender)
{
   if (NewItem)
   {
      Name->Text = "Название";
      HasWeight->Checked = true;
      Hasatstart->Checked = false;
      Estimated->Checked = false;
      Kolvo->Visible = false;
      Kolvo->Value = 0;
      Descript->Text = "";
   }
   else
   {
      NewItem = true;
   }
   KilvoAdd = false;
   Name->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TInventoryForm::EstimatedClick(TObject *Sender)
{
   Kolvo->Visible = Estimated->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TInventoryForm::KolvoChange(TObject *Sender)
{
   if (KilvoAdd)
   {
      if (Kolvo->Value > 0)
         Descript->Text = "Крутите колесо мышки чтобы менять количество.";
      KilvoAdd = false;
   }
}
//---------------------------------------------------------------------------
