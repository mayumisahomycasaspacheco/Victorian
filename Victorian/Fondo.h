#pragma once
using namespace System;
using namespace System::Drawing;

inline Bitmap^ cargar_fondo()
{
	try
	{
		System::Net::ServicePointManager::SecurityProtocol = System::Net::SecurityProtocolType::Tls12;
		System::Net::WebClient^ cliente = gcnew System::Net::WebClient();
		array<Byte>^ datos = cliente->DownloadData("https://cdn.hackclub.com/01a1975a-e9d4-7cf4-b386-b0d910f2cba5/sprite-0001.png");
		System::IO::MemoryStream^ flujo = gcnew System::IO::MemoryStream(datos);
		return gcnew Bitmap(flujo);
	}
	catch (Exception^)
	{
		return nullptr;
	}
}