#pragma once
#include "cargarArchivo.h"
#include <string>

#include "ventanaInsertarMenu.h"
#include "ventanaBuscarMenu.h"
#include "ventanaModificarMenu.h"
#include "ventanaEliminarMenu.h"


namespace Interfaz {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ventanaPopupMenu
	/// </summary>
	public ref class ventanaPopupMenu : public System::Windows::Forms::Form
	{
	public:
		cargarArchivo* progra;
		ventanaPopupMenu(cargarArchivo* progra)
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
		~ventanaPopupMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Label^ label4;
	protected:
	public: System::Windows::Forms::Button^ button4;
	public: System::Windows::Forms::Label^ label3;
	public: System::Windows::Forms::Button^ button3;
	public: System::Windows::Forms::Label^ label2;
	public: System::Windows::Forms::Button^ button2;
	public: System::Windows::Forms::Label^ label1;
	public: System::Windows::Forms::Button^ button1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		
		ventanaInsertarMenu^ InsertarMenu;
		ventanaBuscarMenu^ BuscarMenu;
		ventanaModificarMenu^ ModificarMenu;
		ventanaEliminarMenu^ EliminarMenu;
		
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ventanaPopupMenu::typeid));
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(203, 245);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(58, 13);
			this->label4->TabIndex = 31;
			this->label4->Text = L"ELIMINAR";
			this->label4->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// button4
			// 
			this->button4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.BackgroundImage")));
			this->button4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button4->Location = System::Drawing::Point(182, 157);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(85, 85);
			this->button4->TabIndex = 30;
			this->button4->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &ventanaPopupMenu::button4_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(61, 245);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(66, 13);
			this->label3->TabIndex = 29;
			this->label3->Text = L"MODIFICAR";
			this->label3->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// button3
			// 
			this->button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.BackgroundImage")));
			this->button3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button3->Location = System::Drawing::Point(51, 157);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(85, 85);
			this->button3->TabIndex = 28;
			this->button3->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &ventanaPopupMenu::button3_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(203, 117);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 13);
			this->label2->TabIndex = 27;
			this->label2->Text = L"BUSCAR";
			this->label2->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// button2
			// 
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button2->Location = System::Drawing::Point(182, 29);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(85, 85);
			this->button2->TabIndex = 26;
			this->button2->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ventanaPopupMenu::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(63, 117);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(62, 13);
			this->label1->TabIndex = 25;
			this->label1->Text = L"INSERTAR";
			this->label1->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// button1
			// 
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->Location = System::Drawing::Point(51, 29);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(85, 85);
			this->button1->TabIndex = 24;
			this->button1->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ventanaPopupMenu::button1_Click);
			// 
			// ventanaPopupMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(318, 286);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"ventanaPopupMenu";
			this->Text = L"Menu";
			this->Load += gcnew System::EventHandler(this, &ventanaPopupMenu::ventanaPopupMenu_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ventanaPopupMenu_Load(System::Object^ sender, System::EventArgs^ e) {
	}


	private: System::Void ventanaInsertarMenu_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
		// Check if ventanaPopupMenues is disposed before accessing it
		if (InsertarMenu != nullptr && !InsertarMenu->IsDisposed) {
			// Unsubscribe events
			InsertarMenu->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaPopupMenu::ventanaInsertarMenu_FormClosed);
			// Show the ventanaPrincipal form when ventanaPopupMenues is closed
		}
		this->Show();
	}



	private: System::Void ventanaBuscarMenu_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
		// Check if ventanaBuscarMenu is disposed before accessing it
		if (BuscarMenu != nullptr && !BuscarMenu->IsDisposed) {
			// Unsubscribe events
			BuscarMenu->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaPopupMenu::ventanaBuscarMenu_FormClosed);
			// Show the ventanaPrincipal form when BuscarMenu is closed
		}
		this->Show();
	}



	private: System::Void ventanaModificarMenu_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
		// Check if ventanaModificarMenu is disposed before accessing it
		if (ModificarMenu != nullptr && !ModificarMenu->IsDisposed) {
			// Unsubscribe events
			ModificarMenu->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaPopupMenu::ventanaModificarMenu_FormClosed);
			// Show the ventanaPrincipal form when ModificarMenu is closed
		}
		this->Show();
	}



	private: System::Void ventanaEliminarMenu_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
		// Check if ventanaEliminarMenu is disposed before accessing it
		if (EliminarMenu != nullptr && !EliminarMenu->IsDisposed) {
			// Unsubscribe events
			EliminarMenu->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaPopupMenu::ventanaEliminarMenu_FormClosed);
			// Show the ventanaPrincipal form when EliminarMenu is closed
		}
		this->Show();
	}



private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	//text box para Insertar Menu
	InsertarMenu = gcnew ventanaInsertarMenu(progra);
	InsertarMenu->FormClosed += gcnew FormClosedEventHandler(this, &ventanaPopupMenu::ventanaInsertarMenu_FormClosed);
	InsertarMenu->Show();
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	//text box para Buscar Menu
	BuscarMenu = gcnew ventanaBuscarMenu(progra);
	BuscarMenu->FormClosed += gcnew FormClosedEventHandler(this, &ventanaPopupMenu::ventanaBuscarMenu_FormClosed);
	BuscarMenu->Show();
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	//text box para Modificar Menu
	ModificarMenu = gcnew ventanaModificarMenu(progra);
	ModificarMenu->FormClosed += gcnew FormClosedEventHandler(this, &ventanaPopupMenu::ventanaModificarMenu_FormClosed);
	ModificarMenu->Show();
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	//text box para Eliminar Menu
	EliminarMenu = gcnew ventanaEliminarMenu(progra);
	EliminarMenu->FormClosed += gcnew FormClosedEventHandler(this, &ventanaPopupMenu::ventanaEliminarMenu_FormClosed);
	EliminarMenu->Show();
}
};
}
