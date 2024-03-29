#pragma once

#include "FrmBanding.h"

namespace AntSimulatedAnnealing {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected: 
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  btnkeluar;

	private: System::Windows::Forms::Button^  btnPengembang;

	private: System::Windows::Forms::Button^  btnMasuk;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->btnkeluar = (gcnew System::Windows::Forms::Button());
			this->btnPengembang = (gcnew System::Windows::Forms::Button());
			this->btnMasuk = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Meiryo", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(10, 14);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(387, 36);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Perbandingan Performansi Hasil";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Meiryo", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Maroon;
			this->label2->Location = System::Drawing::Point(12, 50);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(442, 21);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Algoritma Ant System dan Algoritma Simulated Annealing";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Meiryo", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::MidnightBlue;
			this->label3->Location = System::Drawing::Point(13, 71);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(348, 21);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Untuk Penyelesaian Minimum Spanning Tree";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->btnkeluar);
			this->panel1->Controls->Add(this->btnPengembang);
			this->panel1->Controls->Add(this->btnMasuk);
			this->panel1->Location = System::Drawing::Point(8, 109);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(564, 277);
			this->panel1->TabIndex = 2;
			// 
			// btnkeluar
			// 
			this->btnkeluar->BackColor = System::Drawing::Color::Ivory;
			this->btnkeluar->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnkeluar->Location = System::Drawing::Point(188, 189);
			this->btnkeluar->Name = L"btnkeluar";
			this->btnkeluar->Size = System::Drawing::Size(160, 63);
			this->btnkeluar->TabIndex = 0;
			this->btnkeluar->Text = L"Keluar";
			this->btnkeluar->UseVisualStyleBackColor = false;
			this->btnkeluar->Click += gcnew System::EventHandler(this, &Form1::btnkeluar_Click);
			// 
			// btnPengembang
			// 
			this->btnPengembang->BackColor = System::Drawing::Color::Ivory;
			this->btnPengembang->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnPengembang->Location = System::Drawing::Point(188, 107);
			this->btnPengembang->Name = L"btnPengembang";
			this->btnPengembang->Size = System::Drawing::Size(160, 63);
			this->btnPengembang->TabIndex = 0;
			this->btnPengembang->Text = L"Pengembang";
			this->btnPengembang->UseVisualStyleBackColor = false;
			// 
			// btnMasuk
			// 
			this->btnMasuk->BackColor = System::Drawing::Color::Ivory;
			this->btnMasuk->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnMasuk->Location = System::Drawing::Point(188, 29);
			this->btnMasuk->Name = L"btnMasuk";
			this->btnMasuk->Size = System::Drawing::Size(160, 63);
			this->btnMasuk->TabIndex = 0;
			this->btnMasuk->Text = L"Masuk";
			this->btnMasuk->UseVisualStyleBackColor = false;
			this->btnMasuk->Click += gcnew System::EventHandler(this, &Form1::btnMasuk_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightGoldenrodYellow;
			this->ClientSize = System::Drawing::Size(584, 389);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Ant  dan Simulated Annealing";
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnkeluar_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Close();
				  
			 }
private: System::Void btnMasuk_Click(System::Object^  sender, System::EventArgs^  e) {
			 FrmBanding^ fBanding = gcnew FrmBanding();
			
			 fBanding->ShowDialog();
		 }
};
}

