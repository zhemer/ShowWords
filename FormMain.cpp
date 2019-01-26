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
#include "FormSettings.h"
#include "FormAddWord.h"
#include "FormAbout.h"
#include "iniFile.h"
using namespace std;

char sIniFile[_MAX_PATH];
CIniFile iniFile;



//--------------------------------------------------------------------------------------------------
// main
//--------------------------------------------------------------------------------------------------
int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	System::Threading::Thread::CurrentThread->ApartmentState = System::Threading::ApartmentState::STA;
	Application::Run(new FormMain());
	return 0;
}



//--------------------------------------------------------------------------------------------------
FormMain::FormMain()
{
	FileInfo* fileInfo = new FileInfo(Application::ExecutablePath);

	InitializeComponent();
	this->notifyIcon1->Text = PRG_NAME;
	this->Text = PRG_NAME;

	sIniWordList = new String("");
	sAppDir = new String("");
	sAppDir = fileInfo->DirectoryName;
	pIniFont = new System::Drawing::Font("Arial", 12);
	sTmp = new String("");

	daWords = new ArrayList();
	iWordCntSh = 0;

	ReadIni();
	if (RC_ERR == LoadWordList(sIniWordList))
		sIniWordList = "";
}



//--------------------------------------------------------------------------------------------------
void FormMain::Dispose(Boolean disposing)
{
	if (disposing && components) {
		components->Dispose();
	}
	__super::Dispose(disposing);
}



//--------------------------------------------------------------------------------------------------
void FormMain::InitializeComponent(void)
{
	this->components = new System::ComponentModel::Container();
	System::Resources::ResourceManager *  resources = new System::Resources::ResourceManager(__typeof(FormMain));
	this->lblWord = new System::Windows::Forms::Label();
	this->notifyIcon1 = new System::Windows::Forms::NotifyIcon(this->components);
	this->pmTray = new System::Windows::Forms::ContextMenu();
	this->pmTrayAddWord = new System::Windows::Forms::MenuItem();
	this->pmTraySettings = new System::Windows::Forms::MenuItem();
	this->pmTrayDic = new System::Windows::Forms::MenuItem();
	this->pmTrayDicOpen = new System::Windows::Forms::MenuItem();
	this->pmTrayDicReload = new System::Windows::Forms::MenuItem();
	this->pmTrayAbout = new System::Windows::Forms::MenuItem();
	this->pmTraySep0 = new System::Windows::Forms::MenuItem();
	this->pmTrayExit = new System::Windows::Forms::MenuItem();
	this->SuspendLayout();
	// 
	// lblWord
	// 
	this->lblWord->Anchor = (System::Windows::Forms::AnchorStyles)(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
		| System::Windows::Forms::AnchorStyles::Left) 
		| System::Windows::Forms::AnchorStyles::Right);
	this->lblWord->BackColor = System::Drawing::SystemColors::Info;
	this->lblWord->Font = new System::Drawing::Font(S"Arial", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)204);
	this->lblWord->Location = System::Drawing::Point(0, 0);
	this->lblWord->Name = S"lblWord";
	this->lblWord->Size = System::Drawing::Size(547, 117);
	this->lblWord->TabIndex = 0;
	// 
	// notifyIcon1
	// 
	this->notifyIcon1->ContextMenu = this->pmTray;
	this->notifyIcon1->Icon = (__try_cast<System::Drawing::Icon *>(resources->GetObject(S"notifyIcon1.Icon")));
	this->notifyIcon1->Text = S"";
	this->notifyIcon1->Visible = true;
	this->notifyIcon1->DoubleClick += new System::EventHandler(this, pmTraySettings_Click);
	// 
	// pmTray
	// 
	System::Windows::Forms::MenuItem* __mcTemp__1[] = new System::Windows::Forms::MenuItem*[6];
	__mcTemp__1[0] = this->pmTrayAddWord;
	__mcTemp__1[1] = this->pmTraySettings;
	__mcTemp__1[2] = this->pmTrayDic;
	__mcTemp__1[3] = this->pmTrayAbout;
	__mcTemp__1[4] = this->pmTraySep0;
	__mcTemp__1[5] = this->pmTrayExit;
	this->pmTray->MenuItems->AddRange(__mcTemp__1);
	// 
	// pmTrayAddWord
	// 
	this->pmTrayAddWord->Index = 0;
	this->pmTrayAddWord->Text = S"Add word...";
	this->pmTrayAddWord->Click += new System::EventHandler(this, pmTrayAddWord_Click);
	// 
	// pmTraySettings
	// 
	this->pmTraySettings->Index = 1;
	this->pmTraySettings->Text = S"Settings...";
	this->pmTraySettings->Click += new System::EventHandler(this, pmTraySettings_Click);
	// 
	// pmTrayDic
	// 
	this->pmTrayDic->Index = 2;
	System::Windows::Forms::MenuItem* __mcTemp__2[] = new System::Windows::Forms::MenuItem*[2];
	__mcTemp__2[0] = this->pmTrayDicOpen;
	__mcTemp__2[1] = this->pmTrayDicReload;
	this->pmTrayDic->MenuItems->AddRange(__mcTemp__2);
	this->pmTrayDic->Text = S"Dictionary";
	// 
	// pmTrayDicOpen
	// 
	this->pmTrayDicOpen->Index = 0;
	this->pmTrayDicOpen->Text = S"Open in notepad";
	this->pmTrayDicOpen->Click += new System::EventHandler(this, pmDicOpen_Click);
	// 
	// pmTrayDicReload
	// 
	this->pmTrayDicReload->Index = 1;
	this->pmTrayDicReload->Text = S"Reload";
	this->pmTrayDicReload->Click += new System::EventHandler(this, pmDicReload_Click);
	// 
	// pmTrayAbout
	// 
	this->pmTrayAbout->Index = 3;
	this->pmTrayAbout->Text = S"About...";
	this->pmTrayAbout->Click += new System::EventHandler(this, pmTrayAbout_Click);
	// 
	// pmTraySep0
	// 
	this->pmTraySep0->Index = 4;
	this->pmTraySep0->Text = S"-";
	// 
	// pmTrayExit
	// 
	this->pmTrayExit->Index = 5;
	this->pmTrayExit->Text = S"Exit";
	this->pmTrayExit->Click += new System::EventHandler(this, pmTrayExit_Click);
	// 
	// FormMain
	// 
	this->AutoScaleBaseSize = System::Drawing::Size(6, 15);
	this->ClientSize = System::Drawing::Size(100, 30);
	this->ControlBox = false;
	this->Controls->Add(this->lblWord);
	this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
	this->Icon = (__try_cast<System::Drawing::Icon *  >(resources->GetObject(S"$this.Icon")));
	this->MaximizeBox = false;
	this->Name = S"FormMain";
	this->ShowInTaskbar = false;
	this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
	this->TopMost = true;
	this->Closing += new System::ComponentModel::CancelEventHandler(this, FormMain_Closing);
	this->Load += new System::EventHandler(this, FormMain_Load);
	this->ResumeLayout(false);
}



//--------------------------------------------------------------------------------------------------
void FormMain::ThreadShowWord()
{
	int iWord = -1, iWait;
	String *sWord;
	Graphics *g = CreateGraphics();
	System::Drawing::Size sizeWord;

	lblWord->Font = pIniFont;

	if (daWords->Count < 1)
		goto lEnd;

	while (bThRun) {
		iWord++;
		if (iWord == daWords->Count)
			iWord = 0;

		sWord = daWords->get_Item(iWord)->ToString();
		sizeWord = g->MeasureString(sWord, pIniFont).ToSize();
		sizeWord.Width++;
		this->Size = sizeWord;
		lblWord->Size = sizeWord;

		lblWord->Text = sWord;
		this->Text = sWord;
		Visible = true;
		iWordCntSh++;
		sprintf(sBuf, PRG_NAME": %d/%d words were shown", iWordCntSh, (iWordCntSh-1)/daWords->Count + 1);
		notifyIcon1->Text = sBuf;

		// Duration of showing word
		iWait = iIniWordDuration;
		while (bThRun && iWait--)
			Thread::Sleep(1000);
		if (!bThRun)
			break;

		Visible = false;

		// Delay between words
		iWait = iIniWordDelay;
		while (bThRun && iWait--)
			Thread::Sleep(1000);

	}

lEnd:
	thShowWord = NULL;
}



//--------------------------------------------------------------------------------------------------
void FormMain::pmTrayExit_Click(System::Object *sender, System::EventArgs *e)
{
	Close();
}



//--------------------------------------------------------------------------------------------------
void FormMain::pmTraySettings_Click(System::Object *sender, System::EventArgs *e)
{
	notifyIcon1->DoubleClick -= new EventHandler(this, pmTraySettings_Click);
	pmTraySettings->Enabled = false;
	FormSettings *frm = new FormSettings(this);
	frm->ShowDialog();
	pmTraySettings->Enabled = true;
	notifyIcon1->DoubleClick += new EventHandler(this, pmTraySettings_Click);
}



//--------------------------------------------------------------------------------------------------
void FormMain::StartStop()
{
try {
	if (!bThRun) {
		if (sIniWordList == "")
			return;

		bThRun = true;
		thShowWord = new Thread(new ThreadStart(this, ThreadShowWord));
		thShowWord->Start();
	} else
		if (thShowWord) {
			thShowWord->Suspend();
			bThRun = false;
			thShowWord->Resume();
			thShowWord->Join();
			thShowWord = NULL;
		}

} catch(Exception *e) {
	mb(FN": %s", cstr(e->Message));
}
}



//--------------------------------------------------------------------------------------------------
void FormMain::ReadIni()
{
	Char cDelim[] = {','};
	String* sSplit[] = 0;
	IEnumerator* myEnum;
	unsigned char iR, iG, iB;

	iIniWordDelay = 5;
	iIniWordDuration = 3;
try {
	FileInfo* fileInfo = new FileInfo(Application::ExecutablePath);
	sprintf(sIniFile, "%s\\%s.ini", sAppDir, Path::GetFileNameWithoutExtension(Application::ExecutablePath));

	iniFile.Path(sIniFile);
	if (!iniFile.ReadFile())
		return;

	// Reading word window top-left position
	int x = iniFile.GetValueI(asSect[0], asDic[1], 1);
	int y = iniFile.GetValueI(asSect[0], asDic[2], 1);
	Location = Point(x, y);

	// Words List
	sIniWordList = iniFile.GetValue(asSect[0], asDic[3]).c_str();

	// Font
	sTmp = iniFile.GetValue(asSect[0], asDic[4]).c_str();
	sSplit = sTmp->Split(cDelim);
	myEnum = sSplit->GetEnumerator();
	// Font name
	myEnum->MoveNext();
	String *sName = new String("");
	sName = __try_cast<String*>(myEnum->Current);
	// Font size
	myEnum->MoveNext();
	int iSize = Convert::ToInt16(__try_cast<String*>(myEnum->Current));
	// Font style
	myEnum->MoveNext();
	int iStyle = Convert::ToInt16(__try_cast<String*>(myEnum->Current));
	pIniFont = new System::Drawing::Font(sName, (float)iSize, (FontStyle)iStyle);

	// Reading word background
	sTmp = iniFile.GetValue(asSect[0], asDic[7], "255,255,225").c_str();
	sSplit = sTmp->Split(cDelim);
	myEnum = sSplit->GetEnumerator();
	// Parsing background
	myEnum->MoveNext();
	iR = Convert::ToByte(__try_cast<String*>(myEnum->Current));
	myEnum->MoveNext();
	iG = Convert::ToByte(__try_cast<String*>(myEnum->Current));
	myEnum->MoveNext();
	iB = Convert::ToByte(__try_cast<String*>(myEnum->Current));
	// Setting word background's color
	lblWord->BackColor = Color::FromArgb(iR, iG, iB);

	// Reading word foreground
	sTmp = iniFile.GetValue(asSect[0], asDic[8], "0,0,0").c_str();
	sSplit = sTmp->Split(cDelim);
	myEnum = sSplit->GetEnumerator();
	// Parsing foreground
	myEnum->MoveNext();
	iR = Convert::ToByte(__try_cast<String*>(myEnum->Current));
	myEnum->MoveNext();
	iG = Convert::ToByte(__try_cast<String*>(myEnum->Current));
	myEnum->MoveNext();
	iB = Convert::ToByte(__try_cast<String*>(myEnum->Current));
	// Setting word foreground's color
	lblWord->ForeColor = Color::FromArgb(iR, iG, iB);

	// Reading "word_delay"
	iIniWordDelay = iniFile.GetValueI(asSect[0], asDic[5], 60);
	if (iIniWordDelay < 5)
		iIniWordDelay = 5;

	// Reading word duartion (word_duration)
	iIniWordDuration = iniFile.GetValueI(asSect[0], asDic[6], 10);
	if (iIniWordDuration < 3)
		iIniWordDuration = 3;

} catch(Exception *e) {
	mb(FN": %s", cstr(e->Message));
}
}



//--------------------------------------------------------------------------------------------------
void FormMain::WriteIni()
{
	// word_list
	sprintf(sBuf, "%s", cstr(sIniWordList));
	iniFile.SetValue(asSect[0], asDic[3], sBuf);

	// Saving word's font
	sprintf(sBuf, "%s,%d,%d", cstr(pIniFont->Name), (int)pIniFont->Size, (int)pIniFont->Style);
	iniFile.SetValue(asSect[0], asDic[4], sBuf);
	// Saving word's background
	sprintf(sBuf, "%d,%d,%d", lblWord->BackColor.R, lblWord->BackColor.G, lblWord->BackColor.B);
	iniFile.SetValue(asSect[0], asDic[7], sBuf);
	// Saving word's foreground
	sprintf(sBuf, "%d,%d,%d", lblWord->ForeColor.R, lblWord->ForeColor.G, lblWord->ForeColor.B);
	iniFile.SetValue(asSect[0], asDic[8], sBuf);

	// word_delay
	iniFile.SetValueI(asSect[0], asDic[5], iIniWordDelay);

	// word_duration
	iniFile.SetValueI(asSect[0], asDic[6], iIniWordDuration);

	iniFile.WriteFile();
}



//--------------------------------------------------------------------------------------------------
void FormMain::FormMain_Load(System::Object *sender, System::EventArgs *e)
{
	StartStop();
}



//--------------------------------------------------------------------------------------------------
int FormMain::LoadWordList(System::String *sFile)
{
	int rc = RC_OK;
	FILE *fd = NULL;
	String *sLine;

try {
	if (sFile->Length < 1) {
		throw new Exception(LoadString(IDS_STRING104));
	}

	if (!(fd = fopen(cstr(sFile), "r"))) {
		throw new Exception(sprintf1(LoadString(IDS_STRING105), cstr(sFile)));
	}
	daWords->Clear();

	sLine = new String("");
	while (fgets(sBuf, sizeof(sBuf), fd)) {
		sBuf[strlen(sBuf) - 1] = 0;
		sLine = sBuf;
		daWords->Add(sLine);
	}

} catch(Exception *e) {
	mb(FN": %s", cstr(e->Message));
	rc = RC_ERR;
}
	if (fd)
		fclose(fd);
lEnd:
	return rc;
}



//--------------------------------------------------------------------------------------------------
void FormMain::FormMain_Closing(System::Object *sender, System::ComponentModel::CancelEventArgs *e)
{
	if (thShowWord) {
//mb("thread is running");
		StartStop();
	}

	// Saving settings
	WriteIni();
}



//--------------------------------------------------------------------------------------------------
void FormMain::pmTrayAddWord_Click(System::Object *sender, System::EventArgs *e)
{
	pmTrayAddWord->Enabled = false;
	FormAddWord *frm = new FormAddWord(this);
	frm->ShowDialog();
	pmTrayAddWord->Enabled = true;
}



//--------------------------------------------------------------------------------------------------
void FormMain::pmDicOpen_Click(System::Object *sender, System::EventArgs *e)
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
    //DWORD ExitCode;
	char s[BUF_SIZE];

	ZeroMemory(&si, sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);
    si.wShowWindow = SW_SHOWNORMAL;

	sprintf(s, "notepad.exe %s", sIniWordList);
	if (CreateProcess(NULL, s, NULL, NULL,
					  FALSE, CREATE_DEFAULT_ERROR_MODE | IDLE_PRIORITY_CLASS,
					  NULL, NULL, &si, &pi) == TRUE) {
		CloseHandle(pi.hThread);
    }
}



//--------------------------------------------------------------------------------------------------
void FormMain::pmDicReload_Click(System::Object *sender, System::EventArgs *e)
{
	if (thShowWord)
		StartStop();
	LoadWordList(sIniWordList);
	StartStop();
}



//--------------------------------------------------------------------------------------------------
void FormMain::pmTrayAbout_Click(System::Object *sender, System::EventArgs *e)
{
	pmTrayAbout->Enabled = false;
	FormAbout *frm = new FormAbout();
	frm->ShowDialog();
	pmTrayAbout->Enabled = true;
}