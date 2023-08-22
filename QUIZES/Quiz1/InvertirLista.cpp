void lista::Invertir()
{
	pnodo ant;
	pnodo sig = primero;
	while(primero!=NULL)
	{
		primero = primero->siguiente;
		sig->siguiente=ant;
		ant=sig;
		sig=primero;
	}
	primero=ant;
}
