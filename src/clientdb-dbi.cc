#include <dbi/dbi.h>
#include <dbi/dbd.h>
#include <iostream>
#include "octetos/core/common.hh"

#include "clientdb-dbi.hh"
#include "config.h"


namespace octetos
{
namespace db
{
namespace dbi
{        
	
	/*std::string getPakageName()
	{
        #ifdef ENABLED_CMAKE
        return PACKAGE_NAME;
		#elif defined ENABLED_AUTOTOOLS
		return PACKAGE;
        #endif
	}
	
	octetos::core::Artifact getPackageInfo()
	{
		octetos::core::Artifact packinfo;
		
		#ifdef ENABLED_CMAKE
		packinfo.name = PACKAGE_NAME;
		packinfo.brief = PACKAGE_BRIEF;
		//packinfo.url = PACKAGE_URL;
		
		packinfo.version.setNumbers(VERSION_MAJOR,VERSION_MINOR,VERSION_PATCH);
		packinfo.version.setStage(VERSION_STAGE);
		packinfo.version.setBuild(std::stoul(VERSION_BUILD));
		
		packinfo.licence.type = Licence::Type::GPL;		
		packinfo.licence.name_public = packinfo.name;
		packinfo.licence.owner = "Azael Reyes";
		packinfo.licence.year = 2019;
        packinfo.licence.contact = "azael.devel@gmail.com";
		#elif defined ENABLED_AUTOTOOLS
		packinfo.name = PACKAGE;
		packinfo.brief = "";
		packinfo.url = "";
		
		//packinfo.version.setNumbers(0,0,0);
		//packinfo.version.setStage(Version::Stage::alpha);
		//packinfo.version.setBuild(std::stoul(VERSION_BUILD));
		packinfo.version.set(VERSION);
		
		packinfo.licence.type = Licence::Type::GPL;		
		packinfo.licence.name_public = packinfo.name;
		packinfo.licence.owner = "Azael Reyes";
		packinfo.licence.year = 2019
        packinfo.licence.contact = "azael.devel@gmail.com";
		#endif
		return packinfo;	
	}*/
        
        
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
        
        
        
        
        
       
        
        /*db::Row* Datresult::operator[](unsigned long long index)
        {
                Row* r = NULL;
                if(mysql_num_rows((MYSQL_RES*)result)  < index)
                {
                        mysql_data_seek((MYSQL_RES*)result,index); 
                        if(index >= 0) 
                        {
                                MYSQL_ROW row  = mysql_fetch_row((MYSQL_RES*)result);
                                 r = new Row(row);
#ifdef COLLETION_ASSISTANT
                                addChild(r);
#endif                                 
                                return r;
                        }
                        else
                        {
                                 r = new Row(NULL);
                                  return r;
                        }
                        
                }                
                return r;
        }*/
        
        /*Datresult::Datresult(void* result) : db::Datresult(result)
        {
        }*/
        
        /*db::Row* Datresult::next()
        {
                MYSQL_ROW row  = mysql_fetch_row((MYSQL_RES*)result);
                Row* r = new Row(row);
#ifdef COLLETION_ASSISTANT
                addChild(r);
#endif                                 
                return r;
        }*/
        /*Datresult::~Datresult()
        {
                if(result != NULL)
                {
                        mysql_free_result((MYSQL_RES*)result);
                        result = NULL;
                }
#ifdef COLLETION_ASSISTANT
                if(getCountChilds() > 0)
                {
                        std::cerr << "Una instacia de '" << typeid(*this).name() << "' termino sin que todos sus hijos terminaran primero" << std::endl;
                }
#endif
        }*/
        
   	std::string Datconnect::toString()const
	{
		std::string str = getStringDriver() + "://";
		str += db::Datconnect::toString();

		return str;
	}
	std::string Datconnect::getStringDriver()const
	{
		if(getDriver() == Driver::MySQL or getDriver() == Driver::OCTEOS_DB_MySQL_C or getDriver() == db::Driver::OCTEOS_DBI_MYSQL)
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
		
		return NULL;
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
