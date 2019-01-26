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

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;



//namespace ShowWords { //
//--------------------------------------------------------------------------------------------------	
public __gc class FormSettings : public System::Windows::Forms::Form
{
public:
		FormMain *fm;
private:
		System::Windows::Forms::Label *  label1;
		System::Windows::Forms::Label *  label2;
		String *sWordListOld;
		int iIniWordDelayOld, iIniWordDurationOld;
private: System::Windows::Forms::Button *  btnColorSel;

private: System::Windows::Forms::ColorDialog *  colorDialog1;


public:
//--------------------------------------------------------------------------------------------------	
FormSettings(FormMain *fm)
{
	InitializeComponent();
	this->fm = fm;
	Text = String::Concat(PRG_NAME, " - ", Text);

	// Position window
	HWND hwndDsk = GetDesktopWindow();
	RECT rect;
	if (GetWindowRect(hwndDsk, &rect))
		Location = Point(rect.right - this->Width - 10, rect.bottom - this->Height - 36 - 10);

	// Word list
	edWordList->Text = fm->sIniWordList;
	sWordListOld = new String("");
	sWordListOld = fm->sIniWordList;

	// Font
	lblFontPattern->Font = fm->lblWord->Font;
	lblFontPattern->ForeColor = fm->lblWord->ForeColor;
	lblFontPattern->BackColor = fm->lblWord->BackColor;

	// Word delay
	if (edWordDelay->Minimum > fm->iIniWordDelay)
		edWordDelay->Value = edWordDelay->Minimum;
	else
		edWordDelay->Value = fm->iIniWordDelay;
	iIniWordDelayOld = fm->iIniWordDelay;

	// Word duration
	if (edWordDur->Minimum > fm->iIniWordDuration)
		edWordDur->Value = edWordDur->Minimum;
	else
		edWordDur->Value = fm->iIniWordDuration;
	iIniWordDurationOld = fm->iIniWordDuration;

	// Toool tips
	SetToolTip();
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
private: System::ComponentModel::IContainer *  components;

private:

	System::Windows::Forms::TabControl *  tabControl1;
	System::Windows::Forms::TabPage *  tabPage1;

	System::Windows::Forms::GroupBox *  groupBox1;
	System::Windows::Forms::TextBox *  textBox2;
	private: System::Windows::Forms::Label *  label4;
	private: System::Windows::Forms::Label *  label3;
	private: System::Windows::Forms::TextBox *  textBox1;
	private: System::Windows::Forms::CheckBox *  chkPosShowWin;
	private: System::Windows::Forms::Button *  btnCancel;
	private: System::Windows::Forms::Button *  btnOk;
	private: System::Windows::Forms::TextBox *  edWordList;
	private: System::Windows::Forms::Button *  btnWordListSel;
	private: System::Windows::Forms::Label *  lblFontPattern;
	private: System::Windows::Forms::Button *  btnFontSel;
	private: System::Windows::Forms::Label *  lblFont;
private: System::Windows::Forms::TabPage *  tabPage2;
private: System::Windows::Forms::ToolTip *  toolTip1;
private: System::Windows::Forms::Label *  lblWordList;
private: System::Windows::Forms::NumericUpDown *  edWordDur;
private: System::Windows::Forms::Label *  lblWordDur;
private: System::Windows::Forms::NumericUpDown *  edWordDelay;
private: System::Windows::Forms::Label *  lblWordDelay;



//--------------------------------------------------------------------------------------------------	
void InitializeComponent(void)
{
	this->components = new System::ComponentModel::Container();
	System::Resources::ResourceManager *  resources = new System::Resources::ResourceManager(__typeof(FormSettings));
	this->tabControl1 = new System::Windows::Forms::TabControl();
	this->tabPage1 = new System::Windows::Forms::TabPage();
	this->btnColorSel = new System::Windows::Forms::Button();
	this->edWordList = new System::Windows::Forms::TextBox();
	this->btnWordListSel = new System::Windows::Forms::Button();
	this->lblWordList = new System::Windows::Forms::Label();
	this->groupBox1 = new System::Windows::Forms::GroupBox();
	this->textBox2 = new System::Windows::Forms::TextBox();
	this->label4 = new System::Windows::Forms::Label();
	this->label3 = new System::Windows::Forms::Label();
	this->textBox1 = new System::Windows::Forms::TextBox();
	this->chkPosShowWin = new System::Windows::Forms::CheckBox();
	this->lblFontPattern = new System::Windows::Forms::Label();
	this->btnFontSel = new System::Windows::Forms::Button();
	this->lblFont = new System::Windows::Forms::Label();
	this->tabPage2 = new System::Windows::Forms::TabPage();
	this->label2 = new System::Windows::Forms::Label();
	this->label1 = new System::Windows::Forms::Label();
	this->edWordDur = new System::Windows::Forms::NumericUpDown();
	this->lblWordDur = new System::Windows::Forms::Label();
	this->edWordDelay = new System::Windows::Forms::NumericUpDown();
	this->lblWordDelay = new System::Windows::Forms::Label();
	this->btnCancel = new System::Windows::Forms::Button();
	this->btnOk = new System::Windows::Forms::Button();
	this->toolTip1 = new System::Windows::Forms::ToolTip(this->components);
	this->colorDialog1 = new System::Windows::Forms::ColorDialog();
	this->tabControl1->SuspendLayout();
	this->tabPage1->SuspendLayout();
	this->groupBox1->SuspendLayout();
	this->tabPage2->SuspendLayout();
	(__try_cast<System::ComponentModel::ISupportInitialize *  >(this->edWordDur))->BeginInit();
	(__try_cast<System::ComponentModel::ISupportInitialize *  >(this->edWordDelay))->BeginInit();
	this->SuspendLayout();
	// 
	// tabControl1
	// 
	this->tabControl1->Controls->Add(this->tabPage1);
	this->tabControl1->Controls->Add(this->tabPage2);
	this->tabControl1->Location = System::Drawing::Point(8, 8);
	this->tabControl1->Name = S"tabControl1";
	this->tabControl1->SelectedIndex = 0;
	this->tabControl1->Size = System::Drawing::Size(448, 288);
	this->tabControl1->TabIndex = 0;
	// 
	// tabPage1
	// 
	this->tabPage1->Controls->Add(this->btnColorSel);
	this->tabPage1->Controls->Add(this->edWordList);
	this->tabPage1->Controls->Add(this->btnWordListSel);
	this->tabPage1->Controls->Add(this->lblWordList);
	this->tabPage1->Controls->Add(this->groupBox1);
	this->tabPage1->Controls->Add(this->lblFontPattern);
	this->tabPage1->Controls->Add(this->btnFontSel);
	this->tabPage1->Controls->Add(this->lblFont);
	this->tabPage1->Location = System::Drawing::Point(4, 25);
	this->tabPage1->Name = S"tabPage1";
	this->tabPage1->Size = System::Drawing::Size(440, 259);
	this->tabPage1->TabIndex = 0;
	this->tabPage1->Text = S"Common";
	// 
	// btnColorSel
	// 
	this->btnColorSel->Location = System::Drawing::Point(392, 8);
	this->btnColorSel->Name = S"btnColorSel";
	this->btnColorSel->Size = System::Drawing::Size(40, 23);
	this->btnColorSel->TabIndex = 20;
	this->btnColorSel->Text = S"Bg...";
	this->btnColorSel->Click += new System::EventHandler(this, btnColorSel_Click);
	// 
	// edWordList
	// 
	this->edWordList->BackColor = System::Drawing::SystemColors::Control;
	this->edWordList->Location = System::Drawing::Point(48, 56);
	this->edWordList->Name = S"edWordList";
	this->edWordList->ReadOnly = true;
	this->edWordList->Size = System::Drawing::Size(304, 22);
	this->edWordList->TabIndex = 18;
	this->edWordList->Text = S"";
	// 
	// btnWordListSel
	// 
	this->btnWordListSel->Location = System::Drawing::Point(360, 56);
	this->btnWordListSel->Name = S"btnWordListSel";
	this->btnWordListSel->Size = System::Drawing::Size(24, 23);
	this->btnWordListSel->TabIndex = 17;
	this->btnWordListSel->Text = S"...";
	this->btnWordListSel->Click += new System::EventHandler(this, btnWordListSel_Click);
	// 
	// lblWordList
	// 
	this->lblWordList->Location = System::Drawing::Point(8, 56);
	this->lblWordList->Name = S"lblWordList";
	this->lblWordList->Size = System::Drawing::Size(32, 24);
	this->lblWordList->TabIndex = 16;
	this->lblWordList->Text = S"File";
	this->lblWordList->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
	// 
	// groupBox1
	// 
	this->groupBox1->Controls->Add(this->textBox2);
	this->groupBox1->Controls->Add(this->label4);
	this->groupBox1->Controls->Add(this->label3);
	this->groupBox1->Controls->Add(this->textBox1);
	this->groupBox1->Controls->Add(this->chkPosShowWin);
	this->groupBox1->Location = System::Drawing::Point(16, 184);
	this->groupBox1->Name = S"groupBox1";
	this->groupBox1->Size = System::Drawing::Size(352, 64);
	this->groupBox1->TabIndex = 15;
	this->groupBox1->TabStop = false;
	this->groupBox1->Text = S"Position";
	this->groupBox1->Visible = false;
	// 
	// textBox2
	// 
	this->textBox2->Enabled = false;
	this->textBox2->Location = System::Drawing::Point(144, 24);
	this->textBox2->Name = S"textBox2";
	this->textBox2->ReadOnly = true;
	this->textBox2->Size = System::Drawing::Size(64, 22);
	this->textBox2->TabIndex = 8;
	this->textBox2->Text = S"";
	// 
	// label4
	// 
	this->label4->Enabled = false;
	this->label4->Location = System::Drawing::Point(120, 24);
	this->label4->Name = S"label4";
	this->label4->Size = System::Drawing::Size(24, 23);
	this->label4->TabIndex = 7;
	this->label4->Text = S"Y";
	// 
	// label3
	// 
	this->label3->Enabled = false;
	this->label3->Location = System::Drawing::Point(8, 24);
	this->label3->Name = S"label3";
	this->label3->Size = System::Drawing::Size(24, 23);
	this->label3->TabIndex = 6;
	this->label3->Text = S"X";
	// 
	// textBox1
	// 
	this->textBox1->Enabled = false;
	this->textBox1->Location = System::Drawing::Point(32, 24);
	this->textBox1->Name = S"textBox1";
	this->textBox1->ReadOnly = true;
	this->textBox1->Size = System::Drawing::Size(64, 22);
	this->textBox1->TabIndex = 5;
	this->textBox1->Text = S"";
	// 
	// chkPosShowWin
	// 
	this->chkPosShowWin->Enabled = false;
	this->chkPosShowWin->Location = System::Drawing::Point(240, 24);
	this->chkPosShowWin->Name = S"chkPosShowWin";
	this->chkPosShowWin->Size = System::Drawing::Size(64, 24);
	this->chkPosShowWin->TabIndex = 4;
	this->chkPosShowWin->Text = S"Show";
	this->chkPosShowWin->CheckedChanged += new System::EventHandler(this, chkPosShowWin_CheckedChanged);
	// 
	// lblFontPattern
	// 
	this->lblFontPattern->BackColor = System::Drawing::SystemColors::HighlightText;
	this->lblFontPattern->Location = System::Drawing::Point(48, 8);
	this->lblFontPattern->Name = S"lblFontPattern";
	this->lblFontPattern->Size = System::Drawing::Size(304, 40);
	this->lblFontPattern->TabIndex = 14;
	this->lblFontPattern->Text = S"Text pattern";
	// 
	// btnFontSel
	// 
	this->btnFontSel->Location = System::Drawing::Point(360, 8);
	this->btnFontSel->Name = S"btnFontSel";
	this->btnFontSel->Size = System::Drawing::Size(24, 23);
	this->btnFontSel->TabIndex = 13;
	this->btnFontSel->Text = S"...";
	this->btnFontSel->Click += new System::EventHandler(this, btnFontSel_Click);
	// 
	// lblFont
	// 
	this->lblFont->Location = System::Drawing::Point(8, 8);
	this->lblFont->Name = S"lblFont";
	this->lblFont->Size = System::Drawing::Size(40, 23);
	this->lblFont->TabIndex = 12;
	this->lblFont->Text = S"Font";
	// 
	// tabPage2
	// 
	this->tabPage2->Controls->Add(this->label2);
	this->tabPage2->Controls->Add(this->label1);
	this->tabPage2->Controls->Add(this->edWordDur);
	this->tabPage2->Controls->Add(this->lblWordDur);
	this->tabPage2->Controls->Add(this->edWordDelay);
	this->tabPage2->Controls->Add(this->lblWordDelay);
	this->tabPage2->Location = System::Drawing::Point(4, 25);
	this->tabPage2->Name = S"tabPage2";
	this->tabPage2->Size = System::Drawing::Size(440, 259);
	this->tabPage2->TabIndex = 1;
	this->tabPage2->Text = S"Timing";
	// 
	// label2
	// 
	this->label2->Location = System::Drawing::Point(176, 48);
	this->label2->Name = S"label2";
	this->label2->Size = System::Drawing::Size(72, 23);
	this->label2->TabIndex = 5;
	this->label2->Text = S"seconds";
	this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
	// 
	// label1
	// 
	this->label1->Location = System::Drawing::Point(176, 8);
	this->label1->Name = S"label1";
	this->label1->Size = System::Drawing::Size(72, 23);
	this->label1->TabIndex = 4;
	this->label1->Text = S"seconds";
	this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
	// 
	// edWordDur
	// 
	this->edWordDur->Location = System::Drawing::Point(96, 48);
	System::Int32 __mcTemp__1[] = new System::Int32[4];
	__mcTemp__1[0] = 20;
	__mcTemp__1[1] = 0;
	__mcTemp__1[2] = 0;
	__mcTemp__1[3] = 0;
	this->edWordDur->Maximum = System::Decimal(__mcTemp__1);
	System::Int32 __mcTemp__2[] = new System::Int32[4];
	__mcTemp__2[0] = 3;
	__mcTemp__2[1] = 0;
	__mcTemp__2[2] = 0;
	__mcTemp__2[3] = 0;
	this->edWordDur->Minimum = System::Decimal(__mcTemp__2);
	this->edWordDur->Name = S"edWordDur";
	this->edWordDur->Size = System::Drawing::Size(64, 22);
	this->edWordDur->TabIndex = 3;
	System::Int32 __mcTemp__3[] = new System::Int32[4];
	__mcTemp__3[0] = 3;
	__mcTemp__3[1] = 0;
	__mcTemp__3[2] = 0;
	__mcTemp__3[3] = 0;
	this->edWordDur->Value = System::Decimal(__mcTemp__3);
	// 
	// lblWordDur
	// 
	this->lblWordDur->Location = System::Drawing::Point(8, 48);
	this->lblWordDur->Name = S"lblWordDur";
	this->lblWordDur->Size = System::Drawing::Size(72, 23);
	this->lblWordDur->TabIndex = 2;
	this->lblWordDur->Text = S"Duration";
	this->lblWordDur->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
	this->lblWordDur->Click += new System::EventHandler(this, lblWordDur_Click);
	// 
	// edWordDelay
	// 
	this->edWordDelay->Location = System::Drawing::Point(96, 8);
	System::Int32 __mcTemp__4[] = new System::Int32[4];
	__mcTemp__4[0] = 3600;
	__mcTemp__4[1] = 0;
	__mcTemp__4[2] = 0;
	__mcTemp__4[3] = 0;
	this->edWordDelay->Maximum = System::Decimal(__mcTemp__4);
	System::Int32 __mcTemp__5[] = new System::Int32[4];
	__mcTemp__5[0] = 5;
	__mcTemp__5[1] = 0;
	__mcTemp__5[2] = 0;
	__mcTemp__5[3] = 0;
	this->edWordDelay->Minimum = System::Decimal(__mcTemp__5);
	this->edWordDelay->Name = S"edWordDelay";
	this->edWordDelay->Size = System::Drawing::Size(64, 22);
	this->edWordDelay->TabIndex = 1;
	System::Int32 __mcTemp__6[] = new System::Int32[4];
	__mcTemp__6[0] = 5;
	__mcTemp__6[1] = 0;
	__mcTemp__6[2] = 0;
	__mcTemp__6[3] = 0;
	this->edWordDelay->Value = System::Decimal(__mcTemp__6);
	// 
	// lblWordDelay
	// 
	this->lblWordDelay->Location = System::Drawing::Point(8, 8);
	this->lblWordDelay->Name = S"lblWordDelay";
	this->lblWordDelay->Size = System::Drawing::Size(64, 23);
	this->lblWordDelay->TabIndex = 0;
	this->lblWordDelay->Text = S"Delay";
	this->lblWordDelay->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
	this->lblWordDelay->Click += new System::EventHandler(this, lblWordDelay_Click);
	// 
	// btnCancel
	// 
	this->btnCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
	this->btnCancel->Location = System::Drawing::Point(384, 304);
	this->btnCancel->Name = S"btnCancel";
	this->btnCancel->Size = System::Drawing::Size(72, 23);
	this->btnCancel->TabIndex = 22;
	this->btnCancel->Text = S"Cancel";
	this->btnCancel->Click += new System::EventHandler(this, btnCancel_Click);
	// 
	// btnOk
	// 
	this->btnOk->Location = System::Drawing::Point(304, 304);
	this->btnOk->Name = S"btnOk";
	this->btnOk->Size = System::Drawing::Size(72, 24);
	this->btnOk->TabIndex = 21;
	this->btnOk->Text = S"OK";
	this->btnOk->Click += new System::EventHandler(this, btnOK_Click);
	// 
	// FormSettings
	// 
	this->AcceptButton = this->btnOk;
	this->AutoScaleBaseSize = System::Drawing::Size(6, 15);
	this->CancelButton = this->btnCancel;
	this->ClientSize = System::Drawing::Size(466, 338);
	this->Controls->Add(this->btnCancel);
	this->Controls->Add(this->btnOk);
	this->Controls->Add(this->tabControl1);
	this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
	this->Icon = (__try_cast<System::Drawing::Icon *  >(resources->GetObject(S"$this.Icon")));
	this->MaximizeBox = false;
	this->MinimizeBox = false;
	this->Name = S"FormSettings";
	this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
	this->Text = S"Settings";
	this->tabControl1->ResumeLayout(false);
	this->tabPage1->ResumeLayout(false);
	this->groupBox1->ResumeLayout(false);
	this->tabPage2->ResumeLayout(false);
	(__try_cast<System::ComponentModel::ISupportInitialize *  >(this->edWordDur))->EndInit();
	(__try_cast<System::ComponentModel::ISupportInitialize *  >(this->edWordDelay))->EndInit();
	this->ResumeLayout(false);

}		




//--------------------------------------------------------------------------------------------------	
void chkPosShowWin_CheckedChanged(System::Object *sender, System::EventArgs *e)
{
	fm->Visible = chkPosShowWin->Checked;
}



//--------------------------------------------------------------------------------------------------	
void btnCancel_Click(System::Object *sender, System::EventArgs *e)
{
	Close();
}



//--------------------------------------------------------------------------------------------------	
void btnOK_Click(System::Object *sender, System::EventArgs *e)
{
	bool bThRst = true;

	// Setting font (if it had been changed)
	if (false == fm->lblWord->Font->Equals(lblFontPattern->Font)) {
		fm->pIniFont = lblFontPattern->Font;
		fm->lblWord->Font = fm->pIniFont;
	}
	// Setting font foreground color
	if (fm->lblWord->ForeColor != lblFontPattern->ForeColor)
		fm->lblWord->ForeColor = lblFontPattern->ForeColor;
	// Setting font background color
	if (fm->lblWord->BackColor != lblFontPattern->BackColor)
		fm->lblWord->BackColor = lblFontPattern->BackColor;

	// Setting word delay
	if (fm->iIniWordDelay != edWordDelay->Value) {
		fm->iIniWordDelay = (int)edWordDelay->Value;
		bThRst = true;
	}

	// Setting word duration
	if (fm->iIniWordDuration != edWordDur->Value) {
		fm->iIniWordDuration = (int)edWordDur->Value;
		bThRst = true;
	}

	// Reloading word list
	if (String::Compare(sWordListOld, edWordList->Text) != 0) {
		fm->sIniWordList = edWordList->Text;
		fm->LoadWordList(fm->sIniWordList);
		bThRst = true;
	}

	// Restarting word thread
	if (bThRst) {
		if (fm->bThRun)
			fm->StartStop();
		fm->StartStop();
	}
	Close();
}



//--------------------------------------------------------------------------------------------------	
void btnWordListSel_Click(System::Object *sender, System::EventArgs *e)
{
	OpenFileDialog *dlg = new OpenFileDialog();

	sprintf(sBuf, "%s", cstr(fm->sIniWordList));
	if (sBuf[1] != ':') {
		sprintf(sBuf, "%s\\%s", cstr(fm->sAppDir), cstr(fm->sIniWordList));
	}

	dlg->InitialDirectory = Path::GetDirectoryName(sBuf);
	dlg->FileName = Path::GetFileName(sBuf);
	dlg->Filter = LoadString(IDS_STRING114);
	dlg->FilterIndex = 2;

	if (dlg->ShowDialog() == DialogResult::OK) {
		edWordList->Text = dlg->FileName;
	}
}



//--------------------------------------------------------------------------------------------------	
void btnFontSel_Click(System::Object *sender, System::EventArgs *e)
{
	FontDialog *dlg = new FontDialog();

	dlg->ShowColor = true;
	dlg->Font = lblFontPattern->Font;
	dlg->Color = lblFontPattern->ForeColor;

	if (DialogResult::OK == dlg->ShowDialog()) {
		lblFontPattern->Font = dlg->Font;
		lblFontPattern->ForeColor = dlg->Color;
	}
}



//--------------------------------------------------------------------------------------------------	
void SetToolTip()
{
	// Set up the ToolTip text for two edit boxes
	toolTip1->SetToolTip(lblWordDelay, LoadString(IDS_STRING112));
	toolTip1->SetToolTip(lblWordDur, LoadString(IDS_STRING113));
}



//--------------------------------------------------------------------------------------------------	
private: void lblWordDelay_Click(System::Object *sender, System::EventArgs *e)
{
	edWordDelay->Focus();
}



//--------------------------------------------------------------------------------------------------	
private: void lblWordDur_Click(System::Object *sender, System::EventArgs *e)
{
	edWordDur->Focus();
}



//--------------------------------------------------------------------------------------------------	
private: System::Void btnColorSel_Click(System::Object *  sender, System::EventArgs *  e)
{
	ColorDialog *dlg = new ColorDialog();
      
	dlg->AllowFullOpen = true;
	dlg->Color = lblFontPattern->BackColor;
      
	// Update the text box color if the user selects OK 
	if (DialogResult::OK == dlg->ShowDialog()) {
		lblFontPattern->BackColor = dlg->Color;
	}
}

}; // class FormSettings
//} // namespace ShowWords
