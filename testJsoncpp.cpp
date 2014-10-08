//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop
//#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("MainForm.cpp", JasoncppForm);
//---------------------------------------------------------------------------
extern "C" int FMXmain()
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TJasoncppForm), &JasoncppForm);
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
