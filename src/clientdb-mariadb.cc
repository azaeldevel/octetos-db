#include <mysql/mysql.h>
#include <iostream>
#include <octetos/core/Artifact.hh>
#include <string.h>

#include "clientdb-mariadb.hh"
#include "config.h"

namespace octetos
{
namespace db
{
namespace mariadb
{        
        



	char Row::getchar(const std::string&)const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica.");
	}
	unsigned char Row::getuchar(const std::string&)const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica.");
	}
	short Row::getshort(const std::string&)const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica.");
	}
	unsigned short Row::getushort(const std::string&)const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica.");
	}
	unsigned int Row::getuint(const std::string&)const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica.");
	}
	unsigned long Row::getul(const std::string&)const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica.");
	}
	unsigned long long Row::getull(const std::string&)const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica.");
	}
	float Row::getfloat(const std::string&)const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica.");
	}
	double Row::getdouble(const std::string&)const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica.");
	}
	int Row::getint(const std::string&) const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica.");
	}
	long Row::getl(const std::string&)const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica.");
	}
	long long Row::getll(const std::string&)const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica.");
	}
	std::string Row::getString(const std::string&)const 
	{ 
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica.");
	}
	
	char Row::getchar(FieldNumber field)const
	{
		MYSQL_ROW r = (MYSQL_ROW)row;
		return r[field] ? r[field][0] : 0;
	}
	unsigned char Row::getuchar(FieldNumber field)const
	{
		MYSQL_ROW r = (MYSQL_ROW)row;
		return r[field] ? (unsigned char)r[field][0] : '\0';
	}
	short Row::getshort(FieldNumber field)const
	{
		MYSQL_ROW r = (MYSQL_ROW)row;
		return r[field] ? (short)std::stoi(r[field]) : '\0';
	}
	unsigned short Row::getushort(FieldNumber field)const
	{
		MYSQL_ROW r = (MYSQL_ROW)row;
		return r[field] ? (unsigned short)std::stoul(r[field]) : 0;
	}
	unsigned int Row::getuint(FieldNumber field)const
	{
		MYSQL_ROW r = (MYSQL_ROW)row;
		return r[field] ? (unsigned int)std::stoul(r[field]) : 0;
	}
	unsigned long Row::getul(FieldNumber field)const
	{
		MYSQL_ROW r = (MYSQL_ROW)row;
		return r[field] ? std::stoul(r[field]) : 0;
	}
	unsigned long long Row::getull(FieldNumber field)const
	{
		MYSQL_ROW r = (MYSQL_ROW)row;
		return r[field] ? std::stoull(r[field]) : 0;
	}
	float Row::getfloat(FieldNumber field)const
	{
		MYSQL_ROW r = (MYSQL_ROW)row;
		return r[field] ? std::stof(r[field]) : 0;
	}
	double Row::getdouble(FieldNumber field)const
	{
		MYSQL_ROW r = (MYSQL_ROW)row;
		return r[field] ? std::stod(r[field]) : 0;
	}
	int Row::getint(FieldNumber field)const
	{
		MYSQL_ROW r = (MYSQL_ROW)row;
		return r[field] ? std::atol(r[field]) : 0;
	}
	long Row::getl(FieldNumber field)const
	{
		MYSQL_ROW r = (MYSQL_ROW)row;
		return r[field] ? std::atol(r[field]) : 0;
	}
	long long Row::getll(FieldNumber field)const
	{
		MYSQL_ROW r = (MYSQL_ROW)row;
		return r[field] ? std::atoll(r[field]) : 0;
	}
	std::string Row::getString(FieldNumber field)const 
	{
		MYSQL_ROW r = (MYSQL_ROW)row;
		return r[field] ? r[field] : "";
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
	Row::Row(const Row& r)
	{
		this->row = r.row;
	}        
	Row::Row()
	{
		
	}
	Row::Row(void* row)
	{
		this->row = row;
	}
        
        

  	char Datresult::getchar(const std::string&)const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica.");
	}
	unsigned char Datresult::getuchar(const std::string&)const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica.");
	}
	short Datresult::getshort(const std::string&)const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica.");
	}
	unsigned short Datresult::getushort(const std::string&)const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica.");
	}
	unsigned int Datresult::getuint(const std::string&)const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica.");
	}
	unsigned long Datresult::getul(const std::string&)const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica.");
	}
	unsigned long long Datresult::getull(const std::string&)const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica.");
	}
	float Datresult::getfloat(const std::string&)const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica.");
	}
	double Datresult::getdouble(const std::string&)const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica.");
	}
	int Datresult::getint(const std::string&) const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica.");
	}
	long Datresult::getl(const std::string&)const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica.");
	}
	long long Datresult::getll(const std::string&)const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica.");
	}
	std::string Datresult::getString(const std::string&)const 
	{ 
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica.");
	}
	
	char Datresult::getchar(FieldNumber field)const
	{
		return actualRow ? actualRow->getchar(field) : 0;
	}
	unsigned char Datresult::getuchar(FieldNumber field)const
	{
		return actualRow ? actualRow->getuchar(field) : 0;
	}
	short Datresult::getshort(FieldNumber field)const
	{
		return actualRow ? actualRow->getshort(field) : 0;
	}
	unsigned short Datresult::getushort(FieldNumber field)const
	{
		return actualRow ? actualRow->getushort(field) : 0;
	}
	unsigned int Datresult::getuint(FieldNumber field)const
	{
		return actualRow ? actualRow->getuint(field) : 0;
	}
	unsigned long Datresult::getul(FieldNumber field)const
	{
		return actualRow ? actualRow->getul(field) : 0;
	}
	unsigned long long Datresult::getull(FieldNumber field)const
	{
		return actualRow ? actualRow->getull(field) : 0;
	}
	float Datresult::getfloat(FieldNumber field)const
	{
		return actualRow ? actualRow->getfloat(field) : 0;
	}
	double Datresult::getdouble(FieldNumber field)const
	{
		return actualRow ? actualRow->getdouble(field) : 0;
	}
	int Datresult::getint(FieldNumber field) const
	{
		return actualRow ? actualRow->getint(field) : 0;
	}
	long Datresult::getl(FieldNumber field)const
	{
		return actualRow ? ((Row*)actualRow)->getl(field) : 0;
	}
	long long Datresult::getll(FieldNumber field)const
	{
		return actualRow ? ((Row*)actualRow)->getll(field) : 0;
	}
	std::string Datresult::getString(FieldNumber field)const 
	{
		return actualRow ? ((Row*)actualRow)->getString(field) : "";
	}
	bool Datresult::nextRow()
	{
		MYSQL_ROW row  = mysql_fetch_row((MYSQL_RES*)getResult());
		if(actualRow)
		{
			delete actualRow;
		}
		actualRow = new Row(row);
#ifdef COLLETION_ASSISTANT
		addChild(actualRow);
#endif 		
		if(row) return true;
		return false;
	}
        
        Datresult::Datresult(void* result) : db::Datresult(result)
        {
			actualRow = NULL;
        }
	Datresult::Datresult()
	{
		actualRow = NULL;
	}
	Datresult::~Datresult()
	{
		if(actualRow)
		{
			delete actualRow;
		}
		if(getResult())
		{
			mysql_free_result((MYSQL_RES*)getResult());
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
        Datconnect::Datconnect(const Datconnect& obj) : db::Datconnect(obj)
        {
        }
        
        const Datconnect& Datconnect::operator=(const Datconnect& obj)
        {		
             ((db::Datconnect&)*this)=obj;//llamar el construc de la clase base
             return *this;
        }
        
        Datconnect::Datconnect(const std::string& host, unsigned int port,const std::string& database,const std::string& user,const std::string& password) : db::Datconnect(Driver::MariaDB,host,port,database,user,password)
        {
        }
        
        

	bool Connector::select(const std::string& str,db::Datresult& rs)
	{
		return execute (str,rs);
	}		
	RowNumber Connector::update(const std::string&,db::Datresult&)
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica.");
	}		
	RowNumber Connector::remove(const std::string&,db::Datresult&)
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica.");
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
	bool Connector::execute(const std::string& str,db::Datresult& rs)
	{
		if (mysql_query((MYSQL*)conn, str.c_str())  != 0) 
		{
			std::string msg = "";
			msg = msg + " MySQL Server Error No. : '";
			msg = msg + std::to_string(mysql_errno((MYSQL*)conn));
			msg = msg + "' ";
			msg = msg + mysql_error((MYSQL*)conn);  
			core::Error::write(SQLException(msg)); 
			return false;
		}
		MYSQL_RES *result = mysql_store_result((MYSQL*)conn);
		if (result == NULL && mysql_errno((MYSQL*)conn) != 0) 
		{
			std::string msg = "";
			msg = msg + " MySQL Server Error No. : '";
			msg = msg + std::to_string(mysql_errno((MYSQL*)conn));
			msg = msg + "' ";
			msg = msg + mysql_error((MYSQL*)conn);  
			core::Error::write(SQLException(msg));
			return false;
		}
		rs = (Result)result;   
		return true;
	}
	core::Semver Connector::getVerionServer() const
	{
		core::Semver ver;
		ver.set(mysql_get_server_version((MYSQL*)conn),core::semver::ImportCode::MySQL);
		
		return ver;
	}
        bool Connector::begin()
        {
            return false; 
        }
	void Connector::close()
	{
		if (conn) 
		{
			mysql_close((MYSQL*)conn);
			conn = NULL;
			datconn = NULL;
		}
	}       
        bool Connector::rollback()
        {
                if (conn != NULL)
                {
                        if(mysql_rollback((MYSQL*)conn) == 0)
                        {
                        return true;
                        }
                }
            
                return false; 
        }        
        bool Connector::commit()
        {
            if (conn != NULL)
            {
                if(mysql_commit((MYSQL*)conn) == 0)
                {
                    return true;
                }
            }
            
            return false; 
        }
	RowNumber Connector::insert(const std::string& str,db::Datresult&)
	{
            if (mysql_query((MYSQL*)conn, str.c_str()) == 0) 
            {
                return mysql_insert_id((MYSQL*)conn);
            }
            else
            {   
                return 0; 
            }		
	}     
        /*const char* Connector::serverDescription()
        {
            return mysql_get_client_info();
        }*/
	bool Connector::connect(const db::Datconnect& dtcon)
	{
           	conn = mysql_init(NULL);
            if (conn == NULL)
            {
                std::string msg = "";
                msg = msg + " MySQL Server Error No. : '";
                msg = msg + std::to_string(mysql_errno((MYSQL*)conn));
                msg = msg + "' ";
                msg = msg + mysql_error((MYSQL*)conn);  
				core::Error::write(SQLException(msg));
				return false;
            }
            if (mysql_real_connect((MYSQL*)conn, dtcon.getHost().c_str(), dtcon.getUser().c_str(), dtcon.getPassword().c_str(),dtcon.getDatabase().c_str(),dtcon.getPort(), NULL, 0) == NULL)
            {
                std::string msg = "";
                msg = msg + " MySQL Server Error No. : '";
                msg = msg + std::to_string(mysql_errno((MYSQL*)conn));
                msg = msg + "' ";
                msg = msg + mysql_error((MYSQL*)conn);
				core::Error::write(SQLException(msg));
				return false;
            }        
            if(mysql_autocommit((MYSQL*)conn,0) != 0)
            {
                std::string msg = "";
                msg = msg + " MySQL Server Error No. : '";
                msg = msg + std::to_string(mysql_errno((MYSQL*)conn));
                msg = msg + "' ";
                msg = msg + mysql_error((MYSQL*)conn);                
				core::Error::write(SQLException(msg));
				return false;
            }        
			datconn = &dtcon;
            return true;
	}
}
}
}
