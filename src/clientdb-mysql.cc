#include <mysql/mysql.h>
#include <iostream>
#include <octetos/core/Artifact.hh>

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
		return r[field] ? std::string(r[field]) : "";
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
	Row::Row(const Row& r):db::Row(r)
	{
		
	}        
	Row::Row()
	{
		
	}
	Row::Row(void* row):db::Row(row)
	{
		
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
		if(!(Row*)actualRow) return actualRow->getint(field);
		return 0;
	}
	long Datresult::getl(db::IndexField field)const
	{
		if(!(Row*)actualRow) return ((Row*)actualRow)->getl(field);
		return 0;
	}
	long long Datresult::getll(db::IndexField field)const
	{
		if(!(Row*)actualRow) return ((Row*)actualRow)->getll(field);
		return 0;
	}
	std::string Datresult::getString(db::IndexField field)const 
	{
		if(!(Row*)actualRow) return ((Row*)actualRow)->getString(field);
		return "";
	}
	/*db::Row* Datresult::getRow()
	{
		db::Row* ret = actualRow;
		actualRow = NULL;

		return ret;
	}*/
	bool Datresult::nextRow()
	{
		MYSQL_ROW row  = mysql_fetch_row((MYSQL_RES*)result);
		if(actualRow != NULL)
		{
			delete actualRow;
			actualRow = new Row((void*)row);
#ifdef COLLETION_ASSISTANT
			addChild(actualRow);
#endif 
		}
		else
		{
			actualRow = new Row((void*)row);
#ifdef COLLETION_ASSISTANT
			addChild(actualRow);
#endif 
		}
		
		if(row) return true;
		return false;
	}
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
        
        Datresult::Datresult(void* result) : db::Datresult(result)
        {
			actualRow = NULL;
        }
        
        /*db::Row* Datresult::next()
        {
                MYSQL_ROW row  = mysql_fetch_row((MYSQL_RES*)result);
                Row* r = new Row(row);
#ifdef COLLETION_ASSISTANT
                addChild(r);
#endif                                 
                return r;
        }*/
	Datresult::~Datresult()
	{
		if(actualRow != NULL)
		{
			delete actualRow;
		}
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
        db::Datresult* Connector::query(const char* str)
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





	core::Semver Connector::getVerionServer() const
	{
		core::Semver ver;
		ver.importFactors(mysql_get_server_version((MYSQL*)serverConnector),core::Semver::Imports::MySQL);
		
		return ver;
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
        bool Connector::connect(const db::Datconnect* conection)
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
