#pragma once

namespace TestCLR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ RightPanel;
	private: System::Windows::Forms::Panel^ LeftPanel;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

	protected:


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->RightPanel = (gcnew System::Windows::Forms::Panel());
			this->LeftPanel = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->LeftPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// RightPanel
			// 
			this->RightPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"RightPanel.BackgroundImage")));
			this->RightPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->RightPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->RightPanel->Location = System::Drawing::Point(0, 0);
			this->RightPanel->Name = L"RightPanel";
			this->RightPanel->Size = System::Drawing::Size(884, 561);
			this->RightPanel->TabIndex = 0;
			// 
			// LeftPanel
			// 
			this->LeftPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"LeftPanel.BackgroundImage")));
			this->LeftPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->LeftPanel->Controls->Add(this->pictureBox1);
			this->LeftPanel->Dock = System::Windows::Forms::DockStyle::Left;
			this->LeftPanel->Location = System::Drawing::Point(0, 0);
			this->LeftPanel->Name = L"LeftPanel";
			this->LeftPanel->Size = System::Drawing::Size(304, 561);
			this->LeftPanel->TabIndex = 1;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(12, 101);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(280, 105);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(884, 561);
			this->Controls->Add(this->LeftPanel);
			this->Controls->Add(this->RightPanel);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->HelpButton = true;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"US Course Management System";
			this->LeftPanel->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion


};
}
