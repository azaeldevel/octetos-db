#ifndef TOOLKIT_CLIENTDB_POSTGRESQL_HPP
#define TOOLKIT_CLIENTDB_POSTGRESQL_HPP

#include <vector>

#include "clientdb.hh"

namespace octetos
{
namespace db
{
namespace postgresql
{                   

        
        class Datconnect : public db::Datconnect
        {
        public:         
            Datconnect(const std::string& host, unsigned int port,const std::string& database,const std::string& usuario,const std::string& password);
            Datconnect(const Datconnect& obj);
            const Datconnect& operator=(const Datconnect&);
			Datconnect();
        };

    
	class Datresult : public db::Datresult
	{
	private:		
		unsigned long long currentRow;
                
	public:
		Datresult(void* result);
		Datresult();
		virtual ~Datresult();
		virtual bool nextRow();
		//retrive data field by index
		virtual char getchar(FieldNumber field)const;
		virtual unsigned char getuchar(FieldNumber field)const;
		virtual short getshort(FieldNumber field)const;
		virtual unsigned short getushort(FieldNumber field)const;
		virtual int getint(FieldNumber field)const;
		virtual unsigned int getuint(FieldNumber field)const;
		virtual long getl(FieldNumber field)const;
		virtual unsigned long getul(FieldNumber field)const;
		virtual long long getll(FieldNumber field)const;
		virtual unsigned long long getull(FieldNumber field)const;
		virtual float getfloat(FieldNumber field)const;
		virtual double getdouble(FieldNumber field)const;
		virtual std::string getString(FieldNumber field)const;
		//retrive data field by name
		virtual char getchar(const std::string&)const;
		virtual unsigned char getuchar(const std::string&)const;
		virtual short getshort(const std::string&)const;
		virtual unsigned short getushort(const std::string&)const;
		virtual int getint(const std::string&)const;
		virtual unsigned int getuint(const std::string&)const;
		virtual long getl(const std::string&)const;
		virtual unsigned long getul(const std::string&)const;
		virtual long long getll(const std::string&)const;
		virtual unsigned long long getull(const std::string&)const;
		virtual float getfloat(const std::string&)const;
		virtual double getdouble(const std::string&)const;
		virtual std::string getString(const std::string&)const;
	};

	class Connector : public db::Connector
	{
	public:
		virtual ~Connector();
		Connector();
		const db::Datconnect& getDatconection() const; 
		//
		virtual bool connect(const db::Datconnect& connector);            
		virtual bool execute(const std::string& str,db::Datresult&);
		virtual RowNumber insert(const std::string&);         
		virtual bool select(const std::string& str,db::Datresult&);
		virtual RowNumber update(const std::string&);
		virtual RowNumber remove(const std::string&);
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
