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

#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


//namespace ShowWords {
	public __gc class FormAbout : public System::Windows::Forms::Form
	{
	public: 
		FormAbout(void)
		{
			InitializeComponent();
			Text = String::Concat(PRG_NAME, " - ", Text);
			edNameVer->Text = PRG_NAME " version " PRG_VER;
			lnkEmail->Text = PRG_AUTHOR;
			lnkUrl->Text = PRG_URL;
		}
        
	protected: 
		void Dispose(Boolean disposing)
		{
			if (disposing && components)
			{
				components->Dispose();
			}
			__super::Dispose(disposing);
		}


	private: System::Windows::Forms::Label *  label1;
	private: System::Windows::Forms::Label *  label2;
	private: System::Windows::Forms::Button *  btnOk;
	private: System::Windows::Forms::LinkLabel *  lnkEmail;
	private: System::Windows::Forms::LinkLabel *  lnkUrl;
	private: System::Windows::Forms::TextBox *  edNameVer;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container* components;

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Resources::ResourceManager *  resources = new System::Resources::ResourceManager(__typeof(FormAbout));
			this->edNameVer = new System::Windows::Forms::TextBox();
			this->label1 = new System::Windows::Forms::Label();
			this->label2 = new System::Windows::Forms::Label();
			this->lnkUrl = new System::Windows::Forms::LinkLabel();
			this->btnOk = new System::Windows::Forms::Button();
			this->lnkEmail = new System::Windows::Forms::LinkLabel();
			this->SuspendLayout();
			// 
			// edNameVer
			// 
			this->edNameVer->BackColor = System::Drawing::SystemColors::Control;
			this->edNameVer->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->edNameVer->Location = System::Drawing::Point(8, 8);
			this->edNameVer->Name = S"edNameVer";
			this->edNameVer->ReadOnly = true;
			this->edNameVer->Size = System::Drawing::Size(312, 15);
			this->edNameVer->TabIndex = 1;
			this->edNameVer->Text = S"";
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(8, 32);
			this->label1->Name = S"label1";
			this->label1->Size = System::Drawing::Size(72, 23);
			this->label1->TabIndex = 2;
			this->label1->Text = S"Written by";
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(8, 56);
			this->label2->Name = S"label2";
			this->label2->Size = System::Drawing::Size(80, 23);
			this->label2->TabIndex = 3;
			this->label2->Text = S"Home page";
			// 
			// lnkUrl
			// 
			this->lnkUrl->Location = System::Drawing::Point(96, 56);
			this->lnkUrl->Name = S"lnkUrl";
			this->lnkUrl->Size = System::Drawing::Size(192, 23);
			this->lnkUrl->TabIndex = 3;
			this->lnkUrl->TabStop = true;
			this->lnkUrl->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, lnkUrl_LinkClicked);
			// 
			// btnOk
			// 
			this->btnOk->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->btnOk->Location = System::Drawing::Point(136, 104);
			this->btnOk->Name = S"btnOk";
			this->btnOk->TabIndex = 0;
			this->btnOk->Text = S"OK";
			// 
			// lnkEmail
			// 
			this->lnkEmail->Location = System::Drawing::Point(96, 32);
			this->lnkEmail->Name = S"lnkEmail";
			this->lnkEmail->Size = System::Drawing::Size(192, 23);
			this->lnkEmail->TabIndex = 2;
			this->lnkEmail->TabStop = true;
			this->lnkEmail->Text = S"";
			this->lnkEmail->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, lnkEmail_LinkClicked);
			// 
			// FormAbout
			// 
			this->AcceptButton = this->btnOk;
			this->AutoScaleBaseSize = System::Drawing::Size(6, 15);
			this->ClientSize = System::Drawing::Size(344, 144);
			this->Controls->Add(this->lnkEmail);
			this->Controls->Add(this->btnOk);
			this->Controls->Add(this->lnkUrl);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->edNameVer);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (__try_cast<System::Drawing::Icon *  >(resources->GetObject(S"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = S"FormAbout";
			this->Text = S"About";
			this->ResumeLayout(false);

		}		




private: System::Void lnkEmail_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 System::Diagnostics::Process::Start("mailto:" PRG_EMAIL);
		 }

private: System::Void lnkUrl_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
		 System::Diagnostics::Process::Start(this->lnkUrl->Text);
		 }

}; // class FormAbout
//} // namespace ShowWords
