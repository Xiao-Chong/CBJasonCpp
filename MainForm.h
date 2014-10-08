//---------------------------------------------------------------------------

#ifndef MainFormH
#define MainFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TJasoncppForm : public TForm
{
__published:	// IDE-managed Components
	TButton *btn1;
	TButton *btn2;
	void __fastcall btn1Click(TObject *Sender);
	void __fastcall btn2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TJasoncppForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TJasoncppForm *JasoncppForm;
//---------------------------------------------------------------------------
#endif
