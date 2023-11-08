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
	/// Summary for ventanaReporteRestaurante
	/// </summary>
	public ref class ventanaReporteRestaurante : public System::Windows::Forms::Form
	{
	public:
		cargarArchivo* progra;
		ventanaReporteRestaurante(cargarArchivo* progra)
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
		~ventanaReporteRestaurante()
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
			this->button2->Location = System::Drawing::Point(177, 85);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 29;
			this->button2->Text = L"Cancelar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ventanaReporteRestaurante::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(60, 86);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 28;
			this->button1->Text = L"Buscar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ventanaReporteRestaurante::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(144, 48);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(167, 20);
			this->textBox2->TabIndex = 27;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(143, 15);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(167, 20);
			this->textBox1->TabIndex = 26;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 55);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(123, 13);
			this->label2->TabIndex = 25;
			this->label2->Text = L"Digite codigo de Ciudad:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(110, 13);
			this->label1->TabIndex = 24;
			this->label1->Text = L"Digite codigo de Pais:";
			// 
			// ventanaReporteRestaurante
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(320, 116);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"ventanaReporteRestaurante";
			this->Text = L"Reporte de Restaurantes por Ciudad";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// Obtener texto de textBox and BuscarCiudad
		String^ codStrPais = textBox1->Text;
		String^ codStrCiudad = textBox2->Text;

		// Check if the strings are not empty
		if (!String::IsNullOrWhiteSpace(codStrPais) && !String::IsNullOrWhiteSpace(codStrCiudad)) {
			int temp;
			int temp2;
			Int32::TryParse(codStrPais, temp);
			Int32::TryParse(codStrCiudad, temp2);
			pnodoPais aux = progra->listaPais->BuscarPais(progra->listaPais->raiz, temp);
			if (aux != NULL) {
				pnodoCiudad aux2 = aux->ArbolCiudad.BuscarCiudad(aux->ArbolCiudad.raiz, temp2);
				if (aux2 != NULL) {
					cout << "\nSe esta generando el archivo Reporte_Restaurante_" + aux2->ciudad + ".txt\n.\n.\n.\n" << endl;
					aux2->ArbolRest.MostrarRN3(aux2->ciudad);
					System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
						"Reporte_Restaurante_" + codStrCiudad + ".txt\n",
						"Reporte generado",
						MessageBoxButtons::OK,
						MessageBoxIcon::Information);
				//	aux2->ArbolRest.MostrarRN();
					this->Close();
				}
				else {
					System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
						"Datos incorrectos, por favor intente de nuevo.",
						"ERROR",
						MessageBoxButtons::OK,
						MessageBoxIcon::Error);
					cout << "Datos incorrectos, por favor intente de nuevo.";
				}
			}
			else {
				System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
					"Datos incorrectos, por favor intente de nuevo.",
					"ERROR",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error);
				cout << "Datos incorrectos, por favor intente de nuevo.";
			}
		}
		else {
			System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
				"No se permiten espacios vacios",
				"ERROR",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error);
		}

	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
