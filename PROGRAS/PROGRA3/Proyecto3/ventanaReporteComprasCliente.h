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
	/// Summary for ventanaReporteComprasCliente
	/// </summary>
	public ref class ventanaReporteComprasCliente : public System::Windows::Forms::Form
	{
	public:
		cargarArchivo* progra;
		ventanaReporteComprasCliente(cargarArchivo* progra)
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
		~ventanaReporteComprasCliente()
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
			this->button2->Location = System::Drawing::Point(175, 56);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 21;
			this->button2->Text = L"Cancelar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ventanaReporteComprasCliente::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(58, 57);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 20;
			this->button1->Text = L"Buscar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ventanaReporteComprasCliente::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(143, 15);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(167, 20);
			this->textBox1->TabIndex = 19;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(121, 13);
			this->label1->TabIndex = 18;
			this->label1->Text = L"Digite cedula de cliente:";
			// 
			// ventanaReporteComprasCliente
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(329, 88);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"ventanaReporteComprasCliente";
			this->Text = L"Reporte Compras de Cliente";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// Obtener texto de textBox and Insertar Producto
		String^ codStrCompra = textBox1->Text;
		if (!String::IsNullOrWhiteSpace(codStrCompra)) {
			int temp;
			int compras;
			Int32::TryParse(codStrCompra, temp);
			compras = progra->listaCliente->CompraDeCliente(temp, progra->listaCliente->raiz);
			if (compras == -1) {
				System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
					"Cliente no encontrado",
					"Error",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error);
			}
			else {
				System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
					"Cliente "+ temp + "\nHa comprado: " + compras + " veces.",
					"Error",
					MessageBoxButtons::OK,
					MessageBoxIcon::Information);
			}
		}
		else {
			System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
				"Ingrese cedula de cliente",
				"Error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error);
		}

	}
};
}
