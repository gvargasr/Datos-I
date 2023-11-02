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
	/// Summary for ventanaBuscarPais
	/// </summary>
	public ref class ventanaBuscarPais : public System::Windows::Forms::Form
	{
	public:
		cargarArchivo* progra;
		ventanaBuscarPais(cargarArchivo* progra)
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
		~ventanaBuscarPais()
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
		System::ComponentModel::Container^ components;

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
			this->button2->Location = System::Drawing::Point(164, 60);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Cancelar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ventanaBuscarPais::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(47, 61);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Buscar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ventanaBuscarPais::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(130, 19);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(167, 20);
			this->textBox1->TabIndex = 7;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(110, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Digite codigo de Pais:";
			// 
			// ventanaBuscarPais
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(313, 106);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"ventanaBuscarPais";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Buscar Pais";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		//cancelar y cerrar ventana
		this->Close();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// Obtener texto de textBox and BuscarAdmin
		String^ codStrPais = textBox1->Text;

		// Check if the strings are not empty
		if (!String::IsNullOrWhiteSpace(codStrPais)) {
			int temp;
			Int32::TryParse(codStrPais, temp);
			NodoBinarioPais* aux = progra->listaPais->BuscarPais(progra->listaPais->raiz, temp);

			if (aux != NULL) {
				std::string adminInfoStdString = aux->pais;
				String^ adminInfo = gcnew String(adminInfoStdString.c_str());
					System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
						"Codigo: " + temp + "\nPais: " + adminInfo,
						"Pais Encontrado",
						MessageBoxButtons::OK,
						MessageBoxIcon::Information);
					this->Close();
				cout << "\n.:Pais encontrado:.\nCodigo: " << aux->valor << "\nNombre: " << aux->pais << endl;
			}
			else {
					System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
						"Codigo: " + temp,
						"Pais No Encontrado",
						MessageBoxButtons::OK,
						MessageBoxIcon::Error);
				cout << "El pais " << temp << " no se encuentra" << endl;
			}

		}
	}
	
	};
}
