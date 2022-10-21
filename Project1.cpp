//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("MainForm.cpp", BaseForm);
USEFORM("Dice.cpp", FormDice);
USEFORM("NewItem.cpp", NewItemForm);
//---------------------------------------------------------------------------
WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->Title = "Лист персонажа";
		Application->CreateForm(__classid(TBaseForm), &BaseForm);
		Application->CreateForm(__classid(TFormDice), &FormDice);
		Application->CreateForm(__classid(TNewItemForm), &NewItemForm);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
