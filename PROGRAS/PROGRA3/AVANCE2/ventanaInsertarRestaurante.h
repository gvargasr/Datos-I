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
	/// Summary for ventanaInsertarRestaurante
	/// </summary>
	public ref class ventanaInsertarRestaurante : public System::Windows::Forms::Form
	{
	public:
		cargarArchivo* progra;
		ventanaInsertarRestaurante(cargarArchivo* progra)
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
		~ventanaInsertarRestaurante()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox3;
	protected:
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label4;

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
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(169, 89);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(167, 20);
			this->textBox3->TabIndex = 21;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 129);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(151, 13);
			this->label3->TabIndex = 20;
			this->label3->Text = L"Digite nombre de Restaurante:";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(193, 165);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 19;
			this->button2->Text = L"Cancelar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ventanaInsertarRestaurante::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(73, 165);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 18;
			this->button1->Text = L"Aceptar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ventanaInsertarRestaurante::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(169, 53);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(167, 20);
			this->textBox2->TabIndex = 17;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(169, 21);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(167, 20);
			this->textBox1->TabIndex = 16;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 60);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(123, 13);
			this->label2->TabIndex = 15;
			this->label2->Text = L"Digite codigo de Ciudad:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(110, 13);
			this->label1->TabIndex = 14;
			this->label1->Text = L"Digite codigo de Pais:";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(169, 122);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(167, 20);
			this->textBox4->TabIndex = 23;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(15, 96);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(148, 13);
			this->label4->TabIndex = 22;
			this->label4->Text = L"Digite codigo de Restaurante:";
			// 
			// ventanaInsertarRestaurante
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(357, 203);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"ventanaInsertarRestaurante";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Agregar Restaurante";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// Obtener texto de textBox and Insertar Restaurante
		String^ codStrPais = textBox1->Text;
		String^ codStrCiudad = textBox2->Text;
		String^ codStrRestaurante = textBox3->Text;
		String^ nombreCiudad = textBox4->Text;


		// Check if the strings are not empty
		if (!String::IsNullOrWhiteSpace(codStrPais) && !String::IsNullOrWhiteSpace(codStrCiudad) && !String::IsNullOrWhiteSpace(nombreCiudad)) {
			int temp;
			int temp2;
			int temp3;
			Int32::TryParse(codStrPais, temp);
			Int32::TryParse(codStrCiudad, temp2);
			Int32::TryParse(codStrRestaurante, temp3);
			char cStr[50] = { 0 };
			String^ clrString = nombreCiudad;
			sprintf_s(cStr, "%s", clrString);
			std::string stlString(cStr);
			//INICIO CODIGO
			NodoBinarioPais* aux = progra->listaPais->BuscarPais(progra->listaPais->raiz, temp);
			if (aux != NULL) {
				NodoBinarioCiudad* aux2 = aux->ArbolCiudad.BuscarCiudad(aux->ArbolCiudad.raiz, temp2);
				if (aux2 != NULL) {
					aux2->ArbolRest.insertar(temp3, cStr);
				}
				else {
					cout << "No se agrego el restaurante, valores incorrectos";
				}
			}
			else {
				cout << "No se agrego el restaurante, valores incorrectos";
			}
			//FIN CODIGO();
		}
		else {
			// Handle empty input in textBox1 or textBox2
			// Display an error message or take appropriate action
		}
		// cerrar ventana
		this->Close();
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
