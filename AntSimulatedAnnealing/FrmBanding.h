#pragma once

#include "SimulatedAnnealing.h"
#include "GraphDrawer.h"
#include "AntColony.h"
 

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Diagnostics;


namespace AntSimulatedAnnealing {

	/// <summary>
	/// Summary for FrmBanding
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class FrmBanding : public System::Windows::Forms::Form
	{
	public:
		array<double,2> ^jarakkota;
		int bykota ;
		bool mulaiupdate;
		Stopwatch^ sw;
		GraphDrawer ^gwsaawal;
		GraphDrawer ^gwsaakhir;
		GraphDrawer ^gwantawal;
		GraphDrawer ^gwantakhir;
		SimulatedAnnealing ^sa;
		AntColony ^antcol;
		bool sedangproses;
		array<int> ^bestroutesa;
        array<int> ^bestrouteant;
		array<int> ^initRouteSA;
		array<int> ^initRouteAnt;
	private: System::Windows::Forms::Label^  label17;
	public: 
	private: System::Windows::Forms::TextBox^  txtQ;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Timer^  timer2;
	private: System::Windows::Forms::Timer^  timer3;
	private: System::Windows::Forms::Timer^  timer4;
			 
           
		 

		 void updateJarak()
		{
			 //Mencari Jarak Euclidean Antara Posisi Kota
			 for(int i=0;i<bykota;i++)
			 {
				 for(int j=0;j<bykota;j++)
			     {
					 double d = Math::Sqrt(Math::Pow(posisikota[i]->X - posisikota[j]->X,2) + Math::Pow(posisikota[i]->Y - posisikota[j]->Y,2));
                     jarakkota[i,j] = d;                   
				 }
			 }
			 graph->setCityDistances(jarakkota);

             //Membuat Tabel Matrikx Jarak
			 lvMatrixJarak->Clear();
			 lvMatrixJarak->Columns->Add("");
			 for(int j=0;j<bykota;j++)
			 {
			    lvMatrixJarak->Columns->Add("Kota Ke-" + (j+1).ToString());                 
			 }

			 for(int j=0;j<bykota;j++)
			 {
				ListViewItem ^lvi = lvMatrixJarak->Items->Add("Kota Ke-" + (j+1).ToString());
				for(int i=0;i<bykota;i++)
				{
				  lvi->SubItems->Add(jarakkota[j,i].ToString());
				}
			 }
		}
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::TextBox^  txttempawal;
	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::TextBox^  txtDecT;
	private: System::Windows::Forms::TabControl^  tabControl3;
	private: System::Windows::Forms::TabPage^  tabPage5;








	private: System::Windows::Forms::TabPage^  tabPage6;
	private: System::Windows::Forms::Label^  lblwktuprosesant;

	private: System::Windows::Forms::Label^  lblpjruteant;

	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  lblruteterpendekant;

	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::PictureBox^  pbantawal;
	private: System::Windows::Forms::PictureBox^  pbantakhir;
	private: System::Windows::Forms::Label^  lblwktuprosessa;



	private: System::Windows::Forms::PictureBox^  pbsaakhir;


	private: System::Windows::Forms::PictureBox^  pbsaawal;


	private: System::Windows::Forms::Label^  lblpjrutesa;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Label^  lblrutesa;
	private: System::Windows::Forms::Label^  label18;
	public: 
          
        
		array<Point^> ^posisikota;
		Graph ^graph;

		FrmBanding(void)
		{
			InitializeComponent();
			bestroutesa=nullptr;
			bestrouteant = nullptr;
			sedangproses=false;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FrmBanding()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected: 
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  dataToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  prosesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  outputToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  tutupToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  baruToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  bukaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  simpanToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  tutupToolStripMenuItem1;
	private: System::Windows::Forms::Panel^  pnldata;

	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::TabControl^  tabControl2;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::TabPage^  tabPage4;
	private: System::Windows::Forms::DataGridView^  dgvKoordinat;
	private: System::Windows::Forms::ListView^  lvMatrixJarak;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::Button^  btnTambahTitik;

	private: System::Windows::Forms::TextBox^  txtJumlahTitik;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  txtbeta;

	private: System::Windows::Forms::TextBox^  txtalpha;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  txtrho;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
private: System::Windows::Forms::TextBox^  txtjumlahsemut;


	private: System::Windows::Forms::TextBox^  txtmakssiklus;


	private: System::Windows::Forms::TextBox^  txtmaxsukses;

	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  txtmiterasi;

	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  txtepsilon;

	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Panel^  pnlhasil;


















	private: System::Windows::Forms::Panel^  pnlOutputDetail;
private: System::Windows::Forms::GroupBox^  gbbanding;



	private: System::Windows::Forms::GroupBox^  groupBox4;
private: System::Windows::Forms::RichTextBox^  rtbSA;
private: System::Windows::Forms::RichTextBox^  rtbAnt;


	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
private: System::ComponentModel::IContainer^  components;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->baruToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->bukaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->simpanToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->tutupToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dataToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->prosesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->outputToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tutupToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pnldata = (gcnew System::Windows::Forms::Panel());
			this->tabControl2 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtjumlahsemut = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtQ = (gcnew System::Windows::Forms::TextBox());
			this->txtrho = (gcnew System::Windows::Forms::TextBox());
			this->txtmakssiklus = (gcnew System::Windows::Forms::TextBox());
			this->txtbeta = (gcnew System::Windows::Forms::TextBox());
			this->txtalpha = (gcnew System::Windows::Forms::TextBox());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->txtepsilon = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->txtDecT = (gcnew System::Windows::Forms::TextBox());
			this->txttempawal = (gcnew System::Windows::Forms::TextBox());
			this->txtmaxsukses = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->txtmiterasi = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->btnTambahTitik = (gcnew System::Windows::Forms::Button());
			this->txtJumlahTitik = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dgvKoordinat = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->lvMatrixJarak = (gcnew System::Windows::Forms::ListView());
			this->pnlhasil = (gcnew System::Windows::Forms::Panel());
			this->tabControl3 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->lblwktuprosessa = (gcnew System::Windows::Forms::Label());
			this->pbsaakhir = (gcnew System::Windows::Forms::PictureBox());
			this->pbsaawal = (gcnew System::Windows::Forms::PictureBox());
			this->lblpjrutesa = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->lblrutesa = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->tabPage6 = (gcnew System::Windows::Forms::TabPage());
			this->lblwktuprosesant = (gcnew System::Windows::Forms::Label());
			this->lblpjruteant = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->lblruteterpendekant = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->pbantakhir = (gcnew System::Windows::Forms::PictureBox());
			this->pbantawal = (gcnew System::Windows::Forms::PictureBox());
			this->pnlOutputDetail = (gcnew System::Windows::Forms::Panel());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->rtbAnt = (gcnew System::Windows::Forms::RichTextBox());
			this->rtbSA = (gcnew System::Windows::Forms::RichTextBox());
			this->gbbanding = (gcnew System::Windows::Forms::GroupBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer3 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer4 = (gcnew System::Windows::Forms::Timer(this->components));
			this->menuStrip1->SuspendLayout();
			this->pnldata->SuspendLayout();
			this->tabControl2->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->tabPage4->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvKoordinat))->BeginInit();
			this->tabPage2->SuspendLayout();
			this->pnlhasil->SuspendLayout();
			this->tabControl3->SuspendLayout();
			this->tabPage5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbsaakhir))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbsaawal))->BeginInit();
			this->tabPage6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbantakhir))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbantawal))->BeginInit();
			this->pnlOutputDetail->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->fileToolStripMenuItem, 
				this->dataToolStripMenuItem, this->prosesToolStripMenuItem, this->outputToolStripMenuItem, this->tutupToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(776, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->baruToolStripMenuItem, 
				this->bukaToolStripMenuItem, this->simpanToolStripMenuItem, this->toolStripMenuItem1, this->tutupToolStripMenuItem1});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// baruToolStripMenuItem
			// 
			this->baruToolStripMenuItem->Name = L"baruToolStripMenuItem";
			this->baruToolStripMenuItem->Size = System::Drawing::Size(114, 22);
			this->baruToolStripMenuItem->Text = L"Baru";
			// 
			// bukaToolStripMenuItem
			// 
			this->bukaToolStripMenuItem->Name = L"bukaToolStripMenuItem";
			this->bukaToolStripMenuItem->Size = System::Drawing::Size(114, 22);
			this->bukaToolStripMenuItem->Text = L"Buka";
			this->bukaToolStripMenuItem->Click += gcnew System::EventHandler(this, &FrmBanding::bukaToolStripMenuItem_Click);
			// 
			// simpanToolStripMenuItem
			// 
			this->simpanToolStripMenuItem->Name = L"simpanToolStripMenuItem";
			this->simpanToolStripMenuItem->Size = System::Drawing::Size(114, 22);
			this->simpanToolStripMenuItem->Text = L"Simpan";
			this->simpanToolStripMenuItem->Click += gcnew System::EventHandler(this, &FrmBanding::simpanToolStripMenuItem_Click);
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(111, 6);
			// 
			// tutupToolStripMenuItem1
			// 
			this->tutupToolStripMenuItem1->Name = L"tutupToolStripMenuItem1";
			this->tutupToolStripMenuItem1->Size = System::Drawing::Size(114, 22);
			this->tutupToolStripMenuItem1->Text = L"Tutup";
			this->tutupToolStripMenuItem1->Click += gcnew System::EventHandler(this, &FrmBanding::tutupToolStripMenuItem1_Click);
			// 
			// dataToolStripMenuItem
			// 
			this->dataToolStripMenuItem->Name = L"dataToolStripMenuItem";
			this->dataToolStripMenuItem->Size = System::Drawing::Size(43, 20);
			this->dataToolStripMenuItem->Text = L"Data";
			this->dataToolStripMenuItem->Click += gcnew System::EventHandler(this, &FrmBanding::dataToolStripMenuItem_Click);
			// 
			// prosesToolStripMenuItem
			// 
			this->prosesToolStripMenuItem->Name = L"prosesToolStripMenuItem";
			this->prosesToolStripMenuItem->Size = System::Drawing::Size(53, 20);
			this->prosesToolStripMenuItem->Text = L"Proses";
			this->prosesToolStripMenuItem->Click += gcnew System::EventHandler(this, &FrmBanding::prosesToolStripMenuItem_Click);
			// 
			// outputToolStripMenuItem
			// 
			this->outputToolStripMenuItem->Name = L"outputToolStripMenuItem";
			this->outputToolStripMenuItem->Size = System::Drawing::Size(90, 20);
			this->outputToolStripMenuItem->Text = L"Output Detail";
			this->outputToolStripMenuItem->Click += gcnew System::EventHandler(this, &FrmBanding::outputToolStripMenuItem_Click);
			// 
			// tutupToolStripMenuItem
			// 
			this->tutupToolStripMenuItem->Name = L"tutupToolStripMenuItem";
			this->tutupToolStripMenuItem->Size = System::Drawing::Size(51, 20);
			this->tutupToolStripMenuItem->Text = L"Tutup";
			this->tutupToolStripMenuItem->Click += gcnew System::EventHandler(this, &FrmBanding::tutupToolStripMenuItem_Click);
			// 
			// pnldata
			// 
			this->pnldata->BackColor = System::Drawing::Color::WhiteSmoke;
			this->pnldata->Controls->Add(this->tabControl2);
			this->pnldata->Controls->Add(this->tabControl1);
			this->pnldata->Location = System::Drawing::Point(12, 39);
			this->pnldata->Name = L"pnldata";
			this->pnldata->Size = System::Drawing::Size(754, 433);
			this->pnldata->TabIndex = 1;
			// 
			// tabControl2
			// 
			this->tabControl2->Controls->Add(this->tabPage3);
			this->tabControl2->Controls->Add(this->tabPage4);
			this->tabControl2->Location = System::Drawing::Point(17, 222);
			this->tabControl2->Name = L"tabControl2";
			this->tabControl2->SelectedIndex = 0;
			this->tabControl2->Size = System::Drawing::Size(726, 192);
			this->tabControl2->TabIndex = 1;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->label6);
			this->tabPage3->Controls->Add(this->label5);
			this->tabPage3->Controls->Add(this->label17);
			this->tabPage3->Controls->Add(this->label4);
			this->tabPage3->Controls->Add(this->label3);
			this->tabPage3->Controls->Add(this->txtjumlahsemut);
			this->tabPage3->Controls->Add(this->label2);
			this->tabPage3->Controls->Add(this->txtQ);
			this->tabPage3->Controls->Add(this->txtrho);
			this->tabPage3->Controls->Add(this->txtmakssiklus);
			this->tabPage3->Controls->Add(this->txtbeta);
			this->tabPage3->Controls->Add(this->txtalpha);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(718, 166);
			this->tabPage3->TabIndex = 0;
			this->tabPage3->Text = L"Parameter Ant";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(350, 103);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(88, 13);
			this->label6->TabIndex = 3;
			this->label6->Text = L"Maksimum Siklus";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(19, 99);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(73, 13);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Jumlah Semut";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(352, 45);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(15, 13);
			this->label17->TabIndex = 0;
			this->label17->Text = L"Q";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(19, 48);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(27, 13);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Rho";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(350, 19);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(29, 13);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Beta";
			// 
			// txtjumlahsemut
			// 
			this->txtjumlahsemut->Location = System::Drawing::Point(103, 96);
			this->txtjumlahsemut->Name = L"txtjumlahsemut";
			this->txtjumlahsemut->Size = System::Drawing::Size(129, 20);
			this->txtjumlahsemut->TabIndex = 2;
			this->txtjumlahsemut->Text = L"4";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(19, 22);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(34, 13);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Alpha";
			// 
			// txtQ
			// 
			this->txtQ->Location = System::Drawing::Point(472, 41);
			this->txtQ->Name = L"txtQ";
			this->txtQ->Size = System::Drawing::Size(129, 20);
			this->txtQ->TabIndex = 2;
			this->txtQ->Text = L"2";
			// 
			// txtrho
			// 
			this->txtrho->Location = System::Drawing::Point(103, 45);
			this->txtrho->Name = L"txtrho";
			this->txtrho->Size = System::Drawing::Size(129, 20);
			this->txtrho->TabIndex = 2;
			this->txtrho->Text = L"0,01";
			// 
			// txtmakssiklus
			// 
			this->txtmakssiklus->Location = System::Drawing::Point(472, 100);
			this->txtmakssiklus->Name = L"txtmakssiklus";
			this->txtmakssiklus->Size = System::Drawing::Size(129, 20);
			this->txtmakssiklus->TabIndex = 2;
			this->txtmakssiklus->Text = L"1000";
			// 
			// txtbeta
			// 
			this->txtbeta->Location = System::Drawing::Point(472, 19);
			this->txtbeta->Name = L"txtbeta";
			this->txtbeta->Size = System::Drawing::Size(129, 20);
			this->txtbeta->TabIndex = 2;
			this->txtbeta->Text = L"2";
			// 
			// txtalpha
			// 
			this->txtalpha->Location = System::Drawing::Point(103, 22);
			this->txtalpha->Name = L"txtalpha";
			this->txtalpha->Size = System::Drawing::Size(129, 20);
			this->txtalpha->TabIndex = 2;
			this->txtalpha->Text = L"3";
			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->label23);
			this->tabPage4->Controls->Add(this->label22);
			this->tabPage4->Controls->Add(this->txtepsilon);
			this->tabPage4->Controls->Add(this->label9);
			this->tabPage4->Controls->Add(this->txtDecT);
			this->tabPage4->Controls->Add(this->txttempawal);
			this->tabPage4->Controls->Add(this->txtmaxsukses);
			this->tabPage4->Controls->Add(this->label8);
			this->tabPage4->Controls->Add(this->txtmiterasi);
			this->tabPage4->Controls->Add(this->label7);
			this->tabPage4->Location = System::Drawing::Point(4, 22);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(3);
			this->tabPage4->Size = System::Drawing::Size(718, 166);
			this->tabPage4->TabIndex = 1;
			this->tabPage4->Text = L"Parameter Simulated Annealing";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(241, 68);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(72, 13);
			this->label23->TabIndex = 4;
			this->label23->Text = L"Alpha / DecT";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(241, 21);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(87, 13);
			this->label22->TabIndex = 4;
			this->label22->Text = L"Temperatur Awal";
			// 
			// txtepsilon
			// 
			this->txtepsilon->Location = System::Drawing::Point(14, 131);
			this->txtepsilon->Name = L"txtepsilon";
			this->txtepsilon->Size = System::Drawing::Size(156, 20);
			this->txtepsilon->TabIndex = 3;
			this->txtepsilon->Text = L"0,01";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(11, 115);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(93, 13);
			this->label9->TabIndex = 2;
			this->label9->Text = L"Threshold/Epsilon";
			// 
			// txtDecT
			// 
			this->txtDecT->Location = System::Drawing::Point(244, 84);
			this->txtDecT->Name = L"txtDecT";
			this->txtDecT->Size = System::Drawing::Size(228, 20);
			this->txtDecT->TabIndex = 1;
			this->txtDecT->Text = L"0,999";
			// 
			// txttempawal
			// 
			this->txttempawal->Location = System::Drawing::Point(244, 37);
			this->txttempawal->Name = L"txttempawal";
			this->txttempawal->Size = System::Drawing::Size(228, 20);
			this->txttempawal->TabIndex = 1;
			this->txttempawal->Text = L"400";
			// 
			// txtmaxsukses
			// 
			this->txtmaxsukses->Location = System::Drawing::Point(14, 84);
			this->txtmaxsukses->Name = L"txtmaxsukses";
			this->txtmaxsukses->Size = System::Drawing::Size(156, 20);
			this->txtmaxsukses->TabIndex = 1;
			this->txtmaxsukses->Text = L"100";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(12, 68);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(95, 13);
			this->label8->TabIndex = 0;
			this->label8->Text = L"Maksimum Sukses";
			// 
			// txtmiterasi
			// 
			this->txtmiterasi->Location = System::Drawing::Point(15, 37);
			this->txtmiterasi->Name = L"txtmiterasi";
			this->txtmiterasi->Size = System::Drawing::Size(155, 20);
			this->txtmiterasi->TabIndex = 1;
			this->txtmiterasi->Text = L"1000";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(12, 21);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(88, 13);
			this->label7->TabIndex = 0;
			this->label7->Text = L"Maksimum Iterasi";
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(13, 9);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(734, 208);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->btnTambahTitik);
			this->tabPage1->Controls->Add(this->txtJumlahTitik);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->dgvKoordinat);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(726, 182);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Koordinat";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// btnTambahTitik
			// 
			this->btnTambahTitik->Location = System::Drawing::Point(163, 21);
			this->btnTambahTitik->Name = L"btnTambahTitik";
			this->btnTambahTitik->Size = System::Drawing::Size(94, 38);
			this->btnTambahTitik->TabIndex = 3;
			this->btnTambahTitik->Text = L"Tambah";
			this->btnTambahTitik->UseVisualStyleBackColor = true;
			this->btnTambahTitik->Click += gcnew System::EventHandler(this, &FrmBanding::btnTambahTitik_Click);
			// 
			// txtJumlahTitik
			// 
			this->txtJumlahTitik->Location = System::Drawing::Point(18, 31);
			this->txtJumlahTitik->Name = L"txtJumlahTitik";
			this->txtJumlahTitik->Size = System::Drawing::Size(129, 20);
			this->txtJumlahTitik->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(14, 14);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(63, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Jumlah Titik";
			// 
			// dgvKoordinat
			// 
			this->dgvKoordinat->AllowUserToAddRows = false;
			this->dgvKoordinat->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvKoordinat->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {this->Column1, 
				this->Column2, this->Column3});
			this->dgvKoordinat->Location = System::Drawing::Point(338, 9);
			this->dgvKoordinat->Name = L"dgvKoordinat";
			this->dgvKoordinat->Size = System::Drawing::Size(382, 157);
			this->dgvKoordinat->TabIndex = 0;
			this->dgvKoordinat->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &FrmBanding::dgvKoordinat_CellValueChanged);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Kota";
			this->Column1->Name = L"Column1";
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"X";
			this->Column2->Name = L"Column2";
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Y";
			this->Column3->Name = L"Column3";
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->lvMatrixJarak);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(726, 182);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Matrix Jarak";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// lvMatrixJarak
			// 
			this->lvMatrixJarak->FullRowSelect = true;
			this->lvMatrixJarak->GridLines = true;
			this->lvMatrixJarak->Location = System::Drawing::Point(6, 6);
			this->lvMatrixJarak->Name = L"lvMatrixJarak";
			this->lvMatrixJarak->Size = System::Drawing::Size(714, 173);
			this->lvMatrixJarak->TabIndex = 0;
			this->lvMatrixJarak->UseCompatibleStateImageBehavior = false;
			this->lvMatrixJarak->View = System::Windows::Forms::View::Details;
			// 
			// pnlhasil
			// 
			this->pnlhasil->Controls->Add(this->tabControl3);
			this->pnlhasil->Location = System::Drawing::Point(12, 35);
			this->pnlhasil->Name = L"pnlhasil";
			this->pnlhasil->Size = System::Drawing::Size(760, 442);
			this->pnlhasil->TabIndex = 2;
			this->pnlhasil->Visible = false;
			// 
			// tabControl3
			// 
			this->tabControl3->Controls->Add(this->tabPage5);
			this->tabControl3->Controls->Add(this->tabPage6);
			this->tabControl3->Location = System::Drawing::Point(6, 13);
			this->tabControl3->Name = L"tabControl3";
			this->tabControl3->SelectedIndex = 0;
			this->tabControl3->Size = System::Drawing::Size(754, 436);
			this->tabControl3->TabIndex = 1;
			// 
			// tabPage5
			// 
			this->tabPage5->Controls->Add(this->lblwktuprosessa);
			this->tabPage5->Controls->Add(this->pbsaakhir);
			this->tabPage5->Controls->Add(this->pbsaawal);
			this->tabPage5->Controls->Add(this->lblpjrutesa);
			this->tabPage5->Controls->Add(this->label16);
			this->tabPage5->Controls->Add(this->label19);
			this->tabPage5->Controls->Add(this->lblrutesa);
			this->tabPage5->Controls->Add(this->label18);
			this->tabPage5->Location = System::Drawing::Point(4, 22);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Padding = System::Windows::Forms::Padding(3);
			this->tabPage5->Size = System::Drawing::Size(746, 410);
			this->tabPage5->TabIndex = 0;
			this->tabPage5->Text = L"Simulated Annealing";
			this->tabPage5->UseVisualStyleBackColor = true;
			// 
			// lblwktuprosessa
			// 
			this->lblwktuprosessa->AutoSize = true;
			this->lblwktuprosessa->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblwktuprosessa->ForeColor = System::Drawing::Color::DodgerBlue;
			this->lblwktuprosessa->Location = System::Drawing::Point(652, 385);
			this->lblwktuprosessa->Name = L"lblwktuprosessa";
			this->lblwktuprosessa->Size = System::Drawing::Size(14, 13);
			this->lblwktuprosessa->TabIndex = 7;
			this->lblwktuprosessa->Text = L"0";
			// 
			// pbsaakhir
			// 
			this->pbsaakhir->BackColor = System::Drawing::Color::Black;
			this->pbsaakhir->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pbsaakhir->Location = System::Drawing::Point(378, 3);
			this->pbsaakhir->Name = L"pbsaakhir";
			this->pbsaakhir->Size = System::Drawing::Size(362, 365);
			this->pbsaakhir->TabIndex = 3;
			this->pbsaakhir->TabStop = false;
			this->pbsaakhir->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmBanding::pbsaakhir_Paint);
			// 
			// pbsaawal
			// 
			this->pbsaawal->BackColor = System::Drawing::Color::Black;
			this->pbsaawal->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pbsaawal->Location = System::Drawing::Point(6, 3);
			this->pbsaawal->Name = L"pbsaawal";
			this->pbsaawal->Size = System::Drawing::Size(366, 365);
			this->pbsaawal->TabIndex = 3;
			this->pbsaawal->TabStop = false;
			this->pbsaawal->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmBanding::pbsaawal_Paint);
			// 
			// lblpjrutesa
			// 
			this->lblpjrutesa->AutoSize = true;
			this->lblpjrutesa->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblpjrutesa->ForeColor = System::Drawing::Color::DodgerBlue;
			this->lblpjrutesa->Location = System::Drawing::Point(414, 385);
			this->lblpjrutesa->Name = L"lblpjrutesa";
			this->lblpjrutesa->Size = System::Drawing::Size(14, 13);
			this->lblpjrutesa->TabIndex = 9;
			this->lblpjrutesa->Text = L"0";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label16->Location = System::Drawing::Point(9, 387);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(99, 13);
			this->label16->TabIndex = 6;
			this->label16->Text = L"Rute Terpendek";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label19->Location = System::Drawing::Point(560, 385);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(86, 13);
			this->label19->TabIndex = 5;
			this->label19->Text = L"Waktu Proses";
			// 
			// lblrutesa
			// 
			this->lblrutesa->AutoSize = true;
			this->lblrutesa->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblrutesa->ForeColor = System::Drawing::Color::DodgerBlue;
			this->lblrutesa->Location = System::Drawing::Point(114, 387);
			this->lblrutesa->Name = L"lblrutesa";
			this->lblrutesa->Size = System::Drawing::Size(14, 13);
			this->lblrutesa->TabIndex = 8;
			this->lblrutesa->Text = L"0";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label18->Location = System::Drawing::Point(314, 385);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(84, 13);
			this->label18->TabIndex = 4;
			this->label18->Text = L"Panjang Rute";
			// 
			// tabPage6
			// 
			this->tabPage6->Controls->Add(this->lblwktuprosesant);
			this->tabPage6->Controls->Add(this->lblpjruteant);
			this->tabPage6->Controls->Add(this->label14);
			this->tabPage6->Controls->Add(this->label12);
			this->tabPage6->Controls->Add(this->lblruteterpendekant);
			this->tabPage6->Controls->Add(this->label10);
			this->tabPage6->Controls->Add(this->pbantakhir);
			this->tabPage6->Controls->Add(this->pbantawal);
			this->tabPage6->Location = System::Drawing::Point(4, 22);
			this->tabPage6->Name = L"tabPage6";
			this->tabPage6->Padding = System::Windows::Forms::Padding(3);
			this->tabPage6->Size = System::Drawing::Size(746, 410);
			this->tabPage6->TabIndex = 1;
			this->tabPage6->Text = L"Ant Colony";
			this->tabPage6->UseVisualStyleBackColor = true;
			// 
			// lblwktuprosesant
			// 
			this->lblwktuprosesant->AutoSize = true;
			this->lblwktuprosesant->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblwktuprosesant->ForeColor = System::Drawing::Color::DodgerBlue;
			this->lblwktuprosesant->Location = System::Drawing::Point(649, 382);
			this->lblwktuprosesant->Name = L"lblwktuprosesant";
			this->lblwktuprosesant->Size = System::Drawing::Size(14, 13);
			this->lblwktuprosesant->TabIndex = 7;
			this->lblwktuprosesant->Text = L"0";
			// 
			// lblpjruteant
			// 
			this->lblpjruteant->AutoSize = true;
			this->lblpjruteant->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblpjruteant->ForeColor = System::Drawing::Color::DodgerBlue;
			this->lblpjruteant->Location = System::Drawing::Point(419, 388);
			this->lblpjruteant->Name = L"lblpjruteant";
			this->lblpjruteant->Size = System::Drawing::Size(14, 13);
			this->lblpjruteant->TabIndex = 8;
			this->lblpjruteant->Text = L"0";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label14->Location = System::Drawing::Point(546, 382);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(86, 13);
			this->label14->TabIndex = 6;
			this->label14->Text = L"Waktu Proses";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(316, 388);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(84, 13);
			this->label12->TabIndex = 4;
			this->label12->Text = L"Panjang Rute";
			// 
			// lblruteterpendekant
			// 
			this->lblruteterpendekant->AutoSize = true;
			this->lblruteterpendekant->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblruteterpendekant->ForeColor = System::Drawing::Color::DodgerBlue;
			this->lblruteterpendekant->Location = System::Drawing::Point(111, 389);
			this->lblruteterpendekant->Name = L"lblruteterpendekant";
			this->lblruteterpendekant->Size = System::Drawing::Size(14, 13);
			this->lblruteterpendekant->TabIndex = 9;
			this->lblruteterpendekant->Text = L"0";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(8, 388);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(99, 13);
			this->label10->TabIndex = 5;
			this->label10->Text = L"Rute Terpendek";
			// 
			// pbantakhir
			// 
			this->pbantakhir->BackColor = System::Drawing::Color::Black;
			this->pbantakhir->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pbantakhir->Location = System::Drawing::Point(374, 5);
			this->pbantakhir->Name = L"pbantakhir";
			this->pbantakhir->Size = System::Drawing::Size(365, 365);
			this->pbantakhir->TabIndex = 3;
			this->pbantakhir->TabStop = false;
			this->pbantakhir->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmBanding::pbantakhir_Paint);
			// 
			// pbantawal
			// 
			this->pbantawal->BackColor = System::Drawing::Color::Black;
			this->pbantawal->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pbantawal->Location = System::Drawing::Point(3, 5);
			this->pbantawal->Name = L"pbantawal";
			this->pbantawal->Size = System::Drawing::Size(365, 365);
			this->pbantawal->TabIndex = 3;
			this->pbantawal->TabStop = false;
			this->pbantawal->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmBanding::pbantawal_Paint);
			// 
			// pnlOutputDetail
			// 
			this->pnlOutputDetail->Controls->Add(this->groupBox4);
			this->pnlOutputDetail->Controls->Add(this->gbbanding);
			this->pnlOutputDetail->Location = System::Drawing::Point(12, 35);
			this->pnlOutputDetail->Name = L"pnlOutputDetail";
			this->pnlOutputDetail->Size = System::Drawing::Size(757, 437);
			this->pnlOutputDetail->TabIndex = 3;
			this->pnlOutputDetail->Visible = false;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->rtbAnt);
			this->groupBox4->Controls->Add(this->rtbSA);
			this->groupBox4->Location = System::Drawing::Point(18, 201);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(729, 225);
			this->groupBox4->TabIndex = 1;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Rincian Per Siklus / Materi";
			// 
			// rtbAnt
			// 
			this->rtbAnt->Location = System::Drawing::Point(10, 125);
			this->rtbAnt->Name = L"rtbAnt";
			this->rtbAnt->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->rtbAnt->Size = System::Drawing::Size(709, 92);
			this->rtbAnt->TabIndex = 0;
			this->rtbAnt->Text = L"";
			// 
			// rtbSA
			// 
			this->rtbSA->Location = System::Drawing::Point(10, 20);
			this->rtbSA->Name = L"rtbSA";
			this->rtbSA->Size = System::Drawing::Size(709, 92);
			this->rtbSA->TabIndex = 0;
			this->rtbSA->Text = L"";
			// 
			// gbbanding
			// 
			this->gbbanding->Location = System::Drawing::Point(22, 15);
			this->gbbanding->Name = L"gbbanding";
			this->gbbanding->Size = System::Drawing::Size(725, 183);
			this->gbbanding->TabIndex = 0;
			this->gbbanding->TabStop = false;
			this->gbbanding->Text = L"Grafik Perbandingan Waktu Ant System dan Simulated Annealing";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// timer1
			// 
			this->timer1->Interval = 10;
			this->timer1->Tick += gcnew System::EventHandler(this, &FrmBanding::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Interval = 10;
			this->timer2->Tick += gcnew System::EventHandler(this, &FrmBanding::timer2_Tick);
			// 
			// timer3
			// 
			this->timer3->Tick += gcnew System::EventHandler(this, &FrmBanding::timer3_Tick);
			// 
			// timer4
			// 
			this->timer4->Tick += gcnew System::EventHandler(this, &FrmBanding::timer4_Tick);
			// 
			// FrmBanding
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(776, 481);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->pnldata);
			this->Controls->Add(this->pnlhasil);
			this->Controls->Add(this->pnlOutputDetail);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"FrmBanding";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Perbandingan Hasil";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->pnldata->ResumeLayout(false);
			this->tabControl2->ResumeLayout(false);
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->tabPage4->ResumeLayout(false);
			this->tabPage4->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvKoordinat))->EndInit();
			this->tabPage2->ResumeLayout(false);
			this->pnlhasil->ResumeLayout(false);
			this->tabControl3->ResumeLayout(false);
			this->tabPage5->ResumeLayout(false);
			this->tabPage5->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbsaakhir))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbsaawal))->EndInit();
			this->tabPage6->ResumeLayout(false);
			this->tabPage6->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbantakhir))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbantawal))->EndInit();
			this->pnlOutputDetail->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void tutupToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
private: System::Void tutupToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }


private: System::Void prosesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (txtmaxsukses->Text=="" || txtmiterasi->Text=="" || txtDecT->Text=="" || txtmiterasi->Text=="" || txtepsilon->Text=="" || txttempawal->Text=="")
			 {
				 MessageBox::Show("Parameter Simulated Annealing Masih Ada yang kosong!","Belum Lengkap",MessageBoxButtons::OK,MessageBoxIcon::Warning);
			 }
			 else
			 {
				 if (txtalpha->Text=="" || txtbeta->Text=="" || txtrho->Text=="" || txtQ->Text =="" || txtjumlahsemut->Text=="" || txtmakssiklus->Text=="")
				 {
                       MessageBox::Show("Parameter Ant Colony Masih Ada yang kosong!","Belum Lengkap",MessageBoxButtons::OK,MessageBoxIcon::Warning);
					
				 }else{
					 if (sedangproses==false) {
					 if (bykota > 1) {
						double mxiterasi = Convert::ToDouble(txtmiterasi->Text);
						double maxsukses = Convert::ToDouble(txtmaxsukses->Text);
						double alpha = Convert::ToDouble(txtDecT->Text);
						double t0 = Convert::ToDouble(txttempawal->Text);
						double epsilon = Convert::ToDouble(txtepsilon->Text);               
						pnlhasil->Visible=true;
						pnldata->Visible=false;
						pnlOutputDetail->Visible=false;
						sedangproses = true;
						//Menjalankan Simulated Annealing
						this->Text = "Perbandingan Hasil -> Sedang Menjalankan Simulated Annealing ....";

						sa = gcnew SimulatedAnnealing(graph, jarakkota,mxiterasi,maxsukses,alpha,t0,epsilon,posisikota->Length);
						timer1->Enabled=true;
						initRouteSA = sa->InitRoute();
						initRouteAnt = sa->InitRoute();
						sw=gcnew Stopwatch();
						timer3->Enabled=true;
						sw->Start(); 
						sa->StartAnnealing(rtbSA);
						lblpjrutesa->Text=sa->GetShortestDistance().ToString();
						lblrutesa->Text = sa->ShowBestRoute();
						bestroutesa = sa->GetBestRoute();
						pbsaakhir->Invalidate();
						this->Text = "Perbandingan Hasil -> Simulated Annealing Selesai Dijalankan";
						Application::DoEvents();
						timer1->Enabled =false;
						sw->Stop();
						timer3->Enabled=false;
						System::Threading::Thread::Sleep(3000);
						//Menjalankan Ant Colony
						

						this->Text = "Perbandingan Hasil -> Sedang Menjalankan Ant Colony .... ";
						double alphaant = Convert::ToDouble(txtalpha->Text);
						double beta = Convert::ToDouble(txtbeta->Text);
						double rho = Convert::ToDouble(txtrho->Text);
						double Q = Convert::ToDouble(txtQ->Text);
						int maxants = Convert::ToInt16(txtjumlahsemut->Text);
						int maxsiklus = Convert::ToInt16(txtmakssiklus->Text);

						antcol = gcnew AntColony(alphaant,beta,rho,Q,maxants,bykota,maxsiklus );
						array<array<int >^ > ^jarakkotaaco;
						jarakkotaaco =gcnew array<array<int > ^ >(bykota);
						for(int i=0;i<bykota;i++)
						{
							jarakkotaaco[i] = gcnew array<int>(bykota);
						} 
					
							
			
						for(int i=0;i<bykota;i++)
						{
							 for(int j=0;j<bykota;j++)
							{					  
								jarakkotaaco[i][j] =  jarakkota[i,j];
                   
							 }
						 }

						antcol->SetGraphDistances(jarakkotaaco);
						timer2->Enabled = true;
						sw->Reset();
						sw->Start();
						timer4->Enabled = true;
						antcol->runAntColony(rtbAnt);
						bestrouteant = antcol->GetBestTrail(); 
						lblpjruteant->Text = antcol->GetBestTrailDistance().ToString();
						lblruteterpendekant->Text = antcol->ShowBestRoute();
						pbantakhir->Invalidate();
						this->Text = "Perbandingan Hasil ->  Ant Colony Berhasil Dijalankan.... ";
						timer2->Enabled =false;
						sw->Stop();
                        timer4->Enabled  =false;


					 }else{
						MessageBox::Show("Belum Ada Node(Graph) Kota!","Belum Lengkap",MessageBoxButtons::OK,MessageBoxIcon::Warning);
					 }
					 }else{
                        pnlhasil->Visible=true;
						pnldata->Visible=false;
						pnlOutputDetail->Visible=false;
					 }
					
				 }

			 }
		 }
private: System::Void outputToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 pnlOutputDetail->Visible=true; 
			 pnlhasil->Visible=false;
			 pnldata->Visible=false;
				 
		 }
private: System::Void dataToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			  pnldata->Visible=true;
			  pnlhasil->Visible=false;
			  pnlOutputDetail->Visible=false;
		 }
private: System::Void bukaToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 openFileDialog1->ShowDialog();
		 }
private: System::Void simpanToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 saveFileDialog1->ShowDialog();
		 }

private: System::Void btnTambahTitik_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 Random ^rand =gcnew Random();
			 int minRandom = 0;
			 int maxRandom = 100;
			 bykota = Convert::ToUInt16(txtJumlahTitik->Text);
			 posisikota = gcnew array<Point^>(bykota);			 
			 jarakkota = gcnew array<double,2>(bykota,bykota);
			 
			 dgvKoordinat->Rows->Clear();
			 graph = gcnew Graph(bykota);
			 for(int i=0;i<bykota;i++)
			 {
				 dgvKoordinat->Rows->Add();

				 posisikota[i] = gcnew Point();
				 posisikota[i]->X = rand->Next(minRandom,maxRandom);
				 posisikota[i]->Y = rand->Next(minRandom,maxRandom);

                 CityNode ^cn = gcnew CityNode( posisikota[i]);
				 graph->addCityNode(cn);

				 dgvKoordinat->Rows[i]->Cells[0]->Value = (i+1).ToString();
				 dgvKoordinat->Rows[i]->Cells[1]->Value = posisikota[i]->X.ToString();
				 dgvKoordinat->Rows[i]->Cells[2]->Value = posisikota[i]->Y.ToString();
			 }
			 
			updateJarak();
			graph->createGraph();
            mulaiupdate =true;


		 }
private: System::Void dgvKoordinat_CellValueChanged(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
			 if (mulaiupdate)
			 {
			    //MessageBox::Show("Berubah");
                 for(int i=0;i<bykota;i++)
			     {
					 
					 
					 posisikota[i]->X =  Convert::ToInt16(dgvKoordinat->Rows[i]->Cells[1]->Value);
					 posisikota[i]->Y = Convert::ToInt16(dgvKoordinat->Rows[i]->Cells[2]->Value);

					 
			    }				  
				 updateJarak();
			 }
		 }
private: System::Void pbsaawal_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 if (mulaiupdate){
				 gwsaawal = gcnew GraphDrawer("Graph Sebelum:",e->Graphics,pbsaawal->Height,pbsaawal->Width,100,100,graph);
				 gwsaawal->DrawNodesTrail(posisikota, initRouteSA);
			 }
		 }
private: System::Void pbsaakhir_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
             if (mulaiupdate)
			 {
				 gwsaakhir = gcnew GraphDrawer("Graph Sesudah:",e->Graphics,pbsaakhir->Height,pbsaakhir->Width,100,100,graph);
				gwsaakhir->DrawNodesTrail(posisikota,bestroutesa);
			 }
		 }
private: System::Void pbantawal_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			  if (mulaiupdate)
			 {
				 gwantawal = gcnew GraphDrawer("Graph Sebelum:",e->Graphics,pbantawal->Height,pbantawal->Width,100,100,graph);
				 gwantawal->DrawNodesTrail(posisikota,initRouteAnt);
			 }
		 }
private: System::Void pbantakhir_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			  if (mulaiupdate)
			 {
				 gwantakhir = gcnew GraphDrawer("Graph Sesudah:",e->Graphics,pbantakhir->Height,pbantakhir->Width,100,100,graph);
				 gwantakhir->DrawNodesTrail(posisikota,bestrouteant);
			 }
		 }
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			 if (sa->GetBestRoute()!=nullptr){
			    bestroutesa = sa->GetBestRoute();
			    pbsaakhir->Invalidate();
			 }
		 }
private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) {
			  if (antcol->GetBestTrail()!=nullptr){
				  bestrouteant = antcol->GetBestTrail();
			      pbantakhir->Invalidate();
			 }
		 }
private: System::Void timer3_Tick(System::Object^  sender, System::EventArgs^  e) {
						 
			 TimeSpan ^ts=sw->Elapsed;
			 lblwktuprosessa->Text= String::Format("{0:00}m:{1:00}s:{2:00}ms", ts->Minutes.ToString(), ts->Seconds.ToString(), ts->Milliseconds.ToString());

		 }
private: System::Void timer4_Tick(System::Object^  sender, System::EventArgs^  e) {
		 TimeSpan ^ts=sw->Elapsed;
		 lblwktuprosesant->Text= String::Format("{0:00}m:{1:00}s:{2:00}ms", ts->Minutes.ToString(), ts->Seconds.ToString(), ts->Milliseconds.ToString());
		 }
};
}
