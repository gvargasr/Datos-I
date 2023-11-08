#pragma once

#include "cargarArchivo.h"

namespace Interfaz {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ventanaReporteCiudades
	/// </summary>
	public ref class ventanaReporteCiudades : public System::Windows::Forms::Form
	{
	public:
		cargarArchivo* progra;
		ventanaReporteCiudades(cargarArchivo* progra)
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
		~ventanaReporteCiudades()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button2;
	protected:
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::TextBox^ textBox1;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(178, 58);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 35;
			this->button2->Text = L"Cancelar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ventanaReporteCiudades::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(61, 59);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 34;
			this->button1->Text = L"Aceptar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ventanaReporteCiudades::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(143, 16);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(167, 20);
			this->textBox1->TabIndex = 32;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(110, 13);
			this->label1->TabIndex = 30;
			this->label1->Text = L"Digite codigo de Pais:";
			// 
			// ventanaReporteCiudades
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(329, 99);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"ventanaReporteCiudades";
			this->Text = L"Reporte de Ciudades";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ codStrPais = textBox1->Text;

	// Check if the strings are not empty
	if (!String::IsNullOrWhiteSpace(codStrPais)){
		int temp;
		Int32::TryParse(codStrPais, temp);

		pnodoPais aux = progra->listaPais->BuscarPais(progra->listaPais->raiz, temp);
		if (aux != NULL) {
			System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
				"Reporte de Ciudades Reporte_Ciudades_" + codStrPais + ".txt\n",
				"Reporte generado",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information);
			cout << "\nSe esta generando el archivo Reporte_Ciudades_" + aux->pais + ".txt\n.\n.\n.\n" << endl;
			aux->ArbolCiudad.reporteCiudad("Reporte_Ciudades_" + aux->pais);
			this->Close();
		}
		else {
			System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
				"Pais no se encuentra",
				"Reporte no generado",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error);
			cout << "El pais ingresado no existe";

			this->Close();

		}
	}
	else {
		System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
			"Ingrese codigo de pais",
			"Error",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error);
		this->Close();
	}
	this->Close();
}
};
}
