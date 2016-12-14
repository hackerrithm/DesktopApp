#pragma once

namespace DesktopApp {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;
	using namespace MySql::Data::Entity;

	/// <summary>
	/// Summary for FormsApp
	/// </summary>
	public ref class FormsApp : public System::Windows::Forms::Form
	{
	public:
		FormsApp(void)
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
		~FormsApp()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected:
	private: System::Windows::Forms::Button^  button1;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			//
			// textBox1
			//
			this->textBox1->Location = System::Drawing::Point(13, 13);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(877, 166);
			this->textBox1->TabIndex = 0;
			//
			// button1
			//
			this->button1->Location = System::Drawing::Point(402, 206);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &FormsApp::button1_Click);
			//
			// FormsApp
			//
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(902, 298);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Name = L"FormsApp";
			this->Text = L"FormsApp";
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ SQLQuery = textBox1->Text;
		String^ connectionInfo = "datasource=localhost;port=3306;username=root;password=kemar;database=testdb";
		MySqlConnection^ con = gcnew MySqlConnection(connectionInfo);
		MySqlCommand^ conCommand = gcnew MySqlCommand(SQLQuery, con);
		MySqlDataReader^ dataReader;

		try
		{
			con->Open();
			dataReader = conCommand->ExecuteReader();
			MessageBox::Show("Command executed!");
		}
		catch (Exception^ exe)
		{
			MessageBox::Show(exe->StackTrace);
		}
	}
	};
}
