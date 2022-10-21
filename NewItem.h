//---------------------------------------------------------------------------

#ifndef NewItemH
#define NewItemH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TNewItemForm : public TForm
{
__published:	// IDE-managed Components
	TMemo *Descript;
	TButton *CancelBtn;
	TButton *ButtonAdd;
	TCheckBox *Estimated;
	TCheckBox *Hasatstart;
	TCheckBox *HasWeight;
	TEdit *Name;
	TEdit *Kolvo;
	TUpDown *UpDown1;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall EstimatedClick(TObject *Sender);
	void __fastcall UpDown1Changing(TObject *Sender, bool &AllowChange);
private:	// User declarations
public:		// User declarations
	__fastcall TNewItemForm(TComponent* Owner);
	bool NewItem;
   bool KilvoAdd;
};
//---------------------------------------------------------------------------
extern PACKAGE TNewItemForm *NewItemForm;
//---------------------------------------------------------------------------
#endif
