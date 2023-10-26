#pragma once

#include "ventanaMenu.h"

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
		ventanaPrincipal(void)
		{
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

	protected:

	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ LabelSaludo;
	private: System::Windows::Forms::CheckBox^ checkAdmin;

	private: System::Windows::Forms::CheckBox^ checkBoxCliente;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ buttonCerrar;



	private:
		ventanaMenu^ menuForm;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->LabelSaludo = (gcnew System::Windows::Forms::Label());
			this->checkAdmin = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxCliente = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->buttonCerrar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(84, 139);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(120, 40);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Aceptar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ventanaPrincipal::button1_Click);
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
			this->checkAdmin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkAdmin->Location = System::Drawing::Point(16, 76);
			this->checkAdmin->Name = L"checkAdmin";
			this->checkAdmin->Size = System::Drawing::Size(120, 40);
			this->checkAdmin->TabIndex = 3;
			this->checkAdmin->Text = L"Administrador";
			this->checkAdmin->UseVisualStyleBackColor = false;
			// 
			// checkBoxCliente
			// 
			this->checkBoxCliente->BackColor = System::Drawing::SystemColors::Control;
			this->checkBoxCliente->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBoxCliente->Location = System::Drawing::Point(142, 76);
			this->checkBoxCliente->Name = L"checkBoxCliente";
			this->checkBoxCliente->Size = System::Drawing::Size(120, 40);
			this->checkBoxCliente->TabIndex = 4;
			this->checkBoxCliente->Text = L"Cliente";
			this->checkBoxCliente->UseVisualStyleBackColor = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(136, 24);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Ingresar como:";
			this->label1->Click += gcnew System::EventHandler(this, &ventanaPrincipal::label1_Click);
			// 
			// buttonCerrar
			// 
			this->buttonCerrar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonCerrar->Location = System::Drawing::Point(2, 240);
			this->buttonCerrar->Name = L"buttonCerrar";
			this->buttonCerrar->Size = System::Drawing::Size(66, 35);
			this->buttonCerrar->TabIndex = 6;
			this->buttonCerrar->Text = L"Salir";
			this->buttonCerrar->UseVisualStyleBackColor = true;
			this->buttonCerrar->Click += gcnew System::EventHandler(this, &ventanaPrincipal::buttonCerrar_Click);
			// 
			// ventanaPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(459, 280);
			this->Controls->Add(this->buttonCerrar);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->checkBoxCliente);
			this->Controls->Add(this->checkAdmin);
			this->Controls->Add(this->LabelSaludo);
			this->Controls->Add(this->button1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"ventanaPrincipal";
			this->Text = L"Log In";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		menuForm = gcnew ventanaMenu();
		menuForm->FormClosed += gcnew FormClosedEventHandler(this, &ventanaPrincipal::menuForm_FormClosed);
		menuForm->Show();
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

	};
}