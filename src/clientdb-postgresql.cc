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
        
	Datconnect::Datconnect()
	{
		
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
		const char* str = PQgetvalue((PGresult*)getResult(),currentRow,field);
		return str ? str[0] : '\0';
	}
	unsigned char Datresult::getuchar(FieldNumber field)const
	{
		const char* str = PQgetvalue((PGresult*)getResult(),currentRow,field);
		return str ? str[0] : '\0';
	}
	short Datresult::getshort(FieldNumber field)const
	{
		const char* str = PQgetvalue((PGresult*)getResult(),currentRow,field);
		return str ? (short)std::stoi(str) : 0;
	}
	unsigned short Datresult::getushort(FieldNumber field)const
	{
		const char* str = PQgetvalue((PGresult*)getResult(),currentRow,field);
		return str ? (unsigned short)std::stoul(str) : 0;
	}
	unsigned int Datresult::getuint(FieldNumber field)const
	{
		const char* str = PQgetvalue((PGresult*)getResult(),currentRow,field);
		return str ? (unsigned int)std::stoul(str) : 0;
	}
	unsigned long Datresult::getul(FieldNumber field)const
	{
		const char* str = PQgetvalue((PGresult*)getResult(),currentRow,field);
		return str ? std::stoul(str) : 0;
	}
	unsigned long long Datresult::getull(FieldNumber field)const
	{
		const char* str = PQgetvalue((PGresult*)getResult(),currentRow,field);
		return str ? std::stoull(str) : 0;
	}
	float Datresult::getfloat(FieldNumber field)const
	{
		const char* str = PQgetvalue((PGresult*)getResult(),currentRow,field);
		return str ? std::stod(str) : 0;
	}
	double Datresult::getdouble(FieldNumber field)const
	{
		const char* str = PQgetvalue((PGresult*)getResult(),currentRow,field);
		return str ? std::atoi(str) : 0;
	}
	int Datresult::getint(FieldNumber field) const
	{
		const char* str = PQgetvalue((PGresult*)getResult(),currentRow,field);
		return str ? std::atoi(str) : 0;
	}
	long Datresult::getl(FieldNumber field)const
	{
		const char* str = PQgetvalue((PGresult*)getResult(),currentRow,field);
		return str ? std::atol(str) : 0;
	}
	long long Datresult::getll(FieldNumber field)const
	{
		const char* str = PQgetvalue((PGresult*)getResult(),currentRow,field);
		return str ? std::atoll(str) : 0;
	}
	std::string Datresult::getString(FieldNumber field)const 
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

	Datresult::Datresult()
	{
		currentRow = -1;
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
        
        
       
	bool Connector::select(const std::string& str,db::Datresult& rs)
	{
		return execute (str,rs);
	}		
	RowNumber Connector::update(const std::string& str,db::Datresult& rs)
	{		
		if(!execute (str,rs)) return -1;
		RowNumber count = PQntuples((PGresult*)rs.getResult());
		return count;
	}		
	RowNumber Connector::remove(const std::string& str,db::Datresult& rs)
	{
		if(!execute (str,rs)) return -1;
		RowNumber count = PQntuples((PGresult*)rs.getResult());
		return count;
	}		
	core::Semver Connector::getVerionServer() const
	{
		core::Semver ver;
		ver.set(PQserverVersion((PGconn*)conn),core::Semver::ImportCode::PostgreSQL);

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
            if((PGconn*)conn) 
			{
				PQfinish((PGconn*)conn);
				conn=NULL;
				datconn=NULL;
			}
        }        
        bool Connector::begin()
        {
			Datresult rs;
            return execute("BEGIN",rs); 
        }
        bool Connector::rollback()
        {
			Datresult rs;
            return execute("ROLLBACK",rs); 
        }        
        bool Connector::commit()
        {
			Datresult rs;
            return execute("COMMIT",rs); 
        }

		RowNumber Connector::insert(const std::string& str,db::Datresult& rs)
        {
        	PGresult *res = PQexec((PGconn*)conn, str.c_str()); 
            if (res == NULL)
            {       
                PQclear(res);
				std::string msg = "La consuta de insert fallo: ";
				msg += PQerrorMessage((PGconn*)conn);
                throw SQLExceptionQuery(msg); 
            }        
			
			res = PQexec((PGconn*)conn, "SELECT lastval()"); 
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
			else if(countR > 1)
			{
				throw SQLException("la funcion 'lastval()' retorno muchos resutlados.");
			}
			else
			{
				throw SQLException("la funcion 'lastval()' no retorno resultdo.");
			}
			rs = (Result)res;
            return ID;		
        }
        bool Connector::connect(const db::Datconnect& conection)
        {
            std::string strsql = "";
            if(conection.getHost().length() > 1)
            {
                if(is_ipv4_address(conection.getHost()))
                {
                    strsql = strsql + "hostaddr=" + conection.getHost();
                }
                else if(is_ipv6_address(conection.getHost()))
                {
                    strsql = strsql + "hostaddr=" + conection.getHost();
                }
                else if(is_valid_domain_name(conection.getHost()))
                {
                    strsql = strsql + "host=" + conection.getHost();
                }
            }
            if(conection.getUser().length() > 1)
            {
                strsql = strsql + " user=" + conection.getUser();
            }
            if(conection.getPort() > 0)
            {
                strsql = strsql + " port=" + std::to_string(conection.getPort());
            }
            if(conection.getDatabase().length() > 1)
            {
                strsql = strsql + " dbname=" + conection.getDatabase();
            }
            if(conection.getPassword().length() > 1)
            {
                strsql = strsql + " password=" + conection.getPassword();
            }
			conn = PQconnectdb(strsql.c_str());
            if (PQstatus((PGconn*)conn) == CONNECTION_BAD) 
            {
                std::string msg = PQerrorMessage((PGconn*)conn);  
                SQLException sqlfail(msg); 
				core::Error::write(sqlfail);
				return false;
            }           
			datconn = &conection;
            return true;
        }        
	bool Connector::execute(const std::string& str,db::Datresult& rs)
	{
		//std::cout << "Connector::execute : Step 1 \n";
		PGresult *res = PQexec((PGconn*)conn, str.c_str());
		if(res == NULL)
		{
			//std::cout << "Connector::execute : Step 1.1 \n";
			std::string msg = "Fail on proceses query.";
			SQLException ex(msg);
			octetos::core::Error::write(ex);
			return false;
		}
		if (PQresultStatus(res) != PGRES_TUPLES_OK)
		{
			//std::cout << "Connector::execute : Step 2.1 \n";
			std::string msg = PQerrorMessage((PGconn*)conn);
			SQLException ex(msg);
			octetos::core::Error::write(ex);
			return false;
		}
		
		//std::cout << "Connector::execute : Step 3 \n";
		rs = (Result)res;
		return true;
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
