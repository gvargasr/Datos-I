#pragma once
#include "cargarArchivo.h"
#include <string>

namespace Interfaz {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ventanaModificarAdmin
	/// </summary>
	public ref class ventanaModificarAdmin : public System::Windows::Forms::Form
	{
	public:
		cargarArchivo* progra;
		ventanaModificarAdmin(cargarArchivo* progra)
		{
			this->progra = progra;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ventanaModificarAdmin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button2;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;

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
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(174, 87);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 23;
			this->button2->Text = L"Cancelar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ventanaModificarAdmin::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(57, 88);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 22;
			this->button1->Text = L"Aceptar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ventanaModificarAdmin::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(143, 51);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(167, 20);
			this->textBox2->TabIndex = 21;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(143, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(167, 20);
			this->textBox1->TabIndex = 20;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(11, 58);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(122, 13);
			this->label2->TabIndex = 19;
			this->label2->Text = L"Digite nombre de Admin:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(119, 13);
			this->label1->TabIndex = 18;
			this->label1->Text = L"Digite cedula de Admin:";
			// 
			// ventanaModificarAdmin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(335, 123);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"ventanaModificarAdmin";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Modificar Admin";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// Obtener texto de textBox and Insertar Producto
		String^ codStrCedula = textBox1->Text;
		String^ codStrNombre = textBox2->Text;



		// Check if the strings are not empty
		if (!String::IsNullOrWhiteSpace(codStrCedula) && !String::IsNullOrWhiteSpace(codStrCedula)) {
			int temp;

			Int32::TryParse(codStrCedula, temp);


			char cStr[50] = { 0 };
			String^ clrString = codStrNombre;
			sprintf_s(cStr, "%s", clrString);
			std::string stlString(cStr);
			//INICIO CODIGO
			if (progra->listaAdmin->Search(temp, progra->listaAdmin->raiz) == true) {
				progra->listaAdmin->Modificar(temp, cStr, progra->listaAdmin->raiz);
				System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
					"Codigo: " + temp + "\nNombre: " + codStrNombre,
					"Administrador modificado.",
					MessageBoxButtons::OK,
					MessageBoxIcon::Information);
				this->Close();
			}
			else {
				System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
					"Codigo: " + temp + " no existe",
					"Error .",
					MessageBoxButtons::OK,
					MessageBoxIcon::Information);
			}
			//FIN CODIGO();
		}
		else {
			// Handle empty input in textBox1 or textBox2
			// Display an error message or take appropriate action
		}
		// cerrar ventana
	}


private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
