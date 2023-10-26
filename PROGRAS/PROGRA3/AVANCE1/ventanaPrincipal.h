#pragma once

#include "ventanaMenu.h"
#include <iostream>
#include "cargarArchivo.h"

namespace Interfaz {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ventanaPrincipal
	/// </summary>
	public ref class ventanaPrincipal : public System::Windows::Forms::Form

	{
	public:
		cargarArchivo* progra;
		
		ventanaPrincipal(void)
		{
			progra = new cargarArchivo();
			progra->cargaInicial();
			InitializeComponent();
			checkAdmin->CheckedChanged += gcnew System::EventHandler(this, &ventanaPrincipal::checkBox_CheckedChanged);
			checkBoxCliente->CheckedChanged += gcnew System::EventHandler(this, &ventanaPrincipal::checkBox_CheckedChanged);
			//
			//TODO: Add the constructor code here
			//


		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ventanaPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ buttonLogin;
	protected:

	protected:

	protected:

	private: System::Windows::Forms::Label^ LabelSaludo;
	private: System::Windows::Forms::CheckBox^ checkAdmin;

	private: System::Windows::Forms::CheckBox^ checkBoxCliente;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ buttonCerrar;



	private:
		ventanaMenu^ menuForm;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;

		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		/// 

		void checkBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
		{
			// Handle the CheckedChanged event for both checkboxes
			CheckBox^ currentCheckBox = dynamic_cast<CheckBox^>(sender);

			// Uncheck the other checkbox if the current checkbox is checked
			if (currentCheckBox->Checked)
			{
				if (currentCheckBox == checkAdmin)
				{
					checkBoxCliente->Checked = false;
				}
				else if (currentCheckBox == checkBoxCliente)
				{
					checkAdmin->Checked = false;
				}
			}
		}

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ventanaPrincipal::typeid));
			this->buttonLogin = (gcnew System::Windows::Forms::Button());
			this->LabelSaludo = (gcnew System::Windows::Forms::Label());
			this->checkAdmin = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxCliente = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->buttonCerrar = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// buttonLogin
			// 
			this->buttonLogin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonLogin->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->buttonLogin->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonLogin.Image")));
			this->buttonLogin->ImageAlign = System::Drawing::ContentAlignment::BottomLeft;
			this->buttonLogin->Location = System::Drawing::Point(79, 192);
			this->buttonLogin->Name = L"buttonLogin";
			this->buttonLogin->Size = System::Drawing::Size(120, 40);
			this->buttonLogin->TabIndex = 1;
			this->buttonLogin->Text = L"Aceptar";
			this->buttonLogin->UseVisualStyleBackColor = true;
			this->buttonLogin->Click += gcnew System::EventHandler(this, &ventanaPrincipal::buttonLogin_Click);
			// 
			// LabelSaludo
			// 
			this->LabelSaludo->AutoSize = true;
			this->LabelSaludo->Location = System::Drawing::Point(127, 153);
			this->LabelSaludo->Name = L"LabelSaludo";
			this->LabelSaludo->Size = System::Drawing::Size(0, 13);
			this->LabelSaludo->TabIndex = 2;
			// 
			// checkAdmin
			// 
			this->checkAdmin->BackColor = System::Drawing::SystemColors::Control;
			this->checkAdmin->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkAdmin.BackgroundImage")));
			this->checkAdmin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkAdmin->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->checkAdmin->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkAdmin.Image")));
			this->checkAdmin->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->checkAdmin->Location = System::Drawing::Point(16, 76);
			this->checkAdmin->Name = L"checkAdmin";
			this->checkAdmin->Size = System::Drawing::Size(132, 40);
			this->checkAdmin->TabIndex = 3;
			this->checkAdmin->Text = L"Administrador";
			this->checkAdmin->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->checkAdmin->UseVisualStyleBackColor = false;
			// 
			// checkBoxCliente
			// 
			this->checkBoxCliente->BackColor = System::Drawing::SystemColors::Control;
			this->checkBoxCliente->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBoxCliente.BackgroundImage")));
			this->checkBoxCliente->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBoxCliente->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->checkBoxCliente->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBoxCliente.Image")));
			this->checkBoxCliente->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->checkBoxCliente->Location = System::Drawing::Point(154, 76);
			this->checkBoxCliente->Name = L"checkBoxCliente";
			this->checkBoxCliente->Size = System::Drawing::Size(120, 40);
			this->checkBoxCliente->TabIndex = 4;
			this->checkBoxCliente->Text = L"Cliente";
			this->checkBoxCliente->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->checkBoxCliente->UseVisualStyleBackColor = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label1.Image")));
			this->label1->Location = System::Drawing::Point(12, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(136, 24);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Ingresar como:";
			// 
			// buttonCerrar
			// 
			this->buttonCerrar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonCerrar->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->buttonCerrar->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonCerrar.Image")));
			this->buttonCerrar->ImageAlign = System::Drawing::ContentAlignment::BottomLeft;
			this->buttonCerrar->Location = System::Drawing::Point(2, 240);
			this->buttonCerrar->Name = L"buttonCerrar";
			this->buttonCerrar->Size = System::Drawing::Size(66, 35);
			this->buttonCerrar->TabIndex = 6;
			this->buttonCerrar->Text = L"Salir";
			this->buttonCerrar->UseVisualStyleBackColor = true;
			this->buttonCerrar->Click += gcnew System::EventHandler(this, &ventanaPrincipal::buttonCerrar_Click);
			// 
			// label2
			// 
			this->label2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label2.Image")));
			this->label2->Location = System::Drawing::Point(13, 153);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(87, 23);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Cedula: ";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F));
			this->textBox1->Location = System::Drawing::Point(106, 150);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(117, 29);
			this->textBox1->TabIndex = 8;
			// 
			// ventanaPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(459, 280);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->buttonCerrar);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->checkBoxCliente);
			this->Controls->Add(this->checkAdmin);
			this->Controls->Add(this->LabelSaludo);
			this->Controls->Add(this->buttonLogin);
			this->Name = L"ventanaPrincipal";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Log In";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void buttonLogin_Click(System::Object^ sender, System::EventArgs^ e) {

		ArbolB* ad = this->progra->listaAdmin;
		ArbolB* cl = this->progra->listaCliente;
		String^ Resp = this->textBox1->Text;
		int ced;
		if (Int32::TryParse(Resp, ced)) {
			// Conversion successful, intValue now holds the integer value
			// You can use intValue as an integer variable in your code
		}
		else {
			// Handle the case where Resp is not a valid numeric string
			// For example, display an error message to the user
		}
		if (checkAdmin->Checked == true) {
			bool^ flag = gcnew bool(true);
			menuForm = gcnew ventanaMenu(progra, Resp, flag);
			menuForm->FormClosed += gcnew FormClosedEventHandler(this, &ventanaPrincipal::menuForm_FormClosed);
			if (ad->Search(ced, ad->raiz) == true) {
				this->Hide();
				//menuForm = gcnew ventanaMenu(progra);
				//menuForm->FormClosed += gcnew FormClosedEventHandler(this, &ventanaPrincipal::menuForm_FormClosed);
				menuForm->Show();
			}
			else {
				cout << "No se encuentra en la lista de admins";
				System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
					"Admin no se encuentra en base de datos.",
					"Alerta de login:",
					MessageBoxButtons::OK,
					MessageBoxIcon::Information);

				if (SelectUSER == System::Windows::Forms::DialogResult::OK) {
				}
			}

		}
		else if (checkBoxCliente->Checked == true) {
			if (cl->Search(ced, cl->raiz) == true) {
				bool^ flag = gcnew bool(false);
				menuForm = gcnew ventanaMenu(progra, Resp, flag);
				menuForm->FormClosed += gcnew FormClosedEventHandler(this, &ventanaPrincipal::menuForm_FormClosed);
				menuForm->leerArchivosMenuItem->Enabled = false;
				menuForm->insertarMenuItem->Enabled = false;
				menuForm->modificarMenuItem->Enabled = false;
				menuForm->eliminarMenuItem->Enabled = false;
				menuForm->BuscaClienteMenuItem->Enabled = false;
				menuForm->BuscaAdminMenuItem->Enabled = false;
				menuForm->clientesMenuItem->Enabled = false;
				menuForm->cantidadDeProductoMenuItem->Enabled = false;
				menuForm->facturaDeMayorMontoMenuItem->Enabled = false;
				menuForm->facturaDeMenorMontoMenuItem->Enabled = false;
				menuForm->productoMasCompradoMenuItem->Enabled = false;
				menuForm->eliminacionesMenuItem->Enabled = false;
				menuForm->FormClosed += gcnew FormClosedEventHandler(this, &ventanaPrincipal::menuForm_FormClosed);
				this->Hide();
				menuForm->Show();
			}
			else {
				cout << "No se encuentra en la lista de clientes";
				System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
					"Cliente no se encuentra en base de datos.",
					"Alerta de login:",
					MessageBoxButtons::OK,
					MessageBoxIcon::Information);

				if (SelectUSER == System::Windows::Forms::DialogResult::OK) {
				}
			}
		}
		else{
			System::Windows::Forms::DialogResult SelectUSER= MessageBox::Show(
				"Por favor seleccionar Admin o Cliente",
				"Alerta de login:",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information);

			if (SelectUSER == System::Windows::Forms::DialogResult::OK) {
				//this->Show();
			}
		}
	}

	private: System::Void menuForm_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
		// Check if ventanaMenu is disposed before accessing it
		if (menuForm != nullptr && !menuForm->IsDisposed) {
			// Unsubscribe events
			menuForm->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaPrincipal::menuForm_FormClosed);
			// Show the ventanaPrincipal form when ventanaMenu is closed
		}
		this->Show();
	}

	private: System::Void buttonCerrar_Click(System::Object^ sender, System::EventArgs^ e) {

		System::Windows::Forms::Application::Exit();
	}



	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}

};
}