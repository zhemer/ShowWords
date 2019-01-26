/*
ShowWord foreign words trainer.
Copyright (C) 2007 Sergey Zhemerdeev <zhseal0@gmail.com>

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#include "stdafx.h"
#include "FormMain.h"
#undef GetObject

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;



//namespace ShowWords {//
//--------------------------------------------------------------------------------------------------	
public __gc class FormAddWord : public System::Windows::Forms::Form
{
public:
		FormMain *fm;

//--------------------------------------------------------------------------------------------------	
FormAddWord(FormMain *fm)
{
	InitializeComponent();
	this->fm = fm;
	Text = String::Concat(PRG_NAME, " - ", Text);

	// Position window
	HWND hwndDsk = GetDesktopWindow();
	RECT rect;
	if (GetWindowRect(hwndDsk, &rect))
		Location = Point(rect.right - this->Width - 10, rect.bottom - this->Height - 36 - 10);
}

protected: 
//--------------------------------------------------------------------------------------------------	
void Dispose(Boolean disposing)
{
	if (disposing && components) {
		components->Dispose();
	}
	__super::Dispose(disposing);
}


private:
	System::ComponentModel::Container* components;

	System::Windows::Forms::TextBox *  edWord;
	System::Windows::Forms::Button *  btnOk;
	System::Windows::Forms::Button *  btnCancel;


//--------------------------------------------------------------------------------------------------	
void InitializeComponent(void)
{
	System::Resources::ResourceManager *  resources = new System::Resources::ResourceManager(__typeof(FormAddWord));
	this->edWord = new System::Windows::Forms::TextBox();
	this->btnOk = new System::Windows::Forms::Button();
	this->btnCancel = new System::Windows::Forms::Button();
	this->SuspendLayout();
	// 
	// edWord
	// 
	this->edWord->Location = System::Drawing::Point(8, 8);
	this->edWord->Multiline = true;
	this->edWord->Name = S"edWord";
	this->edWord->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
	this->edWord->Size = System::Drawing::Size(328, 56);
	this->edWord->TabIndex = 1;
	this->edWord->Text = S"";
	this->edWord->TextChanged += new System::EventHandler(this, edWord_TextChanged);
	// 
	// btnOk
	// 
	this->btnOk->Enabled = false;
	this->btnOk->Location = System::Drawing::Point(184, 72);
	this->btnOk->Name = S"btnOk";
	this->btnOk->TabIndex = 2;
	this->btnOk->Text = S"OK";
	this->btnOk->Click += new System::EventHandler(this, btnOk_Click);
	// 
	// btnCancel
	// 
	this->btnCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
	this->btnCancel->Location = System::Drawing::Point(264, 72);
	this->btnCancel->Name = S"btnCancel";
	this->btnCancel->TabIndex = 3;
	this->btnCancel->Text = S"Cancel";
	this->btnCancel->Click += new System::EventHandler(this, btnCancel_Click);
	// 
	// FormAddWord
	// 
	this->AcceptButton = this->btnOk;
	this->AutoScaleBaseSize = System::Drawing::Size(6, 15);
	this->CancelButton = this->btnCancel;
	this->ClientSize = System::Drawing::Size(346, 98);
	this->Controls->Add(this->btnCancel);
	this->Controls->Add(this->btnOk);
	this->Controls->Add(this->edWord);
	this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
	this->Icon = (__try_cast<System::Drawing::Icon *  >(resources->GetObject(S"$this.Icon")));
	this->MaximizeBox = false;
	this->MinimizeBox = false;
	this->Name = S"FormAddWord";
	this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
	this->Text = S"Adding word";
	this->ResumeLayout(false);

}		


	
//--------------------------------------------------------------------------------------------------	
void btnCancel_Click(System::Object *sender, System::EventArgs *e)
{
	Close();
}



//--------------------------------------------------------------------------------------------------	
void btnOk_Click(System::Object *sender, System::EventArgs *e)
{
	bool bThRun1 = fm->bThRun;

	AddWord();

	if (bThRun1)
		fm->StartStop();

	fm->LoadWordList(fm->sIniWordList);

	if (bThRun1)
		fm->StartStop();

	Close();
}



//--------------------------------------------------------------------------------------------------	
void edWord_TextChanged(System::Object *sender, System::EventArgs *e)
{
	if (StrCmp(edWord->Text, "") == 0)
		btnOk->Enabled = false;
	else
		btnOk->Enabled = true;
}


//--------------------------------------------------------------------------------------------------	
void AddWord()
{
	char sBuf[BUF_SIZE], sPath[_MAX_PATH], sPathTmp[_MAX_PATH];
	FILE *f, *fTmp;
	
	strcpy(sPath, cstr(fm->sIniWordList));
	sprintf(sPathTmp, "%s.tmp", sPath);
	
	rename(sPath, sPathTmp);

	f = fopen(sPath, "w");	
	fTmp = fopen(sPathTmp, "r");
	
	sprintf(sBuf, "%s\n", cstr(edWord->Text));
	fputs(sBuf, f);
	while (fgets(sBuf, 200, fTmp)) {
		fputs(sBuf, f);
	}
	fclose(f);
	fclose(fTmp);

	remove(sPathTmp);
}



}; // class FormAddWord
//} // namespace ShowWords
