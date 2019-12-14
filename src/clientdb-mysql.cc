#include <mysql/mysql.h>
#include <iostream>
#include "octetos/core/common.hh"

#include "clientdb-mysql.hh"
//#include "versionInfo-myc++.h"
#ifdef ENABLED_CMAKE
	#include "packInfo.hpp"
#endif
#ifdef ENABLED_AUTOTOOLS
	#include "config.h"
#endif

namespace octetos
{
namespace db
{
namespace clientdb
{
namespace mysql
{        
        
	std::string getPakageName()
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
	}
        
        
        Row::~Row()
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
        Row::Row(void* row):db::clientdb::Row(row)
        {
#ifdef COLLETION_ASSISTANT
                
#endif
        }
        
        
        
        
        
       
        
        db::clientdb::Row* Datresult::operator[](unsigned long long index)
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
        }
        
        Datresult::Datresult(void* result) : db::clientdb::Datresult(result)
        {
        }
        
        db::clientdb::Row* Datresult::next()
        {
                MYSQL_ROW row  = mysql_fetch_row((MYSQL_RES*)result);
                Row* r = new Row(row);
#ifdef COLLETION_ASSISTANT
                addChild(r);
#endif                                 
                return r;
        }
        Datresult::~Datresult()
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
        Datconnect::Datconnect(const Datconnect& obj) : db::clientdb::Datconnect(obj)
        {
        }
        
        const Datconnect& Datconnect::operator=(const Datconnect& obj)
        {		
             ((clientdb::Datconnect&)*this)=obj;//llamar el construc de la clase base
             return *this;
        }
        
        Datconnect::Datconnect(const std::string& host, unsigned int port,const std::string& database,const std::string& user,const std::string& password) : clientdb::Datconnect(ServerType::MySQL,host,port,database,user,password)
        {
        }
        
        

        
        Connector::Connector()
        {
        }
        Connector::~Connector()
        {
                close();
#ifdef COLLETION_ASSISTANT
                if(getCountChilds() > 0)
                {
                        std::cerr << "Una instacia de '" << typeid(*this).name() << "' termino sin que todos sus hijos terminaran primero" << std::endl;
                }
#endif
        }
        db::clientdb::Datresult* Connector::query(const char* str)
        {
                if (mysql_query((MYSQL*)serverConnector, str)  != 0) 
                {
                        std::string msg = "";
                        msg = msg + " MySQL Server Error No. : '";
                        msg = msg + std::to_string(mysql_errno((MYSQL*)serverConnector));
                        msg = msg + "' ";
                        msg = msg + mysql_error((MYSQL*)serverConnector);
                        throw SQLException(msg);   
                }
                MYSQL_RES *result = mysql_store_result((MYSQL*)serverConnector);
                if (result == NULL && mysql_errno((MYSQL*)serverConnector) != 0) 
                {
                        std::string msg = "";
                        msg = msg + " MySQL Server Error No. : '";
                        msg = msg + std::to_string(mysql_errno((MYSQL*)serverConnector));
                        msg = msg + "' ";
                        msg = msg + mysql_error((MYSQL*)serverConnector);
                        throw SQLException(msg);   
                }
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
                if (serverConnector != NULL) mysql_close((MYSQL*)serverConnector);
                serverConnector = NULL;
        }       
        bool Connector::rollback()
        {
                if (serverConnector != NULL)
                {
                        if(mysql_rollback((MYSQL*)serverConnector) == 0)
                        {
                        return true;
                        }
                }
            
                return false; 
        }        
        bool Connector::commit()
        {
            if (serverConnector != NULL)
            {
                if(mysql_commit((MYSQL*)serverConnector) == 0)
                {
                    return true;
                }
            }
            
            return false; 
        }
        unsigned long long Connector::insert(const std::string& str)
        {
            if (mysql_query((MYSQL*)serverConnector, str.c_str()) == 0) 
            {
                return mysql_insert_id((MYSQL*)serverConnector);
            }
            else
            {   
                return 0; 
            }		
        }        
        const char* Connector::serverDescription()
        {
            return mysql_get_client_info();
        }
        bool Connector::connect(const db::clientdb::Datconnect* conection)
        {
            serverConnector = (void*)mysql_init(NULL);
            if (serverConnector == NULL)
            {
                std::string msg = "";
                msg = msg + " MySQL Server Error No. : '";
                msg = msg + std::to_string(mysql_errno((MYSQL*)serverConnector));
                msg = msg + "' ";
                msg = msg + mysql_error((MYSQL*)serverConnector);
                throw SQLException(msg);           
            }
            if (mysql_real_connect((MYSQL*)serverConnector, conection->getHost().c_str(), conection->getUser().c_str(), conection->getPassword().c_str(),conection->getDatabase().c_str(),conection->getPort(), NULL, 0) == NULL)
            {
                std::string msg = "";
                msg = msg + " MySQL Server Error No. : '";
                msg = msg + std::to_string(mysql_errno((MYSQL*)serverConnector));
                msg = msg + "' ";
                msg = msg + mysql_error((MYSQL*)serverConnector);
                throw SQLException(msg);
            }        
            if(mysql_autocommit((MYSQL*)serverConnector,0) != 0)
            {
                std::string msg = "";
                msg = msg + " MySQL Server Error No. : '";
                msg = msg + std::to_string(mysql_errno((MYSQL*)serverConnector));
                msg = msg + "' ";
                msg = msg + mysql_error((MYSQL*)serverConnector);
                throw SQLException(msg);
            }        
            datconection = conection;
            return true;
        }
}    
}
}
}
