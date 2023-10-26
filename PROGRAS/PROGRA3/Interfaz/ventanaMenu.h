#pragma once

namespace Interfaz {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ventanaMenu
	/// </summary>
	public ref class ventanaMenu : public System::Windows::Forms::Form
	{
	public:
		ventanaMenu(void)
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
		~ventanaMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ToolStrip^ toolStrip1;
	protected:




	private: System::Windows::Forms::ToolStripDropDownButton^ toolStripButton1;





	private: System::Windows::Forms::ToolStripMenuItem^ salirToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripDropDownButton^ toolStripButton2;

	private: System::Windows::Forms::ToolStripButton^ toolStripButton3;
	private: System::Windows::Forms::ToolStripMenuItem^ insertarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ buscarToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ modificarToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ eliminarToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripDropDownButton^ toolStripButton4;
	private: System::Windows::Forms::ToolStripMenuItem^ paisesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ciudadesToolStripMenuItem;

	private: System::Windows::Forms::ToolStripDropDownButton^ toolStripButton5;
	private: System::Windows::Forms::ToolStripDropDownButton^ toolStripButton7;
	private: System::Windows::Forms::ToolStripMenuItem^ informacionDeLaEmpresaToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ menuToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ productosToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ clientesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ comprasToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ listaDeClientesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ comprasDeUnClienteToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ restaurantesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ listaDeRestaurantesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ restauranteMasBuscadoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ precioDeProductoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ cantidadDeProductoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ facturacionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ facturaDeMayorMontoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ facturaDeMenorMontoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ descuentoConTarjetaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ eliminacionesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ paisesEliminadosToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ciudadesEliminadasToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ restaurantesEliminadosToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ menusEliminadosToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ productosEliminadosToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ comprarProductoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ eliminarCompraToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ paisToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ciudadToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ restauranteToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ menuToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ productoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ clienteToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ paisToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ ciudadToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ restauranteToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ menuToolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^ productoToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ clienteToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ administradorToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ paisToolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^ ciudadToolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^ restauranteToolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^ menuToolStripMenuItem3;
	private: System::Windows::Forms::ToolStripMenuItem^ productoToolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^ clienteToolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^ administradorToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ paisToolStripMenuItem3;
	private: System::Windows::Forms::ToolStripMenuItem^ ciudadToolStripMenuItem3;
	private: System::Windows::Forms::ToolStripMenuItem^ restauranteToolStripMenuItem3;
	private: System::Windows::Forms::ToolStripMenuItem^ menuToolStripMenuItem4;
	private: System::Windows::Forms::ToolStripMenuItem^ productoToolStripMenuItem3;
	private: System::Windows::Forms::ToolStripMenuItem^ clienteToolStripMenuItem3;
	private: System::Windows::Forms::ToolStripMenuItem^ administradorToolStripMenuItem2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Label^ label1;
private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::Label^ label3;
private: System::Windows::Forms::Label^ label4;
private: System::Windows::Forms::ToolStripMenuItem^ leerArchivosToolStripMenuItem;



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ventanaMenu::typeid));
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->leerArchivosToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->salirToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripButton2 = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->insertarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->paisToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ciudadToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->restauranteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->productoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clienteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->buscarToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->paisToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ciudadToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->restauranteToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->productoToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clienteToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->administradorToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->modificarToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->paisToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ciudadToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->restauranteToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuToolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->productoToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clienteToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->administradorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->eliminarToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->paisToolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ciudadToolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->restauranteToolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuToolStripMenuItem4 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->productoToolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clienteToolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->administradorToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripButton4 = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->paisesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ciudadesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->restaurantesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->listaDeRestaurantesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->restauranteMasBuscadoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->productosToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->precioDeProductoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cantidadDeProductoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clientesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->listaDeClientesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->comprasDeUnClienteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->comprasToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->facturacionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->facturaDeMayorMontoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->facturaDeMenorMontoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->descuentoConTarjetaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->eliminacionesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->paisesEliminadosToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ciudadesEliminadasToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->restaurantesEliminadosToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menusEliminadosToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->productosEliminadosToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripButton5 = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->comprarProductoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->eliminarCompraToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripButton7 = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->informacionDeLaEmpresaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripButton3 = (gcnew System::Windows::Forms::ToolStripButton());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->toolStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// toolStrip1
			// 
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->toolStripButton1,
					this->toolStripButton2, this->toolStripButton4, this->toolStripButton5, this->toolStripButton7, this->toolStripButton3
			});
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(602, 25);
			this->toolStrip1->TabIndex = 0;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripButton1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->leerArchivosToolStripMenuItem,
					this->salirToolStripMenuItem1
			});
			this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton1.Image")));
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(51, 22);
			this->toolStripButton1->Text = L"Menu";
			// 
			// leerArchivosToolStripMenuItem
			// 
			this->leerArchivosToolStripMenuItem->Name = L"leerArchivosToolStripMenuItem";
			this->leerArchivosToolStripMenuItem->Size = System::Drawing::Size(145, 22);
			this->leerArchivosToolStripMenuItem->Text = L"Leer Archivos";
			// 
			// salirToolStripMenuItem1
			// 
			this->salirToolStripMenuItem1->Name = L"salirToolStripMenuItem1";
			this->salirToolStripMenuItem1->Size = System::Drawing::Size(145, 22);
			this->salirToolStripMenuItem1->Text = L"Salir";
			// 
			// toolStripButton2
			// 
			this->toolStripButton2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripButton2->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->insertarToolStripMenuItem,
					this->buscarToolStripMenuItem1, this->modificarToolStripMenuItem1, this->eliminarToolStripMenuItem1
			});
			this->toolStripButton2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton2.Image")));
			this->toolStripButton2->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton2->Name = L"toolStripButton2";
			this->toolStripButton2->Size = System::Drawing::Size(102, 22);
			this->toolStripButton2->Text = L"Mantenimiento";
			// 
			// insertarToolStripMenuItem
			// 
			this->insertarToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->paisToolStripMenuItem,
					this->ciudadToolStripMenuItem, this->restauranteToolStripMenuItem, this->menuToolStripMenuItem1, this->productoToolStripMenuItem,
					this->clienteToolStripMenuItem
			});
			this->insertarToolStripMenuItem->Name = L"insertarToolStripMenuItem";
			this->insertarToolStripMenuItem->Size = System::Drawing::Size(125, 22);
			this->insertarToolStripMenuItem->Text = L"Insertar";
			// 
			// paisToolStripMenuItem
			// 
			this->paisToolStripMenuItem->Name = L"paisToolStripMenuItem";
			this->paisToolStripMenuItem->Size = System::Drawing::Size(136, 22);
			this->paisToolStripMenuItem->Text = L"Pais";
			// 
			// ciudadToolStripMenuItem
			// 
			this->ciudadToolStripMenuItem->Name = L"ciudadToolStripMenuItem";
			this->ciudadToolStripMenuItem->Size = System::Drawing::Size(136, 22);
			this->ciudadToolStripMenuItem->Text = L"Ciudad";
			// 
			// restauranteToolStripMenuItem
			// 
			this->restauranteToolStripMenuItem->Name = L"restauranteToolStripMenuItem";
			this->restauranteToolStripMenuItem->Size = System::Drawing::Size(136, 22);
			this->restauranteToolStripMenuItem->Text = L"Restaurante";
			// 
			// menuToolStripMenuItem1
			// 
			this->menuToolStripMenuItem1->Name = L"menuToolStripMenuItem1";
			this->menuToolStripMenuItem1->Size = System::Drawing::Size(136, 22);
			this->menuToolStripMenuItem1->Text = L"Menu";
			// 
			// productoToolStripMenuItem
			// 
			this->productoToolStripMenuItem->Name = L"productoToolStripMenuItem";
			this->productoToolStripMenuItem->Size = System::Drawing::Size(136, 22);
			this->productoToolStripMenuItem->Text = L"Producto";
			// 
			// clienteToolStripMenuItem
			// 
			this->clienteToolStripMenuItem->Name = L"clienteToolStripMenuItem";
			this->clienteToolStripMenuItem->Size = System::Drawing::Size(136, 22);
			this->clienteToolStripMenuItem->Text = L"Cliente";
			// 
			// buscarToolStripMenuItem1
			// 
			this->buscarToolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->paisToolStripMenuItem1,
					this->ciudadToolStripMenuItem1, this->restauranteToolStripMenuItem1, this->menuToolStripMenuItem2, this->productoToolStripMenuItem1,
					this->clienteToolStripMenuItem1, this->administradorToolStripMenuItem1
			});
			this->buscarToolStripMenuItem1->Name = L"buscarToolStripMenuItem1";
			this->buscarToolStripMenuItem1->Size = System::Drawing::Size(125, 22);
			this->buscarToolStripMenuItem1->Text = L"Buscar";
			// 
			// paisToolStripMenuItem1
			// 
			this->paisToolStripMenuItem1->Name = L"paisToolStripMenuItem1";
			this->paisToolStripMenuItem1->Size = System::Drawing::Size(150, 22);
			this->paisToolStripMenuItem1->Text = L"Pais";
			// 
			// ciudadToolStripMenuItem1
			// 
			this->ciudadToolStripMenuItem1->Name = L"ciudadToolStripMenuItem1";
			this->ciudadToolStripMenuItem1->Size = System::Drawing::Size(150, 22);
			this->ciudadToolStripMenuItem1->Text = L"Ciudad";
			// 
			// restauranteToolStripMenuItem1
			// 
			this->restauranteToolStripMenuItem1->Name = L"restauranteToolStripMenuItem1";
			this->restauranteToolStripMenuItem1->Size = System::Drawing::Size(150, 22);
			this->restauranteToolStripMenuItem1->Text = L"Restaurante";
			// 
			// menuToolStripMenuItem2
			// 
			this->menuToolStripMenuItem2->Name = L"menuToolStripMenuItem2";
			this->menuToolStripMenuItem2->Size = System::Drawing::Size(150, 22);
			this->menuToolStripMenuItem2->Text = L"Menu";
			// 
			// productoToolStripMenuItem1
			// 
			this->productoToolStripMenuItem1->Name = L"productoToolStripMenuItem1";
			this->productoToolStripMenuItem1->Size = System::Drawing::Size(150, 22);
			this->productoToolStripMenuItem1->Text = L"Producto";
			// 
			// clienteToolStripMenuItem1
			// 
			this->clienteToolStripMenuItem1->Name = L"clienteToolStripMenuItem1";
			this->clienteToolStripMenuItem1->Size = System::Drawing::Size(150, 22);
			this->clienteToolStripMenuItem1->Text = L"Cliente";
			// 
			// administradorToolStripMenuItem1
			// 
			this->administradorToolStripMenuItem1->Name = L"administradorToolStripMenuItem1";
			this->administradorToolStripMenuItem1->Size = System::Drawing::Size(150, 22);
			this->administradorToolStripMenuItem1->Text = L"Administrador";
			// 
			// modificarToolStripMenuItem1
			// 
			this->modificarToolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->paisToolStripMenuItem2,
					this->ciudadToolStripMenuItem2, this->restauranteToolStripMenuItem2, this->menuToolStripMenuItem3, this->productoToolStripMenuItem2,
					this->clienteToolStripMenuItem2, this->administradorToolStripMenuItem
			});
			this->modificarToolStripMenuItem1->Name = L"modificarToolStripMenuItem1";
			this->modificarToolStripMenuItem1->Size = System::Drawing::Size(125, 22);
			this->modificarToolStripMenuItem1->Text = L"Modificar";
			// 
			// paisToolStripMenuItem2
			// 
			this->paisToolStripMenuItem2->Name = L"paisToolStripMenuItem2";
			this->paisToolStripMenuItem2->Size = System::Drawing::Size(150, 22);
			this->paisToolStripMenuItem2->Text = L"Pais";
			// 
			// ciudadToolStripMenuItem2
			// 
			this->ciudadToolStripMenuItem2->Name = L"ciudadToolStripMenuItem2";
			this->ciudadToolStripMenuItem2->Size = System::Drawing::Size(150, 22);
			this->ciudadToolStripMenuItem2->Text = L"Ciudad";
			// 
			// restauranteToolStripMenuItem2
			// 
			this->restauranteToolStripMenuItem2->Name = L"restauranteToolStripMenuItem2";
			this->restauranteToolStripMenuItem2->Size = System::Drawing::Size(150, 22);
			this->restauranteToolStripMenuItem2->Text = L"Restaurante";
			// 
			// menuToolStripMenuItem3
			// 
			this->menuToolStripMenuItem3->Name = L"menuToolStripMenuItem3";
			this->menuToolStripMenuItem3->Size = System::Drawing::Size(150, 22);
			this->menuToolStripMenuItem3->Text = L"Menu";
			// 
			// productoToolStripMenuItem2
			// 
			this->productoToolStripMenuItem2->Name = L"productoToolStripMenuItem2";
			this->productoToolStripMenuItem2->Size = System::Drawing::Size(150, 22);
			this->productoToolStripMenuItem2->Text = L"Producto";
			// 
			// clienteToolStripMenuItem2
			// 
			this->clienteToolStripMenuItem2->Name = L"clienteToolStripMenuItem2";
			this->clienteToolStripMenuItem2->Size = System::Drawing::Size(150, 22);
			this->clienteToolStripMenuItem2->Text = L"Cliente";
			// 
			// administradorToolStripMenuItem
			// 
			this->administradorToolStripMenuItem->Name = L"administradorToolStripMenuItem";
			this->administradorToolStripMenuItem->Size = System::Drawing::Size(150, 22);
			this->administradorToolStripMenuItem->Text = L"Administrador";
			// 
			// eliminarToolStripMenuItem1
			// 
			this->eliminarToolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->paisToolStripMenuItem3,
					this->ciudadToolStripMenuItem3, this->restauranteToolStripMenuItem3, this->menuToolStripMenuItem4, this->productoToolStripMenuItem3,
					this->clienteToolStripMenuItem3, this->administradorToolStripMenuItem2
			});
			this->eliminarToolStripMenuItem1->Name = L"eliminarToolStripMenuItem1";
			this->eliminarToolStripMenuItem1->Size = System::Drawing::Size(125, 22);
			this->eliminarToolStripMenuItem1->Text = L"Eliminar";
			// 
			// paisToolStripMenuItem3
			// 
			this->paisToolStripMenuItem3->Name = L"paisToolStripMenuItem3";
			this->paisToolStripMenuItem3->Size = System::Drawing::Size(150, 22);
			this->paisToolStripMenuItem3->Text = L"Pais";
			// 
			// ciudadToolStripMenuItem3
			// 
			this->ciudadToolStripMenuItem3->Name = L"ciudadToolStripMenuItem3";
			this->ciudadToolStripMenuItem3->Size = System::Drawing::Size(150, 22);
			this->ciudadToolStripMenuItem3->Text = L"Ciudad";
			// 
			// restauranteToolStripMenuItem3
			// 
			this->restauranteToolStripMenuItem3->Name = L"restauranteToolStripMenuItem3";
			this->restauranteToolStripMenuItem3->Size = System::Drawing::Size(150, 22);
			this->restauranteToolStripMenuItem3->Text = L"Restaurante";
			// 
			// menuToolStripMenuItem4
			// 
			this->menuToolStripMenuItem4->Name = L"menuToolStripMenuItem4";
			this->menuToolStripMenuItem4->Size = System::Drawing::Size(150, 22);
			this->menuToolStripMenuItem4->Text = L"Menu";
			// 
			// productoToolStripMenuItem3
			// 
			this->productoToolStripMenuItem3->Name = L"productoToolStripMenuItem3";
			this->productoToolStripMenuItem3->Size = System::Drawing::Size(150, 22);
			this->productoToolStripMenuItem3->Text = L"Producto";
			// 
			// clienteToolStripMenuItem3
			// 
			this->clienteToolStripMenuItem3->Name = L"clienteToolStripMenuItem3";
			this->clienteToolStripMenuItem3->Size = System::Drawing::Size(150, 22);
			this->clienteToolStripMenuItem3->Text = L"Cliente";
			// 
			// administradorToolStripMenuItem2
			// 
			this->administradorToolStripMenuItem2->Name = L"administradorToolStripMenuItem2";
			this->administradorToolStripMenuItem2->Size = System::Drawing::Size(150, 22);
			this->administradorToolStripMenuItem2->Text = L"Administrador";
			// 
			// toolStripButton4
			// 
			this->toolStripButton4->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripButton4->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(9) {
				this->paisesToolStripMenuItem,
					this->ciudadesToolStripMenuItem, this->restaurantesToolStripMenuItem, this->menuToolStripMenuItem, this->productosToolStripMenuItem,
					this->clientesToolStripMenuItem, this->comprasToolStripMenuItem, this->facturacionToolStripMenuItem, this->eliminacionesToolStripMenuItem
			});
			this->toolStripButton4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton4.Image")));
			this->toolStripButton4->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton4->Name = L"toolStripButton4";
			this->toolStripButton4->Size = System::Drawing::Size(66, 22);
			this->toolStripButton4->Text = L"Reportes";
			// 
			// paisesToolStripMenuItem
			// 
			this->paisesToolStripMenuItem->Name = L"paisesToolStripMenuItem";
			this->paisesToolStripMenuItem->Size = System::Drawing::Size(193, 22);
			this->paisesToolStripMenuItem->Text = L"Paises";
			// 
			// ciudadesToolStripMenuItem
			// 
			this->ciudadesToolStripMenuItem->Name = L"ciudadesToolStripMenuItem";
			this->ciudadesToolStripMenuItem->Size = System::Drawing::Size(193, 22);
			this->ciudadesToolStripMenuItem->Text = L"Ciudades";
			// 
			// restaurantesToolStripMenuItem
			// 
			this->restaurantesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->listaDeRestaurantesToolStripMenuItem,
					this->restauranteMasBuscadoToolStripMenuItem
			});
			this->restaurantesToolStripMenuItem->Name = L"restaurantesToolStripMenuItem";
			this->restaurantesToolStripMenuItem->Size = System::Drawing::Size(193, 22);
			this->restaurantesToolStripMenuItem->Text = L"Restaurantes";
			// 
			// listaDeRestaurantesToolStripMenuItem
			// 
			this->listaDeRestaurantesToolStripMenuItem->Name = L"listaDeRestaurantesToolStripMenuItem";
			this->listaDeRestaurantesToolStripMenuItem->Size = System::Drawing::Size(209, 22);
			this->listaDeRestaurantesToolStripMenuItem->Text = L"Lista de Restaurantes";
			// 
			// restauranteMasBuscadoToolStripMenuItem
			// 
			this->restauranteMasBuscadoToolStripMenuItem->Name = L"restauranteMasBuscadoToolStripMenuItem";
			this->restauranteMasBuscadoToolStripMenuItem->Size = System::Drawing::Size(209, 22);
			this->restauranteMasBuscadoToolStripMenuItem->Text = L"Restaurante mas buscado";
			// 
			// menuToolStripMenuItem
			// 
			this->menuToolStripMenuItem->Name = L"menuToolStripMenuItem";
			this->menuToolStripMenuItem->Size = System::Drawing::Size(193, 22);
			this->menuToolStripMenuItem->Text = L"Menus";
			// 
			// productosToolStripMenuItem
			// 
			this->productosToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->precioDeProductoToolStripMenuItem,
					this->cantidadDeProductoToolStripMenuItem
			});
			this->productosToolStripMenuItem->Name = L"productosToolStripMenuItem";
			this->productosToolStripMenuItem->Size = System::Drawing::Size(193, 22);
			this->productosToolStripMenuItem->Text = L"Productos";
			// 
			// precioDeProductoToolStripMenuItem
			// 
			this->precioDeProductoToolStripMenuItem->Name = L"precioDeProductoToolStripMenuItem";
			this->precioDeProductoToolStripMenuItem->Size = System::Drawing::Size(190, 22);
			this->precioDeProductoToolStripMenuItem->Text = L"Precio de producto";
			// 
			// cantidadDeProductoToolStripMenuItem
			// 
			this->cantidadDeProductoToolStripMenuItem->Name = L"cantidadDeProductoToolStripMenuItem";
			this->cantidadDeProductoToolStripMenuItem->Size = System::Drawing::Size(190, 22);
			this->cantidadDeProductoToolStripMenuItem->Text = L"Cantidad de producto";
			// 
			// clientesToolStripMenuItem
			// 
			this->clientesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->listaDeClientesToolStripMenuItem,
					this->comprasDeUnClienteToolStripMenuItem
			});
			this->clientesToolStripMenuItem->Name = L"clientesToolStripMenuItem";
			this->clientesToolStripMenuItem->Size = System::Drawing::Size(193, 22);
			this->clientesToolStripMenuItem->Text = L"Clientes";
			// 
			// listaDeClientesToolStripMenuItem
			// 
			this->listaDeClientesToolStripMenuItem->Name = L"listaDeClientesToolStripMenuItem";
			this->listaDeClientesToolStripMenuItem->Size = System::Drawing::Size(195, 22);
			this->listaDeClientesToolStripMenuItem->Text = L"Lista de Clientes";
			// 
			// comprasDeUnClienteToolStripMenuItem
			// 
			this->comprasDeUnClienteToolStripMenuItem->Name = L"comprasDeUnClienteToolStripMenuItem";
			this->comprasDeUnClienteToolStripMenuItem->Size = System::Drawing::Size(195, 22);
			this->comprasDeUnClienteToolStripMenuItem->Text = L"Compras de un Cliente";
			// 
			// comprasToolStripMenuItem
			// 
			this->comprasToolStripMenuItem->Name = L"comprasToolStripMenuItem";
			this->comprasToolStripMenuItem->Size = System::Drawing::Size(193, 22);
			this->comprasToolStripMenuItem->Text = L"Compras de un cliente";
			// 
			// facturacionToolStripMenuItem
			// 
			this->facturacionToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->facturaDeMayorMontoToolStripMenuItem,
					this->facturaDeMenorMontoToolStripMenuItem, this->descuentoConTarjetaToolStripMenuItem
			});
			this->facturacionToolStripMenuItem->Name = L"facturacionToolStripMenuItem";
			this->facturacionToolStripMenuItem->Size = System::Drawing::Size(193, 22);
			this->facturacionToolStripMenuItem->Text = L"Facturacion";
			// 
			// facturaDeMayorMontoToolStripMenuItem
			// 
			this->facturaDeMayorMontoToolStripMenuItem->Name = L"facturaDeMayorMontoToolStripMenuItem";
			this->facturaDeMayorMontoToolStripMenuItem->Size = System::Drawing::Size(243, 22);
			this->facturaDeMayorMontoToolStripMenuItem->Text = L"Factura de mayor monto";
			// 
			// facturaDeMenorMontoToolStripMenuItem
			// 
			this->facturaDeMenorMontoToolStripMenuItem->Name = L"facturaDeMenorMontoToolStripMenuItem";
			this->facturaDeMenorMontoToolStripMenuItem->Size = System::Drawing::Size(243, 22);
			this->facturaDeMenorMontoToolStripMenuItem->Text = L"Factura de menor monto";
			// 
			// descuentoConTarjetaToolStripMenuItem
			// 
			this->descuentoConTarjetaToolStripMenuItem->Name = L"descuentoConTarjetaToolStripMenuItem";
			this->descuentoConTarjetaToolStripMenuItem->Size = System::Drawing::Size(243, 22);
			this->descuentoConTarjetaToolStripMenuItem->Text = L"Descuento por pagar con tarjeta";
			// 
			// eliminacionesToolStripMenuItem
			// 
			this->eliminacionesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->paisesEliminadosToolStripMenuItem,
					this->ciudadesEliminadasToolStripMenuItem, this->restaurantesEliminadosToolStripMenuItem, this->menusEliminadosToolStripMenuItem,
					this->productosEliminadosToolStripMenuItem
			});
			this->eliminacionesToolStripMenuItem->Name = L"eliminacionesToolStripMenuItem";
			this->eliminacionesToolStripMenuItem->Size = System::Drawing::Size(193, 22);
			this->eliminacionesToolStripMenuItem->Text = L"Eliminaciones";
			// 
			// paisesEliminadosToolStripMenuItem
			// 
			this->paisesEliminadosToolStripMenuItem->Name = L"paisesEliminadosToolStripMenuItem";
			this->paisesEliminadosToolStripMenuItem->Size = System::Drawing::Size(202, 22);
			this->paisesEliminadosToolStripMenuItem->Text = L"Paises eliminados";
			// 
			// ciudadesEliminadasToolStripMenuItem
			// 
			this->ciudadesEliminadasToolStripMenuItem->Name = L"ciudadesEliminadasToolStripMenuItem";
			this->ciudadesEliminadasToolStripMenuItem->Size = System::Drawing::Size(202, 22);
			this->ciudadesEliminadasToolStripMenuItem->Text = L"Ciudades eliminadas";
			// 
			// restaurantesEliminadosToolStripMenuItem
			// 
			this->restaurantesEliminadosToolStripMenuItem->Name = L"restaurantesEliminadosToolStripMenuItem";
			this->restaurantesEliminadosToolStripMenuItem->Size = System::Drawing::Size(202, 22);
			this->restaurantesEliminadosToolStripMenuItem->Text = L"Restaurantes eliminados";
			// 
			// menusEliminadosToolStripMenuItem
			// 
			this->menusEliminadosToolStripMenuItem->Name = L"menusEliminadosToolStripMenuItem";
			this->menusEliminadosToolStripMenuItem->Size = System::Drawing::Size(202, 22);
			this->menusEliminadosToolStripMenuItem->Text = L"Menus eliminados";
			// 
			// productosEliminadosToolStripMenuItem
			// 
			this->productosEliminadosToolStripMenuItem->Name = L"productosEliminadosToolStripMenuItem";
			this->productosEliminadosToolStripMenuItem->Size = System::Drawing::Size(202, 22);
			this->productosEliminadosToolStripMenuItem->Text = L"Productos eliminados";
			// 
			// toolStripButton5
			// 
			this->toolStripButton5->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripButton5->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->comprarProductoToolStripMenuItem,
					this->eliminarCompraToolStripMenuItem
			});
			this->toolStripButton5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton5.Image")));
			this->toolStripButton5->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton5->Name = L"toolStripButton5";
			this->toolStripButton5->Size = System::Drawing::Size(82, 22);
			this->toolStripButton5->Text = L"Facturacion";
			// 
			// comprarProductoToolStripMenuItem
			// 
			this->comprarProductoToolStripMenuItem->Name = L"comprarProductoToolStripMenuItem";
			this->comprarProductoToolStripMenuItem->Size = System::Drawing::Size(161, 22);
			this->comprarProductoToolStripMenuItem->Text = L"Comprar";
			// 
			// eliminarCompraToolStripMenuItem
			// 
			this->eliminarCompraToolStripMenuItem->Name = L"eliminarCompraToolStripMenuItem";
			this->eliminarCompraToolStripMenuItem->Size = System::Drawing::Size(161, 22);
			this->eliminarCompraToolStripMenuItem->Text = L"Eliminar compra";
			// 
			// toolStripButton7
			// 
			this->toolStripButton7->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripButton7->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->informacionDeLaEmpresaToolStripMenuItem });
			this->toolStripButton7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton7.Image")));
			this->toolStripButton7->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton7->Name = L"toolStripButton7";
			this->toolStripButton7->Size = System::Drawing::Size(72, 22);
			this->toolStripButton7->Text = L"Acerca de";
			// 
			// informacionDeLaEmpresaToolStripMenuItem
			// 
			this->informacionDeLaEmpresaToolStripMenuItem->Name = L"informacionDeLaEmpresaToolStripMenuItem";
			this->informacionDeLaEmpresaToolStripMenuItem->Size = System::Drawing::Size(218, 22);
			this->informacionDeLaEmpresaToolStripMenuItem->Text = L"Informacion de la empresa.";
			// 
			// toolStripButton3
			// 
			this->toolStripButton3->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripButton3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton3.Image")));
			this->toolStripButton3->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton3->Name = L"toolStripButton3";
			this->toolStripButton3->Size = System::Drawing::Size(60, 22);
			this->toolStripButton3->Text = L"Contacto";
			// 
			// button1
			// 
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->Location = System::Drawing::Point(12, 51);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(85, 85);
			this->button1->TabIndex = 1;
			this->button1->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button2->Location = System::Drawing::Point(358, 51);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(85, 85);
			this->button2->TabIndex = 2;
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.BackgroundImage")));
			this->button3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button3->Location = System::Drawing::Point(12, 316);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(85, 85);
			this->button3->TabIndex = 3;
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.BackgroundImage")));
			this->button4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button4->Location = System::Drawing::Point(358, 316);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(85, 85);
			this->button4->TabIndex = 4;
			this->button4->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(23, 143);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(58, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"LUGARES";
			this->label1->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(369, 143);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(63, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"USUARIOS";
			this->label2->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(379, 408);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(44, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"PAGOS";
			this->label3->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(9, 408);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(95, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"RESTAURANTES";
			this->label4->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// ventanaMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(602, 428);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->toolStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"ventanaMenu";
			this->Text = L"ventanaMenu";
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



};
}
