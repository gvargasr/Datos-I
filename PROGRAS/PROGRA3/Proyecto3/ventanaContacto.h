#pragma once

#include <iostream>
#include <string>
#include <fstream>

using namespace std; 

namespace Interfaz {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for contacto
	/// </summary>
	public ref class contacto : public System::Windows::Forms::Form
	{
	public:
		contacto(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~contacto()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Button^ AceptarContacto;

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox4;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->AceptarContacto = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(13, 42);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(59, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Nombre:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(13, 69);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Correo:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(13, 95);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(64, 16);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Telefono:";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(83, 38);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(254, 22);
			this->textBox1->TabIndex = 3;
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(83, 65);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(254, 22);
			this->textBox2->TabIndex = 4;
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(83, 91);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(113, 22);
			this->textBox3->TabIndex = 5;
			// 
			// AceptarContacto
			// 
			this->AceptarContacto->Location = System::Drawing::Point(83, 248);
			this->AceptarContacto->Name = L"AceptarContacto";
			this->AceptarContacto->Size = System::Drawing::Size(75, 23);
			this->AceptarContacto->TabIndex = 6;
			this->AceptarContacto->Text = L"Aceptar";
			this->AceptarContacto->UseVisualStyleBackColor = true;
			this->AceptarContacto->Click += gcnew System::EventHandler(this, &contacto::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(206, 248);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Cancelar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &contacto::button2_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(13, 131);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(79, 16);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Comentario:";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(16, 151);
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(321, 91);
			this->textBox4->TabIndex = 9;
			// 
			// contacto
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(394, 287);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->AceptarContacto);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"contacto";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Formulario de contacto";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		//Aceptar y guardar la informacion
		String^ nombre = this->textBox1->Text;
		String^ correo = this->textBox2->Text;
		String^ telefono = this->textBox3->Text;
		String^ comentario = this->textBox4->Text;

		char cStr1[50] = { 0 };
		char cStr2[50] = { 0 };
		char cStr3[50] = { 0 };
		char cStr4[500] = { 0 };


		String^ clrString = nombre;
		sprintf_s(cStr1, "%s", clrString);
		std::string stlString(cStr1);

		String^ clrString2 = correo;
		sprintf_s(cStr2, "%s", clrString2);
		std::string stlString2(cStr2);
		
		String^ clrString3 = telefono;
		sprintf_s(cStr3, "%s", clrString3);
		std::string stlString3(cStr3);
		
		String^ clrString4 = comentario;
		sprintf_s(cStr4, "%s", clrString4);
		std::string stlString4(cStr4);

		ofstream outFile("Contacto.txt", ios::app);
		outFile << "\t.: Contacto :." << endl << endl << endl;
		if (outFile.is_open()) {
			outFile << "--Nombre: " << cStr1 << endl;
			outFile << "--Correo: " << cStr2 << endl;
			outFile << "--Telefono: " << cStr3 << endl;
			outFile << "--Comentario:\n" << cStr4 << endl;
			outFile << "\n\n####################################\n\n\n\n\n\n";
			cout << "Informacion guardada " << endl;
		}
		else {
			cout << "No se pudo abrir el archivo." << endl;
		}
		outFile.close();
		this->Close();
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		//cancelar y cerrar ventana
	this->Close();
}
};
}
