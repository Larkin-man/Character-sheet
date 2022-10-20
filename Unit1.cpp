//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSpin"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
   : TForm(Owner)
{
   //Form2->Show();
   out->Cells[0][0] = "�����";
   out->Cells[1][0] = "��";
   out->Cells[2][0] = "��";
   out->Cells[3][0] = "���";
   fight->Cells[0][0] = "����";
   fight->Cells[1][0] = "������";
   fight->Cells[2][0] = "������";
   fight->ColWidths[0] = 40;
   fight->ColWidths[2] = 80;
   zrankChange(NULL);
   clear = 1;
   quad[0] = q1;  quad[1] = q2;  quad[2] = q3;
   quad[3] = q4;  quad[4] = q5;  quad[5] = q6;
   Feku = 15;  
}
//---------------------------------------------------------------------------
#include <time.h>
#include <stdlib.h>

int random(const int& min, const int& max)
{    //�� ��� �� ���� ������������
     //srand(time(NULL));   //������������ ����������. ���� ����� ������
     return (min + rand() % (max+1-min));
}
void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
   int youdam, enemdam;
   int hp=you2->Value, ehp=e2->Value;

   for (int i=1; ;i++)
   {
      out->Cells[0][i]=i;
      youdam = random(1,6)+random(1,6)+you1->Value;
      out->Cells[1][i]=youdam;
      enemdam = random(1,6)+random(1,6)+e1->Value;
      out->Cells[2][i]=enemdam;
      if (youdam > enemdam)
      {
         ehp-=2;
         out->Cells[3][i]="��: "+IntToStr(ehp);
      }
      else if (enemdam > youdam)
      {
         hp-=2;
         out->Cells[3][i]="��: "+IntToStr(hp);
      }
      if (ehp <=0)
         break;
   }
   Memo1->Lines->Add("�� �������� "+IntToStr(you2->Value-hp));
   Memo1->Lines->Add("� ��� �������� "+IntToStr(hp));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
   srand(time(NULL));
   for (int i=0;i<12;i++)
   {
      out->Cells[1][i]=random(1,6);
   }
   Form2->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
   int you = random(1,6)+random(1,6);
   Memo2->Text = "�� ��������� " + IntToStr(you);
   if ( you + youz->Value > hiez->Value )
      Memo2->Lines->Append("�������� �������� �������.");
   else
      Memo2->Lines->Append("��� �������� �������.");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::zrankChange(TObject *Sender)
{
   def = zrank->Value + zbattle->Value + zdosp->Value;
   Def->Text = def;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
   //int round = 1;
   int hp = zhp->Value;
   int cubics, damage;
   int enemy = zehp->Value;
   int i;
   for (i=1; ;i++)
   {
      fight->Cells[0][i] = i;
      cubics = random(1,6)+random(1,6);
      fight->Cells[1][i] = cubics;
      if (i % 2 == 1)
      { //��� ����
         cubics += zbattle->Value;
         if ( cubics > zedef->Value )
         {
            damage = cubics - zedef->Value;
            fight->Cells[2][i] = "���� -"+IntToStr(damage);
            enemy -= damage;
            if (enemy < 1)
               break;
         }
         else
            fight->Cells[2][i] = "������";
      }
      else
      {  //��� ����
         cubics += zebattle->Value;
         if ( cubics > def )
         {
            damage = cubics - def;
            fight->Cells[2][i] = "�� -"+IntToStr(damage);
            hp -= damage;
         }
         else
            fight->Cells[2][i] = "������";

      }
   }

   Memo3->Text = "�� �������� "+IntToStr(zhp->Value - hp);
   Memo3->Lines->Append("� ��� �������� "+IntToStr(hp));
   if (hp < 1)
      Memo3->Lines->Append("�� ������...");
   else
      Memo3->Lines->Append("������!");
   if (clear > i)
   {
      clear++;
      for (int j=i+1; j<clear; j++)
      {
         fight->Cells[0][j] = "";
         fight->Cells[1][j] = "";
         fight->Cells[2][j] = "";
      }
   }
   clear = i;

}
//---------------------------------------------------------------------------
//���������
void __fastcall TForm1::RadioPar1Click(TObject *Sender)
{
   you1->LabelCaption = RadioPar1->Items->Strings[RadioPar1->ItemIndex];
   e1->LabelCaption = RadioPar1->Items->Strings[RadioPar1->ItemIndex];
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Par1Change(TObject *Sender)
{
   RadioPar1->Items->Strings[2] = Par1->Text;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioPar2Click(TObject *Sender)
{
   you2->LabelCaption = RadioPar2->Items->Strings[RadioPar2->ItemIndex];
   e2->LabelCaption = RadioPar2->Items->Strings[RadioPar2->ItemIndex];
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Par2Change(TObject *Sender)
{
   RadioPar2->Items->Strings[2] = Par2->Text;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
   int luck = random(1,6)+random(1,6);
   Memo1->Text = "������ "+IntToStr(luck);
   if (luck <= Luck->Value)
      Memo1->Lines->Append("��� �������!");
   else
      Memo1->Lines->Append("��c �������� �������...");
   Luck->Value--;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::quadratClick(TObject *Sender)
{
   TStaticText *sender=(TStaticText*)Sender;
   if (sender->Font->Style.Contains(fsStrikeOut))
      sender->Font->Style = TFontStyles()>> fsStrikeOut; //���������
   else
      sender->Font->Style = TFontStyles()<< fsStrikeOut; //����������
   //sender->Font->Style.operator >>(fsStrikeOut);
   //if ((TStaticText *)Sender)->Font->
   //*TStaticText(Sender)->
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn2Click(TObject *Sender)
{
   static bool sranding = false;
   if (!sranding)
   {
      srand(time(NULL));
      sranding = true;
   }

   int dice = rand() % 6;
   for (int i=0; i<6; i++)
      if (i != dice)
         quad[i]->Font->Color = clBlack;
   if (quad[dice]->Font->Style.Contains(fsStrikeOut))
      if (quad[dice]->Font->Color == clRed)
         quad[dice]->Font->Color = clYellow;
      else
         quad[dice]->Font->Color = clRed;
   else
   {
      quad[dice]->Font->Style = TFontStyles()<< fsStrikeOut; //����������
      quad[dice]->Font->Color = clGreen;
   }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::N1Click(TObject *Sender)
{
     ggl->Value = random(1,6) + 6;
     gghp->Value = random(1,6) * 2 + 12;
     Fsu = 0;
     Eku = 15;
     day->Value = 0;
     honor->Value = 3;
     food->Value = 2;     
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn3Click(TObject *Sender)
{
   if (random(1,6) > 3)
      Memo4->Text = "����� �� ����� �������!";
   else
      Memo4->Text = "���������";
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button5Click(TObject *Sender)
{
   if (MoneyType->ItemIndex == 0)
      Eku -= nal->FloatValue;
   else
      Su -= nal->FloatValue;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
   if (MoneyType->ItemIndex == 0)
      Eku += nal->FloatValue;
   else
      Su += nal->FloatValue;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
   if (ammo->Value <= 0)
      Memo4->Text = "� ��� ��� ����.";
   else
   {
      ammo->Value--;
      shhp -= 4;
      Memo4->Text = "�� ������ � ����!";
   }
}
//---------------------------------------------------------------------------

