//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dice.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormDice *FormDice;
//---------------------------------------------------------------------------
__fastcall TFormDice::TFormDice(TComponent* Owner) : TForm(Owner)
{
	sides = 6;
	prev = 0;
}
//---------------------------------------------------------------------------

int __fastcall random(const int& min, const int& max)
{	//От мин до макс включительно
	return (min + rand() % (max+1-min));
}
//---------------------------------------------------------------------------
void __fastcall TFormDice::N6Click(TObject *Sender)
{
	Deselect();
	sides = 6;
	N6->Checked = true;
}
//---------------------------------------------------------------------------
void __fastcall TFormDice::N10Click(TObject *Sender)
{
	Deselect();
	sides = 10;
	N10->Checked = true;
}
//---------------------------------------------------------------------------
void __fastcall TFormDice::N20Click(TObject *Sender)
{
	Deselect();
	sides = 20;
	N20->Checked = true;
}
//---------------------------------------------------------------------------
void __fastcall TFormDice::N100Click(TObject *Sender)
{
	Deselect();
	sides = 100;
	N100->Checked = true;
}
//---------------------------------------------------------------------------

void __fastcall TFormDice::SingleDiceClick(TObject *Sender)
{
	int rand = (random(1, sides));
	if (rand == prev)
		res->Font->Color = clBlue;
	else
		res->Font->Color = clNavy;
	res->Caption = IntToStr(rand);
	prev = rand;
	//Board->Canvas->Draw(rand*20, rand*15, Gray->)
}
//---------------------------------------------------------------------------

void __fastcall TFormDice::TwoDiceClick(TObject *Sender)
{
	res->Caption = IntToStr(random(1, sides) );
	int rand1 = (random(1, sides));
	int rand2 = (random(1, sides));
	if (rand1+rand2 == prev)
		res->Font->Color = clBlue;
	else
		res->Font->Color = clNavy;

	res->Caption = IntToStr(rand1)+"+"+IntToStr(rand2)+"="+IntToStr(rand1+rand2);
	prev = rand1+rand2;
}
//---------------------------------------------------------------------------

