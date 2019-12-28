#ifndef TOOLKIT_CLIENTDB_MYSQL_HPP
#define TOOLKIT_CLIENTDB_MYSQL_HPP

#include <vector>

#include "clientdb.hh"

namespace octetos
{
namespace db
{       
namespace dbi
{        
	class Datconnect : public db::Datconnect
	{
	public:         
		Datconnect(Driver driver,const std::string& host, unsigned int port,const std::string& database,const std::string& usuario,const std::string& password);
		Datconnect(const Datconnect& obj);
		//const Datconnect& operator=(const Datconnect&);
		~Datconnect();
		Datconnect();
		std::string getStringDriver()const;
		virtual std::string toString()const;
	};      

	class Row : public db::Row
	{
	public:
#ifdef COLLETION_ASSISTANT
		Row(Datresult* rs,void* row);
#endif
		virtual const char* operator[](unsigned long long index); 
		Row();
		virtual ~Row();
		Row(void* row);
		Row(Row& row);
		virtual int getint(short field)const;
		virtual long getl(short field)const;
		virtual long long getll(short field)const;
		virtual std::string getString(short field)const;
	};
        
	class Datresult : public db::Datresult
	{
	public:
		virtual ~Datresult();
		Datresult(void* result);
		virtual db::Row* operator[](unsigned long long index);                
		virtual db::Row* next() __attribute__ ((deprecated));      
		virtual bool nextRow();
		virtual db::Row* getRow();
		virtual int getint(short field)const;
		virtual int getuint(short field)const;
		virtual long getl(short field)const;
		virtual long long getll(short field)const;
		virtual std::string getString(short field)const;
	};
        
	class Connector : public db::Connector
	{
	private:
		void* instance;
		
	public:
		virtual ~Connector();
		Connector();
		virtual bool connect(const db::Datconnect* connector);
		const char* serverDescription();
		std::string getVerionString();
		//virtual bool query(const std::string&);
		//virtual bool query(const std::string&, std::vector<std::vector<const char*>>&);
		virtual db::Datresult* query(const char*);
		virtual unsigned long long insert(const std::string&);
		virtual bool commit();
		virtual bool begin();
		virtual bool rollback();
		virtual void close();
		virtual core::Semver getVerionServer() const;
	};      
}
}
}

#endif
