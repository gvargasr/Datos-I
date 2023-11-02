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
	/// Summary for ventanaPopupEliminarCompra
	/// </summary>
	public ref class ventanaPopupEliminarCompra : public System::Windows::Forms::Form
	{
	public:
		cargarArchivo* progra;
		bool^ flag;
		String^ usuario;
		ventanaPopupEliminarCompra(cargarArchivo* progra, String^ usuario, bool^ flag)
		{
			this->progra = progra;
			this->usuario = usuario;
			this->flag = flag;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ventanaPopupEliminarCompra()
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
			this->button2->Location = System::Drawing::Point(165, 57);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 25;
			this->button2->Text = L"Cancelar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ventanaPopupEliminarCompra::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(48, 58);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 24;
			this->button1->Text = L"Buscar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ventanaPopupEliminarCompra::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(141, 18);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(167, 20);
			this->textBox1->TabIndex = 23;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &ventanaPopupEliminarCompra::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(126, 13);
			this->label1->TabIndex = 22;
			this->label1->Text = L"Digite cedula del usuario:";
			this->label1->Click += gcnew System::EventHandler(this, &ventanaPopupEliminarCompra::label1_Click);
			// 
			// ventanaPopupEliminarCompra
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(318, 94);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"ventanaPopupEliminarCompra";
			this->Text = L"Eliminar Compra";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// Obtener texto de textBox and BuscarAdmin
		String^ codStrCedula = textBox1->Text;

		// Check if the strings are not empty
		if (!String::IsNullOrWhiteSpace(codStrCedula)) {
			int temp;
			Int32::TryParse(codStrCedula, temp);
			pnodoFila comprador = progra->listaFila->Buscador(temp);
	
			//INICIO CODIGO
			if (comprador != NULL) {
				std::string adminInfoStdString = comprador->nombre;
				std::string comprasStdString = comprador->listaComp->Mostrar();
				String^ adminInfo = gcnew String(adminInfoStdString.c_str());
				String^ compras = gcnew String(comprasStdString.c_str());
				this->Close();
				System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
					"Cedula: " + temp + "\nNombre: " + adminInfo + "\nProducto: "+ compras,
					"Compra eliminada",
					MessageBoxButtons::OK,
					MessageBoxIcon::Information);
				progra->listaFila->BorrarNodo(temp);
			}
			else {
				System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
					"Cedula: " + temp+ " no tiene compras activas.",
					"No hay compras ",
					MessageBoxButtons::OK,
					MessageBoxIcon::Warning);
			}
			//FIN CODIGO();
		}
		else {
			System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
				"Datos insuficientes.",
				"Ingresar datos",
				MessageBoxButtons::OK,
				MessageBoxIcon::Warning);
			// Handle empty input in textBox1 or textBox2
			// Display an error message or take appropriate action
		}
		// cerrar ventana
		
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}
