//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("Dice.cpp", FormDice);
USEFORM("MainForm.cpp", BaseForm);
USEFORM("Inventory.cpp", InventoryForm);
USEFORM("About.cpp", AboutBox);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
   try
   {
       Application->Initialize();
       Application->CreateForm(__classid(TBaseForm), &BaseForm);
       Application->CreateForm(__classid(TFormDice), &FormDice);
       Application->CreateForm(__classid(TInventoryForm), &InventoryForm);
       Application->CreateForm(__classid(TAboutBox), &AboutBox);
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
