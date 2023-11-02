#pragma once
#include "cargarArchivo.h"
#include <string>

#include "ventanaComprar.h"

namespace Interfaz {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ventanaModificarCompra
	/// </summary>
	public ref class ventanaModificarCompra : public System::Windows::Forms::Form
	{
	public:
		String^ usuario;
		bool^ flag;
		cargarArchivo* progra;
		ventanaModificarCompra(cargarArchivo* progra, String^ usuario, bool^ flag)
		{
			this->usuario = usuario;
			this->flag = flag;
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
		~ventanaModificarCompra()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Button^ button1;
	public: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label1;
	public:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button3;
	protected:


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		
		ventanaComprar^ ventanaCompra;
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ventanaModificarCompra::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->Location = System::Drawing::Point(25, 23);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(85, 85);
			this->button1->TabIndex = 7;
			this->button1->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ventanaModificarCompra::button1_Click);
			// 
			// button2
			// 
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button2->Location = System::Drawing::Point(155, 23);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(85, 85);
			this->button2->TabIndex = 8;
			this->button2->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ventanaModificarCompra::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(36, 124);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(68, 13);
			this->label1->TabIndex = 9;
			this->label1->Text = L"PRODUCTO";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(162, 124);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(62, 13);
			this->label2->TabIndex = 10;
			this->label2->Text = L"CANTIDAD";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(92, 157);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 21;
			this->button3->Text = L"Cancelar";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &ventanaModificarCompra::button3_Click);
			// 
			// ventanaModificarCompra
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(264, 191);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"ventanaModificarCompra";
			this->Text = L"ventanaModificarCompra";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

private: System::Void ventanaComprar_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaPopupClientees is disposed before accessing it
	if (ventanaCompra != nullptr && !ventanaCompra->IsDisposed) {
		// Unsubscribe events
		ventanaCompra->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaModificarCompra::ventanaComprar_FormClosed);
		// Show the ventanaPrincipal form when ventanaPopupClientees is closed
	}
	this->Show();
}

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	//Cambia producto en compra
	int temp;
	Int32::TryParse(usuario, temp);

	progra->listaFila->BorrarNodo(temp);
	ventanaCompra = gcnew ventanaComprar(progra, usuario, flag);
	ventanaCompra->FormClosed += gcnew FormClosedEventHandler(this, &ventanaModificarCompra::ventanaComprar_FormClosed);
	ventanaCompra->Show();
	
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	//Cambia cantidad de producto
	//progra->listaFila.
}
};
}
