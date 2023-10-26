#pragma once
#include "cargarArchivo.h"
#include <string>

//Popups
#include "ventanaPopupCiudades.h"
#include "ventanaPopupPaises.h"

namespace Interfaz {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ventanaPopupLugares
	/// </summary>
	public ref class ventanaPopupLugares : public System::Windows::Forms::Form
	{
	public:
		cargarArchivo* progra;
		bool^ flag;
		ventanaPopupLugares(cargarArchivo* progra, bool^ flag)
		{
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
		~ventanaPopupLugares()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Label^ label1;
	protected:
	public: System::Windows::Forms::Button^ button1;
	public: System::Windows::Forms::Label^ label2;
	public: System::Windows::Forms::Button^ button2;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		/// 
		
		ventanaPopupPaises^ popupPaises;
		ventanaPopupCiudades^ popupCiudades;

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ventanaPopupLugares::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(33, 111);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(45, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"PAISES";
			this->label1->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// button1
			// 
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->Location = System::Drawing::Point(12, 23);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(85, 85);
			this->button1->TabIndex = 6;
			this->button1->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ventanaPopupLugares::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(137, 111);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(62, 13);
			this->label2->TabIndex = 9;
			this->label2->Text = L"CIUDADES";
			this->label2->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// button2
			// 
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button2->Location = System::Drawing::Point(127, 23);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(85, 85);
			this->button2->TabIndex = 8;
			this->button2->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ventanaPopupLugares::button2_Click);
			// 
			// ventanaPopupLugares
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(224, 132);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"ventanaPopupLugares";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Lugares";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void popupPaises_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
		// Check if popupLugares is disposed before accessing it
		if (popupPaises != nullptr && !popupPaises->IsDisposed) {
			// Unsubscribe events
			popupPaises->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaPopupLugares::popupPaises_FormClosed);
			// Show the ventanaPrincipal form when ventanaMenu is closed
		}
		this->Show();
	}

	private: System::Void popupCiudades_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
		// Check if popupLugares is disposed before accessing it
		if (popupCiudades != nullptr && !popupCiudades->IsDisposed) {
			// Unsubscribe events
			popupCiudades->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaPopupLugares::popupCiudades_FormClosed);
			// Show the ventanaPrincipal form when ventanaMenu is closed
		}
		this->Show();
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		//text box para popupPaises
		if (*flag == true) {
			popupPaises = gcnew ventanaPopupPaises(progra, flag);
			popupPaises->FormClosed += gcnew FormClosedEventHandler(this, &ventanaPopupLugares::popupPaises_FormClosed);
			popupPaises->Show();
		}
		else {
			popupPaises = gcnew ventanaPopupPaises(progra, flag);
			popupPaises->button1->Enabled = false;
			popupPaises->button3->Enabled = false;
			popupPaises->button4->Enabled = false;
			popupPaises->FormClosed += gcnew FormClosedEventHandler(this, &ventanaPopupLugares::popupPaises_FormClosed);
			popupPaises->Show();
		}


	}

private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	//text box para popupPaises
	if (*flag == true) {
		popupCiudades = gcnew ventanaPopupCiudades(progra, flag);
		popupCiudades->FormClosed += gcnew FormClosedEventHandler(this, &ventanaPopupLugares::popupCiudades_FormClosed);
		popupCiudades->Show();
	}
	else {
		popupCiudades = gcnew ventanaPopupCiudades(progra, flag);
		popupCiudades->button1->Enabled = false;
		popupCiudades->button3->Enabled = false;
		popupCiudades->button4->Enabled = false;
		popupCiudades->FormClosed += gcnew FormClosedEventHandler(this, &ventanaPopupLugares::popupCiudades_FormClosed);
		popupCiudades->Show();
	}


}
};
}


