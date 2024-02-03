//---------------------------------------------------------------------------
#include <vector>
#include <vcl.h>
#pragma hdrstop

#include "TableLoader.cpp"
#include "MainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TBaseForm *BaseForm;
//---------------------------------------------------------------------------
__fastcall TBaseForm::TBaseForm(TComponent* Owner)	: TForm(Owner)
{
	bool SpinClick = false;
	fight->Cells[0][0] = "Раунд";
	fight->Cells[1][0] = "Вы";
	fight->Cells[2][0] = "Враг";
	fight->Cells[3][0] = "Кто";
	zrankChange(NULL);
	clear = 1;
	fight->ColWidths[0] = 52;
	fight->ColWidths[3] = 68;
	quad[0] = q1; quad[1] = q2; quad[2] = q3;
	quad[3] = q4; quad[4] = q5; quad[5] = q6;
	Feku = 15;
	Memo1->Text = "Результаты боя";
	Descript->Text = "";
	InBackpack = 0;
	ItemsMet->Caption = "Предметов: "+IntToStr(InBackpack)+"/"+IntToStr((int)MaxInvent->Text.ToInt());
	MH->Checked[mhFF] = true;
	MH->Checked[mhLuck] = true;
	MH->Checked[mhCharm] = true;
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
	BaseForm->Height = BaseForm->Height - PanelGameReader->Height;
	ti.IgnoreFirstString = false;
	ButtonWidth = you1->Images->Width;
	PageControl1->TabIndex = 0;
}
//---------------------------------------------------------------------------

void TBaseForm::MinusClick(TCustomEdit* Sender)
{
	int i = Sender->Text.ToIntDef(0);
	i --;
	if (i <= 0)
		i = 0;
	Sender->Text = i;
}
//---------------------------------------------------------------------------

void TBaseForm::PlusClick(TCustomEdit* Sender)
{
	int i = Sender->Text.ToIntDef(0);
	i ++;
	Sender->Text = i;
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::LuckMouseActivate(TObject *Sender, TMouseButton Button,
			 TShiftState Shift, int X, int Y, int HitTest, TMouseActivate &MouseActivate)
{
	if (X >= 0 && X < ButtonWidth)
		return MinusClick(dynamic_cast<TCustomEdit*>(Sender));
	if (X >= (((TControl*)Sender)->Width - ButtonWidth - 4) && X < (((TControl*)Sender)->Width - 4))
		return PlusClick(dynamic_cast<TCustomEdit*>(Sender));
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::LuckKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if (Key == VK_UP)
		PlusClick(dynamic_cast<TCustomEdit*>(Sender));
	else
	if (Key == VK_DOWN)
		MinusClick(dynamic_cast<TCustomEdit*>(Sender));
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::ZProvBtnClick(TObject *Sender)
{
	int you = random(1,6)+random(1,6); //FloatToStrF(SumMR[you] / ALLVAR, ffGeneral, 1,1)+ "%.
	Memo2->Text = "Вы выбросили " + IntToStr(you);
	if ( you + youz->Text.ToInt() > hiez->Text.ToInt() )
		Memo2->Lines->Append("Проверка пройдена успешно.");
	else
		Memo2->Lines->Append("Вас постигла неудача.");
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::zrankChange(TObject *Sender)
{
	def = zrank->Text.ToInt() + zbattle->Text.ToInt() + zdosp->Text.ToInt();
	Def->Text = def;
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::FabledFightClick(TObject *Sender)
{
	fight->Cells[0][0] = "Удар";
	fight->Cells[1][0] = "Кубики";
	fight->Cells[2][0] = "Потери";
	fight->ColWidths[0] = 40;
	fight->ColWidths[2] = 80;

	int hp = zhp->Text.ToInt();
	int cubics, damage;
	int enemy = zehp->Text.ToInt();
	if (zbattle->Text.ToInt() + 12 <= zedef->Text.ToInt())
	{
		Memo3->Text = "Тут невозможно выиграть, вы обречены...";
		return;
	}
	int i;
	for (i=1; ;i++)
	{
		if (fight->RowCount <= i)
			fight->RowCount++;
		fight->Cells[0][i] = i;
		cubics = random(1,6)+random(1,6);
		fight->Cells[1][i] = cubics;
		if (i % 2 == 1)
		{ //ваш удар
			cubics += zbattle->Text.ToInt();
			if ( cubics > zedef->Text.ToInt() )
			{
				damage = cubics - zedef->Text.ToInt();
				fight->Cells[2][i] = "Враг -"+IntToStr(damage);
				enemy -= damage;
				if (enemy <= 0)
					break;
			}
			else
				fight->Cells[2][i] = "промах";
		}
		else
		{ //Его удар
			cubics += zebattle->Text.ToInt();
			if ( cubics > def )
			{
				damage = cubics - def;
				fight->Cells[2][i] = "Вы -"+IntToStr(damage);
				hp -= damage;
			}
			else
				fight->Cells[2][i] = "промах";
		}
	}
	if (i < fight->RowCount-1)
		fight->RowCount = i + 1;
	Memo3->Text = "Вы потеряли "+IntToStr((int)zhp->Text.ToInt() - hp);
	Memo3->Lines->Append("У вас осталось "+IntToStr(hp));
	if (hp < 1)
		Memo3->Lines->Append("Вы мертвы...");
	else
		Memo3->Lines->Append("Победа!");
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

void __fastcall TBaseForm::LuckBtnClick(TObject *Sender)
{
	PBattle->Show();
	int luck = random(1,6)+random(1,6);
	int lv = Luck->Text.ToInt();
	if (lv > 12)
		lv = 12;
	Memo1->Text = FloatToStrF(SumMR[lv] / ALLVAR, ffGeneral, 1,1)+ "%. Выпало "+IntToStr(luck);
	if (luck <= lv)
		Memo1->Lines->Append("Вам повезло!");
	else
		Memo1->Lines->Append("Ваc постигла неудача...");
	if (lv > 0)
		Luck->Text = lv-1;
	else
		Luck->Text = "0";
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::q1Click(TObject *Sender)
{
	TStaticText *sender=(TStaticText*)Sender;
	if (sender->Font->Style.Contains(fsStrikeOut))
		sender->Font->Style = TFontStyles()>> fsStrikeOut; //Почистить
	else
		sender->Font->Style = TFontStyles()<< fsStrikeOut; //Зачеркнуть
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::N1Click(TObject *Sender)
{
	if (MessageBox(Application->Handle,"Генерировать параметры героя?\n\
Мастерство = кубик + 6;\nВыносливость = 2 кубика + 12;\n\
Удача = кубик + 6.","Генерировать параметры героя",MB_YESNO) == ID_YES)
	{
		ggl->Text = random(1,6) + 6;
		you1->Text = ggl->Text.ToInt();
		gghp->Text = random(1,6)+random(1,6) + 12;
		you2->Text = gghp->Text.ToInt();
		Luck->Text = random(1,6) + 6;
		Fsu = 0;
		Eku = 15;
		day->Text = 0;
		honor->Text = 3;
		food->Text = 2;
	}
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::NNewtableClick(TObject *Sender)
{
	if (MessageBox(Application->Handle,"Генерировать параметры по таблице?\n\
>Подземелья черного замка 1995;\n>Повелитель безбрежной пустыни;\n\
>Капитан морской ведьмы;\n  ......","Генерировать по таблице",MB_YESNO) == ID_YES)
	{
		int cubics = random(1,6)+random(1,6);
		switch (cubics)
		{
			case 2 : you1->Text = 8; you2->Text = 22; Charizm->Text = 8; break;
			case 3 : you1->Text = 10; you2->Text = 20; Charizm->Text = 6; break;
			case 4 : you1->Text = 12; you2->Text = 16; Charizm->Text = 5; break;
			case 5 : you1->Text = 9; you2->Text = 18; Charizm->Text = 8; break;
			case 6 : you1->Text = 11; you2->Text = 20; Charizm->Text = 6; break;
			case 7 : you1->Text = 9; you2->Text = 20; Charizm->Text = 6; break;
			case 8 : you1->Text = 10; you2->Text = 16; Charizm->Text = 7; break;
			case 9 : you1->Text = 8; you2->Text = 24; Charizm->Text = 7; break;
			case 10 : you1->Text = 9; you2->Text = 22; Charizm->Text = 6; break;
			case 11 : you1->Text = 10; you2->Text = 18; Charizm->Text = 7; break;
			case 12 : you1->Text = 11; you2->Text = 20; Charizm->Text = 5; break;
		}
		Memo1->Text = "Выпало "+IntToStr(cubics)+" : Ловкость "+IntToStr((int)you1->Text.ToInt())
			+" Сила "+IntToStr((int)you2->Text.ToInt())+" Обаяние "+IntToStr((int)Charizm->Text.ToInt());
		NSetStoreClick(Sender);
	}
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::NGetStoreClick(TObject *Sender)
{
	int ListStart, ListEnd;
	switch (LP->ItemIndex)
	{
		case 0 : ListStart = 9; ListEnd = 15; break;
		case 1 : ListStart = 15; ListEnd = 20; break;
		default: ListStart = 0; ListEnd = 9; break;
	}

	for (int i = ListStart; i < ListEnd; ++i)
		Spins[i]->Text = Store[i];
	for (int i=0; i<6; i++)
		if (Lucker[i])
			quad[i]->Font->Style = TFontStyles()<< fsStrikeOut;
		else
			quad[i]->Font->Style = TFontStyles()>> fsStrikeOut;
	if (LP->ItemIndex == 0) ///ШПАГА
		{ Eku = Store[20];		Su = Store[21]; }
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::ButtonEkuPClick(TObject *Sender)
{
	if (nal->Text.ToInt() != int((int)nal->Text.ToInt()))
		if (MoneyType->ItemIndex == 0)
			Su += 15; //Тут прибавление изза бага в строке $
		else
			nal->Text = (int)nal->Text.ToInt();
	if (MoneyType->ItemIndex == 0)
		Eku -= (int)nal->Text.ToInt(); //$
	else
		Su -= (int)nal->Text.ToInt();
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::ButtonEkuGiveClick(TObject *Sender)
{
			if (nal->Text.ToInt() != int(nal->Text.ToInt()))
		if (MoneyType->ItemIndex == 0)
			Su += 15;
		else
			nal->Text = int(nal->Text.ToInt());
	if (MoneyType->ItemIndex == 0)
		Eku += (int)nal->Text.ToInt();
	else
		Su += (int)nal->Text.ToInt();
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::ButtonShotGaskonClick(TObject *Sender)
{
	if (ammo->Text.ToInt() <= 0)
		Memo4->Text = "У вас нет пуль.";
	else
	{
		ammo->Text = ammo->Text.ToInt()-1;
		shhp -= 4;
		Memo4->Text = "Вы попали в цель!";
	}
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::CharmBtnClick(TObject *Sender)
{
	PBattle->Show();
	int charizm = random(1,6)+random(1,6);
	int cv = Charizm->Text.ToInt();
	if (cv > 12)
		cv = 12;
	Memo1->Text = FloatToStrF(SumMR[cv] / ALLVAR, ffGeneral, 1,1)+ "%. Выпало "+IntToStr(charizm);
	if (charizm <= Charizm->Text.ToInt())
	{
		Memo1->Lines->Append("Обаяние сработало!");
		Charizm->Text = cv+1;
	}
	else
	{
		Memo1->Lines->Append("Этот трюк не прошел...");
		cv--;
		if (cv < 0)
			cv = 0;
		Charizm->Text = cv;
	}
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::BattleBtn1Click(TObject *Sender)
{
	PBattle->Show();
	int youdam, enemdam;
	int hp = you2->Text.ToInt(), ehp = e2->Text.ToInt();
	int i;
	for (i=1; ;i++)
	{
		fight->Cells[0][i]=" "+IntToStr(i);
		int rand = random(1,6);
		youdam = random(1,6);
		fight->Cells[1][i]=IntToStr(rand)+"+"+IntToStr(youdam);
		youdam += rand + you1->Text.ToInt();
		rand = random(1,6);
		enemdam = random(1,6);
		fight->Cells[2][i]=IntToStr(rand)+"+"+IntToStr(enemdam);
		enemdam += rand + e1->Text.ToInt();
		if (youdam > enemdam)
		{
			ehp-=2;
			fight->Cells[3][i]="Он: "+IntToStr(ehp);
		}
		else if (enemdam > youdam)
		{
			hp-=2;
			fight->Cells[3][i]="Вы: "+IntToStr(hp);
		}
		else
			fight->Cells[3][i]=" =";
		if (ehp <=0)
			break;
		if (i >= fight->RowCount)
			fight->RowCount += 2;
	}
	fight->RowCount = i+1;
	/*if (clear > i)
	{
		clear++;
		for (int j=i+1; j<clear; j++)
		{
			fight->Cells[0][j] = "";
			fight->Cells[1][j] = "";
			fight->Cells[2][j] = "";
			fight->Cells[3][j] = "";
		}
	}		*/
	clear = i;
	Memo1->Lines->Append("Вы потеряли "+IntToStr((int)you2->Text.ToInt()-hp));
	Memo1->Lines->Append("У вас осталось "+IntToStr(hp));
	if (hp < 1)
		Memo1->Lines->Append("Вы проиграли.");
	you2->Text = hp;
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::ParametersValidate(TObject *Sender, int ACol, int ARow,
			 const UnicodeString KeyName, const UnicodeString KeyValue)
{
	switch (ARow)
	{
		case 1: Label3->Caption = KeyValue; Label6->Caption = KeyValue; break;
		case 2: LuckBtn->Visible = !KeyValue.IsEmpty(); Label4->Caption = KeyValue; Label5->Caption = KeyValue; break;
		case 3: CharmBtn->Visible = !KeyValue.IsEmpty(); Label7->Caption = KeyValue; break;
		case 4: Label9->Caption = KeyValue; break;
		case 5: Label10->Caption = KeyValue; break;
		case 6: Label11->Caption = KeyValue; break;
		case 7: Label13->Caption = KeyValue; break;
		case 8: Label14->Caption = KeyValue; break;
		case 9: Label15->Caption = KeyValue; break;
	}
	if (ARow > 0)
		Spins[ARow-1]->Visible = !KeyValue.IsEmpty();
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::BattleBtnShClick(TObject *Sender)
{
	you1->Text = ggl->Text.ToInt();
	you2->Text = gghp->Text.ToInt();
	e1->Text = sh1->Text.ToInt();
	e2->Text = shhp->Text.ToInt();
	BattleBtn1Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::NewItemBtnClick(TObject *Sender)
{
	if (NewItemForm->ShowModal() == ID_OK)
	{
		Item *NewItem = new Item;
		NewItem->Name = NewItemForm->Name->Text;
		NewItem->HasWeight = NewItemForm->HasWeight->Checked;
		NewItem->HasAtStart = NewItemForm->Hasatstart->Checked;
		if (NewItemForm->Estimated->Checked)
		{
			NewItem->Count = NewItemForm->Kolvo->Text.ToInt();
			Inventory->AddItem(NewItem->Name+"("+IntToStr(NewItem->Count)+")", (TObject*)NewItem);
		}
		else
		{
			NewItem->Count = 0;
			Inventory->AddItem(NewItem->Name, (TObject*)NewItem);
		}
		NewItem->Description= NewItemForm->Descript->Text;

		Inventory->Checked[Inventory->Count-1] = true;
		InventoryClickCheck(Sender); //Вес
	}
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::FormClose(TObject *Sender, TCloseAction &Action)
{
	delete Book;
	for (int i=0; i<Inventory->Count; i++)
	{
		if (Inventory->Items->Objects[i] != NULL)
			delete ((Item*)Inventory->Items->Objects[i]);
	}
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::RemoveItemsBtnClick(TObject *Sender)
{
	for (int i=0; i<Inventory->Count; i++)
	{
		if (((Item*)Inventory->Items->Objects[i])->HasAtStart)
			Inventory->Checked[i] = true;
		else
			Inventory->Checked[i] = false;
	}
	InventoryClickCheck(Sender);
	RichEdit1->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::InventoryClick(TObject *Sender)
{
	int sel = Inventory->ItemIndex;
	if (sel == -1)
		return;
	Descript->Text = (((Item*)Inventory->Items->Objects[sel])->Description);
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::MaxInventChange(TObject *Sender)
{
	ItemsMet->Caption = "Предметов: "+IntToStr(InBackpack)+"/"+IntToStr((int)MaxInvent->Text.ToInt());
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::InventoryClickCheck(TObject *Sender)
{
	//Inventory->Checked[Inventory->ItemIndex]
	InBackpack = 0;
	for (int i=0; i<Inventory->Count; i++)
	{
		if (Inventory->Checked[i])
			if (((Item*)Inventory->Items->Objects[i])->HasWeight)
				InBackpack++;
			//else
			//	InBackpack--;
	}
	ItemsMet->Caption = "Предметов: "+IntToStr(InBackpack)+"/"+IntToStr((int)MaxInvent->Text.ToInt());
	if (InBackpack > MaxInvent->Text.ToInt())
		ItemsMet->Font->Color = clRed;
	else
		ItemsMet->Font->Color = clNavy;
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::InventoryKeyPress(TObject *Sender, wchar_t &Key)
{
	int select = Inventory->ItemIndex;
	if (select == -1)
		return;
	if (Key == VK_RETURN)
	{
		Item *Sel = ((Item*)Inventory->Items->Objects[select]);
		NewItemForm->Name->Text = Sel->Name; //Inventory->Items->Strings[select];
		NewItemForm->HasWeight->Checked = Sel->HasWeight;
		NewItemForm->Hasatstart->Checked = Sel->HasAtStart;
		NewItemForm->Estimated->Checked = Sel->Count;
		NewItemForm->Kolvo->Visible = Sel->Count;
		NewItemForm->Kolvo->Text = Sel->Count;
		NewItemForm->Descript->Text = Sel->Description;
		NewItemForm->NewItem = false;
		if (NewItemForm->ShowModal() == ID_OK)
		{
			Sel->Name = NewItemForm->Name->Text;
		if (Sel->HasWeight != NewItemForm->HasWeight->Checked)
		{
			Sel->HasWeight = NewItemForm->HasWeight->Checked;
			InventoryClickCheck(Sender);
		}
		else
				Sel->HasWeight = NewItemForm->HasWeight->Checked;
			Sel->HasAtStart = NewItemForm->Hasatstart->Checked;
			Inventory->Items->Strings[select] = Sel->Name;
			if (NewItemForm->Estimated->Checked)
			{
				Sel->Count = NewItemForm->Kolvo->Text.ToInt();
				Inventory->Items->Strings[select] = Inventory->Items->Strings[select] +"("+IntToStr(Sel->Count)+")";
			}
			else
				Sel->Count = 0;
			Sel->Description = NewItemForm->Descript->Text;
			Descript->Text = Sel->Description;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::ShpagaLuckBtnClick(TObject *Sender)
{
	if (random(1,6) > 3)
		Memo4->Text = "Удача на вашей стороне!";
	else
		Memo4->Text = "Не повезло...";
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::InventoryDblClick(TObject *Sender)
{
	wchar_t K = VK_RETURN;
	InventoryKeyPress(Sender, K);
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::LuckSQBtnClick(TObject *Sender)
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
		quad[dice]->Font->Style = TFontStyles()<< fsStrikeOut; //Зачеркнуть
		quad[dice]->Font->Color = clGreen;
	}
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::PageControl1Changing(TObject *Sender, bool &AllowChange)

{
	switch (LP->ItemIndex)
	{
		case 0 : Notebook1->PageIndex = LPShpaga; break;
		case 1 : Notebook1->PageIndex = LPFabled; break;
		default: Notebook1->PageIndex = LPDef; break;
	}
	PanelFF->Visible = MH->Checked[mhFF];
	LuckBtn->Visible = MH->Checked[mhLuck];
	CharmBtn->Visible = MH->Checked[mhCharm];
	LuckSq->Visible = MH->Checked[mhLuckSq];
	you1->Visible = true;
	you2->Visible = true;
	SpinsRepos();
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::MHClickCheck(TObject *Sender)
{
	Splitter3->Visible = MH->Checked[mhGR];
	PanelGameReader->Visible = MH->Checked[mhGR];
	PageControl2->Pages[2]->TabVisible = MH->Checked[mhFF];
	if (MH->Checked[mhFF])
		PageControl2->Constraints->MinWidth = 258;
	else
		PageControl2->Constraints->MinWidth = 170;
	if (MH->Checked[mhGR])
	{
		if (PanelGameReader->Align == alTop)
		{
			BaseForm->WindowState = wsMaximized;
			PageControl1->Align = alBottom;
			Splitter3->Align = alBottom;
			PanelGameReader->Align = alClient;
			PageControl1->Height = 408;
		}
	}
	else
	{
		if (PanelGameReader->Align == alClient)
		{
			PanelGameReader->Align = alTop;
			Splitter3->Align = alTop;
			PageControl1->Align = alClient;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::AddParBtnClick(TObject *Sender)
{
	if (Parameters->RowCount < 10)
	{
		switch (Parameters->RowCount)
		{
			case 9 : Par3->Visible = true; Label15->Visible = true;
			case 8 : Par2->Visible = true; Label14->Visible = true;
			case 7 : Par1->Visible = true; Label13->Visible = true;
		}
		Parameters->InsertRow(Parameters->RowCount, "Новый", true);
	}
	Parameters->SetFocus();
	Parameters->Row = Parameters->RowCount - 1;
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::DicesBtnClick(TObject *Sender)
{
 	srand(time(NULL));
	FormDice->Show();
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::ToolButton2Click(TObject *Sender)
{
	RichEdit1->SelAttributes->Color = clBlack;
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::ToolButton3Click(TObject *Sender)
{
	RichEdit1->SelAttributes->Color = clRed;
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::FontEdit1BeforeExecute(TObject *Sender)
{
	FontEdit1->Dialog->Font->Assign(RichEdit1->SelAttributes);
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::FontEdit1Accept(TObject *Sender)
{
	RichEdit1->SelAttributes->Assign(FontEdit1->Dialog->Font);
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::ColorSelect1Accept(TObject *Sender)
{
	RichEdit1->SelAttributes->Color = ColorSelect1->Dialog->Color;
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::FileOpen1Accept(TObject *Sender)
{
	MyFName = FileOpen1->Dialog->FileName;
	RichEdit1->Lines->LoadFromFile(FileOpen1->Dialog->FileName);
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::FileSaveAs1BeforeExecute(TObject *Sender)
{
	FileSaveAs1->Dialog->FileName = MyFName;
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::FileSaveAs1Accept(TObject *Sender)
{
	MyFName = FileSaveAs1->Dialog->FileName;
	RichEdit1->Lines->SaveToFile(FileSaveAs1->Dialog->FileName);
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::OneRoundBtnClick(TObject *Sender)
{
	PBattle->Show();
	int youdam, enemdam;
	//int hp=you2->Text.ToInt(), ehp=e2->Text.ToInt();
	int i;

		int rand = random(1,6);
		youdam = random(1,6);
		int rand2 = random(1,6);
		enemdam = random(1,6);
		Memo1->Lines->Append("");
		Memo1->Lines->Append(IntToStr(rand)+"+"+IntToStr(youdam)+" X "+IntToStr(rand2)+"+"+IntToStr(enemdam));
		youdam += rand + you1->Text.ToInt();
		enemdam += rand2 + e1->Text.ToInt();
		if (youdam > enemdam)
		{
			e2->Text = e2->Text.ToInt()-2;
			Memo1->Lines->Append("Вы наносите удар.");
		}
		else if (enemdam > youdam)
		{
			you2->Text = you2->Text.ToInt()-2;
			Memo1->Lines->Append("Проиграли раунд.");
		}
		else
			Memo1->Lines->Append("Отразили удары");
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::OpenBtnClick(TObject *Sender)
{
	if (OpenTextFileDialog1->Execute() == ID_OK)
	{
		//Form1->Name = OpenDialog1->FileName;
		Path.clear();
		Path.reserve(20);
		Step = 0;
		BackStep = 0;

		//Out->Lines->LoadFromFile
		if (OpenTextFileDialog1->Options.Contains(ofExtensionDifferent))
		{		//Store->Lines
			Book->LoadFromFile(OpenTextFileDialog1->FileName,
				(TEncoding *) (OpenTextFileDialog1->Encodings->Objects[OpenTextFileDialog1->EncodingIndex] ));
			//Book->Clear();
			//Book->AddStrings(Out->Lines);
			//Book->Assign(Store->Lines);
			//Store->Lines->LoadFromFile(OpenTextFileDialog1->FileName);
			//return;
		}
		else	//*/
			Book->LoadFromFile(OpenTextFileDialog1->FileName,
 				(TEncoding *) (OpenTextFileDialog1->Encodings->Objects[OpenTextFileDialog1->EncodingIndex] ));
		RefreshBookName(OpenTextFileDialog1->FileName);
		ParStartStr.clear();
		ParStartStr.reserve(50);
		ParStartStr.push_back(-1);
		int par;
		int seek = 1;
		for (int i=0; i < Book->Count; i++)
		{
			par = Book->Strings[i].Trim().ToIntDef(0);
			if (par == seek)
			{
				ParStartStr.push_back(i);
				seek++;
				for (int j=i+1; j < Book->Count; j++)
					if (Book->Strings[j].IsEmpty())
					{
						Book->Delete(j);
						j--;
					}
			}
			//try		{} catch (EConvertError&){ 	}
		}
		ParCount = seek-1;
		ParStartStr.push_back(Book->Count);
		ShowMessage("В книге "+IntToStr(ParCount)+" параграфов.");
		SelPar->Text = "0";
		GoBtnClick(Sender);
		SelPar->Text = "1";
		GoBtn->Enabled = ParCount > 0;
		PrintStepsBtn->Enabled = false;
		MacrosBtn->Enabled = true;
		MacrosPar.clear();
	}
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::OutClick(TObject *Sender)
{
	IfParSel = false;
	int Sel = Out->SelStart;
	if (Sel > 3500)
		return;
	int E = 0;
	for (int i = 0; i < Out->Lines->Count; ++i)
	{
		E += Out->Lines->Strings[i].Length();
		if (Sel <= E)
			break;
		if (Out->Text[E + 2] == '\n')
		{
			Sel++;
			E += 2;
		}
	}
	//Sel += Out->CaretPos.y;
	if (Sel == 0)
		return;
	//Memo1->Lines->Add(Out->Text[Sel]);
	if (IsCipher(Out->Text[Sel]) == false)
		Sel++;
	int Start = Sel, End = Sel;
	for (int i = Sel; i <= Out->Text.Length(); ++i)
		if (IsCipher(Out->Text[i]))
			End++;
		else
			break;
	if (Sel > Out->Text.Length())
		Sel = Out->Text.Length();
	for (int i = Sel; i > 0; --i)
		if (IsCipher(Out->Text[i]))
			Start--;
		else
			break;
	//Memo1->Lines->Add(IntToStr(Start)+"<>"+IntToStr(End));
	Start++;
	//Memo1->Lines->Add(Out->Text.SubString(Start, End-Start));
	if (End-Start > 0)
	{
		SelPar->Text = Out->Text.SubString(Start, End-Start);
		IfParSel = true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::OutDblClick(TObject *Sender)
{
	if (IfParSel)
	{
		GoBtnClick(Sender);
		SelPar->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::NEditClick(TObject *Sender)
{
 	NEdit->Checked = Out->ReadOnly;
	Out->ReadOnly = !Out->ReadOnly;
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::NPrintBookClick(TObject *Sender)
{
	Out->Lines = Book;
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::NClearPathClick(TObject *Sender)
{
	Step = 1;
	BackBtn->Enabled = false;
	BackStep = 0;
	ForwBtn->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::NNoCheatClick(TObject *Sender)
{
	NNoCheat->Checked = true;
	NNoCheat->Enabled = false;
	BackBtn->Visible = false;
	ForwBtn->Visible = false;
	PrintStepsBtn->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::NNewBeginClick(TObject *Sender)
{
	SelPar->Text = "0";
	GoBtnClick(Sender);
	SelPar->Text = "1";
	NClearPathClick(Sender);
	RemoveItemsBtnClick(Sender);
	NGetStoreClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::FontBtnClick(TObject *Sender)
{
	FontDialog1->Font = Out->Font;
	if (FontDialog1->Execute() == ID_OK)
		Out->Font = FontDialog1->Font;
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::GoBtnClick(TObject *Sender)
{
	if (MacrosWrite)
	{
		SetMacros();
	}
	int Par = SelPar->Text.ToInt();
	if (Par > ParCount)
	{
		Out->Lines->Add("В книге "+IntToStr(ParCount)+" параграфов.");
		return;
	}
	int Stop = ParStartStr[Par+1];
	Out->Lines->BeginUpdate();
	Out->Lines->Clear();
	for (int i = ParStartStr[Par]+1; i < Stop; ++i)
		Out->Lines->Add(Book->Strings[i]);
	Out->SelStart = 0;
	Out->SelLength = 0;
	Out->Invalidate();
	if (Path.size() <= Step)
	{
		Path.push_back(Par);
	}
	else //p>s
	{
		Path[Step] = Par;
	}
	Step++;
	BackBtn->Enabled = (Step > 1);
	if (BackStep > 0)
		BackStep--;
	ForwBtn->Enabled = (BackStep > 0);
	PrintStepsBtn->Enabled = true;
	if (MacrosPar.empty() == false)
	{
		RunMacros(Par);
	}
	Out->Lines->EndUpdate();
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::SelParMouseEnter(TObject *Sender)
{
	SelPar->SetFocus();
	SelPar->SelectAll();
	//SelPar->SelStart = 0;
	//SelPar->SelLength = SelPar->Text.Length();
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::BackBtnClick(TObject *Sender)
{
	BackStep += 2;
	Step -= 2;
	SelPar->Text = Path[Step];
	GoBtnClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::ForwBtnClick(TObject *Sender)
{
	SelPar->Text = Path[Step];
	GoBtnClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::PrintStepsBtnClick(TObject *Sender)
{
	Out->Lines->Add("Сделано шагов: "+IntToStr((int)Step-1));
	UnicodeString Str = "0";
	for (unsigned int i = 1; i < Step; ++i)
		Str += "->"+IntToStr(Path[i]);
	Out->Lines->Add(Str);
}
//---------------------------------------------------------------------------
//Обновить заголовок окна
void TBaseForm::RefreshBookName(UnicodeString FileName)
{
	for (int i=FileName.Length(); i>1; --i)
		if (FileName[i] == '\\')
		{
			FileName = FileName.SubString(i+1, FileName.Length());
			break;
		}
	BaseForm->Caption = FileName.SubString(1, FileName.Length()-4) + " - Лист персонажа";
}
//---------------------------------------------------------------------------
//Позиционирование спинов
void TBaseForm::SpinsRepos()
{
	static int PLeft[] = {you1->Left, e1->Left, e1->Left + e1->Left - you1->Left}; //Столбец
	static int PTopStep = you2->Top - you1->Top; //32-100% 39-125%
	static int PTop[] = {you1->Top, you1->Top + PTopStep*2, you1->Top + PTopStep*3 };
	//Начало Top: 0сверху 1безFF 2сFF 18
	int BaseTop = 2;		//{18, 80, 118}
	int BaseLeft = 0;
	if (MH->Checked[mhFF] == false)
		BaseTop = 1;
	if (MH->Checked[mhGR])
	{
		BaseLeft = 2;
		BaseTop = 0;
	}

	for (int i = 2; i < 6; ++i)
	{
		Spins[i]->Left = PLeft[BaseLeft];
		Spins[i]->Top = PTop[BaseTop] + (i-2)*PTopStep;
		Labels[i]->Left = PLeft[BaseLeft] - 7 - Labels[i]->Width;
		Labels[i]->Top = Spins[i]->Top + 3;
	}
	LuckBtn->Top = Luck->Top + 1;
	LuckBtn->Left = Luck->Left + Luck->Width + 8;
	CharmBtn->Top = Charizm->Top + 1;
	CharmBtn->Left = Charizm->Left + Charizm->Width + 8;
	if (BaseLeft == 0)
		BaseLeft = 1;
	int TopMod = 0;
	if ((MH->Checked[mhLuck])&&(MH->Checked[mhCharm]))
		TopMod = 2 * PTopStep;
	else if (MH->Checked[mhLuck])
		TopMod = 1 * PTopStep;
	else if (MH->Checked[mhFF] == false)
		TopMod = -2 * PTopStep;
	if (MH->Checked[mhGR])
	{
		if (MH->Checked[mhFF])
			TopMod = 3 * PTopStep + 7;
		else
			TopMod = 2 * PTopStep;
		BaseLeft = 0;
	}

	for (int i = 6; i < 9; ++i)
	{
		Spins[i]->Left = PLeft[BaseLeft];
		Spins[i]->Top = PTop[BaseTop] + (i-6)*PTopStep + TopMod;
		Labels[i]->Left = PLeft[BaseLeft] - 7 - Labels[i]->Width;
		Labels[i]->Top = Spins[i]->Top + 3;
	}

	LuckSq->Top = 263;
	if (MH->Checked[mhGR])
		LuckSq->Top -= 54;
	if (MH->Checked[mhFF] == false)
		LuckSq->Top -= 38;
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::MacrosBtnClick(TObject *Sender)
{
	if (MacrosWrite)
	{
		SetMacros();
		ShowMessage("Макрос записан!");
		return;
	}
	if (MessageBox(Application->Handle, "Макрос это последовательность действий\
 которые автоматически применятся на этом параграфе. Модифицируйте\
 несколько своих параметров.\nЗаписать макрос?",
	"Макрос",MB_YESNO + MB_ICONINFORMATION) == ID_YES)
	{
		CurrPar = SelPar->Text.ToInt();
		MacrosWrite = true;
		int ListStart, ListEnd;
		switch (LP->ItemIndex)
		{
			case 0 : ListStart = 9; ListEnd = 15; break;
			case 1 : ListStart = 15; ListEnd = 20; break;
			default: ListStart = 0; ListEnd = 9; break;
		}
		for (int i = ListStart; i < ListEnd; ++i)
		{
			MacrosStore[i] = Spins[i]->Text.ToInt();
		}
	}
}
//---------------------------------------------------------------------------
void TBaseForm::SetMacros()
{
	MacrosWrite = false;
	int ListStart, ListEnd;
	switch (LP->ItemIndex)
	{
		case 0 : ListStart = 9; ListEnd = 15; break;
		case 1 : ListStart = 15; ListEnd = 20; break;
		default: ListStart = 0; ListEnd = 9; break;
	}
	for (int i = ListStart; i < ListEnd; ++i)
	{
		if (MacrosStore[i] != Spins[i]->Text.ToInt())
		{
			MacrosPar.push_back(MacrosData(CurrPar, i, Spins[i]->Text.ToInt() - MacrosStore[i]));
		}
	}
}
//---------------------------------------------------------------------------

void TBaseForm::RunMacros(int Par)
{
	for (std::vector<MacrosData>::const_iterator i = MacrosPar.begin(); i != MacrosPar.end(); ++i)
		if (Par == i->Par)
		{
			Spins[i->StoreIdx]->Text = Spins[i->StoreIdx]->Text.ToInt() + i->Mod;
			Out->Lines->Add(Labels[i->StoreIdx]->Caption +"+"+IntToStr(i->Mod));
		}
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::SelParKeyPress(TObject *Sender, wchar_t &Key)
{
	if (Key == VK_RETURN)
		if (GoBtn->Enabled)
			GoBtnClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::NSetStoreClick(TObject *Sender)
{
	for (int i = 0; i < SPINSSAVE; ++i)
	{
		Store[i] = Spins[i]->Text.ToInt();
		Spins[i]->Hint = "Исходное значение: "+IntToStr(Store[i]);
		Spins[i]->ShowHint = true;
	}
	for (int i=0; i<6; i++)
		Lucker[i] = quad[i]->Font->Style.Contains(fsStrikeOut);
	Store[20] = Eku;
	Store[21] = Su;
	NGetStore->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::BoxInvClick(TObject *Sender)
{
	if (ItemsMet->Visible)
		PanelItemsBottom->Height = 28;
	else
		PanelItemsBottom->Height = 48;
	ItemsMet->Visible = !BoxInv->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::LPClick(TObject *Sender)
{
	if (LP->ItemIndex != chkCustomList)
		MH->Checked[mhFF] = true;
	PageControl2->Pages[2]->TabVisible = MH->Checked[mhFF];
	MH->ItemEnabled[mhFF] = LP->ItemIndex == chkCustomList;
	MH->ItemEnabled[mhLuck] = LP->ItemIndex == chkCustomList;
	MH->ItemEnabled[mhCharm] = LP->ItemIndex == chkCustomList;
	MH->ItemEnabled[mhLuckSq] = LP->ItemIndex == chkCustomList;
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::NSaveItemsClick(TObject *Sender)
{
	Item *it;
	TStringList *save = new TStringList;
	save->Capacity = Inventory->Count;
	for (int i = 0; i < Inventory->Count; ++i)
	{
		it = ((Item*)Inventory->Items->Objects[i]);
		save->Append(it->Name+"\t"+IntToStr((int)it->HasWeight)
			+"\t"+IntToStr((int)it->HasAtStart)+"\t"+IntToStr(it->Count)
			+"\t"+IntToStr((int)Inventory->Checked[i])+"\t"+it->Description);
	}
	save->SaveToFile("Items.txt");
	ShowMessage("Saved items to Items.txt");
	delete save;
}
//---------------------------------------------------------------------------

void TBaseForm::SetEku(int eku)
{
	Feku = eku;
	if (Feku < 0)
		Feku = 0;
	Label1->Caption = "Деньги: "+IntToStr(Feku)+" Экю, " +IntToStr(Fsu)+" Су.";
}
//---------------------------------------------------------------------------

void TBaseForm::SetSu(int su)
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
	Label1->Caption = "Деньги: "+IntToStr(Feku)+" Экю, " +IntToStr(Fsu)+" Су.";
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::NLoadItemsClick(TObject *Sender)
{
	String *Name, *Desc;
	bool	*Start, *Weig, *Has;
	int	*Count;
	ti.LoadFromFile("Items.txt","sbbibs",&Name,&Weig,&Start,&Count,&Has,&Desc);
	for (int i = 0; i < ti.RowCount; ++i)
	{
		Item *NewItem = new Item;
		NewItem->Name = Name[i];
		NewItem->Description = Desc[i];
		NewItem->HasWeight = Weig[i];
		NewItem->HasAtStart = Start[i];
		NewItem->Count = Count[i];
		if (Count[i] > 1)
			Inventory->AddItem(Name[i]+"("+IntToStr(Count[i])+")", (TObject*)NewItem);
		else
			Inventory->AddItem(Name[i], (TObject*)NewItem);
		if (Has[i])
			Inventory->Checked[Inventory->Count-1] = true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::youzChange(TObject *Sender)
{
	int ti = hiez->Text.ToIntDef(0);
	ti -= youz->Text.ToIntDef(0);
	if (ti > 12)	ti = 12;
	else if (ti < 0)	ti = 0;
	ti = 12 - ti;
	ti++;
	if (ti > 12)	ti = 12;
	ZProvBtn->Hint = FloatToStrF(SumMR[ti] / ALLVAR, ffGeneral, 3, 2)+"%";
	//Memo3->Text = ti;
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::shardsLeftButtonClick(TObject *Sender)
{
	int value = shards->Text.ToInt();
	if (value <= 0)
	{
		shards->Text = "0";
		return;
	}
	shards->Text = value-Adds->Text.ToIntDef(1);
	if (Adds->Text != "1")
		Adds->Text = "1";
}
//---------------------------------------------------------------------------

void __fastcall TBaseForm::shardsRightButtonClick(TObject *Sender)
{
	int value = shards->Text.ToInt();
	shards->Text = value+Adds->Text.ToIntDef(1);
	if (Adds->Text != "1")
		Adds->Text = "1";
}
//---------------------------------------------------------------------------

