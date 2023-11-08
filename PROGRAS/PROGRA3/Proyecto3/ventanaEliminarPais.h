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
	/// Summary for ventanaEliminarPais
	/// </summary>
	public ref class ventanaEliminarPais : public System::Windows::Forms::Form
	{
	public:
		cargarArchivo* progra;
		ventanaEliminarPais(cargarArchivo* progra)
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
		~ventanaEliminarPais()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::TextBox^ textBox1;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	protected:

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(110, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Digite codigo de Pais:";
			this->label1->Click += gcnew System::EventHandler(this, &ventanaEliminarPais::label1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(144, 5);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(167, 20);
			this->textBox1->TabIndex = 2;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(61, 47);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Aceptar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ventanaEliminarPais::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(178, 46);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Cancelar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ventanaEliminarPais::button2_Click);
			// 
			// ventanaEliminarPais
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(336, 85);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"ventanaEliminarPais";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Eliminar Pais";
			this->Load += gcnew System::EventHandler(this, &ventanaEliminarPais::ventanaEliminarPais_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ventanaEliminarPais_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
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
				"Pais Eliminado",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information);
			this->Close();
			cout << "\n.:Pais Eliminado:.\nCodigo: " << aux->valor << "\nNombre: " << aux->pais << endl;
			progra->listaPaisEliminado->InsertarClave(aux->valor, aux->pais, progra->listaPaisEliminado->raiz);
			progra->listaPais->EliminarPais(progra->listaPais->raiz, temp);
		}
		else {
			System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
				"Codigo: " + temp,
				"Pais No Eliminado",
				MessageBoxButtons::OK,
				MessageBoxIcon::Warning);
			cout << "El pais " << temp << " no se encuentra" << endl;
		}

	}
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
