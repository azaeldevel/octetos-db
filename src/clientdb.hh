#ifndef TOOLKIT_CLIENTDB_HPP
#define TOOLKIT_CLIENTDB_HPP

#include <octetos/core/common.hh>
#include <octetos/core/Artifact.hh>
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

	
	/**
	 * \brief retorna la informacion del paquete usese ne lugar getPakageVersion y getPakageName
	 **/
	core::Artifact getPackageInfo();


	class SQLException : public std::exception
	{
	public:
		virtual ~SQLException() throw();
		virtual const char* what() const throw();
		SQLException(const std::string &description) throw();
	private:
		std::string description;
	};
	class SQLExceptionConnection : public SQLException
	{
	public:
		virtual ~SQLExceptionConnection() throw();
		SQLExceptionConnection(const std::string &description) throw();
	};
	class SQLExceptionQuery : public SQLException
	{
	public:
		virtual ~SQLExceptionQuery() throw();
		SQLExceptionQuery(const std::string &description) throw();
	};
	class NotSupportedExcetion  : public SQLException
	{
	public:
		virtual ~NotSupportedExcetion() throw();
		NotSupportedExcetion(const std::string &description) throw();		
	};
    
	enum Driver
	{
		Unknow,
		MySQL,
		PostgreSQL
	};

   	class Datconnect : public core::Object
	{
	public:
   		//typedef Driver ServerType;/*deprecated*/
   		Datconnect(const Datconnect&);
		Datconnect();
		//const Datconnect& operator=(const Datconnect& obj);
		void set(Driver serverType,const std::string& host, unsigned int port,const std::string& database,const std::string& usuario,const std::string& password);
            
            virtual std::string toString()const;
            const std::string& getHost()const;
            const std::string& getUser()const;
            const std::string& getPassword()const;
            const std::string& getDatabase()const;
			Driver getDriver()const;
            const char* getServerTypeString()const;/*deprecated*/
            unsigned int getPort()const;
            void setHost(const std::string&);
            void setUser(const std::string&);
            void setPassword(const std::string&);
            void setDatabase(const std::string&);
            void setPort(unsigned int);
            
            Datconnect(Driver serverType,const std::string& host, unsigned int port,const std::string& database,const std::string& user,const std::string& password);
            
	private:
            Driver driver;
            std::string host;
            std::string user;
            std::string password;
            std::string database;
            unsigned int port;        
	};	
	
        
	/*class Row : public core::Object
	{
	protected:
		void* row;
                
	public:
		//virtual const char* operator[](unsigned long long index) = 0; 
		virtual ~Row();
		Row();
		Row(void* row);
		Row(const Row& row);
		virtual int getint(IndexField field)const = 0;
		virtual long getl(IndexField field)const = 0;
		virtual long long getll(IndexField field)const = 0;
		virtual std::string getString(IndexField field)const = 0;
	};*/
        
	class Datresult : public core::Object
	{
	private:
		Result result;
    	
	public:
		Datresult(void* result);
		virtual ~Datresult();
		virtual bool nextRow() = 0;
		Result getResult() const;
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
		//retrive field meta-data
	};
        
	class Connector : public core::Object
	{
	private:
		Connection conn;
		const Datconnect* datconection;

	protected:
		void setConnecion(Connection,const Datconnect*);
            
	public:
            //
            static bool is_ipv4_address(const std::string& str);
            static bool is_ipv6_address(const std::string& str);
            static bool is_valid_domain_name(const std::string& str);
            virtual ~Connector();
            Connector();
            //Connector(const Connector&);
            Connection getConnection()const;
            const Datconnect* getDatconection() const; 
            const Connector& operator=(const Connector& obj);
			//
            virtual bool connect(const Datconnect* connector)  = 0;            
            virtual Datresult* execute(const std::string& str) = 0;  
            virtual RowNumber insert(const std::string&) = 0;         
            virtual Datresult* select(const std::string& str) = 0;
            virtual RowNumber update(const std::string&) = 0;
            virtual RowNumber remove(const std::string&) = 0;
            virtual bool commit() = 0;
            virtual bool begin() = 0;
            virtual bool rollback() = 0;
            virtual void close() = 0; 
			virtual core::Semver getVerionServer() const = 0;
	};

}
}

#endif
