#include <mysql/mysql.h>
#include <iostream>
#include <octetos/core/Artifact.hh>
#include <string.h>

#include "clientdb-mysql.hh"
#include "config.h"

namespace octetos
{
namespace db
{
namespace mysql
{        
        




	int Row::getint(db::IndexField field)const
	{
		MYSQL_ROW r = (MYSQL_ROW)row;
		return r[field] ? std::atol(r[field]) : 0;
	}
	long Row::getl(db::IndexField field)const
	{
		MYSQL_ROW r = (MYSQL_ROW)row;
		return r[field] ? std::atol(r[field]) : 0;
	}
	long long Row::getll(db::IndexField field)const
	{
		MYSQL_ROW r = (MYSQL_ROW)row;
		return r[field] ? std::atoll(r[field]) : 0;
	}
	std::string Row::getString(db::IndexField field)const 
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
        
        

	size_t Datresult::getFieldLength(db::IndexField field) const
	{

	}
	size_t Datresult::getFieldLength(const std::string&) const
	{

	}
	IndexField Datresult::getFieldNumbers() const
	{

	}
  	char Datresult::getchar(const std::string&)const
	{

	}
	unsigned char Datresult::getuchar(const std::string&)const
	{

	}
	short Datresult::getshort(const std::string&)const
	{

	}
	unsigned short Datresult::getushort(const std::string&)const
	{

	}
	unsigned int Datresult::getuint(const std::string&)const
	{

	}
	unsigned long Datresult::getul(const std::string&)const
	{

	}
	unsigned long long Datresult::getull(const std::string&)const
	{

	}
	float Datresult::getfloat(const std::string&)const
	{

	}
	double Datresult::getdouble(const std::string&)const
	{

	}
	int Datresult::getint(const std::string&) const
	{
		
	}
	long Datresult::getl(const std::string&)const
	{
		
	}
	long long Datresult::getll(const std::string&)const
	{
		
	}
	std::string Datresult::getString(const std::string&)const 
	{ 
		
	}
	
	char Datresult::getchar(db::IndexField field)const
	{

	}
	unsigned char Datresult::getuchar(db::IndexField field)const
	{

	}
	short Datresult::getshort(db::IndexField field)const
	{

	}
	unsigned short Datresult::getushort(db::IndexField field)const
	{

	}
	unsigned int Datresult::getuint(db::IndexField field)const
	{

	}
	unsigned long Datresult::getul(db::IndexField field)const
	{

	}
	unsigned long long Datresult::getull(db::IndexField field)const
	{

	}
	float Datresult::getfloat(db::IndexField field)const
	{

	}
	double Datresult::getdouble(db::IndexField field)const
	{

	}
	int Datresult::getint(db::IndexField field) const
	{
		if(!actualRow) return actualRow->getint(field);
		return 0;
	}
	long Datresult::getl(db::IndexField field)const
	{
		if(!(Row*)actualRow) return ((Row*)actualRow)->getl(field);
		return 0;
	}
	long long Datresult::getll(db::IndexField field)const
	{
		return ((Row*)actualRow)->getll(field);
	}
	std::string Datresult::getString(db::IndexField field)const 
	{
		if(actualRow) return "yes";
		return "no";
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
        
        Datconnect::Datconnect(const std::string& host, unsigned int port,const std::string& database,const std::string& user,const std::string& password) : db::Datconnect(Driver::MySQL,host,port,database,user,password)
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
        db::Datresult* Connector::execute(const std::string& strq)
        {
                if (mysql_query((MYSQL*)getConnection(), strq.c_str())  != 0) 
                {
                        std::string msg = "";
                        msg = msg + " MySQL Server Error No. : '";
                        msg = msg + std::to_string(mysql_errno((MYSQL*)getConnection()));
                        msg = msg + "' ";
                        msg = msg + mysql_error((MYSQL*)getConnection());
                        throw SQLException(msg);   
                }
                MYSQL_RES *result = mysql_store_result((MYSQL*)getConnection());
                if (result == NULL && mysql_errno((MYSQL*)getConnection()) != 0) 
                {
                        std::string msg = "";
                        msg = msg + " MySQL Server Error No. : '";
                        msg = msg + std::to_string(mysql_errno((MYSQL*)getConnection()));
                        msg = msg + "' ";
                        msg = msg + mysql_error((MYSQL*)getConnection());
                        throw SQLException(msg);   
                }
                Datresult* dtrs = new Datresult(result);
#ifdef COLLETION_ASSISTANT
                addChild(dtrs);
#endif    
                return dtrs;
        }
	core::Semver Connector::getVerionServer() const
	{
		core::Semver ver;
		ver.set(mysql_get_server_version((MYSQL*)getConnection()),core::semver::ImportCode::MySQL);
		
		return ver;
	}
        bool Connector::begin()
        {
            return false; 
        }
        void Connector::close()
        {
                if (getConnection() != NULL) mysql_close((MYSQL*)getConnection());
        }       
        bool Connector::rollback()
        {
                if (getConnection() != NULL)
                {
                        if(mysql_rollback((MYSQL*)getConnection()) == 0)
                        {
                        return true;
                        }
                }
            
                return false; 
        }        
        bool Connector::commit()
        {
            if (getConnection() != NULL)
            {
                if(mysql_commit((MYSQL*)getConnection()) == 0)
                {
                    return true;
                }
            }
            
            return false; 
        }
        /*unsigned long long Connector::insert(const std::string& str)
        {
            if (mysql_query((MYSQL*)serverConnector, str.c_str()) == 0) 
            {
                return mysql_insert_id((MYSQL*)serverConnector);
            }
            else
            {   
                return 0; 
            }		
        }     */   
        /*const char* Connector::serverDescription()
        {
            return mysql_get_client_info();
        }*/
        bool Connector::connect(const db::Datconnect* dtcon)
        {
            MYSQL* conn = mysql_init(NULL);
            if (getConnection() == NULL)
            {
                /*std::string msg = "";
                msg = msg + " MySQL Server Error No. : '";
                msg = msg + std::to_string(mysql_errno(conn));
                msg = msg + "' ";
                msg = msg + mysql_error(conn);
                throw SQLException(msg);*/
				return false;
            }
            if (mysql_real_connect(conn, dtcon->getHost().c_str(), dtcon->getUser().c_str(), dtcon->getPassword().c_str(),dtcon->getDatabase().c_str(),dtcon->getPort(), NULL, 0) == NULL)
            {
                /*std::string msg = "";
                msg = msg + " MySQL Server Error No. : '";
                msg = msg + std::to_string(mysql_errno(conn));
                msg = msg + "' ";
                msg = msg + mysql_error(conn);
                throw SQLException(msg);*/
				return false;
            }        
            if(mysql_autocommit(conn,0) != 0)
            {
                /*std::string msg = "";
                msg = msg + " MySQL Server Error No. : '";
                msg = msg + std::to_string(mysql_errno(conn));
                msg = msg + "' ";
                msg = msg + mysql_error(conn);
                throw SQLException(msg);*/
				return false;
            }        
			setConnecion(conn,dtcon);
            return true;
        }
}
}
}
