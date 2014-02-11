#include "cube.h"
#include "ClrServer.h"


ClrServer::ClrServer()
{
	plugins = gcnew PluginList();
}


ClrServer::~ClrServer()
{
}

void ClrServer::LoadDll(const char* path){
	System::Reflection::Assembly^ assembly = System::AppDomain::CurrentDomain->Load(gcnew System::String(path));

	auto types = assembly->GetExportedTypes();

	for (int i = 0; i < types->Length; i++) {
		if (types[0]->IsAssignableFrom(IPlugin::typeid)) {
			IPlugin^ plugin = dynamic_cast<IPlugin^>(System::Activator::CreateInstance(types[0]));

			plugins->Add(plugin);
		}
	}
}

bool ClrServer::OnInit()
{
	return true;
}

bool ClrServer::OnConnecting(int clientNumber, System::String^ hostname, System::String^ name, System::String^ password, bool isReserved)
{
	return true;
}
bool ClrServer::OnConnect(int clientNumber, bool spy)
{
	return true;
}
bool ClrServer::OnDisconnect(int clientNumber, System::String^ reason)
{
	return true;
}
bool ClrServer::OnFailedConnect(System::String^ hostname, System::String^ reason)
{
	return true;
}
