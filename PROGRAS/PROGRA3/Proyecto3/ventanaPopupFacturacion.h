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
	/// Summary for ventanaPopupFacturacion
	/// </summary>
	public ref class ventanaPopupFacturacion : public System::Windows::Forms::Form
	{
	public:
		cargarArchivo* progra;
		bool^ flag;
		String^ usuario;
		ventanaPopupFacturacion(cargarArchivo * progra, String ^ usuario, bool^ flag)
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
		~ventanaPopupFacturacion()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button3;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	public: System::Windows::Forms::Button^ button2;
	private:
	public: System::Windows::Forms::Button^ button1;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ventanaPopupFacturacion::typeid));
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(79, 158);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 26;
			this->button3->Text = L"Cancelar";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &ventanaPopupFacturacion::button3_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(149, 125);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(80, 13);
			this->label2->TabIndex = 25;
			this->label2->Text = L"PARA LLEVAR";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 125);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(75, 13);
			this->label1->TabIndex = 24;
			this->label1->Text = L"COMER AQUI";
			// 
			// button2
			// 
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button2->Location = System::Drawing::Point(142, 24);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(85, 85);
			this->button2->TabIndex = 23;
			this->button2->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ventanaPopupFacturacion::button2_Click);
			// 
			// button1
			// 
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->Location = System::Drawing::Point(12, 24);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(85, 85);
			this->button1->TabIndex = 22;
			this->button1->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ventanaPopupFacturacion::button1_Click);
			// 
			// ventanaPopupFacturacion
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(246, 202);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"ventanaPopupFacturacion";
			this->Text = L"Comprar";
			this->Load += gcnew System::EventHandler(this, &ventanaPopupFacturacion::ventanaPopupFacturacion_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ventanaPopupFacturacion_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	//Pagar para comer en local 1% desc
	pnodoFila aux = progra->listaFila->GetPrimero();

	if (aux != NULL) {
		cout << "Productos comprados: " << endl;
		aux->listaComp->Mostrar();
		cout << "Precio (Sin desc): " << endl;
		cout << aux->listaComp->CalcularPrecio() << endl;
		cout << "Precio (Con desc): " << endl;
		int precioFin = aux->listaComp->CalcularPrecio();
		precioFin = precioFin - ((precioFin / 100) * 1);
		cout << precioFin << endl;
		ofstream archivo_salida("Fact" + to_string(aux->valor) + ".txt");
		if (!archivo_salida.is_open()) {
			cerr << "Error generando el archivo." << endl;
		}
		archivo_salida << "\t.:Factura del cliente:." << endl << endl << endl;
		archivo_salida << "Cedula: " << aux->valor << "\n" << aux->listaComp->Mostrar() << "\n Total: " << precioFin << "\n" << endl << endl;

		archivo_salida.close();
		cout << "Factura generada";
		/*	int FactAct = aux->listaComp->CalcularPrecio();
			int FactGra = FacturaGrande->listaComp->CalcularPrecio();
			int FactPeq = FacturaPequena->listaComp->CalcularPrecio();
			if (FacturaGrande == NULL || FacturaPequena == NULL){
				FacturaGrande = aux;
				FacturaPequena = aux;
				FacturaGrande->valor = cedula;
				FacturaPequena->valor = cedula;
			} else {
				if (aux->listaComp->CalcularPrecio() > FacturaGrande->listaComp->CalcularPrecio()){
					FacturaGrande = aux;
					FacturaGrande->valor = cedula;
				}
				if (aux->listaComp->CalcularPrecio() < FacturaPequena->listaComp->CalcularPrecio()){
					FacturaPequena = aux;
					FacturaPequena->valor = cedula;
				}
			}*/
		System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
			"Cedula: " + aux->valor + "\nMonto: " + precioFin,
			"Compra generada",
			MessageBoxButtons::OK,
			MessageBoxIcon::Information);
		progra->listaFila->BorrarInicio();
	}
	else {
		System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
			"No hay clientes en la fila",
			"Error",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error);
	}

}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	//Pagar para llevar 3% desc
	pnodoFila aux = progra->listaFila->GetPrimero();
	if (aux != NULL) {
		cout << "Productos comprados: " << endl;
		aux->listaComp->Mostrar();
		cout << "Precio (Sin desc): " << endl;
		cout << aux->listaComp->CalcularPrecio() << endl;
		cout << "Precio (Con desc): " << endl;
		int precioFin = aux->listaComp->CalcularPrecio();
		precioFin = precioFin - ((precioFin / 100) * 3);
		cout << precioFin << endl;
		ofstream archivo_salida("Fact" + to_string(aux->valor) + ".txt");
		if (!archivo_salida.is_open()) {
			cerr << "Error generando el archivo." << endl;
		}
		archivo_salida << "\t.:Factura del cliente:." << endl << endl << endl;
		archivo_salida << "Cedula: " << aux->valor << "\n" << aux->listaComp->Mostrar() << "\n Total: " << precioFin << "\n" << endl << endl;

		archivo_salida.close();
		cout << "Factura generada";
		//int FactAct = aux->listaComp->CalcularPrecio();
		//int FactGra = FacturaGrande->listaComp->CalcularPrecio();
		//int FactPeq = FacturaPequena->listaComp->CalcularPrecio();
		//if (FacturaGrande == NULL || FacturaPequena == NULL){
		//	FacturaGrande = aux;
		//	FacturaPequena = aux;
		//} else {
		//	if (FactAct > FactGra){
		//		FacturaGrande = aux;
		//	} else {
		//		
		//	}
		//	if (FactAct < FactPeq){
		//		FacturaPequena = aux;
		//	} else{
		//		
		//	}
		//}
		System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
			"Cedula: " + aux->valor + "\nMonto: " + precioFin,
			"Compra generada",
			MessageBoxButtons::OK,
			MessageBoxIcon::Information);
		progra->listaFila->BorrarInicio();
	}
	else {
		System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
			"No hay clientes en la fila",
			"Error",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error);
	}
}
};
}
