//---------------------------------------------------------------------------
#include <vector>
#include <vcl.h>
#pragma hdrstop

#include "MainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TBaseForm *BaseForm;
//---------------------------------------------------------------------------
__fastcall TBaseForm::TBaseForm(TComponent* Owner)
   : TForm(Owner)
{
   //Form2->Show();
   fight->Cells[0][0] = "Раунд";
   fight->Cells[1][0] = "Вы";
	fight->Cells[2][0] = "Враг";
   fight->Cells[3][0] = "Кто";
	zrankChange(NULL);
   clear = 1;
	fight->ColWidths[0] = 52;
   fight->ColWidths[3] = 68;
   quad[0] = q1;  quad[1] = q2;  quad[2] = q3;
   quad[3] = q4;  quad[4] = q5;  quad[5] = q6;
   Feku = 15;
   //NSetStoreClick(NULL);
	Memo1->Text = "Результаты боя";
   Descript->Text = "";
	InBackpack = 0;
	ItemsMet->Caption = "Предметов: "+IntToStr(InBackpack)+"/"+IntToStr((int)MaxInvent->Value);
   MH->Checked[mhFF] = true;
	MH->Checked[mhLuck] = true;
   MH->Checked[mhCharm] = true;
	//PageControl1->Pages->
	//NewItemBtn->Top = PInvent->Height
	Spins[0] = you1;
	Spins[1] = you2;
	Spins[2] = Luck;
	Spins[3] = Charizm;
	Spins[4] = gold;
	Spins[5] = food1;
	Spins[6] = Par1;
	Spins[7] = Par2;
	Spins[8] = Par3;
	///ШПАГА
	Spins[9] = ggl;
	Spins[10] = gghp;
	Spins[11] = ammo;
	Spins[12] = honor;
	Spins[13] = day;
	Spins[14] = food;
	//fabled
	Spins[15] = zrank;
	Spins[16] = zbattle;
	Spins[17] = zdosp;
	Spins[18] = zhp;
	Spins[19] = shards;

	Labels[0] = Label3;
	Labels[1] = Label4;
	Labels[2] = Label7;
	Labels[3] = Label9;
	Labels[4] = Label10;
	Labels[5] = Label11;
	Labels[6] = Label13;
	Labels[7] = Label14;
	Labels[8] = Label15;
	OpenTextFileDialog1->InitialDir = GetCurrentDir();
	Book = new TStringList;
	ParCount = 0;
	MacrosWrite = false;
}
//---------------------------------------------------------------------------
#include <time.h>
#include <stdlib.h>




void __fastcall TBaseForm::RadioPar2Click(TObject *Sender)
{
   ///you2->LabelCaption = RadioPar2->Items->Strings[RadioPar2->ItemIndex];
   //e2->LabelCaption = RadioPar2->Items->Strings[RadioPar2->ItemIndex];
}
//---------------------------------------------------------------------------
void __fastcall TBaseForm::Par2Change(TObject *Sender)
{
   //RadioPar2->Items->Strings[2] = Par2->Text;
}
//---------------------------------------------------------------------------














//Добавить предмет




void __fastcall TBaseForm::Panel1Exit(TObject *Sender)
{
	Descript->Text = "";
}
//---------------------------------------------------------------------------










//Добавить параметр

void __fastcall TBaseForm::N2Click(TObject *Sender)
{
   AboutBox->ShowModal();
}
//---------------------------------------------------------------------------
























void __fastcall TBaseForm::debug1Click(TObject *Sender)
{
	PageControl2->Pages[2]->Enabled = false;
	PageControl2->Pages[2]->Visible = false;
	PageControl2->Pages[2]->TabVisible = false;

	PageControl2->Pages[2]->Hide();
	PageControl2->Invalidate();
}
//---------------------------------------------------------------------------



