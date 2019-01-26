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

#ifndef __FORMMAIN_H__
#define __FORMMAIN_H__

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Threading;
using namespace System::Text;
using namespace System::IO;



//namespace ShowWords { //
//--------------------------------------------------------------------------------------------------
public __gc class FormMain: public System::Windows::Forms::Form
{	
public:
	FormMain();
	void ThreadShowWord();
	void StartStop();
	void ReadIni();
	void WriteIni();
	int LoadWordList(String *);

	ArrayList *daWords;
	Thread *thShowWord;
	bool volatile bThRun;
	String *sTmp, *sAppDir;

	String *sIniWordList;
	System::Drawing::Font *pIniFont;
	int iIniWordDelay, iIniWordDuration;
private: System::Windows::Forms::MenuItem *  pmTrayDic;
private: System::Windows::Forms::MenuItem *  pmTrayDicOpen;
private: System::Windows::Forms::MenuItem *  pmTrayDicReload;
private: System::Windows::Forms::MenuItem *  pmTrayAbout;

protected:
	void Dispose(Boolean disposing);

private:
	void InitializeComponent(void);
	void pmTraySettings_Click(System::Object *, System::EventArgs *);
	void pmTrayExit_Click(System::Object *, System::EventArgs *);
	void FormMain_Load(System::Object *, System::EventArgs *);
	void FormMain_Closing(System::Object *, System::ComponentModel::CancelEventArgs *);
	void pmTrayAddWord_Click(System::Object *, System::EventArgs *);
	void pmDicOpen_Click(System::Object *, System::EventArgs *);
	void pmDicReload_Click(System::Object *, System::EventArgs *);
	void pmTrayAbout_Click(System::Object *, System::EventArgs *);

	System::ComponentModel::IContainer *components;
public: System::Windows::Forms::Label *lblWord;
	System::Windows::Forms::NotifyIcon *notifyIcon1;
	System::Windows::Forms::ContextMenu *pmTray;
	System::Windows::Forms::MenuItem *pmTrayAddWord;
	System::Windows::Forms::MenuItem *pmTraySettings;
	System::Windows::Forms::MenuItem *pmTraySep0;
	System::Windows::Forms::MenuItem *pmTrayExit;

	int iWordCntSh;
	static char __nogc *asDic[] = {"main", "left", "top", "word_list", "font",
		"word_delay", "word_duration", "bgcolor", "fgcolor", "Error"};
	static char __nogc *asSect[] = {asDic[0]};

}; // class FormMain
//} // namespace



#endif __FORMMAIN_H__
