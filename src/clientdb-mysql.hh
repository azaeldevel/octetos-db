#ifndef TOOLKIT_CLIENTDB_MYSQL_HPP
#define TOOLKIT_CLIENTDB_MYSQL_HPP

#include <vector>
#include <string>

#include "clientdb.hh"

namespace octetos
{
namespace db
{       
namespace mysql
{	
        
        class Datconnect : public db::Datconnect
        {
        public:         
            Datconnect(const std::string& host, unsigned int port,const std::string& database,const std::string& usuario,const std::string& password);
            Datconnect(const Datconnect& obj);
            const Datconnect& operator=(const Datconnect&);
            ~Datconnect();
            Datconnect();
        };      

	class Row
	{
	private:
		void* row;
	public:
#ifdef COLLETION_ASSISTANT
		Row(Datresult* rs,void* row);
#endif
		//virtual const char* operator[](unsigned long long index); 
		virtual ~Row();
		Row();
		Row(void* row);
		Row(const Row& row);
		virtual int getint(db::IndexField field)const;
		virtual long getl(db::IndexField field)const;
		virtual long long getll(db::IndexField field)const;
		virtual std::string getString(db::IndexField field)const;
	};
        
	class Datresult : public db::Datresult
	{
	private:
		Row* actualRow;

	public:
		virtual ~Datresult();
		Datresult(void* result);
		//virtual db::Row* operator[](unsigned long long index);                
		//virtual db::Row* next() __attribute__ ((deprecated));
		virtual bool nextRow();
		//virtual db::Row* getRow();
		//retrive data field by index
		virtual char getchar(db::IndexField field)const;
		virtual unsigned char getuchar(db::IndexField field)const;
		virtual short getshort(db::IndexField field)const;
		virtual unsigned short getushort(db::IndexField field)const;
		virtual int getint(db::IndexField field)const;
		virtual unsigned int getuint(db::IndexField field)const;
		virtual long getl(db::IndexField field)const;
		virtual unsigned long getul(db::IndexField field)const;
		virtual long long getll(db::IndexField field)const;
		virtual unsigned long long getull(db::IndexField field)const;
		virtual float getfloat(db::IndexField field)const;
		virtual double getdouble(db::IndexField field)const;
		virtual std::string getString(db::IndexField field)const;
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
		//retrive field meta-data
		virtual size_t getFieldLength(db::IndexField field) const;
		virtual size_t getFieldLength(const std::string&) const;
		virtual IndexField getFieldNumbers() const;
	};
        
	class Connector : public db::Connector
	{
	public:
		virtual ~Connector();
		Connector();
		const char* serverDescription();
		virtual core::Semver getVerionServer() const;
		//
		virtual bool connect(const db::Datconnect* connector);
		virtual db::Datresult* execute(const std::string& str);
		virtual unsigned long long insert(const std::string&);
		virtual bool commit();
		virtual bool begin();
		virtual bool rollback();
		virtual void close(); 
	};      
}
}
}

#endif
