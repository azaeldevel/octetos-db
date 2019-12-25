#include <dbi/dbi.h>
#include <dbi/dbd.h>
#include <iostream>
#include "octetos/core/Artifact.hh"

#include "clientdb-dbi.hh"
#include "config.h"


namespace octetos
{
namespace db
{
namespace dbi
{        
	
	std::string getPakageName()
	{
		return PACKAGE;
	}
	
	octetos::core::Artifact getPackageInfo()
	{
		octetos::core::Artifact packinfo;
		
		packinfo.name = PACKAGE;
		packinfo.brief = "";
		packinfo.url = "";
		
		//packinfo.version.setNumbers(0,0,0);
		//packinfo.version.setStage(Version::Stage::alpha);
		//packinfo.version.setBuild(std::stoul(VERSION_BUILD));
		packinfo.version.set(VERSION);
		
		packinfo.licence.type = core::Licence::Type::GPL;		
		packinfo.licence.name_public = packinfo.name;
		packinfo.licence.owner = "Azael Reyes";
		packinfo.licence.year = 2019;
        packinfo.licence.contact = "azael.devel@gmail.com";
		
		return packinfo;	
	}
        
        
        /*Row::~Row()
        {
#ifdef COLLETION_ASSISTANT
                if(getCountChilds() > 0)
                {
                        std::cerr << "Una instacia de '" << typeid(*this).name() << "' termino sin que todos sus hijos terminaran primero" << std::endl;
                }                
#endif
        }
        Row::Row(Row& row)
        {
                this->row = row.row;
        }
         const char* Row::operator[](unsigned long long index)
         {
                 if(row != NULL) return ((MYSQL_ROW)row)[index];
                 return NULL;
        }
        Row::Row()
        {
#ifdef COLLETION_ASSISTANT
                
#endif
        }
        Row::Row(void* row):db::Row(row)
        {
#ifdef COLLETION_ASSISTANT
                
#endif
        }*/
        
        
        
        
        
       
	bool Datresult::nextRow()
	{
		if (result) 
		{
			return dbi_result_next_row(result);
		}

		return false;
	}
	unsigned int Datresult::getuint(const std::string& field)const
	{
		return dbi_result_get_uint(result, field.c_str());
	}
	std::string Datresult::getString(const std::string& field)const
	{
		return dbi_result_get_string(result, field.c_str());
	}
	db::Row* Datresult::operator[](unsigned long long index)
	{
    	return NULL;
	}
        
	Datresult::Datresult(void* result) : db::Datresult(result)
	{
	}        
	db::Row* Datresult::next()
	{
		throw NotSupportedExcetion("Datresult::next no tiene soporte en DBI, ademas, esta funcion esta desclasificada, use nextRow en su lugar.");
	}
	Datresult::~Datresult()
	{
		if(result != NULL)
		{
			dbi_result_free(result);
			result = NULL;
		}
#ifdef COLLETION_ASSISTANT
		if(getCountChilds() > 0)
		{
			std::cerr << "Una instacia de '" << typeid(*this).name() << "' termino sin que todos sus hijos terminaran primero" << std::endl;
		}
#endif
	}








	
   	std::string Datconnect::toString()const
	{
		std::string str = getStringDriver() + "://";
		str += db::Datconnect::toString();

		return str;
	}
	std::string Datconnect::getStringDriver()const
	{
		if(getDriver() == Driver::MySQL or getDriver() == db::Driver::DBI_MYSQL)
		{
			return "mysql";
		}

		return "unknow";
	}
	Datconnect::~Datconnect() 
    {                
#ifdef COLLETION_ASSISTANT
		if(getCountChilds() > 0)
		{
			std::cerr << "Una instacia de '" << typeid(*this).name() << "' termino sin que todos sus hijos terminaran primero" << std::endl;
		}
#endif
	}
	Datconnect::Datconnect()
	{
	}
	Datconnect::Datconnect(const Datconnect& obj) : db::Datconnect(obj)
	{
	}
	/*const Datconnect& Datconnect::operator=(const Datconnect& obj)
	{		
   		((db::Datconnect&)*this)=obj;//llamar el construc de la clase base
    	return *this;
	}*/        
	Datconnect::Datconnect(Driver driver,const std::string& host, unsigned int port,const std::string& database,const std::string& user,const std::string& password) : db::Datconnect(driver,host,port,database,user,password)
    {			
	}




	
        

        
	Connector::Connector()
	{
	}
	Connector::~Connector()
	{
		if (serverConnector != NULL) close();
#ifdef COLLETION_ASSISTANT
		if(getCountChilds() > 0)
		{
			std::cerr << "Una instacia de '" << typeid(*this).name() << "' termino sin que todos sus hijos terminaran primero" << std::endl;
		}
#endif
	}
	db::Datresult* Connector::query(const char* str)
	{
		dbi_result result = dbi_conn_queryf(serverConnector,str);

		Datresult* dtrs = new Datresult(result);
#ifdef COLLETION_ASSISTANT
     	addChild(dtrs);
#endif    
    	return dtrs;
	}
	bool Connector::begin()
	{
		return false; 
	}
	void Connector::close()
	{
		if (serverConnector != NULL) dbi_conn_close(serverConnector);
		serverConnector = NULL;
	}     
	bool Connector::rollback()
	{
		return false; 
	}       
	bool Connector::commit()
	{    
		return false; 
	}
	unsigned long long Connector::insert(const std::string& str)
	{		
		return 0;            	
	}        
	const char* Connector::serverDescription()
	{
		        return NULL;
	}    
	std::string Connector::getVerionString()
	{
		char verstr[50];
		dbi_conn_get_engine_version_string(serverConnector,verstr);
		std::string strret = verstr;
		return strret;
	}
	bool Connector::connect(const db::Datconnect* datcon)
	{
		dbi_initialize_r(NULL, &instance);			
		serverConnector = dbi_conn_new_r(((octetos::db::dbi::Datconnect*)datcon)->getStringDriver().c_str(), instance);
					
		dbi_conn_set_option(serverConnector, "host", ((octetos::db::dbi::Datconnect*)datcon)->getHost().c_str());
		dbi_conn_set_option(serverConnector, "username", ((octetos::db::dbi::Datconnect*)datcon)->getUser().c_str());
		dbi_conn_set_option(serverConnector, "password", ((octetos::db::dbi::Datconnect*)datcon)->getPassword().c_str());
		dbi_conn_set_option(serverConnector, "dbname", ((octetos::db::dbi::Datconnect*)datcon)->getDatabase().c_str());

		if (dbi_conn_connect(serverConnector) < 0) 
		{
			return false;
		}

		return true;
	}


}
}
}
