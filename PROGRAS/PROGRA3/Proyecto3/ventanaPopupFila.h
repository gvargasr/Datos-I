#pragma once
#include "cargarArchivo.h"
#include <string>

#include "ventanaComprar.h"
#include "ventanaEliminarCompra.h"
#include "ventanaModificarCompra.h"

namespace Interfaz {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ventanaPopupFila
	/// </summary>
	public ref class ventanaPopupFila : public System::Windows::Forms::Form
	{
	public:
		String^ usuario;
		bool^ flag;
		cargarArchivo* progra;
		ventanaPopupFila(cargarArchivo* progra, String^ usuario, bool^ flag)
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
		~ventanaPopupFila()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:



	public: System::Windows::Forms::Label^ label2;
	public: System::Windows::Forms::Button^ button2;
	public: System::Windows::Forms::Label^ label1;
	public: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button5;
	public: System::Windows::Forms::Label^ label3;
	private:
	public: System::Windows::Forms::Button^ button3;
	public:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		
		ventanaComprar^ ventanaCompra;
		ventanaPopupEliminarCompra^ ventanaEliminarCompra;
		ventanaModificarCompra^ ventanaModCompra;
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ventanaPopupFila::typeid));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(256, 104);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(107, 13);
			this->label2->TabIndex = 27;
			this->label2->Text = L"ELIMINAR COMPRA";
			this->label2->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// button2
			// 
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button2->Location = System::Drawing::Point(268, 16);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(85, 85);
			this->button2->TabIndex = 26;
			this->button2->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ventanaPopupFila::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(46, 104);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(61, 13);
			this->label1->TabIndex = 25;
			this->label1->Text = L"COMPRAR";
			this->label1->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// button1
			// 
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->Location = System::Drawing::Point(34, 16);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(85, 85);
			this->button1->TabIndex = 24;
			this->button1->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ventanaPopupFila::button1_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(158, 134);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 28;
			this->button5->Text = L"Cancelar";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &ventanaPopupFila::button5_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(136, 104);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(115, 13);
			this->label3->TabIndex = 30;
			this->label3->Text = L"MODIFICAR COMPRA";
			this->label3->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// button3
			// 
			this->button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.BackgroundImage")));
			this->button3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button3->Location = System::Drawing::Point(148, 16);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(85, 85);
			this->button3->TabIndex = 29;
			this->button3->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &ventanaPopupFila::button3_Click);
			// 
			// ventanaPopupFila
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(380, 160);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"ventanaPopupFila";
			this->Text = L"Fila";
			this->Load += gcnew System::EventHandler(this, &ventanaPopupFila::ventanaPopupFila_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ventanaPopupFila_Load(System::Object^ sender, System::EventArgs^ e) {
	}

private: System::Void ventanaComprar_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaPopupClientees is disposed before accessing it
	if (ventanaCompra != nullptr && !ventanaCompra->IsDisposed) {
		// Unsubscribe events
		ventanaCompra->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaPopupFila::ventanaComprar_FormClosed);
		// Show the ventanaPrincipal form when ventanaPopupClientees is closed
	}
	this->Show();
}

private: System::Void ventanaPopupEliminarCompra_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaPopupClientees is disposed before accessing it
	if (ventanaEliminarCompra != nullptr && !ventanaEliminarCompra->IsDisposed) {
		// Unsubscribe events
		ventanaEliminarCompra->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaPopupFila::ventanaPopupEliminarCompra_FormClosed);
		// Show the ventanaPrincipal form when ventanaPopupClientees is closed
	}
	this->Show();
}

private: System::Void ventanaModificarCompra_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaPopupClientees is disposed before accessing it
	if (ventanaModCompra != nullptr && !ventanaModCompra->IsDisposed) {
		// Unsubscribe events
		ventanaModCompra->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaPopupFila::ventanaModificarCompra_FormClosed);
		// Show the ventanaPrincipal form when ventanaPopupClientees is closed
	}
	this->Show();
}


private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	ventanaCompra = gcnew ventanaComprar(progra, usuario, flag);
	ventanaCompra->FormClosed += gcnew FormClosedEventHandler(this, &ventanaPopupFila::ventanaComprar_FormClosed);
	ventanaCompra->Show();
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	ventanaEliminarCompra = gcnew ventanaPopupEliminarCompra(progra, usuario, flag);
	ventanaEliminarCompra->FormClosed += gcnew FormClosedEventHandler(this, &ventanaPopupFila::ventanaPopupEliminarCompra_FormClosed);
	ventanaEliminarCompra->Show();
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	ventanaModCompra = gcnew ventanaModificarCompra(progra, usuario, flag);
	ventanaModCompra->FormClosed += gcnew FormClosedEventHandler(this, &ventanaPopupFila::ventanaModificarCompra_FormClosed);
	ventanaModCompra->Show();
}
};
}
