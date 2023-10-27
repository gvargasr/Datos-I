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
	/// Summary for ventanaComprar
	/// </summary>
	public ref class ventanaComprar : public System::Windows::Forms::Form
	{

	private: System::Windows::Forms::Button^ button1;
	public:
	private: System::Windows::Forms::Button^ button2;
	public:
		bool^ flag;
		String^ usuario;
		cargarArchivo* progra;
		ventanaComprar(cargarArchivo* progra, String^ usuario, bool^ flag)
		{
			this->progra = progra;
			this->flag = flag;
			this->usuario = usuario;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ventanaComprar()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox6;
	protected:
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label3;
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
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(175, 183);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(167, 20);
			this->textBox6->TabIndex = 81;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(12, 158);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(133, 13);
			this->label6->TabIndex = 80;
			this->label6->Text = L"Digite codigo de Producto:";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(175, 148);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(167, 20);
			this->textBox5->TabIndex = 79;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 123);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(117, 13);
			this->label5->TabIndex = 78;
			this->label5->Text = L"Digite codigo de Menu:";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(175, 116);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(167, 20);
			this->textBox4->TabIndex = 77;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 91);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(148, 13);
			this->label4->TabIndex = 76;
			this->label4->Text = L"Digite codigo de Restaurante:";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(175, 84);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(167, 20);
			this->textBox3->TabIndex = 75;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 187);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(49, 13);
			this->label3->TabIndex = 74;
			this->label3->Text = L"Cantidad";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(175, 52);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(167, 20);
			this->textBox2->TabIndex = 73;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(175, 19);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(167, 20);
			this->textBox1->TabIndex = 72;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 55);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(123, 13);
			this->label2->TabIndex = 71;
			this->label2->Text = L"Digite codigo de Ciudad:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(110, 13);
			this->label1->TabIndex = 70;
			this->label1->Text = L"Digite codigo de Pais:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(78, 219);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 82;
			this->button1->Text = L"Comprar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ventanaComprar::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(175, 219);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 83;
			this->button2->Text = L"Cancelar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ventanaComprar::button2_Click);
			// 
			// ventanaComprar
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(359, 257);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"ventanaComprar";
			this->Text = L"Comprar";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		int cedula;
		Int32::TryParse(usuario, cedula);
		string nombre = progra->listaCliente->SearchNodo(cedula, progra->listaCliente->raiz);
		String^ codStrPais = textBox1->Text;
		String^ codStrCiudad = textBox2->Text;
		String^ codStrRestaurante = textBox3->Text;
		String^ codStrMenu = textBox4->Text;
		String^ codStrProducto = textBox5->Text;
		String^ cantidadStrProducto = textBox6->Text;


		if (!String::IsNullOrWhiteSpace(codStrPais) && !String::IsNullOrWhiteSpace(codStrCiudad) && !String::IsNullOrWhiteSpace(codStrRestaurante) && !String::IsNullOrWhiteSpace(codStrMenu) && !String::IsNullOrWhiteSpace(codStrProducto) && !String::IsNullOrWhiteSpace(cantidadStrProducto)) {
			int temp;
			int temp2;
			int temp3;
			int temp4;
			int temp5;
			int temp6;
			Int32::TryParse(codStrPais, temp);
			Int32::TryParse(codStrCiudad, temp2);
			Int32::TryParse(codStrRestaurante, temp3);
			Int32::TryParse(codStrMenu, temp4);
			Int32::TryParse(codStrProducto, temp5);
			Int32::TryParse(cantidadStrProducto, temp6);



		NodoBinarioPais* aux = progra->listaPais->BuscarPais(progra->listaPais->raiz, temp);
		if (aux != NULL) {
			NodoBinarioCiudad* aux2 = aux->ArbolCiudad.BuscarCiudad(aux->ArbolCiudad.raiz, temp2);
			if (aux2 != NULL) {
				NodoPtr aux3 = aux2->ArbolRest.BusquedaMRest(temp3);
				if (aux3 != NULL) {
					NodoMPtr aux4 = aux3->listaMenu.BusquedaM(temp4);
					if (aux4 != NULL) {
						NodoBinarioProducto* aux5 = aux4->listaProducto.BuscarProducto(aux4->listaProducto.raiz, temp5);
						if (aux5->Cantidad < temp6 || aux5->Cantidad == 0) {
							cout << "No se tiene suficiente producto en existencia" << endl;
							System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
								"Cantidad insuficiente",
								"Error .",
								MessageBoxButtons::OK,
								MessageBoxIcon::Information);
						}
						else {
							aux4->listaProducto.Reducir(aux5, temp6);
							cout << "Producto fue añadido" << endl;
							cout << "- Codigo: " << aux5->valor << endl;
							cout << "- Nombre: " << aux5->Producto << endl;
							cout << "- Kcal: " << aux5->Kcal << endl;
							cout << "- Precio: " << aux5->Precio << endl;
							cout << "- Cantidad: " << temp6 << endl;
							std::string prod = aux5->Producto;
							progra->listaFila->Comprar(cedula, nombre, aux5->valor, aux5->Producto, aux5->Kcal, aux5->Precio, temp6);
							System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
								"Codigo : " + aux5->valor + "\nCantidad : " + temp6 + "\nPrecio Unitario: "+ aux5->Precio,
								"Producto comprado.",
								MessageBoxButtons::OK,
								MessageBoxIcon::Information);
							this->Close();
						}

					}
					else {
						System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
							"Valores incorrectos",
							"Error .",
							MessageBoxButtons::OK,
							MessageBoxIcon::Information);
						cout << "El Producto " << temp5 << " no se encuentra" << endl;
					}
				}
				else {
					System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
						"Valores incorrectos",
						"Error .",
						MessageBoxButtons::OK,
						MessageBoxIcon::Information);
					cout << "El Producto " << temp5 << " no se encuentra" << endl;
				}
			}
			else {
				System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
					"Valores incorrectos",
					"Error .",
					MessageBoxButtons::OK,
					MessageBoxIcon::Information);
				cout << "El Producto " << temp5 << " no se encuentra" << endl;
			}
		}
		else {
			System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
				"Valores incorrectos",
				"Error .",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information);
			cout << "El Producto " << temp5 << " no se encuentra" << endl;
		}
		}
		else {
			// Handle empty input in textBox1 or textBox2
			// Display an error message or take appropriate action
		}
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
