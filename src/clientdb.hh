#ifndef OCTETOS_CLIENTDB_HH
#define OCTETOS_CLIENTDB_HH


#include <octetos/core/Artifact.hh>
#include <octetos/core/Error.hh>
#include <vector>
#include <string>

namespace octetos
{
namespace db
{
	typedef void*  Handler;
	typedef Handler Connection;
	typedef Handler Result;

	typedef unsigned long long RowNumber;
	typedef unsigned int FieldNumber;
	enum ErrorCodes
	{
		UnknowError = core::Error::ROOFCODE,
		ErrorConection
	};
	
	/**
	 * \brief retorna la informacion del paquete usese ne lugar getPakageVersion y getPakageName
	 **/
	bool getPackageInfo(core::Artifact&);
	
	
	class SQLException : public core::Error
	{
	public:
		virtual ~SQLException() throw();
		SQLException(const std::string& description) throw();
		SQLException(const std::string&, int code) throw();
	private:
		//std::string description;
	};
	class SQLExceptionConnection : public SQLException
	{
	public:
		virtual ~SQLExceptionConnection() throw();
		SQLExceptionConnection(const std::string& description) throw();
		SQLExceptionConnection(const std::string& description, int code) throw();
	};
	class SQLExceptionQuery : public SQLException
	{
	public:
		virtual ~SQLExceptionQuery() throw();
		SQLExceptionQuery(const std::string& description) throw();
		SQLExceptionQuery(const std::string& description, int code) throw();
	};
	class NotSupportedExcetion  : public SQLException
	{
	public:
		virtual ~NotSupportedExcetion() throw();
		NotSupportedExcetion(const std::string& description) throw();
		NotSupportedExcetion(const std::string& description, int code) throw();		
	};
    
	enum Driver
	{
		Unknow,
		MySQL,
		PostgreSQL,
		MariaDB
	};
	const char* getDriverString(Driver);

   	class Datconnect : public core::Object
	{
	public:
   		Datconnect(Driver serverType,const std::string& host, unsigned int port,const std::string& database,const std::string& user,const std::string& password);
   		Datconnect(const Datconnect&);
		Datconnect();
		            
		virtual std::string toString()const;
		const std::string& getHost()const;
		const std::string& getUser()const;
		const std::string& getPassword()const;
		const std::string& getDatabase()const;
		Driver getDriver()const;
		unsigned int getPort()const;
		void setHost(const std::string&);
		void setUser(const std::string&);
		void setPassword(const std::string&);
		void setDatabase(const std::string&);
		void setPort(unsigned int);
        void set(Driver serverType,const std::string& host, unsigned int port,const std::string& database,const std::string& usuario,const std::string& password);
		
		bool write(const std::string&);
		bool read(const std::string&);
            
	private:
		Driver driver;
		std::string host;
		std::string user;
		std::string password;
		std::string database;
		unsigned int port;        
	};		
        
        
	class Datresult : public core::Object
	{
	protected:
		Result result;
    	
	public:
		Datresult(void* result);
		Datresult();
		virtual ~Datresult();
		virtual bool nextRow() = 0;
		Result getResult() const;
		const Datresult& operator = (Result);
		//retrive data field by index
		virtual char getchar(FieldNumber field)const = 0;
		virtual unsigned char getuchar(FieldNumber field)const = 0;
		virtual short getshort(FieldNumber field)const = 0;
		virtual unsigned short getushort(FieldNumber field)const = 0;
		virtual int getint(FieldNumber field)const = 0;
		virtual unsigned int getuint(FieldNumber field)const = 0;
		virtual long getl(FieldNumber field)const = 0;
		virtual unsigned long getul(FieldNumber field)const = 0;
		virtual long long getll(FieldNumber field)const = 0;
		virtual unsigned long long getull(FieldNumber field)const = 0;
		virtual float getfloat(FieldNumber field)const = 0;
		virtual double getdouble(FieldNumber field)const = 0;
		virtual std::string getString(FieldNumber field)const = 0;
		//retrive data field by name
		virtual char getchar(const std::string&)const = 0;
		virtual unsigned char getuchar(const std::string&)const = 0;
		virtual short getshort(const std::string&)const = 0;
		virtual unsigned short getushort(const std::string&)const = 0;
		virtual int getint(const std::string&)const = 0;
		virtual unsigned int getuint(const std::string&)const = 0;
		virtual long getl(const std::string&)const = 0;
		virtual unsigned long getul(const std::string&)const = 0;
		virtual long long getll(const std::string&)const = 0;
		virtual unsigned long long getull(const std::string&)const = 0;
		virtual float getfloat(const std::string&)const = 0;
		virtual double getdouble(const std::string&)const = 0;
		virtual std::string getString(const std::string&)const = 0;
	};
        
	class Connector : public core::Object
	{
	protected:
		Connection conn;
		const Datconnect* datconn;

	protected:
		//void setConnecion(Connection,const Datconnect*);
            
	public:
		//
		static bool is_ipv4_address(const std::string& str);
		static bool is_ipv6_address(const std::string& str);
		static bool is_valid_domain_name(const std::string& str);
		virtual ~Connector();
		Connector();
		Connection getConnection()const;
		const Datconnect* getDatconection() const; 
		const Connector& operator=(const Connector& obj);
		//
		virtual bool connect(const Datconnect& connector)  = 0;            
		virtual bool execute(const std::string& str,Datresult&) = 0;  
		virtual RowNumber insert(const std::string&,Datresult&) = 0;         
		virtual bool select(const std::string& str,Datresult&) = 0;
		virtual RowNumber update(const std::string&,Datresult&) = 0;
		virtual RowNumber remove(const std::string&,Datresult&) = 0;
		virtual bool commit() = 0;
		virtual bool begin() = 0;
		virtual bool rollback() = 0;
		virtual void close() = 0; 
		virtual core::Semver getVerionServer() const = 0;
	};

}
}

#endif
