#pragma once

#include "cargarArchivo.h"

//Ventanas Insertar
#include "ventanaInsertarPais.h"
#include "ventanaInsertarCiudad.h"
#include "ventanaInsertarRestaurante.h"
#include "ventanaInsertarMenu.h"
#include "ventanaInsertarProducto.h"
#include "ventanaInsertarCliente.h"
#include "ventanaInsertarAdmin.h"

//Ventanas Eliminar
#include "ventanaEliminarPais.h"
#include "ventanaEliminarCiudad.h"
#include "ventanaEliminarRestaurante.h"
#include "ventanaEliminarMenu.h"
#include "ventanaEliminarProducto.h"
#include "ventanaEliminarCliente.h"
#include "ventanaEliminarAdmin.h"

//Ventanas Buscar
#include "ventanaBuscarPais.h"
#include "ventanaBuscarCiudad.h"
#include "ventanaBuscarRestaurante.h"
#include "ventanaBuscarMenu.h"
#include "ventanaBuscarProducto.h"
#include "ventanaBuscarCliente.h"
#include "ventanaBuscarAdmin.h"

//Ventanas Modificar
#include "ventanaModificarPais.h"
#include "ventanaModificarCiudad.h"
#include "ventanaModificarRestaurante.h"
#include "ventanaModificarMenu.h"
#include "ventanaModificarProducto.h"
#include "ventanaModificarCliente.h"
#include "ventanaModificarAdmin.h"


//Ventana Contacto
#include "ventanaContacto.h"

//Ventanas Popup
#include "ventanaPopupLugares.h"
#include "ventanaPopupPagos.h"
#include "ventanaPopupRestaurantes.h"
#include "ventanaPopupUsuarios.h"

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
		cargarArchivo* progra;

		ventanaMenu(cargarArchivo *progra, String^ cedula)
		{
			this->progra = progra;
			InitializeComponent();
			//progra = new cargarArchivo();
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
	private: System::Windows::Forms::ToolStripDropDownButton^ MenuMenu;
	protected:










	public: System::Windows::Forms::ToolStripMenuItem^ salirToolStripMenuItem1;
	public: System::Windows::Forms::ToolStripDropDownButton^ MantenimientoMenu;
	public: System::Windows::Forms::ToolStripButton^ ContactoMenu;



	public: System::Windows::Forms::ToolStripMenuItem^ insertarMenuItem;
	public: System::Windows::Forms::ToolStripMenuItem^ buscarItem;
	public: System::Windows::Forms::ToolStripMenuItem^ modificarMenuItem;
	public: System::Windows::Forms::ToolStripMenuItem^ eliminarMenuItem;
	public: System::Windows::Forms::ToolStripDropDownButton^ ReportesMenu;
	public: System::Windows::Forms::ToolStripMenuItem^ ReportePaisMenuItem;

	public: System::Windows::Forms::ToolStripMenuItem^ ReporteCiudadMenuItem;








	public: System::Windows::Forms::ToolStripDropDownButton^ FacturacionMenu;
	public: System::Windows::Forms::ToolStripDropDownButton^ AcercaDeMenu;
	public: System::Windows::Forms::ToolStripMenuItem^ AboutMenuItem;
	public: System::Windows::Forms::ToolStripMenuItem^ ReporteMenuMenuItem;
	public: System::Windows::Forms::ToolStripMenuItem^ ProductosMenuItem;
	public: System::Windows::Forms::ToolStripMenuItem^ clientesMenuItem;










	public: System::Windows::Forms::ToolStripMenuItem^ listaDeClientesToolStripMenuItem;
	public: System::Windows::Forms::ToolStripMenuItem^ comprasDeUnClienteToolStripMenuItem;
	public: System::Windows::Forms::ToolStripMenuItem^ ReporteRestauranteMenuItem;

	public: System::Windows::Forms::ToolStripMenuItem^ listaDeRestaurantesToolStripMenuItem;
	public: System::Windows::Forms::ToolStripMenuItem^ restauranteMasBuscadoToolStripMenuItem;
	public: System::Windows::Forms::ToolStripMenuItem^ precioDeProductoMenuItem;
	public: System::Windows::Forms::ToolStripMenuItem^ cantidadDeProductoMenuItem;
	public: System::Windows::Forms::ToolStripMenuItem^ facturacionMenuItem;
	public: System::Windows::Forms::ToolStripMenuItem^ facturaDeMayorMontoMenuItem;
	public: System::Windows::Forms::ToolStripMenuItem^ facturaDeMenorMontoMenuItem;
	public: System::Windows::Forms::ToolStripMenuItem^ descuentoConTarjetaMenuItem;
	public: System::Windows::Forms::ToolStripMenuItem^ eliminacionesMenuItem;







	public: System::Windows::Forms::ToolStripMenuItem^ paisesEliminadosMenuItem;
	public: System::Windows::Forms::ToolStripMenuItem^ ciudadesEliminadasMenuItem;
	public: System::Windows::Forms::ToolStripMenuItem^ restaurantesEliminadosMenuItem;
	public: System::Windows::Forms::ToolStripMenuItem^ menusEliminadosMenuItem;
	public: System::Windows::Forms::ToolStripMenuItem^ productosEliminadosMenuItem;





	public: System::Windows::Forms::ToolStripMenuItem^ comprarProductoMenuItem;
	public: System::Windows::Forms::ToolStripMenuItem^ eliminarCompraMenuItem;


	public: System::Windows::Forms::ToolStripMenuItem^ paisToolStripMenuItem;
	public: System::Windows::Forms::ToolStripMenuItem^ ciudadToolStripMenuItem;
	public: System::Windows::Forms::ToolStripMenuItem^ restauranteToolStripMenuItem;
	public: System::Windows::Forms::ToolStripMenuItem^ menuToolStripMenuItem1;
	public: System::Windows::Forms::ToolStripMenuItem^ productoToolStripMenuItem;
	public: System::Windows::Forms::ToolStripMenuItem^ clienteToolStripMenuItem;
	public: System::Windows::Forms::ToolStripMenuItem^ paisToolStripMenuItem1;
	public: System::Windows::Forms::ToolStripMenuItem^ ciudadToolStripMenuItem1;
	public: System::Windows::Forms::ToolStripMenuItem^ restauranteToolStripMenuItem1;
	public: System::Windows::Forms::ToolStripMenuItem^ menuToolStripMenuItem2;
	public: System::Windows::Forms::ToolStripMenuItem^ productoToolStripMenuItem1;
	public: System::Windows::Forms::ToolStripMenuItem^ BuscaClienteMenuItem;
	public: System::Windows::Forms::ToolStripMenuItem^ BuscaAdminMenuItem;


	public: System::Windows::Forms::ToolStripMenuItem^ paisToolStripMenuItem2;
	public: System::Windows::Forms::ToolStripMenuItem^ ciudadToolStripMenuItem2;
	public: System::Windows::Forms::ToolStripMenuItem^ restauranteToolStripMenuItem2;
	public: System::Windows::Forms::ToolStripMenuItem^ menuToolStripMenuItem3;
	public: System::Windows::Forms::ToolStripMenuItem^ productoToolStripMenuItem2;
	public: System::Windows::Forms::ToolStripMenuItem^ clienteToolStripMenuItem2;
	public: System::Windows::Forms::ToolStripMenuItem^ administradorToolStripMenuItem;
	public: System::Windows::Forms::ToolStripMenuItem^ paisToolStripMenuItem3;
	public: System::Windows::Forms::ToolStripMenuItem^ ciudadToolStripMenuItem3;
	public: System::Windows::Forms::ToolStripMenuItem^ restauranteToolStripMenuItem3;
	public: System::Windows::Forms::ToolStripMenuItem^ menuToolStripMenuItem4;
	public: System::Windows::Forms::ToolStripMenuItem^ productoToolStripMenuItem3;
	public: System::Windows::Forms::ToolStripMenuItem^ clienteToolStripMenuItem3;
	public: System::Windows::Forms::ToolStripMenuItem^ administradorToolStripMenuItem2;
	public: System::Windows::Forms::Button^ button1;
	public: System::Windows::Forms::Button^ button2;
	public: System::Windows::Forms::Button^ button3;
	public: System::Windows::Forms::Button^ button4;
	public: System::Windows::Forms::Label^ label1;
	public: System::Windows::Forms::Label^ label2;
	public: System::Windows::Forms::Label^ label3;
	public: System::Windows::Forms::Label^ label4;
	public: System::Windows::Forms::ToolStripMenuItem^ leerArchivosMenuItem;
	public: System::Windows::Forms::ToolStripMenuItem^ productoMasCompradoMenuItem;
	public: System::Windows::Forms::ToolStripMenuItem^ listaDeMenuToolStripMenuItem;
	public: System::Windows::Forms::ToolStripMenuItem^ menuMasBuscadoToolStripMenuItem;



	private:
		contacto^ menuContacto;

		ventanaPopupLugares^ popupLugares;
		ventanaPopupPagos^ popupPagos;
		ventanaPopupRestaurantes^ popupRestaurantes;
		ventanaPopupUsuarios^ popupUsuarios;

		ventanaInsertarPais^ InsertarPais;
		ventanaInsertarCiudad^ InsertarCiudad;
		ventanaInsertarRestaurante^ InsertarRestaurante;
		ventanaInsertarMenu^ InsertarMenu;
		ventanaInsertarProducto^ InsertarProducto;
		ventanaInsertarCliente^ InsertarCliente;
		ventanaInsertarAdmin^ InsertarAdmin;

		ventanaEliminarPais^ EliminarPais;
		ventanaEliminarCiudad^ EliminarCiudad;
		ventanaEliminarRestaurante^ EliminarRestaurante;
		ventanaEliminarMenu^ EliminarMenu;
		ventanaEliminarProducto^ EliminarProducto;
		ventanaEliminarCliente^ EliminarCliente;
		ventanaEliminarAdmin^ EliminarAdmin;

		ventanaBuscarPais^ BuscarPais;
		ventanaBuscarCiudad^ BuscarCiudad;
		ventanaBuscarRestaurante^ BuscarRestaurante;
		ventanaBuscarMenu^ BuscarMenu;
		ventanaBuscarProducto^ BuscarProducto;
		ventanaBuscarCliente^ BuscarCliente;
		ventanaBuscarAdmin^ BuscarAdmin;

		ventanaModificarPais^ ModificarPais;
		ventanaModificarCiudad^ ModificarCiudad;
		ventanaModificarRestaurante^ ModificarRestaurante;
		ventanaModificarMenu^ ModificarMenu;
		ventanaModificarProducto^ ModificarProducto;
		ventanaModificarCliente^ ModificarCliente;
		ventanaModificarAdmin^ ModificarAdmin;

private: System::Windows::Forms::ToolStripMenuItem^ adminToolStripMenuItem;


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
			this->MenuMenu = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->leerArchivosMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->salirToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->MantenimientoMenu = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->insertarMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->paisToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ciudadToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->restauranteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->productoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clienteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->adminToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->buscarItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->paisToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ciudadToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->restauranteToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->productoToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->BuscaClienteMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->BuscaAdminMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->modificarMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->paisToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ciudadToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->restauranteToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuToolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->productoToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clienteToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->administradorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->eliminarMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->paisToolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ciudadToolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->restauranteToolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuToolStripMenuItem4 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->productoToolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clienteToolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->administradorToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ReportesMenu = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->ReportePaisMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ReporteCiudadMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ReporteRestauranteMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->listaDeRestaurantesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->restauranteMasBuscadoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ReporteMenuMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->listaDeMenuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuMasBuscadoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ProductosMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->precioDeProductoMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cantidadDeProductoMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->productoMasCompradoMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clientesMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->listaDeClientesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->comprasDeUnClienteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->facturacionMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->facturaDeMayorMontoMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->facturaDeMenorMontoMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->descuentoConTarjetaMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->eliminacionesMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->paisesEliminadosMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ciudadesEliminadasMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->restaurantesEliminadosMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menusEliminadosMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->productosEliminadosMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->FacturacionMenu = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->comprarProductoMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->eliminarCompraMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->AcercaDeMenu = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->AboutMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ContactoMenu = (gcnew System::Windows::Forms::ToolStripButton());
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
				this->MenuMenu, this->MantenimientoMenu,
					this->ReportesMenu, this->FacturacionMenu, this->AcercaDeMenu, this->ContactoMenu
			});
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(487, 25);
			this->toolStrip1->TabIndex = 0;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// MenuMenu
			// 
			this->MenuMenu->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->MenuMenu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->leerArchivosMenuItem,
					this->salirToolStripMenuItem1
			});
			this->MenuMenu->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"MenuMenu.Image")));
			this->MenuMenu->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->MenuMenu->Name = L"MenuMenu";
			this->MenuMenu->Size = System::Drawing::Size(51, 22);
			this->MenuMenu->Text = L"Menu";
			// 
			// leerArchivosMenuItem
			// 
			this->leerArchivosMenuItem->Name = L"leerArchivosMenuItem";
			this->leerArchivosMenuItem->Size = System::Drawing::Size(145, 22);
			this->leerArchivosMenuItem->Text = L"Leer Archivos";
			this->leerArchivosMenuItem->Click += gcnew System::EventHandler(this, &ventanaMenu::leerArchivosMenuItem_Click);
			// 
			// salirToolStripMenuItem1
			// 
			this->salirToolStripMenuItem1->Name = L"salirToolStripMenuItem1";
			this->salirToolStripMenuItem1->Size = System::Drawing::Size(145, 22);
			this->salirToolStripMenuItem1->Text = L"Salir";
			this->salirToolStripMenuItem1->Click += gcnew System::EventHandler(this, &ventanaMenu::salirToolStripMenuItem1_Click);
			// 
			// MantenimientoMenu
			// 
			this->MantenimientoMenu->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->MantenimientoMenu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->insertarMenuItem,
					this->buscarItem, this->modificarMenuItem, this->eliminarMenuItem
			});
			this->MantenimientoMenu->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"MantenimientoMenu.Image")));
			this->MantenimientoMenu->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->MantenimientoMenu->Name = L"MantenimientoMenu";
			this->MantenimientoMenu->Size = System::Drawing::Size(102, 22);
			this->MantenimientoMenu->Text = L"Mantenimiento";
			this->MantenimientoMenu->Click += gcnew System::EventHandler(this, &ventanaMenu::MantenimientoMenu_Click);
			// 
			// insertarMenuItem
			// 
			this->insertarMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->paisToolStripMenuItem,
					this->ciudadToolStripMenuItem, this->restauranteToolStripMenuItem, this->menuToolStripMenuItem1, this->productoToolStripMenuItem,
					this->clienteToolStripMenuItem, this->adminToolStripMenuItem
			});
			this->insertarMenuItem->Name = L"insertarMenuItem";
			this->insertarMenuItem->Size = System::Drawing::Size(125, 22);
			this->insertarMenuItem->Text = L"Insertar";
			this->insertarMenuItem->Click += gcnew System::EventHandler(this, &ventanaMenu::insertarMenuItem_Click);
			// 
			// paisToolStripMenuItem
			// 
			this->paisToolStripMenuItem->Name = L"paisToolStripMenuItem";
			this->paisToolStripMenuItem->Size = System::Drawing::Size(136, 22);
			this->paisToolStripMenuItem->Text = L"Pais";
			this->paisToolStripMenuItem->Click += gcnew System::EventHandler(this, &ventanaMenu::paisToolStripMenuItem_Click);
			// 
			// ciudadToolStripMenuItem
			// 
			this->ciudadToolStripMenuItem->Name = L"ciudadToolStripMenuItem";
			this->ciudadToolStripMenuItem->Size = System::Drawing::Size(136, 22);
			this->ciudadToolStripMenuItem->Text = L"Ciudad";
			this->ciudadToolStripMenuItem->Click += gcnew System::EventHandler(this, &ventanaMenu::ciudadToolStripMenuItem_Click);
			// 
			// restauranteToolStripMenuItem
			// 
			this->restauranteToolStripMenuItem->Name = L"restauranteToolStripMenuItem";
			this->restauranteToolStripMenuItem->Size = System::Drawing::Size(136, 22);
			this->restauranteToolStripMenuItem->Text = L"Restaurante";
			this->restauranteToolStripMenuItem->Click += gcnew System::EventHandler(this, &ventanaMenu::restauranteToolStripMenuItem_Click);
			// 
			// menuToolStripMenuItem1
			// 
			this->menuToolStripMenuItem1->Name = L"menuToolStripMenuItem1";
			this->menuToolStripMenuItem1->Size = System::Drawing::Size(136, 22);
			this->menuToolStripMenuItem1->Text = L"Menu";
			this->menuToolStripMenuItem1->Click += gcnew System::EventHandler(this, &ventanaMenu::menuToolStripMenuItem1_Click);
			// 
			// productoToolStripMenuItem
			// 
			this->productoToolStripMenuItem->Name = L"productoToolStripMenuItem";
			this->productoToolStripMenuItem->Size = System::Drawing::Size(136, 22);
			this->productoToolStripMenuItem->Text = L"Producto";
			this->productoToolStripMenuItem->Click += gcnew System::EventHandler(this, &ventanaMenu::productoToolStripMenuItem_Click);
			// 
			// clienteToolStripMenuItem
			// 
			this->clienteToolStripMenuItem->Name = L"clienteToolStripMenuItem";
			this->clienteToolStripMenuItem->Size = System::Drawing::Size(136, 22);
			this->clienteToolStripMenuItem->Text = L"Cliente";
			this->clienteToolStripMenuItem->Click += gcnew System::EventHandler(this, &ventanaMenu::clienteToolStripMenuItem_Click);
			// 
			// adminToolStripMenuItem
			// 
			this->adminToolStripMenuItem->Name = L"adminToolStripMenuItem";
			this->adminToolStripMenuItem->Size = System::Drawing::Size(136, 22);
			this->adminToolStripMenuItem->Text = L"Admin";
			this->adminToolStripMenuItem->Click += gcnew System::EventHandler(this, &ventanaMenu::adminToolStripMenuItem_Click);
			// 
			// buscarItem
			// 
			this->buscarItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->paisToolStripMenuItem1,
					this->ciudadToolStripMenuItem1, this->restauranteToolStripMenuItem1, this->menuToolStripMenuItem2, this->productoToolStripMenuItem1,
					this->BuscaClienteMenuItem, this->BuscaAdminMenuItem
			});
			this->buscarItem->Name = L"buscarItem";
			this->buscarItem->Size = System::Drawing::Size(125, 22);
			this->buscarItem->Text = L"Buscar";
			// 
			// paisToolStripMenuItem1
			// 
			this->paisToolStripMenuItem1->Name = L"paisToolStripMenuItem1";
			this->paisToolStripMenuItem1->Size = System::Drawing::Size(150, 22);
			this->paisToolStripMenuItem1->Text = L"Pais";
			this->paisToolStripMenuItem1->Click += gcnew System::EventHandler(this, &ventanaMenu::paisToolStripMenuItem1_Click);
			// 
			// ciudadToolStripMenuItem1
			// 
			this->ciudadToolStripMenuItem1->Name = L"ciudadToolStripMenuItem1";
			this->ciudadToolStripMenuItem1->Size = System::Drawing::Size(150, 22);
			this->ciudadToolStripMenuItem1->Text = L"Ciudad";
			this->ciudadToolStripMenuItem1->Click += gcnew System::EventHandler(this, &ventanaMenu::ciudadToolStripMenuItem1_Click);
			// 
			// restauranteToolStripMenuItem1
			// 
			this->restauranteToolStripMenuItem1->Name = L"restauranteToolStripMenuItem1";
			this->restauranteToolStripMenuItem1->Size = System::Drawing::Size(150, 22);
			this->restauranteToolStripMenuItem1->Text = L"Restaurante";
			this->restauranteToolStripMenuItem1->Click += gcnew System::EventHandler(this, &ventanaMenu::restauranteToolStripMenuItem1_Click);
			// 
			// menuToolStripMenuItem2
			// 
			this->menuToolStripMenuItem2->Name = L"menuToolStripMenuItem2";
			this->menuToolStripMenuItem2->Size = System::Drawing::Size(150, 22);
			this->menuToolStripMenuItem2->Text = L"Menu";
			this->menuToolStripMenuItem2->Click += gcnew System::EventHandler(this, &ventanaMenu::menuToolStripMenuItem2_Click);
			// 
			// productoToolStripMenuItem1
			// 
			this->productoToolStripMenuItem1->Name = L"productoToolStripMenuItem1";
			this->productoToolStripMenuItem1->Size = System::Drawing::Size(150, 22);
			this->productoToolStripMenuItem1->Text = L"Producto";
			this->productoToolStripMenuItem1->Click += gcnew System::EventHandler(this, &ventanaMenu::productoToolStripMenuItem1_Click);
			// 
			// BuscaClienteMenuItem
			// 
			this->BuscaClienteMenuItem->Name = L"BuscaClienteMenuItem";
			this->BuscaClienteMenuItem->Size = System::Drawing::Size(150, 22);
			this->BuscaClienteMenuItem->Text = L"Cliente";
			this->BuscaClienteMenuItem->Click += gcnew System::EventHandler(this, &ventanaMenu::BuscaClienteMenuItem_Click);
			// 
			// BuscaAdminMenuItem
			// 
			this->BuscaAdminMenuItem->Name = L"BuscaAdminMenuItem";
			this->BuscaAdminMenuItem->Size = System::Drawing::Size(150, 22);
			this->BuscaAdminMenuItem->Text = L"Administrador";
			this->BuscaAdminMenuItem->Click += gcnew System::EventHandler(this, &ventanaMenu::BuscaAdminMenuItem_Click);
			// 
			// modificarMenuItem
			// 
			this->modificarMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->paisToolStripMenuItem2,
					this->ciudadToolStripMenuItem2, this->restauranteToolStripMenuItem2, this->menuToolStripMenuItem3, this->productoToolStripMenuItem2,
					this->clienteToolStripMenuItem2, this->administradorToolStripMenuItem
			});
			this->modificarMenuItem->Name = L"modificarMenuItem";
			this->modificarMenuItem->Size = System::Drawing::Size(125, 22);
			this->modificarMenuItem->Text = L"Modificar";
			// 
			// paisToolStripMenuItem2
			// 
			this->paisToolStripMenuItem2->Name = L"paisToolStripMenuItem2";
			this->paisToolStripMenuItem2->Size = System::Drawing::Size(150, 22);
			this->paisToolStripMenuItem2->Text = L"Pais";
			this->paisToolStripMenuItem2->Click += gcnew System::EventHandler(this, &ventanaMenu::paisToolStripMenuItem2_Click);
			// 
			// ciudadToolStripMenuItem2
			// 
			this->ciudadToolStripMenuItem2->Name = L"ciudadToolStripMenuItem2";
			this->ciudadToolStripMenuItem2->Size = System::Drawing::Size(150, 22);
			this->ciudadToolStripMenuItem2->Text = L"Ciudad";
			this->ciudadToolStripMenuItem2->Click += gcnew System::EventHandler(this, &ventanaMenu::ciudadToolStripMenuItem2_Click);
			// 
			// restauranteToolStripMenuItem2
			// 
			this->restauranteToolStripMenuItem2->Name = L"restauranteToolStripMenuItem2";
			this->restauranteToolStripMenuItem2->Size = System::Drawing::Size(150, 22);
			this->restauranteToolStripMenuItem2->Text = L"Restaurante";
			this->restauranteToolStripMenuItem2->Click += gcnew System::EventHandler(this, &ventanaMenu::restauranteToolStripMenuItem2_Click);
			// 
			// menuToolStripMenuItem3
			// 
			this->menuToolStripMenuItem3->Name = L"menuToolStripMenuItem3";
			this->menuToolStripMenuItem3->Size = System::Drawing::Size(150, 22);
			this->menuToolStripMenuItem3->Text = L"Menu";
			this->menuToolStripMenuItem3->Click += gcnew System::EventHandler(this, &ventanaMenu::menuToolStripMenuItem3_Click);
			// 
			// productoToolStripMenuItem2
			// 
			this->productoToolStripMenuItem2->Name = L"productoToolStripMenuItem2";
			this->productoToolStripMenuItem2->Size = System::Drawing::Size(150, 22);
			this->productoToolStripMenuItem2->Text = L"Producto";
			this->productoToolStripMenuItem2->Click += gcnew System::EventHandler(this, &ventanaMenu::productoToolStripMenuItem2_Click);
			// 
			// clienteToolStripMenuItem2
			// 
			this->clienteToolStripMenuItem2->Name = L"clienteToolStripMenuItem2";
			this->clienteToolStripMenuItem2->Size = System::Drawing::Size(150, 22);
			this->clienteToolStripMenuItem2->Text = L"Cliente";
			this->clienteToolStripMenuItem2->Click += gcnew System::EventHandler(this, &ventanaMenu::clienteToolStripMenuItem2_Click);
			// 
			// administradorToolStripMenuItem
			// 
			this->administradorToolStripMenuItem->Name = L"administradorToolStripMenuItem";
			this->administradorToolStripMenuItem->Size = System::Drawing::Size(150, 22);
			this->administradorToolStripMenuItem->Text = L"Administrador";
			this->administradorToolStripMenuItem->Click += gcnew System::EventHandler(this, &ventanaMenu::administradorToolStripMenuItem_Click);
			// 
			// eliminarMenuItem
			// 
			this->eliminarMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->paisToolStripMenuItem3,
					this->ciudadToolStripMenuItem3, this->restauranteToolStripMenuItem3, this->menuToolStripMenuItem4, this->productoToolStripMenuItem3,
					this->clienteToolStripMenuItem3, this->administradorToolStripMenuItem2
			});
			this->eliminarMenuItem->Name = L"eliminarMenuItem";
			this->eliminarMenuItem->Size = System::Drawing::Size(125, 22);
			this->eliminarMenuItem->Text = L"Eliminar";
			// 
			// paisToolStripMenuItem3
			// 
			this->paisToolStripMenuItem3->Name = L"paisToolStripMenuItem3";
			this->paisToolStripMenuItem3->Size = System::Drawing::Size(150, 22);
			this->paisToolStripMenuItem3->Text = L"Pais";
			this->paisToolStripMenuItem3->Click += gcnew System::EventHandler(this, &ventanaMenu::paisToolStripMenuItem3_Click);
			// 
			// ciudadToolStripMenuItem3
			// 
			this->ciudadToolStripMenuItem3->Name = L"ciudadToolStripMenuItem3";
			this->ciudadToolStripMenuItem3->Size = System::Drawing::Size(150, 22);
			this->ciudadToolStripMenuItem3->Text = L"Ciudad";
			this->ciudadToolStripMenuItem3->Click += gcnew System::EventHandler(this, &ventanaMenu::ciudadToolStripMenuItem3_Click);
			// 
			// restauranteToolStripMenuItem3
			// 
			this->restauranteToolStripMenuItem3->Name = L"restauranteToolStripMenuItem3";
			this->restauranteToolStripMenuItem3->Size = System::Drawing::Size(150, 22);
			this->restauranteToolStripMenuItem3->Text = L"Restaurante";
			this->restauranteToolStripMenuItem3->Click += gcnew System::EventHandler(this, &ventanaMenu::restauranteToolStripMenuItem3_Click);
			// 
			// menuToolStripMenuItem4
			// 
			this->menuToolStripMenuItem4->Name = L"menuToolStripMenuItem4";
			this->menuToolStripMenuItem4->Size = System::Drawing::Size(150, 22);
			this->menuToolStripMenuItem4->Text = L"Menu";
			this->menuToolStripMenuItem4->Click += gcnew System::EventHandler(this, &ventanaMenu::menuToolStripMenuItem4_Click);
			// 
			// productoToolStripMenuItem3
			// 
			this->productoToolStripMenuItem3->Name = L"productoToolStripMenuItem3";
			this->productoToolStripMenuItem3->Size = System::Drawing::Size(150, 22);
			this->productoToolStripMenuItem3->Text = L"Producto";
			this->productoToolStripMenuItem3->Click += gcnew System::EventHandler(this, &ventanaMenu::productoToolStripMenuItem3_Click);
			// 
			// clienteToolStripMenuItem3
			// 
			this->clienteToolStripMenuItem3->Name = L"clienteToolStripMenuItem3";
			this->clienteToolStripMenuItem3->Size = System::Drawing::Size(150, 22);
			this->clienteToolStripMenuItem3->Text = L"Cliente";
			this->clienteToolStripMenuItem3->Click += gcnew System::EventHandler(this, &ventanaMenu::clienteToolStripMenuItem3_Click);
			// 
			// administradorToolStripMenuItem2
			// 
			this->administradorToolStripMenuItem2->Name = L"administradorToolStripMenuItem2";
			this->administradorToolStripMenuItem2->Size = System::Drawing::Size(150, 22);
			this->administradorToolStripMenuItem2->Text = L"Administrador";
			this->administradorToolStripMenuItem2->Click += gcnew System::EventHandler(this, &ventanaMenu::administradorToolStripMenuItem2_Click);
			// 
			// ReportesMenu
			// 
			this->ReportesMenu->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->ReportesMenu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {
				this->ReportePaisMenuItem,
					this->ReporteCiudadMenuItem, this->ReporteRestauranteMenuItem, this->ReporteMenuMenuItem, this->ProductosMenuItem, this->clientesMenuItem,
					this->facturacionMenuItem, this->eliminacionesMenuItem
			});
			this->ReportesMenu->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ReportesMenu.Image")));
			this->ReportesMenu->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->ReportesMenu->Name = L"ReportesMenu";
			this->ReportesMenu->Size = System::Drawing::Size(66, 22);
			this->ReportesMenu->Text = L"Reportes";
			// 
			// ReportePaisMenuItem
			// 
			this->ReportePaisMenuItem->Name = L"ReportePaisMenuItem";
			this->ReportePaisMenuItem->Size = System::Drawing::Size(147, 22);
			this->ReportePaisMenuItem->Text = L"Paises";
			// 
			// ReporteCiudadMenuItem
			// 
			this->ReporteCiudadMenuItem->Name = L"ReporteCiudadMenuItem";
			this->ReporteCiudadMenuItem->Size = System::Drawing::Size(147, 22);
			this->ReporteCiudadMenuItem->Text = L"Ciudades";
			// 
			// ReporteRestauranteMenuItem
			// 
			this->ReporteRestauranteMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->listaDeRestaurantesToolStripMenuItem,
					this->restauranteMasBuscadoToolStripMenuItem
			});
			this->ReporteRestauranteMenuItem->Name = L"ReporteRestauranteMenuItem";
			this->ReporteRestauranteMenuItem->Size = System::Drawing::Size(147, 22);
			this->ReporteRestauranteMenuItem->Text = L"Restaurantes";
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
			// ReporteMenuMenuItem
			// 
			this->ReporteMenuMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->listaDeMenuToolStripMenuItem,
					this->menuMasBuscadoToolStripMenuItem
			});
			this->ReporteMenuMenuItem->Name = L"ReporteMenuMenuItem";
			this->ReporteMenuMenuItem->Size = System::Drawing::Size(147, 22);
			this->ReporteMenuMenuItem->Text = L"Menus";
			// 
			// listaDeMenuToolStripMenuItem
			// 
			this->listaDeMenuToolStripMenuItem->Name = L"listaDeMenuToolStripMenuItem";
			this->listaDeMenuToolStripMenuItem->Size = System::Drawing::Size(178, 22);
			this->listaDeMenuToolStripMenuItem->Text = L"Lista de Menu";
			// 
			// menuMasBuscadoToolStripMenuItem
			// 
			this->menuMasBuscadoToolStripMenuItem->Name = L"menuMasBuscadoToolStripMenuItem";
			this->menuMasBuscadoToolStripMenuItem->Size = System::Drawing::Size(178, 22);
			this->menuMasBuscadoToolStripMenuItem->Text = L"Menu mas buscado";
			// 
			// ProductosMenuItem
			// 
			this->ProductosMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->precioDeProductoMenuItem,
					this->cantidadDeProductoMenuItem, this->productoMasCompradoMenuItem
			});
			this->ProductosMenuItem->Name = L"ProductosMenuItem";
			this->ProductosMenuItem->Size = System::Drawing::Size(147, 22);
			this->ProductosMenuItem->Text = L"Productos";
			// 
			// precioDeProductoMenuItem
			// 
			this->precioDeProductoMenuItem->Name = L"precioDeProductoMenuItem";
			this->precioDeProductoMenuItem->Size = System::Drawing::Size(206, 22);
			this->precioDeProductoMenuItem->Text = L"Precio de producto";
			// 
			// cantidadDeProductoMenuItem
			// 
			this->cantidadDeProductoMenuItem->Name = L"cantidadDeProductoMenuItem";
			this->cantidadDeProductoMenuItem->Size = System::Drawing::Size(206, 22);
			this->cantidadDeProductoMenuItem->Text = L"Cantidad de producto";
			// 
			// productoMasCompradoMenuItem
			// 
			this->productoMasCompradoMenuItem->Name = L"productoMasCompradoMenuItem";
			this->productoMasCompradoMenuItem->Size = System::Drawing::Size(206, 22);
			this->productoMasCompradoMenuItem->Text = L"Producto mas comprado";
			// 
			// clientesMenuItem
			// 
			this->clientesMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->listaDeClientesToolStripMenuItem,
					this->comprasDeUnClienteToolStripMenuItem
			});
			this->clientesMenuItem->Name = L"clientesMenuItem";
			this->clientesMenuItem->Size = System::Drawing::Size(147, 22);
			this->clientesMenuItem->Text = L"Clientes";
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
			// facturacionMenuItem
			// 
			this->facturacionMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->facturaDeMayorMontoMenuItem,
					this->facturaDeMenorMontoMenuItem, this->descuentoConTarjetaMenuItem
			});
			this->facturacionMenuItem->Name = L"facturacionMenuItem";
			this->facturacionMenuItem->Size = System::Drawing::Size(147, 22);
			this->facturacionMenuItem->Text = L"Facturacion";
			// 
			// facturaDeMayorMontoMenuItem
			// 
			this->facturaDeMayorMontoMenuItem->Name = L"facturaDeMayorMontoMenuItem";
			this->facturaDeMayorMontoMenuItem->Size = System::Drawing::Size(243, 22);
			this->facturaDeMayorMontoMenuItem->Text = L"Factura de mayor monto";
			// 
			// facturaDeMenorMontoMenuItem
			// 
			this->facturaDeMenorMontoMenuItem->Name = L"facturaDeMenorMontoMenuItem";
			this->facturaDeMenorMontoMenuItem->Size = System::Drawing::Size(243, 22);
			this->facturaDeMenorMontoMenuItem->Text = L"Factura de menor monto";
			// 
			// descuentoConTarjetaMenuItem
			// 
			this->descuentoConTarjetaMenuItem->Name = L"descuentoConTarjetaMenuItem";
			this->descuentoConTarjetaMenuItem->Size = System::Drawing::Size(243, 22);
			this->descuentoConTarjetaMenuItem->Text = L"Descuento por pagar con tarjeta";
			// 
			// eliminacionesMenuItem
			// 
			this->eliminacionesMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->paisesEliminadosMenuItem,
					this->ciudadesEliminadasMenuItem, this->restaurantesEliminadosMenuItem, this->menusEliminadosMenuItem, this->productosEliminadosMenuItem
			});
			this->eliminacionesMenuItem->Name = L"eliminacionesMenuItem";
			this->eliminacionesMenuItem->Size = System::Drawing::Size(147, 22);
			this->eliminacionesMenuItem->Text = L"Eliminaciones";
			// 
			// paisesEliminadosMenuItem
			// 
			this->paisesEliminadosMenuItem->Name = L"paisesEliminadosMenuItem";
			this->paisesEliminadosMenuItem->Size = System::Drawing::Size(202, 22);
			this->paisesEliminadosMenuItem->Text = L"Paises eliminados";
			// 
			// ciudadesEliminadasMenuItem
			// 
			this->ciudadesEliminadasMenuItem->Name = L"ciudadesEliminadasMenuItem";
			this->ciudadesEliminadasMenuItem->Size = System::Drawing::Size(202, 22);
			this->ciudadesEliminadasMenuItem->Text = L"Ciudades eliminadas";
			// 
			// restaurantesEliminadosMenuItem
			// 
			this->restaurantesEliminadosMenuItem->Name = L"restaurantesEliminadosMenuItem";
			this->restaurantesEliminadosMenuItem->Size = System::Drawing::Size(202, 22);
			this->restaurantesEliminadosMenuItem->Text = L"Restaurantes eliminados";
			// 
			// menusEliminadosMenuItem
			// 
			this->menusEliminadosMenuItem->Name = L"menusEliminadosMenuItem";
			this->menusEliminadosMenuItem->Size = System::Drawing::Size(202, 22);
			this->menusEliminadosMenuItem->Text = L"Menus eliminados";
			// 
			// productosEliminadosMenuItem
			// 
			this->productosEliminadosMenuItem->Name = L"productosEliminadosMenuItem";
			this->productosEliminadosMenuItem->Size = System::Drawing::Size(202, 22);
			this->productosEliminadosMenuItem->Text = L"Productos eliminados";
			// 
			// FacturacionMenu
			// 
			this->FacturacionMenu->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->FacturacionMenu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->comprarProductoMenuItem,
					this->eliminarCompraMenuItem
			});
			this->FacturacionMenu->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"FacturacionMenu.Image")));
			this->FacturacionMenu->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->FacturacionMenu->Name = L"FacturacionMenu";
			this->FacturacionMenu->Size = System::Drawing::Size(82, 22);
			this->FacturacionMenu->Text = L"Facturacion";
			// 
			// comprarProductoMenuItem
			// 
			this->comprarProductoMenuItem->Name = L"comprarProductoMenuItem";
			this->comprarProductoMenuItem->Size = System::Drawing::Size(161, 22);
			this->comprarProductoMenuItem->Text = L"Comprar";
			// 
			// eliminarCompraMenuItem
			// 
			this->eliminarCompraMenuItem->Name = L"eliminarCompraMenuItem";
			this->eliminarCompraMenuItem->Size = System::Drawing::Size(161, 22);
			this->eliminarCompraMenuItem->Text = L"Eliminar compra";
			// 
			// AcercaDeMenu
			// 
			this->AcercaDeMenu->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->AcercaDeMenu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->AboutMenuItem });
			this->AcercaDeMenu->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"AcercaDeMenu.Image")));
			this->AcercaDeMenu->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->AcercaDeMenu->Name = L"AcercaDeMenu";
			this->AcercaDeMenu->Size = System::Drawing::Size(72, 22);
			this->AcercaDeMenu->Text = L"Acerca de";
			// 
			// AboutMenuItem
			// 
			this->AboutMenuItem->Name = L"AboutMenuItem";
			this->AboutMenuItem->Size = System::Drawing::Size(218, 22);
			this->AboutMenuItem->Text = L"Informacion de la empresa.";
			// 
			// ContactoMenu
			// 
			this->ContactoMenu->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->ContactoMenu->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ContactoMenu.Image")));
			this->ContactoMenu->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->ContactoMenu->Name = L"ContactoMenu";
			this->ContactoMenu->Size = System::Drawing::Size(60, 22);
			this->ContactoMenu->Text = L"Contacto";
			this->ContactoMenu->Click += gcnew System::EventHandler(this, &ventanaMenu::toolStripButton3_Click);
			// 
			// button1
			// 
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->Location = System::Drawing::Point(63, 75);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(85, 85);
			this->button1->TabIndex = 1;
			this->button1->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ventanaMenu::button1_Click);
			// 
			// button2
			// 
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button2->Location = System::Drawing::Point(316, 75);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(85, 85);
			this->button2->TabIndex = 2;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ventanaMenu::button2_Click);
			// 
			// button3
			// 
			this->button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.BackgroundImage")));
			this->button3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button3->Location = System::Drawing::Point(63, 213);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(85, 85);
			this->button3->TabIndex = 3;
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &ventanaMenu::button3_Click);
			// 
			// button4
			// 
			this->button4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.BackgroundImage")));
			this->button4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button4->Location = System::Drawing::Point(316, 213);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(85, 85);
			this->button4->TabIndex = 4;
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &ventanaMenu::button4_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(74, 167);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(58, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"LUGARES";
			this->label1->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(327, 167);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(63, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"USUARIOS";
			this->label2->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(337, 305);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(44, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"PAGOS";
			this->label3->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(60, 305);
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
			this->ClientSize = System::Drawing::Size(487, 345);
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
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Menu Principal";
			this->Load += gcnew System::EventHandler(this, &ventanaMenu::ventanaMenu_Load);
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



private: System::Void ventanaMenu_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void salirToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
	System::Windows::Forms::DialogResult result = MessageBox::Show(
		"Esta seguro que desea salir?",  
		"Salir del programa:", 
		MessageBoxButtons::YesNo,  
		MessageBoxIcon::Question);  

	if (result == System::Windows::Forms::DialogResult::Yes) {
		this->Close();
	}

}

private: System::Void popupLugares_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if popupLugares is disposed before accessing it
	if (popupLugares != nullptr && !popupLugares->IsDisposed) {
		// Unsubscribe events
		popupLugares->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaMenu::popupLugares_FormClosed);
		// Show the ventanaPrincipal form when ventanaMenu is closed
	}
	this->Show();
}

private: System::Void popupUsuarios_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if popupLugares is disposed before accessing it
	if (popupUsuarios != nullptr && !popupUsuarios->IsDisposed) {
		// Unsubscribe events
		popupUsuarios->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaMenu::popupUsuarios_FormClosed);
		// Show the ventanaPrincipal form when ventanaMenu is closed
	}
	this->Show();
}

private: System::Void popupRestaurantes_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if popupLugares is disposed before accessing it
	if (popupRestaurantes != nullptr && !popupRestaurantes->IsDisposed) {
		// Unsubscribe events
		popupRestaurantes->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaMenu::popupRestaurantes_FormClosed);
		// Show the ventanaPrincipal form when ventanaMenu is closed
	}
	this->Show();
}

private: System::Void popupPagos_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if popupLugares is disposed before accessing it
	if (popupPagos != nullptr && !popupPagos->IsDisposed) {
		// Unsubscribe events
		popupPagos->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaMenu::popupPagos_FormClosed);
		// Show the ventanaPrincipal form when ventanaMenu is closed
	}
	this->Show();
}

private: System::Void menuContacto_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaMenu is disposed before accessing it
	if (menuContacto != nullptr && !menuContacto->IsDisposed) {
		// Unsubscribe events
		menuContacto->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaMenu::menuContacto_FormClosed);
		// Show the ventanaPrincipal form when ventanaMenu is closed
	}
	this->Show();
}

private: System::Void ventanaInsertarPais_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaMenu is disposed before accessing it
	if (InsertarPais != nullptr && !InsertarPais->IsDisposed) {
		// Unsubscribe events
		InsertarPais->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaInsertarPais_FormClosed);
		// Show the ventanaPrincipal form when ventanaMenu is closed
	}
	this->Show();
}

private: System::Void ventanaInsertarCiudad_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaMenu is disposed before accessing it
	if (InsertarCiudad != nullptr && !InsertarCiudad->IsDisposed) {
		// Unsubscribe events
		InsertarCiudad->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaInsertarCiudad_FormClosed);
		// Show the ventanaPrincipal form when ventanaMenu is closed
	}
	this->Show();
}

private: System::Void ventanaInsertarRestaurante_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaMenu is disposed before accessing it
	if (InsertarRestaurante != nullptr && !InsertarRestaurante->IsDisposed) {
		// Unsubscribe events
		InsertarRestaurante->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaInsertarRestaurante_FormClosed);
		// Show the ventanaPrincipal form when ventanaMenu is closed
	}
	this->Show();
}

private: System::Void ventanaInsertarMenu_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaMenu is disposed before accessing it
	if (InsertarMenu != nullptr && !InsertarMenu->IsDisposed) {
		// Unsubscribe events
		InsertarMenu->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaInsertarMenu_FormClosed);
		// Show the ventanaPrincipal form when ventanaMenu is closed
	}
	this->Show();
}

private: System::Void ventanaInsertarProducto_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaProducto is disposed before accessing it
	if (InsertarProducto != nullptr && !InsertarProducto->IsDisposed) {
		// Unsubscribe events
		InsertarProducto->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaInsertarProducto_FormClosed);
		// Show the ventanaPrincipal form when ventanaProducto is closed
	}
	this->Show();
}

private: System::Void ventanaInsertarCliente_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaCliente is disposed before accessing it
	if (InsertarCliente != nullptr && !InsertarCliente->IsDisposed) {
		// Unsubscribe events
		InsertarCliente->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaInsertarCliente_FormClosed);
		// Show the ventanaPrincipal form when ventanaCliente is closed
	}
	this->Show();
}

private: System::Void ventanaInsertarAdmin_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaAdmin is disposed before accessing it
	if (InsertarAdmin != nullptr && !InsertarAdmin->IsDisposed) {
		// Unsubscribe events
		InsertarAdmin->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaInsertarAdmin_FormClosed);
		// Show the ventanaPrincipal form when ventanaAdmin is closed
	}
	this->Show();
}


private: System::Void ventanaEliminarPais_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaEliminarPais is disposed before accessing it
	if (EliminarPais != nullptr && !EliminarPais->IsDisposed) {
		// Unsubscribe events
		EliminarPais->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaEliminarPais_FormClosed);
		// Show the ventanaPrincipal form when EliminarPais is closed
	}
	this->Show();
}

private: System::Void ventanaEliminarCiudad_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaEliminarCiudad is disposed before accessing it
	if (EliminarCiudad != nullptr && !EliminarCiudad->IsDisposed) {
		// Unsubscribe events
		EliminarCiudad->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaEliminarCiudad_FormClosed);
		// Show the ventanaPrincipal form when EliminarCiudad is closed
	}
	this->Show();
}

private: System::Void ventanaEliminarRestaurante_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaEliminarRestaurante is disposed before accessing it
	if (EliminarRestaurante != nullptr && !EliminarRestaurante->IsDisposed) {
		// Unsubscribe events
		EliminarRestaurante->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaEliminarRestaurante_FormClosed);
		// Show the ventanaPrincipal form when EliminarRestaurante is closed
	}
	this->Show();
}

private: System::Void ventanaEliminarMenu_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaEliminarMenu is disposed before accessing it
	if (EliminarMenu != nullptr && !EliminarMenu->IsDisposed) {
		// Unsubscribe events
		EliminarMenu->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaEliminarMenu_FormClosed);
		// Show the ventanaPrincipal form when EliminarMenu is closed
	}
	this->Show();
}

private: System::Void ventanaEliminarProducto_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaEliminarProducto is disposed before accessing it
	if (EliminarProducto != nullptr && !EliminarProducto->IsDisposed) {
		// Unsubscribe events
		EliminarProducto->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaEliminarProducto_FormClosed);
		// Show the ventanaPrincipal form when EliminarProducto is closed
	}
	this->Show();
}

private: System::Void ventanaEliminarCliente_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaEliminarCliente is disposed before accessing it
	if (EliminarCliente != nullptr && !EliminarCliente->IsDisposed) {
		// Unsubscribe events
		EliminarCliente->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaEliminarCliente_FormClosed);
		// Show the ventanaPrincipal form when EliminarCliente is closed
	}
	this->Show();
}

private: System::Void ventanaEliminarAdmin_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaEliminarAdmin is disposed before accessing it
	if (EliminarAdmin != nullptr && !EliminarAdmin->IsDisposed) {
		// Unsubscribe events
		EliminarAdmin->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaEliminarAdmin_FormClosed);
		// Show the ventanaPrincipal form when EliminarAdmin is closed
	}
	this->Show();
}


private: System::Void ventanaBuscarPais_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaBuscarPais is disposed before accessing it
	if (BuscarPais != nullptr && !BuscarPais->IsDisposed) {
		// Unsubscribe events
		BuscarPais->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaBuscarPais_FormClosed);
		// Show the ventanaPrincipal form when BuscarPais is closed
	}
	this->Show();
}

private: System::Void ventanaBuscarCiudad_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaBuscarCiudad is disposed before accessing it
	if (BuscarCiudad != nullptr && !BuscarCiudad->IsDisposed) {
		// Unsubscribe events
		BuscarCiudad->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaBuscarCiudad_FormClosed);
		// Show the ventanaPrincipal form when BuscarCiudad is closed
	}
	this->Show();
}

private: System::Void ventanaBuscarRestaurante_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaBuscarRestaurante is disposed before accessing it
	if (BuscarRestaurante != nullptr && !BuscarRestaurante->IsDisposed) {
		// Unsubscribe events
		BuscarRestaurante->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaBuscarRestaurante_FormClosed);
		// Show the ventanaPrincipal form when BuscarRestaurante is closed
	}
	this->Show();
}

private: System::Void ventanaBuscarMenu_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaBuscarMenu is disposed before accessing it
	if (BuscarMenu != nullptr && !BuscarMenu->IsDisposed) {
		// Unsubscribe events
		BuscarMenu->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaBuscarMenu_FormClosed);
		// Show the ventanaPrincipal form when BuscarMenu is closed
	}
	this->Show();
}

private: System::Void ventanaBuscarProducto_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaBuscarProducto is disposed before accessing it
	if (BuscarProducto != nullptr && !BuscarProducto->IsDisposed) {
		// Unsubscribe events
		BuscarProducto->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaBuscarProducto_FormClosed);
		// Show the ventanaPrincipal form when BuscarProducto is closed
	}
	this->Show();
}

private: System::Void ventanaBuscarCliente_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaBuscarCliente is disposed before accessing it
	if (BuscarCliente != nullptr && !BuscarCliente->IsDisposed) {
		// Unsubscribe events
		BuscarCliente->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaBuscarCliente_FormClosed);
		// Show the ventanaPrincipal form when BuscarCliente is closed
	}
	this->Show();
}

private: System::Void ventanaBuscarAdmin_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaBuscarAdmin is disposed before accessing it
	if (BuscarAdmin != nullptr && !BuscarAdmin->IsDisposed) {
		// Unsubscribe events
		BuscarAdmin->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaBuscarAdmin_FormClosed);
		// Show the ventanaPrincipal form when BuscarAdmin is closed
	}
	this->Show();
}



private: System::Void ventanaModificarPais_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaModificarPais is disposed before accessing it
	if (ModificarPais != nullptr && !ModificarPais->IsDisposed) {
		// Unsubscribe events
		ModificarPais->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaModificarPais_FormClosed);
		// Show the ventanaPrincipal form when ModificarPais is closed
	}
	this->Show();
}

private: System::Void ventanaModificarCiudad_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaModificarCiudad is disposed before accessing it
	if (ModificarCiudad != nullptr && !ModificarCiudad->IsDisposed) {
		// Unsubscribe events
		ModificarCiudad->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaModificarCiudad_FormClosed);
		// Show the ventanaPrincipal form when ModificarCiudad is closed
	}
	this->Show();
}

private: System::Void ventanaModificarRestaurante_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaModificarRestaurante is disposed before accessing it
	if (ModificarRestaurante != nullptr && !ModificarRestaurante->IsDisposed) {
		// Unsubscribe events
		ModificarRestaurante->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaModificarRestaurante_FormClosed);
		// Show the ventanaPrincipal form when ModificarRestaurante is closed
	}
	this->Show();
}

private: System::Void ventanaModificarMenu_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaModificarMenu is disposed before accessing it
	if (ModificarMenu != nullptr && !ModificarMenu->IsDisposed) {
		// Unsubscribe events
		ModificarMenu->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaModificarMenu_FormClosed);
		// Show the ventanaPrincipal form when ModificarMenu is closed
	}
	this->Show();
}

private: System::Void ventanaModificarProducto_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaModificarProducto is disposed before accessing it
	if (ModificarProducto != nullptr && !ModificarProducto->IsDisposed) {
		// Unsubscribe events
		ModificarProducto->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaModificarProducto_FormClosed);
		// Show the ventanaPrincipal form when ModificarProducto is closed
	}
	this->Show();
}

private: System::Void ventanaModificarCliente_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaModificarCliente is disposed before accessing it
	if (ModificarCliente != nullptr && !ModificarCliente->IsDisposed) {
		// Unsubscribe events
		ModificarCliente->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaModificarCliente_FormClosed);
		// Show the ventanaPrincipal form when ModificarCliente is closed
	}
	this->Show();
}

private: System::Void ventanaModificarAdmin_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaModificarAdmin is disposed before accessing it
	if (ModificarAdmin != nullptr && !ModificarAdmin->IsDisposed) {
		// Unsubscribe events
		ModificarAdmin->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaModificarAdmin_FormClosed);
		// Show the ventanaPrincipal form when ModificarAdmin is closed
	}
	this->Show();
}




private: System::Void toolStripButton3_Click(System::Object^ sender, System::EventArgs^ e) {
	//text box para contacto
	menuContacto = gcnew contacto();
	menuContacto->FormClosed += gcnew FormClosedEventHandler(this, &ventanaMenu::menuContacto_FormClosed);
	menuContacto->Show();
}

private: System::Void MantenimientoMenu_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void leerArchivosMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	progra->cargaInicial();
}

private: System::Void paisToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	//text box para Insertar Pais
	InsertarPais = gcnew ventanaInsertarPais(progra);
	InsertarPais->FormClosed += gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaInsertarPais_FormClosed);
	InsertarPais->Show();
}
private: System::Void ciudadToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	//text box para InsertarCiudad
	InsertarCiudad = gcnew ventanaInsertarCiudad(progra);
	InsertarCiudad->FormClosed += gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaInsertarCiudad_FormClosed);
	InsertarCiudad->Show();
}
private: System::Void restauranteToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	//text box para Insertar Restaurante
	InsertarRestaurante = gcnew ventanaInsertarRestaurante(progra);
	InsertarRestaurante->FormClosed += gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaInsertarRestaurante_FormClosed);
	InsertarRestaurante->Show();
}
private: System::Void menuToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
	//text box para Insertar Menu
	InsertarMenu = gcnew ventanaInsertarMenu(progra);
	InsertarMenu->FormClosed += gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaInsertarMenu_FormClosed);
	InsertarMenu->Show();
}
private: System::Void productoToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	//text box para Insertar Producto
	InsertarProducto = gcnew ventanaInsertarProducto(progra);
	InsertarProducto->FormClosed += gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaInsertarProducto_FormClosed);
	InsertarProducto->Show();
}
private: System::Void clienteToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	//text box para Insertar Cliente
	InsertarCliente = gcnew ventanaInsertarCliente(progra);
	InsertarCliente->FormClosed += gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaInsertarCliente_FormClosed);
	InsertarCliente->Show();
}
private: System::Void adminToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	//text box para Insertar Admin
	InsertarAdmin = gcnew ventanaInsertarAdmin(progra);
	InsertarAdmin->FormClosed += gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaInsertarAdmin_FormClosed);
	InsertarAdmin->Show();
}
private: System::Void paisToolStripMenuItem3_Click(System::Object^ sender, System::EventArgs^ e) {
	//text box para Eliminar Pais
	EliminarPais = gcnew ventanaEliminarPais(progra);
	EliminarPais->FormClosed += gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaEliminarPais_FormClosed);
	EliminarPais->Show();
}
private: System::Void ciudadToolStripMenuItem3_Click(System::Object^ sender, System::EventArgs^ e) {
	//text box para Eliminar Ciudad
	EliminarCiudad = gcnew ventanaEliminarCiudad(progra);
	EliminarCiudad->FormClosed += gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaEliminarCiudad_FormClosed);
	EliminarCiudad->Show();
}
private: System::Void restauranteToolStripMenuItem3_Click(System::Object^ sender, System::EventArgs^ e) {
	//text box para Eliminar Restaurante
	EliminarRestaurante = gcnew ventanaEliminarRestaurante(progra);
	EliminarRestaurante->FormClosed += gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaEliminarRestaurante_FormClosed);
	EliminarRestaurante->Show();
}
private: System::Void menuToolStripMenuItem4_Click(System::Object^ sender, System::EventArgs^ e) {
	//text box para Eliminar Menu
	EliminarMenu = gcnew ventanaEliminarMenu(progra);
	EliminarMenu->FormClosed += gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaEliminarMenu_FormClosed);
	EliminarMenu->Show();
}
private: System::Void productoToolStripMenuItem3_Click(System::Object^ sender, System::EventArgs^ e) {
	//text box para Eliminar Producto
	EliminarProducto = gcnew ventanaEliminarProducto(progra);
	EliminarProducto->FormClosed += gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaEliminarProducto_FormClosed);
	EliminarProducto->Show();
}
private: System::Void clienteToolStripMenuItem3_Click(System::Object^ sender, System::EventArgs^ e) {
	//text box para Eliminar Cliente
	EliminarCliente = gcnew ventanaEliminarCliente(progra);
	EliminarCliente->FormClosed += gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaEliminarCliente_FormClosed);
	EliminarCliente->Show();
}
private: System::Void administradorToolStripMenuItem2_Click(System::Object^ sender, System::EventArgs^ e) {
	//text box para Eliminar Admin
	EliminarAdmin = gcnew ventanaEliminarAdmin(progra);
	EliminarAdmin->FormClosed += gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaEliminarAdmin_FormClosed);
	EliminarAdmin->Show();
}
private: System::Void paisToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
	//text box para Buscar Pais
	BuscarPais = gcnew ventanaBuscarPais(progra);
	BuscarPais->FormClosed += gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaBuscarPais_FormClosed);
	BuscarPais->Show();
}
private: System::Void ciudadToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
	//text box para Buscar Ciudad
	BuscarCiudad = gcnew ventanaBuscarCiudad(progra);
	BuscarCiudad->FormClosed += gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaBuscarCiudad_FormClosed);
	BuscarCiudad->Show();
}
private: System::Void restauranteToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
	//text box para Buscar Restaurante
	BuscarRestaurante = gcnew ventanaBuscarRestaurante(progra);
	BuscarRestaurante->FormClosed += gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaBuscarRestaurante_FormClosed);
	BuscarRestaurante->Show();
}
private: System::Void menuToolStripMenuItem2_Click(System::Object^ sender, System::EventArgs^ e) {
	//text box para Buscar Menu
	BuscarMenu = gcnew ventanaBuscarMenu(progra);
	BuscarMenu->FormClosed += gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaBuscarMenu_FormClosed);
	BuscarMenu->Show();
}
private: System::Void productoToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
	//text box para Buscar Producto
	BuscarProducto = gcnew ventanaBuscarProducto(progra);
	BuscarProducto->FormClosed += gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaBuscarProducto_FormClosed);
	BuscarProducto->Show();
}
private: System::Void BuscaClienteMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	//text box para Buscar Cliente
	BuscarCliente = gcnew ventanaBuscarCliente(progra);
	BuscarCliente->FormClosed += gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaBuscarCliente_FormClosed);
	BuscarCliente->Show();
}
private: System::Void BuscaAdminMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	//text box para Buscar Admin
	BuscarAdmin = gcnew ventanaBuscarAdmin(progra);
	BuscarAdmin->FormClosed += gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaBuscarAdmin_FormClosed);
	BuscarAdmin->Show();
}
private: System::Void paisToolStripMenuItem2_Click(System::Object^ sender, System::EventArgs^ e) {
	//text box para Modificar Pais
	ModificarPais = gcnew ventanaModificarPais(progra);
	ModificarPais->FormClosed += gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaModificarPais_FormClosed);
	ModificarPais->Show();
}
private: System::Void ciudadToolStripMenuItem2_Click(System::Object^ sender, System::EventArgs^ e) {
	//text box para Modificar Ciudad
	ModificarCiudad = gcnew ventanaModificarCiudad(progra);
	ModificarCiudad->FormClosed += gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaModificarCiudad_FormClosed);
	ModificarCiudad->Show();
}
private: System::Void restauranteToolStripMenuItem2_Click(System::Object^ sender, System::EventArgs^ e) {
	//text box para Modificar Restaurante
	ModificarRestaurante = gcnew ventanaModificarRestaurante(progra);
	ModificarRestaurante->FormClosed += gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaModificarRestaurante_FormClosed);
	ModificarRestaurante->Show();
}
private: System::Void menuToolStripMenuItem3_Click(System::Object^ sender, System::EventArgs^ e) {
	//text box para Modificar Menu
	ModificarMenu = gcnew ventanaModificarMenu(progra);
	ModificarMenu->FormClosed += gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaModificarMenu_FormClosed);
	ModificarMenu->Show();
}
private: System::Void productoToolStripMenuItem2_Click(System::Object^ sender, System::EventArgs^ e) {
	//text box para Modificar Producto
	ModificarProducto = gcnew ventanaModificarProducto(progra);
	ModificarProducto->FormClosed += gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaModificarProducto_FormClosed);
	ModificarProducto->Show();
}
private: System::Void clienteToolStripMenuItem2_Click(System::Object^ sender, System::EventArgs^ e) {
	//text box para Modificar Cliente
	ModificarCliente = gcnew ventanaModificarCliente(progra);
	ModificarCliente->FormClosed += gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaModificarCliente_FormClosed);
	ModificarCliente->Show();
}
private: System::Void administradorToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	//text box para Modificar Admin
	ModificarAdmin = gcnew ventanaModificarAdmin(progra);
	ModificarAdmin->FormClosed += gcnew FormClosedEventHandler(this, &ventanaMenu::ventanaModificarAdmin_FormClosed);
	ModificarAdmin->Show();
}

private: System::Void checkedListBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	//text box para popupLugares
	popupLugares = gcnew ventanaPopupLugares(progra);
	popupLugares->FormClosed += gcnew FormClosedEventHandler(this, &ventanaMenu::popupLugares_FormClosed);
	popupLugares->Show();
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	popupUsuarios = gcnew ventanaPopupUsuarios(progra);
	popupUsuarios->FormClosed += gcnew FormClosedEventHandler(this, &ventanaMenu::popupUsuarios_FormClosed);
	popupUsuarios->Show();
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	popupRestaurantes = gcnew ventanaPopupRestaurantes(progra);
	popupRestaurantes->FormClosed += gcnew FormClosedEventHandler(this, &ventanaMenu::popupRestaurantes_FormClosed);
	popupRestaurantes->Show();
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	popupPagos = gcnew ventanaPopupPagos(progra);
	popupPagos->FormClosed += gcnew FormClosedEventHandler(this, &ventanaMenu::popupPagos_FormClosed);
	popupPagos->Show();
}
private: System::Void insertarMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
}
};

}
