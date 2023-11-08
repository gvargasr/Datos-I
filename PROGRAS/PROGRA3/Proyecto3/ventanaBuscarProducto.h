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
	/// Summary for ventanaBuscarProducto
	/// </summary>
	public ref class ventanaBuscarProducto : public System::Windows::Forms::Form
	{
	public:
		cargarArchivo* progra;
		ventanaBuscarProducto(cargarArchivo* progra)
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
		~ventanaBuscarProducto()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox5;
	protected:

	protected:
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox4;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox3;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button2;
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
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(175, 150);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(167, 20);
			this->textBox5->TabIndex = 61;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(12, 157);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(133, 13);
			this->label6->TabIndex = 60;
			this->label6->Text = L"Digite codigo de Producto:";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(175, 115);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(167, 20);
			this->textBox4->TabIndex = 59;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 122);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(117, 13);
			this->label5->TabIndex = 58;
			this->label5->Text = L"Digite codigo de Menu:";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(175, 83);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(167, 20);
			this->textBox3->TabIndex = 57;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 90);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(148, 13);
			this->label4->TabIndex = 56;
			this->label4->Text = L"Digite codigo de Restaurante:";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(190, 194);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 55;
			this->button2->Text = L"Cancelar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ventanaBuscarProducto::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(70, 194);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 54;
			this->button1->Text = L"Aceptar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ventanaBuscarProducto::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(175, 51);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(167, 20);
			this->textBox2->TabIndex = 53;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(175, 15);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(167, 20);
			this->textBox1->TabIndex = 52;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 54);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(123, 13);
			this->label2->TabIndex = 51;
			this->label2->Text = L"Digite codigo de Ciudad:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(110, 13);
			this->label1->TabIndex = 50;
			this->label1->Text = L"Digite codigo de Pais:";
			// 
			// ventanaBuscarProducto
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(360, 226);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"ventanaBuscarProducto";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Buscar Producto";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// Obtener texto de textBox and BuscarAdmin
		String^ codStrPais = textBox1->Text;
		String^ codStrCiudad = textBox2->Text;
		String^ codStrRestaurante = textBox3->Text;
		String^ codStrMenu = textBox4->Text;
		String^ codStrProducto = textBox5->Text;



		// Check if the strings are not empty
	if (!String::IsNullOrWhiteSpace(codStrPais) && !String::IsNullOrWhiteSpace(codStrCiudad) && !String::IsNullOrWhiteSpace(codStrRestaurante)) {
		int temp;
		int temp2;
		int temp3;
		int temp4;
		int temp5;
		Int32::TryParse(codStrPais, temp);
		Int32::TryParse(codStrCiudad, temp2);
		Int32::TryParse(codStrRestaurante, temp3);
		Int32::TryParse(codStrMenu, temp4);
		Int32::TryParse(codStrProducto, temp5);



		NodoBinarioPais* aux = progra->listaPais->BuscarPais(progra->listaPais->raiz, temp);
		if (aux != NULL) {
			NodoBinarioCiudad* aux2 = aux->ArbolCiudad.BuscarCiudad(aux->ArbolCiudad.raiz, temp2);
			if (aux2 != NULL) {
				NodoPtr aux3 = aux2->ArbolRest.BusquedaMRest(temp3);
				if (aux3 != NULL) {
					NodoMPtr aux4 = aux3->listaMenu.BusquedaM(temp4);
					if (aux4 != NULL) {
						pNodoBinarioProducto aux5 = aux4->listaProducto.BuscarProducto(aux4->listaProducto.raiz, temp5);
						if (aux5 != NULL) {
							std::string adminInfoStdString = aux5->Producto;
							String^ adminInfo = gcnew String(adminInfoStdString.c_str());
							System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
								"Pais: " + temp + "\nCiudad: " + temp2 + "\nRestaurante: " + temp3 + "\nMenu : " + temp4 + "\nProducto: " + adminInfo + "\nKcal: "+aux5->Kcal+"\nPrecio: "+aux5->Precio+"\nCantidad: "+aux5->Cantidad,
								"Producto Encontrado",
								MessageBoxButtons::OK,
								MessageBoxIcon::Information);
							cout << "\n.:Restaurante encontrado:.\nCodigo Pais: " << temp << "\nCodigo Ciudad: " << temp2 << "\nCodigo Restaurante: " << temp3 << "\nNombre: " << aux3->nombreRest << endl;
							aux4->listaProducto.BuscarProductoPrecio(aux4->listaProducto.raiz, temp5);
							aux4->listaProducto.BuscarProductoCantidad(aux4->listaProducto.raiz, temp5);
							this->Close();
						}
						else {
							System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
								"Codigo: " + temp5,
								"Producto No Encontrado",
								MessageBoxButtons::OK,
								MessageBoxIcon::Error);
							this->Close();
							cout << "El Producto " << temp5 << " no se encuentra" << endl;
						}
					}
					else {
						System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
							"Codigo: " + temp5,
							"Producto No Encontrado",
							MessageBoxButtons::OK,
							MessageBoxIcon::Error);
						this->Close();
						cout << "El Producto " << temp5 << " no se encuentra" << endl;
					}
				}
				else {
					System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
						"Codigo: " + temp5,
						"Producto No Encontrado",
						MessageBoxButtons::OK,
						MessageBoxIcon::Error);
					this->Close();
					cout << "El Producto " << temp5 << " no se encuentra" << endl;
				}
			}
			else {
				System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
					"Codigo: " + temp5,
					"Producto No Encontrado",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error);
				this->Close();
				cout << "El Producto " << temp5 << " no se encuentra" << endl;
			}
		}
		else {
			System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
				"Codigo: " + temp5,
				"Producto No Encontrado",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error);
			this->Close();
			cout << "El Producto " << temp5 << " no se encuentra" << endl;
		}
	}
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
