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
	/// Summary for ventanaInsertarMenu
	/// </summary>
	public ref class ventanaInsertarMenu : public System::Windows::Forms::Form
	{
	public:
		cargarArchivo* progra;

		ventanaInsertarMenu(cargarArchivo* progra)
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
		~ventanaInsertarMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox4;
	protected:
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label5;

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
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(182, 132);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(167, 20);
			this->textBox4->TabIndex = 33;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(28, 107);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(148, 13);
			this->label4->TabIndex = 32;
			this->label4->Text = L"Digite codigo de Restaurante:";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(182, 100);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(167, 20);
			this->textBox3->TabIndex = 31;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(25, 172);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(120, 13);
			this->label3->TabIndex = 30;
			this->label3->Text = L"Digite nombre de Menu:";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(206, 221);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 29;
			this->button2->Text = L"Cancelar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ventanaInsertarMenu::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(86, 221);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 28;
			this->button1->Text = L"Aceptar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ventanaInsertarMenu::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(182, 64);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(167, 20);
			this->textBox2->TabIndex = 27;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(182, 32);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(167, 20);
			this->textBox1->TabIndex = 26;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(25, 71);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(123, 13);
			this->label2->TabIndex = 25;
			this->label2->Text = L"Digite codigo de Ciudad:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(25, 39);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(110, 13);
			this->label1->TabIndex = 24;
			this->label1->Text = L"Digite codigo de Pais:";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(182, 165);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(167, 20);
			this->textBox5->TabIndex = 35;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(28, 139);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(117, 13);
			this->label5->TabIndex = 34;
			this->label5->Text = L"Digite codigo de Menu:";
			// 
			// ventanaInsertarMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(383, 271);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label5);
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
			this->Name = L"ventanaInsertarMenu";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Agregar Menu";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// Obtener texto de textBox and Insertar Restaurante
		String^ codStrPais = textBox1->Text;
		String^ codStrCiudad = textBox2->Text;
		String^ codStrRestaurante = textBox3->Text;
		String^ codStrMenu = textBox4->Text;
		String^ nombreMenu = textBox5->Text;


		// Check if the strings are not empty
		if (!String::IsNullOrWhiteSpace(codStrPais) && !String::IsNullOrWhiteSpace(codStrCiudad) && !String::IsNullOrWhiteSpace(codStrRestaurante) && !String::IsNullOrWhiteSpace(codStrMenu) && !String::IsNullOrWhiteSpace(nombreMenu)) {
			int temp;
			int temp2;
			int temp3;
			int temp4;
			Int32::TryParse(codStrPais, temp);
			Int32::TryParse(codStrCiudad, temp2);
			Int32::TryParse(codStrRestaurante, temp3);
			Int32::TryParse(codStrMenu, temp4);

			char cStr[50] = { 0 };
			String^ clrString = nombreMenu;
			sprintf(cStr, "%s", clrString);
			std::string stlString(cStr);
			//INICIO CODIGO
			NodoBinarioPais* q = progra->listaPais->BuscarPais(progra->listaPais->raiz, temp);
			while (q != NULL) {
				if (temp < q->valor) {
					q = q->Hizq;
				}
				if (temp > q->valor) {
					q = q->Hder;
				}
				else if (temp == q->valor) {
					NodoBinarioCiudad* b = q->ArbolCiudad.BuscarCiudad(q->ArbolCiudad.raiz, temp2);
					while (b != NULL) {
						if (temp2 < b->valor) {
							b = b->Hizq;
						}
						if (temp2 > b->valor) {
							b = b->Hder;
						}
						else if (temp2 == b->valor) {
							NodoPtr c = b->ArbolRest.Busqueda(b->ArbolRest.Raiz, temp3);
							if (c != NULL) {
								if(c->listaMenu.BuscarNodoMenu1(temp4) == NULL){
								c->listaMenu.insertar(temp4, cStr);
								System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
									"Codigo: " + temp4 + "\nMenu: " + nombreMenu,
									"Menu agregado.",
									MessageBoxButtons::OK,
									MessageBoxIcon::Information);
								this->Close();
								}
								else {
									System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
										"Codigo: " + temp4 + " ya existe",
										"Error .",
										MessageBoxButtons::OK,
										MessageBoxIcon::Information);
								}
							}
							break;
						}
					}
					if (b == NULL) {
						System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
							"Valores incorrectos.",
							"Error .",
							MessageBoxButtons::OK,
							MessageBoxIcon::Information);
						cout << "Menu: " << temp4 << ":" << cStr << " no fue agregado" << endl;
					}
					break;
				}
				else {
					System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
						"Valores incorrectos.",
						"Error .",
						MessageBoxButtons::OK,
						MessageBoxIcon::Information);
				}
			}
			if (q == NULL) {
				cout << "Menu: " << temp4 << ":" << cStr << " no fue agregado" << endl;
				System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
					"Valores incorrectos.",
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
