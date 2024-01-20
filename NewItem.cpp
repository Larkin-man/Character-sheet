//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "NewItem.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TNewItemForm *NewItemForm;
//---------------------------------------------------------------------------
__fastcall TNewItemForm::TNewItemForm(TComponent* Owner)	: TForm(Owner)
{
	NewItem = true;
}
//---------------------------------------------------------------------------
void __fastcall TNewItemForm::FormShow(TObject *Sender)
{
	if (NewItem)
	{
		Name->Text = "Название";
		HasWeight->Checked = true;
		Hasatstart->Checked = false;
		Estimated->Checked = false;
		Kolvo->Visible = false;
		UpDown1->Visible = false;
		Kolvo->Text = 0;
		Descript->Text = "";
	}
	else
	{
		NewItem = true;
	}
	KilvoAdd = false;
	Name->SetFocus();
	Name->SelectAll();
}
//---------------------------------------------------------------------------

void __fastcall TNewItemForm::EstimatedClick(TObject *Sender)
{
	Kolvo->Visible = Estimated->Checked;
	UpDown1->Visible = Estimated->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TNewItemForm::UpDown1Changing(TObject *Sender, bool &AllowChange)
{
	if (KilvoAdd)
	{
		if (Kolvo->Text.ToInt() > 0)
			Descript->Text = "Крутите колесо мышки чтобы менять количество.";
		KilvoAdd = false;
	}
}
//---------------------------------------------------------------------------
