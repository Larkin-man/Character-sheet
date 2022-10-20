//---------------------------------------------------------------------------

#ifndef InventoryH
#define InventoryH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "CSPIN.h"
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TInventoryForm : public TForm
{
__published:	// IDE-managed Components
   TEdit *Name;
   TMemo *Descript;
   TCheckBox *HasWeight;
   TButton *Button1;
   TButton *Button2;
	TCheckBox *Hasatstart;
   TCheckBox *Estimated;
	TCSpinEdit *Kolvo;
   void __fastcall FormShow(TObject *Sender);
	void __fastcall EstimatedClick(TObject *Sender);
   void __fastcall KolvoChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
   __fastcall TInventoryForm(TComponent* Owner);
   bool NewItem;
   bool KilvoAdd;
};
//---------------------------------------------------------------------------
extern PACKAGE TInventoryForm *InventoryForm;
//---------------------------------------------------------------------------
#endif
