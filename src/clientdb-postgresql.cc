#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>
#include <iostream>
#include <string>


#include "clientdb-postgresql.hh"



namespace octetos
{
namespace db
{
namespace postgresql
{
        


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
		const char* str = PQgetvalue((PGresult*)getResult(),currentRow,field);
		return str ? str[0] : '\0';
	}
	unsigned char Datresult::getuchar(db::IndexField field)const
	{
		const char* str = PQgetvalue((PGresult*)getResult(),currentRow,field);
		return str ? str[0] : '\0';
	}
	short Datresult::getshort(db::IndexField field)const
	{
		const char* str = PQgetvalue((PGresult*)getResult(),currentRow,field);
		return str ? (short)std::stoi(str) : 0;
	}
	unsigned short Datresult::getushort(db::IndexField field)const
	{
		const char* str = PQgetvalue((PGresult*)getResult(),currentRow,field);
		return str ? (unsigned short)std::stoul(str) : 0;
	}
	unsigned int Datresult::getuint(db::IndexField field)const
	{
		const char* str = PQgetvalue((PGresult*)getResult(),currentRow,field);
		return str ? (unsigned int)std::stoul(str) : 0;
	}
	unsigned long Datresult::getul(db::IndexField field)const
	{
		const char* str = PQgetvalue((PGresult*)getResult(),currentRow,field);
		return str ? std::stoul(str) : 0;
	}
	unsigned long long Datresult::getull(db::IndexField field)const
	{
		const char* str = PQgetvalue((PGresult*)getResult(),currentRow,field);
		return str ? std::stoull(str) : 0;
	}
	float Datresult::getfloat(db::IndexField field)const
	{
		const char* str = PQgetvalue((PGresult*)getResult(),currentRow,field);
		return str ? std::stod(str) : 0;
	}
	double Datresult::getdouble(db::IndexField field)const
	{
		const char* str = PQgetvalue((PGresult*)getResult(),currentRow,field);
		return str ? std::atoi(str) : 0;
	}
	int Datresult::getint(db::IndexField field) const
	{
		const char* str = PQgetvalue((PGresult*)getResult(),currentRow,field);
		return str ? std::atoi(str) : 0;
	}
	long Datresult::getl(db::IndexField field)const
	{
		const char* str = PQgetvalue((PGresult*)getResult(),currentRow,field);
		return str ? std::atol(str) : 0;
	}
	long long Datresult::getll(db::IndexField field)const
	{
		const char* str = PQgetvalue((PGresult*)getResult(),currentRow,field);
		return str ? std::atoll(str) : 0;
	}
	std::string Datresult::getString(db::IndexField field)const 
	{
		return PQgetvalue((PGresult*)getResult(),currentRow,field);
	}
	bool Datresult::nextRow()
	{
		if(PQntuples((PGresult*)getResult()) > currentRow + 1) 
		{
			currentRow++;
			return true;
		}

		return false;
	}
        
        Datresult::Datresult(void* result) : db::Datresult(result)
        {
			currentRow = -1;
        }
        
	Datresult::~Datresult()
	{
		if(getResult())
		{
			PQclear((PGresult*)getResult());
		}
#ifdef COLLETION_ASSISTANT
		if(getCountChilds() > 0)
		{
			std::cerr << "Una instacia de '" << typeid(*this).name() << "' termino sin que todos sus hijos terminaran primero" << std::endl;
		}
#endif
	}

	
        /*std::string Datasource::toString() const
        {		
            return toolkit::clientdb::Datasource::toString();
        } */
        Datconnect::Datconnect(const Datconnect& obj) : db::Datconnect(obj)
        {
            
        }
        const Datconnect& Datconnect::operator=(const Datconnect& obj)
        {		
            ((Datconnect&)*this)=obj;
            return *this;
        }
        Datconnect::Datconnect(const std::string& host, unsigned int port,const std::string& database,const std::string& usuario,const std::string& password) : db::Datconnect(Driver::MySQL,host,port,database,usuario,password)
        {
        }
        
        
        
	core::Semver Connector::getVerionServer() const
	{
		core::Semver ver;
		ver.set(PQserverVersion((PGconn*)getConnection()),core::semver::ImportCode::PostgreSQL);

		return ver;
	}
        Connector::Connector()
        {
        }
        Connector::~Connector()
        {
            close();
        }
        const db::Datconnect& Connector::getDatconection() const
        {
            return (const db::postgresql::Datconnect&)Connector::getDatconection();
        } 
        void Connector::close()
        {
			PGconn* conn = (PGconn*)getConnection();
            if(conn) 
			{
				PQfinish(conn);
				setConnecion (NULL,NULL);
			}
        }        
        bool Connector::begin()
        {
            return execute("BEGIN"); 
        }
        bool Connector::rollback()
        {
            return execute("ROLLBACK"); 
        }        
        bool Connector::commit()
        {
            return execute("COMMIT"); 
        }
        unsigned long long Connector::insert(const std::string& str)
        { 		
            PGresult *res = PQexec((PGconn*)getConnection(), str.c_str()); 
            if (res == NULL)
            {
                throw SQLExceptionQuery("La consuta de insert fallo.");        
                PQclear(res);
            }        
			
			res = PQexec((PGconn*)getConnection(), "SELECT lastval()"); 
            if (res == NULL)
            {
                throw SQLExceptionQuery("No se retorno datos.");        
                PQclear(res);
            }
            int ID = 0;
            int countR = PQntuples(res);
            if(countR == 1)
            {
				ID = std::stoi(PQgetvalue(res, 0, 0));
			}
			else
			{
				throw SQLException("la funcion 'lastval()' no retorno resultdo.");
			}
			
            return ID;		
        } 
        bool Connector::connect(const db::Datconnect* conection)
        {
            std::string strsql = "";
            if(conection->getHost().length() > 1)
            {
                if(is_ipv4_address(conection->getHost()))
                {
                    strsql = strsql + "hostaddr=" + conection->getHost();
                }
                else if(is_ipv6_address(conection->getHost()))
                {
                    strsql = strsql + "hostaddr=" + conection->getHost();
                }
                else if(is_valid_domain_name(conection->getHost()))
                {
                    strsql = strsql + "host=" + conection->getHost();
                }
            }
            if(conection->getUser().length() > 1)
            {
                strsql = strsql + " user=" + conection->getUser();
            }
            if(conection->getPort() > 0)
            {
                strsql = strsql + " port=" + std::to_string(conection->getPort());
            }
            if(conection->getDatabase().length() > 1)
            {
                strsql = strsql + " dbname=" + conection->getDatabase();
            }
            if(conection->getPassword().length() > 1)
            {
                strsql = strsql + " password=" + conection->getPassword();
            }
			PGconn* conn = PQconnectdb(strsql.c_str());
            if (PQstatus(conn) == CONNECTION_BAD) 
            {
                //std::string msg = PQerrorMessage((PGconn*)serverConnector);  
                //throw SQLException(msg);  
				return false;
            }            
            setConnecion(conn,conection);
            return true;
        }        
	db::Datresult* Connector::execute(const std::string& str)
	{
		PGresult *res = PQexec((PGconn*)getConnection(), str.c_str());
		if (PQresultStatus(res) != PGRES_TUPLES_OK)
		{		
			return NULL;
		}
		
		Datresult* dtrs = new Datresult(res);
#ifdef COLLETION_ASSISTANT
		addChild(dtrs);
#endif    
		return dtrs;			
		
	}
        /*bool Connector::query(const std::string& str, std::vector<std::vector<const char*>>& rows)
        {
            PGresult *res = PQexec((PGconn*)serverConnector, str.c_str()); 
            if (PQresultStatus(res) != PGRES_TUPLES_OK)
            {
                throw SQLExceptionQuery("No se retorno datos.");        
                PQclear(res);
            }
            int countR = PQntuples(res); 
            int countF = PQnfields(res);
            for(int i = 0; i < countR; i++) 
            {           
                std::vector<const char*> val;
                for(int j = 0; j < countF; j++)
                {
                    val.push_back(PQgetvalue(res, i, 0));
                }
                rows.push_back(val);
            }
            PQclear(res);
            return true;
        }*/
}
}
}
