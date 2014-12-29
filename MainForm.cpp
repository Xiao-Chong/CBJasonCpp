//---------------------------------------------------------------------------
#include <fmx.h>

#include <memory>
#include <string>

#pragma hdrstop

#include "MainForm.h"
#include <json/json.h>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
#pragma resource ("*.NmXhdpiPh.fmx", _PLAT_ANDROID)

using namespace std;


TJasoncppForm *JasoncppForm;
//---------------------------------------------------------------------------
__fastcall TJasoncppForm::TJasoncppForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TJasoncppForm::btn1Click(TObject *Sender)
{
    // why not use UTF8String ? because mobile apps don't support it.

	TBytes doc = TEncoding::UTF8->GetBytes(L"{\"array\":[{\"id\":1,\"name\":\"蕭沖\"},{\"id\":2,\"name\":\"喆寶\"}]}");
	doc.Length = doc.Length +1; // important here for string test
	doc[doc.High] = 0;          // for string test
	string test((char*)&doc[0]);
	Json::Reader reader;
	Json::Value value;
	if (reader.parse(test, value)) {
		const Json::Value arrayObj = value["array"];
		for (int i=0; i<arrayObj.size(); i++) {
			int id = arrayObj[i]["id"].asInt();
			string name = arrayObj[i]["name"].asString();
			TBytes byName = BytesOf(name.c_str(),name.length());
			ShowMessage(IntToStr(id) + L" " +TEncoding::UTF8->GetString(byName));  // GetString in Windows use MultiByteToWideChar
		}
	} else {

	}
}
//---------------------------------------------------------------------------
void __fastcall TJasoncppForm::btn2Click(TObject *Sender)
{
    // another way to convert unicode to utf8 by stream
	//::unique_ptr<TStringStream> ss(new TStringStream("",TEncoding::GetEncoding(65001),true)); //UTF8 65001
	//ss->WriteString(L"{\"id\":1,\"name\":\"hello蕭沖A\"}");
	//string test((char*)ss->Memory);

	TBytes doc = TEncoding::UTF8->GetBytes(L"{\"id\":1,\"name\":\"hello蕭沖A喆B\"}");
	doc.Length = doc.Length +1;
	doc[doc.High] = 0;
	string test((char*)&doc[0]);

//	Json::Features features;
//	features.strictRoot_ = true;
	Json::Reader reader(Json::Features::strictMode());
	Json::Value value;
//	string test2("404 Not Found");
	if (reader.parse(test, value)) {
		int id = value["id"].asInt();
		string name = value["name"].asString();

		TBytes byName = BytesOf(name.c_str(),name.length());
		ShowMessage(TEncoding::UTF8->GetString(byName));

	} else {

	}

	// below try to figure out encoding and converting tricks.
	TBytes cp950 = TEncoding::GetEncoding(950)->GetBytes(L"中國中12345");
	cp950.Length = cp950.Length + 1;  // why? cause NULL byte was not converted
	cp950[cp950.High] = 0;

	string text((char*)&cp950[0]); // note NULL termintated needed.

	//string text = "中國中12345";  //OSX emit utf8; but android win CP_ACP


	TBytes db, db2;
	int dl = text.length();
	db = BytesOf(text.c_str(), dl);
	db2.Length = dl*2;
	BinToHex(db,0,db2,0,dl);

	//db[db.High] = 0;
	//db2[db2.High] = 0;

	ShowMessage(TEncoding::GetEncoding(950)->GetString(db));
	ShowMessage(TEncoding::ASCII->GetString(db2));

}
//---------------------------------------------------------------------------

