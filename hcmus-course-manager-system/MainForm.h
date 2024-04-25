#pragma once

namespace CourseManagerSystem {

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
	private: System::Windows::Forms::Label^ lableNoAccount;
	private: System::Windows::Forms::Button^ btnRegister;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::TextBox^ txtBoxUsername;

	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::TextBox^ txtBoxPassword;
	private: System::Windows::Forms::CheckBox^ checkBoxRemember;
	private: System::Windows::Forms::Button^ btnSignIn;
	private: System::Windows::Forms::Label^ labelForgotPassword;






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
			this->labelForgotPassword = (gcnew System::Windows::Forms::Label());
			this->btnSignIn = (gcnew System::Windows::Forms::Button());
			this->checkBoxRemember = (gcnew System::Windows::Forms::CheckBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->txtBoxPassword = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->txtBoxUsername = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->LeftPanel = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnRegister = (gcnew System::Windows::Forms::Button());
			this->lableNoAccount = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->RightPanel->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->LeftPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// RightPanel
			// 
			this->RightPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"RightPanel.BackgroundImage")));
			this->RightPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->RightPanel->Controls->Add(this->labelForgotPassword);
			this->RightPanel->Controls->Add(this->btnSignIn);
			this->RightPanel->Controls->Add(this->checkBoxRemember);
			this->RightPanel->Controls->Add(this->panel2);
			this->RightPanel->Controls->Add(this->panel1);
			this->RightPanel->Controls->Add(this->label4);
			this->RightPanel->Controls->Add(this->label3);
			this->RightPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->RightPanel->Location = System::Drawing::Point(0, 0);
			this->RightPanel->Name = L"RightPanel";
			this->RightPanel->Size = System::Drawing::Size(884, 561);
			this->RightPanel->TabIndex = 0;
			this->RightPanel->Click += gcnew System::EventHandler(this, &MainForm::other_click);
			// 
			// labelForgotPassword
			// 
			this->labelForgotPassword->AutoSize = true;
			this->labelForgotPassword->BackColor = System::Drawing::Color::Transparent;
			this->labelForgotPassword->Cursor = System::Windows::Forms::Cursors::Hand;
			this->labelForgotPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelForgotPassword->ForeColor = System::Drawing::Color::LightSkyBlue;
			this->labelForgotPassword->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->labelForgotPassword->Location = System::Drawing::Point(541, 432);
			this->labelForgotPassword->Name = L"labelForgotPassword";
			this->labelForgotPassword->Size = System::Drawing::Size(100, 13);
			this->labelForgotPassword->TabIndex = 10;
			this->labelForgotPassword->Text = L"Forgot password\?";
			this->labelForgotPassword->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->labelForgotPassword->Click += gcnew System::EventHandler(this, &MainForm::forgotPassword_click);
			// 
			// btnSignIn
			// 
			this->btnSignIn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(196)),
				static_cast<System::Int32>(static_cast<System::Byte>(54)));
			this->btnSignIn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnSignIn->FlatAppearance->BorderSize = 0;
			this->btnSignIn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSignIn->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSignIn->Location = System::Drawing::Point(415, 370);
			this->btnSignIn->Name = L"btnSignIn";
			this->btnSignIn->Size = System::Drawing::Size(350, 50);
			this->btnSignIn->TabIndex = 9;
			this->btnSignIn->Text = L"Sign In";
			this->btnSignIn->UseVisualStyleBackColor = false;
			this->btnSignIn->Click += gcnew System::EventHandler(this, &MainForm::btnSignIn_Click);
			// 
			// checkBoxRemember
			// 
			this->checkBoxRemember->AutoSize = true;
			this->checkBoxRemember->BackColor = System::Drawing::Color::Transparent;
			this->checkBoxRemember->Checked = true;
			this->checkBoxRemember->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxRemember->Cursor = System::Windows::Forms::Cursors::Hand;
			this->checkBoxRemember->FlatAppearance->BorderSize = 0;
			this->checkBoxRemember->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->checkBoxRemember->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->checkBoxRemember->Location = System::Drawing::Point(415, 331);
			this->checkBoxRemember->Name = L"checkBoxRemember";
			this->checkBoxRemember->Size = System::Drawing::Size(101, 17);
			this->checkBoxRemember->TabIndex = 8;
			this->checkBoxRemember->Text = L"Remember me";
			this->checkBoxRemember->UseVisualStyleBackColor = false;
			this->checkBoxRemember->Click += gcnew System::EventHandler(this, &MainForm::other_click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(141)),
				static_cast<System::Int32>(static_cast<System::Byte>(218)));
			this->panel2->Controls->Add(this->txtBoxPassword);
			this->panel2->Location = System::Drawing::Point(415, 266);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(350, 50);
			this->panel2->TabIndex = 7;
			// 
			// txtBoxPassword
			// 
			this->txtBoxPassword->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(141)),
				static_cast<System::Int32>(static_cast<System::Byte>(218)));
			this->txtBoxPassword->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtBoxPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12.25F));
			this->txtBoxPassword->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->txtBoxPassword->Location = System::Drawing::Point(18, 16);
			this->txtBoxPassword->Name = L"txtBoxPassword";
			this->txtBoxPassword->Size = System::Drawing::Size(310, 22);
			this->txtBoxPassword->TabIndex = 0;
			this->txtBoxPassword->Text = L"Password";
			this->txtBoxPassword->UseSystemPasswordChar = true;
			this->txtBoxPassword->Click += gcnew System::EventHandler(this, &MainForm::txtBoxPassword_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(141)),
				static_cast<System::Int32>(static_cast<System::Byte>(218)));
			this->panel1->Controls->Add(this->txtBoxUsername);
			this->panel1->Location = System::Drawing::Point(415, 210);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(350, 50);
			this->panel1->TabIndex = 6;
			// 
			// txtBoxUsername
			// 
			this->txtBoxUsername->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(141)),
				static_cast<System::Int32>(static_cast<System::Byte>(218)));
			this->txtBoxUsername->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtBoxUsername->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12.25F));
			this->txtBoxUsername->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->txtBoxUsername->Location = System::Drawing::Point(18, 16);
			this->txtBoxUsername->Name = L"txtBoxUsername";
			this->txtBoxUsername->Size = System::Drawing::Size(310, 22);
			this->txtBoxUsername->TabIndex = 0;
			this->txtBoxUsername->Text = L"Username";
			this->txtBoxUsername->Click += gcnew System::EventHandler(this, &MainForm::txtBoxUsername_Click);
			// 
			// label4
			// 
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->label4->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->label4->Location = System::Drawing::Point(412, 147);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(331, 44);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Sign in to your account to enroll courses, manage your grades, tasks and more.";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label4->Click += gcnew System::EventHandler(this, &MainForm::other_click);
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Calibri", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->label3->Location = System::Drawing::Point(395, 93);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(152, 65);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Sign In";
			this->label3->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label3->Click += gcnew System::EventHandler(this, &MainForm::other_click);
			// 
			// LeftPanel
			// 
			this->LeftPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"LeftPanel.BackgroundImage")));
			this->LeftPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->LeftPanel->Controls->Add(this->label2);
			this->LeftPanel->Controls->Add(this->label1);
			this->LeftPanel->Controls->Add(this->btnRegister);
			this->LeftPanel->Controls->Add(this->lableNoAccount);
			this->LeftPanel->Controls->Add(this->pictureBox1);
			this->LeftPanel->Dock = System::Windows::Forms::DockStyle::Left;
			this->LeftPanel->Location = System::Drawing::Point(0, 0);
			this->LeftPanel->Name = L"LeftPanel";
			this->LeftPanel->Size = System::Drawing::Size(304, 561);
			this->LeftPanel->TabIndex = 1;
			this->LeftPanel->Click += gcnew System::EventHandler(this, &MainForm::other_click);
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Gainsboro;
			this->label2->Location = System::Drawing::Point(15, 260);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(273, 25);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Efficiency, enthusiastic, excellence.";
			this->label2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label2->Click += gcnew System::EventHandler(this, &MainForm::other_click);
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Calibri", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->label1->Location = System::Drawing::Point(12, 180);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(280, 80);
			this->label1->TabIndex = 3;
			this->label1->Text = L"US Course Management System";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label1->Click += gcnew System::EventHandler(this, &MainForm::other_click);
			// 
			// btnRegister
			// 
			this->btnRegister->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(196)),
				static_cast<System::Int32>(static_cast<System::Byte>(54)));
			this->btnRegister->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnRegister->FlatAppearance->BorderSize = 0;
			this->btnRegister->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRegister->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRegister->Location = System::Drawing::Point(76, 403);
			this->btnRegister->Name = L"btnRegister";
			this->btnRegister->Size = System::Drawing::Size(140, 40);
			this->btnRegister->TabIndex = 2;
			this->btnRegister->Text = L"Register";
			this->btnRegister->UseVisualStyleBackColor = false;
			this->btnRegister->Click += gcnew System::EventHandler(this, &MainForm::btnRegister_Click);
			// 
			// lableNoAccount
			// 
			this->lableNoAccount->AutoSize = true;
			this->lableNoAccount->BackColor = System::Drawing::Color::Transparent;
			this->lableNoAccount->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lableNoAccount->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->lableNoAccount->Location = System::Drawing::Point(97, 370);
			this->lableNoAccount->Name = L"lableNoAccount";
			this->lableNoAccount->Size = System::Drawing::Size(103, 21);
			this->lableNoAccount->TabIndex = 1;
			this->lableNoAccount->Text = L"No Account\?";
			this->lableNoAccount->Click += gcnew System::EventHandler(this, &MainForm::other_click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(12, 56);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(280, 121);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MainForm::other_click);
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
			this->RightPanel->ResumeLayout(false);
			this->RightPanel->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->LeftPanel->ResumeLayout(false);
			this->LeftPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

private: System::Void txtBoxUsername_Click(System::Object^ sender, System::EventArgs^ e) {
	if(txtBoxUsername->Text == "Username")
	{
		txtBoxUsername->Clear();
	}
	if (txtBoxPassword->Text == "") {
		txtBoxPassword->Text = "Password";
	}
}

private: System::Void txtBoxPassword_Click(System::Object^ sender, System::EventArgs^ e) {
	if(txtBoxPassword->Text == "Password")
	{
		txtBoxPassword->Clear();
	}
	if (txtBoxUsername->Text == "") {
		txtBoxUsername->Text = "Username";
	}
}

private: System::Void other_click(System::Object^ sender, System::EventArgs^ e) {
	if (txtBoxUsername->Text == "") {
		txtBoxUsername->Text = "Username";
	}
	if (txtBoxPassword->Text == "") {
		txtBoxPassword->Text = "Password";
	}
}
private: System::Void forgotPassword_click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Please contact the administrator to reset your password.", "Message", MessageBoxButtons::OKCancel);
}
private: System::Void btnRegister_Click(System::Object^ sender, System::EventArgs^ e) {
	//MessageBox::Show("Please contact the administrator to register an account.", "Message", MessageBoxButtons::OKCancel);
	System::Diagnostics::Process::Start("https://hcmus.edu.vn/");
}
private: System::Void btnSignIn_Click(System::Object^ sender, System::EventArgs^ e) {
	if (txtBoxUsername->Text == "Username" || txtBoxPassword->Text == "Password") {
		MessageBox::Show("Please enter your username and password.", "Message", MessageBoxButtons::OKCancel);
	}
	else {
		MessageBox::Show("Sign in successfully.", "Message", MessageBoxButtons::OKCancel);
	}
}
};
}
