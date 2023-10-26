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
	/// Summary for ventanaInsertarProducto
	/// </summary>
	public ref class ventanaInsertarProducto : public System::Windows::Forms::Form
	{
	public:
		cargarArchivo* progra;
		ventanaInsertarProducto(cargarArchivo* progra)
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
		~ventanaInsertarProducto()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox5;
	protected:
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::Label^ label9;

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
			this->label5 = (gcnew System::Windows::Forms::Label());
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
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(199, 154);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(167, 20);
			this->textBox5->TabIndex = 47;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(36, 126);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(117, 13);
			this->label5->TabIndex = 46;
			this->label5->Text = L"Digite codigo de Menu:";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(199, 123);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(167, 20);
			this->textBox4->TabIndex = 45;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(36, 94);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(148, 13);
			this->label4->TabIndex = 44;
			this->label4->Text = L"Digite codigo de Restaurante:";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(202, 87);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(167, 20);
			this->textBox3->TabIndex = 43;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(36, 190);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(136, 13);
			this->label3->TabIndex = 42;
			this->label3->Text = L"Digite nombre de Producto:";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(215, 325);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 41;
			this->button2->Text = L"Cancelar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ventanaInsertarProducto::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(95, 325);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 40;
			this->button1->Text = L"Aceptar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ventanaInsertarProducto::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(199, 55);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(167, 20);
			this->textBox2->TabIndex = 39;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(199, 19);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(167, 20);
			this->textBox1->TabIndex = 38;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(36, 58);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(123, 13);
			this->label2->TabIndex = 37;
			this->label2->Text = L"Digite codigo de Ciudad:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(36, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(110, 13);
			this->label1->TabIndex = 36;
			this->label1->Text = L"Digite codigo de Pais:";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(199, 183);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(167, 20);
			this->textBox6->TabIndex = 49;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(36, 161);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(133, 13);
			this->label6->TabIndex = 48;
			this->label6->Text = L"Digite codigo de Producto:";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(202, 213);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(167, 20);
			this->textBox7->TabIndex = 51;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(39, 220);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(91, 13);
			this->label7->TabIndex = 50;
			this->label7->Text = L"Cantidad de Kcal:";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(202, 245);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(167, 20);
			this->textBox8->TabIndex = 53;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(39, 252);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(40, 13);
			this->label8->TabIndex = 52;
			this->label8->Text = L"Precio:";
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(202, 276);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(167, 20);
			this->textBox9->TabIndex = 55;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(39, 283);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(52, 13);
			this->label9->TabIndex = 54;
			this->label9->Text = L"Cantidad:";
			// 
			// ventanaInsertarProducto
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(399, 373);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->label6);
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
			this->Name = L"ventanaInsertarProducto";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Agregar Producto";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// Obtener texto de textBox and Insertar Producto
		String^ codStrPais = textBox1->Text;
		String^ codStrCiudad = textBox2->Text;
		String^ codStrRestaurante = textBox3->Text;
		String^ codStrMenu = textBox4->Text;
		String^ codStrProducto = textBox5->Text;
		String^ nombreStrProducto = textBox6->Text;
		String^ kcalStrProducto = textBox7->Text;
		String^ precioStrProducto = textBox8->Text;
		String^ cantidadStrProducto = textBox9->Text;


		// Check if the strings are not empty
		if (!String::IsNullOrWhiteSpace(codStrPais) && !String::IsNullOrWhiteSpace(codStrCiudad) && !String::IsNullOrWhiteSpace(codStrRestaurante) && !String::IsNullOrWhiteSpace(codStrMenu) && !String::IsNullOrWhiteSpace(codStrProducto) && !String::IsNullOrWhiteSpace(nombreStrProducto) && !String::IsNullOrWhiteSpace(kcalStrProducto) && !String::IsNullOrWhiteSpace(precioStrProducto) && !String::IsNullOrWhiteSpace(cantidadStrProducto)) {
			int temp;
			int temp2;
			int temp3;
			int temp4;
			int temp5;
			int temp6;
			int temp7;
			int temp8;
			Int32::TryParse(codStrPais, temp);
			Int32::TryParse(codStrCiudad, temp2);
			Int32::TryParse(codStrRestaurante, temp3);
			Int32::TryParse(codStrMenu, temp4);
			Int32::TryParse(codStrProducto, temp5);
			Int32::TryParse(kcalStrProducto, temp6);
			Int32::TryParse(precioStrProducto, temp7);
			Int32::TryParse(cantidadStrProducto, temp8);

			char cStr[50] = { 0 };
			String^ clrString = nombreStrProducto;
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
					pNodoBinarioCiudad b = q->ArbolCiudad.BuscarCiudad(q->ArbolCiudad.raiz, temp2);
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
								NodoMPtr d = c->listaMenu.BusquedaM(temp4);
								if (d != NULL)
									if (d->listaProducto.BuscarProductoBool(d->listaProducto.raiz,temp5) == false) {
										d->listaProducto.InsertaNodoProducto(temp5, cStr, temp6, temp7, temp8);
										System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
											"Codigo: " + codStrProducto + "\nProducto: " + nombreStrProducto + "\nKcal : " + kcalStrProducto + "\nPrecio : " + precioStrProducto + "\nCantidad : " + cantidadStrProducto,
											"Producto agregado.",
											MessageBoxButtons::OK,
											MessageBoxIcon::Information);
										this->Close();
									}
									else {
										System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
											"Producto no agregado",
											"Error .",
											MessageBoxButtons::OK,
											MessageBoxIcon::Information);
									}
								break;
							}
							break;
						}
					}
					if (b == NULL) {
						cout << "Producto: " << temp5 << ":" << cStr << " no fue agregado" << endl;
						System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
							"Producto no agregado",
							"Error .",
							MessageBoxButtons::OK,
							MessageBoxIcon::Information);
					}
					break;
				}
			}
			if (q == NULL) {
				cout << "Producto: " << temp5 << ":" << cStr << " no fue agregado" << endl;
				System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
					"Producto no agregado",
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
